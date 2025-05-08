#ifndef EXPERIMENTMODULEBASICSETTINGWINDOW_H
#define EXPERIMENTMODULEBASICSETTINGWINDOW_H

#include <QWidget>
#include<const.h>

namespace Ui {
class experimentModuleBasicSettingWindow;
}

class experimentModuleBasicSettingWindow : public QWidget
{
    Q_OBJECT

public:
    explicit experimentModuleBasicSettingWindow(QWidget *parent = nullptr);
    ~experimentModuleBasicSettingWindow();
    void initialBasicPara();
private:
    Ui::experimentModuleBasicSettingWindow *ui;
    bool isInitialBasicPara;
public slots:
    void slot_initialPara();
    void slot_changeNumOfSensors(const int& tmp);
    void slot_changeNumOfMeanFrames(const int& tmp);

signals:
    void sigAppendLog(const QString& message);
    void sig_getDatFileLoadPath(const QString&);
    void sig_getRFDataFileLoadAddress(const QString&);
    void sig_setFs(const int&);
    void sig_setTotalTimeSteps(const int&);
    void sig_setDelayTimeSteps(const int&);
    void sig_setSoS(const float&);
    void sig_setStartDatInd(const int&);
    void sig_setNumOfMeanFrames(const int&);
    void sig_setNumOfSensors(const int&);
    void sig_setPitch(const float&);
    void sig_setRadius(const float&);
    void sig_setAngleRange(const float&);
    void sig_setArraySensorType(const ArraySensorType);
    void sig_setLabType(const LabType);
    void sig_preShowSensorMap();
private slots:
    void on_pushButton_getDatFileLoadPath_clicked();
    void on_spinBox_sampleFrequency_editingFinished();
    void on_spinBox_totalTimeSteps_editingFinished();
    void on_spinBox_delayTimeSteps_editingFinished();
    void on_doubleSpinBox_SoS_editingFinished();
    void on_spinBox_startDatInd_editingFinished();
    void on_spinBox_numOfMeanFrames_editingFinished();
    void on_spinBox_numOfSensors_editingFinished();
    void on_doubleSpinBox_pitch_editingFinished();
    void on_doubleSpinBox_radius_editingFinished();
    void on_doubleSpinBox_angleRange_editingFinished();
    void on_comboBox_sensorType_currentIndexChanged(int index);
    void on_pushButton_preShowSensorsMap_clicked();
    void on_comboBox_LabType_currentIndexChanged(int index);
    void on_pushButton_getRFDataFileLoadAddress_clicked();
};

#endif // EXPERIMENTMODULEBASICSETTINGWINDOW_H
