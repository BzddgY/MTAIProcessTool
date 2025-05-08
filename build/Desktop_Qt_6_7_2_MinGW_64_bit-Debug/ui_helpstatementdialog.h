/********************************************************************************
** Form generated from reading UI file 'helpstatementdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPSTATEMENTDIALOG_H
#define UI_HELPSTATEMENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_helpStatementDialog
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *helpStatementDialog)
    {
        if (helpStatementDialog->objectName().isEmpty())
            helpStatementDialog->setObjectName("helpStatementDialog");
        helpStatementDialog->resize(984, 580);
        gridLayout = new QGridLayout(helpStatementDialog);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 92, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(159, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        label = new QLabel(helpStatementDialog);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(159, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 92, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 4);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 4);
        gridLayout->setColumnStretch(2, 1);
        gridLayout->setColumnMinimumWidth(0, 1);
        gridLayout->setColumnMinimumWidth(1, 4);
        gridLayout->setColumnMinimumWidth(2, 1);
        gridLayout->setRowMinimumHeight(0, 1);
        gridLayout->setRowMinimumHeight(1, 4);
        gridLayout->setRowMinimumHeight(2, 1);

        retranslateUi(helpStatementDialog);

        QMetaObject::connectSlotsByName(helpStatementDialog);
    } // setupUi

    void retranslateUi(QDialog *helpStatementDialog)
    {
        helpStatementDialog->setWindowTitle(QCoreApplication::translate("helpStatementDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("helpStatementDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt;\">\350\277\231\344\270\252\350\275\257\344\273\266\345\217\257\344\273\245\347\224\250\346\235\245\345\256\236\347\216\260\345\276\256\346\263\242\347\203\255\345\243\260\346\210\220\345\203\217</span></p><p align=\"center\"><span style=\" font-size:20pt;\">\350\277\207\347\250\213\344\270\255\347\232\204\344\277\241\345\217\267\345\244\204\347\220\206\343\200\201\346\210\220\345\203\217\346\230\276\347\244\272\344\273\245\345\217\212\345\256\232\351\207\217\345\210\206\346\236\220\357\274\201</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class helpStatementDialog: public Ui_helpStatementDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPSTATEMENTDIALOG_H
