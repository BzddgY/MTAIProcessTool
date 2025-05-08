#ifndef DECONVOLUTIONTOOL_H
#define DECONVOLUTIONTOOL_H

#include <QWidget>

namespace Ui {
class DeconvolutionTool;
}

class DeconvolutionTool : public QWidget
{
    Q_OBJECT

public:
    explicit DeconvolutionTool(QWidget *parent = nullptr);
    ~DeconvolutionTool();

private:
    Ui::DeconvolutionTool *ui;
};

#endif // DECONVOLUTIONTOOL_H
