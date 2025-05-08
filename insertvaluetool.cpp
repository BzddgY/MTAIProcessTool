#include "insertvaluetool.h"
#include "ui_insertvaluetool.h"

InsertValueTool::InsertValueTool(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InsertValueTool)
{
    ui->setupUi(this);
}

InsertValueTool::~InsertValueTool()
{
    delete ui;
}

void InsertValueTool::runInsertValue(QVector<float> &inData, const int &NSens_, const int &NTimes_, const InsertValueType &indertType_, const int &Fs_, const float &R_)
{
    //插值默认都只插中间传感器值，故长度由NSens_到NSens_+NSens_-1
    //备份数据
    QVector<float> tmp(NSens_*NTimes_);
    for(int i = 0; i < tmp.size(); ++i){
        tmp[i] = inData[i];
    }
    inData.resize((2*NSens_-1)*NTimes_);
    //根据不同的类型进行插值
    switch(indertType_){
    case InsertValueType::linear:
        //线性插值，直接用相邻传感器的均值插为间隔传感器的采集值
        for(int i = 0; i < (2*NSens_-1); i++){
            if((i+1)%2 == 0){
                for(int j = 0; j < NTimes_; j++){
                    inData[i+j*(2*NSens_-1)] = (tmp[(i+1)/2+j*NSens_]+tmp[(i+1)/2-1 + j*NSens_])/2;
                }
            }else{
                for(int j = 0; j < NTimes_; j++){
                    inData[i+j*(2*NSens_-1)] = tmp[qFloor((i+1)/2)+j*NSens_];
                }
            }
        }
        break;
    case InsertValueType::egi:
        break;
    }
}
