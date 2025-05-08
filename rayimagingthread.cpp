#include "rayimagingthread.h"

rayImagingThread::rayImagingThread(TADataBox *TADataBox_,
                                   QVector<float> * sensorDecare_,
                                   const RayImagingType &rayImagingType_,
                                   const float &SoS, const int &Fs,
                                   const int &isReverseImaging,
                                   const double& x1,
                                   const double& x2,
                                   const double& dx,
                                   const double& y1,
                                   const double& y2,
                                   const double& dy,
                                   QObject *parent):
    QThread{parent},
    _TADataBox(TADataBox_), _sensorDecare(sensorDecare_),
    _rayImagingType(rayImagingType_), _SoS(SoS),
    _Fs(Fs), _isReverseImaging(isReverseImaging),
    _x1(x1), _x2(x2), _dx(dx), _y1(y1), _y2(y2), _dy(dy), _bstop(false)
{

}

void rayImagingThread::run()
{
    if(_bstop){
        return;
    }
    //求解射线成像结果
    calculateRayImaging();
}

void rayImagingThread::calculateRayImaging()
{
    if(_bstop){
        return;
    }
    //首先计算Nx和Ny
    int Nx = qFloor((_x2 - _x1) / _dx+0.1)+1;
    int Ny = qFloor((_y2 - _y1) / _dy+0.1)+1;

    if(!_TADataBox->contains("TAI_RayImaging_xVec")){
        _TADataBox->addData(Nx, "TAI_RayImaging_xVec");
        for(int i = 0; i < Nx; ++i){
            _TADataBox->getData("TAI_RayImaging_xVec")[i] = _x1 + i*_dx;
        }
    }
    if(!_TADataBox->contains("TAI_RayImaging_yVec")){
        _TADataBox->addData(Ny, "TAI_RayImaging_yVec");
        for(int i = 0; i < Ny; ++i){
            _TADataBox->getData("TAI_RayImaging_yVec")[i] = _y1 + i*_dy;
        }
    }
    if(!_TADataBox->contains("TAI_RayImaging")){
        _TADataBox->addData(Ny*Nx, "TAI_RayImaging");
    }
    QVector<float>& xVec_ = _TADataBox->getData("TAI_RayImaging_xVec");
    QVector<float>& yVec_ = _TADataBox->getData("TAI_RayImaging_yVec");
    if(xVec_.size() != Nx){
        xVec_.resize(Nx);
        for(int i = 0; i < Nx; ++i){
            _TADataBox->getData("TAI_RayImaging_xVec")[i] = _x1 + i*_dx;
        }
    }
    if(yVec_.size() != Ny){
        yVec_.resize(Ny);
        for(int i = 0; i < Ny; ++i){
            _TADataBox->getData("TAI_RayImaging_yVec")[i] = _y1 + i*_dy;
        }
    }
    QVector<float>& TAI_ = _TADataBox->getData("TAI_RayImaging");
    TAI_.resize(Ny*Nx);
    //全置零；
    for(int i = 0; i < TAI_.size(); ++i){
        if(_bstop){
            return;
        }
        TAI_[i] = 0;
    }
    //循环求解
    //若为BP算法需要先计算导数再求解
    int NSens = _TADataBox->viewData("PreProcessedRFData_yVec").size();
    int NTimes = _TADataBox->viewData("PreProcessedRFData_xVec").size();
    const QVector<float>& RFData_ = _TADataBox->viewData("PreProcessedRFData");
    float dt = 1/static_cast<float>(_Fs)*1e-6;//采样时间间隔(s)
    QVector<float> p_dt(NSens * NTimes);
    int ToF;int count(0);
    //计算耗时
    QElapsedTimer timer;
    int timerValue = timer.elapsed();
    if(_rayImagingType == RayImagingType::BP){//BP成像
        for(int i = 0; i < NSens; ++i){
            for(int j = 0; j < NTimes-1; ++j){
                if(_bstop){
                    return;
                }
                p_dt[i + j*NSens] = (RFData_[i + (j+1)*NSens] - RFData_[i + j*NSens]) / dt;//后向差分求导
            }
        }
        //依次求解每个点的叠加
        for(int i = 0; i < Nx; ++i){
            for(int j = 0; j < Ny; j++){
                for(int sensInd = 0; sensInd < NSens; sensInd++){
                    if(_bstop){
                        return;
                    }
                    ToF = qFloor(sqrt((xVec_[i]*1e-3-(*_sensorDecare)[0+sensInd*2])*
                                          (xVec_[i]*1e-3-(*_sensorDecare)[0+sensInd*2])
                                      + (yVec_[j]*1e-3-(*_sensorDecare)[1+sensInd*2])
                                            *(yVec_[j]*1e-3-(*_sensorDecare)[1+sensInd*2]))
                                 / _SoS / dt);
                    if(ToF < NTimes && ToF >= 0){
                        TAI_[j + i*Ny] += (RFData_[sensInd + ToF*NSens] - ToF*dt*p_dt[sensInd + ToF*NSens])*_isReverseImaging;
                    }
                    emit sigUpdateProgress(++count);//更新算法运行状态
                }
            }
        }
    }else{//DAS成像
        //依次求解每个点的叠加
        for(int i = 0; i < Nx; ++i){
            for(int j = 0; j < Ny; j++){
                for(int sensInd = 0; sensInd < NSens; sensInd++){
                    if(_bstop){
                        return;
                    }
                    ToF = qFloor(sqrt((xVec_[i]*1e-3-(*_sensorDecare)[0+sensInd*2])*
                                          (xVec_[i]*1e-3-(*_sensorDecare)[0+sensInd*2])
                                      + (yVec_[j]*1e-3-(*_sensorDecare)[1+sensInd*2])
                                            *(yVec_[j]*1e-3-(*_sensorDecare)[1+sensInd*2]))
                                 / _SoS / dt);
                    if(ToF < NTimes && ToF >= 0){
                        TAI_[j + i*Ny] += (RFData_[sensInd + ToF*NSens])*_isReverseImaging;
                    }
                    emit sigUpdateProgress(++count);//更新算法运行状态
                }
            }
        }
    }
    //将运行算法所耗时间传递出去并在日志窗口显示输出
    emit sig_showRunningTime("本次射线算法运行时间为：",timer.elapsed() - timerValue);
    emit sigFinishProgress(); emit sig_appendLog("本次射线成像求解完成！！");
    emit sig_setIsUpdateRayImagingTAIFalse();
    emit sig_plotRayImagingTAI();//计算结束，绘制结果
}

void rayImagingThread::slotCancelProgress()
{
    _bstop = true;
}
