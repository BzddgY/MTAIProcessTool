#include "dragresizewgt.h"
#include<ui_dragresizewgt.h>
#include <QDebug>
#include "Windows.h"
#include <QMouseEvent>
#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#define min(a,b) ((a)<(b)? (a) :(b))
#define max(a,b) ((a)>(b)? (a) :(b))

DragResizeWgt::DragResizeWgt(QWidget *parent) :
    QWidget(parent),ui(new Ui::DragResizeWgt),
    resizeDir(nodir), m_resizing(false),m_repositioning(false),
    m_resizeableTop(true), m_resizeableBottom(true),
    m_resizeableRight(true), m_resizeableLeft(true)
{
    ui->setupUi(this);
    this->setObjectName("DragResizeWgt");

    //注意：一定要设置一个最小的宽高奥，要不会被拖到看不见，默认最小（0，0）
    setMinimumSize(100, 100);

    //一定一定要有这句话奥，这是能捕捉到这个窗口鼠标事件的关键，还有一点需要特别注意，如果这个窗口上会叠加其他的widget或者控件，对应的子UI也需要调用setMouseTracking这个函数
    this->setMouseTracking(true);

    //鼠标事件过滤器，来处理父窗口与子窗口的事件关系，不能互相干扰，后续会十分用得到
    setAttribute(Qt::WA_NoMousePropagation);
    installEventFilter(this);
    // QVBoxLayout *layout = new QVBoxLayout(this);
    // QLabel *label = new QLabel("Resizable and Draggable Widget", this);
    // layout->addWidget(label);

    edgeMargin = 4;        //设置检测边缘为4
    resizeDir = nodir;   //初始化检测方向为无

    setEdgeBeReSized(false,true,true,false);
    // setEdgeBeReSized(true,true,true,true);
    setLayout(new QHBoxLayout);
}

DragResizeWgt::~DragResizeWgt() = default;

void DragResizeWgt::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)  //每当按下鼠标左键就记录一下位置
    {
        dragPosition = event->globalPos() - frameGeometry().topLeft();  //获得鼠标按键位置相对窗口左上面的位置
        m_startCursor = event->globalPos();

        m_nLeftOff = frameGeometry().left();
        m_nRightOff = frameGeometry().right() + 1;
        m_nTopOff = frameGeometry().top();
        m_nBottomOff = frameGeometry().bottom() + 1;
        qDebug() << "mousePressEvent" << dragPosition << m_startCursor << m_nLeftOff << m_nRightOff << m_nTopOff << m_nBottomOff;
    }
}

void DragResizeWgt::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)//如果左键是按下的
    {
        if(resizeDir == nodir)//鼠标未放置在边缘处，进行窗口整体拖动处理
        {
            if(m_repositioning)
            {
                move(event->globalPos() - dragPosition);
            }
        }
        else//拖拽边缘，根据拖拽方向进行大小调整
        {

            int ptop,pbottom,pleft,pright;
            ptop = m_nTopOff;
            pbottom = m_nBottomOff;
            pleft = m_nLeftOff;
            pright = m_nRightOff;
            //这里获取父窗口的大小，如果没有则获取全局可用的屏幕大小
            QRect parentRect = parentWidget() ? parentWidget()->rect() : QApplication::primaryScreen()->availableGeometry();
            if(resizeDir & top)//拖拽顶部上下变化
            {
                //计算根据当前鼠标位置与拖拽偏移量计算当前top的位置
                ptop = m_nTopOff-(m_startCursor.ry()- event->globalY());
                qDebug() << "#########top position" << ptop << m_nTopOff << m_startCursor.ry() << event->globalY();
                if(ptop < 0)
                {
                    ptop = parentRect.height() - this->maximumHeight();
                }
                else{
                    if(this->height() <= minimumHeight())//进行极端高度最小的处理
                    {
                        ptop = min(m_nBottomOff-minimumHeight(),ptop);
                        qDebug() << "this->height() >= minimumHeight()" << ptop  << m_nBottomOff << minimumHeight();
                    }
                    else if(this->height() >= maximumHeight())//进行极端高度最大的处理
                    {
                        ptop = max(m_nBottomOff-maximumHeight(),ptop);
                        qDebug() << "this->height() >= maximumHeight()" << ptop << m_nBottomOff << maximumHeight();
                    }
                }
            }
            else if(resizeDir & bottom)//拖拽底部上下变化
            {
                //计算根据当前鼠标位置与拖拽偏移量计算当前bottom的位置
                pbottom = m_nBottomOff +(event->globalY()-m_startCursor.ry());
                if(pbottom > parentRect.bottom())
                {
                    pbottom = this->maximumHeight();
                }else{
                    if(this->height()<minimumHeight())//进行极端高度最小的处理
                    {
                        pbottom = m_nTopOff+minimumHeight();
                    }
                    else if(this->height()>maximumHeight())//进行极端高度最大的处理
                    {
                        pbottom = m_nTopOff+maximumHeight();
                    }
                }
            }

            if(resizeDir & left)//拖拽左侧左右变化
            {
                //计算根据当前鼠标位置与拖拽偏移量计算当前left的位置
                pleft = m_nLeftOff-(m_startCursor.rx() - event->globalX());
                if(pleft < 0)
                {
                    pleft = 0;
                }else{
                    if(this->width()<= minimumWidth())//进行极端宽度最小的处理
                    {
                        pleft = min(pleft,m_nRightOff- minimumWidth());
                    }
                    else if(this->width() >= maximumWidth())//进行极端宽度最大的处理
                    {
                        pleft = max(m_nRightOff- maximumWidth(),pleft);
                    }
                }
            }
            else if(resizeDir & right)//拖拽右侧左右变化
            {
                //计算根据当前鼠标位置与拖拽偏移量计算当前right的位置
                pright = m_nRightOff + (event->globalX()-m_startCursor.rx());
                if(pright > parentRect.right())
                {
                    pright = parentRect.right();
                }
                if(this->width()<minimumWidth())//进行极端宽度最小的处理
                {
                    pright = m_nLeftOff+minimumWidth();
                }
                else if(this->width()> this->maximumWidth())//进行极端宽度最大的处理
                {
                    pright = m_nLeftOff + this->maximumWidth();
                }
            }
            setGeometry(pleft,ptop,pright-pleft,pbottom-ptop);
            emit sizeChange();
        }

    }
    else checkEdge();
}

void DragResizeWgt::mouseReleaseEvent(QMouseEvent * event)
{
    // Q_UNUSED(event);
    if(resizeDir != nodir)//还原鼠标样式
    {
        checkEdge();
        emit sizeChange();
    }
}

void DragResizeWgt::paintEvent(QPaintEvent *event)
{
    // QPainter painter(this);
    // painter.fillRect(rect(), Qt::white);
    QWidget::paintEvent(event);
}

void DragResizeWgt::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    // emit sizeChange();
}

bool DragResizeWgt::eventFilter(QObject *watch, QEvent *event)
{
    //一定要加这一句，不然父窗口的event事件也会出发窗口大小的改变信号
    if(watch == parentWidget() && event->type() == QEvent::MouseButtonRelease)
    {
        event->ignore();
        return true;
    }
    // if(watch == parentWidget() && event->type() == QEvent::Resize)
    // {
    //     event->ignore();
    //     return true;
    // }
    return QWidget::eventFilter(watch, event);
}

void DragResizeWgt::setEdgeBeReSized(const bool &resizeableTop, const bool &resizeableBottom, const bool &resizeableRight, const bool &resizeableLeft)
{
    m_resizeableTop = resizeableTop;
    m_resizeableBottom =  resizeableBottom;
    m_resizeableRight = resizeableRight;
    m_resizeableLeft = resizeableLeft;
}

void DragResizeWgt::setIsRepositioning(const bool &reposition)
{
    m_repositioning = reposition;
}

void DragResizeWgt::checkEdge()
{
    QPoint pos = this->mapFromGlobal(QCursor::pos());//开始拖拽时点击控件的什么位置

    int diffLeft = pos.rx();
    int diffRight = this->width() - diffLeft;
    int diffTop = pos.ry();
    int diffBottom = this->height() - diffTop;
    QCursor tempCursor;                                    //获得当前鼠标样式，注意:只能获得当前鼠标样式然后再重新设置鼠标样式
    tempCursor = cursor();                                 //因为获得的不是鼠标指针，所以不能这样用:cursor().setXXXXX

    // qDebug() << "diffLeft" << diffLeft << "diffRight" << diffRight << "diffTop" << diffTop << "diffBottom" << diffBottom ;
    if(diffTop < edgeMargin && m_resizeableTop)
    {                              //根据 边缘距离 分类改变尺寸的方向
        if(diffLeft < edgeMargin  && m_resizeableTop && m_resizeableLeft)
        {
            resizeDir = topLeft;
            tempCursor.setShape(Qt::SizeFDiagCursor);
        }
        else if(diffRight < edgeMargin && m_resizeableTop && m_resizeableRight)
        {
            resizeDir = topRight;
            tempCursor.setShape(Qt::SizeBDiagCursor);
        }
        else
        {
            resizeDir = top;
            tempCursor.setShape(Qt::SizeVerCursor);
        }
    }
    else if(diffBottom < edgeMargin && m_resizeableBottom)
    {
        if(diffLeft < edgeMargin && m_resizeableBottom && m_resizeableLeft)
        {
            resizeDir = bottomLeft;
            tempCursor.setShape(Qt::SizeBDiagCursor);
        }
        else if(diffRight < edgeMargin && m_resizeableBottom && m_resizeableRight)
        {
            resizeDir = bottomRight;
            tempCursor.setShape(Qt::SizeFDiagCursor);
        }
        else
        {
            resizeDir = bottom;
            tempCursor.setShape(Qt::SizeVerCursor);
        }
    }
    else if(diffLeft < edgeMargin && m_resizeableLeft)
    {
        resizeDir = left;
        tempCursor.setShape(Qt::SizeHorCursor);
    }
    else if(diffRight < edgeMargin && m_resizeableRight)
    {
        resizeDir = right;
        tempCursor.setShape(Qt::SizeHorCursor);
    }
    else
    {
        resizeDir = nodir;
        tempCursor.setShape(Qt::ArrowCursor);
    }

    setCursor(tempCursor);
}


