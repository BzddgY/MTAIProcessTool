#include "expprocesswindow.h"
#include "ui_expprocesswindow.h"

ExpProcessWindow::ExpProcessWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ExpProcessWindow)
{
    ui->setupUi(this);
}

ExpProcessWindow::~ExpProcessWindow()
{
    delete ui;
}
