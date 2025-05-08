/********************************************************************************
** Form generated from reading UI file 'expimagingmodule.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPIMAGINGMODULE_H
#define UI_EXPIMAGINGMODULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExpImagingModule
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *pushButton_preShowRayImagingTAI_2;
    QComboBox *comboBox_rayReconstructionType;
    QDoubleSpinBox *doubleSpinBox_y2;
    QDoubleSpinBox *doubleSpinBox_dy;
    QSpacerItem *horizontalSpacer_15;
    QSpacerItem *horizontalSpacer_14;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_21;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *spinBox_nonNegativeWidth;
    QLabel *label_5;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_10;
    QLabel *label;
    QPushButton *pushButton_preShowRayImagingTAI;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *horizontalSpacer_17;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_12;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_20;
    QLabel *label_9;
    QComboBox *comboBox_nonNegativeReconType;
    QDoubleSpinBox *doubleSpinBox_dx;
    QSpacerItem *horizontalSpacer_16;
    QDoubleSpinBox *doubleSpinBox_x2;
    QDoubleSpinBox *doubleSpinBox_y1;
    QSpacerItem *horizontalSpacer_19;
    QDoubleSpinBox *doubleSpinBox_x1;
    QCheckBox *checkBox;

    void setupUi(QWidget *ExpImagingModule)
    {
        if (ExpImagingModule->objectName().isEmpty())
            ExpImagingModule->setObjectName("ExpImagingModule");
        ExpImagingModule->resize(309, 366);
        verticalLayout = new QVBoxLayout(ExpImagingModule);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        pushButton_preShowRayImagingTAI_2 = new QPushButton(ExpImagingModule);
        pushButton_preShowRayImagingTAI_2->setObjectName("pushButton_preShowRayImagingTAI_2");

        gridLayout->addWidget(pushButton_preShowRayImagingTAI_2, 11, 0, 1, 1);

        comboBox_rayReconstructionType = new QComboBox(ExpImagingModule);
        comboBox_rayReconstructionType->setObjectName("comboBox_rayReconstructionType");

        gridLayout->addWidget(comboBox_rayReconstructionType, 7, 1, 1, 1);

        doubleSpinBox_y2 = new QDoubleSpinBox(ExpImagingModule);
        doubleSpinBox_y2->setObjectName("doubleSpinBox_y2");
        doubleSpinBox_y2->setMinimumSize(QSize(120, 0));
        doubleSpinBox_y2->setMaximumSize(QSize(120, 16777215));
        doubleSpinBox_y2->setMinimum(-9999.000000000000000);
        doubleSpinBox_y2->setMaximum(9999.000000000000000);
        doubleSpinBox_y2->setSingleStep(0.100000000000000);
        doubleSpinBox_y2->setValue(40.000000000000000);

        gridLayout->addWidget(doubleSpinBox_y2, 5, 1, 1, 1);

        doubleSpinBox_dy = new QDoubleSpinBox(ExpImagingModule);
        doubleSpinBox_dy->setObjectName("doubleSpinBox_dy");
        doubleSpinBox_dy->setMinimumSize(QSize(120, 0));
        doubleSpinBox_dy->setMaximumSize(QSize(120, 16777215));
        doubleSpinBox_dy->setMinimum(0.000000000000000);
        doubleSpinBox_dy->setMaximum(9999.000000000000000);
        doubleSpinBox_dy->setSingleStep(0.100000000000000);
        doubleSpinBox_dy->setValue(0.400000000000000);

        gridLayout->addWidget(doubleSpinBox_dy, 6, 1, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_15, 2, 4, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_14, 1, 4, 1, 1);

        label_3 = new QLabel(ExpImagingModule);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_2 = new QLabel(ExpImagingModule);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_4 = new QLabel(ExpImagingModule);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_21, 8, 4, 1, 1);

        label_7 = new QLabel(ExpImagingModule);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 4, 1, 1);

        spinBox_nonNegativeWidth = new QSpinBox(ExpImagingModule);
        spinBox_nonNegativeWidth->setObjectName("spinBox_nonNegativeWidth");
        spinBox_nonNegativeWidth->setMinimumSize(QSize(100, 0));
        spinBox_nonNegativeWidth->setMaximumSize(QSize(100, 16777215));
        spinBox_nonNegativeWidth->setMinimum(1);
        spinBox_nonNegativeWidth->setMaximum(9999);

        gridLayout->addWidget(spinBox_nonNegativeWidth, 10, 1, 1, 1);

        label_5 = new QLabel(ExpImagingModule);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_6 = new QLabel(ExpImagingModule);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_11, 10, 4, 1, 1);

        label_10 = new QLabel(ExpImagingModule);
        label_10->setObjectName("label_10");

        gridLayout->addWidget(label_10, 10, 0, 1, 1);

        label = new QLabel(ExpImagingModule);
        label->setObjectName("label");

        gridLayout->addWidget(label, 7, 0, 1, 1);

        pushButton_preShowRayImagingTAI = new QPushButton(ExpImagingModule);
        pushButton_preShowRayImagingTAI->setObjectName("pushButton_preShowRayImagingTAI");

        gridLayout->addWidget(pushButton_preShowRayImagingTAI, 8, 0, 1, 1);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_18, 4, 4, 1, 1);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_17, 3, 4, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 9, 4, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_12, 11, 4, 1, 1);

        label_8 = new QLabel(ExpImagingModule);
        label_8->setObjectName("label_8");

        gridLayout->addWidget(label_8, 6, 0, 1, 1);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_20, 6, 4, 1, 1);

        label_9 = new QLabel(ExpImagingModule);
        label_9->setObjectName("label_9");

        gridLayout->addWidget(label_9, 9, 0, 1, 1);

        comboBox_nonNegativeReconType = new QComboBox(ExpImagingModule);
        comboBox_nonNegativeReconType->setObjectName("comboBox_nonNegativeReconType");

        gridLayout->addWidget(comboBox_nonNegativeReconType, 9, 1, 1, 1);

        doubleSpinBox_dx = new QDoubleSpinBox(ExpImagingModule);
        doubleSpinBox_dx->setObjectName("doubleSpinBox_dx");
        doubleSpinBox_dx->setMinimumSize(QSize(120, 0));
        doubleSpinBox_dx->setMaximumSize(QSize(120, 16777215));
        doubleSpinBox_dx->setMinimum(0.000000000000000);
        doubleSpinBox_dx->setMaximum(9999.000000000000000);
        doubleSpinBox_dx->setSingleStep(0.100000000000000);
        doubleSpinBox_dx->setValue(0.400000000000000);

        gridLayout->addWidget(doubleSpinBox_dx, 3, 1, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_16, 7, 4, 1, 1);

        doubleSpinBox_x2 = new QDoubleSpinBox(ExpImagingModule);
        doubleSpinBox_x2->setObjectName("doubleSpinBox_x2");
        doubleSpinBox_x2->setMinimumSize(QSize(120, 0));
        doubleSpinBox_x2->setMaximumSize(QSize(120, 16777215));
        doubleSpinBox_x2->setMinimum(-9999.000000000000000);
        doubleSpinBox_x2->setMaximum(9999.000000000000000);
        doubleSpinBox_x2->setSingleStep(0.100000000000000);
        doubleSpinBox_x2->setValue(40.000000000000000);

        gridLayout->addWidget(doubleSpinBox_x2, 2, 1, 1, 1);

        doubleSpinBox_y1 = new QDoubleSpinBox(ExpImagingModule);
        doubleSpinBox_y1->setObjectName("doubleSpinBox_y1");
        doubleSpinBox_y1->setMinimumSize(QSize(120, 0));
        doubleSpinBox_y1->setMaximumSize(QSize(120, 16777215));
        doubleSpinBox_y1->setMinimum(-9999.000000000000000);
        doubleSpinBox_y1->setMaximum(9999.000000000000000);
        doubleSpinBox_y1->setSingleStep(0.100000000000000);
        doubleSpinBox_y1->setValue(-40.000000000000000);

        gridLayout->addWidget(doubleSpinBox_y1, 4, 1, 1, 1);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_19, 5, 4, 1, 1);

        doubleSpinBox_x1 = new QDoubleSpinBox(ExpImagingModule);
        doubleSpinBox_x1->setObjectName("doubleSpinBox_x1");
        doubleSpinBox_x1->setMinimumSize(QSize(120, 0));
        doubleSpinBox_x1->setMaximumSize(QSize(120, 16777215));
        doubleSpinBox_x1->setMinimum(-9999.000000000000000);
        doubleSpinBox_x1->setMaximum(9999.000000000000000);
        doubleSpinBox_x1->setSingleStep(0.100000000000000);
        doubleSpinBox_x1->setValue(-40.000000000000000);

        gridLayout->addWidget(doubleSpinBox_x1, 1, 1, 1, 1);

        checkBox = new QCheckBox(ExpImagingModule);
        checkBox->setObjectName("checkBox");

        gridLayout->addWidget(checkBox, 8, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(ExpImagingModule);

        QMetaObject::connectSlotsByName(ExpImagingModule);
    } // setupUi

    void retranslateUi(QWidget *ExpImagingModule)
    {
        ExpImagingModule->setWindowTitle(QCoreApplication::translate("ExpImagingModule", "Form", nullptr));
        pushButton_preShowRayImagingTAI_2->setText(QCoreApplication::translate("ExpImagingModule", "\351\242\204\350\247\210\351\235\236\350\264\237\345\217\215\346\274\224\345\233\276\345\203\217", nullptr));
        label_3->setText(QCoreApplication::translate("ExpImagingModule", "\346\250\252\350\275\264\350\265\267\345\247\213\344\275\215\347\275\256\345\235\220\346\240\207x1(mm)\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("ExpImagingModule", "\346\210\220\345\203\217\350\214\203\345\233\264\350\256\276\347\275\256\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("ExpImagingModule", "\346\250\252\350\275\264\347\273\210\346\255\242\344\275\215\347\275\256\345\235\220\346\240\207x2(mm)\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("ExpImagingModule", "\346\250\252\350\275\264\347\275\221\346\240\274\345\260\272\345\257\270dx(mm)\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("ExpImagingModule", "\347\272\265\350\275\264\350\265\267\345\247\213\344\275\215\347\275\256\345\235\220\346\240\207y1(mm)\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("ExpImagingModule", "\347\272\265\350\275\264\347\273\210\346\255\242\344\275\215\347\275\256\345\235\220\346\240\207y2(mm)\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("ExpImagingModule", "\350\260\203\346\225\264\351\235\236\350\264\237\346\210\220\345\203\217\346\227\266\347\232\204\344\277\241\345\217\267\345\256\275\345\272\246", nullptr));
        label->setText(QCoreApplication::translate("ExpImagingModule", "\345\237\272\344\272\216\345\260\204\347\272\277\347\232\204\346\227\266\351\227\264\345\217\215\346\212\225\345\275\261\347\256\227\346\263\225", nullptr));
        pushButton_preShowRayImagingTAI->setText(QCoreApplication::translate("ExpImagingModule", "\351\242\204\350\247\210\345\260\204\347\272\277\345\217\215\346\274\224\345\233\276\345\203\217", nullptr));
        label_8->setText(QCoreApplication::translate("ExpImagingModule", "\347\272\265\350\275\264\347\275\221\346\240\274\345\260\272\345\257\270dy(mm)\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("ExpImagingModule", "\351\235\236\350\264\237\346\210\220\345\203\217\346\226\271\345\274\217", nullptr));
        checkBox->setText(QCoreApplication::translate("ExpImagingModule", "\346\210\220\345\203\217\345\217\215\347\233\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExpImagingModule: public Ui_ExpImagingModule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPIMAGINGMODULE_H
