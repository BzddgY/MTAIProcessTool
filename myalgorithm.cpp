#include "myalgorithm.h"

MyAlgorithm::MyAlgorithm(QObject *parent)
    : QObject{parent}
{}

void MyAlgorithm::addVectors(QVector<float> &vec1, const QVector<float> &vec2)
{
    if(vec1.size() != vec2.size()){
        return;
    }
    for(int i = 0; i < vec1.size(); i++){
        vec1[i]+=vec2[i];
    }
}

void MyAlgorithm::FreDomainCurve_1d(QVector<float> &fftResult, QVector<float> &fftResult_xVec, QVector<float> &origin, float &fs)
{
    double *in;
    fftw_complex* outc;
    fftw_plan p;
    int N = origin.size(); // 变换的长度
    // 分配输入输出数组
    in = (double*) fftw_malloc(sizeof(double) * N);
    outc = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);

    // 准备输入数据
    for (int i = 0; i < N; ++i) {
        in[i] = static_cast<double>(origin[i]); // 实部
    }
    // 创建变换计划
    p = fftw_plan_dft_r2c_1d(N, in, outc, FFTW_ESTIMATE);
    // 执行变换
    fftw_execute(p);
    fftResult.resize(N/2+1);
    // 处理变换结果
    for (int i = 0; i < N/2+1; ++i) {
        // 进行后续处理
        fftResult[i] = static_cast<float>(sqrt(outc[i][0]*outc[i][0] + outc[i][1]*outc[i][1])/N);
        if(i >0 && i < N/2){
            fftResult[i] *= 2;
        }
    }
    // 清理
    fftw_destroy_plan(p);
    fftw_free(in);
    fftw_free(outc);

    fftResult_xVec.resize(N/2+1);
    float fsDivideN = (static_cast<float>(fs)/(static_cast<float>(N-1)));
    for(int j = 1; j < N/2+1; ++j){
       fftResult_xVec[j] = j*fsDivideN;//(j+1)*(_basicPara.getFs()/(_basicPara.getTotalTimeSteps()-1))
    }
}

QVector<float> MyAlgorithm::normalizeOne(const QVector<float> &origVec)
{
    float max_ = maxVec(origVec);
    float min_ = minVec(origVec);
    QVector<float> out(origVec.size());
    for(int i = 0; i < origVec.size(); ++i){
        out[i] = (origVec[i]-min_)/max_;
    }
    //将最大值设置为1
    *std::max_element(out.begin(),out.end()) = 1;
    return out;
}
