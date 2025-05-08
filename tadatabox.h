#ifndef TADATABOX_H
#define TADATABOX_H
// tadatabox.h
#include <QObject>
#include <QHash>
#include <QVector>
#include <QString>
#include <QDateTime>
#include <QSharedPointer>
#include<const.h>
//该类用来管理TATool中所有关于TA信号的数据（原始RF信号、预处理后的RF信号、成像后的TAI值）
//以下给出一些应用例子
//::

// // 初始化数据箱
// TADataBox dataBox;

// // 添加原始RF数据
// dataBox.addData(128*4096, "rawRF");

// // 访问并填充数据
// QVector<float>& rawData = dataBox.getData("rawRF");
// for (int i=0; i<rawData.size(); ++i) {
//     rawData[i] = acquireSample(i); // 填充实际采样数据
// }

// // 处理数据时创建副本
// dataBox.cloneData("rawRF", "filteredRF");
// QVector<float>& filtered = dataBox.getData("filteredRF");
// applyFilter(filtered); // 应用滤波算法

// // 检查数据存在性
// if (dataBox.contains("denoisedRF")) {
//     // 执行去噪后处理...
// }

// // 获取所有数据集列表
// qDebug() << "Available datasets:" << dataBox.availableData();



class TADataBox : public QObject {
    Q_OBJECT
public:
    struct DataEntry {
        QSharedPointer<QVector<float>> data; // 智能指针管理数据
        qint64 totalSize;                    // 总元素个数
        QDateTime createTime;               // 创建时间戳
        QString comment;                    // 用户注释（可选）
        // 在DataEntry中添加版本号
        int version;
    };

    explicit TADataBox(QObject *parent = nullptr);

    // 核心接口
    bool addData(qint64 size, const QString& name, const QString& comment = "");
    bool removeData(const QString& name);
    QVector<float>& getData(const QString& name);
    const QVector<float>& viewData(const QString& name) const;
    //克隆接口
    bool cloneData(const QString& srcName, const QString& destName);

    // 元数据查询
    QStringList availableData() const;
    qint64 getDataSize(const QString& name) const;
    bool contains(const QString& name) const;

private:
    QHash<QString, DataEntry> m_dataStore; // 核心存储结构
    // const qint64 MY_TADATABOX_MAX_MEMORY = 1024 * 1024 * 1024; // 最大内存限制1GB

    bool checkMemory(qint64 newSize); // 内存安全检查
};

#endif
