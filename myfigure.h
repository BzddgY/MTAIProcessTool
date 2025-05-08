#ifndef MYFIGURE_H
#define MYFIGURE_H

#include <QMainWindow>
#include "qcustomplot.h"

#include<const.h>
#include<MyMathCaculator.h>
#include<QFont>

namespace Ui {
class MyFigure;
}

class MyFigure : public QMainWindow
{
    Q_OBJECT

private slots:
    // void onSaveClicked();
    // void onGradientChanged(int index);
    // void onRangeChanged();
    void on_toolButton_confirmTitle_clicked();
    void on_lineEdit_title_returnPressed();
    bool on_saveFigButton_clicked();
    void on_toolButton_confirmColorbar_clicked();
    void on_lineEdit_xLabel_returnPressed();
    void on_lineEdit_yLabel_returnPressed();

public:
    explicit MyFigure(QWidget *parent = nullptr);
    ~MyFigure();
    // 热力图接口
    void plotHeatMap(const QVector<float> &data,
                     const QVector<float> &xVec,
                     const QVector<float> &yVec,
                     const QString &title = "");

    // 曲线图接口
    QCPGraph* plotCurve(const QVector<float> &xData,
                        const QVector<float> &yData,
                        const QColor &color = Qt::blue,
                        int lineWidth = 1, const QString& curveName = "");

    QCPGraph* addCurve(const QVector<float> &xData,
                  const QVector<float> &yData,
                  const QColor &color = Qt::blue,
                  int lineWidth = 1, const QString& curveName = "");

    // 参数更新方法
    void updateColorGradient(QCPColorGradient::GradientPreset preset);
    // void updateDynamicRange(double min, double max);
    // void updateBrightness(int value);
    void updateHW();

    //外面参数更改接口
    bool setMyMapTitle(const QString title);
    bool setMyWindowTitle(const QString title);
    bool setMyColorBar(const ColorbarType colorbarType);
    bool setMyXLabel(const QString xLabel_);
    bool setMyYLabel(const QString yLabel_);
    void setMyAxisImage();//设置自适应图像伸缩

    void updateLineStyle(QCPScatterStyle::ScatterShape& inputLineStyle);
    void updateCurvesLineStyle(QCPScatterStyle::ScatterShape& inputLineStyle);

    void setYRange(QCPRange yRange);
    void setXRange(QCPRange xRange);

protected:
    void resizeEvent(QResizeEvent *event);

private:
    Ui::MyFigure *ui;
    QCPColorMap *colorMap;
    QCPColorGradient currentGradient;//设置色阶
    QList<QCPGraph*> curves;//所有curves
    bool isHaveTitle;
    QCPTextElement* m_title;//设置标题
    double HWRatio;//高宽比，保持一致
    int MaxCustomPlotHeight, MaxCustomPlotWidth;
    int availableWidth,availableHeight;
    QCPColorGradient parulaGradient;
    bool isSetAxisImage;//是否设置自适应图像伸缩
    //xRange
    QCPRange _xRange;
    QCPRange _yRange;

    //LineStyle
    QCPScatterStyle::ScatterShape _currentLineStyle;//当前添加曲线时设置曲线样式
    QCPScatterStyle::ScatterShape _selectedLineStyle;//当前添加曲线时设置曲线样式
    int _scatterSkip;//默认共设置一百个点



    bool isSetParulaGradient;
    void set_parulaGradient();

    // void setupConnections();
    // void initColorGradients();
private slots:
    void checkXAxisRange(const QCPRange &newRange);
    void checkYAxisRange(const QCPRange &newRange);

    void on_toolButton_confirmXLabel_clicked();
    void on_toolButton_confirmYLabel_clicked();
    void on_toolButton_confirmLineStyle_clicked();
    void on_toolButton_confirmWordType_clicked();
    void on_toolButton_confirmWordSize_clicked();
};

#endif // MYFIGURE_H
