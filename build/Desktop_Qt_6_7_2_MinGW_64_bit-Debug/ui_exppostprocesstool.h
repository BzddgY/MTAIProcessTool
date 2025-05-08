/********************************************************************************
** Form generated from reading UI file 'exppostprocesstool.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPPOSTPROCESSTOOL_H
#define UI_EXPPOSTPROCESSTOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExpPostProcessTool
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QGridLayout *gridLayout;
    QLabel *label;

    void setupUi(QWidget *ExpPostProcessTool)
    {
        if (ExpPostProcessTool->objectName().isEmpty())
            ExpPostProcessTool->setObjectName("ExpPostProcessTool");
        ExpPostProcessTool->resize(249, 193);
        verticalLayout = new QVBoxLayout(ExpPostProcessTool);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(ExpPostProcessTool);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(ExpPostProcessTool);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(ExpPostProcessTool);

        QMetaObject::connectSlotsByName(ExpPostProcessTool);
    } // setupUi

    void retranslateUi(QWidget *ExpPostProcessTool)
    {
        ExpPostProcessTool->setWindowTitle(QCoreApplication::translate("ExpPostProcessTool", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("ExpPostProcessTool", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("ExpPostProcessTool", "<html><head/><body><p><span style=\" font-size:18pt;\">\345\256\232\351\207\217\345\220\216\345\244\204\347\220\206</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExpPostProcessTool: public Ui_ExpPostProcessTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPPOSTPROCESSTOOL_H
