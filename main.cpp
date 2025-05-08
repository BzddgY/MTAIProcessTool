#include "mainwindow.h"

#include <QApplication>
#include<const.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("MTAIProcessTool");
    w.setWindowIcon(QIcon(":/icon/MTAI.ico"));
    w.setMinimumHeight(MAINWINDOW_HEIGHT); w.setMinimumWidth(MAINWINDOW_WIDTH);
    w.show();
    return a.exec();
}
