/********************************************************************************
** Form generated from reading UI file 'logviewer.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGVIEWER_H
#define UI_LOGVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_logViewer
{
public:
    QGridLayout *gridLayout;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *logViewer)
    {
        if (logViewer->objectName().isEmpty())
            logViewer->setObjectName("logViewer");
        logViewer->resize(400, 300);
        gridLayout = new QGridLayout(logViewer);
        gridLayout->setObjectName("gridLayout");
        plainTextEdit = new QPlainTextEdit(logViewer);
        plainTextEdit->setObjectName("plainTextEdit");

        gridLayout->addWidget(plainTextEdit, 0, 0, 1, 1);


        retranslateUi(logViewer);

        QMetaObject::connectSlotsByName(logViewer);
    } // setupUi

    void retranslateUi(QWidget *logViewer)
    {
        logViewer->setWindowTitle(QCoreApplication::translate("logViewer", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class logViewer: public Ui_logViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGVIEWER_H
