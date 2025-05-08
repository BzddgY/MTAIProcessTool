#include "expsignalprocesstool.h"
#include "ui_expsignalprocesstool.h"

ExpSignalProcessTool::ExpSignalProcessTool(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ExpSignalProcessTool)
{
    ui->setupUi(this);
    //设置RF数据导入方式选择
    ui->comboBox_RFDataLoadType->addItems({"文件夹中导入","单文件导入"});
    ui->pushButton_loadRFData->setIcon(QIcon(":/icon/noLoad.png"));
    ui->toolButton_confirmSelectedSensorIndex->setIcon(QIcon(":/icon/noLoad.png"));
    ui->pushButton_preProcessRFData->setIcon(QIcon(":/icon/noLoad.png"));
    _selectedSensorIndex = ui->spinBox_selectedSensorIndex->value();

    //滤波设置
    ui->checkBox_isFilter->setText("滤波处理");
    ui->checkBox_isFilter->setChecked(true);
    ui->checkBox_isFilter->setTristate(false);//仅两种选中选项
    ui->toolButton_setFilterPara->setIcon(QIcon(":/icon/confirmSetting.png"));
    ui->comboBox_filterType->addItems({"矩形窗","海明窗","汉宁窗","布莱克窗","凯瑟尔窗"});
    ui->comboBox_filterType->setCurrentIndex(2);//初始化为汉宁窗

    //去卷积设置
    ui->checkBox_isDeconvolution->setText("去卷积处理");
    ui->checkBox_isDeconvolution->setChecked(false);
    ui->checkBox_isDeconvolution->setTristate(false);//仅两种选中选项
    ui->toolButton_setDeconvolutionPara->setIcon(QIcon(":/icon/confirmSetting.png"));
    ui->comboBox_deConvolutionType->addItems({"自定义EIR"});

    //置零去微波脉冲干扰设置
    ui->checkBox_isCutZeros->setText("去微波脉冲干扰处理");
    ui->checkBox_isCutZeros->setChecked(true);
    ui->checkBox_isCutZeros->setTristate(false);//仅两种选中选项

    //镂空阵列特殊处理设置
    ui->checkBox_isLouKong->setText("镂空阵列特殊处理");
    ui->checkBox_isLouKong->setChecked(false);
    ui->checkBox_isLouKong->setTristate(false);//仅两种选中选项
    ui->toolButton_setLouKongProcessPara->setIcon(QIcon(":/icon/confirmSetting.png"));

    //插值设置
    ui->checkBox_isInsertValue->setText("插值处理");
    ui->checkBox_isInsertValue->setChecked(false);
    ui->checkBox_isInsertValue->setTristate(false);//仅两种选中选项
    ui->toolButton_setInsertValuePara->setIcon(QIcon(":/icon/confirmSetting.png"));
    ui->comboBox_insertValueType->addItems({"线性插值(Linear)","极值引导的插值(EGI)"});

    //希尔伯特设置
    ui->checkBox_isHilbertTransform->setChecked(false);
    ui->checkBox_isHilbertTransform->setTristate(false);//仅两种选中选项

}

ExpSignalProcessTool::~ExpSignalProcessTool()
{
    delete ui;
}

//信号处理界面的参数初始化槽
void ExpSignalProcessTool::slot_initialPara()
{
    switch(ui->comboBox_RFDataLoadType->currentIndex()){
    case 0://PathLoad
        emit sig_setRFDataLoadType(RFDataLoadType::PathLoad);
        break;
    case 1://AddressLoad
        emit sig_setRFDataLoadType(RFDataLoadType::AddressLoad);
        break;
    default:
        emit sig_setRFDataLoadType(RFDataLoadType::PathLoad);
        break;
    }
    emit sig_setCutZerosTimeSteps(ui->spinBox_cutZerosTimesteps->value());
    emit sig_setFilterType(FilterType::hanningWindow);
    emit sig_setInsertValueType(InsertValueType::linear);
}

void ExpSignalProcessTool::slot_setPushButtonLoadRFDatasIcon(const QIcon& iconName)
{
    ui->pushButton_loadRFData->setIcon(iconName);
}

void ExpSignalProcessTool::slot_setSpinBoxSelectedSensorsMax(const int &max_)
{
    ui->spinBox_selectedSensorIndex->setMaximum(max_);
}

void ExpSignalProcessTool::slot_setTotalTimeSteps(const int &totalTimeSteps)
{
    ui->spinBox_cutZerosTimesteps->setMaximum(totalTimeSteps);
}

void ExpSignalProcessTool::slot_setPreProcessButtonIcon(const bool& ok)
{
    if (ok){
        ui->pushButton_preProcessRFData->setIcon(QIcon(":/icon/LoadDone.png"));
    }else{
        ui->pushButton_preProcessRFData->setIcon(QIcon(":/icon/noLoad.png"));
    }
}

void ExpSignalProcessTool::on_comboBox_RFDataLoadType_currentIndexChanged(int index)
{
    switch(index){
    case 0://PathLoad
        emit sig_setRFDataLoadType(RFDataLoadType::PathLoad);
        break;
    case 1://AddressLoad
        emit sig_setRFDataLoadType(RFDataLoadType::AddressLoad);
        break;
    default:
        emit sig_setRFDataLoadType(RFDataLoadType::PathLoad);
        break;
    }
}


void ExpSignalProcessTool::on_pushButton_loadRFData_clicked()
{
    emit sig_loadRFData();
}


void ExpSignalProcessTool::on_pushButton_plotAllRFData_clicked()
{
    emit sig_plotAllRFData();
}


void ExpSignalProcessTool::on_pushButton_savePreProcessRFData_clicked()
{
    emit sig_savePreProcessRFData();
}


void ExpSignalProcessTool::on_toolButton_confirmSelectedSensorIndex_clicked()
{
    _selectedSensorIndex = ui->spinBox_selectedSensorIndex->value();
    ui->toolButton_confirmSelectedSensorIndex->setIcon(QIcon(":/icon/LoadDone.png"));
}


void ExpSignalProcessTool::on_pushButton_plotSingleRFData_clicked()
{
    emit sig_plotSingleRFData(_selectedSensorIndex);
}


void ExpSignalProcessTool::on_spinBox_selectedSensorIndex_editingFinished()
{
    if(_selectedSensorIndex != ui->spinBox_selectedSensorIndex->value()){
        ui->toolButton_confirmSelectedSensorIndex->setIcon(QIcon(":/icon/noLoad.png"));
    }
}


void ExpSignalProcessTool::on_pushButton_plotAllPreProcessRFData_clicked()
{
    emit sig_plotAllPreProcessRFData();
}


void ExpSignalProcessTool::on_pushButton_preProcessRFData_clicked()
{
    emit sig_preProcessRFData();
}


void ExpSignalProcessTool::on_checkBox_isDeconvolution_stateChanged(int arg1)
{
    switch(arg1){
    case 0://未选中
        emit sig_isDeconvolution(false);
        break;
    case 2://选中
        emit sig_isDeconvolution(true);
        break;
    }
    ui->pushButton_preProcessRFData->setIcon(QIcon(":/icon/noLoad.png"));
}


void ExpSignalProcessTool::on_checkBox_isFilter_stateChanged(int arg1)
{
    switch(arg1){
    case 0://未选中
        emit sig_isFilter(false);
        break;
    case 2://选中
        emit sig_isFilter(true);
        break;
    }
    ui->pushButton_preProcessRFData->setIcon(QIcon(":/icon/noLoad.png"));
}


void ExpSignalProcessTool::on_checkBox_isCutZeros_stateChanged(int arg1)
{
    switch(arg1){
    case 0://未选中
        emit sig_isCutZeros(false);
        break;
    case 2://选中
        emit sig_isCutZeros(true);
        break;
    }
    ui->pushButton_preProcessRFData->setIcon(QIcon(":/icon/noLoad.png"));
}


void ExpSignalProcessTool::on_checkBox_isLouKong_stateChanged(int arg1)
{
    switch(arg1){
    case 0://未选中
        emit sig_isLouKong(false);
        break;
    case 2://选中
        emit sig_isLouKong(true);
        break;
    }
    ui->pushButton_preProcessRFData->setIcon(QIcon(":/icon/noLoad.png"));
}


void ExpSignalProcessTool::on_checkBox_isInsertValue_stateChanged(int arg1)
{
    switch(arg1){
    case 0://未选中
        emit sig_isInsertValue(false);
        break;
    case 2://选中
        emit sig_isInsertValue(true);
        break;
    }
    ui->pushButton_preProcessRFData->setIcon(QIcon(":/icon/noLoad.png"));
}


void ExpSignalProcessTool::on_pushButton_plotSinglePreProcessedRFData_clicked()
{
    emit sig_plotSinglePreProcessedRFData(_selectedSensorIndex);
}


void ExpSignalProcessTool::on_pushButton_plotSingleBeforeAndAfterRFData_clicked()
{
    emit sig_plotSingleBeforeAndAfterRFData(_selectedSensorIndex);
}


void ExpSignalProcessTool::on_spinBox_cutZerosTimesteps_editingFinished()
{
    emit sig_setCutZerosTimeSteps(ui->spinBox_cutZerosTimesteps->value());
}


void ExpSignalProcessTool::on_pushButton_plotSingleRFData_PreDomain_clicked()
{
    emit sig_plotSingleRFData_PreDomain(_selectedSensorIndex);
}


void ExpSignalProcessTool::on_pushButton_plotSinglePreProcessedRFData_FreDomain_clicked()
{
    emit sig_plotSinglePreProcessedRFData_FreDomain(_selectedSensorIndex);
}


void ExpSignalProcessTool::on_pushButton_plotSingleBeforeAndAfterRFData_FreDomain_clicked()
{
    emit sig_plotSingleBeforeAndAfterRFData_FreDomain(_selectedSensorIndex);
}


void ExpSignalProcessTool::on_comboBox_filterType_currentIndexChanged(int index)
{
    switch(index){
    case 0:
        emit sig_setFilterType(FilterType::rectangleWindow);
        break;
    case 1:
        emit sig_setFilterType(FilterType::hammingWindow);
        break;
    case 2:
        emit sig_setFilterType(FilterType::hanningWindow);
        break;
    case 3:
        emit sig_setFilterType(FilterType::blackManWindow);
        break;
    case 4:
        emit sig_setFilterType(FilterType::kaiserWindow);
        break;
    default:
        break;
    }
    ui->pushButton_preProcessRFData->setIcon(QIcon(":/icon/noLoad.png"));
}


void ExpSignalProcessTool::on_toolButton_setFilterPara_clicked()
{
    emit sig_setFilterTool();
}


void ExpSignalProcessTool::on_toolButton_setLouKongProcessPara_clicked()
{
    emit sig_setLouKongProcessTool();
}


void ExpSignalProcessTool::on_comboBox_insertValueType_currentIndexChanged(int index)
{
    switch(index){
    case 0:
        emit sig_setInsertValueType(InsertValueType::linear);
        break;
    case 1:
        emit sig_setInsertValueType(InsertValueType::linear);
        break;
    default:
        break;
    }
}


void ExpSignalProcessTool::on_checkBox_isHilbertTransform_stateChanged(int arg1)
{
    switch(arg1){
    case 0://未选中
        emit sig_isHilbert(false);
        break;
    case 2://选中
        emit sig_isHilbert(true);
        break;
    }
    ui->pushButton_preProcessRFData->setIcon(QIcon(":/icon/noLoad.png"));
}


void ExpSignalProcessTool::on_toolButton_setDeconvolutionPara_clicked()
{
    emit sig_setDeconvolutionTool();
}

