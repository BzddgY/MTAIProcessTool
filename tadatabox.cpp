// tadatabox.cpp
#include "tadatabox.h"

TADataBox::TADataBox(QObject *parent) : QObject(parent) {}

bool TADataBox::addData(qint64 size, const QString& name, const QString& comment) {
    if (name.isEmpty() || size <= 0) return false;
    if (m_dataStore.contains(name)) {
        qWarning() << "Data name already exists:" << name;
        return false;
    }

    // 内存安全检查
    if (!checkMemory(size)) {
        qCritical() << "Memory limit exceeded when adding" << name;
        return false;
    }

    // 创建数据容器（延迟内存分配）
    DataEntry entry;
    entry.data = QSharedPointer<QVector<float>>::create(size);
    // entry.data->reserve(size); // 预分配内存但不初始化
    entry.totalSize = size;
    entry.createTime = QDateTime::currentDateTime();
    entry.comment = comment;

    m_dataStore.insert(name, entry);
    return true;
}

bool TADataBox::removeData(const QString& name) {
    return m_dataStore.remove(name) > 0;
}

QVector<float>& TADataBox::getData(const QString& name) {
    auto it = m_dataStore.find(name);
    if (it == m_dataStore.end()) {
        throw std::invalid_argument("Invalid data name: " + name.toStdString());
    }
    return *(it->data);
}

const QVector<float>& TADataBox::viewData(const QString& name) const {
    auto it = m_dataStore.constFind(name);
    if (it == m_dataStore.constEnd()) {
        throw std::out_of_range("Data not found: " + name.toStdString());
    }
    return *(it->data);
}

bool TADataBox::cloneData(const QString &srcName, const QString &destName)
{
    if (!contains(srcName)) return false;

    const auto& srcEntry = m_dataStore[srcName];
    DataEntry newEntry = srcEntry;
    newEntry.data = QSharedPointer<QVector<float>>::create(*srcEntry.data);
    newEntry.createTime = QDateTime::currentDateTime();
    newEntry.version = 0;

    m_dataStore.insert(destName, newEntry);
    return true;
}

QStringList TADataBox::availableData() const {
    return m_dataStore.keys();
}

qint64 TADataBox::getDataSize(const QString& name) const {
    auto it = m_dataStore.constFind(name);
    return (it != m_dataStore.constEnd()) ? it->totalSize : -1;
}

bool TADataBox::contains(const QString& name) const {
    return m_dataStore.contains(name);
}

bool TADataBox::checkMemory(qint64 newSize) {
    qint64 currentUsage = 0;
    for (const auto& entry : m_dataStore) {
        currentUsage += entry.data->capacity() * sizeof(float);
    }
    return (currentUsage + newSize * sizeof(float)) <= MY_TADATABOX_MAX_MEMORY;
}
