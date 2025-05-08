#ifndef EXPPROCESSWINDOW_H
#define EXPPROCESSWINDOW_H

#include <QWidget>

namespace Ui {
class ExpProcessWindow;
}

class ExpProcessWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ExpProcessWindow(QWidget *parent = nullptr);
    ~ExpProcessWindow();

private:
    Ui::ExpProcessWindow *ui;
};

#endif // EXPPROCESSWINDOW_H
