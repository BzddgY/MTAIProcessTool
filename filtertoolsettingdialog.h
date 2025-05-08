#ifndef FILTERTOOLSETTINGDIALOG_H
#define FILTERTOOLSETTINGDIALOG_H

#include <QDialog>

namespace Ui {
class FilterToolSettingDialog;
}

class FilterToolSettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FilterToolSettingDialog(QWidget *parent = nullptr);
    ~FilterToolSettingDialog();
    void addFilterTool(QWidget* tmp);

private:
    Ui::FilterToolSettingDialog *ui;
};

#endif // FILTERTOOLSETTINGDIALOG_H
