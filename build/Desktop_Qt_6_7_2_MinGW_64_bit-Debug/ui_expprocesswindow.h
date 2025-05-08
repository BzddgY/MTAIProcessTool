/********************************************************************************
** Form generated from reading UI file 'expprocesswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPPROCESSWINDOW_H
#define UI_EXPPROCESSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExpProcessWindow
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_signalPreProcess;
    QLabel *label_3;
    QWidget *widget_imaging;
    QLabel *label_4;
    QWidget *widget_postAnalyze;
    QLabel *label_5;

    void setupUi(QWidget *ExpProcessWindow)
    {
        if (ExpProcessWindow->objectName().isEmpty())
            ExpProcessWindow->setObjectName("ExpProcessWindow");
        ExpProcessWindow->resize(831, 556);
        verticalLayout = new QVBoxLayout(ExpProcessWindow);
        verticalLayout->setObjectName("verticalLayout");
        widget_signalPreProcess = new QWidget(ExpProcessWindow);
        widget_signalPreProcess->setObjectName("widget_signalPreProcess");
        label_3 = new QLabel(widget_signalPreProcess);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 0, 81, 31));

        verticalLayout->addWidget(widget_signalPreProcess);

        widget_imaging = new QWidget(ExpProcessWindow);
        widget_imaging->setObjectName("widget_imaging");
        label_4 = new QLabel(widget_imaging);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 0, 81, 31));

        verticalLayout->addWidget(widget_imaging);

        widget_postAnalyze = new QWidget(ExpProcessWindow);
        widget_postAnalyze->setObjectName("widget_postAnalyze");
        label_5 = new QLabel(widget_postAnalyze);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 0, 81, 31));

        verticalLayout->addWidget(widget_postAnalyze);


        retranslateUi(ExpProcessWindow);

        QMetaObject::connectSlotsByName(ExpProcessWindow);
    } // setupUi

    void retranslateUi(QWidget *ExpProcessWindow)
    {
        ExpProcessWindow->setWindowTitle(QCoreApplication::translate("ExpProcessWindow", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("ExpProcessWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:700;\">\344\277\241\345\217\267\351\242\204\345\244\204\347\220\206</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("ExpProcessWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:700;\">\345\217\215\346\274\224\346\210\220\345\203\217</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("ExpProcessWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:700;\">\345\256\232\351\207\217\345\210\206\346\236\220</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExpProcessWindow: public Ui_ExpProcessWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPPROCESSWINDOW_H
