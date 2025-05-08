#ifndef EXPSIGNALPROCESSTOOL_H
#define EXPSIGNALPROCESSTOOL_H

#include <QWidget>
#include<const.h>

//说明
//该类用来实现信号预处理界面设置!!!!!!!!!!!!!!

namespace Ui {
class ExpSignalProcessTool;
}

class ExpSignalProcessTool : public QWidget
{
    Q_OBJECT

public:
    explicit ExpSignalProcessTool(QWidget *parent = nullptr);
    ~ExpSignalProcessTool();


    //外面控制界面访问该界面中参数的接口!!!!

signals:
    void sig_setRFDataLoadType(const RFDataLoadType);//将界面的导入数据方式信号发出去
    void sig_loadRFData();
    void sig_plotAllRFData();
    void sig_savePreProcessRFData();
    void sig_plotSingleRFData(const int&);
    void sig_plotAllPreProcessRFData();
    void sig_preProcessRFData();
    void sig_isDeconvolution(bool);
    void sig_isFilter(bool);
    void sig_isCutZeros(bool);
    void sig_isLouKong(bool);
    void sig_isInsertValue(bool);
    void sig_isHilbert(const bool);
    void sig_plotSinglePreProcessedRFData(const int &);
    void sig_plotSingleBeforeAndAfterRFData(const int&);
    void sig_setCutZerosTimeSteps(const int&);
    void sig_plotSingleRFData_PreDomain(const int&);
    void sig_plotSinglePreProcessedRFData_FreDomain(const int&);
    void sig_plotSingleBeforeAndAfterRFData_FreDomain(const int&);
    void sig_setFilterType(const FilterType&);
    void sig_setFilterTool();
    void sig_setLouKongProcessTool();
    void sig_setInsertValueType(const InsertValueType&);
    void sig_setDeconvolutionTool();

public slots:
    void slot_initialPara();
    void slot_setPushButtonLoadRFDatasIcon(const QIcon& iconName);
    void slot_setSpinBoxSelectedSensorsMax(const int& max_);
    void slot_setTotalTimeSteps(const int& totalTimeSteps);
    void slot_setPreProcessButtonIcon(const bool& ok);

private slots:
    void on_comboBox_RFDataLoadType_currentIndexChanged(int index);
    void on_pushButton_loadRFData_clicked();
    void on_pushButton_plotAllRFData_clicked();
    void on_pushButton_savePreProcessRFData_clicked();
    void on_toolButton_confirmSelectedSensorIndex_clicked();
    void on_pushButton_plotSingleRFData_clicked();
    void on_spinBox_selectedSensorIndex_editingFinished();
    void on_pushButton_plotAllPreProcessRFData_clicked();

    void on_pushButton_preProcessRFData_clicked();

    void on_checkBox_isDeconvolution_stateChanged(int arg1);

    void on_checkBox_isFilter_stateChanged(int arg1);

    void on_checkBox_isCutZeros_stateChanged(int arg1);

    void on_checkBox_isLouKong_stateChanged(int arg1);

    void on_checkBox_isInsertValue_stateChanged(int arg1);

    void on_pushButton_plotSinglePreProcessedRFData_clicked();//!!!!!!!!!!!!未实现

    void on_pushButton_plotSingleBeforeAndAfterRFData_clicked();//!!!!!!!!!!!!未实现

    void on_spinBox_cutZerosTimesteps_editingFinished();

    void on_pushButton_plotSingleRFData_PreDomain_clicked();

    void on_pushButton_plotSinglePreProcessedRFData_FreDomain_clicked();

    void on_pushButton_plotSingleBeforeAndAfterRFData_FreDomain_clicked();

    void on_comboBox_filterType_currentIndexChanged(int index);

    void on_toolButton_setFilterPara_clicked();

    void on_toolButton_setLouKongProcessPara_clicked();

    void on_comboBox_insertValueType_currentIndexChanged(int index);

    void on_checkBox_isHilbertTransform_stateChanged(int arg1);

    void on_toolButton_setDeconvolutionPara_clicked();

private:
    Ui::ExpSignalProcessTool *ui;
    int _selectedSensorIndex;//选择的单传感器通道\
    //预处理信号参数
    bool _isDeconvolution;//是否去卷积
    bool _isInsertValue;//是否插值
    bool _isFilter;//是否滤波
    bool _isCutZeros;//是否置零
    bool _isLouKongProcess;//是否镂空阵列处理
};

#endif // EXPSIGNALPROCESSTOOL_H
