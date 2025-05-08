#ifndef MYMATHCACULATOR_H
#define MYMATHCACULATOR_H
#include<const.h>

float minVec(const QVector<float> &vec, const int vecIndex = 0, const int Nx = 0, const int Ny = 0,const VectorType vecType = VectorType::Vector);
float maxVec(const QVector<float> &vec, const int vecIndex = 0, const int Nx = 0, const int Ny = 0,const VectorType vecType = VectorType::Vector);

bool floatToDouble(QVector<double>& result, const QVector<float>& orig);


#endif // MYMATHCACULATOR_H
