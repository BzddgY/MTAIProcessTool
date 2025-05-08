/****************************************************************************
** Meta object code from reading C++ file 'expsignalprocesstool.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../expsignalprocesstool.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'expsignalprocesstool.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSExpSignalProcessToolENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSExpSignalProcessToolENDCLASS = QtMocHelpers::stringData(
    "ExpSignalProcessTool",
    "sig_setRFDataLoadType",
    "",
    "RFDataLoadType",
    "sig_loadRFData",
    "sig_plotAllRFData",
    "sig_savePreProcessRFData",
    "sig_plotSingleRFData",
    "sig_plotAllPreProcessRFData",
    "sig_preProcessRFData",
    "sig_isDeconvolution",
    "sig_isFilter",
    "sig_isCutZeros",
    "sig_isLouKong",
    "sig_isInsertValue",
    "sig_isHilbert",
    "sig_plotSinglePreProcessedRFData",
    "sig_plotSingleBeforeAndAfterRFData",
    "sig_setCutZerosTimeSteps",
    "sig_plotSingleRFData_PreDomain",
    "sig_plotSinglePreProcessedRFData_FreDomain",
    "sig_plotSingleBeforeAndAfterRFData_FreDomain",
    "sig_setFilterType",
    "FilterType",
    "sig_setFilterTool",
    "sig_setLouKongProcessTool",
    "sig_setInsertValueType",
    "InsertValueType",
    "sig_setDeconvolutionTool",
    "slot_initialPara",
    "slot_setPushButtonLoadRFDatasIcon",
    "iconName",
    "slot_setSpinBoxSelectedSensorsMax",
    "max_",
    "slot_setTotalTimeSteps",
    "totalTimeSteps",
    "slot_setPreProcessButtonIcon",
    "ok",
    "on_comboBox_RFDataLoadType_currentIndexChanged",
    "index",
    "on_pushButton_loadRFData_clicked",
    "on_pushButton_plotAllRFData_clicked",
    "on_pushButton_savePreProcessRFData_clicked",
    "on_toolButton_confirmSelectedSensorIndex_clicked",
    "on_pushButton_plotSingleRFData_clicked",
    "on_spinBox_selectedSensorIndex_editingFinished",
    "on_pushButton_plotAllPreProcessRFData_clicked",
    "on_pushButton_preProcessRFData_clicked",
    "on_checkBox_isDeconvolution_stateChanged",
    "arg1",
    "on_checkBox_isFilter_stateChanged",
    "on_checkBox_isCutZeros_stateChanged",
    "on_checkBox_isLouKong_stateChanged",
    "on_checkBox_isInsertValue_stateChanged",
    "on_pushButton_plotSinglePreProcessedRFData_clicked",
    "on_pushButton_plotSingleBeforeAndAfterRFData_clicked",
    "on_spinBox_cutZerosTimesteps_editingFinished",
    "on_pushButton_plotSingleRFData_PreDomain_clicked",
    "on_pushButton_plotSinglePreProcessedRFData_FreDomain_clicked",
    "on_pushButton_plotSingleBeforeAndAfterRFData_FreDomain_clicked",
    "on_comboBox_filterType_currentIndexChanged",
    "on_toolButton_setFilterPara_clicked",
    "on_toolButton_setLouKongProcessPara_clicked",
    "on_comboBox_insertValueType_currentIndexChanged",
    "on_checkBox_isHilbertTransform_stateChanged",
    "on_toolButton_setDeconvolutionPara_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSExpSignalProcessToolENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      55,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      24,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  344,    2, 0x06,    1 /* Public */,
       4,    0,  347,    2, 0x06,    3 /* Public */,
       5,    0,  348,    2, 0x06,    4 /* Public */,
       6,    0,  349,    2, 0x06,    5 /* Public */,
       7,    1,  350,    2, 0x06,    6 /* Public */,
       8,    0,  353,    2, 0x06,    8 /* Public */,
       9,    0,  354,    2, 0x06,    9 /* Public */,
      10,    1,  355,    2, 0x06,   10 /* Public */,
      11,    1,  358,    2, 0x06,   12 /* Public */,
      12,    1,  361,    2, 0x06,   14 /* Public */,
      13,    1,  364,    2, 0x06,   16 /* Public */,
      14,    1,  367,    2, 0x06,   18 /* Public */,
      15,    1,  370,    2, 0x06,   20 /* Public */,
      16,    1,  373,    2, 0x06,   22 /* Public */,
      17,    1,  376,    2, 0x06,   24 /* Public */,
      18,    1,  379,    2, 0x06,   26 /* Public */,
      19,    1,  382,    2, 0x06,   28 /* Public */,
      20,    1,  385,    2, 0x06,   30 /* Public */,
      21,    1,  388,    2, 0x06,   32 /* Public */,
      22,    1,  391,    2, 0x06,   34 /* Public */,
      24,    0,  394,    2, 0x06,   36 /* Public */,
      25,    0,  395,    2, 0x06,   37 /* Public */,
      26,    1,  396,    2, 0x06,   38 /* Public */,
      28,    0,  399,    2, 0x06,   40 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      29,    0,  400,    2, 0x0a,   41 /* Public */,
      30,    1,  401,    2, 0x0a,   42 /* Public */,
      32,    1,  404,    2, 0x0a,   44 /* Public */,
      34,    1,  407,    2, 0x0a,   46 /* Public */,
      36,    1,  410,    2, 0x0a,   48 /* Public */,
      38,    1,  413,    2, 0x08,   50 /* Private */,
      40,    0,  416,    2, 0x08,   52 /* Private */,
      41,    0,  417,    2, 0x08,   53 /* Private */,
      42,    0,  418,    2, 0x08,   54 /* Private */,
      43,    0,  419,    2, 0x08,   55 /* Private */,
      44,    0,  420,    2, 0x08,   56 /* Private */,
      45,    0,  421,    2, 0x08,   57 /* Private */,
      46,    0,  422,    2, 0x08,   58 /* Private */,
      47,    0,  423,    2, 0x08,   59 /* Private */,
      48,    1,  424,    2, 0x08,   60 /* Private */,
      50,    1,  427,    2, 0x08,   62 /* Private */,
      51,    1,  430,    2, 0x08,   64 /* Private */,
      52,    1,  433,    2, 0x08,   66 /* Private */,
      53,    1,  436,    2, 0x08,   68 /* Private */,
      54,    0,  439,    2, 0x08,   70 /* Private */,
      55,    0,  440,    2, 0x08,   71 /* Private */,
      56,    0,  441,    2, 0x08,   72 /* Private */,
      57,    0,  442,    2, 0x08,   73 /* Private */,
      58,    0,  443,    2, 0x08,   74 /* Private */,
      59,    0,  444,    2, 0x08,   75 /* Private */,
      60,    1,  445,    2, 0x08,   76 /* Private */,
      61,    0,  448,    2, 0x08,   78 /* Private */,
      62,    0,  449,    2, 0x08,   79 /* Private */,
      63,    1,  450,    2, 0x08,   80 /* Private */,
      64,    1,  453,    2, 0x08,   82 /* Private */,
      65,    0,  456,    2, 0x08,   84 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 23,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 27,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QIcon,   31,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void, QMetaType::Bool,   37,
    QMetaType::Void, QMetaType::Int,   39,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   49,
    QMetaType::Void, QMetaType::Int,   49,
    QMetaType::Void, QMetaType::Int,   49,
    QMetaType::Void, QMetaType::Int,   49,
    QMetaType::Void, QMetaType::Int,   49,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   39,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   39,
    QMetaType::Void, QMetaType::Int,   49,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ExpSignalProcessTool::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSExpSignalProcessToolENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSExpSignalProcessToolENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSExpSignalProcessToolENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ExpSignalProcessTool, std::true_type>,
        // method 'sig_setRFDataLoadType'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const RFDataLoadType, std::false_type>,
        // method 'sig_loadRFData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sig_plotAllRFData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sig_savePreProcessRFData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sig_plotSingleRFData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'sig_plotAllPreProcessRFData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sig_preProcessRFData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sig_isDeconvolution'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'sig_isFilter'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'sig_isCutZeros'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'sig_isLouKong'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'sig_isInsertValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'sig_isHilbert'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool, std::false_type>,
        // method 'sig_plotSinglePreProcessedRFData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'sig_plotSingleBeforeAndAfterRFData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'sig_setCutZerosTimeSteps'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'sig_plotSingleRFData_PreDomain'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'sig_plotSinglePreProcessedRFData_FreDomain'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'sig_plotSingleBeforeAndAfterRFData_FreDomain'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'sig_setFilterType'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const FilterType &, std::false_type>,
        // method 'sig_setFilterTool'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sig_setLouKongProcessTool'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sig_setInsertValueType'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const InsertValueType &, std::false_type>,
        // method 'sig_setDeconvolutionTool'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_initialPara'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_setPushButtonLoadRFDatasIcon'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QIcon &, std::false_type>,
        // method 'slot_setSpinBoxSelectedSensorsMax'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'slot_setTotalTimeSteps'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'slot_setPreProcessButtonIcon'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool &, std::false_type>,
        // method 'on_comboBox_RFDataLoadType_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pushButton_loadRFData_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_plotAllRFData_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_savePreProcessRFData_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_toolButton_confirmSelectedSensorIndex_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_plotSingleRFData_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinBox_selectedSensorIndex_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_plotAllPreProcessRFData_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_preProcessRFData_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_checkBox_isDeconvolution_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_checkBox_isFilter_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_checkBox_isCutZeros_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_checkBox_isLouKong_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_checkBox_isInsertValue_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pushButton_plotSinglePreProcessedRFData_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_plotSingleBeforeAndAfterRFData_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinBox_cutZerosTimesteps_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_plotSingleRFData_PreDomain_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_plotSinglePreProcessedRFData_FreDomain_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_plotSingleBeforeAndAfterRFData_FreDomain_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comboBox_filterType_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_toolButton_setFilterPara_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_toolButton_setLouKongProcessPara_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comboBox_insertValueType_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_checkBox_isHilbertTransform_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_toolButton_setDeconvolutionPara_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ExpSignalProcessTool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ExpSignalProcessTool *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sig_setRFDataLoadType((*reinterpret_cast< std::add_pointer_t<RFDataLoadType>>(_a[1]))); break;
        case 1: _t->sig_loadRFData(); break;
        case 2: _t->sig_plotAllRFData(); break;
        case 3: _t->sig_savePreProcessRFData(); break;
        case 4: _t->sig_plotSingleRFData((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->sig_plotAllPreProcessRFData(); break;
        case 6: _t->sig_preProcessRFData(); break;
        case 7: _t->sig_isDeconvolution((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->sig_isFilter((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: _t->sig_isCutZeros((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 10: _t->sig_isLouKong((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 11: _t->sig_isInsertValue((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 12: _t->sig_isHilbert((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 13: _t->sig_plotSinglePreProcessedRFData((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->sig_plotSingleBeforeAndAfterRFData((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->sig_setCutZerosTimeSteps((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->sig_plotSingleRFData_PreDomain((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->sig_plotSinglePreProcessedRFData_FreDomain((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 18: _t->sig_plotSingleBeforeAndAfterRFData_FreDomain((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 19: _t->sig_setFilterType((*reinterpret_cast< std::add_pointer_t<FilterType>>(_a[1]))); break;
        case 20: _t->sig_setFilterTool(); break;
        case 21: _t->sig_setLouKongProcessTool(); break;
        case 22: _t->sig_setInsertValueType((*reinterpret_cast< std::add_pointer_t<InsertValueType>>(_a[1]))); break;
        case 23: _t->sig_setDeconvolutionTool(); break;
        case 24: _t->slot_initialPara(); break;
        case 25: _t->slot_setPushButtonLoadRFDatasIcon((*reinterpret_cast< std::add_pointer_t<QIcon>>(_a[1]))); break;
        case 26: _t->slot_setSpinBoxSelectedSensorsMax((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 27: _t->slot_setTotalTimeSteps((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 28: _t->slot_setPreProcessButtonIcon((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 29: _t->on_comboBox_RFDataLoadType_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 30: _t->on_pushButton_loadRFData_clicked(); break;
        case 31: _t->on_pushButton_plotAllRFData_clicked(); break;
        case 32: _t->on_pushButton_savePreProcessRFData_clicked(); break;
        case 33: _t->on_toolButton_confirmSelectedSensorIndex_clicked(); break;
        case 34: _t->on_pushButton_plotSingleRFData_clicked(); break;
        case 35: _t->on_spinBox_selectedSensorIndex_editingFinished(); break;
        case 36: _t->on_pushButton_plotAllPreProcessRFData_clicked(); break;
        case 37: _t->on_pushButton_preProcessRFData_clicked(); break;
        case 38: _t->on_checkBox_isDeconvolution_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 39: _t->on_checkBox_isFilter_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 40: _t->on_checkBox_isCutZeros_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 41: _t->on_checkBox_isLouKong_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 42: _t->on_checkBox_isInsertValue_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 43: _t->on_pushButton_plotSinglePreProcessedRFData_clicked(); break;
        case 44: _t->on_pushButton_plotSingleBeforeAndAfterRFData_clicked(); break;
        case 45: _t->on_spinBox_cutZerosTimesteps_editingFinished(); break;
        case 46: _t->on_pushButton_plotSingleRFData_PreDomain_clicked(); break;
        case 47: _t->on_pushButton_plotSinglePreProcessedRFData_FreDomain_clicked(); break;
        case 48: _t->on_pushButton_plotSingleBeforeAndAfterRFData_FreDomain_clicked(); break;
        case 49: _t->on_comboBox_filterType_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 50: _t->on_toolButton_setFilterPara_clicked(); break;
        case 51: _t->on_toolButton_setLouKongProcessPara_clicked(); break;
        case 52: _t->on_comboBox_insertValueType_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 53: _t->on_checkBox_isHilbertTransform_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 54: _t->on_toolButton_setDeconvolutionPara_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ExpSignalProcessTool::*)(const RFDataLoadType );
            if (_t _q_method = &ExpSignalProcessTool::sig_setRFDataLoadType; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ExpSignalProcessTool::*)();
            if (_t _q_method = &ExpSignalProcessTool::sig_loadRFData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ExpSignalProcessTool::*)();
            if (_t _q_method = &ExpSignalProcessTool::sig_plotAllRFData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ExpSignalProcessTool::*)();
            if (_t _q_method = &ExpSignalProcessTool::sig_savePreProcessRFData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ExpSignalProcessTool::*)(const int & );
            if (_t _q_method = &ExpSignalProcessTool::sig_plotSingleRFData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ExpSignalProcessTool::*)();
            if (_t _q_method = &ExpSignalProcessTool::sig_plotAllPreProcessRFData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ExpSignalProcessTool::*)();
            if (_t _q_method = &ExpSignalProcessTool::sig_preProcessRFData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ExpSignalProcessTool::*)(bool );
            if (_t _q_method = &ExpSignalProcessTool::sig_isDeconvolution; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (ExpSignalProcessTool::*)(bool );
            if (_t _q_method = &ExpSignalProcessTool::sig_isFilter; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (ExpSignalProcessTool::*)(bool );
            if (_t _q_method = &ExpSignalProcessTool::sig_isCutZeros; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (ExpSignalProcessTool::*)(bool );
            if (_t _q_method = &ExpSignalProcessTool::sig_isLouKong; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (ExpSignalProcessTool::*)(bool );
            if (_t _q_method = &ExpSignalProcessTool::sig_isInsertValue; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (ExpSignalProcessTool::*)(const bool );
            if (_t _q_method = &ExpSignalProcessTool::sig_isHilbert; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (ExpSignalProcessTool::*)(const int & );
            if (_t _q_method = &ExpSignalProcessTool::sig_plotSinglePreProcessedRFData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (ExpSignalProcessTool::*)(const int & );
            if (_t _q_method = &ExpSignalProcessTool::sig_plotSingleBeforeAndAfterRFData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (ExpSignalProcessTool::*)(const int & );
            if (_t _q_method = &ExpSignalProcessTool::sig_setCutZerosTimeSteps; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (ExpSignalProcessTool::*)(const int & );
            if (_t _q_method = &ExpSignalProcessTool::sig_plotSingleRFData_PreDomain; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (ExpSignalProcessTool::*)(const int & );
            if (_t _q_method = &ExpSignalProcessTool::sig_plotSinglePreProcessedRFData_FreDomain; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (ExpSignalProcessTool::*)(const int & );
            if (_t _q_method = &ExpSignalProcessTool::sig_plotSingleBeforeAndAfterRFData_FreDomain; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (ExpSignalProcessTool::*)(const FilterType & );
            if (_t _q_method = &ExpSignalProcessTool::sig_setFilterType; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (ExpSignalProcessTool::*)();
            if (_t _q_method = &ExpSignalProcessTool::sig_setFilterTool; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (ExpSignalProcessTool::*)();
            if (_t _q_method = &ExpSignalProcessTool::sig_setLouKongProcessTool; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (ExpSignalProcessTool::*)(const InsertValueType & );
            if (_t _q_method = &ExpSignalProcessTool::sig_setInsertValueType; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (ExpSignalProcessTool::*)();
            if (_t _q_method = &ExpSignalProcessTool::sig_setDeconvolutionTool; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 23;
                return;
            }
        }
    }
}

const QMetaObject *ExpSignalProcessTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExpSignalProcessTool::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSExpSignalProcessToolENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ExpSignalProcessTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 55)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 55;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 55)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 55;
    }
    return _id;
}

// SIGNAL 0
void ExpSignalProcessTool::sig_setRFDataLoadType(const RFDataLoadType _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ExpSignalProcessTool::sig_loadRFData()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ExpSignalProcessTool::sig_plotAllRFData()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ExpSignalProcessTool::sig_savePreProcessRFData()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ExpSignalProcessTool::sig_plotSingleRFData(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ExpSignalProcessTool::sig_plotAllPreProcessRFData()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void ExpSignalProcessTool::sig_preProcessRFData()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void ExpSignalProcessTool::sig_isDeconvolution(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ExpSignalProcessTool::sig_isFilter(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void ExpSignalProcessTool::sig_isCutZeros(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void ExpSignalProcessTool::sig_isLouKong(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void ExpSignalProcessTool::sig_isInsertValue(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void ExpSignalProcessTool::sig_isHilbert(const bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void ExpSignalProcessTool::sig_plotSinglePreProcessedRFData(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void ExpSignalProcessTool::sig_plotSingleBeforeAndAfterRFData(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void ExpSignalProcessTool::sig_setCutZerosTimeSteps(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void ExpSignalProcessTool::sig_plotSingleRFData_PreDomain(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void ExpSignalProcessTool::sig_plotSinglePreProcessedRFData_FreDomain(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void ExpSignalProcessTool::sig_plotSingleBeforeAndAfterRFData_FreDomain(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void ExpSignalProcessTool::sig_setFilterType(const FilterType & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void ExpSignalProcessTool::sig_setFilterTool()
{
    QMetaObject::activate(this, &staticMetaObject, 20, nullptr);
}

// SIGNAL 21
void ExpSignalProcessTool::sig_setLouKongProcessTool()
{
    QMetaObject::activate(this, &staticMetaObject, 21, nullptr);
}

// SIGNAL 22
void ExpSignalProcessTool::sig_setInsertValueType(const InsertValueType & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void ExpSignalProcessTool::sig_setDeconvolutionTool()
{
    QMetaObject::activate(this, &staticMetaObject, 23, nullptr);
}
QT_WARNING_POP
