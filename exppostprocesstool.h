#ifndef EXPPOSTPROCESSTOOL_H
#define EXPPOSTPROCESSTOOL_H

#include <QWidget>

namespace Ui {
class ExpPostProcessTool;
}

class ExpPostProcessTool : public QWidget
{
    Q_OBJECT

public:
    explicit ExpPostProcessTool(QWidget *parent = nullptr);
    ~ExpPostProcessTool();

private:
    Ui::ExpPostProcessTool *ui;
};

#endif // EXPPOSTPROCESSTOOL_H
