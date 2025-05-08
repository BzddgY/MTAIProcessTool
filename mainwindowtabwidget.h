#ifndef MAINWINDOWTABWIDGET_H
#define MAINWINDOWTABWIDGET_H

#include <QTabWidget>
#include<basicparameter.h>
#include<experimentmodulebasicsettingwindow.h>
#include<expprocesswindow.h>
#include<const.h>
#include<QVector>
#include<myfigure.h>
#include<tadatabox.h>
#include<myalgorithm.h>
#include<MyMathCaculator.h>
#include "fftw-3.3.5-dll64/fftw3.h"
#include<filtertool.h>
#include<filtertoolsettingdialog.h>
#include<loukongprocesstool.h>
#include<insertvaluetool.h>
#include<QFileDialog>
#include<QKeyEvent>
#include<QDir>
#include<QFile>
#include<mainwindow.h>
#include<QTMath>
#include<const.h>
#include<matrixplot.h>
#include<QVector>
#include<ToolBox.h>
#include<expsignalprocesstool.h>
#include<expimagingmodule.h>
#include<exppostprocesstool.h>
#include<deconvolutiontool.h>
#include<loadrfdatathread.h>


namespace Ui {
class MainWindowTabWidget;
}

class MainWindowTabWidget : public QTabWidget
{
    Q_OBJECT

public:
    explicit MainWindowTabWidget(QWidget *parent = nullptr);
    ~MainWindowTabWidget();
    void calculateSensorDecare();
    // float minVec(const QVector<float> &vec, const int vecIndex = 0, const int Nx = 0, const int Ny = 0,const VectorType vecType = VectorType::Vector);
    // float maxVec(const QVector<float> &vec, const int vecIndex = 0, const int Nx = 0, const int Ny = 0,const VectorType vecType = VectorType::Vector);
    void initialPara();
    bool preProcessRFData();//预处理传感器信号!!!!!!!!!未测试

private slots:
    void slot_getDatFileLoadPath(const QString& path);
    void slot_getRFDataFileLoadAddress(const QString& path);
    void slot_setTotalTimeSteps(const int&);
    void slot_setFs(const int&);
    void slot_setDelayTimeSteps(const int&);
    void slot_setStartDatInd(const int&);
    void slot_setNumOfMeanFrames(const int&);
    void slot_setNumOfSensors(const int& tmp);
    void slot_setSoS(const float&);
    void slot_setPitch(const float&);
    void slot_setRadius(const float&);
    void slot_setAngleRange(const float&);
    void slot_setArraySensorType(const ArraySensorType);
    void slot_setLabType(const LabType);
    void slot_preShowSensorMap();//画传感器图
    void slot_setRFDataLoadType(const RFDataLoadType);
    void slot_loadRFData();
    void slot_plotAllRFData();
    void slot_savePreProcessRFData();
    void slot_plotSingleRFData(const int & _sensorIndex);
    void slot_plotSingleRFData_PreDomain(const int & index);
    void slot_plotSinglePreProcessedRFData_FreDomain(const int&);
    void slot_plotSingleBeforeAndAfterRFData_FreDomain(const int& index);
    void slot_appendLog(const QString& message);
    void slot_setExpPushButtonLoadRFDatasIcon(const QIcon& iconName);

    //preprocessRFData
    void slot_plotAllPreProcessRFData();//绘制预处理传感器信号的槽函数
    void slot_preProcessRFData();
    void slot_plotSinglePreProcessedRFData(const int &index);//
    void slot_plotSingleBeforeAndAfterRFData(const int &index);//
    void slot_isDeconvolution(const bool& tmp);
    void slot_isFilter(const bool& tmp);
    void slot_isCutZeros(const bool& tmp);
    void slot_isLouKongProcess(const bool& tmp);
    void slot_isInsertValue(const bool& tmp);
    void slot_isHilbert(const bool& tmp);
    void slot_setCutZerosTimeSteps(const int & tmp);
    void slot_setFilterType(const FilterType& tmp);
    void slot_setFilterTool();
    void slot_setLouKongProcessTool();
    void slot_setInsertValueType(const InsertValueType& tmp);
    void slot_setDeconvolutionTool();

    //Imaging Module
    void slot_setRayImagingType(const RayImagingType& tmp);
    void slot_preShowRayImagingTAI();
    void slot_plotRayImagingTAI();//绘制射线成像图
    void slot_setNonNegativeImagingType(const NonNegativeImagingType& tmp);
    void slot_preShowNonNegativeImagingTAI();
    void slot_plotNonNegativeImagingTAI();//绘制非负成像图!!!!!!!!!!1未实现且未连接
    // void slot_setIsReverseImaging(bool tmp);

private:
    void setNumOfSensorsAfterInsertValue(const int& tmp);
    bool loadRFData();//根据导入RF数据方式导入RF数据

    //信号预处理算法
    void filterRFData();//滤波
    void deConvolutionRFData();//去卷积 ！！！！！！！！！！！！！未实现
    void cutZerosRFData();//置零去微波脉冲噪声
    void louKongProcessRFData();//镂空阵列处理
    void insertValueRFData();//插值RF数据！！！！！！！！！！！！！！未完全实现
    void hilbertRFData();//希尔伯特变换处理

private:
    Ui::MainWindowTabWidget *ui;
    QWidget* baseUi;
    QString _lastLoadPath;//上次打开写入文件路径
    QString _lastSavePath;//上次保存路径
    QString _fileDirectoryName;//.dat文件导入路径
    QString _RFDataFileAddress;//射频数据文件绝对地址
    BasicParameter _basicPara;//基本参数：包括传感器所有设置
    QVector<float> _sensorDecare;//传感器位置坐标 一维向量存储2行N列的矩阵元素，[i][j]的索引为[i+j*2]
    bool _isNeedCalculateSensorDecare;//用于判断是否需要更新传感器坐标
    QString _sensorArrayName;//
    TADataBox _TADataBox;//数据管理箱
    bool _isNeedUpdateRFData;//是否需要更新RFData
    bool _isNeedUpdatePreProcessRFData;//是否需要更新预处理信号
    //智能指针管理创建项目的线程
    std::shared_ptr<LoadRFDataThread> _thread_loadRFData;

    //预处理信号参数
    bool _isDeconvolution;//是否去卷积
    bool _isInsertValue;//是否插值
    bool _isFilter;//是否滤波
    bool _isCutZeros;//是否置零
    bool _isLouKongProcess;//是否镂空阵列处理
    bool _isHilbert;//是否希尔伯特处理
    int _cutZerosTimeSteps;//置零步长
    FilterType _filterType;//滤波类型
    FilterTool* _filterTool;//滤波工具
    FilterToolSettingDialog* _filterProcessToolSetting;//用来放置预处理设置工具的
    FilterToolSettingDialog* _louKongProcessToolSetting;//用来放置预处理设置工具的
    FilterToolSettingDialog* _deconvolutionToolSetting;//用来放置卷积设置工具
    LouKongProcessTool* _louKongProcessTool;//镂空处理工具
    InsertValueTool* _insertValueTool;//插值工具
    InsertValueType _insertValueType;//插值类型
    DeconvolutionTool* _deconvolutionTool;//去卷积工具

    //成像参数
    ExpImagingModule* _expImagingModule;
    RayImagingType _rayImagingType;//时域射线反演叠加算法方式
    NonNegativeImagingType _nonNegativeImagingType;//非负射线成像方式
    // bool _isReverseImaging;//成像是否反相


signals:
    void sigAppendLog(const QString& message);
    void sig_initialBasicPara();
    void sig_initialExpSignalProcessPara();
    void sig_setExpPushButtonLoadRFDatasIcon(const QIcon& iconName);
    void sig_setSpinBoxSelectedSensorsMax(const int &max_);
    void sig_setTotalTimeSteps(const int & totalTimeSteps);
    void sigSetPreProcessButtonIcon(const bool& ok);
    void sig_changeNumOfSensors(const int &tmp);
    void sig_changeNumOfMeanFrames(const int& tmp);
    void sig_cancelLoadRFDataProgress();
};

#endif // MAINWINDOWTABWIDGET_H
