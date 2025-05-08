/********************************************************************************
** Form generated from reading UI file 'experimentmodulebasicsettingwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPERIMENTMODULEBASICSETTINGWINDOW_H
#define UI_EXPERIMENTMODULEBASICSETTINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_experimentModuleBasicSettingWindow
{
public:
    QGridLayout *gridLayout;
    QWidget *widget_basicSet;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_27;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_SoS;
    QSpacerItem *horizontalSpacer_21;
    QPushButton *pushButton_getDatFileLoadPath;
    QLabel *label_fileAddress;
    QLabel *label_radius;
    QLabel *label_pitch;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer_23;
    QSpinBox *spinBox_startDatInd;
    QDoubleSpinBox *doubleSpinBox_angleRange;
    QSpacerItem *horizontalSpacer_26;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_34;
    QSpacerItem *horizontalSpacer_24;
    QComboBox *comboBox_sensorType;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_31;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *lineEdit_RFDataFileAddress;
    QSpacerItem *horizontalSpacer_22;
    QComboBox *comboBox_LabType;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_28;
    QSpinBox *spinBox_sampleFrequency;
    QLabel *label_8;
    QSpinBox *spinBox_numOfSensors;
    QSpacerItem *horizontalSpacer_29;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_RFFileAddressName;
    QSpinBox *spinBox_delayTimeSteps;
    QSpacerItem *horizontalSpacer_25;
    QDoubleSpinBox *doubleSpinBox_pitch;
    QSpinBox *spinBox_numOfMeanFrames;
    QSpinBox *spinBox_totalTimeSteps;
    QLineEdit *lineEdit_datFileLoadPath;
    QSpacerItem *horizontalSpacer_20;
    QSpacerItem *horizontalSpacer_35;
    QLabel *label_angleRange;
    QDoubleSpinBox *doubleSpinBox_radius;
    QLabel *label_13;
    QPushButton *pushButton_getRFDataFileLoadAddress;
    QPushButton *pushButton_preShowSensorsMap;
    QSpacerItem *horizontalSpacer_19;
    QSpacerItem *horizontalSpacer_30;

    void setupUi(QWidget *experimentModuleBasicSettingWindow)
    {
        if (experimentModuleBasicSettingWindow->objectName().isEmpty())
            experimentModuleBasicSettingWindow->setObjectName("experimentModuleBasicSettingWindow");
        experimentModuleBasicSettingWindow->resize(350, 450);
        experimentModuleBasicSettingWindow->setMinimumSize(QSize(350, 450));
        gridLayout = new QGridLayout(experimentModuleBasicSettingWindow);
        gridLayout->setObjectName("gridLayout");
        widget_basicSet = new QWidget(experimentModuleBasicSettingWindow);
        widget_basicSet->setObjectName("widget_basicSet");
        gridLayout_2 = new QGridLayout(widget_basicSet);
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalSpacer_27 = new QSpacerItem(44, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_27, 16, 7, 1, 1);

        label_10 = new QLabel(widget_basicSet);
        label_10->setObjectName("label_10");

        gridLayout_2->addWidget(label_10, 11, 0, 1, 1);

        doubleSpinBox_SoS = new QDoubleSpinBox(widget_basicSet);
        doubleSpinBox_SoS->setObjectName("doubleSpinBox_SoS");
        QFont font;
        font.setPointSize(9);
        doubleSpinBox_SoS->setFont(font);
        doubleSpinBox_SoS->setDecimals(1);
        doubleSpinBox_SoS->setMaximum(9999.000000000000000);
        doubleSpinBox_SoS->setSingleStep(5.000000000000000);
        doubleSpinBox_SoS->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        doubleSpinBox_SoS->setValue(1400.000000000000000);

        gridLayout_2->addWidget(doubleSpinBox_SoS, 11, 1, 1, 7);

        horizontalSpacer_21 = new QSpacerItem(123, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_21, 10, 4, 1, 9);

        pushButton_getDatFileLoadPath = new QPushButton(widget_basicSet);
        pushButton_getDatFileLoadPath->setObjectName("pushButton_getDatFileLoadPath");
        pushButton_getDatFileLoadPath->setFont(font);

        gridLayout_2->addWidget(pushButton_getDatFileLoadPath, 2, 7, 1, 4);

        label_fileAddress = new QLabel(widget_basicSet);
        label_fileAddress->setObjectName("label_fileAddress");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font1.setPointSize(9);
        label_fileAddress->setFont(font1);

        gridLayout_2->addWidget(label_fileAddress, 2, 0, 1, 1);

        label_radius = new QLabel(widget_basicSet);
        label_radius->setObjectName("label_radius");

        gridLayout_2->addWidget(label_radius, 17, 0, 1, 1);

        label_pitch = new QLabel(widget_basicSet);
        label_pitch->setObjectName("label_pitch");

        gridLayout_2->addWidget(label_pitch, 16, 0, 1, 1);

        label_15 = new QLabel(widget_basicSet);
        label_15->setObjectName("label_15");

        gridLayout_2->addWidget(label_15, 15, 0, 1, 1);

        horizontalSpacer_23 = new QSpacerItem(87, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_23, 12, 7, 1, 6);

        spinBox_startDatInd = new QSpinBox(widget_basicSet);
        spinBox_startDatInd->setObjectName("spinBox_startDatInd");
        spinBox_startDatInd->setFont(font);
        spinBox_startDatInd->setMinimum(1);
        spinBox_startDatInd->setMaximum(99999);
        spinBox_startDatInd->setSingleStep(10);
        spinBox_startDatInd->setValue(1);

        gridLayout_2->addWidget(spinBox_startDatInd, 12, 1, 1, 1);

        doubleSpinBox_angleRange = new QDoubleSpinBox(widget_basicSet);
        doubleSpinBox_angleRange->setObjectName("doubleSpinBox_angleRange");
        doubleSpinBox_angleRange->setFont(font);
        doubleSpinBox_angleRange->setMaximum(2.000000000000000);
        doubleSpinBox_angleRange->setSingleStep(0.250000000000000);
        doubleSpinBox_angleRange->setValue(1.000000000000000);

        gridLayout_2->addWidget(doubleSpinBox_angleRange, 18, 1, 1, 5);

        horizontalSpacer_26 = new QSpacerItem(99, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_26, 15, 6, 1, 7);

        label_9 = new QLabel(widget_basicSet);
        label_9->setObjectName("label_9");

        gridLayout_2->addWidget(label_9, 10, 0, 1, 1);

        horizontalSpacer_34 = new QSpacerItem(99, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_34, 2, 11, 1, 1);

        horizontalSpacer_24 = new QSpacerItem(123, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_24, 13, 7, 1, 6);

        comboBox_sensorType = new QComboBox(widget_basicSet);
        comboBox_sensorType->setObjectName("comboBox_sensorType");
        comboBox_sensorType->setFont(font);

        gridLayout_2->addWidget(comboBox_sensorType, 15, 1, 1, 5);

        label_12 = new QLabel(widget_basicSet);
        label_12->setObjectName("label_12");

        gridLayout_2->addWidget(label_12, 12, 0, 1, 1);

        horizontalSpacer_31 = new QSpacerItem(99, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_31, 1, 7, 1, 2);

        verticalSpacer_3 = new QSpacerItem(20, 7, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 20, 0, 1, 1);

        lineEdit_RFDataFileAddress = new QLineEdit(widget_basicSet);
        lineEdit_RFDataFileAddress->setObjectName("lineEdit_RFDataFileAddress");
        lineEdit_RFDataFileAddress->setFont(font);

        gridLayout_2->addWidget(lineEdit_RFDataFileAddress, 5, 1, 1, 2);

        horizontalSpacer_22 = new QSpacerItem(22, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_22, 11, 8, 1, 1);

        comboBox_LabType = new QComboBox(widget_basicSet);
        comboBox_LabType->setObjectName("comboBox_LabType");
        comboBox_LabType->setFont(font);

        gridLayout_2->addWidget(comboBox_LabType, 1, 1, 1, 1);

        label_14 = new QLabel(widget_basicSet);
        label_14->setObjectName("label_14");

        gridLayout_2->addWidget(label_14, 14, 0, 1, 1);

        horizontalSpacer_28 = new QSpacerItem(44, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_28, 17, 7, 1, 1);

        spinBox_sampleFrequency = new QSpinBox(widget_basicSet);
        spinBox_sampleFrequency->setObjectName("spinBox_sampleFrequency");
        spinBox_sampleFrequency->setFont(font);
        spinBox_sampleFrequency->setMaximum(1000);
        spinBox_sampleFrequency->setSingleStep(5);
        spinBox_sampleFrequency->setValue(40);

        gridLayout_2->addWidget(spinBox_sampleFrequency, 8, 1, 1, 5);

        label_8 = new QLabel(widget_basicSet);
        label_8->setObjectName("label_8");

        gridLayout_2->addWidget(label_8, 9, 0, 1, 1);

        spinBox_numOfSensors = new QSpinBox(widget_basicSet);
        spinBox_numOfSensors->setObjectName("spinBox_numOfSensors");
        spinBox_numOfSensors->setFont(font);
        spinBox_numOfSensors->setMinimum(1);
        spinBox_numOfSensors->setMaximum(9999);
        spinBox_numOfSensors->setSingleStep(64);
        spinBox_numOfSensors->setValue(128);

        gridLayout_2->addWidget(spinBox_numOfSensors, 14, 1, 1, 5);

        horizontalSpacer_29 = new QSpacerItem(44, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_29, 18, 7, 1, 1);

        label = new QLabel(widget_basicSet);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        label_6 = new QLabel(widget_basicSet);
        label_6->setObjectName("label_6");

        gridLayout_2->addWidget(label_6, 8, 0, 1, 1);

        label_RFFileAddressName = new QLabel(widget_basicSet);
        label_RFFileAddressName->setObjectName("label_RFFileAddressName");

        gridLayout_2->addWidget(label_RFFileAddressName, 5, 0, 1, 1);

        spinBox_delayTimeSteps = new QSpinBox(widget_basicSet);
        spinBox_delayTimeSteps->setObjectName("spinBox_delayTimeSteps");
        spinBox_delayTimeSteps->setFont(font);
        spinBox_delayTimeSteps->setMaximum(19998);
        spinBox_delayTimeSteps->setSingleStep(128);
        spinBox_delayTimeSteps->setValue(0);

        gridLayout_2->addWidget(spinBox_delayTimeSteps, 10, 1, 1, 3);

        horizontalSpacer_25 = new QSpacerItem(123, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_25, 14, 7, 1, 6);

        doubleSpinBox_pitch = new QDoubleSpinBox(widget_basicSet);
        doubleSpinBox_pitch->setObjectName("doubleSpinBox_pitch");
        doubleSpinBox_pitch->setFont(font);
        doubleSpinBox_pitch->setSingleStep(0.100000000000000);
        doubleSpinBox_pitch->setValue(0.300000000000000);

        gridLayout_2->addWidget(doubleSpinBox_pitch, 16, 1, 1, 5);

        spinBox_numOfMeanFrames = new QSpinBox(widget_basicSet);
        spinBox_numOfMeanFrames->setObjectName("spinBox_numOfMeanFrames");
        spinBox_numOfMeanFrames->setFont(font);
        spinBox_numOfMeanFrames->setMinimum(1);
        spinBox_numOfMeanFrames->setMaximum(99999);
        spinBox_numOfMeanFrames->setSingleStep(10);
        spinBox_numOfMeanFrames->setValue(1);

        gridLayout_2->addWidget(spinBox_numOfMeanFrames, 13, 1, 1, 5);

        spinBox_totalTimeSteps = new QSpinBox(widget_basicSet);
        spinBox_totalTimeSteps->setObjectName("spinBox_totalTimeSteps");
        spinBox_totalTimeSteps->setFont(font);
        spinBox_totalTimeSteps->setMaximum(20000);
        spinBox_totalTimeSteps->setSingleStep(4096);
        spinBox_totalTimeSteps->setValue(4096);
        spinBox_totalTimeSteps->setDisplayIntegerBase(10);

        gridLayout_2->addWidget(spinBox_totalTimeSteps, 9, 1, 1, 7);

        lineEdit_datFileLoadPath = new QLineEdit(widget_basicSet);
        lineEdit_datFileLoadPath->setObjectName("lineEdit_datFileLoadPath");
        lineEdit_datFileLoadPath->setFont(font);

        gridLayout_2->addWidget(lineEdit_datFileLoadPath, 2, 1, 1, 1);

        horizontalSpacer_20 = new QSpacerItem(123, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_20, 9, 8, 1, 5);

        horizontalSpacer_35 = new QSpacerItem(99, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_35, 5, 11, 1, 1);

        label_angleRange = new QLabel(widget_basicSet);
        label_angleRange->setObjectName("label_angleRange");

        gridLayout_2->addWidget(label_angleRange, 18, 0, 1, 1);

        doubleSpinBox_radius = new QDoubleSpinBox(widget_basicSet);
        doubleSpinBox_radius->setObjectName("doubleSpinBox_radius");
        doubleSpinBox_radius->setFont(font);
        doubleSpinBox_radius->setMaximum(9999.000000000000000);
        doubleSpinBox_radius->setSingleStep(5.000000000000000);
        doubleSpinBox_radius->setValue(65.000000000000000);

        gridLayout_2->addWidget(doubleSpinBox_radius, 17, 1, 1, 5);

        label_13 = new QLabel(widget_basicSet);
        label_13->setObjectName("label_13");

        gridLayout_2->addWidget(label_13, 13, 0, 1, 1);

        pushButton_getRFDataFileLoadAddress = new QPushButton(widget_basicSet);
        pushButton_getRFDataFileLoadAddress->setObjectName("pushButton_getRFDataFileLoadAddress");
        pushButton_getRFDataFileLoadAddress->setFont(font);

        gridLayout_2->addWidget(pushButton_getRFDataFileLoadAddress, 5, 7, 1, 4);

        pushButton_preShowSensorsMap = new QPushButton(widget_basicSet);
        pushButton_preShowSensorsMap->setObjectName("pushButton_preShowSensorsMap");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font2.setPointSize(9);
        pushButton_preShowSensorsMap->setFont(font2);

        gridLayout_2->addWidget(pushButton_preShowSensorsMap, 19, 0, 1, 8);

        horizontalSpacer_19 = new QSpacerItem(22, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_19, 8, 7, 1, 1);

        horizontalSpacer_30 = new QSpacerItem(65, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_30, 19, 8, 1, 5);


        gridLayout->addWidget(widget_basicSet, 0, 0, 1, 1);


        retranslateUi(experimentModuleBasicSettingWindow);

        QMetaObject::connectSlotsByName(experimentModuleBasicSettingWindow);
    } // setupUi

    void retranslateUi(QWidget *experimentModuleBasicSettingWindow)
    {
        experimentModuleBasicSettingWindow->setWindowTitle(QCoreApplication::translate("experimentModuleBasicSettingWindow", "Form", nullptr));
        label_10->setText(QCoreApplication::translate("experimentModuleBasicSettingWindow", "<html><head/><body><p>\345\235\207\345\214\200\345\243\260\351\200\237(m/s)\357\274\232</p></body></html>", nullptr));
        pushButton_getDatFileLoadPath->setText(QCoreApplication::translate("experimentModuleBasicSettingWindow", "\347\202\271\345\207\273\350\216\267\345\217\226\350\267\257\345\276\204", nullptr));
        label_fileAddress->setText(QCoreApplication::translate("experimentModuleBasicSettingWindow", "<html><head/><body><p>.dat\346\226\207\344\273\266\350\267\257\345\276\204\357\274\232</p></body></html>", nullptr));
        label_radius->setText(QCoreApplication::translate("experimentModuleBasicSettingWindow", "<html><head/><body><p>radius(mm)\357\274\232</p></body></html>", nullptr));
        label_pitch->setText(QCoreApplication::translate("experimentModuleBasicSettingWindow", "<html><head/><body><p>pitch(mm)\357\274\232</p></body></html>", nullptr));
        label_15->setText(QCoreApplication::translate("experimentModuleBasicSettingWindow", "<html><head/><body><p>\344\274\240\346\204\237\345\231\250\347\261\273\345\236\213\357\274\232</p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("experimentModuleBasicSettingWindow", "<html><head/><body><p>\345\273\266\346\227\266\346\255\245\351\225\277\357\274\232</p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("experimentModuleBasicSettingWindow", "<html><head/><body><p>\345\274\200\345\247\213\345\244\204\347\220\206\345\270\247\346\225\260\357\274\232</p></body></html>", nullptr));
        label_14->setText(QCoreApplication::translate("experimentModuleBasicSettingWindow", "<html><head/><body><p>\351\200\232\351\201\223\346\225\260\357\274\232</p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("experimentModuleBasicSettingWindow", "<html><head/><body><p>\351\207\207\346\240\267\347\202\271\346\225\260\357\274\232</p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("experimentModuleBasicSettingWindow", "<html><head/><body><p>\345\256\236\351\252\214\345\256\244\357\274\232</p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("experimentModuleBasicSettingWindow", "<html><head/><body><p>\351\207\207\346\240\267\351\242\221\347\216\207(MHz)\357\274\232</p></body></html>", nullptr));
        label_RFFileAddressName->setText(QCoreApplication::translate("experimentModuleBasicSettingWindow", "<html><head/><body><p>RF\346\225\260\346\215\256\346\226\207\344\273\266\345\234\260\345\235\200\357\274\232</p></body></html>", nullptr));
        label_angleRange->setText(QCoreApplication::translate("experimentModuleBasicSettingWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\274\247\350\247\222\350\214\203\345\233\264(\317\200)\357\274\232</p></body></html>", nullptr));
        label_13->setText(QCoreApplication::translate("experimentModuleBasicSettingWindow", "<html><head/><body><p>\345\270\247\345\271\263\345\235\207\346\225\260\357\274\232</p></body></html>", nullptr));
        pushButton_getRFDataFileLoadAddress->setText(QCoreApplication::translate("experimentModuleBasicSettingWindow", "\347\202\271\345\207\273\350\216\267\345\217\226\345\234\260\345\235\200", nullptr));
        pushButton_preShowSensorsMap->setText(QCoreApplication::translate("experimentModuleBasicSettingWindow", "\347\202\271\345\207\273\351\242\204\350\247\210\344\274\240\346\204\237\345\231\250\344\275\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class experimentModuleBasicSettingWindow: public Ui_experimentModuleBasicSettingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPERIMENTMODULEBASICSETTINGWINDOW_H
