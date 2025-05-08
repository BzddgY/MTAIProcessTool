#include "logviewer.h"
#include "ui_logviewer.h"

logViewer::logViewer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::logViewer)
{
    ui->setupUi(this);
}

logViewer::~logViewer()
{
    delete ui;
}
