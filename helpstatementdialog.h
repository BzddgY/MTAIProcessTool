#ifndef HELPSTATEMENTDIALOG_H
#define HELPSTATEMENTDIALOG_H

#include <QDialog>

namespace Ui {
class helpStatementDialog;
}

class helpStatementDialog : public QDialog
{
    Q_OBJECT

public:
    explicit helpStatementDialog(QWidget *parent = nullptr);
    ~helpStatementDialog();

private:
    Ui::helpStatementDialog *ui;
};

#endif // HELPSTATEMENTDIALOG_H
