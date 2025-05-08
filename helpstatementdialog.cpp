#include "helpstatementdialog.h"
#include "ui_helpstatementdialog.h"

helpStatementDialog::helpStatementDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::helpStatementDialog)
{
    ui->setupUi(this);
}

helpStatementDialog::~helpStatementDialog()
{
    delete ui;
}
