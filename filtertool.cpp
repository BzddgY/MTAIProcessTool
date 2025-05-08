#include "filtertool.h"
#include "ui_filtertool.h"
#include<algorithm>

FilterTool::FilterTool(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FilterTool)
{
    ui->setupUi(this);
    ui->comboBox_preShowFilterType->addItems({"矩形窗","海明窗","汉宁窗","布莱克窗","凯瑟尔窗"});
    _M = ui->spinBox_M->value(); _fSample = ui->spinBox_Fs->value();
    _fPass = ui->doubleSpinBox_FPass->value();
    _fStop = ui->doubleSpinBox_FStop->value();
    _beta = ui->doubleSpinBox_beta->value();
    _filterType = FilterType::rectangleWindow;
    ui->checkBox->setChecked(true);
}

FilterTool::~FilterTool()
{
    delete ui;
}

void FilterTool::filter_2d(QVector<float> &originSignal_, const FilterType& filterType_, const int& Nsens, const int& Ntime)
{
    //根据不同的滤波类型计算滤波窗函数
    QVector<double> filterW_n = calculateWn(filterType_);
    //利用窗函数进行滤波

    int N = Ntime;
    int M = _M;
    int L = N + M - 1; // 卷积结果长度

    // 输入信号FFT
    fftw_complex *in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * L);
    fftw_complex *out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * L);
    fftw_plan p = fftw_plan_dft_1d(L, in, out, FFTW_FORWARD, FFTW_ESTIMATE);

    // 滤波器系数FFT
    fftw_complex *h_in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * L);
    fftw_complex *h_out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * L);
    fftw_plan h_p = fftw_plan_dft_1d(L, h_in, h_out, FFTW_FORWARD, FFTW_ESTIMATE);

    // 填充滤波器系数
    for (int i = 0; i < L; ++i) {
        h_in[i][0] = (i < M) ? filterW_n[i] : 0.0;
        h_in[i][1] = 0.0;
    }
    fftw_execute(h_p);

    // 频域相乘
    fftw_complex *result = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * L);

    fftw_plan inv_p = fftw_plan_dft_1d(L, result, out, FFTW_BACKWARD, FFTW_ESTIMATE);

    //依次对每个通道信号进行滤波
    for(int sensInd = 0; sensInd < Nsens; ++sensInd){
        // 填充输入信号
        for (int i = 0; i < L; ++i) {
            in[i][0] = (i < N) ? originSignal_[sensInd + i*Nsens] : 0.0;
            in[i][1] = 0.0;
        }
        fftw_execute(p);


        for (int i = 0; i < L; ++i) {
            result[i][0] = out[i][0] * h_out[i][0] - out[i][1] * h_out[i][1];
            result[i][1] = out[i][0] * h_out[i][1] + out[i][1] * h_out[i][0];
        }

        // IFFT
        fftw_execute(inv_p);

        // 提取实部
        for (int i = 0; i < N; ++i) {
            originSignal_[sensInd + i*Nsens] = out[i][0] / L; // FFTW未归一化，需除以长度
        }

    }

    // 清理资源
    fftw_destroy_plan(p);
    fftw_destroy_plan(h_p);
    fftw_destroy_plan(inv_p);
    fftw_free(in); fftw_free(out);
    fftw_free(h_in); fftw_free(h_out);
    fftw_free(result);
}

void FilterTool::on_comboBox_preShowFilterType_currentIndexChanged(int index)
{
    switch(index){
    case 0:
        _filterType = FilterType::rectangleWindow;
        break;
    case 1:
        _filterType = FilterType::hammingWindow;
        break;
    case 2:
        _filterType = FilterType::hanningWindow;
        break;
    case 3:
        _filterType = FilterType::blackManWindow;
        break;
    case 4:
        _filterType = FilterType::kaiserWindow;
        break;
    default:
        break;
    }
    if(ui->checkBox->isChecked()){
        calculateM();
    }
}


void FilterTool::on_spinBox_M_editingFinished()
{
    if(ui->spinBox_M->value()!=_M){
        _M = ui->spinBox_M->value();
    }
}


void FilterTool::on_spinBox_Fs_editingFinished()
{
    if(ui->spinBox_Fs->value() != _fSample){
        _fSample = ui->spinBox_Fs->value();
    }
}


void FilterTool::on_doubleSpinBox_beta_editingFinished()
{
    if(ui->doubleSpinBox_beta->value() != _beta){
        _beta = ui->doubleSpinBox_beta->value();
    }
}


void FilterTool::on_doubleSpinBox_FPass_editingFinished()
{
    if(ui->doubleSpinBox_FPass->value()!= _fPass){
        _fPass = ui->doubleSpinBox_FPass->value();
    }
}


void FilterTool::on_doubleSpinBox_FStop_editingFinished()
{
    if(ui->doubleSpinBox_FStop->value() != _fStop){
        _fStop = ui->doubleSpinBox_FStop->value();
    }
}


void FilterTool::on_pushButton_adjustM_clicked()
{
    if(ui->checkBox->isChecked()){
        calculateM();
    }
}


void FilterTool::on_checkBox_stateChanged(int arg1)
{
    switch(arg1){
    case 0://未勾选
        ui->spinBox_M->setReadOnly(false);
        break;
    case 2://勾选
        ui->spinBox_M->setReadOnly(true);
        calculateM();
        break;
    }
}

void FilterTool::calculateM()
{
    double deltaF;
    deltaF = 2*M_PI*(_fStop-_fPass)/_fSample;
    switch(_filterType){
    case FilterType::rectangleWindow:
        _M = int(1.8*M_PI / deltaF);
        ui->spinBox_M->setValue(_M);
        break;
    case FilterType::hammingWindow:
        _M = int(6.6*M_PI / deltaF);
        ui->spinBox_M->setValue(_M);
        break;
    case FilterType::hanningWindow:
        _M = int(6.2*M_PI / deltaF);
        ui->spinBox_M->setValue(_M);
        break;
    case FilterType::blackManWindow:
        _M = int(11*M_PI / deltaF);
        ui->spinBox_M->setValue(_M);
        break;
    case FilterType::kaiserWindow:
        _M = int(10*M_PI / deltaF);
        ui->spinBox_M->setValue(_M);
        break;
    default:
        break;
    }
}

QVector<double> FilterTool::calculateWn(const FilterType &filterType_)
{
    QVector<double> filterWn(_M);
    switch(filterType_){
    case FilterType::rectangleWindow:
        for(int i = 0; i < _M; ++i){
            filterWn[i] = 1;
        }
        break;
    case FilterType::hammingWindow:
        for(int i = 0; i < _M; ++i){
            filterWn[i] = (0.54-0.46*cos(2*M_PI*i/(_M-1)));
        }
        break;
    case FilterType::hanningWindow:
        for(int i = 0; i < _M; ++i){
            filterWn[i] = 0.5*(1-cos(2*M_PI*i/(_M-1)));
        }
        break;
    case FilterType::blackManWindow:
        for(int i = 0; i < _M; ++i){
            filterWn[i] = (0.42-0.5*cos(2*M_PI*i/(_M-1))+0.08*cos(4*M_PI*i/(_M-1)));
        }
        break;
    case FilterType::kaiserWindow:
        for(int i = 0; i < _M; ++i){
            filterWn[i] = modifiedBessel0(_beta*sqrt(1-(1-2*i/(_M-1))*(1-2*i/(_M-1)))) / modifiedBessel0(_beta);
        }
        break;
    default:
        break;
    }
    return filterWn;
}



void FilterTool::on_pushButton_preShowFilterWindow_clicked()
{
    //根据不同的滤波类型计算滤波窗函数
    QVector<double> coeffs = calculateWn(_filterType);
    int N = _M;
    float fftSize = 4096;

    // FFT计算
    fftw_complex *in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * fftSize);
    fftw_complex *out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * fftSize);
    fftw_plan p = fftw_plan_dft_1d(fftSize, in, out, FFTW_FORWARD, FFTW_ESTIMATE);

    // 填充数据
    for (int i=0; i<fftSize; ++i) {
        in[i][0] = (i < N) ? coeffs[i] : 0.0;
        in[i][1] = 0.0;
    }
    fftw_execute(p);

    // 计算幅度谱
    QVector<float> freq(fftSize/2);
    QVector<float> mag(fftSize/2);
    QVector<float> outNorm(fftSize/2);

    //归一化处理
    for(int i = 0; i < fftSize/2; ++i){
        outNorm[i] = static_cast<float>(sqrt(out[i][0]*out[i][0] + out[i][1]*out[i][1]));
    }
    float max_ = maxVec(outNorm);
    for (int i=0; i<fftSize/2; ++i) {
        freq[i] = i * static_cast<float>(_fSample) / fftSize;
        mag[i] = static_cast<float>(20 * log10(outNorm[i]/max_));
    }
    //只绘制一半的曲线
    QVector<float> freqHalf(fftSize/2/2);
    QVector<float> magHalf(fftSize/2/2);

    for (int i=0; i<fftSize/2/2; ++i) {
        freqHalf[i] = freq[i];
        magHalf[i] = mag[i];
    }
    freqHalf[fftSize/2/2-1] = _fSample/2/2;
    // 绘制
    MyFigure* curveFigure = new MyFigure(this);
    curveFigure->plotCurve(freqHalf, magHalf, Qt::blue, 2, "窗函数频谱曲线");
    curveFigure->setMyXLabel("MHz");
    curveFigure->setMyYLabel("Amplitude(a.u)");
    curveFigure->setMyMapTitle("窗函数频谱图");
    curveFigure->setMyWindowTitle("窗函数频谱图");
    curveFigure->show();

    // 清理资源
    fftw_destroy_plan(p);
    fftw_free(in); fftw_free(out);
}

