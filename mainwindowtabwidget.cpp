#include "mainwindowtabwidget.h"
#include "ui_mainwindowtabwidget.h"


MainWindowTabWidget::MainWindowTabWidget(QWidget *parent)
    : QTabWidget(parent)
    , ui(new Ui::MainWindowTabWidget)
{
    baseUi = new QWidget(nullptr);
    ui->setupUi(this);_isNeedCalculateSensorDecare = true;
    _isNeedUpdateRFData = true;
    _isNeedUpdatePreProcessRFData = true;

    //预处理信号参数
    _isDeconvolution  = false;//是否去卷积
    _isInsertValue = false;//是否插值
    _isFilter = true;//是否滤波
    _isCutZeros = true;//是否置零
    _isLouKongProcess = false;//是否镂空阵列处理
    _isHilbert = false;//是否希尔伯特变换处理
    _filterProcessToolSetting = nullptr;
    _louKongProcessToolSetting = nullptr;
    _deconvolutionToolSetting = nullptr;
    _louKongProcessTool = nullptr;
    _insertValueTool = nullptr;

    //成像参数定义
    _rayImagingType = RayImagingType::BP;//射线成像方式
    _nonNegativeImagingType = NonNegativeImagingType::Amplitude;//非负成像方式
    // _isReverseImaging = false;

    //设置窗口中间可以自适应左右拖动
    // ui->expBasicParaSettingWgt->setEdgeBeReSized(false,false,true,false);//top bottum right left
    // connect(ui->expBasicParaSettingWgt, &DragResizeWgt::sizeChange, [=](){
    //     qDebug() << "this->width()" << this->width() << "ui->widget->width()"<< ui->expBasicParaSettingWgt->width();
    //     int remainingWidth = this->width() -  ui->expBasicParaSettingWgt->width();
    //     ui->expProcessWgt->setFixedWidth(remainingWidth);
    // });
    // ui->expBasicParaSettingWgt->setLayout(ui->expBasicSettingLayout);
    // ui->expProcessWgt->setLayout(ui->expProcessLayout);
    //设置参数设置模块
    experimentModuleBasicSettingWindow* expMBSWind = new experimentModuleBasicSettingWindow;

    //连接实验模块参数设置信号与主模块参数槽
    connect(expMBSWind, &experimentModuleBasicSettingWindow::sigAppendLog, this, &MainWindowTabWidget::sigAppendLog);
    connect(expMBSWind, &experimentModuleBasicSettingWindow::sig_getDatFileLoadPath, this, &MainWindowTabWidget::slot_getDatFileLoadPath);
    connect(expMBSWind, &experimentModuleBasicSettingWindow::sig_getRFDataFileLoadAddress, this, &MainWindowTabWidget::slot_getRFDataFileLoadAddress);
    connect(expMBSWind, &experimentModuleBasicSettingWindow::sig_setFs, this, &MainWindowTabWidget::slot_setFs);
    connect(expMBSWind, &experimentModuleBasicSettingWindow::sig_setTotalTimeSteps, this, &MainWindowTabWidget::slot_setTotalTimeSteps);
    connect(expMBSWind, &experimentModuleBasicSettingWindow::sig_setDelayTimeSteps, this, &MainWindowTabWidget::slot_setDelayTimeSteps);
    connect(expMBSWind, &experimentModuleBasicSettingWindow::sig_setNumOfMeanFrames, this, &MainWindowTabWidget::slot_setNumOfMeanFrames);
    connect(expMBSWind, &experimentModuleBasicSettingWindow::sig_setNumOfSensors, this, &MainWindowTabWidget::slot_setNumOfSensors);
    connect(expMBSWind, &experimentModuleBasicSettingWindow::sig_setStartDatInd, this, &MainWindowTabWidget::slot_setStartDatInd);
    connect(expMBSWind, &experimentModuleBasicSettingWindow::sig_setSoS, this, &MainWindowTabWidget::slot_setSoS);
    connect(expMBSWind, &experimentModuleBasicSettingWindow::sig_setAngleRange, this, &MainWindowTabWidget::slot_setAngleRange);
    connect(expMBSWind, &experimentModuleBasicSettingWindow::sig_setPitch, this, &MainWindowTabWidget::slot_setPitch);
    connect(expMBSWind, &experimentModuleBasicSettingWindow::sig_setRadius, this, &MainWindowTabWidget::slot_setRadius);
    connect(expMBSWind, &experimentModuleBasicSettingWindow::sig_setArraySensorType, this, &MainWindowTabWidget::slot_setArraySensorType);
    connect(expMBSWind, &experimentModuleBasicSettingWindow::sig_setLabType, this, &MainWindowTabWidget::slot_setLabType);
    connect(expMBSWind, &experimentModuleBasicSettingWindow::sig_preShowSensorMap, this, &MainWindowTabWidget::slot_preShowSensorMap);
    connect(this,&MainWindowTabWidget::sig_initialBasicPara, expMBSWind, &experimentModuleBasicSettingWindow::slot_initialPara);
    connect(this, &MainWindowTabWidget::sig_changeNumOfSensors, expMBSWind, &experimentModuleBasicSettingWindow::slot_changeNumOfSensors);
    connect(this, &MainWindowTabWidget::sig_changeNumOfMeanFrames, expMBSWind, &experimentModuleBasicSettingWindow::slot_changeNumOfMeanFrames);

    //放置一个工具箱（参数设置）
    ToolBox *expParaSettingToolBox = new ToolBox(this);
    expParaSettingToolBox->addWidget(QStringLiteral("基础设置"), expMBSWind);
    ui->expBasicSettingLayout->addWidget(expParaSettingToolBox);
    expParaSettingToolBox->setMinimumWidth(1.1*expMBSWind->minimumWidth());

    //放置三个工具箱（信号处理、成像、成像后处理）
    ToolBox *expToolBox = new ToolBox(this); ToolBox *expImagingBox = new ToolBox(this);
    ExpSignalProcessTool* expSignalProcessTool = new ExpSignalProcessTool();
    _expImagingModule = new ExpImagingModule();
    // ExpPostProcessTool* expPostProcessTool = new ExpPostProcessTool();
    expToolBox->addWidget(QStringLiteral("信号预处理"), expSignalProcessTool);
    expImagingBox->addWidget(QStringLiteral("反演成像"), _expImagingModule);
    // expToolBox->addWidget(QStringLiteral("定量处理"), expPostProcessTool);
    // expToolBox->setMinimumWidth(3.1*expMBSWind->minimumWidth());
    ui->expProcessLayout->addWidget(expToolBox);
    ui->expImagingLayout->addWidget(expImagingBox);

    //信号处理tool
    //设置信号处理模块
    connect(expSignalProcessTool, &ExpSignalProcessTool::sig_isCutZeros, this, &MainWindowTabWidget::slot_isCutZeros);
    connect(expSignalProcessTool, &ExpSignalProcessTool::sig_isDeconvolution, this, &MainWindowTabWidget::slot_isDeconvolution);
    connect(expSignalProcessTool, &ExpSignalProcessTool::sig_isFilter, this, &MainWindowTabWidget::slot_isFilter);
    connect(expSignalProcessTool, &ExpSignalProcessTool::sig_isInsertValue, this, &MainWindowTabWidget::slot_isInsertValue);
    connect(expSignalProcessTool, &ExpSignalProcessTool::sig_isLouKong, this, &MainWindowTabWidget::slot_isLouKongProcess);
    connect(expSignalProcessTool, &ExpSignalProcessTool::sig_isHilbert, this, &MainWindowTabWidget::slot_isHilbert);
    connect(expSignalProcessTool, &ExpSignalProcessTool::sig_loadRFData, this, &MainWindowTabWidget::slot_loadRFData);
    connect(expSignalProcessTool, &ExpSignalProcessTool::sig_plotAllPreProcessRFData, this, &MainWindowTabWidget::slot_plotAllPreProcessRFData);
    connect(expSignalProcessTool, &ExpSignalProcessTool::sig_plotAllRFData, this, &MainWindowTabWidget::slot_plotAllRFData);
    connect(expSignalProcessTool, &ExpSignalProcessTool::sig_plotSingleRFData, this, &MainWindowTabWidget::slot_plotSingleRFData);
    connect(expSignalProcessTool, &ExpSignalProcessTool::sig_preProcessRFData, this, &MainWindowTabWidget::slot_preProcessRFData);
    connect(expSignalProcessTool, &ExpSignalProcessTool::sig_savePreProcessRFData, this, &MainWindowTabWidget::slot_savePreProcessRFData);
    connect(expSignalProcessTool, &ExpSignalProcessTool::sig_setRFDataLoadType, this, &MainWindowTabWidget::slot_setRFDataLoadType);
    connect(this, &MainWindowTabWidget::sigSetPreProcessButtonIcon, expSignalProcessTool, &ExpSignalProcessTool::slot_setPreProcessButtonIcon);
    connect(this, &MainWindowTabWidget::sig_initialExpSignalProcessPara,expSignalProcessTool, &ExpSignalProcessTool::slot_initialPara);
    connect(this, &MainWindowTabWidget::sig_setExpPushButtonLoadRFDatasIcon, expSignalProcessTool, &ExpSignalProcessTool::slot_setPushButtonLoadRFDatasIcon);
    connect(this, &MainWindowTabWidget::sig_setSpinBoxSelectedSensorsMax, expSignalProcessTool, &ExpSignalProcessTool::slot_setSpinBoxSelectedSensorsMax);
    connect(this, &MainWindowTabWidget::sig_setTotalTimeSteps, expSignalProcessTool, &ExpSignalProcessTool::slot_setTotalTimeSteps);
    connect(expSignalProcessTool, &ExpSignalProcessTool::sig_plotSinglePreProcessedRFData, this, &MainWindowTabWidget::slot_plotSinglePreProcessedRFData);
    connect(expSignalProcessTool, &ExpSignalProcessTool::sig_plotSingleBeforeAndAfterRFData, this, &MainWindowTabWidget::slot_plotSingleBeforeAndAfterRFData);
    connect(expSignalProcessTool, &ExpSignalProcessTool::sig_setCutZerosTimeSteps, this, &MainWindowTabWidget::slot_setCutZerosTimeSteps);
    connect(expSignalProcessTool, &ExpSignalProcessTool::sig_plotSingleRFData_PreDomain, this, &MainWindowTabWidget::slot_plotSingleRFData_PreDomain);
    connect(expSignalProcessTool, &ExpSignalProcessTool::sig_plotSinglePreProcessedRFData_FreDomain, this, &MainWindowTabWidget::slot_plotSinglePreProcessedRFData_FreDomain);
    connect(expSignalProcessTool, &ExpSignalProcessTool::sig_plotSingleBeforeAndAfterRFData_FreDomain, this, &MainWindowTabWidget::slot_plotSingleBeforeAndAfterRFData_FreDomain);
    connect(expSignalProcessTool, &ExpSignalProcessTool::sig_setFilterType, this, &MainWindowTabWidget::slot_setFilterType);
    _filterTool = new FilterTool();
    connect(expSignalProcessTool, &ExpSignalProcessTool::sig_setFilterTool, this, &MainWindowTabWidget::slot_setFilterTool);
    _louKongProcessTool = new LouKongProcessTool();
    connect(expSignalProcessTool, &ExpSignalProcessTool::sig_setLouKongProcessTool, this, &MainWindowTabWidget::slot_setLouKongProcessTool);
    _insertValueTool = new InsertValueTool();
    connect(expSignalProcessTool, &ExpSignalProcessTool::sig_setInsertValueType, this, &MainWindowTabWidget::slot_setInsertValueType);
    _deconvolutionTool = new DeconvolutionTool();
    connect(expSignalProcessTool, &ExpSignalProcessTool::sig_setDeconvolutionTool, this, &MainWindowTabWidget::slot_setDeconvolutionTool);

    //成像反演tool
    //设置成像模块
    connect(_expImagingModule, &ExpImagingModule::sig_setRayImagingType, this, &MainWindowTabWidget::slot_setRayImagingType);
    connect(_expImagingModule, &ExpImagingModule::sig_setNonNegativeImagingType, this, &MainWindowTabWidget::slot_setNonNegativeImagingType);
    connect(_expImagingModule, &ExpImagingModule::sig_preShowRayImagingTAI, this, &MainWindowTabWidget::slot_preShowRayImagingTAI);
    connect(_expImagingModule, &ExpImagingModule::sig_plotRayImagingTAI, this, &MainWindowTabWidget::slot_plotRayImagingTAI);
    connect(_expImagingModule, &ExpImagingModule::sigAppendLog, this, &MainWindowTabWidget::slot_appendLog);
    connect(_expImagingModule, &ExpImagingModule::sig_preShowNonNegativeImagingTAI, this, &MainWindowTabWidget::slot_preShowNonNegativeImagingTAI);
    connect(_expImagingModule, &ExpImagingModule::sig_plotNonNegativeImagingTAI, this, &MainWindowTabWidget::slot_plotNonNegativeImagingTAI);
    // connect(_expImagingModule, &ExpImagingModule::sig_isReverseImaging, this, &MainWindowTabWidget::slot_setIsReverseImaging);

}

MainWindowTabWidget::~MainWindowTabWidget()
{
    delete ui;
    if(_filterTool != nullptr){
        delete _filterTool;
    }
    if(_filterProcessToolSetting != nullptr){
        delete _filterProcessToolSetting;
    }
    if(_louKongProcessToolSetting != nullptr){
        delete _louKongProcessToolSetting;
    }
    if(_deconvolutionToolSetting != nullptr){
        delete _deconvolutionToolSetting;
    }
    if(_louKongProcessTool != nullptr){
        delete _louKongProcessTool;
    }
    if(_insertValueTool != nullptr){
        delete _insertValueTool;
    }
    // if(_sensorDecare !=nullptr){
    //     delete [] _sensorDecare;
    // }
}

//该函数用来计算求解传感器坐标
void MainWindowTabWidget::calculateSensorDecare()
{
    //为了方便，线阵直接放在y轴为0的位置，环阵从x负轴开始顺时针依次到终点
    //竖轴为y轴且从上到下为正向，横轴为x轴且从左到右为正向
    //根据类型计算传感器坐标
    // if(_sensorDecare !=nullptr){
    //     delete [] _sensorDecare;
    // }
    // _sensorDecare = new QVector<QVector<float>>(2);
    _sensorDecare.resize(2*_basicPara.getNumOfSensors());
    float startXDeca; float deltaAngle;
    switch(_basicPara.getArraySensorType()){
    case ArraySensorType::LineArray:
        //分奇偶计算x坐标
        if(_basicPara.getNumOfSensors()  % 2 != 0)//余数不为0为奇数
        {
            startXDeca = -(_basicPara.getNumOfSensors()-1)/2*_basicPara.getPitch()*1e-3;//开始x坐标
        }else{
            startXDeca = -((_basicPara.getNumOfSensors())/2-0.5)*_basicPara.getPitch()*1e-3;//开始x坐标
        }
        for(int i = 0; i <_basicPara.getNumOfSensors(); i++){
            _sensorDecare[0+i*2] = startXDeca+i*_basicPara.getPitch()*1e-3;
            _sensorDecare[1+i*2] = 0;
        }
        _sensorArrayName = "线形阵列";
        break;
    case ArraySensorType::RingArray:
        deltaAngle = 2*M_PI/(_basicPara.getNumOfSensors());
        for(int i = 0; i <_basicPara.getNumOfSensors(); i++){
            _sensorDecare[0+i*2] =_basicPara.getRadius()*1e-3*qCos(-i*deltaAngle+M_PI);
            _sensorDecare[1+i*2] = _basicPara.getRadius()*1e-3*qSin(-i*deltaAngle+M_PI);
        }
        _sensorArrayName = "全环阵列";
        break;
    case ArraySensorType::SemiRingArray:
        deltaAngle = 1*M_PI/(_basicPara.getNumOfSensors()-1);
        for(int i = 0; i <_basicPara.getNumOfSensors(); i++){
            _sensorDecare[0+i*2] =_basicPara.getRadius()*1e-3*qCos(-i*deltaAngle+M_PI);
            _sensorDecare[1+i*2] = _basicPara.getRadius()*1e-3*qSin(-i*deltaAngle+M_PI);
        }
        _sensorArrayName = "半环阵列";
        break;
    case ArraySensorType::FiniteArcArray:
        if(_basicPara.getAngleRange()==2){
            deltaAngle = 2*M_PI/(_basicPara.getNumOfSensors());
        }else{
            deltaAngle = _basicPara.getAngleRange()*M_PI/(_basicPara.getNumOfSensors()-1);
        }
        for(int i = 0; i <_basicPara.getNumOfSensors(); i++){
            _sensorDecare[0+i*2] =_basicPara.getRadius()*1e-3*qCos(-i*deltaAngle+M_PI);
            _sensorDecare[1+i*2] = _basicPara.getRadius()*1e-3*qSin(-i*deltaAngle+M_PI);
        }
        _sensorArrayName = "有限弧度阵列";
        break;
    default:
        qDebug()<<"calculateSensorDecare(): default!";
        break;
    }
}

void MainWindowTabWidget::initialPara()
{
    emit sig_initialBasicPara();
    emit sig_initialExpSignalProcessPara();
}

//预处理信号
bool MainWindowTabWidget::preProcessRFData()
{
    if(_isNeedUpdateRFData){
        emit sigAppendLog("未预处理，由于未更新导入数据");
        emit sigSetPreProcessButtonIcon(false);
        return false;
    }

    if(!_isNeedUpdatePreProcessRFData){
        emit sigAppendLog("未预处理，由于不需要处理！");
        return false;
    }

    //重新初始化预处理矩阵

    _TADataBox.cloneData("RFData","PreProcessedRFData");
    _TADataBox.cloneData("RFData_xVec", "PreProcessedRFData_xVec");
    _TADataBox.cloneData("RFData_yVec","PreProcessedRFData_yVec");

    //预处理前需要重置传感器数
    _basicPara.resetNumOfSensors();

    if(!(_isFilter || _isDeconvolution || _isCutZeros || _isLouKongProcess || _isInsertValue || _isHilbert)){
        emit sigAppendLog("本次预处理未处理，由于未设置任何处理选项！");
        // emit sigSetPreProcessButtonIcon(false);
        return false;
    }


    //根据是否需要进行什么处理去处理该信号
    //处理一：噪声滤波
    if (_isFilter){
        filterRFData();
        emit sigAppendLog("滤波完成！");
    }
    //处理二：去传感器响应卷积
    if(_isDeconvolution){
        deConvolutionRFData();
        emit sigAppendLog("去卷积完成！");
    }
    //处理三：置零去微波脉冲噪声
    if(_isCutZeros){
        cutZerosRFData();
        emit sigAppendLog("置零去微波脉冲噪声完成！");
    }

    //处理四：镂空阵列补偿特殊考虑
    if (_isLouKongProcess){
        louKongProcessRFData();
        emit sigAppendLog("镂空阵列特殊补偿处理完毕！");
    }

    //处理五：插值
    if(_isInsertValue){
        insertValueRFData();
        emit sigAppendLog("插值结束！");
    }

    //处理六：希尔伯特变换
    if(_isHilbert){
        hilbertRFData();
        emit sigAppendLog("希尔伯特变换完毕！");
    }
    emit sigAppendLog("信号预处理完毕！");
    emit sigSetPreProcessButtonIcon(true);
    return true;
}

void MainWindowTabWidget::slot_getDatFileLoadPath(const QString& path)
{
    if(_fileDirectoryName != path)
    {
        _fileDirectoryName = path;
        _isNeedUpdateRFData = true;
        emit sig_setExpPushButtonLoadRFDatasIcon(QIcon(":/icon/noLoad.png"));
        if(_thread_loadRFData.get() != nullptr && _thread_loadRFData->isRunning()){
            emit sig_cancelLoadRFDataProgress();
        }
        switch(_basicPara.getLabType()){
        case LabType::MITAI111Lab:
            emit sigAppendLog(QString("已选择要处理的.dat文件路径！"));
            break;
        case LabType::OtherLab:
            emit sigAppendLog(QString("已选择要处理的RF文件路径！"));
            break;
        default:
            break;
        }
    }
}

void MainWindowTabWidget::slot_getRFDataFileLoadAddress(const QString &path)
{
    if(_RFDataFileAddress != path)
    {
        _RFDataFileAddress = path;
        _isNeedUpdateRFData = true;
        emit sig_setExpPushButtonLoadRFDatasIcon(QIcon(":/icon/noLoad.png"));
        if(_thread_loadRFData.get() != nullptr && _thread_loadRFData->isRunning()){
            emit sig_cancelLoadRFDataProgress();
        }
        emit sigAppendLog(QString("已选择要处理的RF数据文件地址！"));
    }
}

void MainWindowTabWidget::slot_setTotalTimeSteps(const int& tmp)
{
    if(_basicPara.getTotalTimeSteps() != tmp)
    {
        _basicPara.setTotalTimeSteps(tmp);
        emit sig_setTotalTimeSteps(tmp);
        emit sigAppendLog("总采样点数："+QString::number(_basicPara.getTotalTimeSteps()));
        _louKongProcessTool->slot_setNTimes(tmp);
    }
}

void MainWindowTabWidget::slot_setFs(const int& Fs)
{
    if (_basicPara.getFs() != Fs){
        _basicPara.setFs(Fs);
        emit sigAppendLog("采样频率："+QString::number(_basicPara.getFs())+" MHz");
    }
}

void MainWindowTabWidget::slot_setDelayTimeSteps(const int& tmp)
{
    if (_basicPara.getDelayTimeSteps() != tmp){
        _basicPara.setDelayTimeSteps(tmp);
        emit sigAppendLog("采样延时："+QString::number(_basicPara.getDelayTimeSteps()));
    }
}

void MainWindowTabWidget::slot_setStartDatInd(const int& tmp)
{
    if (_basicPara.getStartDatInd() != tmp){
        _basicPara.setStartDatInd(tmp);
        _isNeedUpdateRFData = true;
        emit sig_setExpPushButtonLoadRFDatasIcon(QIcon(":/icon/noLoad.png"));
        if(_thread_loadRFData.get() != nullptr && _thread_loadRFData->isRunning()){
            emit sig_cancelLoadRFDataProgress();
        }
        emit sigAppendLog("起始处理帧："+QString::number(_basicPara.getStartDatInd()));
    }

}

void MainWindowTabWidget::slot_setNumOfMeanFrames(const int& tmp)
{
    if (_basicPara.getNumOfMeanFrames() != tmp){
        _basicPara.setNumOfMeanFrames(tmp);
        _isNeedUpdateRFData = true;
        emit sig_setExpPushButtonLoadRFDatasIcon(QIcon(":/icon/noLoad.png"));
        if(_thread_loadRFData.get() != nullptr && _thread_loadRFData->isRunning()){
            emit sig_cancelLoadRFDataProgress();
        }
        emit sigAppendLog("平均帧数："+QString::number(_basicPara.getNumOfMeanFrames()));
        emit sig_changeNumOfMeanFrames(tmp);
    }
}

void MainWindowTabWidget::slot_setNumOfSensors(const int& tmp)
{
    if (_basicPara.getNumOfSensors() != tmp){
        emit sig_setSpinBoxSelectedSensorsMax(tmp);
        _basicPara.setNumOfSensors(tmp);
        _basicPara.saveNumOfSensors();
        _isNeedCalculateSensorDecare = true;
        emit sigAppendLog("通道数："+QString::number(_basicPara.getNumOfSensors()));
        _louKongProcessTool->slot_setNSens(tmp);
        emit sig_changeNumOfSensors(tmp);
    }
}

void MainWindowTabWidget::slot_setSoS(const float& tmp)
{
    if (_basicPara.getSoS() != tmp){
        _basicPara.setSoS(tmp);
        emit sigAppendLog("均匀声速："+QString::number(_basicPara.getSoS())+" m/s");
    }
}

void MainWindowTabWidget::slot_setPitch(const float& tmp)
{
    if (_basicPara.getPitch() != tmp){
        _basicPara.setPitch(tmp);
        _isNeedCalculateSensorDecare = true;
        emit sigAppendLog("线阵阵元间隔："+QString::number(_basicPara.getPitch())+" mm");
    }
}

void MainWindowTabWidget::slot_setRadius(const float& tmp)
{
    if (_basicPara.getRadius() != tmp){
        _isNeedCalculateSensorDecare = true;
        _basicPara.setRadius(tmp);
        emit sigAppendLog("弧阵半径："+QString::number(_basicPara.getRadius())+" mm");
    }
}

void MainWindowTabWidget::slot_setAngleRange(const float& tmp)
{
    if (_basicPara.getAngleRange() != tmp){
        _isNeedCalculateSensorDecare = true;
        _basicPara.setAngleRange(tmp);
        emit sigAppendLog("弧阵总弧度角："+QString::number(_basicPara.getAngleRange())+" pi");
    }
}

void MainWindowTabWidget::slot_setArraySensorType(const ArraySensorType  tmp)
{
    if (_basicPara.getArraySensorType() != tmp){
        _basicPara.setArraySensorType(tmp);
        switch(_basicPara.getArraySensorType()){
        case ArraySensorType::LineArray:
            emit sigAppendLog("传感器阵列为：线阵");
            break;
        case ArraySensorType::RingArray:
            emit sigAppendLog("传感器阵列为：环阵");
            break;
        case ArraySensorType::SemiRingArray:
            emit sigAppendLog("传感器阵列为：半环阵");
            break;
        case ArraySensorType::FiniteArcArray:
            emit sigAppendLog("传感器阵列为：有限弧度阵");
            break;
        default:
            break;
        }
    }
}

void MainWindowTabWidget::slot_setLabType(const LabType tmp)
{
    if (_basicPara.getLabType() != tmp){
        _basicPara.setLabType(tmp);
        switch(_basicPara.getLabType()){
        case LabType::MITAI111Lab:
            emit sigAppendLog("Welcome MITAI111Lab!");
            break;
        case LabType::OtherLab:
            emit sigAppendLog("Welcome friends' Lab!");
            break;
        default:
            break;
        }
    }
}

//该函数用来显示预览当前传感器位置
void MainWindowTabWidget::slot_preShowSensorMap()
{
    // qDebug()<<"计算传感器坐标前！";
    //判断是否需要计算传感器
    if (_isNeedCalculateSensorDecare){
        calculateSensorDecare();
        _isNeedCalculateSensorDecare = false;
    }
    // qDebug()<<"计算坐标后！坐标向量行：" <<QString::number(_sensorDecare.size()) << "，列：" << QString::number(_sensorDecare[0].size());
    QVector<float> imageData;int Nx,Ny;
    QVector<float> xVec, yVec;
    float minXDeca, maxXDeca, minYDeca, maxYDeca;
    //求解绘制的范围
    minYDeca = minVec(_sensorDecare,1,_basicPara.getNumOfSensors(),2,VectorType::MatrixRow)-EXPAND_WIDTH*1e-3;
    // qDebug()<<"计算minYDeca后！";
    maxYDeca = maxVec(_sensorDecare,1,_basicPara.getNumOfSensors(),2,VectorType::MatrixRow)+EXPAND_WIDTH*1e-3;
    minXDeca = minVec(_sensorDecare,0,_basicPara.getNumOfSensors(),2,VectorType::MatrixRow)-EXPAND_WIDTH*1e-3;
    maxXDeca = maxVec(_sensorDecare,0,_basicPara.getNumOfSensors(),2,VectorType::MatrixRow)+EXPAND_WIDTH*1e-3;
    // qDebug()<<"计算范围后！";
    //求解绘制网格坐标
    Nx = qFloor((maxXDeca-minXDeca)/(DEFAULT_DELTA_X*1e-3)+0.1)+1;
    Ny = qFloor((maxYDeca-minYDeca)/(DEFAULT_DELTA_X*1e-3)+0.1)+1;
    xVec.resize(Nx);
    yVec.resize(Ny);
    for(int i=0; i<Nx; i++){
        xVec[i] = minXDeca + (DEFAULT_DELTA_X*1e-3)*i;
    }
    for(int i=0; i<Ny; i++){
        yVec[i] = minYDeca + (DEFAULT_DELTA_X*1e-3)*i;
    }
    // qDebug()<<"计算网格坐标后！";
    //获取绘制矩阵值
    //这里，传感器坐标距离最近的点作为传感器所在位置
    imageData.resize(Ny*Nx);//设置矩阵元素多少Ny*Nx
    // qDebug()<<"设置imageData后！";
    //可依次计算传感器位置所在的索引，然后将该索引的位置置一
    int yy,xx;
    for(int i = 0; i <_basicPara.getNumOfSensors();i++){
        xx = qFloor((_sensorDecare[0+i*2]-minXDeca)/(DEFAULT_DELTA_X*1e-3)+0.1)+1;
        yy = qFloor((_sensorDecare[1+i*2]-minYDeca)/(DEFAULT_DELTA_X*1e-3)+0.1)+1;
        imageData[yy+xx*Ny] = 1;
    }
    for(int i=0; i<Nx; i++){
        xVec[i] *= 1000;
    }
    for(int i=0; i<Ny; i++){
        yVec[i] *= 1000;
    }
    //绘制数据
    //这可以设置一个窗口类，该类可以绘制plot曲线和imagesc2D图
    // qDebug()<<"绘制前！";
    MyFigure* myFigure = new MyFigure(baseUi);
    // myFigure->setAttribute(Qt::WA_DeleteOnClose); // 设置关闭时自动释放内存
    myFigure->plotHeatMap(imageData, xVec, yVec, _sensorArrayName);
    // myFigure->setMyAxisImage();
    // myFigure->setMyColorBar(ColorbarType::Parula);
    myFigure->setMyXLabel("x(mm)");
    myFigure->setMyYLabel("y(mm)");
    myFigure->show();
}

void MainWindowTabWidget::slot_setRFDataLoadType(const RFDataLoadType tmp)
{
    if (_basicPara.getRFDataLoadType() != tmp){
        _basicPara.setRFDataLoadType(tmp);
        _isNeedUpdateRFData = true;
        emit sig_setExpPushButtonLoadRFDatasIcon(QIcon(":/icon/noLoad.png"));
        if(_thread_loadRFData.get() != nullptr && _thread_loadRFData->isRunning()){
            emit sig_cancelLoadRFDataProgress();
        }
        switch(_basicPara.getRFDataLoadType()){
        case RFDataLoadType::PathLoad:
            emit sigAppendLog("已设置为文件夹中导入RF数据！");
            break;
        case RFDataLoadType::AddressLoad:
            emit sigAppendLog("已设置为直接导入单个RF数据文件！");
            break;
        default:
            break;
        }
    }
}

void MainWindowTabWidget::slot_loadRFData()
{
    loadRFData();
}

void MainWindowTabWidget::slot_plotAllRFData()
{
    //绘制数据
    //这可以设置一个窗口类，该类可以绘制plot曲线和imagesc2D图
    // qDebug()<<"绘制前！";
    // loadRFData();
    if (!_isNeedUpdateRFData){
        MyFigure* myFigure = new MyFigure(baseUi);
        // myFigure->setAttribute(Qt::WA_DeleteOnClose); // 设置关闭时自动释放内存
        myFigure->plotHeatMap(_TADataBox.viewData("RFData"), _TADataBox.viewData("RFData_xVec"), _TADataBox.viewData("RFData_yVec"), "原始传感器数据");
        // myFigure->setMyAxisImage();
        // myFigure->setMyColorBar(ColorbarType::Parula);
        myFigure->setMyXLabel("时间步长");
        myFigure->setMyYLabel("传感器通道索引");
        myFigure->setMyWindowTitle("传感器原始信号图");
        myFigure->show();
    }
    else{
        emit sigAppendLog("绘制失败^><^需要更新传感器数据！");
    }
}

void MainWindowTabWidget::slot_savePreProcessRFData()
{
    if(!_TADataBox.contains("PreProcessedRFData")){
        emit sigAppendLog("保存数据失败^><^请实现预处理后再保存该数据！");
        return;
    }
    if(_isNeedUpdatePreProcessRFData){
        emit sigAppendLog("保存数据失败^><^请更新预处理数据后预览确认后再保存该数据！");
        return;
    }
    // 获取初始目录（首次为软件位置，之后为上次路径）
    QString initialDir = _lastSavePath.isEmpty()
                             ? QCoreApplication::applicationDirPath()
                             : _lastSavePath;
    // 弹出保存对话框
    QString fileName = QFileDialog::getSaveFileName(
        this,
        "保存矩阵数据",
        initialDir + "/untitled",
        "Text Files (*.txt);;CSV Files (*.csv)"
        );

    if (fileName.isEmpty()) return; // 用户取消操作

    // 根据文件扩展名选择分隔符
    QString separator = fileName.endsWith(".csv") ? "," : " ";
    const QVector<float>& saveData = _TADataBox.viewData("PreProcessedRFData");
    // if (!_TADataBox.contains("PreProcessRFData")){
    //     const QVector<float>& saveData = _TADataBox.viewData("RFData");}
    // else{
    //     const QVector<float>& saveData = _TADataBox.viewData("PreProcessRFData");
    // }
    // 打开文件并写入数据
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        //一行一行写出
        for (int i = 0; i < _basicPara.getNumOfSensors(); ++i) {
            QStringList rowStr;
            for (int j = 0; j < _basicPara.getTotalTimeSteps(); ++j) {
                rowStr << QString::number(saveData[i+j*_basicPara.getNumOfSensors()], 'f', 6); // 保留6位小数
            }
            stream << rowStr.join(separator) << "\n";
        }
        file.close();

        // 更新上次保存路径（提取目录部分）
        _lastSavePath = QFileInfo(fileName).absolutePath();
    } else {
        QMessageBox::warning(this, "错误", "文件保存失败！");
    }
}

//画单传感器信号
void MainWindowTabWidget::slot_plotSingleRFData(const int &_sensorIndex)
{
    // loadRFData();
    if(!_isNeedUpdateRFData){
        QVector<float> yCurve(_basicPara.getTotalTimeSteps());
        for(int i = 0; i < _basicPara.getTotalTimeSteps(); ++i){
            yCurve[i] = _TADataBox.viewData("RFData")[_sensorIndex-1+i*_basicPara.getNumOfSensors()];
        }
        MyFigure* curveFigure = new MyFigure(baseUi);
        curveFigure->plotCurve(_TADataBox.viewData("RFData_xVec"), yCurve, Qt::blue, 2);
        curveFigure->setMyXLabel("时间步长");
        curveFigure->setMyYLabel("TA Intensity(a.u)");
        curveFigure->setMyMapTitle("通道"+QString::number(_sensorIndex)+"的原始RF信号曲线图");
        curveFigure->setMyWindowTitle("传感器单通道原始信号曲线图");
        curveFigure->show();
    }else{
        emit sigAppendLog("绘制失败^><^需要更新传感器数据！");
    }
}

void MainWindowTabWidget::slot_plotSingleRFData_PreDomain(const int &index)
{
    if(_isNeedUpdateRFData){
        emit sigAppendLog("绘制失败^><^需要更新传感器数据！");
        return;
    }
    QVector<float> origin(_basicPara.getTotalTimeSteps());
    // 准备输入数据
    for (int i = 0; i < _basicPara.getTotalTimeSteps(); ++i) {
        origin[i] = (_TADataBox.viewData("RFData")[index-1+i*_basicPara.getNumOfSensors()]); // 实部
    }
    QVector<float> fftOut, fftOut_xVec;float Fs_ = static_cast<float>(_basicPara.getFs());
    MyAlgorithm::FreDomainCurve_1d(fftOut, fftOut_xVec, origin, Fs_);
    //画图
    MyFigure* curveFigure = new MyFigure(baseUi);
    curveFigure->plotCurve(fftOut_xVec, fftOut, Qt::blue, 2, "原始信号");
    curveFigure->setMyXLabel("MHz");
    curveFigure->setMyYLabel("Amplitude(a.u)");
    curveFigure->setMyMapTitle("通道"+QString::number(index)+"的原始RF信号频域曲线图");
    curveFigure->setMyWindowTitle("传感器单通道原始信号频域曲线图");
    curveFigure->show();

}

void MainWindowTabWidget::slot_plotSinglePreProcessedRFData_FreDomain(const int & index)
{
    if(_isNeedUpdateRFData){
        emit sigAppendLog("绘制失败^><^请更新原始数据");
        return;
    }
    //
    if(_isNeedUpdatePreProcessRFData){
        emit sigAppendLog("绘制失败^><^请更新预处理数据");
        return;
    };

    QVector<float> origin(_basicPara.getTotalTimeSteps());
    // 准备输入数据
    for (int i = 0; i < _basicPara.getTotalTimeSteps(); ++i) {
        origin[i] = (_TADataBox.viewData("PreProcessedRFData")[index-1+i*_basicPara.getNumOfSensors()]); // 实部
    }
    QVector<float> fftOut, fftOut_xVec;float Fs_ = static_cast<float>(_basicPara.getFs());
    MyAlgorithm::FreDomainCurve_1d(fftOut, fftOut_xVec, origin, Fs_);
    //只绘制一半的曲线
    QVector<float> freqHalf(origin.size()/2/2);
    QVector<float> magHalf(origin.size()/2/2);

    for (int i=0; i<origin.size()/2/2; ++i) {
        freqHalf[i] = fftOut[i];
        magHalf[i] = fftOut_xVec[i];
    }
    MyFigure* curveFigure = new MyFigure(baseUi);
    curveFigure->plotCurve(freqHalf, magHalf, Qt::red, 2, "预处理后信号");
    curveFigure->setMyXLabel("MHz");
    curveFigure->setMyYLabel("Amplitude(a.u)");
    curveFigure->setMyMapTitle("通道"+QString::number(index)+"的预处理RF信号频域曲线图");
    curveFigure->setMyWindowTitle("传感器单通道预处理后信号频域曲线图");
    curveFigure->show();

}

void MainWindowTabWidget::slot_plotSingleBeforeAndAfterRFData_FreDomain(const int &index)
{
    if(_isNeedUpdateRFData){
        emit sigAppendLog("绘制失败^><^请更新原始数据");
        return;
    }
    //
    if(_isNeedUpdatePreProcessRFData){
        emit sigAppendLog("绘制失败^><^请更新预处理数据");
        return;
    };

    //绘制原始信号频谱图
    QVector<float> yCurveOriginalRFData(_basicPara.getTotalTimeSteps());
    for(int i = 0; i < _basicPara.getTotalTimeSteps(); ++i){
        yCurveOriginalRFData[i] = _TADataBox.viewData("RFData")[index-1+i*_basicPara.getNumOfSensors()];
    }
    QVector<float> fftOutRF, fftOutRF_xVec;float Fs_ = static_cast<float>(_basicPara.getFs());
    MyAlgorithm::FreDomainCurve_1d(fftOutRF, fftOutRF_xVec, yCurveOriginalRFData, Fs_);
    //只绘制一半的曲线
    QVector<float> freqHalf(yCurveOriginalRFData.size()/2/2);
    QVector<float> magHalf(yCurveOriginalRFData.size()/2/2);

    for (int i=0; i<yCurveOriginalRFData.size()/2/2; ++i) {
        freqHalf[i] = fftOutRF[i];
        magHalf[i] = fftOutRF_xVec[i];
    }
    magHalf[yCurveOriginalRFData.size()/2/2-1] = Fs_/2/2;

    MyFigure* curveFigure = new MyFigure(this);
    curveFigure->plotCurve(magHalf, MyAlgorithm::normalizeOne(freqHalf), Qt::blue, 2,"原始信号")->setScatterStyle(QCPScatterStyle::ssCircle);

    //添加绘制预处理信号频谱图！！！！
    QVector<float> yCurve(_basicPara.getTotalTimeSteps());
    for(int i = 0; i < _basicPara.getTotalTimeSteps(); ++i){
        yCurve[i] = _TADataBox.viewData("PreProcessedRFData")[index-1+i*_basicPara.getNumOfSensors()];
    }
    QVector<float> fftOutPreProcessRF, fftOutPreProcessRF_xVec;
    MyAlgorithm::FreDomainCurve_1d(fftOutPreProcessRF, fftOutPreProcessRF_xVec, yCurve, Fs_);
    //只绘制一半的曲线
    QVector<float> freqPreHalf(yCurve.size()/2/2);
    QVector<float> magPreHalf(yCurve.size()/2/2);

    for (int i=0; i<yCurve.size()/2/2; ++i) {
        freqPreHalf[i] = fftOutPreProcessRF[i];
        magPreHalf[i] = fftOutPreProcessRF_xVec[i];
    }
    magPreHalf[yCurve.size()/2/2-1] = Fs_/2/2;

    curveFigure->addCurve(magPreHalf, MyAlgorithm::normalizeOne(freqPreHalf), Qt::red, 2, "预处理后信号")->setScatterStyle(QCPScatterStyle::ssCross);
    curveFigure->setMyXLabel("MHz");
    curveFigure->setMyYLabel("Amplitude(a.u)");
    curveFigure->setMyMapTitle("通道"+QString::number(index)+"的预处理前后RF信号频谱图");
    curveFigure->setMyWindowTitle("传感器单通道预处理前后信号频谱图");
    curveFigure->show();
}

void MainWindowTabWidget::slot_appendLog(const QString &message)
{
    emit sigAppendLog(message);
}

void MainWindowTabWidget::slot_setExpPushButtonLoadRFDatasIcon(const QIcon &iconName)
{
    emit sig_setExpPushButtonLoadRFDatasIcon(iconName);
}

void MainWindowTabWidget::slot_plotAllPreProcessRFData()
{
    if(_isNeedUpdateRFData){
        emit sigAppendLog("绘制失败^><^请更新原始数据");
        return;
    }
    //
    if(_isNeedUpdatePreProcessRFData){
        emit sigAppendLog("绘制失败^><^请更新预处理数据");
        return;
    };
    //绘制预处理信号图！！！！
    MyFigure* myFigure = new MyFigure(baseUi);
    // myFigure->setAttribute(Qt::WA_DeleteOnClose); // 设置关闭时自动释放内存
    myFigure->plotHeatMap(_TADataBox.viewData("PreProcessedRFData"), _TADataBox.viewData("PreProcessedRFData_xVec"), _TADataBox.viewData("PreProcessedRFData_yVec"), "预处理后的原始传感器数据");
    // myFigure->setMyAxisImage();
    // myFigure->setMyColorBar(ColorbarType::Parula);
    myFigure->setMyXLabel("时间步长");
    myFigure->setMyYLabel("传感器通道索引");
    myFigure->setMyWindowTitle("预处理后的传感器信号图");
    myFigure->show();

}

void MainWindowTabWidget::slot_preProcessRFData()
{
    if(preProcessRFData()){
        _isNeedUpdatePreProcessRFData = false;
    }
}

void MainWindowTabWidget::slot_plotSinglePreProcessedRFData(const int &index)
{
    if(_isNeedUpdateRFData){
        emit sigAppendLog("绘制失败^><^请更新原始数据");
        return;
    }
    //
    if(_isNeedUpdatePreProcessRFData){
        emit sigAppendLog("绘制失败^><^请更新预处理数据");
        return;
    };
    //绘制预处理信号图！！！！
    QVector<float> yCurve(_basicPara.getTotalTimeSteps());
    for(int i = 0; i < _basicPara.getTotalTimeSteps(); ++i){
        yCurve[i] = _TADataBox.viewData("PreProcessedRFData")[index-1+i*_basicPara.getNumOfSensors()];
    }

    MyFigure* curveFigure = new MyFigure(baseUi);//放大y轴范围与原始信号一致
    QVector<float> yCurve_(_basicPara.getTotalTimeSteps());
    for(int i = 0; i < _basicPara.getTotalTimeSteps(); ++i){
        yCurve_[i] = _TADataBox.viewData("RFData")[index-1+i*_basicPara.getNumOfSensors()];
    }
    float min_,max_;
    min_ = minVec(yCurve_); max_ = maxVec(yCurve_);
    curveFigure->plotCurve(_TADataBox.viewData("PreProcessedRFData_xVec"), yCurve, Qt::red, 2, "预处理后信号");
    curveFigure->setYRange(QCPRange(min_, max_));
    curveFigure->setMyXLabel("时间步长");
    curveFigure->setMyYLabel("TA Intensity(a.u)");
    curveFigure->setMyMapTitle("通道"+QString::number(index)+"预处理后的RF信号曲线图");
    curveFigure->setMyWindowTitle("传感器单通道预处理后信号曲线图");
    curveFigure->show();
}

void MainWindowTabWidget::slot_plotSingleBeforeAndAfterRFData(const int &index)
{
    if(_isNeedUpdateRFData){
        emit sigAppendLog("绘制失败^><^请更新原始数据");
        return;
    }
    //
    if(_isNeedUpdatePreProcessRFData){
        emit sigAppendLog("绘制失败^><^请更新预处理数据");
        return;
    };
    //绘制原始信号图
    QVector<float> yCurveOriginalRFData(_basicPara.getTotalTimeSteps());
    for(int i = 0; i < _basicPara.getTotalTimeSteps(); ++i){
        yCurveOriginalRFData[i] = _TADataBox.viewData("RFData")[index-1+i*_TADataBox.viewData("RFData_yVec").size()];
    }
    MyFigure* curveFigure = new MyFigure(this);
    curveFigure->plotCurve(_TADataBox.viewData("RFData_xVec"), MyAlgorithm::normalizeOne(yCurveOriginalRFData), Qt::blue, 2,"原始信号")->setScatterStyle(QCPScatterStyle::ssCircle);

    //添加绘制预处理信号图！！！！
    QVector<float> yCurve(_basicPara.getTotalTimeSteps());
    for(int i = 0; i < _basicPara.getTotalTimeSteps(); ++i){
        yCurve[i] = _TADataBox.viewData("PreProcessedRFData")[index-1+i*_TADataBox.viewData("PreProcessedRFData_yVec").size()];
    }
    curveFigure->addCurve(_TADataBox.viewData("PreProcessedRFData_xVec"), MyAlgorithm::normalizeOne(yCurve), Qt::red, 2, "预处理后信号")->setScatterStyle(QCPScatterStyle::ssCross);
    curveFigure->setMyXLabel("时间步长");
    curveFigure->setMyYLabel("TA Intensity(a.u)");
    curveFigure->setMyMapTitle("通道"+QString::number(index)+"预处理前后的RF信号曲线对比图");
    curveFigure->setMyWindowTitle("传感器单通道预处理前后信号曲线对比图");
    curveFigure->show();
}

void MainWindowTabWidget::slot_isDeconvolution(const bool &tmp)
{
    if(_isDeconvolution != tmp){
        _isDeconvolution = tmp;
        _isNeedUpdatePreProcessRFData = true;
    }
}

void MainWindowTabWidget::slot_isFilter(const bool &tmp)
{
    if(_isFilter != tmp){
        _isFilter = tmp;
        _isNeedUpdatePreProcessRFData = true;
    }
}

void MainWindowTabWidget::slot_isCutZeros(const bool &tmp)
{
    if(_isCutZeros != tmp){
        _isCutZeros = tmp;
        _isNeedUpdatePreProcessRFData = true;
    }
}

void MainWindowTabWidget::slot_isLouKongProcess(const bool &tmp)
{
    if(_isLouKongProcess != tmp){
        _isLouKongProcess = tmp;
        _isNeedUpdatePreProcessRFData = true;
    }
}

void MainWindowTabWidget::slot_isInsertValue(const bool &tmp)
{
    if(_isInsertValue != tmp){
        _basicPara.resetNumOfSensors();//插值处理修改后，将传感器数初始化为原先的传感器数
        emit sig_changeNumOfSensors(_basicPara.getNumOfSensors());
        _isInsertValue = tmp;
        _isNeedUpdatePreProcessRFData = true;
    }
}

void MainWindowTabWidget::slot_isHilbert(const bool &tmp)
{
    if(_isHilbert != tmp){
        _isHilbert = tmp;
        _isNeedUpdatePreProcessRFData = true;
    }
}

void MainWindowTabWidget::slot_setCutZerosTimeSteps(const int &tmp)
{
    if(_cutZerosTimeSteps != tmp){
        _cutZerosTimeSteps = tmp;
        _isNeedUpdatePreProcessRFData = true;
        emit sigSetPreProcessButtonIcon(false);
    }
}

void MainWindowTabWidget::slot_setFilterType(const FilterType &tmp)
{
    if(_filterType != tmp){
        _filterType = tmp;
        _isNeedUpdatePreProcessRFData = true;
        emit sigSetPreProcessButtonIcon(false);
    }
}

void MainWindowTabWidget::slot_setFilterTool()
{
    if(_filterProcessToolSetting == nullptr){
        _filterProcessToolSetting = new FilterToolSettingDialog(this);
        _filterProcessToolSetting->setWindowTitle("滤波器设置");
    }
    if(!_filterProcessToolSetting->isVisible()){
        _filterProcessToolSetting->addFilterTool(_filterTool);
        _filterProcessToolSetting->show();
    }
}

void MainWindowTabWidget::slot_setLouKongProcessTool()
{
    if(_louKongProcessToolSetting == nullptr){
        _louKongProcessToolSetting = new FilterToolSettingDialog(this);
        _louKongProcessToolSetting->setWindowTitle("镂空阵列特殊处理设置");
    }
    if(!_louKongProcessToolSetting->isVisible()){
        _louKongProcessToolSetting->addFilterTool(_louKongProcessTool);
        _louKongProcessToolSetting->show();
    }
}

void MainWindowTabWidget::slot_setInsertValueType(const InsertValueType &tmp)
{
    if(_insertValueType != tmp){
        _insertValueType = tmp;
        _isNeedUpdatePreProcessRFData = true;
        emit sigSetPreProcessButtonIcon(false);
    }
}

void MainWindowTabWidget::slot_setDeconvolutionTool()
{
    if(_deconvolutionToolSetting == nullptr){
        _deconvolutionToolSetting = new FilterToolSettingDialog(this);
        _deconvolutionToolSetting->setWindowTitle("去传感器脉冲响应卷积设置");
    }
    if(!_deconvolutionToolSetting->isVisible()){
        _deconvolutionToolSetting->addFilterTool(_deconvolutionTool);
        _deconvolutionToolSetting->show();
    }
}

void MainWindowTabWidget::slot_setRayImagingType(const RayImagingType &tmp)
{
    if(_rayImagingType != tmp){
        _rayImagingType = tmp;
    }
}

void MainWindowTabWidget::slot_preShowRayImagingTAI()
{
    //
    if(_isNeedCalculateSensorDecare){
        calculateSensorDecare();
    }else{
        _isNeedCalculateSensorDecare = false;
    }
    if(_isNeedUpdateRFData){
        emit sigAppendLog("反演失败！，由于未更新导入数据！");
        return;
    }
    if(_isNeedUpdatePreProcessRFData){
        slot_preProcessRFData();
    }
    emit sigAppendLog("开始射线成像反演......");
    _expImagingModule->runRayImaging(_TADataBox, _sensorDecare, _rayImagingType, _basicPara.getSoS(), _basicPara.getFs());
}

void MainWindowTabWidget::slot_plotRayImagingTAI()
{
    MyFigure* myFigure = new MyFigure(baseUi);
    // myFigure->setAttribute(Qt::WA_DeleteOnClose); // 设置关闭时自动释放内存
    QString title_;
    switch(_rayImagingType){
    case RayImagingType::BP:
        title_ = "TAI BP";
        break;
    case RayImagingType::DAS:
        title_ = "TAI DAS";
    }

    myFigure->plotHeatMap(_TADataBox.viewData("TAI_RayImaging"), _TADataBox.viewData("TAI_RayImaging_xVec")
                          , _TADataBox.viewData("TAI_RayImaging_yVec"), title_);
    // myFigure->setMyAxisImage();
    // myFigure->setMyColorBar(ColorbarType::Parula);
    myFigure->setMyXLabel("x(mm)");
    myFigure->setMyYLabel("y(mm)");
    myFigure->setMyWindowTitle("反演成像结果");
    myFigure->show();
}

void MainWindowTabWidget::slot_setNonNegativeImagingType(const NonNegativeImagingType &tmp)
{
    if(_nonNegativeImagingType != tmp){
        _nonNegativeImagingType = tmp;
    }
}

//非负成像
void MainWindowTabWidget::slot_preShowNonNegativeImagingTAI()
{
    //
    if(_isNeedCalculateSensorDecare){
        calculateSensorDecare();
    }else{
        _isNeedCalculateSensorDecare = false;
    }
    if(_isNeedUpdateRFData){
        emit sigAppendLog("反演失败！，由于未更新导入数据！");
        return;
    }

    if(_isNeedUpdatePreProcessRFData){
        slot_preProcessRFData();
    }
    emit sigAppendLog("开始非负成像反演......");
    _expImagingModule->runNonNegativeImaging(_TADataBox,
                                             _sensorDecare, _rayImagingType, _nonNegativeImagingType,
                                             _basicPara.getSoS(), _basicPara.getFs());
}

void MainWindowTabWidget::slot_plotNonNegativeImagingTAI()
{
    MyFigure* myFigure = new MyFigure(baseUi);
    // myFigure->setAttribute(Qt::WA_DeleteOnClose); // 设置关闭时自动释放内存
    QString title_;
    //射线成像方式
    switch(_rayImagingType){
    case RayImagingType::BP:
        title_ = "TAI BP";
        break;
    case RayImagingType::DAS:
        title_ = "TAI DAS";
    }
    //非负成像方式
    switch(_nonNegativeImagingType){
    case NonNegativeImagingType::Amplitude:
        title_ += " with Amplitude";
        break;
    case NonNegativeImagingType::Energy1:
        title_ += " with Energy1";
        break;
    case NonNegativeImagingType::Energy2:
        title_ += " with Energy2";
        break;
    case NonNegativeImagingType::Peak_Peak:
        title_ += " with Peak-Peak";
        break;
    }

    myFigure->plotHeatMap(_TADataBox.viewData("TAI_NonNegativeImaging"), _TADataBox.viewData("TAI_NonNegativeImaging_xVec")
                          , _TADataBox.viewData("TAI_NonNegativeImaging_yVec"), title_);
    // myFigure->setMyAxisImage();
    // myFigure->setMyColorBar(ColorbarType::Parula);
    myFigure->setMyXLabel("x(mm)");
    myFigure->setMyYLabel("y(mm)");
    myFigure->setMyWindowTitle("反演成像结果");
    myFigure->show();
}

void MainWindowTabWidget::setNumOfSensorsAfterInsertValue(const int &tmp)
{
    if (_basicPara.getNumOfSensors() != tmp){
        emit sig_setSpinBoxSelectedSensorsMax(tmp);
        _basicPara.setNumOfSensors(tmp);
        _isNeedCalculateSensorDecare = true;
        emit sigAppendLog("通道数："+QString::number(_basicPara.getNumOfSensors()));
        _louKongProcessTool->slot_setNSens(tmp);
        emit sig_changeNumOfSensors(tmp);
    }
}

bool MainWindowTabWidget::loadRFData()
{
    if(_thread_loadRFData.get() != nullptr && _thread_loadRFData->isRunning()){
        emit sig_cancelLoadRFDataProgress();
        // _thread_loadRFData->quit();
        // _thread_loadRFData->wait();
        emit sigAppendLog("正在进行数据导入！请等待结束后，点击按钮，再进行下次数据的导入.....");
        return false;
    }
    //判断是否需要更新导入RFData
    if(_isNeedUpdateRFData){
        emit sigAppendLog("正在导入数据：");
        //添加RFData
        if(!_TADataBox.contains("RFData")){
            _TADataBox.addData(_basicPara.getNumOfSensors()*_basicPara.getTotalTimeSteps(),"RFData");
        }
        if(!_TADataBox.contains("RFData_xVec")){
            _TADataBox.addData(1*_basicPara.getTotalTimeSteps(),"RFData_xVec");
            QVector<float>& RFData_xVec = _TADataBox.getData("RFData_xVec");
            for(int i = 0; i < _basicPara.getTotalTimeSteps(); i++){
                RFData_xVec[i] = i+1;
            }
        }
        if(!_TADataBox.contains("RFData_yVec")){
            _TADataBox.addData(1*_basicPara.getNumOfSensors(),"RFData_yVec");
            QVector<float>& RFData_yVec = _TADataBox.getData("RFData_yVec");
            for(int i = 0; i < _basicPara.getNumOfSensors(); i++){
                RFData_yVec[i] = i+1;
            }
        }
        bool isOK(false);//判断导入数据是否成功
        //采用子线程按实验室类型进行射频数据导入
        //生成模态对话框
        // _dialog_progress = new QProgressDialog(this);
        _thread_loadRFData = std::make_shared<LoadRFDataThread>(&_basicPara,std::ref(_fileDirectoryName),
                                                                std::ref(_RFDataFileAddress),
                                                                &_TADataBox,this, &isOK,  &_isNeedUpdateRFData,
                                                                &_lastLoadPath, nullptr);
        connect(_thread_loadRFData.get(), &LoadRFDataThread::sigAppendLog, this,
                &MainWindowTabWidget::slot_appendLog);
        connect(_thread_loadRFData.get(), &LoadRFDataThread::sig_setExpPushButtonLoadRFDatasIcon, this,
                &MainWindowTabWidget::slot_setExpPushButtonLoadRFDatasIcon);
        connect(_thread_loadRFData.get(), &LoadRFDataThread::sig_setNumOfMeanFrames, this,
                &MainWindowTabWidget::slot_setNumOfMeanFrames);
        connect(this, &MainWindowTabWidget::sig_cancelLoadRFDataProgress, _thread_loadRFData.get(),&LoadRFDataThread::slotCancelProgress);
        // connect(_thread_createProj.get(), &ProjTreeThread::sigUpdateProgress,
        //         this, &ProjTreeWidget::slotUpdateProgress);
        // connect(_thread_createProj.get(), &ProjTreeThread::sigFinishProgress,
        //         this, &ProjTreeWidget::slotFinishProgress);

        // connect(_dialog_progress, &QProgressDialog::canceled, this, &ProjTreeWidget::slotCancelProgress);

        // connect(this, &ProjTreeWidget::sigCancelProgress, _thread_createProj.get(), &ProjTreeThread::slotCancelProgress);

        _thread_loadRFData->start();
        // _dialog_progress->setWindowTitle(tr("Please wait......"));
        // _dialog_progress->setFixedWidth(PROGRESS_WIDTH);
        // _dialog_progress->setRange(0, PROGRESS_WIDTH);
        // _dialog_progress->exec();

        return isOK;
    }else{
        return false;
    }
}

//根据不同类型进行滤波
void MainWindowTabWidget::filterRFData()
{
    //直接调用滤波工具进行滤波
    _filterTool->filter_2d(_TADataBox.getData("PreProcessedRFData"), _filterType, _basicPara.getNumOfSensors(), _basicPara.getTotalTimeSteps());
    // //测试是否到达
    // emit sigAppendLog("filterRFData()");
}

void MainWindowTabWidget::deConvolutionRFData()
{
    //测试是否到达
    emit sigAppendLog("deConvolutionRFData()");
}

void MainWindowTabWidget::cutZerosRFData()
{
    if(_cutZerosTimeSteps == 0 || _cutZerosTimeSteps <0)
    {
        return;
    }
    int cutEnd = _cutZerosTimeSteps;
    if(_cutZerosTimeSteps >= _TADataBox.getDataSize("PreProcessedRFData_xVec")){
        cutEnd = _TADataBox.getDataSize("PreProcessedRFData_xVec");
    }
    QVector<float>& preProcessedRFData = _TADataBox.getData("PreProcessedRFData");
    for(int i = 0; i < _TADataBox.getDataSize("PreProcessedRFData_yVec");++i){
        for(int j = 0; j < cutEnd; ++j){
            preProcessedRFData[i + j*_TADataBox.getDataSize("PreProcessedRFData_yVec")] = 0;
        }
    }
    //测试是否到达
    // emit sigAppendLog("cutZerosRFData()");
}

void MainWindowTabWidget::louKongProcessRFData()
{
    //直接调用镂空处理类进行处理
    _louKongProcessTool->runLouKongProcess(_TADataBox.getData("PreProcessedRFData"));
    //测试是否到达
    // emit sigAppendLog("louKongProcessRFData()");
}

void MainWindowTabWidget::insertValueRFData()
{
    //直接调用插值处理类进行处理
    _insertValueTool->runInsertValue(_TADataBox.getData("PreProcessedRFData"), _basicPara.getNumOfSensors(), _basicPara.getTotalTimeSteps(), _insertValueType);
    //插值后需要修改传感器阵列信号的纵坐标
    setNumOfSensorsAfterInsertValue(2*_basicPara.getNumOfSensors()-1);//修改插值后的通道数
    QVector<float>& preProcessedRFData_yVec_ = _TADataBox.getData("PreProcessedRFData_yVec");
    preProcessedRFData_yVec_.resize(_basicPara.getNumOfSensors());
    for(int i = 0; i < _basicPara.getNumOfSensors(); ++i){
        preProcessedRFData_yVec_[i] = i+1;
    }
    calculateSensorDecare();//修改传感器坐标
    // //测试是否到达
    // emit sigAppendLog("insertValueRFData()");
}

void MainWindowTabWidget::hilbertRFData()
{
    const int N = _TADataBox.getDataSize("PreProcessedRFData_xVec");

    QVector<float>& preProcessedRFData_ = _TADataBox.getData("PreProcessedRFData");
    QVector<float> tmp(preProcessedRFData_.size());
    //拷贝数据
    for(int i = 0; i < tmp.size(); ++i){
        tmp[i] = preProcessedRFData_[i];
    }

    // 1. 执行FFT
    fftw_complex *in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    fftw_complex *out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    fftw_plan plan = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
    // 3. 执行逆FFT得到解析信号
    fftw_plan inv_plan = fftw_plan_dft_1d(N, out, in, FFTW_BACKWARD, FFTW_ESTIMATE);
    // 4. 提取虚部（即希尔伯特变换结果）
    QVector<double> hilbert(N);
    double tmp_out;

    //依次求解单通道信号的包络
    for(int sensInd = 0; sensInd < _TADataBox.getDataSize("PreProcessedRFData_yVec"); sensInd++){
        // 填充输入数据（实部为信号，虚部为0）
        for (int i = 0; i < N; ++i) {
            in[i][0] = tmp[sensInd + i*_TADataBox.getDataSize("PreProcessedRFData_yVec")];
            in[i][1] = 0.0;
        }
        fftw_execute(plan);

        // 2. 频域处理：正频率乘以-i，负频段乘以i,0频点乘以0
        for (int i = 1; i < N/2; ++i) {
            tmp_out = out[i][0];
            out[i][0] = out[i][1];
            out[i][1] = -1.0*tmp_out;
        }
        for (int i = N/2 + 1; i < N; ++i) {
            tmp_out = out[i][0];
            out[i][0] = out[i][1];
            out[i][1] = -1.0*tmp_out;
        }

        fftw_execute(inv_plan);

        for (int i = 0; i < N; ++i) {
            hilbert[i] = in[i][1] / N; // FFTW结果未归一化，需除以N
        }

        //计算包络
        for (int i = 0; i < N; ++i) {
            preProcessedRFData_[sensInd + i*_TADataBox.getDataSize("PreProcessedRFData_yVec")] =
                sqrt(tmp[sensInd + i*_TADataBox.getDataSize("PreProcessedRFData_yVec")]*tmp[sensInd
             + i*_TADataBox.getDataSize("PreProcessedRFData_yVec")] + hilbert[i]*hilbert[i]);
        }
    }
    // 清理资源
    fftw_destroy_plan(plan);
    fftw_destroy_plan(inv_plan);
    fftw_free(in);
    fftw_free(out);
}

