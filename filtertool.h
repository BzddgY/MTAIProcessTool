#ifndef FILTERTOOL_H
#define FILTERTOOL_H

#include <QWidget>
#include<const.h>
#include<QTMath>
#include<fftw-3.3.5-dll64/fftw3.h>
#include<myfigure.h>
namespace Ui {
class FilterTool;
}

class FilterTool : public QWidget
{
    Q_OBJECT

public:
    explicit FilterTool(QWidget *parent = nullptr);
    ~FilterTool();
    void filter_2d(QVector<float>& originSignal_, const FilterType& filterType_, const int& Nsens, const int& Ntime);
    // 计算零阶修正贝塞尔函数
    double modifiedBessel0(double x) {
        double sum = 0.0, x2 = x*x/4.0;
        double term = 1.0;
        for(int k=0; k<20; ++k) {
            sum += term;
            term *= x2 / ((k+1)*(k+1));
        }
        return sum;
    }

private slots:
    void on_comboBox_preShowFilterType_currentIndexChanged(int index);

    void on_spinBox_M_editingFinished();

    void on_spinBox_Fs_editingFinished();

    void on_doubleSpinBox_beta_editingFinished();

    void on_doubleSpinBox_FPass_editingFinished();

    void on_doubleSpinBox_FStop_editingFinished();

    void on_pushButton_adjustM_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_preShowFilterWindow_clicked();

private:
    Ui::FilterTool *ui;
    double _M;//滤波器阶数
    FilterType _filterType;
    double _fPass, _fStop, _beta, _fSample;

    void calculateM();
    QVector<double> calculateWn(const FilterType& filterType_);

};

#endif // FILTERTOOL_H
