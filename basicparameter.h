#ifndef BASICPARAMETER_H
#define BASICPARAMETER_H

#include<QObject>
#include<const.h>

class BasicParameter : public QObject
{
    Q_OBJECT
public:
    explicit BasicParameter(QObject *parent = nullptr);
    void setFs(const int& Fs_){_Fs = Fs_;};
    void setTotalTimeSteps(const int& totalTimeSteps_){_totalTimeSteps = totalTimeSteps_;};
    void setSoS(const float& SoS_){_SoS = SoS_;};
    void setDelayTimeSteps(const int& delayTimeSteps_){_delayTimeSteps = delayTimeSteps_;};
    void setStartDatInd(const int& startDatInd_){_startDatInd = startDatInd_;};
    void setNumOfMeanFrames(const int& numOfMeanFrames_){_numOfMeanFrames = numOfMeanFrames_;};
    void setNumOfSensors(const int& numOfSensors_){_numOfSensors = numOfSensors_;};
    void setIsLineArraySensor(const bool& isLineArraySensor_){_isLineArraySensor = isLineArraySensor_;};
    void setPitch(const float& pitch_){_pitch = pitch_;};
    void setRadius(const float& radius_){_radius = radius_;};
    void setAngleRange(const float& angleRange_){_angleRange = angleRange_;};
    void setArraySensorType(const ArraySensorType& arraySensorType_){_arraySensorType = arraySensorType_;};
    void setLabType(const LabType& labType_){_labType = labType_;};
    void setRFDataLoadType(const RFDataLoadType& RFDataLoadType_ ){_RFDataLoadType = RFDataLoadType_;};
    void saveNumOfSensors(){_initialNumOfSensors = _numOfSensors;};
    void resetNumOfSensors(){_numOfSensors = _initialNumOfSensors;}

    const int& getFs(){return _Fs;};
    const int& getTotalTimeSteps(){return _totalTimeSteps;};
    const float& getSoS(){return _SoS;};
    const int& getDelayTimeSteps(){return _delayTimeSteps;};
    const int& getStartDatInd(){return _startDatInd;};
    const int& getNumOfMeanFrames(){return _numOfMeanFrames;};
    const int& getNumOfSensors(){return _numOfSensors;};
    const bool& getIsLineArraySensor(){return _isLineArraySensor;};
    const float& getPitch(){return _pitch;};
    const float& getRadius(){return _radius;};
    const float& getAngleRange(){return _angleRange;};
    const ArraySensorType& getArraySensorType(){return _arraySensorType;};
    const LabType& getLabType(){return _labType;};
    const RFDataLoadType& getRFDataLoadType(){return _RFDataLoadType;};


private:
    int _Fs;//采样频率[MHz]
    int _totalTimeSteps;//总采样点数
    float _SoS;//声速（用于均匀处理时的声速）[m/s]
    int _delayTimeSteps;//采样延时步长
    int _startDatInd;//开始处理帧数
    int _numOfMeanFrames;//帧平均数
    int _numOfSensors;//总通道数
    int _initialNumOfSensors;//最原始设置的通道数
    bool _isLineArraySensor;//true表示线阵，false表示环阵或有限弧度阵列
    float _pitch;//线阵阵元之间的间隔[mm]
    float _radius;//有限弧度阵的半径
    float _angleRange;//弧度阵的弧度范围，2pi表示全环，1pi表示半环，这里以[pi]为单位，后续乘以pi计算
    ArraySensorType _arraySensorType;//传感器阵列类型
    LabType _labType;//lab type
    RFDataLoadType _RFDataLoadType;// load type:PathLoad or AddressLoad

signals:
};

#endif // BASICPARAMETER_H
