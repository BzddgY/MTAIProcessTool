#include "expimagingmodule.h"
#include "ui_expimagingmodule.h"

ExpImagingModule::ExpImagingModule(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ExpImagingModule)
{
    ui->setupUi(this);
    ui->comboBox_rayReconstructionType->addItems({"BP","DAS"});
    ui->comboBox_nonNegativeReconType->addItems({"Amplitude","Energy1","Energy2","Peak-Peak"});
    ui->checkBox->setTristate(false);//仅两种选中选项
    _isReverseImaging = 1; _isNeedUpdateRayImagingTAI = true; _isNeedUpdateNonNegativeImagingTAI = true;
    x1 = ui->doubleSpinBox_x1->value(); x2 = ui->doubleSpinBox_x2->value();
    dx = ui->doubleSpinBox_dx->value();
    y1 = ui->doubleSpinBox_y1->value(); y2 = ui->doubleSpinBox_y2->value();
    dy = ui->doubleSpinBox_dy->value();
    _signalWidth = ui->spinBox_nonNegativeWidth->value();
}

ExpImagingModule::~ExpImagingModule()
{
    delete ui;
}

void ExpImagingModule::runRayImaging(TADataBox &TADataBox_,
                                     QVector<float>& sensorDecare_,
                                     const RayImagingType &rayImagingType_,
                                     const float& SoS, const int& Fs)
{
    //生成模态对话框
    _dialog_progress = new QProgressDialog(this);
    _thread_rayImaging = std::make_shared<rayImagingThread>(&TADataBox_,
                                                            &sensorDecare_,
                                                            rayImagingType_,
                                                            SoS,
                                                            Fs,
                                                            _isReverseImaging,
                                                            ui->doubleSpinBox_x1->value(),
                                                            ui->doubleSpinBox_x2->value(),
                                                            ui->doubleSpinBox_dx->value(),
                                                            ui->doubleSpinBox_y1->value(),
                                                            ui->doubleSpinBox_y2->value(),
                                                            ui->doubleSpinBox_dy->value(),
                                                            nullptr);
    //求解算法复杂度
    _maxCount = (qFloor((ui->doubleSpinBox_x2->value() - ui->doubleSpinBox_x1->value()) /
                            ui->doubleSpinBox_dx->value()+0.1)+1)*
                   (qFloor((ui->doubleSpinBox_y2->value() - ui->doubleSpinBox_y1->value()) /
                            ui->doubleSpinBox_dy->value()+0.1)+1)*
                   (TADataBox_.viewData("PreProcessedRFData_yVec").size());
    connect(_thread_rayImaging.get(), &rayImagingThread::sigUpdateProgress,
            this, &ExpImagingModule::slotUpdateProgress);
    connect(_thread_rayImaging.get(), &rayImagingThread::sigFinishProgress,
            this, &ExpImagingModule::slotFinishProgress);
    connect(_thread_rayImaging.get(), &rayImagingThread::sig_showRunningTime,
            this, &ExpImagingModule::slot_showRunningTime);
    connect(_thread_rayImaging.get(), &rayImagingThread::sig_plotRayImagingTAI,
            this, &ExpImagingModule::slot_plotRayImagingTAI);
    connect(_thread_rayImaging.get(), &rayImagingThread::sig_setIsUpdateRayImagingTAIFalse,
            this, &ExpImagingModule::slot_setIsUpdateRayImagingTAIFalse);
    connect(_thread_rayImaging.get(), &rayImagingThread::sig_appendLog,
            this, &ExpImagingModule::slot_appendLog);


    connect(_dialog_progress, &QProgressDialog::canceled, this,
            &ExpImagingModule::slotCancelProgress);
    connect(this, &ExpImagingModule::sigCancelProgress, _thread_rayImaging.get(),
            &rayImagingThread::slotCancelProgress);

    if (_isNeedUpdateRayImagingTAI){
        _thread_rayImaging->start();
        _dialog_progress->setWindowTitle(tr("求解射线成像中，请等待......"));
        _dialog_progress->setFixedWidth(PROGRESS_WIDTH);
        _dialog_progress->setRange(0, 100);
        _dialog_progress->exec();
    }else{
        emit sigAppendLog("由于不需要更新计算射线成像结果，本次射线成像未计算。");
        emit sig_plotRayImagingTAI();
        _dialog_progress->setValue(100);
        _dialog_progress->deleteLater();
    }
}

void ExpImagingModule::runNonNegativeImaging(TADataBox &TADataBox_, QVector<float> &sensorDecare_,
                                             const RayImagingType &rayImagingType_,
                                             const NonNegativeImagingType &nonNegativeImagingType,
                                             const float &SoS, const int &Fs)
{
    //生成模态对话框
    _dialog_nonNegativeImaging_progress = new QProgressDialog(this);
    _thread_nonNegativeImaging = std::make_shared<NonNegativeImagingThread>(&TADataBox_,
                                                            &sensorDecare_,
                                                            rayImagingType_,
                                                            nonNegativeImagingType,
                                                            SoS,
                                                            Fs,
                                                            ui->spinBox_nonNegativeWidth->value(),
                                                            ui->doubleSpinBox_x1->value(),
                                                            ui->doubleSpinBox_x2->value(),
                                                            ui->doubleSpinBox_dx->value(),
                                                            ui->doubleSpinBox_y1->value(),
                                                            ui->doubleSpinBox_y2->value(),
                                                            ui->doubleSpinBox_dy->value(),
                                                            nullptr);
    //求解算法复杂度
    _maxCount_nonNegativeImaging = (qFloor((ui->doubleSpinBox_x2->value() - ui->doubleSpinBox_x1->value()) /
                            ui->doubleSpinBox_dx->value()+0.1)+1)*
                (qFloor((ui->doubleSpinBox_y2->value() - ui->doubleSpinBox_y1->value()) /
                            ui->doubleSpinBox_dy->value()+0.1)+1)*
                (TADataBox_.viewData("PreProcessedRFData_yVec").size());
    connect(_thread_nonNegativeImaging.get(), &NonNegativeImagingThread::sigUpdateProgress,
            this, &ExpImagingModule::slotUpdateNonNegativeImagingProgress);
    connect(_thread_nonNegativeImaging.get(), &NonNegativeImagingThread::sigFinishProgress,
            this, &ExpImagingModule::slotFinishNonNegativeImagingProgress);
    connect(_thread_nonNegativeImaging.get(), &NonNegativeImagingThread::sig_showRunningTime,
            this, &ExpImagingModule::slot_showRunningTime);
    connect(_thread_nonNegativeImaging.get(), &NonNegativeImagingThread::sig_plotNonNegativeImagingTAI,
            this, &ExpImagingModule::slot_plotNonNegativeImagingTAI);
    connect(_thread_nonNegativeImaging.get(), &NonNegativeImagingThread::sig_setIsUpdateNonNegativeImagingTAIFalse,
            this, &ExpImagingModule::slot_setIsUpdateNonNegativeImagingTAIFalse);
    connect(_thread_nonNegativeImaging.get(), &NonNegativeImagingThread::sig_appendLog,
            this, &ExpImagingModule::slot_appendLog);


    connect(_dialog_nonNegativeImaging_progress, &QProgressDialog::canceled, this,
            &ExpImagingModule::slotCancelNonNegativeImagingProgress);
    connect(this, &ExpImagingModule::sigCancelNonNegativeImagingProgress, _thread_nonNegativeImaging.get(),
            &NonNegativeImagingThread::slotCancelNonNegativeImagingProgress);

    if (_isNeedUpdateNonNegativeImagingTAI){
        _thread_nonNegativeImaging->start();
        _dialog_nonNegativeImaging_progress->setWindowTitle(tr("求解非负成像中，请等待......"));
        _dialog_nonNegativeImaging_progress->setFixedWidth(PROGRESS_WIDTH);
        _dialog_nonNegativeImaging_progress->setRange(0, 100);
        _dialog_nonNegativeImaging_progress->exec();
    }else{
        emit sigAppendLog("由于不需要更新计算非负成像结果，本次非负成像未计算。");
        emit sig_plotNonNegativeImagingTAI();
        _dialog_nonNegativeImaging_progress->setValue(100);
        _dialog_nonNegativeImaging_progress->deleteLater();
    }
}

void ExpImagingModule::on_comboBox_rayReconstructionType_currentIndexChanged(int index)
{
    switch(index){
    case 0://BP
        emit sig_setRayImagingType(RayImagingType::BP);
        _isNeedUpdateRayImagingTAI = true;
        _isNeedUpdateNonNegativeImagingTAI = true;
        break;
    case 1://DAS
        emit sig_setRayImagingType(RayImagingType::DAS);
        _isNeedUpdateRayImagingTAI = true;
        _isNeedUpdateNonNegativeImagingTAI = true;
        break;
    default:
        break;
    }
}


void ExpImagingModule::on_pushButton_preShowRayImagingTAI_clicked()
{
    emit sig_preShowRayImagingTAI();
}


void ExpImagingModule::on_checkBox_stateChanged(int arg1)
{
    switch(arg1){
    case 0://未选中
        _isReverseImaging = 1;
        _isNeedUpdateRayImagingTAI = true;
        break;
    case 2://选中
        _isReverseImaging = -1;
        _isNeedUpdateRayImagingTAI = true;
        break;
    }
}

void ExpImagingModule::slotUpdateProgress(int count)
{
    //判断对话框是否为空
    if(!_dialog_progress){
        return;
    }
    _dialog_progress->setValue(count*100 / _maxCount);
}

void ExpImagingModule::slotFinishProgress()
{
    _dialog_progress->setValue(100);
    _dialog_progress->deleteLater();
}

void ExpImagingModule::slotCancelProgress()
{
    emit sigCancelProgress();
    delete _dialog_progress;
    _dialog_progress = nullptr;
}

//注意前面为运行的算法，后面为所耗ms时间
void ExpImagingModule::slot_showRunningTime(QString runningType, int runningTimes)
{
    //计算小时数
    int hours = qFloor(runningTimes/3600000);
    runningTimes %= 3600000;//小于一小时的ms余数
    //计算分钟数
    int miniutes = qFloor(runningTimes / 60000);
    runningTimes %= 60000;//小于一分钟的ms余数
    //计算秒数
    int seconds = qFloor(runningTimes / 1000);
    runningTimes %= 1000;//小于一秒的ms余数
    //根据不同的情况在输出框显示输出耗时
    if(hours >= 1){
        runningType += QString::number(hours)+"h "+QString::number(miniutes) + "min "+QString::number(seconds)+"."+QString::number(runningTimes)+"sec";
    }else if(miniutes >=1){
        runningType += QString::number(miniutes) + "min "+QString::number(seconds)+"."+QString::number(runningTimes)+"sec";
    }else{
        runningType += QString::number(seconds)+"."+QString::number(runningTimes)+"sec";
    }
    emit sigAppendLog(runningType);

}

void ExpImagingModule::slot_appendLog(QString message)
{
    emit sigAppendLog(message);
}

void ExpImagingModule::slotUpdateNonNegativeImagingProgress(int count)
{
    //判断对话框是否为空
    if(!_dialog_nonNegativeImaging_progress){
        return;
    }
    _dialog_nonNegativeImaging_progress->setValue(count*100 / _maxCount_nonNegativeImaging);
}

void ExpImagingModule::slotFinishNonNegativeImagingProgress()
{
    _dialog_nonNegativeImaging_progress->setValue(100);
    _dialog_nonNegativeImaging_progress->deleteLater();
}

void ExpImagingModule::slotCancelNonNegativeImagingProgress()
{
    emit sigCancelNonNegativeImagingProgress();
    delete _dialog_nonNegativeImaging_progress;
    _dialog_nonNegativeImaging_progress = nullptr;
}

void ExpImagingModule::on_comboBox_nonNegativeReconType_currentIndexChanged(int index)
{
    switch(index){
    case 0://Amplitude
        emit sig_setNonNegativeImagingType(NonNegativeImagingType::Amplitude);
        _isNeedUpdateNonNegativeImagingTAI = true;
        break;
    case 1://Energy1
        emit sig_setNonNegativeImagingType(NonNegativeImagingType::Energy1);
        _isNeedUpdateNonNegativeImagingTAI = true;
        break;
    case 2://Energy2
        emit sig_setNonNegativeImagingType(NonNegativeImagingType::Energy2);
        _isNeedUpdateNonNegativeImagingTAI = true;
        break;
    case 3://Peak-Peak
        emit sig_setNonNegativeImagingType(NonNegativeImagingType::Peak_Peak);
        _isNeedUpdateNonNegativeImagingTAI = true;
        break;
    default:
        break;
    }
}


void ExpImagingModule::on_pushButton_preShowRayImagingTAI_2_clicked()
{
    emit sig_preShowNonNegativeImagingTAI();
}

void ExpImagingModule::slot_plotRayImagingTAI()
{
    emit sig_plotRayImagingTAI();
}

void ExpImagingModule::slot_plotNonNegativeImagingTAI()
{
    emit sig_plotNonNegativeImagingTAI();
}

void ExpImagingModule::slot_setIsUpdateRayImagingTAIFalse()
{
    _isNeedUpdateRayImagingTAI = false;
}

void ExpImagingModule::slot_setIsUpdateNonNegativeImagingTAIFalse()
{
    _isNeedUpdateNonNegativeImagingTAI = false;
}


void ExpImagingModule::on_doubleSpinBox_x1_valueChanged(double arg1)
{

}


void ExpImagingModule::on_doubleSpinBox_x1_editingFinished()
{
    if(x1 != ui->doubleSpinBox_x1->value()){
        x1 = ui->doubleSpinBox_x1->value();
        _isNeedUpdateRayImagingTAI = true;
        _isNeedUpdateNonNegativeImagingTAI = true;
    }
}


void ExpImagingModule::on_doubleSpinBox_x2_editingFinished()
{
    if(x2 != ui->doubleSpinBox_x2->value()){
        x2 = ui->doubleSpinBox_x2->value();
        _isNeedUpdateRayImagingTAI = true;
        _isNeedUpdateNonNegativeImagingTAI = true;
    }
}


void ExpImagingModule::on_doubleSpinBox_dx_editingFinished()
{
    if(dx != ui->doubleSpinBox_dx->value()){
        dx = ui->doubleSpinBox_dx->value();
        _isNeedUpdateRayImagingTAI = true;
        _isNeedUpdateNonNegativeImagingTAI = true;
    }
}


void ExpImagingModule::on_doubleSpinBox_y1_editingFinished()
{
    if(y1 != ui->doubleSpinBox_y1->value()){
        y1 = ui->doubleSpinBox_y1->value();
        _isNeedUpdateRayImagingTAI = true;
        _isNeedUpdateNonNegativeImagingTAI = true;
    }
}


void ExpImagingModule::on_doubleSpinBox_y2_editingFinished()
{
    if(y2 != ui->doubleSpinBox_y2->value()){
        y2 = ui->doubleSpinBox_y2->value();
        _isNeedUpdateRayImagingTAI = true;
        _isNeedUpdateNonNegativeImagingTAI = true;
    }
}


void ExpImagingModule::on_doubleSpinBox_dy_editingFinished()
{
    if(dy != ui->doubleSpinBox_dy->value()){
        dy = ui->doubleSpinBox_dy->value();
        _isNeedUpdateRayImagingTAI = true;
        _isNeedUpdateNonNegativeImagingTAI = true;
    }
}


void ExpImagingModule::on_spinBox_nonNegativeWidth_editingFinished()
{
    if(_signalWidth != ui->spinBox_nonNegativeWidth->value()){
        _signalWidth = ui->spinBox_nonNegativeWidth->value();
        _isNeedUpdateNonNegativeImagingTAI = true;
    }
}
