/********************************************************************************
** Form generated from reading UI file 'filtertoolsettingdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERTOOLSETTINGDIALOG_H
#define UI_FILTERTOOLSETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>

QT_BEGIN_NAMESPACE

class Ui_FilterToolSettingDialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;

    void setupUi(QDialog *FilterToolSettingDialog)
    {
        if (FilterToolSettingDialog->objectName().isEmpty())
            FilterToolSettingDialog->setObjectName("FilterToolSettingDialog");
        FilterToolSettingDialog->resize(424, 377);
        gridLayout_2 = new QGridLayout(FilterToolSettingDialog);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");

        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(FilterToolSettingDialog);

        QMetaObject::connectSlotsByName(FilterToolSettingDialog);
    } // setupUi

    void retranslateUi(QDialog *FilterToolSettingDialog)
    {
        FilterToolSettingDialog->setWindowTitle(QCoreApplication::translate("FilterToolSettingDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FilterToolSettingDialog: public Ui_FilterToolSettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERTOOLSETTINGDIALOG_H
