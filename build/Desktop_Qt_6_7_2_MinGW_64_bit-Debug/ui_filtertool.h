/********************************************************************************
** Form generated from reading UI file 'filtertool.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERTOOL_H
#define UI_FILTERTOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilterTool
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_preShowFilterWindow;
    QDoubleSpinBox *doubleSpinBox_FPass;
    QDoubleSpinBox *doubleSpinBox_FStop;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_beta;
    QLabel *label_6;
    QLabel *label_5;
    QComboBox *comboBox_preShowFilterType;
    QSpinBox *spinBox_Fs;
    QPushButton *pushButton_adjustM;
    QSpinBox *spinBox_M;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_7;
    QCheckBox *checkBox;

    void setupUi(QWidget *FilterTool)
    {
        if (FilterTool->objectName().isEmpty())
            FilterTool->setObjectName("FilterTool");
        FilterTool->resize(556, 380);
        gridLayout = new QGridLayout(FilterTool);
        gridLayout->setObjectName("gridLayout");
        pushButton_preShowFilterWindow = new QPushButton(FilterTool);
        pushButton_preShowFilterWindow->setObjectName("pushButton_preShowFilterWindow");

        gridLayout->addWidget(pushButton_preShowFilterWindow, 0, 3, 1, 1);

        doubleSpinBox_FPass = new QDoubleSpinBox(FilterTool);
        doubleSpinBox_FPass->setObjectName("doubleSpinBox_FPass");
        doubleSpinBox_FPass->setMaximum(999.000000000000000);
        doubleSpinBox_FPass->setSingleStep(0.100000000000000);
        doubleSpinBox_FPass->setValue(2.500000000000000);

        gridLayout->addWidget(doubleSpinBox_FPass, 5, 2, 1, 1);

        doubleSpinBox_FStop = new QDoubleSpinBox(FilterTool);
        doubleSpinBox_FStop->setObjectName("doubleSpinBox_FStop");
        doubleSpinBox_FStop->setMaximum(9999.000000000000000);
        doubleSpinBox_FStop->setSingleStep(0.100000000000000);
        doubleSpinBox_FStop->setValue(10.000000000000000);

        gridLayout->addWidget(doubleSpinBox_FStop, 6, 2, 1, 1);

        label_4 = new QLabel(FilterTool);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 3, 1, 1, 1);

        doubleSpinBox_beta = new QDoubleSpinBox(FilterTool);
        doubleSpinBox_beta->setObjectName("doubleSpinBox_beta");
        doubleSpinBox_beta->setSingleStep(0.100000000000000);
        doubleSpinBox_beta->setValue(8.500000000000000);

        gridLayout->addWidget(doubleSpinBox_beta, 3, 2, 1, 1);

        label_6 = new QLabel(FilterTool);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 6, 1, 1, 1);

        label_5 = new QLabel(FilterTool);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 5, 1, 1, 1);

        comboBox_preShowFilterType = new QComboBox(FilterTool);
        comboBox_preShowFilterType->setObjectName("comboBox_preShowFilterType");

        gridLayout->addWidget(comboBox_preShowFilterType, 0, 2, 1, 1);

        spinBox_Fs = new QSpinBox(FilterTool);
        spinBox_Fs->setObjectName("spinBox_Fs");
        spinBox_Fs->setMinimum(1);
        spinBox_Fs->setMaximum(9999);
        spinBox_Fs->setValue(40);

        gridLayout->addWidget(spinBox_Fs, 2, 2, 1, 1);

        pushButton_adjustM = new QPushButton(FilterTool);
        pushButton_adjustM->setObjectName("pushButton_adjustM");

        gridLayout->addWidget(pushButton_adjustM, 5, 3, 1, 1);

        spinBox_M = new QSpinBox(FilterTool);
        spinBox_M->setObjectName("spinBox_M");
        spinBox_M->setMinimum(1);
        spinBox_M->setMaximum(4096);
        spinBox_M->setValue(15);

        gridLayout->addWidget(spinBox_M, 1, 2, 1, 1);

        label_3 = new QLabel(FilterTool);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        label = new QLabel(FilterTool);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_2 = new QLabel(FilterTool);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        label_7 = new QLabel(FilterTool);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 4, 1, 1, 1);

        checkBox = new QCheckBox(FilterTool);
        checkBox->setObjectName("checkBox");

        gridLayout->addWidget(checkBox, 4, 2, 1, 1);


        retranslateUi(FilterTool);

        QMetaObject::connectSlotsByName(FilterTool);
    } // setupUi

    void retranslateUi(QWidget *FilterTool)
    {
        FilterTool->setWindowTitle(QCoreApplication::translate("FilterTool", "Form", nullptr));
        pushButton_preShowFilterWindow->setText(QCoreApplication::translate("FilterTool", "\347\202\271\345\207\273\351\242\204\350\247\210\346\211\200\350\256\276\347\275\256\347\252\227\345\207\275\346\225\260", nullptr));
        label_4->setText(QCoreApplication::translate("FilterTool", "\345\207\257\347\221\237\345\260\224\347\252\227\347\232\204\316\262\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_6->setText(QCoreApplication::translate("FilterTool", "\346\210\252\346\255\242\351\242\221\347\216\207fS(MHz)\350\256\276\347\275\256", nullptr));
        label_5->setText(QCoreApplication::translate("FilterTool", "\351\200\232\345\270\246\351\242\221\347\216\207fP(MHz)\350\256\276\347\275\256", nullptr));
        pushButton_adjustM->setText(QCoreApplication::translate("FilterTool", "\347\202\271\345\207\273\350\207\252\351\200\202\345\272\224\350\256\241\347\256\227M", nullptr));
        label_3->setText(QCoreApplication::translate("FilterTool", "\351\207\207\346\240\267\351\242\221\347\216\207(MHz)", nullptr));
        label->setText(QCoreApplication::translate("FilterTool", "\346\273\244\346\263\242\347\252\227\345\207\275\346\225\260\351\242\204\350\247\210", nullptr));
        label_2->setText(QCoreApplication::translate("FilterTool", "\346\273\244\346\263\242\345\231\250\351\230\266\346\225\260M\350\256\276\347\275\256", nullptr));
        label_7->setText(QCoreApplication::translate("FilterTool", "\351\200\232\350\277\207\350\256\276\347\275\256\351\200\232\345\270\246\351\242\221\347\216\207\345\222\214\346\210\252\346\255\242\351\242\221\347\216\207\350\207\252\351\200\202\345\272\224\350\256\241\347\256\227\346\273\244\346\263\242\345\231\250\351\230\266\346\225\260", nullptr));
        checkBox->setText(QCoreApplication::translate("FilterTool", "\346\230\257\345\220\246\350\207\252\351\200\202\345\272\224\350\256\241\347\256\227M", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FilterTool: public Ui_FilterTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERTOOL_H
