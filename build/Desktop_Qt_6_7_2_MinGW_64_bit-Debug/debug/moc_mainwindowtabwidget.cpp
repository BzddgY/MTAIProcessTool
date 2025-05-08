/****************************************************************************
** Meta object code from reading C++ file 'mainwindowtabwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindowtabwidget.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindowtabwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowTabWidgetENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowTabWidgetENDCLASS = QtMocHelpers::stringData(
    "MainWindowTabWidget",
    "sigAppendLog",
    "",
    "message",
    "sig_initialBasicPara",
    "sig_initialExpSignalProcessPara",
    "sig_setExpPushButtonLoadRFDatasIcon",
    "iconName",
    "sig_setSpinBoxSelectedSensorsMax",
    "max_",
    "sig_setTotalTimeSteps",
    "totalTimeSteps",
    "sigSetPreProcessButtonIcon",
    "ok",
    "sig_changeNumOfSensors",
    "tmp",
    "sig_changeNumOfMeanFrames",
    "sig_cancelLoadRFDataProgress",
    "slot_getDatFileLoadPath",
    "path",
    "slot_getRFDataFileLoadAddress",
    "slot_setTotalTimeSteps",
    "slot_setFs",
    "slot_setDelayTimeSteps",
    "slot_setStartDatInd",
    "slot_setNumOfMeanFrames",
    "slot_setNumOfSensors",
    "slot_setSoS",
    "slot_setPitch",
    "slot_setRadius",
    "slot_setAngleRange",
    "slot_setArraySensorType",
    "ArraySensorType",
    "slot_setLabType",
    "LabType",
    "slot_preShowSensorMap",
    "slot_setRFDataLoadType",
    "RFDataLoadType",
    "slot_loadRFData",
    "slot_plotAllRFData",
    "slot_savePreProcessRFData",
    "slot_plotSingleRFData",
    "_sensorIndex",
    "slot_plotSingleRFData_PreDomain",
    "index",
    "slot_plotSinglePreProcessedRFData_FreDomain",
    "slot_plotSingleBeforeAndAfterRFData_FreDomain",
    "slot_appendLog",
    "slot_setExpPushButtonLoadRFDatasIcon",
    "slot_plotAllPreProcessRFData",
    "slot_preProcessRFData",
    "slot_plotSinglePreProcessedRFData",
    "slot_plotSingleBeforeAndAfterRFData",
    "slot_isDeconvolution",
    "slot_isFilter",
    "slot_isCutZeros",
    "slot_isLouKongProcess",
    "slot_isInsertValue",
    "slot_isHilbert",
    "slot_setCutZerosTimeSteps",
    "slot_setFilterType",
    "FilterType",
    "slot_setFilterTool",
    "slot_setLouKongProcessTool",
    "slot_setInsertValueType",
    "InsertValueType",
    "slot_setDeconvolutionTool",
    "slot_setRayImagingType",
    "RayImagingType",
    "slot_preShowRayImagingTAI",
    "slot_plotRayImagingTAI",
    "slot_setNonNegativeImagingType",
    "NonNegativeImagingType",
    "slot_preShowNonNegativeImagingTAI",
    "slot_plotNonNegativeImagingTAI"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowTabWidgetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      57,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  356,    2, 0x06,    1 /* Public */,
       4,    0,  359,    2, 0x06,    3 /* Public */,
       5,    0,  360,    2, 0x06,    4 /* Public */,
       6,    1,  361,    2, 0x06,    5 /* Public */,
       8,    1,  364,    2, 0x06,    7 /* Public */,
      10,    1,  367,    2, 0x06,    9 /* Public */,
      12,    1,  370,    2, 0x06,   11 /* Public */,
      14,    1,  373,    2, 0x06,   13 /* Public */,
      16,    1,  376,    2, 0x06,   15 /* Public */,
      17,    0,  379,    2, 0x06,   17 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      18,    1,  380,    2, 0x08,   18 /* Private */,
      20,    1,  383,    2, 0x08,   20 /* Private */,
      21,    1,  386,    2, 0x08,   22 /* Private */,
      22,    1,  389,    2, 0x08,   24 /* Private */,
      23,    1,  392,    2, 0x08,   26 /* Private */,
      24,    1,  395,    2, 0x08,   28 /* Private */,
      25,    1,  398,    2, 0x08,   30 /* Private */,
      26,    1,  401,    2, 0x08,   32 /* Private */,
      27,    1,  404,    2, 0x08,   34 /* Private */,
      28,    1,  407,    2, 0x08,   36 /* Private */,
      29,    1,  410,    2, 0x08,   38 /* Private */,
      30,    1,  413,    2, 0x08,   40 /* Private */,
      31,    1,  416,    2, 0x08,   42 /* Private */,
      33,    1,  419,    2, 0x08,   44 /* Private */,
      35,    0,  422,    2, 0x08,   46 /* Private */,
      36,    1,  423,    2, 0x08,   47 /* Private */,
      38,    0,  426,    2, 0x08,   49 /* Private */,
      39,    0,  427,    2, 0x08,   50 /* Private */,
      40,    0,  428,    2, 0x08,   51 /* Private */,
      41,    1,  429,    2, 0x08,   52 /* Private */,
      43,    1,  432,    2, 0x08,   54 /* Private */,
      45,    1,  435,    2, 0x08,   56 /* Private */,
      46,    1,  438,    2, 0x08,   58 /* Private */,
      47,    1,  441,    2, 0x08,   60 /* Private */,
      48,    1,  444,    2, 0x08,   62 /* Private */,
      49,    0,  447,    2, 0x08,   64 /* Private */,
      50,    0,  448,    2, 0x08,   65 /* Private */,
      51,    1,  449,    2, 0x08,   66 /* Private */,
      52,    1,  452,    2, 0x08,   68 /* Private */,
      53,    1,  455,    2, 0x08,   70 /* Private */,
      54,    1,  458,    2, 0x08,   72 /* Private */,
      55,    1,  461,    2, 0x08,   74 /* Private */,
      56,    1,  464,    2, 0x08,   76 /* Private */,
      57,    1,  467,    2, 0x08,   78 /* Private */,
      58,    1,  470,    2, 0x08,   80 /* Private */,
      59,    1,  473,    2, 0x08,   82 /* Private */,
      60,    1,  476,    2, 0x08,   84 /* Private */,
      62,    0,  479,    2, 0x08,   86 /* Private */,
      63,    0,  480,    2, 0x08,   87 /* Private */,
      64,    1,  481,    2, 0x08,   88 /* Private */,
      66,    0,  484,    2, 0x08,   90 /* Private */,
      67,    1,  485,    2, 0x08,   91 /* Private */,
      69,    0,  488,    2, 0x08,   93 /* Private */,
      70,    0,  489,    2, 0x08,   94 /* Private */,
      71,    1,  490,    2, 0x08,   95 /* Private */,
      73,    0,  493,    2, 0x08,   97 /* Private */,
      74,    0,  494,    2, 0x08,   98 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QIcon,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, 0x80000000 | 32,    2,
    QMetaType::Void, 0x80000000 | 34,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 37,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   42,
    QMetaType::Void, QMetaType::Int,   44,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,   44,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QIcon,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   44,
    QMetaType::Void, QMetaType::Int,   44,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, 0x80000000 | 61,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 65,   15,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 68,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 72,   15,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindowTabWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QTabWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowTabWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowTabWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowTabWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindowTabWidget, std::true_type>,
        // method 'sigAppendLog'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'sig_initialBasicPara'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sig_initialExpSignalProcessPara'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sig_setExpPushButtonLoadRFDatasIcon'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QIcon &, std::false_type>,
        // method 'sig_setSpinBoxSelectedSensorsMax'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'sig_setTotalTimeSteps'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'sigSetPreProcessButtonIcon'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool &, std::false_type>,
        // method 'sig_changeNumOfSensors'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'sig_changeNumOfMeanFrames'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'sig_cancelLoadRFDataProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_getDatFileLoadPath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'slot_getRFDataFileLoadAddress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'slot_setTotalTimeSteps'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'slot_setFs'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'slot_setDelayTimeSteps'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'slot_setStartDatInd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'slot_setNumOfMeanFrames'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'slot_setNumOfSensors'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'slot_setSoS'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const float &, std::false_type>,
        // method 'slot_setPitch'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const float &, std::false_type>,
        // method 'slot_setRadius'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const float &, std::false_type>,
        // method 'slot_setAngleRange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const float &, std::false_type>,
        // method 'slot_setArraySensorType'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const ArraySensorType, std::false_type>,
        // method 'slot_setLabType'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const LabType, std::false_type>,
        // method 'slot_preShowSensorMap'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_setRFDataLoadType'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const RFDataLoadType, std::false_type>,
        // method 'slot_loadRFData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_plotAllRFData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_savePreProcessRFData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_plotSingleRFData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'slot_plotSingleRFData_PreDomain'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'slot_plotSinglePreProcessedRFData_FreDomain'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'slot_plotSingleBeforeAndAfterRFData_FreDomain'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'slot_appendLog'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'slot_setExpPushButtonLoadRFDatasIcon'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QIcon &, std::false_type>,
        // method 'slot_plotAllPreProcessRFData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_preProcessRFData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_plotSinglePreProcessedRFData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'slot_plotSingleBeforeAndAfterRFData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'slot_isDeconvolution'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool &, std::false_type>,
        // method 'slot_isFilter'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool &, std::false_type>,
        // method 'slot_isCutZeros'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool &, std::false_type>,
        // method 'slot_isLouKongProcess'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool &, std::false_type>,
        // method 'slot_isInsertValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool &, std::false_type>,
        // method 'slot_isHilbert'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool &, std::false_type>,
        // method 'slot_setCutZerosTimeSteps'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'slot_setFilterType'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const FilterType &, std::false_type>,
        // method 'slot_setFilterTool'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_setLouKongProcessTool'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_setInsertValueType'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const InsertValueType &, std::false_type>,
        // method 'slot_setDeconvolutionTool'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_setRayImagingType'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const RayImagingType &, std::false_type>,
        // method 'slot_preShowRayImagingTAI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_plotRayImagingTAI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_setNonNegativeImagingType'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const NonNegativeImagingType &, std::false_type>,
        // method 'slot_preShowNonNegativeImagingTAI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_plotNonNegativeImagingTAI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindowTabWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindowTabWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sigAppendLog((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->sig_initialBasicPara(); break;
        case 2: _t->sig_initialExpSignalProcessPara(); break;
        case 3: _t->sig_setExpPushButtonLoadRFDatasIcon((*reinterpret_cast< std::add_pointer_t<QIcon>>(_a[1]))); break;
        case 4: _t->sig_setSpinBoxSelectedSensorsMax((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->sig_setTotalTimeSteps((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->sigSetPreProcessButtonIcon((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->sig_changeNumOfSensors((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->sig_changeNumOfMeanFrames((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->sig_cancelLoadRFDataProgress(); break;
        case 10: _t->slot_getDatFileLoadPath((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->slot_getRFDataFileLoadAddress((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->slot_setTotalTimeSteps((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->slot_setFs((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->slot_setDelayTimeSteps((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->slot_setStartDatInd((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->slot_setNumOfMeanFrames((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->slot_setNumOfSensors((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 18: _t->slot_setSoS((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 19: _t->slot_setPitch((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 20: _t->slot_setRadius((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 21: _t->slot_setAngleRange((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 22: _t->slot_setArraySensorType((*reinterpret_cast< std::add_pointer_t<ArraySensorType>>(_a[1]))); break;
        case 23: _t->slot_setLabType((*reinterpret_cast< std::add_pointer_t<LabType>>(_a[1]))); break;
        case 24: _t->slot_preShowSensorMap(); break;
        case 25: _t->slot_setRFDataLoadType((*reinterpret_cast< std::add_pointer_t<RFDataLoadType>>(_a[1]))); break;
        case 26: _t->slot_loadRFData(); break;
        case 27: _t->slot_plotAllRFData(); break;
        case 28: _t->slot_savePreProcessRFData(); break;
        case 29: _t->slot_plotSingleRFData((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 30: _t->slot_plotSingleRFData_PreDomain((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 31: _t->slot_plotSinglePreProcessedRFData_FreDomain((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 32: _t->slot_plotSingleBeforeAndAfterRFData_FreDomain((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 33: _t->slot_appendLog((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 34: _t->slot_setExpPushButtonLoadRFDatasIcon((*reinterpret_cast< std::add_pointer_t<QIcon>>(_a[1]))); break;
        case 35: _t->slot_plotAllPreProcessRFData(); break;
        case 36: _t->slot_preProcessRFData(); break;
        case 37: _t->slot_plotSinglePreProcessedRFData((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 38: _t->slot_plotSingleBeforeAndAfterRFData((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 39: _t->slot_isDeconvolution((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 40: _t->slot_isFilter((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 41: _t->slot_isCutZeros((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 42: _t->slot_isLouKongProcess((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 43: _t->slot_isInsertValue((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 44: _t->slot_isHilbert((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 45: _t->slot_setCutZerosTimeSteps((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 46: _t->slot_setFilterType((*reinterpret_cast< std::add_pointer_t<FilterType>>(_a[1]))); break;
        case 47: _t->slot_setFilterTool(); break;
        case 48: _t->slot_setLouKongProcessTool(); break;
        case 49: _t->slot_setInsertValueType((*reinterpret_cast< std::add_pointer_t<InsertValueType>>(_a[1]))); break;
        case 50: _t->slot_setDeconvolutionTool(); break;
        case 51: _t->slot_setRayImagingType((*reinterpret_cast< std::add_pointer_t<RayImagingType>>(_a[1]))); break;
        case 52: _t->slot_preShowRayImagingTAI(); break;
        case 53: _t->slot_plotRayImagingTAI(); break;
        case 54: _t->slot_setNonNegativeImagingType((*reinterpret_cast< std::add_pointer_t<NonNegativeImagingType>>(_a[1]))); break;
        case 55: _t->slot_preShowNonNegativeImagingTAI(); break;
        case 56: _t->slot_plotNonNegativeImagingTAI(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindowTabWidget::*)(const QString & );
            if (_t _q_method = &MainWindowTabWidget::sigAppendLog; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindowTabWidget::*)();
            if (_t _q_method = &MainWindowTabWidget::sig_initialBasicPara; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindowTabWidget::*)();
            if (_t _q_method = &MainWindowTabWidget::sig_initialExpSignalProcessPara; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindowTabWidget::*)(const QIcon & );
            if (_t _q_method = &MainWindowTabWidget::sig_setExpPushButtonLoadRFDatasIcon; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindowTabWidget::*)(const int & );
            if (_t _q_method = &MainWindowTabWidget::sig_setSpinBoxSelectedSensorsMax; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindowTabWidget::*)(const int & );
            if (_t _q_method = &MainWindowTabWidget::sig_setTotalTimeSteps; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindowTabWidget::*)(const bool & );
            if (_t _q_method = &MainWindowTabWidget::sigSetPreProcessButtonIcon; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindowTabWidget::*)(const int & );
            if (_t _q_method = &MainWindowTabWidget::sig_changeNumOfSensors; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MainWindowTabWidget::*)(const int & );
            if (_t _q_method = &MainWindowTabWidget::sig_changeNumOfMeanFrames; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MainWindowTabWidget::*)();
            if (_t _q_method = &MainWindowTabWidget::sig_cancelLoadRFDataProgress; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
    }
}

const QMetaObject *MainWindowTabWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindowTabWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowTabWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QTabWidget::qt_metacast(_clname);
}

int MainWindowTabWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 57)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 57;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 57)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 57;
    }
    return _id;
}

// SIGNAL 0
void MainWindowTabWidget::sigAppendLog(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindowTabWidget::sig_initialBasicPara()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindowTabWidget::sig_initialExpSignalProcessPara()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindowTabWidget::sig_setExpPushButtonLoadRFDatasIcon(const QIcon & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindowTabWidget::sig_setSpinBoxSelectedSensorsMax(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindowTabWidget::sig_setTotalTimeSteps(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindowTabWidget::sigSetPreProcessButtonIcon(const bool & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindowTabWidget::sig_changeNumOfSensors(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainWindowTabWidget::sig_changeNumOfMeanFrames(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MainWindowTabWidget::sig_cancelLoadRFDataProgress()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
