/********************************************************************************
** Form generated from reading UI file 'expsignalprocesstool.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPSIGNALPROCESSTOOL_H
#define UI_EXPSIGNALPROCESSTOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExpSignalProcessTool
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QPushButton *pushButton_plotSingleRFData_PreDomain;
    QPushButton *pushButton_loadRFData;
    QPushButton *pushButton_plotAllRFData;
    QToolButton *toolButton_confirmSelectedSensorIndex;
    QLabel *label_2;
    QSpinBox *spinBox_selectedSensorIndex;
    QComboBox *comboBox_RFDataLoadType;
    QPushButton *pushButton_plotSingleRFData;
    QLabel *label_4;
    QFormLayout *formLayout_2;
    QPushButton *pushButton_preProcessRFData;
    QPushButton *pushButton_plotAllPreProcessRFData;
    QPushButton *pushButton_savePreProcessRFData;
    QPushButton *pushButton_plotSinglePreProcessedRFData;
    QPushButton *pushButton_plotSingleBeforeAndAfterRFData;
    QPushButton *pushButton_plotSingleBeforeAndAfterRFData_FreDomain;
    QPushButton *pushButton_plotSinglePreProcessedRFData_FreDomain;
    QSpacerItem *horizontalSpacer_10;
    QGridLayout *gridLayout_2;
    QCheckBox *checkBox_isHilbertTransform;
    QLabel *label_7;
    QLabel *label_6;
    QToolButton *toolButton_setLouKongProcessPara;
    QToolButton *toolButton_setFilterPara;
    QCheckBox *checkBox_isFilter;
    QSpinBox *spinBox_cutZerosTimesteps;
    QCheckBox *checkBox_isCutZeros;
    QComboBox *comboBox_deConvolutionType;
    QCheckBox *checkBox_isLouKong;
    QComboBox *comboBox_insertValueType;
    QComboBox *comboBox_filterType;
    QCheckBox *checkBox_isDeconvolution;
    QLabel *label_9;
    QLabel *label_5;
    QToolButton *toolButton_setDeconvolutionPara;
    QLabel *label_8;
    QCheckBox *checkBox_isInsertValue;
    QToolButton *toolButton_setInsertValuePara;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_9;

    void setupUi(QWidget *ExpSignalProcessTool)
    {
        if (ExpSignalProcessTool->objectName().isEmpty())
            ExpSignalProcessTool->setObjectName("ExpSignalProcessTool");
        ExpSignalProcessTool->resize(493, 604);
        verticalLayout = new QVBoxLayout(ExpSignalProcessTool);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        pushButton_plotSingleRFData_PreDomain = new QPushButton(ExpSignalProcessTool);
        pushButton_plotSingleRFData_PreDomain->setObjectName("pushButton_plotSingleRFData_PreDomain");

        gridLayout->addWidget(pushButton_plotSingleRFData_PreDomain, 6, 1, 1, 1);

        pushButton_loadRFData = new QPushButton(ExpSignalProcessTool);
        pushButton_loadRFData->setObjectName("pushButton_loadRFData");

        gridLayout->addWidget(pushButton_loadRFData, 1, 1, 1, 1);

        pushButton_plotAllRFData = new QPushButton(ExpSignalProcessTool);
        pushButton_plotAllRFData->setObjectName("pushButton_plotAllRFData");

        gridLayout->addWidget(pushButton_plotAllRFData, 2, 1, 1, 1);

        toolButton_confirmSelectedSensorIndex = new QToolButton(ExpSignalProcessTool);
        toolButton_confirmSelectedSensorIndex->setObjectName("toolButton_confirmSelectedSensorIndex");

        gridLayout->addWidget(toolButton_confirmSelectedSensorIndex, 4, 2, 1, 1);

        label_2 = new QLabel(ExpSignalProcessTool);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        spinBox_selectedSensorIndex = new QSpinBox(ExpSignalProcessTool);
        spinBox_selectedSensorIndex->setObjectName("spinBox_selectedSensorIndex");
        spinBox_selectedSensorIndex->setMinimum(1);
        spinBox_selectedSensorIndex->setMaximum(999);

        gridLayout->addWidget(spinBox_selectedSensorIndex, 4, 1, 1, 1);

        comboBox_RFDataLoadType = new QComboBox(ExpSignalProcessTool);
        comboBox_RFDataLoadType->setObjectName("comboBox_RFDataLoadType");

        gridLayout->addWidget(comboBox_RFDataLoadType, 0, 1, 1, 1);

        pushButton_plotSingleRFData = new QPushButton(ExpSignalProcessTool);
        pushButton_plotSingleRFData->setObjectName("pushButton_plotSingleRFData");

        gridLayout->addWidget(pushButton_plotSingleRFData, 5, 1, 1, 1);

        label_4 = new QLabel(ExpSignalProcessTool);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 4, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        pushButton_preProcessRFData = new QPushButton(ExpSignalProcessTool);
        pushButton_preProcessRFData->setObjectName("pushButton_preProcessRFData");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, pushButton_preProcessRFData);

        pushButton_plotAllPreProcessRFData = new QPushButton(ExpSignalProcessTool);
        pushButton_plotAllPreProcessRFData->setObjectName("pushButton_plotAllPreProcessRFData");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, pushButton_plotAllPreProcessRFData);

        pushButton_savePreProcessRFData = new QPushButton(ExpSignalProcessTool);
        pushButton_savePreProcessRFData->setObjectName("pushButton_savePreProcessRFData");

        formLayout_2->setWidget(2, QFormLayout::LabelRole, pushButton_savePreProcessRFData);

        pushButton_plotSinglePreProcessedRFData = new QPushButton(ExpSignalProcessTool);
        pushButton_plotSinglePreProcessedRFData->setObjectName("pushButton_plotSinglePreProcessedRFData");

        formLayout_2->setWidget(3, QFormLayout::LabelRole, pushButton_plotSinglePreProcessedRFData);

        pushButton_plotSingleBeforeAndAfterRFData = new QPushButton(ExpSignalProcessTool);
        pushButton_plotSingleBeforeAndAfterRFData->setObjectName("pushButton_plotSingleBeforeAndAfterRFData");

        formLayout_2->setWidget(5, QFormLayout::LabelRole, pushButton_plotSingleBeforeAndAfterRFData);

        pushButton_plotSingleBeforeAndAfterRFData_FreDomain = new QPushButton(ExpSignalProcessTool);
        pushButton_plotSingleBeforeAndAfterRFData_FreDomain->setObjectName("pushButton_plotSingleBeforeAndAfterRFData_FreDomain");

        formLayout_2->setWidget(6, QFormLayout::LabelRole, pushButton_plotSingleBeforeAndAfterRFData_FreDomain);

        pushButton_plotSinglePreProcessedRFData_FreDomain = new QPushButton(ExpSignalProcessTool);
        pushButton_plotSinglePreProcessedRFData_FreDomain->setObjectName("pushButton_plotSinglePreProcessedRFData_FreDomain");

        formLayout_2->setWidget(4, QFormLayout::LabelRole, pushButton_plotSinglePreProcessedRFData_FreDomain);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        formLayout_2->setItem(3, QFormLayout::FieldRole, horizontalSpacer_10);


        horizontalLayout->addLayout(formLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        checkBox_isHilbertTransform = new QCheckBox(ExpSignalProcessTool);
        checkBox_isHilbertTransform->setObjectName("checkBox_isHilbertTransform");

        gridLayout_2->addWidget(checkBox_isHilbertTransform, 7, 7, 1, 1);

        label_7 = new QLabel(ExpSignalProcessTool);
        label_7->setObjectName("label_7");

        gridLayout_2->addWidget(label_7, 3, 3, 1, 1);

        label_6 = new QLabel(ExpSignalProcessTool);
        label_6->setObjectName("label_6");

        gridLayout_2->addWidget(label_6, 0, 3, 1, 1);

        toolButton_setLouKongProcessPara = new QToolButton(ExpSignalProcessTool);
        toolButton_setLouKongProcessPara->setObjectName("toolButton_setLouKongProcessPara");

        gridLayout_2->addWidget(toolButton_setLouKongProcessPara, 5, 6, 1, 1);

        toolButton_setFilterPara = new QToolButton(ExpSignalProcessTool);
        toolButton_setFilterPara->setObjectName("toolButton_setFilterPara");

        gridLayout_2->addWidget(toolButton_setFilterPara, 0, 6, 1, 1);

        checkBox_isFilter = new QCheckBox(ExpSignalProcessTool);
        checkBox_isFilter->setObjectName("checkBox_isFilter");
        checkBox_isFilter->setTristate(true);

        gridLayout_2->addWidget(checkBox_isFilter, 0, 7, 1, 1);

        spinBox_cutZerosTimesteps = new QSpinBox(ExpSignalProcessTool);
        spinBox_cutZerosTimesteps->setObjectName("spinBox_cutZerosTimesteps");
        spinBox_cutZerosTimesteps->setMinimumSize(QSize(100, 25));
        spinBox_cutZerosTimesteps->setMaximumSize(QSize(100, 25));
        spinBox_cutZerosTimesteps->setMinimum(0);
        spinBox_cutZerosTimesteps->setMaximum(4096);
        spinBox_cutZerosTimesteps->setValue(800);

        gridLayout_2->addWidget(spinBox_cutZerosTimesteps, 3, 4, 1, 1);

        checkBox_isCutZeros = new QCheckBox(ExpSignalProcessTool);
        checkBox_isCutZeros->setObjectName("checkBox_isCutZeros");
        checkBox_isCutZeros->setTristate(true);

        gridLayout_2->addWidget(checkBox_isCutZeros, 3, 7, 1, 1);

        comboBox_deConvolutionType = new QComboBox(ExpSignalProcessTool);
        comboBox_deConvolutionType->setObjectName("comboBox_deConvolutionType");
        comboBox_deConvolutionType->setMinimumSize(QSize(100, 0));
        comboBox_deConvolutionType->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(comboBox_deConvolutionType, 2, 4, 1, 1);

        checkBox_isLouKong = new QCheckBox(ExpSignalProcessTool);
        checkBox_isLouKong->setObjectName("checkBox_isLouKong");
        checkBox_isLouKong->setTristate(true);

        gridLayout_2->addWidget(checkBox_isLouKong, 5, 7, 1, 1);

        comboBox_insertValueType = new QComboBox(ExpSignalProcessTool);
        comboBox_insertValueType->setObjectName("comboBox_insertValueType");
        comboBox_insertValueType->setMinimumSize(QSize(100, 0));
        comboBox_insertValueType->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(comboBox_insertValueType, 6, 4, 1, 1);

        comboBox_filterType = new QComboBox(ExpSignalProcessTool);
        comboBox_filterType->setObjectName("comboBox_filterType");
        comboBox_filterType->setMinimumSize(QSize(100, 0));
        comboBox_filterType->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(comboBox_filterType, 0, 4, 1, 1);

        checkBox_isDeconvolution = new QCheckBox(ExpSignalProcessTool);
        checkBox_isDeconvolution->setObjectName("checkBox_isDeconvolution");
        checkBox_isDeconvolution->setTristate(true);

        gridLayout_2->addWidget(checkBox_isDeconvolution, 2, 7, 1, 1);

        label_9 = new QLabel(ExpSignalProcessTool);
        label_9->setObjectName("label_9");

        gridLayout_2->addWidget(label_9, 5, 3, 1, 1);

        label_5 = new QLabel(ExpSignalProcessTool);
        label_5->setObjectName("label_5");

        gridLayout_2->addWidget(label_5, 2, 3, 1, 1);

        toolButton_setDeconvolutionPara = new QToolButton(ExpSignalProcessTool);
        toolButton_setDeconvolutionPara->setObjectName("toolButton_setDeconvolutionPara");

        gridLayout_2->addWidget(toolButton_setDeconvolutionPara, 2, 6, 1, 1);

        label_8 = new QLabel(ExpSignalProcessTool);
        label_8->setObjectName("label_8");

        gridLayout_2->addWidget(label_8, 6, 3, 1, 1);

        checkBox_isInsertValue = new QCheckBox(ExpSignalProcessTool);
        checkBox_isInsertValue->setObjectName("checkBox_isInsertValue");
        checkBox_isInsertValue->setTristate(true);

        gridLayout_2->addWidget(checkBox_isInsertValue, 6, 7, 1, 1);

        toolButton_setInsertValuePara = new QToolButton(ExpSignalProcessTool);
        toolButton_setInsertValuePara->setObjectName("toolButton_setInsertValuePara");

        gridLayout_2->addWidget(toolButton_setInsertValuePara, 6, 6, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 0, 8, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 2, 8, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 3, 8, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_8, 5, 8, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_9, 6, 8, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        retranslateUi(ExpSignalProcessTool);

        QMetaObject::connectSlotsByName(ExpSignalProcessTool);
    } // setupUi

    void retranslateUi(QWidget *ExpSignalProcessTool)
    {
        ExpSignalProcessTool->setWindowTitle(QCoreApplication::translate("ExpSignalProcessTool", "Form", nullptr));
        pushButton_plotSingleRFData_PreDomain->setText(QCoreApplication::translate("ExpSignalProcessTool", "\345\215\225\351\200\232\351\201\223RF\346\225\260\346\215\256\351\242\221\345\237\237\347\273\230\345\210\266", nullptr));
        pushButton_loadRFData->setText(QCoreApplication::translate("ExpSignalProcessTool", "\345\257\274\345\205\245RF\346\225\260\346\215\256", nullptr));
        pushButton_plotAllRFData->setText(QCoreApplication::translate("ExpSignalProcessTool", "RF\346\225\260\346\215\256\351\242\204\350\247\210", nullptr));
        toolButton_confirmSelectedSensorIndex->setText(QString());
        label_2->setText(QCoreApplication::translate("ExpSignalProcessTool", "\345\257\274\345\205\245\346\226\271\345\274\217", nullptr));
        pushButton_plotSingleRFData->setText(QCoreApplication::translate("ExpSignalProcessTool", "\345\215\225\351\200\232\351\201\223RF\346\225\260\346\215\256\346\227\266\345\237\237\347\273\230\345\210\266", nullptr));
        label_4->setText(QCoreApplication::translate("ExpSignalProcessTool", "\351\200\211\346\213\251\345\215\225\351\200\232\351\201\223", nullptr));
        pushButton_preProcessRFData->setText(QCoreApplication::translate("ExpSignalProcessTool", "\351\242\204\345\244\204\347\220\206RF\346\225\260\346\215\256", nullptr));
        pushButton_plotAllPreProcessRFData->setText(QCoreApplication::translate("ExpSignalProcessTool", "\351\242\204\345\244\204\347\220\206\345\220\216\347\232\204RF\346\225\260\346\215\256\351\242\204\350\247\210", nullptr));
        pushButton_savePreProcessRFData->setText(QCoreApplication::translate("ExpSignalProcessTool", "\344\277\235\345\255\230\351\242\204\345\244\204\347\220\206\345\220\216\347\232\204RF\346\225\260\346\215\256", nullptr));
        pushButton_plotSinglePreProcessedRFData->setText(QCoreApplication::translate("ExpSignalProcessTool", "\345\215\225\351\200\232\351\201\223\351\242\204\345\244\204\347\220\206\345\220\216RF\346\225\260\346\215\256\346\227\266\345\237\237\347\273\230\345\210\266", nullptr));
        pushButton_plotSingleBeforeAndAfterRFData->setText(QCoreApplication::translate("ExpSignalProcessTool", "\345\215\225\351\200\232\351\201\223\351\242\204\345\244\204\347\220\206\345\211\215\345\220\216\346\227\266\345\237\237\345\257\271\346\257\224\347\273\230\345\210\266", nullptr));
        pushButton_plotSingleBeforeAndAfterRFData_FreDomain->setText(QCoreApplication::translate("ExpSignalProcessTool", "\345\215\225\351\200\232\351\201\223\351\242\204\345\244\204\347\220\206\345\211\215\345\220\216\351\242\221\345\237\237\345\257\271\346\257\224\347\273\230\345\210\266", nullptr));
        pushButton_plotSinglePreProcessedRFData_FreDomain->setText(QCoreApplication::translate("ExpSignalProcessTool", "\345\215\225\351\200\232\351\201\223\351\242\204\345\244\204\347\220\206\345\220\216RF\346\225\260\346\215\256\351\242\221\345\237\237\347\273\230\345\210\266", nullptr));
        checkBox_isHilbertTransform->setText(QCoreApplication::translate("ExpSignalProcessTool", "\345\270\214\345\260\224\344\274\257\347\211\271\345\217\230\346\215\242\345\244\204\347\220\206", nullptr));
        label_7->setText(QCoreApplication::translate("ExpSignalProcessTool", "\347\275\256\351\233\266\346\227\266\351\227\264\346\255\245\351\225\277", nullptr));
        label_6->setText(QCoreApplication::translate("ExpSignalProcessTool", "\346\273\244\346\263\242\346\226\271\345\274\217", nullptr));
        toolButton_setLouKongProcessPara->setText(QString());
        toolButton_setFilterPara->setText(QString());
        checkBox_isFilter->setText(QString());
        checkBox_isCutZeros->setText(QString());
        checkBox_isLouKong->setText(QString());
        checkBox_isDeconvolution->setText(QString());
        label_9->setText(QCoreApplication::translate("ExpSignalProcessTool", "\351\225\202\347\251\272\351\230\265\345\210\227\345\244\204\347\220\206\350\256\276\347\275\256", nullptr));
        label_5->setText(QCoreApplication::translate("ExpSignalProcessTool", "\345\216\273\345\215\267\347\247\257\346\226\271\345\274\217", nullptr));
        toolButton_setDeconvolutionPara->setText(QString());
        label_8->setText(QCoreApplication::translate("ExpSignalProcessTool", "\346\217\222\345\200\274\346\226\271\345\274\217", nullptr));
        checkBox_isInsertValue->setText(QString());
        toolButton_setInsertValuePara->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ExpSignalProcessTool: public Ui_ExpSignalProcessTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPSIGNALPROCESSTOOL_H
