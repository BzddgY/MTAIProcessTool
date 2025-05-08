#ifndef EXPIMAGINGMODULE_H
#define EXPIMAGINGMODULE_H

#include <QWidget>
#include<const.h>
#include<tadatabox.h>
#include<rayimagingthread.h>
#include<QProgressDialog>
#include<nonnegativeimagingthread.h>

namespace Ui {
class ExpImagingModule;
}

class ExpImagingModule : public QWidget
{
    Q_OBJECT

public:
    explicit ExpImagingModule(QWidget *parent = nullptr);
    ~ExpImagingModule();
    //根据成像方式成像
    void runRayImaging(TADataBox& TADataBox_, QVector<float>& sensorDecare_,
                       const RayImagingType& rayImagingType_, const float& SoS, const int& Fs);
    //非负成像
    void runNonNegativeImaging(TADataBox& TADataBox_, QVector<float>& sensorDecare_, const RayImagingType& rayImagingType_,
                               const NonNegativeImagingType& nonNegativeImagingType, const float& SoS, const int& Fs);


private slots:
    void on_comboBox_rayReconstructionType_currentIndexChanged(int index);

    void on_pushButton_preShowRayImagingTAI_clicked();

    void on_checkBox_stateChanged(int arg1);

    void slotUpdateProgress(int count);
    void slotFinishProgress();
    void slotCancelProgress();
    void slot_showRunningTime(QString runningType, int runningTimes);//注意前面为运行的算法，后面为所耗ms时间
    void slot_appendLog(QString message);
    void slotUpdateNonNegativeImagingProgress(int count);
    void slotFinishNonNegativeImagingProgress();
    void slotCancelNonNegativeImagingProgress();

    void on_comboBox_nonNegativeReconType_currentIndexChanged(int index);

    void on_pushButton_preShowRayImagingTAI_2_clicked();

    void slot_plotRayImagingTAI();//发射绘制射线成像图信号传给主窗口
    void slot_plotNonNegativeImagingTAI();

    void slot_setIsUpdateRayImagingTAIFalse();
    void slot_setIsUpdateNonNegativeImagingTAIFalse();

    void on_doubleSpinBox_x1_valueChanged(double arg1);

    void on_doubleSpinBox_x1_editingFinished();

    void on_doubleSpinBox_x2_editingFinished();

    void on_doubleSpinBox_dx_editingFinished();

    void on_doubleSpinBox_y1_editingFinished();

    void on_doubleSpinBox_y2_editingFinished();

    void on_doubleSpinBox_dy_editingFinished();

    void on_spinBox_nonNegativeWidth_editingFinished();

signals:
    void sig_setRayImagingType(const RayImagingType&);
    void sig_setNonNegativeImagingType(const NonNegativeImagingType&);
    void sig_preShowRayImagingTAI();
    void sig_preShowNonNegativeImagingTAI();
    void sigCancelProgress();
    void sigCancelNonNegativeImagingProgress();
    void sigAppendLog(QString message);
    void sig_plotRayImagingTAI();
    void sig_plotNonNegativeImagingTAI();
    // void sig_isReverseImaging(const bool);

private:
    Ui::ExpImagingModule *ui;
    float _isReverseImaging;//TRUE：-1；false：1
    double x1,x2,dx,y1,y2,dy;int _signalWidth;
    //智能指针管理创建项目的线程
    std::shared_ptr<rayImagingThread> _thread_rayImaging;
    QProgressDialog* _dialog_progress;
    int _maxCount;
    bool _isNeedUpdateRayImagingTAI;

    //非负成像参数
    std::shared_ptr<NonNegativeImagingThread> _thread_nonNegativeImaging;
    QProgressDialog* _dialog_nonNegativeImaging_progress;
    int _maxCount_nonNegativeImaging;
    bool _isNeedUpdateNonNegativeImagingTAI;
};

#endif // EXPIMAGINGMODULE_H
