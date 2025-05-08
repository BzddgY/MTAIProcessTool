QT       += core gui

QT += printsupport
QMAKE_CFLAGS += -Wa,-mbig-obj
QMAKE_CXXFLAGS += -Wa,-mbig-obj

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MyMathCaculator.cpp \
    ToolBox.cpp \
    basicparameter.cpp \
    colorbar.cpp \
    deconvolutiontool.cpp \
    dragresizewgt.cpp \
    experimentmodulebasicsettingwindow.cpp \
    expimagingmodule.cpp \
    exppostprocesstool.cpp \
    expprocesswindow.cpp \
    expsignalprocesstool.cpp \
    filtertool.cpp \
    filtertoolsettingdialog.cpp \
    helpstatementdialog.cpp \
    insertvaluetool.cpp \
    loadrfdatathread.cpp \
    logviewer.cpp \
    loukongprocesstool.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindowtabwidget.cpp \
    matrixplot.cpp \
    myalgorithm.cpp \
    myfigure.cpp \
    nonnegativeimagingthread.cpp \
    qcustomplot.cpp \
    rayimagingthread.cpp \
    tadatabox.cpp \
    toolpage.cpp

HEADERS += \
    MyMathCaculator.h \
    ToolBox.h \
    ToolPage.h \
    basicparameter.h \
    colorbar.h \
    const.h \
    deconvolutiontool.h \
    dragresizewgt.h \
    experimentmodulebasicsettingwindow.h \
    expimagingmodule.h \
    exppostprocesstool.h \
    expprocesswindow.h \
    expsignalprocesstool.h \
    fftw-3.3.5-dll64/fftw3.h \
    filtertool.h \
    filtertoolsettingdialog.h \
    helpstatementdialog.h \
    insertvaluetool.h \
    loadrfdatathread.h \
    logviewer.h \
    loukongprocesstool.h \
    mainwindow.h \
    mainwindowtabwidget.h \
    matrixplot.h \
    myalgorithm.h \
    myfigure.h \
    nonnegativeimagingthread.h \
    qcustomplot.h \
    rayimagingthread.h \
    tadatabox.h

FORMS += \
    ToolBox.ui \
    ToolPage.ui \
    deconvolutiontool.ui \
    dragresizewgt.ui \
    experimentmodulebasicsettingwindow.ui \
    expimagingmodule.ui \
    exppostprocesstool.ui \
    expprocesswindow.ui \
    expsignalprocesstool.ui \
    filtertool.ui \
    filtertoolsettingdialog.ui \
    helpstatementdialog.ui \
    insertvaluetool.ui \
    logviewer.ui \
    loukongprocesstool.ui \
    mainwindow.ui \
    mainwindowtabwidget.ui \
    myfigure.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rsc.qrc

DISTFILES += \
    icon/confirm.png \
    icon/confirmSetting.png

win32:  LIBS  +=  $$PWD/fftw-3.3.5-dll64/libfftw3-3.lib
unix:  LIBS  +=  -L$$PWD/fftw-3.3.5-dll64/  -lfftw3-3

