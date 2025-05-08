#include "myfigure.h"
#include "ui_myfigure.h"
#include<QScreen>
#include<algorithm>
#include<QFile>
#include<QTextStream>
#include <QRegularExpression>

MyFigure::MyFigure(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyFigure)
{
    ui->setupUi(this);
    this->setWindowTitle("MyFigure");
    this->setWindowIcon(QIcon(":/icon/MTAI.ico"));
    isHaveTitle = false;
    HWRatio = 0.5;
    // 获取当前显示窗口的屏幕
    QScreen *screen = this->screen();
    // 获取屏幕的可用工作区大小
    QRect availableGeometry = screen->availableGeometry();
    // 获取可用区域的宽度和高度
    availableWidth = availableGeometry.width();
    availableHeight = availableGeometry.height();
    // updateHW();
    isSetAxisImage = false;
    // 连接轴范围变化信号
    connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(checkXAxisRange(QCPRange)));
    connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(checkYAxisRange(QCPRange)));

    //设置图标
    ui->toolButton_confirmColorbar->setIcon(QIcon(":/icon/confirm.png"));
    ui->toolButton_confirmTitle->setIcon(QIcon(":/icon/confirm.png"));
    ui->toolButton_confirmXLabel->setIcon(QIcon(":/icon/confirm.png"));
    ui->toolButton_confirmYLabel->setIcon(QIcon(":/icon/confirm.png"));
    ui->toolButton_confirmLineColor->setIcon(QIcon(":/icon/confirm.png"));
    ui->toolButton_confirmLineStyle->setIcon(QIcon(":/icon/confirm.png"));
    ui->toolButton_confirmWordSize->setIcon(QIcon(":/icon/confirm.png"));
    ui->toolButton_confirmWordType->setIcon(QIcon(":/icon/confirm.png"));

    //样式选择
    _currentLineStyle = QCPScatterStyle::ScatterShape::ssNone;//默认第一条曲线什么也没有
    _selectedLineStyle = QCPScatterStyle::ScatterShape::ssNone;
    ui->comboBox_lineStyle->addItems({"-","×","+","○","●","□","*"});
    ui->comboBox_lineColor->addItems({"Blue","Red"});

    // 连接信号槽：滑块值变化时更新标签
    connect(ui->horizontalSlider_dynamicRange, &QSlider::valueChanged, [=](int value) {
        ui->label_dynamicRange->setText(QString::number(value));
    });
    connect(ui->horizontalSlider_gain, &QSlider::valueChanged, [=](int value) {
        ui->label_gain->setText(QString::number(value));
    });

    //字体样式选择
    ui->comboBox_wordType->addItems(WordType);
    //字号
    ui->comboBox_wordSize->addItems({"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19",
                                    "20","21","22","23","24","25","26","27","28","29","30","31","32","33","34","35","36","37","38","39","40"});


}

MyFigure::~MyFigure()
{
    delete ui;
    if(colorMap != nullptr){
        delete colorMap;
    }
    if(m_title != nullptr){
        delete m_title;
    }
}

// myfigure.cpp
void MyFigure::plotHeatMap(const QVector<float> &data,
                           const QVector<float> &xVec,
                           const QVector<float> &yVec,
                           const QString &title_) {

    // configure axis rect:
    ui->customPlot->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom); // this will also allow rescaling the color scale by dragging/zooming
    ui->customPlot->axisRect()->setupFullAxesBox(true);
    setMyXLabel("x");
    setMyYLabel("y");
    // // 创建或更新标题
    setMyMapTitle(title_);

    // set up the QCPColorMap:
    colorMap = new QCPColorMap(ui->customPlot->xAxis, ui->customPlot->yAxis);
    int nx = xVec.size();
    int ny = yVec.size();
    colorMap->data()->setSize(nx, ny); // we want the color map to have nx * ny data points
    _xRange = QCPRange(minVec(xVec),maxVec(xVec));
    _yRange = QCPRange(minVec(yVec),maxVec(yVec));
    colorMap->data()->setRange(_xRange, _yRange);
    // now we assign some data, by accessing the QCPColorMapData instance of the color map:
    double x, y, z;
    for (int xIndex=0; xIndex<nx; ++xIndex)
    {
        for (int yIndex=0; yIndex<ny; ++yIndex)
        {
            colorMap->data()->cellToCoord(xIndex, yIndex, &x, &y);
            z = data[yIndex+ny*xIndex];
            colorMap->data()->setCell(xIndex, yIndex, z);
        }
    }

    // add a color scale:
    QCPColorScale *colorScale = new QCPColorScale(ui->customPlot);
    ui->customPlot->plotLayout()->addElement(1, 1, colorScale); // add it to the right of the main axis rect
    colorScale->setType(QCPAxis::atRight); // scale shall be vertical bar with tick/axis labels right (actually atRight is already the default)
    colorScale->setRangeZoom(false);
    colorScale->setRangeDrag(false);
    colorMap->setColorScale(colorScale); // associate the color map with the color scale
    // colorScale->axis()->setLabel("Magnetic Field Strength");

    // rescale the data dimension (color) such that all data points lie in the span visualized by the color gradient:
    colorMap->rescaleDataRange();

    // make sure the axis rect and color scale synchronize their bottom and top margins (so they line up):
    QCPMarginGroup *marginGroup = new QCPMarginGroup(ui->customPlot);
    ui->customPlot->axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
    colorScale->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);

    // rescale the key (x) and value (y) axes so the whole color map is visible:
    ui->customPlot->rescaleAxes();

    // setMyAxisImage();
    setMyColorBar(ColorbarType::Gray);
    ui->customPlot->replot();
    this->setWindowTitle("heatMap");
    ui->comboBox_selectColorbar->addItems({"gray","hot","parula","jet","thermal","night","cold","candy"});
}

QCPGraph* MyFigure::plotCurve(const QVector<float> &xData,
                              const QVector<float> &yData,
                              const QColor &color,
                              int lineWidth,const QString& curveName) {

    if(curves.isEmpty()){
        ui->customPlot->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom); // this will also allow rescaling the color scale by dragging/zooming
        // ui->customPlot->axisRect()->setupFullAxesBox(true);
        //先将xData和yData转为double
        QVector<double> double_xData(xData.size());
        QVector<double> double_yData(yData.size());

        floatToDouble(double_xData, xData);
        floatToDouble(double_yData, yData);
        //
        QCPGraph *graph = ui->customPlot->addGraph();
        graph->setData(double_xData, double_yData);
        graph->setPen(QPen(color, lineWidth));
        curves.append(graph);

        _xRange = QCPRange(minVec(xData),maxVec(xData));
        _yRange = QCPRange(minVec(yData),maxVec(yData));
        ui->customPlot->xAxis->setRange(_xRange);
        ui->customPlot->yAxis->setRange(_yRange);
        ui->comboBox_lineStyle->addItems({"-","×","+","○","●","□","*"});
        graph->setScatterStyle(_currentLineStyle);
        updateLineStyle(_currentLineStyle);
        _scatterSkip = qFloor(xData.size()/N_SCATTER_DOTS);
        graph->setScatterSkip(_scatterSkip);

        int curvesN = curves.size();
        if(curveName == ""){
            graph->setName("curve No: "+QString::number(curvesN));
        }else{
            graph->setName(curveName);
        }
        ui->customPlot->replot();
        return graph;}
    else{
        return addCurve(xData,yData, color, lineWidth, curveName);
    }
}

QCPGraph* MyFigure::addCurve(const QVector<float> &xData, const QVector<float> &yData, const QColor &color, int lineWidth, const QString& curveName)
{
    if(curves.isEmpty()){
        return plotCurve(xData,yData, color, lineWidth, curveName);
    }else{
        //先将xData和yData转为double
        QVector<double> double_xData;
        QVector<double> double_yData;
        double_xData.resize(xData.size());
        std::transform(xData.begin(), xData.end(), double_xData.begin(),
                       [](float f) { return static_cast<double>(f); });
        double_yData.resize(yData.size());
        std::transform(yData.begin(), yData.end(), double_yData.begin(),
                       [](float f) { return static_cast<double>(f); });
        //
        QCPGraph *graph = ui->customPlot->addGraph();
        graph->setData(double_xData, double_yData);
        graph->setPen(QPen(color, lineWidth));
        curves.append(graph);

        QCPRange xRangeTmp(std::min(_xRange.lower,static_cast<double>(minVec(xData))),std::max(_xRange.upper,static_cast<double>(maxVec(xData))));
        QCPRange yRangeTmp(std::min(_yRange.lower,static_cast<double>(minVec(yData))),std::max(_yRange.upper,static_cast<double>(maxVec(yData))));
        ui->customPlot->xAxis->setRange(xRangeTmp);
        ui->customPlot->yAxis->setRange(yRangeTmp);
        graph->setScatterStyle(_currentLineStyle);
        updateLineStyle(_currentLineStyle);
        graph->setScatterSkip(_scatterSkip);
        int curvesN = curves.size();
        if(curveName == ""){
            graph->setName("curve No: "+QString::number(curvesN));
        }else{
            graph->setName(curveName);
        }
        if(curvesN > 1){
            ui->customPlot->legend->setVisible(true);
        }
        ui->customPlot->replot();
        return graph;
    }
}

void MyFigure::updateColorGradient(QCPColorGradient::GradientPreset preset) {
    if(colorMap) {
        colorMap->setGradient(preset);
        ui->customPlot->replot();
    }
}

void MyFigure::updateHW()
{
    double MaxH_ = 0.9*availableHeight;
    double MaxW_ = 0.9*0.8*availableWidth;
    MaxCustomPlotHeight = std::min(qFloor(HWRatio*MaxW_), qFloor(MaxH_));
    MaxCustomPlotWidth = std::min(qFloor(MaxW_), qFloor(MaxH_/HWRatio));
    ui->customPlot->setMaximumHeight(MaxCustomPlotHeight);
    ui->customPlot->setMaximumWidth(MaxCustomPlotWidth);
}

bool MyFigure::setMyMapTitle(const QString title)
{
    if(!isHaveTitle){
        ui->customPlot->plotLayout()->insertRow(0);
        m_title = new QCPTextElement(ui->customPlot);
        ui->lineEdit_title->setText(title);
        m_title->setText(title);
        ui->customPlot->plotLayout()->addElement(0, 0, m_title);
        isHaveTitle= true;
        ui->customPlot->replot();
        return true;
    }else
    {
        ui->lineEdit_title->setText(title);
        m_title->setText(title);
        ui->customPlot->replot();
        return true;
    }
    return false;
}

bool MyFigure::setMyWindowTitle(const QString title)
{
    bool is = false;
    this->setWindowTitle(title);
    is = true;
    if( is){
        return true;}
    else{
        return false;
    }
}

bool MyFigure::setMyColorBar(const ColorbarType colorbarType)
{
    bool is = false;
    switch(colorbarType){
    case ColorbarType::Gray:
        updateColorGradient(QCPColorGradient::gpGrayscale);
        is = true;
        break;
    case ColorbarType::Hot:
        updateColorGradient(QCPColorGradient::gpHot);
        is = true;
        break;
    case ColorbarType::Candy:
        updateColorGradient(QCPColorGradient::gpCandy);
        is = true;
        break;
    case ColorbarType::Cold:
        updateColorGradient(QCPColorGradient::gpCold);
        is = true;
        break;
    case ColorbarType::Jet:
        updateColorGradient(QCPColorGradient::gpJet);
        is = true;
        break;
    case ColorbarType::Night:
        updateColorGradient(QCPColorGradient::gpNight);
        is = true;
        break;
    case ColorbarType::Parula:
        if(!isSetParulaGradient){
            set_parulaGradient();
            isSetParulaGradient = true;
        }
        if(colorMap) {
            colorMap->setGradient(parulaGradient);
            ui->customPlot->replot();
        }
        break;
    case ColorbarType::Thermal:
        updateColorGradient(QCPColorGradient::gpThermal);
        is = true;
        break;
    default:
        break;
    }
    return is;
}

bool MyFigure::setMyXLabel(const QString xLabel_)
{
    bool ok = false;
    ui->customPlot->xAxis->setLabel(xLabel_);
    ui->lineEdit_xLabel->setText(xLabel_);
    ui->customPlot->replot();
    ok = true;
    return ok;
}

bool MyFigure::setMyYLabel(const QString yLabel_)
{
    bool ok = false;
    ui->customPlot->yAxis->setLabel(yLabel_);
    ui->lineEdit_yLabel->setText(yLabel_);
    ui->customPlot->replot();
    ok = true;
    return ok;
}

void MyFigure::setMyAxisImage()
{
    HWRatio = static_cast<double> (ui->customPlot->height())/(ui->customPlot->width());
    updateHW();
    ui->customPlot->setFixedHeight(ui->customPlot->width() * HWRatio);
    isSetAxisImage = true;
}

//依次更新下一个线条样式
void MyFigure::updateLineStyle(QCPScatterStyle::ScatterShape &inputLineStyle)
{
    switch(inputLineStyle){
        case QCPScatterStyle::ScatterShape::ssNone:
            inputLineStyle = QCPScatterStyle::ScatterShape::ssCross;
            break;
        case QCPScatterStyle::ScatterShape::ssCross:
            inputLineStyle = QCPScatterStyle::ScatterShape::ssPlus;
            break;
        case QCPScatterStyle::ScatterShape::ssPlus:
            inputLineStyle = QCPScatterStyle::ScatterShape::ssCircle;
            break;
        case QCPScatterStyle::ScatterShape::ssCircle:
            inputLineStyle = QCPScatterStyle::ScatterShape::ssDisc;
            break;
        case QCPScatterStyle::ScatterShape::ssDisc:
            inputLineStyle = QCPScatterStyle::ScatterShape::ssSquare;
            break;
        case QCPScatterStyle::ScatterShape::ssSquare:
            inputLineStyle = QCPScatterStyle::ScatterShape::ssStar;
            break;
        case QCPScatterStyle::ScatterShape::ssStar:
            inputLineStyle = QCPScatterStyle::ScatterShape::ssNone;
            break;
    }
}

void MyFigure::updateCurvesLineStyle(QCPScatterStyle::ScatterShape& inputLineStyle)
{
    if(curves.isEmpty()){
        return;
    }
    //根据不同的输入依次设置曲线线条样式
    for (auto it = curves.begin(); it != curves.end(); ++it) {
        QCPGraph* graph = *it;
        if (!graph) continue; // 跳过空指针
        // 处理当前 graph
        graph->setScatterStyle(inputLineStyle);
        updateLineStyle(inputLineStyle);
    }
}

void MyFigure::setYRange(QCPRange yRange)
{
    _yRange = yRange;
    ui->customPlot->yAxis->setRange(_yRange);
    ui->customPlot->replot();
}

void MyFigure::setXRange(QCPRange xRange)
{
    _xRange = xRange;
    ui->customPlot->xAxis->setRange(_xRange);
    ui->customPlot->replot();
}

//重写缩放窗口函数事件
void MyFigure::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

    if(isSetAxisImage){
        ui->customPlot->setFixedHeight(ui->customPlot->width() * HWRatio);
        ui->customPlot->replot();
    }
}

//导入并设置parula渐变
void MyFigure::set_parulaGradient()
{
    QFile file(":/matlabParula.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "无法打开文件 parula.txt";
        return;
    }

    QTextStream in(&file);
    QMap<double, QColor> parulaStops;
    int lineCount = 0;

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        QStringList parts = line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
        if (parts.size() != 3) {
            qDebug() << "行格式错误：" << line;
            continue;
        }

        // 转换为浮点数并生成 QColor
        bool ok;
        double r = parts[0].toDouble(&ok);
        double g = parts[1].toDouble(&ok);
        double b = parts[2].toDouble(&ok);
        if (!ok || r < 0.0 || r > 1.0 || g < 0.0 || g > 1.0 || b < 0.0 || b > 1.0) {
            qDebug() << "无效的 RGB 值：" << line;
            continue;
        }

        parulaStops.insert(
            static_cast<double>(lineCount) / 255.0,
            QColor(
                qRound(r * 255),
                qRound(g * 255),
                qRound(b * 255)
                )
            );

        lineCount++;
    }
    file.close();

    if (lineCount != 256) {
        qDebug() << "颜色数据不完整，应为 256 行，实际读取：" << lineCount;
        return;
    }

    // 创建并应用渐变
    parulaGradient.setColorStops(parulaStops);
}

// 检查并限制 X 轴范围
// 检查并限制 X 轴范围
void MyFigure::checkXAxisRange(const QCPRange &newRange)
{
    QCPRange _setRange(newRange);
    bool isNeed(false);
    if (newRange.lower < _xRange.lower) {
        _setRange.lower = _xRange.lower;
        isNeed = true;
    }
    if (newRange.upper > _xRange.upper) {
        _setRange.upper = _xRange.upper;
        isNeed = true;
    }
    if(isNeed){
        ui->customPlot->xAxis->setRange(_setRange);
        ui->customPlot->replot();
    }
}

void MyFigure::checkYAxisRange(const QCPRange &newRange)
{
    QCPRange _setRange(newRange);
    bool isNeed(false);
    if (newRange.lower < _yRange.lower) {
        _setRange.lower = _yRange.lower;
        isNeed = true;
    }
    if (newRange.upper > _yRange.upper) {
        _setRange.upper = _yRange.upper;
        isNeed = true;
    }
    if(isNeed){
        ui->customPlot->yAxis->setRange(_setRange);
        ui->customPlot->replot();
    }
}

// void MyFigure::setupConnections() {
//     connect(ui->btnSave, &QPushButton::clicked, this, &MyFigure::onSaveClicked);
//     connect(ui->cmbColorGradient, QOverload<int>::of(&QComboBox::currentIndexChanged),
//             this, &MyFigure::onGradientChanged);
// }

//确认修改标题
void MyFigure::on_toolButton_confirmTitle_clicked()
{
    if(!isHaveTitle){
        ui->customPlot->plotLayout()->insertRow(0);
        m_title = new QCPTextElement(ui->customPlot);
        m_title->setText(ui->lineEdit_title->text());
        ui->customPlot->plotLayout()->addElement(0, 0, m_title);
        isHaveTitle= true;
    }else
    {
        m_title->setText(ui->lineEdit_title->text());
    }
    ui->customPlot->replot();
}


void MyFigure::on_lineEdit_title_returnPressed()
{
    if(!isHaveTitle){
        ui->customPlot->plotLayout()->insertRow(0);
        m_title = new QCPTextElement(ui->customPlot);
        m_title->setText(ui->lineEdit_title->text());
        ui->customPlot->plotLayout()->addElement(0, 0, m_title);
        isHaveTitle= true;
    }else
    {
        m_title->setText(ui->lineEdit_title->text());
    }
    ui->customPlot->replot();
}

//保存图片
bool MyFigure::on_saveFigButton_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "保存为图片文件", " ","PNG文件(*.png);;JPG文件(*.jpg);;BMP文件(*.bmp);;PDF文件(*.pdf)");

    if( filename == "" ){
        QMessageBox::information(this,"fail","保存失败");
        return false;
    }
    if( filename.endsWith(".png") ){
        QMessageBox::information(this,"success","成功保存为png文件");
        return ui->customPlot->savePng( filename, ui->customPlot->width(), ui->customPlot->height());

    }
    if( filename.endsWith(".jpg")||filename.endsWith(".jpeg") ){
        QMessageBox::information(this,"success","成功保存为jpg文件");
        return ui->customPlot->saveJpg( filename, ui->customPlot->width(), ui->customPlot->height() );

    }
    if( filename.endsWith(".bmp") ){
        QMessageBox::information(this,"success","成功保存为bmp文件");
        return ui->customPlot->saveBmp( filename, ui->customPlot->width(), ui->customPlot->height() );

    }
    if( filename.endsWith(".pdf") ){
        QMessageBox::information(this,"success","成功保存为pdf文件");
        return ui->customPlot->savePdf( filename, ui->customPlot->width(), ui->customPlot->height() );

    }
    else{
        //否则追加后缀名为.png保存文件
        QMessageBox::information(this,"success","保存成功,已默认保存为png文件");
        return ui->customPlot->savePng(filename.append(".png"), ui->customPlot->width(), ui->customPlot->height() );

    }
}

//换色阶
void MyFigure::on_toolButton_confirmColorbar_clicked()
{
    switch(ui->comboBox_selectColorbar->currentIndex()){
    case 0://gray
        setMyColorBar(ColorbarType::Gray);
        break;
    case 1:
        setMyColorBar(ColorbarType::Hot);
        break;
    case 2:
        setMyColorBar(ColorbarType::Parula);
        break;
    case 3:
        setMyColorBar(ColorbarType::Jet);
        break;
    case 4:
        setMyColorBar(ColorbarType::Thermal);
        break;
    case 5:
        setMyColorBar(ColorbarType::Night);
        break;
    case 6:
        setMyColorBar(ColorbarType::Cold);
        break;
    case 7:
        setMyColorBar(ColorbarType::Candy);
        break;
    default:
        break;
    }
}


void MyFigure::on_lineEdit_xLabel_returnPressed()
{
    setMyXLabel(ui->lineEdit_xLabel->text());
}


void MyFigure::on_lineEdit_yLabel_returnPressed()
{
    setMyYLabel(ui->lineEdit_yLabel->text());
}


void MyFigure::on_toolButton_confirmXLabel_clicked()
{
    setMyXLabel(ui->lineEdit_xLabel->text());
}


void MyFigure::on_toolButton_confirmYLabel_clicked()
{
    setMyYLabel(ui->lineEdit_yLabel->text());
}


void MyFigure::on_toolButton_confirmLineStyle_clicked()
{
    switch(ui->comboBox_lineStyle->currentIndex()){
    case 0://分情况判断是否需要更新
        if(_selectedLineStyle == QCPScatterStyle::ScatterShape::ssNone){
            return;
        }
        _selectedLineStyle = QCPScatterStyle::ScatterShape::ssNone;
        _currentLineStyle = _selectedLineStyle;
        updateCurvesLineStyle(_currentLineStyle);
        break;
    case 1://分情况判断是否需要更新
        if(_selectedLineStyle == QCPScatterStyle::ScatterShape::ssCross){
            return;
        }
        _selectedLineStyle = QCPScatterStyle::ScatterShape::ssCross;
        _currentLineStyle = _selectedLineStyle;
        updateCurvesLineStyle(_currentLineStyle);
        break;
    case 2://分情况判断是否需要更新
        if(_selectedLineStyle == QCPScatterStyle::ScatterShape::ssPlus){
            return;
        }
        _selectedLineStyle = QCPScatterStyle::ScatterShape::ssPlus;
        _currentLineStyle = _selectedLineStyle;
        updateCurvesLineStyle(_currentLineStyle);
        break;
    case 3://分情况判断是否需要更新
        if(_selectedLineStyle == QCPScatterStyle::ScatterShape::ssCircle){
            return;
        }
        _selectedLineStyle = QCPScatterStyle::ScatterShape::ssCircle;
        _currentLineStyle = _selectedLineStyle;
        updateCurvesLineStyle(_currentLineStyle);
        break;
    case 4://分情况判断是否需要更新
        if(_selectedLineStyle == QCPScatterStyle::ScatterShape::ssDisc){
            return;
        }
        _selectedLineStyle = QCPScatterStyle::ScatterShape::ssDisc;
        _currentLineStyle = _selectedLineStyle;
        updateCurvesLineStyle(_currentLineStyle);
        break;
    case 5://分情况判断是否需要更新
        if(_selectedLineStyle == QCPScatterStyle::ScatterShape::ssSquare){
            return;
        }
        _selectedLineStyle = QCPScatterStyle::ScatterShape::ssSquare;
        _currentLineStyle = _selectedLineStyle;
        updateCurvesLineStyle(_currentLineStyle);
        break;
    case 6://分情况判断是否需要更新
        if(_selectedLineStyle == QCPScatterStyle::ScatterShape::ssStar){
            return;
        }
        _selectedLineStyle = QCPScatterStyle::ScatterShape::ssStar;
        _currentLineStyle = _selectedLineStyle;
        updateCurvesLineStyle(_currentLineStyle);
        break;
    }
}


void MyFigure::on_toolButton_confirmWordType_clicked()
{
    m_title->setFont(QFont(WordType[ui->comboBox_wordType->currentIndex()],(ui->comboBox_wordSize->currentIndex()+1), QFont::Bold));
    ui->customPlot->xAxis->setLabelFont(QFont(WordType[ui->comboBox_wordType->currentIndex()],(ui->comboBox_wordSize->currentIndex()+1)));
    ui->customPlot->yAxis->setLabelFont(QFont(WordType[ui->comboBox_wordType->currentIndex()],(ui->comboBox_wordSize->currentIndex()+1)));
    ui->customPlot->replot();
}


void MyFigure::on_toolButton_confirmWordSize_clicked()
{
    m_title->setFont(QFont(WordType[ui->comboBox_wordType->currentIndex()],(ui->comboBox_wordSize->currentIndex()+1), QFont::Bold));
    ui->customPlot->xAxis->setLabelFont(QFont(WordType[ui->comboBox_wordType->currentIndex()],(ui->comboBox_wordSize->currentIndex()+1)));
    ui->customPlot->yAxis->setLabelFont(QFont(WordType[ui->comboBox_wordType->currentIndex()],(ui->comboBox_wordSize->currentIndex()+1)));
    ui->customPlot->replot();
}

