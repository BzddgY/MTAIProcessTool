
#ifndef DRAGRESIZEWGT_H
#define DRAGRESIZEWGT_H

#include <QWidget>
#include <QMouseEvent>
#include <QPoint>
#include <QScreen>
#include <QPainter>
#include <QResizeEvent>
#include <QEvent>
namespace Ui {
class DragResizeWgt;
}

class DragResizeWgt : public QWidget
{
    Q_OBJECT
    enum DIRECTION{
        nodir,
        top = 0x01,
        bottom = 0x02,
        left = 0x04,
        right = 0x08,
        topLeft = 0x01 | 0x04,
        topRight = 0x01 | 0x08,
        bottomLeft = 0x02 | 0x04,
        bottomRight = 0x02 | 0x08};
public:
    explicit DragResizeWgt(QWidget *parent = nullptr);
    ~DragResizeWgt();
signals:
    void sizeChange();
public:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    bool eventFilter(QObject *watch, QEvent *event);
    void setEdgeBeReSized(const bool& resizeableTop, const bool& resizeableBottom, const bool& resizeableRight, const bool& resizeableLeft);
    void setIsRepositioning(const bool& reposition);
private:
    void checkEdge();
private:
    Ui::DragResizeWgt *ui;

    QPoint m_startCursor;

    int m_nLeftOff = 0;//鼠标开始拖拽时子窗口左边相对父窗口左边的距离
    int m_nRightOff = 0;//鼠标开始拖拽时子窗口右边相对父窗口左边的距离
    int m_nTopOff = 0;//鼠标开始拖拽时子窗口上边相对父窗口上边的距离
    int m_nBottomOff = 0;//鼠标开始拖拽时子窗口下边相对父窗口上边的距离

    QPoint dragPosition;   //鼠标拖动的位置
    int    edgeMargin = 4;     //鼠标检测的边缘距离
    DIRECTION resizeDir; //更改尺寸的方向

    bool m_resizing;
    bool m_repositioning;
    //帮助判断是否需要激活边框可变化大小
    bool m_resizeableTop;
    bool m_resizeableBottom;
    bool m_resizeableRight;
    bool m_resizeableLeft;
};

#endif // DRAGRESIZEWGT_H
