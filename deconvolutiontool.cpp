#include "deconvolutiontool.h"
#include "ui_deconvolutiontool.h"

DeconvolutionTool::DeconvolutionTool(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeconvolutionTool)
{
    ui->setupUi(this);
    ui->comboBox_loadType->addItems({"通道平均导入EIR","直接导入EIR"});
}

DeconvolutionTool::~DeconvolutionTool()
{
    delete ui;
}
