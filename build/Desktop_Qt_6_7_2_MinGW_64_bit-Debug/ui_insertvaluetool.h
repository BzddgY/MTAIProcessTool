/********************************************************************************
** Form generated from reading UI file 'insertvaluetool.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTVALUETOOL_H
#define UI_INSERTVALUETOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InsertValueTool
{
public:

    void setupUi(QWidget *InsertValueTool)
    {
        if (InsertValueTool->objectName().isEmpty())
            InsertValueTool->setObjectName("InsertValueTool");
        InsertValueTool->resize(400, 300);

        retranslateUi(InsertValueTool);

        QMetaObject::connectSlotsByName(InsertValueTool);
    } // setupUi

    void retranslateUi(QWidget *InsertValueTool)
    {
        InsertValueTool->setWindowTitle(QCoreApplication::translate("InsertValueTool", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InsertValueTool: public Ui_InsertValueTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTVALUETOOL_H
