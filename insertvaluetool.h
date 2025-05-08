#ifndef INSERTVALUETOOL_H
#define INSERTVALUETOOL_H

#include <QWidget>
#include<const.h>

namespace Ui {
class InsertValueTool;
}

class InsertValueTool : public QWidget
{
    Q_OBJECT

public:
    explicit InsertValueTool(QWidget *parent = nullptr);
    ~InsertValueTool();
    void runInsertValue(QVector<float>& inData, const int & NSens_, const int & NTimes_, const InsertValueType& indertType_, const int & Fs_ = 40, const float& R_ = 65);

private:
    Ui::InsertValueTool *ui;
};

#endif // INSERTVALUETOOL_H
