/********************************************************************************
** Form generated from reading UI file 'deconvolutiontool.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DECONVOLUTIONTOOL_H
#define UI_DECONVOLUTIONTOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeconvolutionTool
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QComboBox *comboBox_loadType;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;

    void setupUi(QWidget *DeconvolutionTool)
    {
        if (DeconvolutionTool->objectName().isEmpty())
            DeconvolutionTool->setObjectName("DeconvolutionTool");
        DeconvolutionTool->resize(216, 149);
        verticalLayout = new QVBoxLayout(DeconvolutionTool);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(DeconvolutionTool);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(DeconvolutionTool);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(DeconvolutionTool);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        comboBox_loadType = new QComboBox(DeconvolutionTool);
        comboBox_loadType->setObjectName("comboBox_loadType");

        verticalLayout->addWidget(comboBox_loadType);

        pushButton_3 = new QPushButton(DeconvolutionTool);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(DeconvolutionTool);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);


        retranslateUi(DeconvolutionTool);

        QMetaObject::connectSlotsByName(DeconvolutionTool);
    } // setupUi

    void retranslateUi(QWidget *DeconvolutionTool)
    {
        DeconvolutionTool->setWindowTitle(QCoreApplication::translate("DeconvolutionTool", "Form", nullptr));
        label->setText(QCoreApplication::translate("DeconvolutionTool", "<html><head/><body><p align=\"center\">\345\257\274\345\205\245\344\274\260\350\256\241EIR\346\225\260\346\215\256\346\226\207\344\273\266\345\234\260\345\235\200\357\274\232</p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("DeconvolutionTool", "\347\202\271\345\207\273\350\216\267\345\217\226\345\234\260\345\235\200", nullptr));
        pushButton_3->setText(QCoreApplication::translate("DeconvolutionTool", "\347\202\271\345\207\273\345\257\274\345\205\245EIR\346\225\260\346\215\256", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DeconvolutionTool", "\351\242\204\350\247\210\345\257\274\345\205\245EIR\346\233\262\347\272\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeconvolutionTool: public Ui_DeconvolutionTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DECONVOLUTIONTOOL_H
