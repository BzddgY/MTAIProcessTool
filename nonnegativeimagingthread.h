#ifndef NONNEGATIVEIMAGINGTHREAD_H
#define NONNEGATIVEIMAGINGTHREAD_H

#include <QObject>
#include <QThread>
#include<const.h>
#include<tadatabox.h>
#include<QElapsedTimer>
#include<MyMathCaculator.h>

//该类用来实现非负成像
class NonNegativeImagingThread : public QThread
{
    Q_OBJECT
public:
    explicit NonNegativeImagingThread(TADataBox* TADataBox_,
                                      QVector<float>* sensorDecare_,
                                      const RayImagingType& rayImagingType_,
                                      const NonNegativeImagingType& nonNegativeImagingType_,
                                      const float& SoS,
                                      const int& Fs,
                                      const int& signalWidth,
                                      const double& x1,
                                      const double& x2,
                                      const double& dx,
                                      const double& y1,
                                      const double& y2,
                                      const double& dy,
                                      QObject *parent = nullptr);
    ~ NonNegativeImagingThread(){};
protected:
    virtual void run();
private:
    TADataBox* _TADataBox;
    QVector<float>* _sensorDecare;
    RayImagingType _rayImagingType;
    NonNegativeImagingType _nonNegativeImagingType;
    float _SoS;
    int _Fs;
    int _signalWidth;//单边信号宽度
    double _x1,_x2,_dx,_y1,_y2,_dy;
    bool _bstop;

private:
    void calculateNonNegativeImaging();
signals:
    void sigUpdateProgress(int);
    void sigFinishProgress();
    void sig_appendLog(QString message);
    void sig_showRunningTime(QString runningType, int runningTimes);//注意前面为运行的算法，后面为所耗ms时间
    void sig_plotNonNegativeImagingTAI();
    void sig_setIsUpdateNonNegativeImagingTAIFalse();
public slots:
    void slotCancelNonNegativeImagingProgress();
};

#endif // NONNEGATIVEIMAGINGTHREAD_H
