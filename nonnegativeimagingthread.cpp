#include "nonnegativeimagingthread.h"

NonNegativeImagingThread::NonNegativeImagingThread(TADataBox *TADataBox_,
                                                   QVector<float> *sensorDecare_,
                                                   const RayImagingType &rayImagingType_,
                                                   const NonNegativeImagingType &nonNegativeImagingType_,
                                                   const float &SoS, const int &Fs,
                                                   const int &signalWidth, const double &x1,
                                                   const double &x2, const double &dx,
                                                   const double &y1, const double &y2,
                                                   const double &dy, QObject *parent):
    QThread{parent},
    _TADataBox(TADataBox_), _sensorDecare(sensorDecare_),
    _rayImagingType(rayImagingType_), _nonNegativeImagingType(nonNegativeImagingType_),
    _SoS(SoS), _Fs(Fs), _signalWidth(signalWidth),
    _x1(x1), _x2(x2), _dx(dx), _y1(y1), _y2(y2), _dy(dy), _bstop(false)
{

}

void NonNegativeImagingThread::run()
{
    if(_bstop){
        return;
    }
    //求解射线成像结果
    calculateNonNegativeImaging();
}

void NonNegativeImagingThread::calculateNonNegativeImaging()
{
    if(_bstop){
        return;
    }
    //首先计算Nx和Ny
    int Nx = qFloor((_x2 - _x1) / _dx+0.1)+1;
    int Ny = qFloor((_y2 - _y1) / _dy+0.1)+1;

    if(!_TADataBox->contains("TAI_NonNegativeImaging_xVec")){
        _TADataBox->addData(Nx, "TAI_NonNegativeImaging_xVec");
        for(int i = 0; i < Nx; ++i){
            _TADataBox->getData("TAI_NonNegativeImaging_xVec")[i] = _x1 + i*_dx;
        }
    }
    if(!_TADataBox->contains("TAI_NonNegativeImaging_yVec")){
        _TADataBox->addData(Ny, "TAI_NonNegativeImaging_yVec");
        for(int i = 0; i < Ny; ++i){
            _TADataBox->getData("TAI_NonNegativeImaging_yVec")[i] = _y1 + i*_dy;
        }
    }
    if(!_TADataBox->contains("TAI_NonNegativeImaging")){
        _TADataBox->addData(Ny*Nx, "TAI_NonNegativeImaging");
    }
    QVector<float>& xVec_ = _TADataBox->getData("TAI_NonNegativeImaging_xVec");
    QVector<float>& yVec_ = _TADataBox->getData("TAI_NonNegativeImaging_yVec");
    if(xVec_.size() != Nx){
        xVec_.resize(Nx);
        for(int i = 0; i < Nx; ++i){
            _TADataBox->getData("TAI_NonNegativeImaging_xVec")[i] = _x1 + i*_dx;
        }
    }
    if(yVec_.size() != Ny){
        yVec_.resize(Ny);
        for(int i = 0; i < Ny; ++i){
            _TADataBox->getData("TAI_NonNegativeImaging_yVec")[i] = _y1 + i*_dy;
        }
    }
    QVector<float>& TAI_ = _TADataBox->getData("TAI_NonNegativeImaging");
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
    QVector<float> p_dt(NSens * NTimes);//初始化RF信号时间一次求导向量
    QVector<float> p_rt_width(2*_signalWidth+1);//初始化双边时域信号向量
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
                //将p_rt_width向量全置为零
                for(int k = 0; k< p_rt_width.size(); k++){
                    p_rt_width[k] = 0;
                }
                for(int sensInd = 0; sensInd < NSens; sensInd++){
                    if(_bstop){
                        return;
                    }
                    ToF = qFloor(sqrt((xVec_[i]*1e-3-(*_sensorDecare)[0+sensInd*2])*
                                          (xVec_[i]*1e-3-(*_sensorDecare)[0+sensInd*2])
                                      + (yVec_[j]*1e-3-(*_sensorDecare)[1+sensInd*2])
                                            *(yVec_[j]*1e-3-(*_sensorDecare)[1+sensInd*2]))
                                 / _SoS / dt - 1);
                    if(ToF < NTimes && ToF >= 0){
                    //求解双边时域信号
                    //左右不够的全补零
                    //分情况讨论
                    //case1：左不够
                    if(ToF < _signalWidth){
                        for(int k = 0; k< p_rt_width.size(); k++){
                            if(k >= _signalWidth-ToF){
                                //补完零后依次叠加到p_rt_width向量中
                                p_rt_width[k] += (RFData_[sensInd + (k-_signalWidth+ToF)*NSens] -
                                                  (k-_signalWidth+ToF)*dt*
                                                    p_dt[sensInd + (k-_signalWidth+ToF)*NSens]);
                            }
                        }
                    }//case2:右不够
                    else if(NTimes-1-ToF < _signalWidth){
                        for(int k = 0; k< p_rt_width.size(); k++){
                            if(k < p_rt_width.size() - (_signalWidth-NTimes+1+ToF)){
                                //补完零后依次叠加到p_rt_width向量中
                                p_rt_width[k] += (RFData_[sensInd + (k-_signalWidth+ToF)*NSens] -
                                                  (k-_signalWidth+ToF)*dt*
                                                      p_dt[sensInd + (k-_signalWidth+ToF)*NSens]);
                            }
                        }
                    }
                    //case3:左右都够
                    else{
                        for(int k = 0; k< p_rt_width.size(); k++){
                                //补完零后依次叠加到p_rt_width向量中
                                p_rt_width[k] += (RFData_[sensInd + (k-_signalWidth+ToF)*NSens] -
                                                  (k-_signalWidth+ToF)*dt*
                                                      p_dt[sensInd + (k-_signalWidth+ToF)*NSens]);
                        }
                    }
                    }
                    emit sigUpdateProgress(++count);//更新算法运行状态
                }
                //根据不同的非负成像方式进行成像
                switch(_nonNegativeImagingType){
                case NonNegativeImagingType::Amplitude:
                    TAI_[j + i*Ny] = abs(p_rt_width[_signalWidth]);
                    break;
                case NonNegativeImagingType::Energy1:
                    TAI_[j + i*Ny] = p_rt_width[_signalWidth] * p_rt_width[_signalWidth];
                    break;
                case NonNegativeImagingType::Energy2:
                    for(int k = 0; k< p_rt_width.size(); k++){
                        //补完零后依次叠加到p_rt_width向量中
                        TAI_[j + i*Ny] += p_rt_width[k]*p_rt_width[k];
                    }
                    break;
                case NonNegativeImagingType::Peak_Peak:
                    TAI_[j + i*Ny] = maxVec(p_rt_width) - minVec(p_rt_width);
                    break;
                default:
                    break;
                }
            }
        }
    }else{//DAS成像
        //依次求解每个点的叠加
        for(int i = 0; i < Nx; ++i){
            for(int j = 0; j < Ny; j++){
                //将p_rt_width向量全置为零
                for(int k = 0; k< p_rt_width.size(); k++){
                    p_rt_width[k] = 0;
                }
                for(int sensInd = 0; sensInd < NSens; sensInd++){
                    if(_bstop){
                        return;
                    }
                    ToF = qFloor(sqrt((xVec_[i]*1e-3-(*_sensorDecare)[0+sensInd*2])*
                                          (xVec_[i]*1e-3-(*_sensorDecare)[0+sensInd*2])
                                      + (yVec_[j]*1e-3-(*_sensorDecare)[1+sensInd*2])
                                            *(yVec_[j]*1e-3-(*_sensorDecare)[1+sensInd*2]))
                                 / _SoS / dt - 1);
                    if(ToF < NTimes && ToF >= 0){
                        //求解双边时域信号
                        //左右不够的全补零
                        //分情况讨论
                        //case1：左不够
                        if(ToF < _signalWidth){
                            for(int k = 0; k< p_rt_width.size(); k++){
                                if(k >= _signalWidth-ToF){
                                    //补完零后依次叠加到p_rt_width向量中
                                    p_rt_width[k] += RFData_[sensInd + (k-_signalWidth+ToF)*NSens];
                                }
                            }
                        }//case2:右不够
                        else if(NTimes-1-ToF < _signalWidth){
                            for(int k = 0; k< p_rt_width.size(); k++){
                                if(k < p_rt_width.size() - (_signalWidth-NTimes+1+ToF)){
                                    //补完零后依次叠加到p_rt_width向量中
                                    p_rt_width[k] += RFData_[sensInd + (k-_signalWidth+ToF)*NSens];
                                }
                            }
                        }
                        //case3:左右都够
                        else{
                            for(int k = 0; k< p_rt_width.size(); k++){
                                //补完零后依次叠加到p_rt_width向量中
                                p_rt_width[k] += RFData_[sensInd + (k-_signalWidth+ToF)*NSens];
                            }
                        }
                    }
                    emit sigUpdateProgress(++count);//更新算法运行状态
                }
                //根据不同的非负成像方式进行成像
                switch(_nonNegativeImagingType){
                case NonNegativeImagingType::Amplitude:
                    TAI_[j + i*Ny] = abs(p_rt_width[_signalWidth]);
                    break;
                case NonNegativeImagingType::Energy1:
                    TAI_[j + i*Ny] = p_rt_width[_signalWidth] * p_rt_width[_signalWidth];
                    break;
                case NonNegativeImagingType::Energy2:
                    for(int k = 0; k< p_rt_width.size(); k++){
                        //补完零后依次叠加到p_rt_width向量中
                        TAI_[j + i*Ny] += p_rt_width[k]*p_rt_width[k];
                    }
                    break;
                case NonNegativeImagingType::Peak_Peak:
                    TAI_[j + i*Ny] = maxVec(p_rt_width) - minVec(p_rt_width);
                    break;
                default:
                    break;
                }
            }
        }
    }
    //将运行算法所耗时间传递出去并在日志窗口显示输出
    emit sig_showRunningTime("本次非负成像算法运行时间为：",timer.elapsed() - timerValue);
    emit sigFinishProgress(); emit sig_appendLog("本次非负成像求解完成！！");
    emit sig_setIsUpdateNonNegativeImagingTAIFalse();
    emit sig_plotNonNegativeImagingTAI();//计算结束，绘制结果
}

void NonNegativeImagingThread::slotCancelNonNegativeImagingProgress()
{
    _bstop = true;
}
