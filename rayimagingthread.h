#ifndef RAYIMAGINGTHREAD_H
#define RAYIMAGINGTHREAD_H

//该类用来采用子线程实现射线成像过程
#include <QObject>
#include <QThread>
#include<const.h>
#include<tadatabox.h>
#include<QElapsedTimer>

class rayImagingThread : public QThread
{
    Q_OBJECT
public:
    explicit rayImagingThread(TADataBox* TADataBox_,
                              QVector<float>* sensorDecare_,
                              const RayImagingType& rayImagingType_,
                              const float& SoS,
                              const int& Fs,
                              const int& isReverseImaging,
                              const double& x1,
                              const double& x2,
                              const double& dx,
                              const double& y1,
                              const double& y2,
                              const double& dy,
                              QObject *parent = nullptr);
    ~ rayImagingThread(){};
protected:
    virtual void run();
private:
    TADataBox* _TADataBox;
    QVector<float>* _sensorDecare;
    RayImagingType _rayImagingType;
    float _SoS;
    int _Fs;
    int _isReverseImaging;
    double _x1,_x2,_dx,_y1,_y2,_dy;
    bool _bstop;

private:
    void calculateRayImaging();
signals:
    void sigUpdateProgress(int);
    void sigFinishProgress();
    void sig_showRunningTime(QString runningType, int runningTimes);//注意前面为运行的算法，后面为所耗ms时间
    void sig_plotRayImagingTAI();
    void sig_setIsUpdateRayImagingTAIFalse();
    void sig_appendLog(QString message);
public slots:
    void slotCancelProgress();

};

#endif // RAYIMAGINGTHREAD_H
