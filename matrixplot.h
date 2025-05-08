#ifndef MATRIXPLOT_H
#define MATRIXPLOT_H

#include <QDialog>
#include <QVector>
#include <QGraphicsView>

class QGraphicsScene;
class Colorbar;

class MatrixPlot : public QDialog {
    Q_OBJECT
public:
    explicit MatrixPlot(const QVector<QVector<float>>& matrix,
                        QWidget* parent = nullptr);

private:
    void initUI();
    void drawMatrix(const QVector<QVector<float>>& matrix);
    void drawAxes();
    void findMinMax(const QVector<QVector<float>>& matrix);

    QGraphicsScene* m_scene;
    QGraphicsView* m_view;
    Colorbar* m_colorbar;
    float m_min;
    float m_max;
};

#endif // MATRIXPLOT_H
