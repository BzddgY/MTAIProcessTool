#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>
#include<QDateTime>
#include<QString>
#include<QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    // 主窗口类中添加函数
    void appendLog(const QString &message);
    void showLogContextMenu(const QPoint &pos);

private:
    Ui::MainWindow *ui;
    QPlainTextEdit *_logViewer; // 日志显示组件
    QMenu* _logContextMenu;
private slots:
    void slot_statement();
    void clearLogs();
signals:
    void sigAppendLog(const QString& message);
};
#endif // MAINWINDOW_H
