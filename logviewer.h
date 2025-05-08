#ifndef LOGVIEWER_H
#define LOGVIEWER_H

#include <QWidget>

namespace Ui {
class logViewer;
}

class logViewer : public QWidget
{
    Q_OBJECT

public:
    explicit logViewer(QWidget *parent = nullptr);
    ~logViewer();

private:
    Ui::logViewer *ui;
};

#endif // LOGVIEWER_H
