#include "matrixplot.h"
#include "colorbar.h"
#include <QHBoxLayout>
#include <QImage>
#include <QPainter>
#include <QPen>
#include <QGraphicsTextItem>
#include <algorithm>

MatrixPlot::MatrixPlot(const QVector<QVector<float>>& matrix, QWidget* parent)
    : QDialog(parent), m_scene(new QGraphicsScene(this)),
    m_view(new QGraphicsView(m_scene)), m_colorbar(nullptr) {

    // 窗口初始化
    setWindowTitle("Figure");
    resize(800, 600);

    // 查找极值
    findMinMax(matrix);

    // 创建布局
    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(m_view, 1);

    // 添加色阶条
    m_colorbar = new Colorbar(m_min, m_max);
    mainLayout->addWidget(m_colorbar);

    // 绘制内容
    drawMatrix(matrix);
    drawAxes();
}

void MatrixPlot::findMinMax(const QVector<QVector<float>>& matrix) {
    m_min = std::numeric_limits<float>::max();
    m_max = std::numeric_limits<float>::min();
    for (const auto& row : matrix) {
        auto [minIt, maxIt] = std::minmax_element(row.begin(), row.end());
        if (*minIt < m_min) m_min = *minIt;
        if (*maxIt > m_max) m_max = *maxIt;
    }
}

void MatrixPlot::drawMatrix(const QVector<QVector<float>>& matrix) {
    if (matrix.empty()) return;

    const int rows = matrix.size();
    const int cols = matrix[0].size();
    QImage image(cols, rows, QImage::Format_ARGB32);

    // 生成颜色映射
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            const float normalized = (matrix[y][x] - m_min) / (m_max - m_min);
            const int hue = 240 * (1 - normalized);
            image.setPixelColor(x, y, QColor::fromHsv(hue, 255, 255));
        }
    }

    m_scene->addPixmap(QPixmap::fromImage(image));
}

void MatrixPlot::drawAxes() {
    // 绘制坐标轴
    QPen axisPen(Qt::black, 2);
    const qreal width = m_scene->width();
    const qreal height = m_scene->height();

    // X轴
    m_scene->addLine(0, height-1, width, height-1, axisPen);
    // Y轴
    m_scene->addLine(0, 0, 0, height, axisPen);

    // 添加标签
    QGraphicsTextItem* xLabel = m_scene->addText("X Axis");
    xLabel->setPos(width/2 - 30, height - 20);

    QGraphicsTextItem* yLabel = m_scene->addText("Y Axis");
    yLabel->setRotation(-90);
    yLabel->setPos(-40, height/2 - 40);
}
