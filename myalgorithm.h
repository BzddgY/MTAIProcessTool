#ifndef MYALGORITHM_H
#define MYALGORITHM_H

#include <QObject>
#include<QVector>
#include "fftw-3.3.5-dll64/fftw3.h"
#include<MyMathCaculator.h>
//该类用来实现所有用于计算QVector数据的算法
class MyAlgorithm : public QObject
{
    Q_OBJECT
public:
    explicit MyAlgorithm(QObject *parent = nullptr);
    static void addVectors(QVector<float>& vec1, const QVector<float>& vec2);
    static void FreDomainCurve_1d(QVector<float>& fftResult, QVector<float>& fftResult_xVec, QVector<float>& origin, float& fs);
    static QVector<float> normalizeOne(const QVector<float>& origVec);

signals:
};

#endif // MYALGORITHM_H
