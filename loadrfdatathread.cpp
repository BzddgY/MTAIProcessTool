#include "loadrfdatathread.h"

LoadRFDataThread::LoadRFDataThread(BasicParameter * const basicPara, const QString& fileDirectoryName,
                                   const QString& RFDataFileAddress, TADataBox *TADataBox_,
                                   QTabWidget* mainWindowTabWidget_, bool * isOK,
                                   bool* isNeedUpdateRFData, QString* lastLoadPath,
                                   QObject *parent)
    : QThread{parent}, _basicPara(basicPara), _fileDirectoryName(fileDirectoryName),
    _RFDataFileAddress(RFDataFileAddress), _TADataBox(TADataBox_), _mainWindowTabWidget(mainWindowTabWidget_),
    _bstop(false), _isOK(isOK), _isNeedUpdateRFData(isNeedUpdateRFData), _lastLoadPath(lastLoadPath)
{

}

LoadRFDataThread::~LoadRFDataThread()
{

}

void LoadRFDataThread::run()
{
    if(_bstop){
        emit sigAppendLog("取消导入数据^><^");
        *_isOK = false;
        return;
    }
    //根据不同的导入方式进行导入
    switch(_basicPara->getRFDataLoadType()){
    case RFDataLoadType::PathLoad://路径导入方式导入RF数据，此时用得到第几帧和平均帧数
        // PathLoadRFData();//根据不同实验室类型设置导入RF数据
        if(PathLoadRFData()){
            emit sigAppendLog("已成功导入数据！");
            emit sig_setExpPushButtonLoadRFDatasIcon(QIcon(":/icon/LoadDone.png"));
            *_isNeedUpdateRFData = false;
            *_isOK = true;
            // return true;
        }
        else{
            emit sigAppendLog("导入数据失败^><^");
            *_isOK = false;
            // return false;
        }
        break;
    case RFDataLoadType::AddressLoad://单个文件导入，此时不用考虑第几帧
        //根据不同实验室类型设置导入RF数据
        // AddressLoadRFData();
        if(AddressLoadRFData()){
            emit sigAppendLog("已成功导入数据！");
            emit sig_setExpPushButtonLoadRFDatasIcon(QIcon(":/icon/LoadDone.png"));
            *_isNeedUpdateRFData = false;
            *_isOK = true;
            // return true;
        }
        else{
            emit sigAppendLog("导入数据失败^><^");
            *_isOK = false;
            // return false;
        }
        break;
    default:
        emit sigAppendLog("导入数据失败^><^");
        *_isOK = false;
        // return false;
        break;
    }
}

bool LoadRFDataThread::PathLoadRFData()
{
    if(_bstop){
        emit sigAppendLog("取消导入数据^><^");
        return false;
    }
    switch(_basicPara->getLabType()){
    case LabType::MITAI111Lab://导入.dat
        if (_fileDirectoryName.isEmpty()){
            QMessageBox::information(_mainWindowTabWidget, "提示", "未选择文件夹！");
            return false;
        }
        else{
            //获取选定文件路径里的所有dat文件的绝对路径
            QStringList datFiles = getDatFiles(_fileDirectoryName);// 获取所有.dat文件的文件名并按文件名排序
            if (datFiles.isEmpty()) {
                QMessageBox::information(_mainWindowTabWidget, "提示", "该路径下未找到.dat文件！");
                return false;
            }
            // myDebug("datFiles.size() = " + QString::number(datFiles.size()));
            if (_basicPara->getStartDatInd() >= 1 && _basicPara->getStartDatInd() <= datFiles.size()) {
                if(_bstop){
                    emit sigAppendLog("取消导入数据^><^");
                    return false;
                }
                QVector<float>& rawData = _TADataBox->getData("RFData");
                //判断是否帧数不足，如果不足要在命令行给反馈并修改实际平均帧数
                if(_basicPara->getNumOfMeanFrames() > datFiles.size()-_basicPara->getStartDatInd()+1){
                    emit sig_setNumOfMeanFrames(datFiles.size()-_basicPara->getStartDatInd()+1);
                    emit sigAppendLog("导入帧数设置过多，已默认修改为最大能导入的平均帧数进行射频数据导入！");
                }
                //依次导入dat文件并求和
                int indexEnd = _basicPara->getStartDatInd()-1+_basicPara->getNumOfMeanFrames();
                for(int i = _basicPara->getStartDatInd()-1;i < indexEnd; i++){

                    if(_bstop){
                        emit sigAppendLog("取消导入数据^><^");
                        return false;
                    }

                    // // 打印求解.dat文件名以测试所导入文件的正确性
                    // qDebug() << i+1 << ":" << datFiles.at(i);
                    QString selectedFilePath = _fileDirectoryName + "/" + datFiles.at(i);
                    if(readDatFile(selectedFilePath).isEmpty())
                    {
                        qDebug() << "第"+selectedFilePath+"个文件读取失败或不存在，将依次进行下一个文件的读取";
                        continue;
                    }
                    if (i == _basicPara->getStartDatInd()-1)
                        rawData = readDatFile(selectedFilePath);
                    else
                        MyAlgorithm::addVectors(rawData, readDatFile(selectedFilePath));
                }
                // 手动遍历向量并取平均
                for (int i = 0; i < _basicPara->getNumOfSensors(); ++i) {
                    for(int j = 0; j < _basicPara->getTotalTimeSteps(); ++j){
                        rawData[i+j*_basicPara->getNumOfSensors()] /= _basicPara->getNumOfMeanFrames();
                    }
                }
            }
            return true;
        }
        break;
    case LabType::OtherLab://导入.txt或.csv
        if (_fileDirectoryName.isEmpty()){
            QMessageBox::information(_mainWindowTabWidget, "提示", "未选择文件夹！");
            return false;
        }
        else{
            //获取选定文件路径里的所有dat文件的绝对路径
            QStringList otherLabsFiles = getOtherLabsFiles(_fileDirectoryName);
            if (otherLabsFiles.isEmpty()) {
                QMessageBox::information(_mainWindowTabWidget, "提示", "该路径下未找到.txt或.csv文件！");
                return false;
            }
            // myDebug("datFiles.size() = " + QString::number(datFiles.size()));
            if (_basicPara->getStartDatInd() >= 1 && _basicPara->getStartDatInd() <= otherLabsFiles.size()) {
                if(_bstop){
                    emit sigAppendLog("取消导入数据^><^");
                    return false;
                }
                QVector<float>& rawData = _TADataBox->getData("RFData");
                //依次导入dat文件并求和
                int indexEnd = _basicPara->getStartDatInd()-1+_basicPara->getNumOfMeanFrames();
                for(int i = _basicPara->getStartDatInd()-1;i < indexEnd; i++){
                    if(_bstop){
                        emit sigAppendLog("取消导入数据^><^");
                        return false;
                    }

                    // // 打印求解.dat文件名以测试所导入文件的正确性
                    // qDebug() << i+1 << ":" << datFiles.at(i);
                    QString selectedFilePath = _fileDirectoryName + "/" + otherLabsFiles.at(i);
                    if(readOtherLabsFile(selectedFilePath).isEmpty())
                    {
                        qDebug() << "第"+selectedFilePath+"个文件读取失败或不存在，将依次进行下一个文件的读取";
                        continue;
                    }
                    if (i == _basicPara->getStartDatInd()-1)
                        rawData = readOtherLabsFile(selectedFilePath);
                    else
                        MyAlgorithm::addVectors(rawData, readOtherLabsFile(selectedFilePath));
                }
                // 手动遍历向量并取平均
                for (int i = 0; i < _basicPara->getNumOfSensors(); ++i) {
                    for(int j = 0; j < _basicPara->getTotalTimeSteps(); ++j){
                        rawData[i+j*_basicPara->getNumOfSensors()] /= _basicPara->getNumOfMeanFrames();
                    }
                }
            }
            return true;
        }
        break;
    default:
        return false;
        break;
    }
}

bool LoadRFDataThread::AddressLoadRFData()
{
    if(_bstop){
        emit sigAppendLog("取消导入数据^><^");
        return false;
    }
    switch(_basicPara->getLabType()){
    case LabType::MITAI111Lab://导入.dat
        if (_RFDataFileAddress.isEmpty()){
            QMessageBox::information(_mainWindowTabWidget, "提示", "未选择文件夹！");
            return false;
        }
        else{
            QVector<float>& rawData = _TADataBox->getData("RFData");
            rawData = readDatFile(_RFDataFileAddress);
            return true;
        }
        break;
    case LabType::OtherLab://导入.txt或.csv
        if (_RFDataFileAddress.isEmpty()){
            QMessageBox::information(_mainWindowTabWidget, "提示", "未选择文件夹！");
            return false;
        }
        else{
            QVector<float>& rawData = _TADataBox->getData("RFData");
            rawData = readOtherLabsFile(_RFDataFileAddress);
            return true;
        }
        break;
    default:
        return false;
        break;
    }
}

QStringList LoadRFDataThread::getDatFiles(const QString &directoryPath)
{
    QDir dir(directoryPath);
    dir.setNameFilters(QStringList() << "*.dat");
    dir.setSorting(QDir::Name);
    return dir.entryList(QDir::Files);
}

QVector<float> LoadRFDataThread::readDatFile(const QString &filePath)
{
    QFile file(filePath);
    QVector<float> rawData;
    //所读取的.dat文件是按照每总通道数个依次分别代表每个通道第几个采样点时的信号值且读取时需要按照16位int类型进行转换读取
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "无法打开文件:" << filePath;
        return rawData;
    }

    QDataStream in(&file);
    in.setByteOrder(QDataStream::LittleEndian);

    while (!in.atEnd()) {
        int16_t value;
        in >> value;
        rawData.append(static_cast<float>(value));
    }
    file.close();
    // myDebug("读取数据");
    if ((rawData.size() / _basicPara->getNumOfSensors()) != _basicPara->getTotalTimeSteps()){
        QMessageBox::warning(_mainWindowTabWidget, "警告","所设置的采样点数与将要导入的数据不符\n所导入的数据采样点数为：" + QString::number(rawData.size() / _basicPara->getNumOfSensors()) + "\n请重新设置！");
        return rawData;
    }
    // myDebug("读取数据");

    return rawData;
}

QStringList LoadRFDataThread::getOtherLabsFiles(const QString &directoryPath)
{
    QDir dir(directoryPath);
    dir.setNameFilters(QStringList() << "*.csv" <<"*.txt");
    dir.setSorting(QDir::Name);
    return dir.entryList(QDir::Files);
}

QVector<float> LoadRFDataThread::readOtherLabsFile(const QString &filePath)
{
    QVector<float> loadedData;
    // 读取文件内容
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(_mainWindowTabWidget, "错误", "文件打开失败！");
        return loadedData;
    }

    QTextStream stream(&file);
    QVector<QVector<float>> matrix;
    QString separator = filePath.endsWith(".csv") ? "," : " "; // 根据扩展名确定分隔符

    // 逐行解析数据
    while (!stream.atEnd()) {
        QString line = stream.readLine().trimmed();
        if (line.isEmpty()) continue; // 跳过空行

        QStringList values = line.split(separator, Qt::SkipEmptyParts);
        QVector<float> row;
        bool parseOk = true;

        for (const QString& valStr : values) {
            bool ok;
            float value = valStr.toFloat(&ok);
            if (!ok) {
                parseOk = false;
                break;
            }
            row.append(value);
        }

        if (!parseOk) {
            QMessageBox::warning(_mainWindowTabWidget, "错误", "数据格式错误！");
            file.close();
            return loadedData;
        }

        matrix.append(row);
    }
    file.close();

    if ((matrix.size() != _basicPara->getNumOfSensors()) || matrix[0].size() != _basicPara->getTotalTimeSteps()){
        QMessageBox::warning(_mainWindowTabWidget, "警告","所设置的采样点数与将要导入的数据不符\n所导入的数据采样点数为：" + QString::number(_basicPara->getTotalTimeSteps()) + "\n请重新设置！");
        return loadedData;
    }

    //记录loadedData
    loadedData.resize(_basicPara->getNumOfSensors()*_basicPara->getTotalTimeSteps());
    for(int column = 0; column < _basicPara->getTotalTimeSteps(); column++){
        for(int raw = 0; raw < _basicPara->getNumOfSensors(); raw++){
            loadedData[raw + column*_basicPara->getNumOfSensors()] = matrix[raw][column];
        }
    }

    // 更新状态
    *_lastLoadPath = QFileInfo(filePath).absolutePath();// 记录路径
    return loadedData;
}

void LoadRFDataThread::slotCancelProgress()
{
    this->_bstop = true;
}
