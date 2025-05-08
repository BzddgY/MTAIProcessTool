#include<MyMathCaculator.h>

float minVec(const QVector<float> &vec, const int vecIndex, const int Nx, const int Ny, const VectorType vecType)
{
    float minValue(0.0f);
    int N;
    switch(vecType){
    case VectorType::Vector://一维向量
        N = vec.size();
        if(N>=1){
            minValue= vec[0];
        }else{
            return 0.0;
        }
        for(int i = 1;i<N;i++){
            if(vec[i] < minValue){
                minValue = vec[i];
            }
        }
        break;
    case VectorType::MatrixColumn://矩阵中的列向量
        N = Ny;
        if(N>=1){
            minValue= vec[0+vecIndex*Ny];
        }else{
            return 0.0f;
        }
        for(int i = 1;i<N;i++){
            if(vec[i+vecIndex*Ny] < minValue){
                minValue = vec[i+vecIndex*Ny];
            }
        }
        break;
    case VectorType::MatrixRow://矩阵中的行向量
        N = Nx;
        if(N>=1){
            minValue= vec[vecIndex+0*Ny];
        }else{
            return 0.0f;
        }
        for(int i = 1;i<N;i++){
            if(vec[vecIndex+i*Ny] < minValue){
                minValue = vec[vecIndex+i*Ny];
            }
        }
        break;
    default:
        break;
    }

    return minValue;
}

float maxVec(const QVector<float> &vec, const int vecIndex, const int Nx, const int Ny, const VectorType vecType)
{
    float maxValue(0.0f);
    int N;
    switch(vecType){
    case VectorType::Vector://一维向量
        N = vec.size();
        if(N>=1){
            maxValue= vec[0];
        }else{
            return 0.0;
        }
        for(int i = 1;i<N;i++){
            if(vec[i] > maxValue){
                maxValue = vec[i];
            }
        }
        break;
    case VectorType::MatrixColumn://矩阵中的列向量
        N = Ny;
        if(N>=1){
            maxValue= vec[0+vecIndex*Ny];
        }else{
            return 0.0f;
        }
        for(int i = 1;i<N;i++){
            if(vec[i+vecIndex*Ny] > maxValue){
                maxValue = vec[i+vecIndex*Ny];
            }
        }
        break;
    case VectorType::MatrixRow://矩阵中的行向量
        N = Nx;
        if(N>=1){
            maxValue= vec[vecIndex+0*Ny];
        }else{
            return 0.0f;
        }
        for(int i = 1;i<N;i++){
            if(vec[vecIndex+i*Ny] > maxValue){
                maxValue = vec[vecIndex+i*Ny];
            }
        }
        break;
    default:
        break;
    }

    return maxValue;

}

//将QVector<float>转化为QVector<double>
bool floatToDouble(QVector<double>& result, const QVector<float>& orig){
    if(orig.size() != result.size()){
        return false;
    }
    for(int i = 0; i < orig.size(); ++i){
        result[i] = static_cast<double>(orig[i]);
    }
    return true;
}
