/********************************************************************************
** Form generated from reading UI file 'myfigure.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYFIGURE_H
#define UI_MYFIGURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MyFigure
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *customPlotLayout;
    QCustomPlot *customPlot;
    QGridLayout *menuLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_6;
    QToolButton *toolButton_confirmWordSize;
    QComboBox *comboBox_lineColor;
    QToolButton *toolButton_confirmXLabel;
    QLabel *label_7;
    QLabel *label;
    QToolButton *toolButton_confirmColorbar;
    QLabel *label_2;
    QLineEdit *lineEdit_yLabel;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_dynamicRange;
    QToolButton *toolButton_confirmLineColor;
    QComboBox *comboBox_lineStyle;
    QLabel *label_9;
    QComboBox *comboBox_wordSize;
    QComboBox *comboBox_selectColorbar;
    QLabel *label_4;
    QToolButton *toolButton_confirmLineStyle;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_8;
    QToolButton *toolButton_confirmTitle;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_saveData;
    QToolButton *toolButton_confirmYLabel;
    QSpacerItem *horizontalSpacer_3;
    QSlider *horizontalSlider_dynamicRange;
    QLabel *label_10;
    QSlider *horizontalSlider_gain;
    QComboBox *comboBox_wordType;
    QLineEdit *lineEdit_xLabel;
    QToolButton *toolButton_confirmWordType;
    QLineEdit *lineEdit_title;
    QLabel *label_gain;
    QPushButton *saveFigButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MyFigure)
    {
        if (MyFigure->objectName().isEmpty())
            MyFigure->setObjectName("MyFigure");
        MyFigure->resize(841, 600);
        centralwidget = new QWidget(MyFigure);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        customPlotLayout = new QGridLayout();
        customPlotLayout->setObjectName("customPlotLayout");
        customPlot = new QCustomPlot(centralwidget);
        customPlot->setObjectName("customPlot");
        customPlot->setMinimumSize(QSize(400, 400));

        customPlotLayout->addWidget(customPlot, 0, 0, 1, 1);


        horizontalLayout->addLayout(customPlotLayout);

        menuLayout = new QGridLayout();
        menuLayout->setObjectName("menuLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        menuLayout->addItem(horizontalSpacer_2, 3, 10, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setMinimumSize(QSize(50, 20));
        label_6->setMaximumSize(QSize(50, 20));

        menuLayout->addWidget(label_6, 2, 1, 1, 1);

        toolButton_confirmWordSize = new QToolButton(centralwidget);
        toolButton_confirmWordSize->setObjectName("toolButton_confirmWordSize");

        menuLayout->addWidget(toolButton_confirmWordSize, 9, 5, 1, 1);

        comboBox_lineColor = new QComboBox(centralwidget);
        comboBox_lineColor->setObjectName("comboBox_lineColor");
        comboBox_lineColor->setMinimumSize(QSize(100, 0));
        comboBox_lineColor->setMaximumSize(QSize(100, 16777215));

        menuLayout->addWidget(comboBox_lineColor, 2, 4, 1, 1);

        toolButton_confirmXLabel = new QToolButton(centralwidget);
        toolButton_confirmXLabel->setObjectName("toolButton_confirmXLabel");

        menuLayout->addWidget(toolButton_confirmXLabel, 11, 5, 1, 1);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setMinimumSize(QSize(50, 20));
        label_7->setMaximumSize(QSize(50, 20));

        menuLayout->addWidget(label_7, 5, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setMinimumSize(QSize(50, 20));
        label->setMaximumSize(QSize(50, 20));

        menuLayout->addWidget(label, 10, 1, 1, 1);

        toolButton_confirmColorbar = new QToolButton(centralwidget);
        toolButton_confirmColorbar->setObjectName("toolButton_confirmColorbar");

        menuLayout->addWidget(toolButton_confirmColorbar, 0, 5, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(50, 20));
        label_2->setMaximumSize(QSize(50, 20));

        menuLayout->addWidget(label_2, 0, 1, 1, 1);

        lineEdit_yLabel = new QLineEdit(centralwidget);
        lineEdit_yLabel->setObjectName("lineEdit_yLabel");
        lineEdit_yLabel->setEnabled(true);
        lineEdit_yLabel->setMinimumSize(QSize(100, 20));
        lineEdit_yLabel->setMaximumSize(QSize(100, 20));

        menuLayout->addWidget(lineEdit_yLabel, 12, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        menuLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        menuLayout->addItem(horizontalSpacer_4, 10, 10, 1, 1);

        label_dynamicRange = new QLabel(centralwidget);
        label_dynamicRange->setObjectName("label_dynamicRange");
        label_dynamicRange->setMinimumSize(QSize(0, 20));
        label_dynamicRange->setMaximumSize(QSize(16777215, 20));

        menuLayout->addWidget(label_dynamicRange, 4, 4, 1, 1);

        toolButton_confirmLineColor = new QToolButton(centralwidget);
        toolButton_confirmLineColor->setObjectName("toolButton_confirmLineColor");

        menuLayout->addWidget(toolButton_confirmLineColor, 2, 5, 1, 1);

        comboBox_lineStyle = new QComboBox(centralwidget);
        comboBox_lineStyle->setObjectName("comboBox_lineStyle");
        comboBox_lineStyle->setMinimumSize(QSize(100, 0));
        comboBox_lineStyle->setMaximumSize(QSize(100, 16777215));

        menuLayout->addWidget(comboBox_lineStyle, 1, 4, 1, 1);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setMinimumSize(QSize(50, 20));
        label_9->setMaximumSize(QSize(50, 20));

        menuLayout->addWidget(label_9, 8, 1, 1, 1);

        comboBox_wordSize = new QComboBox(centralwidget);
        comboBox_wordSize->setObjectName("comboBox_wordSize");
        comboBox_wordSize->setMinimumSize(QSize(100, 0));
        comboBox_wordSize->setMaximumSize(QSize(100, 16777215));

        menuLayout->addWidget(comboBox_wordSize, 9, 4, 1, 1);

        comboBox_selectColorbar = new QComboBox(centralwidget);
        comboBox_selectColorbar->setObjectName("comboBox_selectColorbar");
        comboBox_selectColorbar->setMinimumSize(QSize(100, 0));
        comboBox_selectColorbar->setMaximumSize(QSize(100, 16777215));

        menuLayout->addWidget(comboBox_selectColorbar, 0, 4, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(50, 20));
        label_4->setMaximumSize(QSize(50, 20));

        menuLayout->addWidget(label_4, 12, 1, 1, 1);

        toolButton_confirmLineStyle = new QToolButton(centralwidget);
        toolButton_confirmLineStyle->setObjectName("toolButton_confirmLineStyle");

        menuLayout->addWidget(toolButton_confirmLineStyle, 1, 5, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(50, 20));
        label_3->setMaximumSize(QSize(50, 20));

        menuLayout->addWidget(label_3, 11, 1, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setMinimumSize(QSize(50, 20));
        label_5->setMaximumSize(QSize(50, 20));

        menuLayout->addWidget(label_5, 1, 1, 1, 1);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setMinimumSize(QSize(50, 20));
        label_8->setMaximumSize(QSize(50, 20));

        menuLayout->addWidget(label_8, 7, 1, 1, 1);

        toolButton_confirmTitle = new QToolButton(centralwidget);
        toolButton_confirmTitle->setObjectName("toolButton_confirmTitle");

        menuLayout->addWidget(toolButton_confirmTitle, 10, 5, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        menuLayout->addItem(horizontalSpacer_6, 3, 9, 1, 1);

        pushButton_saveData = new QPushButton(centralwidget);
        pushButton_saveData->setObjectName("pushButton_saveData");

        menuLayout->addWidget(pushButton_saveData, 3, 1, 1, 1);

        toolButton_confirmYLabel = new QToolButton(centralwidget);
        toolButton_confirmYLabel->setObjectName("toolButton_confirmYLabel");

        menuLayout->addWidget(toolButton_confirmYLabel, 12, 5, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        menuLayout->addItem(horizontalSpacer_3, 10, 0, 1, 1);

        horizontalSlider_dynamicRange = new QSlider(centralwidget);
        horizontalSlider_dynamicRange->setObjectName("horizontalSlider_dynamicRange");
        horizontalSlider_dynamicRange->setMinimumSize(QSize(100, 0));
        horizontalSlider_dynamicRange->setMaximumSize(QSize(100, 16777215));
        horizontalSlider_dynamicRange->setMinimum(1);
        horizontalSlider_dynamicRange->setMaximum(100);
        horizontalSlider_dynamicRange->setValue(60);
        horizontalSlider_dynamicRange->setOrientation(Qt::Orientation::Horizontal);

        menuLayout->addWidget(horizontalSlider_dynamicRange, 5, 4, 1, 1);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setMinimumSize(QSize(50, 20));
        label_10->setMaximumSize(QSize(50, 20));

        menuLayout->addWidget(label_10, 9, 1, 1, 1);

        horizontalSlider_gain = new QSlider(centralwidget);
        horizontalSlider_gain->setObjectName("horizontalSlider_gain");
        horizontalSlider_gain->setMinimumSize(QSize(100, 0));
        horizontalSlider_gain->setMaximumSize(QSize(100, 16777215));
        horizontalSlider_gain->setMinimum(1);
        horizontalSlider_gain->setMaximum(100);
        horizontalSlider_gain->setValue(80);
        horizontalSlider_gain->setOrientation(Qt::Orientation::Horizontal);

        menuLayout->addWidget(horizontalSlider_gain, 7, 4, 1, 1);

        comboBox_wordType = new QComboBox(centralwidget);
        comboBox_wordType->setObjectName("comboBox_wordType");
        comboBox_wordType->setMinimumSize(QSize(100, 0));
        comboBox_wordType->setMaximumSize(QSize(100, 16777215));

        menuLayout->addWidget(comboBox_wordType, 8, 4, 1, 1);

        lineEdit_xLabel = new QLineEdit(centralwidget);
        lineEdit_xLabel->setObjectName("lineEdit_xLabel");
        lineEdit_xLabel->setMinimumSize(QSize(100, 20));
        lineEdit_xLabel->setMaximumSize(QSize(100, 20));

        menuLayout->addWidget(lineEdit_xLabel, 11, 4, 1, 1);

        toolButton_confirmWordType = new QToolButton(centralwidget);
        toolButton_confirmWordType->setObjectName("toolButton_confirmWordType");

        menuLayout->addWidget(toolButton_confirmWordType, 8, 5, 1, 1);

        lineEdit_title = new QLineEdit(centralwidget);
        lineEdit_title->setObjectName("lineEdit_title");
        lineEdit_title->setMinimumSize(QSize(100, 20));
        lineEdit_title->setMaximumSize(QSize(100, 20));

        menuLayout->addWidget(lineEdit_title, 10, 4, 1, 1);

        label_gain = new QLabel(centralwidget);
        label_gain->setObjectName("label_gain");
        label_gain->setMinimumSize(QSize(0, 20));
        label_gain->setMaximumSize(QSize(16777215, 20));

        menuLayout->addWidget(label_gain, 6, 4, 1, 1);

        saveFigButton = new QPushButton(centralwidget);
        saveFigButton->setObjectName("saveFigButton");
        saveFigButton->setMinimumSize(QSize(100, 20));
        saveFigButton->setMaximumSize(QSize(100, 20));
        saveFigButton->setLayoutDirection(Qt::LayoutDirection::RightToLeft);

        menuLayout->addWidget(saveFigButton, 3, 4, 1, 1);


        horizontalLayout->addLayout(menuLayout);

        horizontalLayout->setStretch(0, 4);
        horizontalLayout->setStretch(1, 1);
        MyFigure->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MyFigure);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 841, 20));
        MyFigure->setMenuBar(menubar);
        statusbar = new QStatusBar(MyFigure);
        statusbar->setObjectName("statusbar");
        MyFigure->setStatusBar(statusbar);

        retranslateUi(MyFigure);

        QMetaObject::connectSlotsByName(MyFigure);
    } // setupUi

    void retranslateUi(QMainWindow *MyFigure)
    {
        MyFigure->setWindowTitle(QCoreApplication::translate("MyFigure", "MainWindow", nullptr));
        label_6->setText(QCoreApplication::translate("MyFigure", "\347\272\277\346\235\241\351\242\234\350\211\262", nullptr));
        toolButton_confirmWordSize->setText(QCoreApplication::translate("MyFigure", "C", nullptr));
        toolButton_confirmXLabel->setText(QCoreApplication::translate("MyFigure", "C", nullptr));
        label_7->setText(QCoreApplication::translate("MyFigure", "\345\212\250\346\200\201\350\214\203\345\233\264", nullptr));
        label->setText(QCoreApplication::translate("MyFigure", "\344\277\256\346\224\271\346\240\207\351\242\230", nullptr));
        toolButton_confirmColorbar->setText(QCoreApplication::translate("MyFigure", "C", nullptr));
        label_2->setText(QCoreApplication::translate("MyFigure", "\351\200\211\346\213\251\350\211\262\351\230\266", nullptr));
        label_dynamicRange->setText(QString());
        toolButton_confirmLineColor->setText(QCoreApplication::translate("MyFigure", "C", nullptr));
        label_9->setText(QCoreApplication::translate("MyFigure", "\345\255\227\344\275\223", nullptr));
        label_4->setText(QCoreApplication::translate("MyFigure", "yLabel", nullptr));
        toolButton_confirmLineStyle->setText(QCoreApplication::translate("MyFigure", "C", nullptr));
        label_3->setText(QCoreApplication::translate("MyFigure", "xLabel", nullptr));
        label_5->setText(QCoreApplication::translate("MyFigure", "\347\272\277\346\235\241\346\240\267\345\274\217", nullptr));
        label_8->setText(QCoreApplication::translate("MyFigure", "\345\242\236\347\233\212", nullptr));
        toolButton_confirmTitle->setText(QCoreApplication::translate("MyFigure", "C", nullptr));
        pushButton_saveData->setText(QCoreApplication::translate("MyFigure", "\344\277\235\345\255\230\346\225\260\346\215\256", nullptr));
        toolButton_confirmYLabel->setText(QCoreApplication::translate("MyFigure", "C", nullptr));
        label_10->setText(QCoreApplication::translate("MyFigure", "\345\255\227\345\217\267", nullptr));
        toolButton_confirmWordType->setText(QCoreApplication::translate("MyFigure", "C", nullptr));
        label_gain->setText(QString());
        saveFigButton->setText(QCoreApplication::translate("MyFigure", "\344\277\235\345\255\230\345\233\276\347\211\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyFigure: public Ui_MyFigure {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYFIGURE_H
