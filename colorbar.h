#ifndef COLORBAR_H
#define COLORBAR_H

#include<QWidget>
#include <QLinearGradient>

class Colorbar : public QWidget {
    Q_OBJECT
public:
    explicit Colorbar(float min, float max, QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    float m_min;
    float m_max;
    QLinearGradient m_gradient;
};

#endif // COLORBAR_H
