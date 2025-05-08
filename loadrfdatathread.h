#ifndef LOADRFDATATHREAD_H
#define LOADRFDATATHREAD_H

#include <QThread>
#include<basicparameter.h>
#include<QMessageBox>
#include<QString>
#include<QDir>
#include<QFile>
#include<QVector>
#include<myalgorithm.h>
#include<tadatabox.h>
#include<QTabWidget>

class LoadRFDataThread : public QThread
{
    Q_OBJECT
public:
    explicit LoadRFDataThread(BasicParameter* const basicPara, const QString& fileDirectoryName, const QString& RFDataFileAddress,
                              TADataBox* TADataBox_, QTabWidget* mainWindowTabWidget_, bool * isOK,  bool* isNeedUpdateRFData,
                              QString* lastLoadPath, QObject *parent = nullptr);

    ~LoadRFDataThread();
protected:
    virtual void run();

private:
    bool PathLoadRFData();//路径按帧数取平均导入RFData
    bool AddressLoadRFData();//绝对路径单帧导入RFData

    // 获取所有.dat文件并按文件名排序
    QStringList getDatFiles(const QString &directoryPath);
    // 读取.dat文件中的光声信号数据
    QVector<float> readDatFile(const QString &filePath);
    // 获取所有.txt,.csv文件并按文件名排序
    QStringList getOtherLabsFiles(const QString &directoryPath);
    // 读取.txt,.csv文件中的光声信号数据
    QVector<float> readOtherLabsFile(const QString &filePath);

private:
    BasicParameter* _basicPara;
    QString _fileDirectoryName;//.dat文件导入路径
    TADataBox* _TADataBox;//数据管理箱地址
    QString _RFDataFileAddress;//射频数据文件绝对地址
    QTabWidget* _mainWindowTabWidget;
    bool _bstop;//是否暂停导入
    bool* _isOK;//是否导入成功的bool变量的地址
    bool* _isNeedUpdateRFData;//是否需要更新RFData
    QString* _lastLoadPath;//上次打开写入文件路径

signals:
    void sigAppendLog(const QString& message);
    void sig_setExpPushButtonLoadRFDatasIcon(const QIcon& iconName);
    void sig_setNumOfMeanFrames(int);
    void sigUpdateProgress(int);
    void sigFinishProgress(int);
public slots:
    void slotCancelProgress();

};

#endif // LOADRFDATATHREAD_H
