#include "colorbar.h"

#include <QPainter>
#include <QPen>

Colorbar::Colorbar(float min, float max, QWidget* parent)
    : QWidget(parent), m_min(min), m_max(max) {
    setFixedWidth(40);
    m_gradient = QLinearGradient(0, 0, 0, height());
    m_gradient.setColorAt(0, Qt::red);
    m_gradient.setColorAt(1, Qt::blue);
}

void Colorbar::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.fillRect(rect(), m_gradient);

    // 绘制刻度标签
    painter.setPen(Qt::black);
    painter.drawText(QRect(5, 5, 35, 20),
                     Qt::AlignRight | Qt::AlignTop,
                     QString::number(m_max));
    painter.drawText(QRect(5, height()-25, 35, 20),
                     Qt::AlignRight | Qt::AlignBottom,
                     QString::number(m_min));
}
