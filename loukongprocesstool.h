#ifndef LOUKONGPROCESSTOOL_H
#define LOUKONGPROCESSTOOL_H

#include <QWidget>

namespace Ui {
class LouKongProcessTool;
}

class LouKongProcessTool : public QWidget
{
    Q_OBJECT

public:
    explicit LouKongProcessTool(QWidget *parent = nullptr);
    ~LouKongProcessTool();
    void initialPara();
    void initialLouKongProcessSetting();
    void runLouKongProcess(QVector<float>& inData);

public slots:
    void slot_setNSens(const int& tmp);
    void slot_setNTimes(const int& tmp);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_confirmCurrentSetting_clicked();

    void on_pushButton_turnToDefaultSetting_clicked();

private:
    Ui::LouKongProcessTool *ui;
    int _NSens;
    QVector<int> _shiftSteps;//移位多少
    QVector<bool> _isShiftRight;//是否右移
    QVector<float> _compensateValue;//补偿倍数
    int _currentSensInd;//当前的通道索引
    int _NTimes;//总采样点数
};

#endif // LOUKONGPROCESSTOOL_H
