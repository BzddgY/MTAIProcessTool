#include "experimentmodulebasicsettingwindow.h"
#include "ui_experimentmodulebasicsettingwindow.h"
#include<QFileDialog>
#include<QMessageBox>

experimentModuleBasicSettingWindow::experimentModuleBasicSettingWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::experimentModuleBasicSettingWindow)
{
    isInitialBasicPara = false;
    ui->setupUi(this);
    ui->comboBox_sensorType->addItems({"线阵","环阵","半环阵","有限弧度阵列"});
    ui->spinBox_totalTimeSteps->setMinimumWidth(ui->spinBox_totalTimeSteps->sizeHint().width()+20); // 基于内容自动调整
    ui->comboBox_LabType->addItems({"MITAI111Lab","Other Lab"});
}

experimentModuleBasicSettingWindow::~experimentModuleBasicSettingWindow()
{
    delete ui;
}

//初始化界面参数
void experimentModuleBasicSettingWindow::initialBasicPara()
{
    if (!isInitialBasicPara){
    ui->lineEdit_datFileLoadPath->setReadOnly(true);
        ui->lineEdit_RFDataFileAddress->setReadOnly(true);
    emit sig_setFs(ui->spinBox_sampleFrequency->value());
    emit sig_setTotalTimeSteps(ui->spinBox_totalTimeSteps->value());
    emit sig_setDelayTimeSteps(ui->spinBox_delayTimeSteps->value());
    emit sig_setSoS(ui->doubleSpinBox_SoS->value());
    emit sig_setStartDatInd(ui->spinBox_startDatInd->value());
    emit sig_setNumOfMeanFrames(ui->spinBox_numOfMeanFrames->value());
    emit sig_setNumOfSensors(ui->spinBox_numOfSensors->value());
    //判断传感器阵列选择并进行操作
    switch (ui->comboBox_sensorType->currentIndex()) {
    case 0://线阵：线阵才需要设置pitch
        ui->doubleSpinBox_radius->setReadOnly(true);
        ui->doubleSpinBox_angleRange->setReadOnly(true);
        emit sig_setArraySensorType(ArraySensorType::LineArray);
        emit sig_setPitch(ui->doubleSpinBox_pitch->value());
        break;
    case 1://环阵：环阵才需要设置radius
        ui->doubleSpinBox_pitch->setReadOnly(true);
        ui->doubleSpinBox_angleRange->setValue(2);//弧角固定为2pi
        ui->doubleSpinBox_angleRange->setReadOnly(true);
        emit sig_setArraySensorType(ArraySensorType::RingArray);
        emit sig_setRadius(ui->doubleSpinBox_radius->value());
        emit sig_setAngleRange(ui->doubleSpinBox_angleRange->value());
        break;
    case 2://半环阵
        ui->doubleSpinBox_pitch->setReadOnly(true);
        ui->doubleSpinBox_angleRange->setValue(1);//弧角固定为1pi
        ui->doubleSpinBox_angleRange->setReadOnly(true);
        emit sig_setArraySensorType(ArraySensorType::SemiRingArray);
        emit sig_setRadius(ui->doubleSpinBox_radius->value());
        emit sig_setAngleRange(ui->doubleSpinBox_angleRange->value());
        break;
    case 3://有限弧度阵列 有限弧度阵列才需要设置弧角angleRange
        ui->doubleSpinBox_pitch->setReadOnly(true);
        emit sig_setArraySensorType(ArraySensorType::FiniteArcArray);
        emit sig_setRadius(ui->doubleSpinBox_radius->value());
        emit sig_setAngleRange(ui->doubleSpinBox_angleRange->value());
        break;
    default:
        break;
    }

    //判断实验室类型选择并进行操作，默认MITAI111Lab
    switch (ui->comboBox_LabType->currentIndex()) {
    case 0://MITAI111Lab：导入数据方式和导入文件标签显示逻辑不太一样
        ui->label_fileAddress->setText(".dat文件导入路径");
        emit sig_setLabType(LabType::MITAI111Lab);
        break;
    case 1://其它实验室：导入数据方式和导入文件标签显示逻辑不太一样
        ui->label_fileAddress->setText("RF数据导入路径");
        emit sig_setLabType(LabType::OtherLab);
        break;
    default:
        break;
    }
    isInitialBasicPara = true;
    }else{
        return;
    }
}

void experimentModuleBasicSettingWindow::slot_initialPara()
{
    initialBasicPara();
}

void experimentModuleBasicSettingWindow::slot_changeNumOfSensors(const int &tmp)
{
    if(ui->spinBox_numOfSensors->value() != tmp){
        ui->spinBox_numOfSensors->setValue(tmp);}
}

void experimentModuleBasicSettingWindow::slot_changeNumOfMeanFrames(const int &tmp)
{
    if(ui->spinBox_numOfMeanFrames->value() != tmp){
        ui->spinBox_numOfMeanFrames->setValue(tmp);}
}

void experimentModuleBasicSettingWindow::on_pushButton_getDatFileLoadPath_clicked()
{
    // QString runPath = QCoreApplication::applicationDirPath();
    QString _fileDirectoryName;
    //判断实验室类型选择并进行操作，默认MITAI111Lab
    switch (ui->comboBox_LabType->currentIndex()) {
    case 0://MITAI111Lab：导入数据方式和导入文件标签显示逻辑不太一样
        _fileDirectoryName = QFileDialog::getExistingDirectory(this,QStringLiteral("选择要处理的.dat文件路径"),"");
        break;
    case 1://其它实验室：导入数据方式和导入文件标签显示逻辑不太一样
        _fileDirectoryName = QFileDialog::getExistingDirectory(this,QStringLiteral("选择要处理的RF文件(.txt, .dat, .csv等)的路径"),"");
        break;
    default:
        break;
    }
    if (!_fileDirectoryName.isEmpty()) {
        // 如果用户选择了文件
        QMessageBox::information(this, "选择的文件", "已选择RF数据文件路径！！");
        ui->lineEdit_datFileLoadPath->setText(_fileDirectoryName);
        emit sig_getDatFileLoadPath(_fileDirectoryName);
    } else {
        // 如果用户没有选择文件
        QMessageBox::information(this, "没有选择文件", "没有选择RF数据文件路径！！");
    }
}


void experimentModuleBasicSettingWindow::on_spinBox_sampleFrequency_editingFinished()
{
    emit sig_setFs(ui->spinBox_sampleFrequency->value());
    // emit sigAppendLog(QString("Fs"));
}


void experimentModuleBasicSettingWindow::on_spinBox_totalTimeSteps_editingFinished()
{
    emit sig_setTotalTimeSteps(ui->spinBox_totalTimeSteps->value());
    // emit sigAppendLog(QString("totalTimeSteps"));
}


void experimentModuleBasicSettingWindow::on_spinBox_delayTimeSteps_editingFinished()
{
    emit sig_setDelayTimeSteps(ui->spinBox_delayTimeSteps->value());
    // emit sigAppendLog(QString("delayT"));
}


void experimentModuleBasicSettingWindow::on_doubleSpinBox_SoS_editingFinished()
{
    emit sig_setSoS(ui->doubleSpinBox_SoS->value());
    // emit sigAppendLog(QString("SoS"));
}


void experimentModuleBasicSettingWindow::on_spinBox_startDatInd_editingFinished()
{
    emit sig_setStartDatInd(ui->spinBox_startDatInd->value());
    // emit sigAppendLog(QString("startDatInd"));
}


void experimentModuleBasicSettingWindow::on_spinBox_numOfMeanFrames_editingFinished()
{
    emit sig_setNumOfMeanFrames(ui->spinBox_numOfMeanFrames->value());
    // emit sigAppendLog(QString("numOfM"));
}


void experimentModuleBasicSettingWindow::on_spinBox_numOfSensors_editingFinished()
{
    emit sig_setNumOfSensors(ui->spinBox_numOfSensors->value());
    // emit sigAppendLog(QString("numOfS"));
}


void experimentModuleBasicSettingWindow::on_doubleSpinBox_pitch_editingFinished()
{
    if (!ui->doubleSpinBox_pitch->isReadOnly()){
        emit sig_setPitch(ui->doubleSpinBox_pitch->value());
    }
    // emit sigAppendLog(QString("pitch"));
}


void experimentModuleBasicSettingWindow::on_doubleSpinBox_radius_editingFinished()
{
    if (!ui->doubleSpinBox_radius->isReadOnly()){
        emit sig_setRadius(ui->doubleSpinBox_radius->value());
    }
    // emit sigAppendLog(QString("radius"));
}


void experimentModuleBasicSettingWindow::on_doubleSpinBox_angleRange_editingFinished()
{
    if (!ui->doubleSpinBox_angleRange->isReadOnly()){
        emit sig_setAngleRange(ui->doubleSpinBox_angleRange->value());
    }
    // emit sigAppendLog(QString("angleRange"));
}


void experimentModuleBasicSettingWindow::on_comboBox_sensorType_currentIndexChanged(int index)
{
    //判断传感器阵列选择并进行操作
    switch (index) {
    case 0://线阵：线阵才需要设置pitch
        ui->doubleSpinBox_radius->setReadOnly(true);
        ui->doubleSpinBox_angleRange->setReadOnly(true);
        ui->doubleSpinBox_pitch->setReadOnly(false);
        emit sig_setArraySensorType(ArraySensorType::LineArray);
        emit sig_setPitch(ui->doubleSpinBox_pitch->value());
        break;
    case 1://环阵：环阵才需要设置radius
        ui->doubleSpinBox_pitch->setReadOnly(true);
        ui->doubleSpinBox_angleRange->setValue(2);//弧角固定为2pi
        ui->doubleSpinBox_angleRange->setReadOnly(true);
        ui->doubleSpinBox_radius->setReadOnly(false);
        emit sig_setArraySensorType(ArraySensorType::RingArray);
        emit sig_setRadius(ui->doubleSpinBox_radius->value());
        emit sig_setAngleRange(ui->doubleSpinBox_angleRange->value());
        break;
    case 2://半环阵
        ui->doubleSpinBox_pitch->setReadOnly(true);
        ui->doubleSpinBox_angleRange->setValue(1);//弧角固定为1pi
        ui->doubleSpinBox_angleRange->setReadOnly(true);
        ui->doubleSpinBox_radius->setReadOnly(false);
        emit sig_setArraySensorType(ArraySensorType::SemiRingArray);
        emit sig_setRadius(ui->doubleSpinBox_radius->value());
        emit sig_setAngleRange(ui->doubleSpinBox_angleRange->value());
        break;
    case 3://有限弧度阵列 有限弧度阵列才需要设置弧角angleRange
        ui->doubleSpinBox_pitch->setReadOnly(true);
        ui->doubleSpinBox_angleRange->setReadOnly(false);
        ui->doubleSpinBox_radius->setReadOnly(false);
        emit sig_setArraySensorType(ArraySensorType::FiniteArcArray);
        emit sig_setRadius(ui->doubleSpinBox_radius->value());
        emit sig_setAngleRange(ui->doubleSpinBox_angleRange->value());
        break;
    default:
        break;
    }
}



void experimentModuleBasicSettingWindow::on_pushButton_preShowSensorsMap_clicked()
{
    //该函数用来预览当前所设置传感器位置，在这里，为了理解方便，我们将横轴设为x轴，纵轴设为y轴，x轴从左到右为为正向，y轴从上到下为正向
    //初始化传感器坐标向量
    initialBasicPara();
    emit sig_preShowSensorMap();

}


void experimentModuleBasicSettingWindow::on_comboBox_LabType_currentIndexChanged(int index)
{
    //判断实验室类型选择并进行操作，默认MITAI111Lab
    switch (index) {
    case 0://MITAI111Lab：导入数据方式和导入文件标签显示逻辑不太一样
        ui->label_fileAddress->setText(".dat文件导入路径");
        emit sig_setLabType(LabType::MITAI111Lab);
        break;
    case 1://其它实验室：导入数据方式和导入文件标签显示逻辑不太一样
        ui->label_fileAddress->setText("RF数据导入路径");
        emit sig_setLabType(LabType::OtherLab);
        break;
    default:
        break;
    }
}


void experimentModuleBasicSettingWindow::on_pushButton_getRFDataFileLoadAddress_clicked()
{
    QString fileAddress;
    //判断实验室类型选择并进行操作，默认MITAI111Lab
    switch (ui->comboBox_LabType->currentIndex()) {
    case 0://MITAI111Lab：导入数据方式和导入文件标签显示逻辑不太一样
        fileAddress = QFileDialog::getOpenFileName(
            this, "选择要处理的RF数据.dat文件",
            "",
            "DAT文件 (*.dat)");
        break;
    case 1://其它实验室：导入数据方式和导入文件标签显示逻辑不太一样
        fileAddress = QFileDialog::getOpenFileName(
            this, "选择要处理的RF数据文件",
            "/",
            "RF数据文件 (*.txt *.csv)");
        break;
    default:
        break;
    }

    if (!fileAddress.isEmpty()) {
        // 如果用户选择了文件
        QMessageBox::information(this, "选择的文件", "已选择RF数据文件！！");
        ui->lineEdit_RFDataFileAddress->setText(fileAddress);
        emit sig_getRFDataFileLoadAddress(fileAddress);
    } else {
        // 如果用户没有选择文件
        QMessageBox::information(this, "没有选择文件", "没有选择RF数据文件");
    }
}

