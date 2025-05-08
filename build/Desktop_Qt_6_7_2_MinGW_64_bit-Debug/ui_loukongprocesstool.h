/********************************************************************************
** Form generated from reading UI file 'loukongprocesstool.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOUKONGPROCESSTOOL_H
#define UI_LOUKONGPROCESSTOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LouKongProcessTool
{
public:
    QGridLayout *gridLayout;
    QComboBox *comboBox_shiftType;
    QLabel *label_2;
    QSpinBox *spinBox_sensorIndex;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *pushButton_confirmCurrentSetting;
    QLabel *label_4;
    QLabel *label;
    QSpinBox *spinBox_shiftSteps;
    QLabel *label_showSensorIndex;
    QLabel *label_3;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_turnToDefaultSetting;

    void setupUi(QWidget *LouKongProcessTool)
    {
        if (LouKongProcessTool->objectName().isEmpty())
            LouKongProcessTool->setObjectName("LouKongProcessTool");
        LouKongProcessTool->resize(392, 327);
        gridLayout = new QGridLayout(LouKongProcessTool);
        gridLayout->setObjectName("gridLayout");
        comboBox_shiftType = new QComboBox(LouKongProcessTool);
        comboBox_shiftType->setObjectName("comboBox_shiftType");

        gridLayout->addWidget(comboBox_shiftType, 3, 1, 1, 1);

        label_2 = new QLabel(LouKongProcessTool);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        spinBox_sensorIndex = new QSpinBox(LouKongProcessTool);
        spinBox_sensorIndex->setObjectName("spinBox_sensorIndex");
        spinBox_sensorIndex->setMinimum(1);
        spinBox_sensorIndex->setMaximum(99999);

        gridLayout->addWidget(spinBox_sensorIndex, 0, 1, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(LouKongProcessTool);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setMinimum(-99.000000000000000);
        doubleSpinBox->setMaximum(99.000000000000000);
        doubleSpinBox->setSingleStep(0.100000000000000);
        doubleSpinBox->setValue(1.000000000000000);

        gridLayout->addWidget(doubleSpinBox, 5, 1, 1, 1);

        pushButton_confirmCurrentSetting = new QPushButton(LouKongProcessTool);
        pushButton_confirmCurrentSetting->setObjectName("pushButton_confirmCurrentSetting");

        gridLayout->addWidget(pushButton_confirmCurrentSetting, 3, 2, 1, 1);

        label_4 = new QLabel(LouKongProcessTool);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        label = new QLabel(LouKongProcessTool);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        spinBox_shiftSteps = new QSpinBox(LouKongProcessTool);
        spinBox_shiftSteps->setObjectName("spinBox_shiftSteps");
        spinBox_shiftSteps->setMinimum(0);
        spinBox_shiftSteps->setMaximum(4096);

        gridLayout->addWidget(spinBox_shiftSteps, 4, 1, 1, 1);

        label_showSensorIndex = new QLabel(LouKongProcessTool);
        label_showSensorIndex->setObjectName("label_showSensorIndex");
        label_showSensorIndex->setMinimumSize(QSize(0, 60));
        label_showSensorIndex->setMaximumSize(QSize(16777215, 60));

        gridLayout->addWidget(label_showSensorIndex, 2, 0, 1, 1);

        label_3 = new QLabel(LouKongProcessTool);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        pushButton = new QPushButton(LouKongProcessTool);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        pushButton_turnToDefaultSetting = new QPushButton(LouKongProcessTool);
        pushButton_turnToDefaultSetting->setObjectName("pushButton_turnToDefaultSetting");

        gridLayout->addWidget(pushButton_turnToDefaultSetting, 1, 1, 1, 1);


        retranslateUi(LouKongProcessTool);

        QMetaObject::connectSlotsByName(LouKongProcessTool);
    } // setupUi

    void retranslateUi(QWidget *LouKongProcessTool)
    {
        LouKongProcessTool->setWindowTitle(QCoreApplication::translate("LouKongProcessTool", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("LouKongProcessTool", "\347\247\273\344\275\215\346\226\271\345\274\217\357\274\232", nullptr));
        pushButton_confirmCurrentSetting->setText(QCoreApplication::translate("LouKongProcessTool", "\347\241\256\350\256\244\350\256\276\347\275\256", nullptr));
        label_4->setText(QCoreApplication::translate("LouKongProcessTool", "\350\241\245\345\201\277\345\200\215\346\225\260\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("LouKongProcessTool", "\351\200\211\346\213\251\350\246\201\350\256\276\347\275\256\347\232\204\351\200\232\351\201\223", nullptr));
        label_showSensorIndex->setText(QString());
        label_3->setText(QCoreApplication::translate("LouKongProcessTool", "\347\247\273\344\275\215\346\255\245\351\225\277\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("LouKongProcessTool", "\347\202\271\345\207\273\347\241\256\350\256\244\345\216\273\350\256\276\347\275\256", nullptr));
        pushButton_turnToDefaultSetting->setText(QCoreApplication::translate("LouKongProcessTool", "\345\210\235\345\247\213\345\214\226\344\270\272\351\273\230\350\256\244\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LouKongProcessTool: public Ui_LouKongProcessTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOUKONGPROCESSTOOL_H
