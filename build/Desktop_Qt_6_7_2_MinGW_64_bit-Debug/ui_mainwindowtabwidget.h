/********************************************************************************
** Form generated from reading UI file 'mainwindowtabwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWTABWIDGET_H
#define UI_MAINWINDOWTABWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowTabWidget
{
public:
    QWidget *startWindow;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_logo;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_statement;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QWidget *experimentModule;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *expBasicSettingLayout;
    QGridLayout *expProcessLayout;
    QGridLayout *expImagingLayout;
    QWidget *simulationModule;

    void setupUi(QTabWidget *MainWindowTabWidget)
    {
        if (MainWindowTabWidget->objectName().isEmpty())
            MainWindowTabWidget->setObjectName("MainWindowTabWidget");
        MainWindowTabWidget->resize(1100, 591);
        MainWindowTabWidget->setMinimumSize(QSize(1100, 0));
        startWindow = new QWidget();
        startWindow->setObjectName("startWindow");
        gridLayout = new QGridLayout(startWindow);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 50, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(241, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        label_logo = new QLabel(startWindow);
        label_logo->setObjectName("label_logo");
        label_logo->setMinimumSize(QSize(40, 40));
        label_logo->setMaximumSize(QSize(40, 40));
        label_logo->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_logo->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_logo, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(241, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(241, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 0, 1, 1);

        label_statement = new QLabel(startWindow);
        label_statement->setObjectName("label_statement");

        gridLayout->addWidget(label_statement, 2, 1, 1, 2);

        horizontalSpacer_4 = new QSpacerItem(241, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 2, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 50, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 2);
        gridLayout->setRowStretch(2, 8);
        gridLayout->setRowStretch(3, 1);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 2);
        gridLayout->setColumnStretch(2, 8);
        gridLayout->setColumnStretch(3, 1);
        MainWindowTabWidget->addTab(startWindow, QString());
        experimentModule = new QWidget();
        experimentModule->setObjectName("experimentModule");
        experimentModule->setMinimumSize(QSize(1000, 0));
        horizontalLayout = new QHBoxLayout(experimentModule);
        horizontalLayout->setObjectName("horizontalLayout");
        expBasicSettingLayout = new QVBoxLayout();
        expBasicSettingLayout->setObjectName("expBasicSettingLayout");

        horizontalLayout->addLayout(expBasicSettingLayout);

        expProcessLayout = new QGridLayout();
        expProcessLayout->setObjectName("expProcessLayout");

        horizontalLayout->addLayout(expProcessLayout);

        expImagingLayout = new QGridLayout();
        expImagingLayout->setObjectName("expImagingLayout");

        horizontalLayout->addLayout(expImagingLayout);

        horizontalLayout->setStretch(0, 7);
        horizontalLayout->setStretch(1, 8);
        horizontalLayout->setStretch(2, 6);
        MainWindowTabWidget->addTab(experimentModule, QString());
        simulationModule = new QWidget();
        simulationModule->setObjectName("simulationModule");
        MainWindowTabWidget->addTab(simulationModule, QString());

        retranslateUi(MainWindowTabWidget);

        MainWindowTabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindowTabWidget);
    } // setupUi

    void retranslateUi(QTabWidget *MainWindowTabWidget)
    {
        MainWindowTabWidget->setWindowTitle(QCoreApplication::translate("MainWindowTabWidget", "TabWidget", nullptr));
        label_logo->setText(QCoreApplication::translate("MainWindowTabWidget", "<html><head/><body><p align=\"center\">logo</p></body></html>", nullptr));
        label_statement->setText(QCoreApplication::translate("MainWindowTabWidget", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt;\">\346\254\242\350\277\216\346\235\245\345\210\260MTAI\345\244\204\347\220\206\345\271\263\345\217\260\357\274\201</span></p><p align=\"center\"><span style=\" font-size:16pt;\">\345\234\250\350\277\231\351\207\214\357\274\214\344\275\240\345\217\257\344\273\245\345\256\236\347\216\260MTAI\345\256\236\351\252\214\346\225\260\346\215\256\347\232\204\344\277\241</span></p><p align=\"center\"><span style=\" font-size:16pt;\">\351\242\204\345\244\204\347\220\206\343\200\201\346\210\220\345\203\217\346\230\276\347\244\272\344\273\245\345\217\212\345\256\232\351\207\217\345\210\206\346\236\220\357\274\214\346\255\244\345\244\226\344\275\240</span></p><p align=\"center\"><span style=\" font-size:16pt;\">\350\277\230\347\224\250\350\257\245\350\275\257\344\273\266\350\277\233\350\241\214\346\225\260\345\200\274\344\273\277\347\234\237\346\250\241\346\213\237\357\274\201\345\260\275\346\203\205\344\272\253\345\217\227</span></p><p align=\"center\"><s"
                        "pan style=\" font-size:16pt;\">\344\275\240\347\232\204MTAI\345\256\236\351\252\214\344\276\277\345\210\251\344\271\213\346\227\205\345\220\247\357\274\201</span></p><p align=\"center\"><br/>copyright By \350\242\253\346\222\236\347\232\204\345\234\260\347\223\234</p></body></html>", nullptr));
        MainWindowTabWidget->setTabText(MainWindowTabWidget->indexOf(startWindow), QCoreApplication::translate("MainWindowTabWidget", "\351\246\226\351\241\265", nullptr));
        MainWindowTabWidget->setTabText(MainWindowTabWidget->indexOf(experimentModule), QCoreApplication::translate("MainWindowTabWidget", "MTAI\345\256\236\351\252\214", nullptr));
        MainWindowTabWidget->setTabText(MainWindowTabWidget->indexOf(simulationModule), QCoreApplication::translate("MainWindowTabWidget", "\346\225\260\345\200\274\344\273\277\347\234\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowTabWidget: public Ui_MainWindowTabWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWTABWIDGET_H
