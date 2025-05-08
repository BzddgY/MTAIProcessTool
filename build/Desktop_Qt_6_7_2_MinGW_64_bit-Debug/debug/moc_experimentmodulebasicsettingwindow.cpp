/****************************************************************************
** Meta object code from reading C++ file 'experimentmodulebasicsettingwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../experimentmodulebasicsettingwindow.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'experimentmodulebasicsettingwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSexperimentModuleBasicSettingWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSexperimentModuleBasicSettingWindowENDCLASS = QtMocHelpers::stringData(
    "experimentModuleBasicSettingWindow",
    "sigAppendLog",
    "",
    "message",
    "sig_getDatFileLoadPath",
    "sig_getRFDataFileLoadAddress",
    "sig_setFs",
    "sig_setTotalTimeSteps",
    "sig_setDelayTimeSteps",
    "sig_setSoS",
    "sig_setStartDatInd",
    "sig_setNumOfMeanFrames",
    "sig_setNumOfSensors",
    "sig_setPitch",
    "sig_setRadius",
    "sig_setAngleRange",
    "sig_setArraySensorType",
    "ArraySensorType",
    "sig_setLabType",
    "LabType",
    "sig_preShowSensorMap",
    "slot_initialPara",
    "slot_changeNumOfSensors",
    "tmp",
    "slot_changeNumOfMeanFrames",
    "on_pushButton_getDatFileLoadPath_clicked",
    "on_spinBox_sampleFrequency_editingFinished",
    "on_spinBox_totalTimeSteps_editingFinished",
    "on_spinBox_delayTimeSteps_editingFinished",
    "on_doubleSpinBox_SoS_editingFinished",
    "on_spinBox_startDatInd_editingFinished",
    "on_spinBox_numOfMeanFrames_editingFinished",
    "on_spinBox_numOfSensors_editingFinished",
    "on_doubleSpinBox_pitch_editingFinished",
    "on_doubleSpinBox_radius_editingFinished",
    "on_doubleSpinBox_angleRange_editingFinished",
    "on_comboBox_sensorType_currentIndexChanged",
    "index",
    "on_pushButton_preShowSensorsMap_clicked",
    "on_comboBox_LabType_currentIndexChanged",
    "on_pushButton_getRFDataFileLoadAddress_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSexperimentModuleBasicSettingWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      34,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      16,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  218,    2, 0x06,    1 /* Public */,
       4,    1,  221,    2, 0x06,    3 /* Public */,
       5,    1,  224,    2, 0x06,    5 /* Public */,
       6,    1,  227,    2, 0x06,    7 /* Public */,
       7,    1,  230,    2, 0x06,    9 /* Public */,
       8,    1,  233,    2, 0x06,   11 /* Public */,
       9,    1,  236,    2, 0x06,   13 /* Public */,
      10,    1,  239,    2, 0x06,   15 /* Public */,
      11,    1,  242,    2, 0x06,   17 /* Public */,
      12,    1,  245,    2, 0x06,   19 /* Public */,
      13,    1,  248,    2, 0x06,   21 /* Public */,
      14,    1,  251,    2, 0x06,   23 /* Public */,
      15,    1,  254,    2, 0x06,   25 /* Public */,
      16,    1,  257,    2, 0x06,   27 /* Public */,
      18,    1,  260,    2, 0x06,   29 /* Public */,
      20,    0,  263,    2, 0x06,   31 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      21,    0,  264,    2, 0x0a,   32 /* Public */,
      22,    1,  265,    2, 0x0a,   33 /* Public */,
      24,    1,  268,    2, 0x0a,   35 /* Public */,
      25,    0,  271,    2, 0x08,   37 /* Private */,
      26,    0,  272,    2, 0x08,   38 /* Private */,
      27,    0,  273,    2, 0x08,   39 /* Private */,
      28,    0,  274,    2, 0x08,   40 /* Private */,
      29,    0,  275,    2, 0x08,   41 /* Private */,
      30,    0,  276,    2, 0x08,   42 /* Private */,
      31,    0,  277,    2, 0x08,   43 /* Private */,
      32,    0,  278,    2, 0x08,   44 /* Private */,
      33,    0,  279,    2, 0x08,   45 /* Private */,
      34,    0,  280,    2, 0x08,   46 /* Private */,
      35,    0,  281,    2, 0x08,   47 /* Private */,
      36,    1,  282,    2, 0x08,   48 /* Private */,
      38,    0,  285,    2, 0x08,   50 /* Private */,
      39,    1,  286,    2, 0x08,   51 /* Private */,
      40,    0,  289,    2, 0x08,   53 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, 0x80000000 | 17,    2,
    QMetaType::Void, 0x80000000 | 19,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject experimentModuleBasicSettingWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSexperimentModuleBasicSettingWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSexperimentModuleBasicSettingWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSexperimentModuleBasicSettingWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<experimentModuleBasicSettingWindow, std::true_type>,
        // method 'sigAppendLog'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'sig_getDatFileLoadPath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'sig_getRFDataFileLoadAddress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'sig_setFs'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'sig_setTotalTimeSteps'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'sig_setDelayTimeSteps'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'sig_setSoS'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const float &, std::false_type>,
        // method 'sig_setStartDatInd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'sig_setNumOfMeanFrames'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'sig_setNumOfSensors'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'sig_setPitch'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const float &, std::false_type>,
        // method 'sig_setRadius'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const float &, std::false_type>,
        // method 'sig_setAngleRange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const float &, std::false_type>,
        // method 'sig_setArraySensorType'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const ArraySensorType, std::false_type>,
        // method 'sig_setLabType'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const LabType, std::false_type>,
        // method 'sig_preShowSensorMap'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_initialPara'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_changeNumOfSensors'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'slot_changeNumOfMeanFrames'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'on_pushButton_getDatFileLoadPath_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinBox_sampleFrequency_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinBox_totalTimeSteps_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinBox_delayTimeSteps_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_doubleSpinBox_SoS_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinBox_startDatInd_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinBox_numOfMeanFrames_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinBox_numOfSensors_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_doubleSpinBox_pitch_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_doubleSpinBox_radius_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_doubleSpinBox_angleRange_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comboBox_sensorType_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pushButton_preShowSensorsMap_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comboBox_LabType_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pushButton_getRFDataFileLoadAddress_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void experimentModuleBasicSettingWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<experimentModuleBasicSettingWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sigAppendLog((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->sig_getDatFileLoadPath((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->sig_getRFDataFileLoadAddress((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->sig_setFs((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->sig_setTotalTimeSteps((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->sig_setDelayTimeSteps((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->sig_setSoS((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 7: _t->sig_setStartDatInd((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->sig_setNumOfMeanFrames((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->sig_setNumOfSensors((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->sig_setPitch((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 11: _t->sig_setRadius((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 12: _t->sig_setAngleRange((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 13: _t->sig_setArraySensorType((*reinterpret_cast< std::add_pointer_t<ArraySensorType>>(_a[1]))); break;
        case 14: _t->sig_setLabType((*reinterpret_cast< std::add_pointer_t<LabType>>(_a[1]))); break;
        case 15: _t->sig_preShowSensorMap(); break;
        case 16: _t->slot_initialPara(); break;
        case 17: _t->slot_changeNumOfSensors((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 18: _t->slot_changeNumOfMeanFrames((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 19: _t->on_pushButton_getDatFileLoadPath_clicked(); break;
        case 20: _t->on_spinBox_sampleFrequency_editingFinished(); break;
        case 21: _t->on_spinBox_totalTimeSteps_editingFinished(); break;
        case 22: _t->on_spinBox_delayTimeSteps_editingFinished(); break;
        case 23: _t->on_doubleSpinBox_SoS_editingFinished(); break;
        case 24: _t->on_spinBox_startDatInd_editingFinished(); break;
        case 25: _t->on_spinBox_numOfMeanFrames_editingFinished(); break;
        case 26: _t->on_spinBox_numOfSensors_editingFinished(); break;
        case 27: _t->on_doubleSpinBox_pitch_editingFinished(); break;
        case 28: _t->on_doubleSpinBox_radius_editingFinished(); break;
        case 29: _t->on_doubleSpinBox_angleRange_editingFinished(); break;
        case 30: _t->on_comboBox_sensorType_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 31: _t->on_pushButton_preShowSensorsMap_clicked(); break;
        case 32: _t->on_comboBox_LabType_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 33: _t->on_pushButton_getRFDataFileLoadAddress_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (experimentModuleBasicSettingWindow::*)(const QString & );
            if (_t _q_method = &experimentModuleBasicSettingWindow::sigAppendLog; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (experimentModuleBasicSettingWindow::*)(const QString & );
            if (_t _q_method = &experimentModuleBasicSettingWindow::sig_getDatFileLoadPath; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (experimentModuleBasicSettingWindow::*)(const QString & );
            if (_t _q_method = &experimentModuleBasicSettingWindow::sig_getRFDataFileLoadAddress; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (experimentModuleBasicSettingWindow::*)(const int & );
            if (_t _q_method = &experimentModuleBasicSettingWindow::sig_setFs; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (experimentModuleBasicSettingWindow::*)(const int & );
            if (_t _q_method = &experimentModuleBasicSettingWindow::sig_setTotalTimeSteps; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (experimentModuleBasicSettingWindow::*)(const int & );
            if (_t _q_method = &experimentModuleBasicSettingWindow::sig_setDelayTimeSteps; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (experimentModuleBasicSettingWindow::*)(const float & );
            if (_t _q_method = &experimentModuleBasicSettingWindow::sig_setSoS; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (experimentModuleBasicSettingWindow::*)(const int & );
            if (_t _q_method = &experimentModuleBasicSettingWindow::sig_setStartDatInd; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (experimentModuleBasicSettingWindow::*)(const int & );
            if (_t _q_method = &experimentModuleBasicSettingWindow::sig_setNumOfMeanFrames; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (experimentModuleBasicSettingWindow::*)(const int & );
            if (_t _q_method = &experimentModuleBasicSettingWindow::sig_setNumOfSensors; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (experimentModuleBasicSettingWindow::*)(const float & );
            if (_t _q_method = &experimentModuleBasicSettingWindow::sig_setPitch; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (experimentModuleBasicSettingWindow::*)(const float & );
            if (_t _q_method = &experimentModuleBasicSettingWindow::sig_setRadius; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (experimentModuleBasicSettingWindow::*)(const float & );
            if (_t _q_method = &experimentModuleBasicSettingWindow::sig_setAngleRange; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (experimentModuleBasicSettingWindow::*)(const ArraySensorType );
            if (_t _q_method = &experimentModuleBasicSettingWindow::sig_setArraySensorType; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (experimentModuleBasicSettingWindow::*)(const LabType );
            if (_t _q_method = &experimentModuleBasicSettingWindow::sig_setLabType; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (experimentModuleBasicSettingWindow::*)();
            if (_t _q_method = &experimentModuleBasicSettingWindow::sig_preShowSensorMap; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 15;
                return;
            }
        }
    }
}

const QMetaObject *experimentModuleBasicSettingWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *experimentModuleBasicSettingWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSexperimentModuleBasicSettingWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int experimentModuleBasicSettingWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 34)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 34;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 34)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 34;
    }
    return _id;
}

// SIGNAL 0
void experimentModuleBasicSettingWindow::sigAppendLog(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void experimentModuleBasicSettingWindow::sig_getDatFileLoadPath(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void experimentModuleBasicSettingWindow::sig_getRFDataFileLoadAddress(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void experimentModuleBasicSettingWindow::sig_setFs(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void experimentModuleBasicSettingWindow::sig_setTotalTimeSteps(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void experimentModuleBasicSettingWindow::sig_setDelayTimeSteps(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void experimentModuleBasicSettingWindow::sig_setSoS(const float & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void experimentModuleBasicSettingWindow::sig_setStartDatInd(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void experimentModuleBasicSettingWindow::sig_setNumOfMeanFrames(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void experimentModuleBasicSettingWindow::sig_setNumOfSensors(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void experimentModuleBasicSettingWindow::sig_setPitch(const float & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void experimentModuleBasicSettingWindow::sig_setRadius(const float & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void experimentModuleBasicSettingWindow::sig_setAngleRange(const float & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void experimentModuleBasicSettingWindow::sig_setArraySensorType(const ArraySensorType _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void experimentModuleBasicSettingWindow::sig_setLabType(const LabType _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void experimentModuleBasicSettingWindow::sig_preShowSensorMap()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}
QT_WARNING_POP
