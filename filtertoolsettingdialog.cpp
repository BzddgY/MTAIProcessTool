#include "filtertoolsettingdialog.h"
#include "ui_filtertoolsettingdialog.h"

FilterToolSettingDialog::FilterToolSettingDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FilterToolSettingDialog)
{
    ui->setupUi(this);
}

FilterToolSettingDialog::~FilterToolSettingDialog()
{
    delete ui;
}

void FilterToolSettingDialog::addFilterTool(QWidget *tmp)
{
    ui->gridLayout->addWidget(tmp);
}
