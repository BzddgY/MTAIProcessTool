#include "exppostprocesstool.h"
#include "ui_exppostprocesstool.h"

ExpPostProcessTool::ExpPostProcessTool(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ExpPostProcessTool)
{
    ui->setupUi(this);
}

ExpPostProcessTool::~ExpPostProcessTool()
{
    delete ui;
}
