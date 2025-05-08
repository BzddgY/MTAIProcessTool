#include "loukongprocesstool.h"
#include "ui_loukongprocesstool.h"
#include<QMessageBox>

LouKongProcessTool::LouKongProcessTool(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LouKongProcessTool)
{
    ui->setupUi(this);
    _currentSensInd = 1;
    _NSens = 128;_NTimes = 4096;ui->spinBox_shiftSteps->setMaximum(_NTimes);
    ui->spinBox_sensorIndex->setMaximum(_NSens);
    ui->label_showSensorIndex->setText("通道"+QString::number(_currentSensInd)+"采集信号的处理设置：");
    ui->comboBox_shiftType->addItems({"右移","左移"});
    initialPara();
    initialLouKongProcessSetting();
}

LouKongProcessTool::~LouKongProcessTool()
{
    delete ui;
}

void LouKongProcessTool::slot_setNSens(const int &tmp)
{
    if(_NSens != tmp){
        _NSens = tmp;
        initialPara();
        ui->spinBox_sensorIndex->setMaximum(_NSens);
    }
}

void LouKongProcessTool::slot_setNTimes(const int &tmp)
{
    if(_NTimes != tmp){
        _NTimes = tmp;
        ui->spinBox_shiftSteps->setMaximum(_NTimes);
    }
}

void LouKongProcessTool::initialPara()
{
    _shiftSteps.resize(_NSens);//移位多少
    _isShiftRight.resize(_NSens);//是否右移
    _compensateValue.resize(_NSens);//补偿倍数
    for(int i = 0; i < _NSens; ++i){
        _shiftSteps[i] = 0;
        _isShiftRight[i] = true;
        _compensateValue[i] = 1;
    }
}

void LouKongProcessTool::initialLouKongProcessSetting()
{
    //预先设定好镂空阵列中的设置；
    for(int i = 0; i < _NSens; ++i){
        if(i>48 && i< 80){
            _compensateValue[i] = -2;
            if(i == 49){
                _shiftSteps[i] = 6;
                _isShiftRight[i] = false;
            }else if(i == 51){
                _shiftSteps[i] = 8;
                _isShiftRight[i] = false;
            }else{
                _shiftSteps[i] = 20;
            }
        }
    }
}

void LouKongProcessTool::runLouKongProcess(QVector<float> &inData)
{
    QVector<float> tmp_(_NTimes);
    //依次对输入数据进行处理
    for(int i = 0; i < _NSens; ++i){
        //拷贝一份
        for(int j = 0; j < _NTimes; j++){
            tmp_[j] = inData[i + j*_NSens];
        }
        //移位可以与补偿一起进行
        for(int j = 0; j < _NTimes; ++j){
            if(_isShiftRight[i]){
                if(j >= _shiftSteps[i]){
                    inData[i + j*_NSens] = _compensateValue[i]*tmp_[j-_shiftSteps[i]];
                }else{
                    inData[i + j*_NSens] = 0;
                }
            }else{
                if(j < _NTimes-_shiftSteps[i]){
                    inData[i + j*_NSens] = _compensateValue[i]*tmp_[j+_shiftSteps[i]];
                }else{
                    inData[i + j*_NSens] = 0;
                }
            }
        }
    }
}

void LouKongProcessTool::on_pushButton_clicked()
{
    if(_currentSensInd != ui->spinBox_sensorIndex->value()){
        _currentSensInd = ui->spinBox_sensorIndex->value();
        //分别显示该通道的设置
        if(_isShiftRight[_currentSensInd-1]){
            ui->comboBox_shiftType->setCurrentIndex(0);//右移
        }
        else{
            ui->comboBox_shiftType->setCurrentIndex(1);//左移
        }
        ui->doubleSpinBox->setValue(_compensateValue[_currentSensInd-1]);
        ui->spinBox_shiftSteps->setValue(_shiftSteps[_currentSensInd-1]);
        ui->label_showSensorIndex->setText("通道"+QString::number(_currentSensInd)+"采集信号的处理设置：");
    }
}


void LouKongProcessTool::on_pushButton_confirmCurrentSetting_clicked()
{
    switch(ui->comboBox_shiftType->currentIndex()){
    case 0://右移
        _isShiftRight[_currentSensInd-1] = true;
        break;
    case 1://左移
        _isShiftRight[_currentSensInd-1] = false;
        break;
    }
    _compensateValue[_currentSensInd-1] =  ui->doubleSpinBox->value();
    _shiftSteps[_currentSensInd-1] = ui->spinBox_shiftSteps->value();
}


void LouKongProcessTool::on_pushButton_turnToDefaultSetting_clicked()
{
    if(_NSens == 128){
        initialLouKongProcessSetting();
        return;
    }
    QMessageBox::information(this, "提示", "初始化失败，默认镂空阵列为128个阵元！");
}

