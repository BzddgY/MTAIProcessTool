/********************************************************************************
** Form generated from reading UI file 'dragresizewgt.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAGRESIZEWGT_H
#define UI_DRAGRESIZEWGT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DragResizeWgt
{
public:

    void setupUi(QWidget *DragResizeWgt)
    {
        if (DragResizeWgt->objectName().isEmpty())
            DragResizeWgt->setObjectName("DragResizeWgt");
        DragResizeWgt->resize(400, 300);

        retranslateUi(DragResizeWgt);

        QMetaObject::connectSlotsByName(DragResizeWgt);
    } // setupUi

    void retranslateUi(QWidget *DragResizeWgt)
    {
        DragResizeWgt->setWindowTitle(QCoreApplication::translate("DragResizeWgt", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DragResizeWgt: public Ui_DragResizeWgt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAGRESIZEWGT_H
