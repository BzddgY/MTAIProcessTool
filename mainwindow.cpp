#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMenu>
#include<QAction>
#include<helpstatementdialog.h>
#include<QVBoxLayout>
#include<mainwindowtabwidget.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //创建菜单
    QMenu * menu_help = menuBar()->addMenu(tr("帮助(&H)"));

    //创建项目动作
    QAction* act_statement = new QAction(tr("使用说明"),this);//QIcon(":/icon/createpro.png"),
    act_statement->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_H));//设置快捷键
    menu_help->addAction(act_statement);

    //连接信号与槽
    connect(act_statement, &QAction::triggered, this, &MainWindow::slot_statement);

    // 主布局
    QWidget *centralWidget = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    // 主功能区域（其他组件）
    MainWindowTabWidget *mainTab = new MainWindowTabWidget;
    mainTab->initialPara();//初始化参数设置
    mainLayout->addWidget(mainTab);


    // 日志区域设置
    _logViewer = new QPlainTextEdit;
    _logViewer->setReadOnly(true); // 只读模式
    _logViewer->setMaximumHeight(150); // 限制高度
    mainLayout->addWidget(_logViewer);
    setCentralWidget(centralWidget);
    // 创建菜单和动作
    _logContextMenu = new QMenu(this);
    QAction* clearLogAction = new QAction("清空日志", this);
    // 连接动作信号
    connect(clearLogAction, &QAction::triggered, this, &MainWindow::clearLogs);
    // 将动作添加到菜单
    _logContextMenu->addAction(clearLogAction);
    // 启用日志区域的上下文菜单策略
    _logViewer->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(_logViewer, &QPlainTextEdit::customContextMenuRequested,
            this, &MainWindow::showLogContextMenu);
    //连接外部信号与主函数槽
        connect(mainTab, &MainWindowTabWidget::sigAppendLog, this, &MainWindow::appendLog);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//更新日志
void MainWindow::appendLog(const QString &message)
{
    QString timestamp = QDateTime::currentDateTime().toString("[hh:mm:ss] ");
    _logViewer->appendPlainText(timestamp + message); // 带时间戳的日志
}

//打开帮助说明窗口
void MainWindow::slot_statement()
{
    helpStatementDialog*   helpStatementDialog_ = new helpStatementDialog();
    helpStatementDialog_->setWindowTitle("帮助说明");
    emit sigAppendLog("浏览帮助说明");
    helpStatementDialog_->show();
    helpStatementDialog_->exec();
}

void MainWindow::showLogContextMenu(const QPoint &pos) {
    // 转换坐标并显示菜单
    QPoint globalPos = _logViewer->viewport()->mapToGlobal(pos);
    _logContextMenu->exec(globalPos);
}

void MainWindow::clearLogs() {
    // 可选：添加确认对话框
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "确认", "确定要清空所有日志吗？",
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::Yes) {
        _logViewer->clear();  // 清空内容
        appendLog("日志已手动清空");  // 记录操作日志
    }
}
