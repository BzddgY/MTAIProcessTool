/****************************************************************************
** Meta object code from reading C++ file 'expimagingmodule.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../expimagingmodule.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'expimagingmodule.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSExpImagingModuleENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSExpImagingModuleENDCLASS = QtMocHelpers::stringData(
    "ExpImagingModule",
    "sig_setRayImagingType",
    "",
    "RayImagingType",
    "sig_setNonNegativeImagingType",
    "NonNegativeImagingType",
    "sig_preShowRayImagingTAI",
    "sig_preShowNonNegativeImagingTAI",
    "sigCancelProgress",
    "sigCancelNonNegativeImagingProgress",
    "sigAppendLog",
    "message",
    "sig_plotRayImagingTAI",
    "sig_plotNonNegativeImagingTAI",
    "on_comboBox_rayReconstructionType_currentIndexChanged",
    "index",
    "on_pushButton_preShowRayImagingTAI_clicked",
    "on_checkBox_stateChanged",
    "arg1",
    "slotUpdateProgress",
    "count",
    "slotFinishProgress",
    "slotCancelProgress",
    "slot_showRunningTime",
    "runningType",
    "runningTimes",
    "slot_appendLog",
    "slotUpdateNonNegativeImagingProgress",
    "slotFinishNonNegativeImagingProgress",
    "slotCancelNonNegativeImagingProgress",
    "on_comboBox_nonNegativeReconType_currentIndexChanged",
    "on_pushButton_preShowRayImagingTAI_2_clicked",
    "slot_plotRayImagingTAI",
    "slot_plotNonNegativeImagingTAI",
    "slot_setIsUpdateRayImagingTAIFalse",
    "slot_setIsUpdateNonNegativeImagingTAIFalse",
    "on_doubleSpinBox_x1_valueChanged",
    "on_doubleSpinBox_x1_editingFinished",
    "on_doubleSpinBox_x2_editingFinished",
    "on_doubleSpinBox_dx_editingFinished",
    "on_doubleSpinBox_y1_editingFinished",
    "on_doubleSpinBox_y2_editingFinished",
    "on_doubleSpinBox_dy_editingFinished",
    "on_spinBox_nonNegativeWidth_editingFinished"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSExpImagingModuleENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      34,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  218,    2, 0x06,    1 /* Public */,
       4,    1,  221,    2, 0x06,    3 /* Public */,
       6,    0,  224,    2, 0x06,    5 /* Public */,
       7,    0,  225,    2, 0x06,    6 /* Public */,
       8,    0,  226,    2, 0x06,    7 /* Public */,
       9,    0,  227,    2, 0x06,    8 /* Public */,
      10,    1,  228,    2, 0x06,    9 /* Public */,
      12,    0,  231,    2, 0x06,   11 /* Public */,
      13,    0,  232,    2, 0x06,   12 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      14,    1,  233,    2, 0x08,   13 /* Private */,
      16,    0,  236,    2, 0x08,   15 /* Private */,
      17,    1,  237,    2, 0x08,   16 /* Private */,
      19,    1,  240,    2, 0x08,   18 /* Private */,
      21,    0,  243,    2, 0x08,   20 /* Private */,
      22,    0,  244,    2, 0x08,   21 /* Private */,
      23,    2,  245,    2, 0x08,   22 /* Private */,
      26,    1,  250,    2, 0x08,   25 /* Private */,
      27,    1,  253,    2, 0x08,   27 /* Private */,
      28,    0,  256,    2, 0x08,   29 /* Private */,
      29,    0,  257,    2, 0x08,   30 /* Private */,
      30,    1,  258,    2, 0x08,   31 /* Private */,
      31,    0,  261,    2, 0x08,   33 /* Private */,
      32,    0,  262,    2, 0x08,   34 /* Private */,
      33,    0,  263,    2, 0x08,   35 /* Private */,
      34,    0,  264,    2, 0x08,   36 /* Private */,
      35,    0,  265,    2, 0x08,   37 /* Private */,
      36,    1,  266,    2, 0x08,   38 /* Private */,
      37,    0,  269,    2, 0x08,   40 /* Private */,
      38,    0,  270,    2, 0x08,   41 /* Private */,
      39,    0,  271,    2, 0x08,   42 /* Private */,
      40,    0,  272,    2, 0x08,   43 /* Private */,
      41,    0,  273,    2, 0x08,   44 /* Private */,
      42,    0,  274,    2, 0x08,   45 /* Private */,
      43,    0,  275,    2, 0x08,   46 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   24,   25,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ExpImagingModule::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSExpImagingModuleENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSExpImagingModuleENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSExpImagingModuleENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ExpImagingModule, std::true_type>,
        // method 'sig_setRayImagingType'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const RayImagingType &, std::false_type>,
        // method 'sig_setNonNegativeImagingType'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const NonNegativeImagingType &, std::false_type>,
        // method 'sig_preShowRayImagingTAI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sig_preShowNonNegativeImagingTAI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sigCancelProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sigCancelNonNegativeImagingProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sigAppendLog'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'sig_plotRayImagingTAI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sig_plotNonNegativeImagingTAI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comboBox_rayReconstructionType_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pushButton_preShowRayImagingTAI_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_checkBox_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slotUpdateProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slotFinishProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotCancelProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_showRunningTime'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slot_appendLog'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'slotUpdateNonNegativeImagingProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slotFinishNonNegativeImagingProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotCancelNonNegativeImagingProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comboBox_nonNegativeReconType_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pushButton_preShowRayImagingTAI_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_plotRayImagingTAI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_plotNonNegativeImagingTAI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_setIsUpdateRayImagingTAIFalse'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_setIsUpdateNonNegativeImagingTAIFalse'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_doubleSpinBox_x1_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_doubleSpinBox_x1_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_doubleSpinBox_x2_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_doubleSpinBox_dx_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_doubleSpinBox_y1_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_doubleSpinBox_y2_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_doubleSpinBox_dy_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinBox_nonNegativeWidth_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ExpImagingModule::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ExpImagingModule *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sig_setRayImagingType((*reinterpret_cast< std::add_pointer_t<RayImagingType>>(_a[1]))); break;
        case 1: _t->sig_setNonNegativeImagingType((*reinterpret_cast< std::add_pointer_t<NonNegativeImagingType>>(_a[1]))); break;
        case 2: _t->sig_preShowRayImagingTAI(); break;
        case 3: _t->sig_preShowNonNegativeImagingTAI(); break;
        case 4: _t->sigCancelProgress(); break;
        case 5: _t->sigCancelNonNegativeImagingProgress(); break;
        case 6: _t->sigAppendLog((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->sig_plotRayImagingTAI(); break;
        case 8: _t->sig_plotNonNegativeImagingTAI(); break;
        case 9: _t->on_comboBox_rayReconstructionType_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->on_pushButton_preShowRayImagingTAI_clicked(); break;
        case 11: _t->on_checkBox_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->slotUpdateProgress((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->slotFinishProgress(); break;
        case 14: _t->slotCancelProgress(); break;
        case 15: _t->slot_showRunningTime((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 16: _t->slot_appendLog((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 17: _t->slotUpdateNonNegativeImagingProgress((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 18: _t->slotFinishNonNegativeImagingProgress(); break;
        case 19: _t->slotCancelNonNegativeImagingProgress(); break;
        case 20: _t->on_comboBox_nonNegativeReconType_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 21: _t->on_pushButton_preShowRayImagingTAI_2_clicked(); break;
        case 22: _t->slot_plotRayImagingTAI(); break;
        case 23: _t->slot_plotNonNegativeImagingTAI(); break;
        case 24: _t->slot_setIsUpdateRayImagingTAIFalse(); break;
        case 25: _t->slot_setIsUpdateNonNegativeImagingTAIFalse(); break;
        case 26: _t->on_doubleSpinBox_x1_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 27: _t->on_doubleSpinBox_x1_editingFinished(); break;
        case 28: _t->on_doubleSpinBox_x2_editingFinished(); break;
        case 29: _t->on_doubleSpinBox_dx_editingFinished(); break;
        case 30: _t->on_doubleSpinBox_y1_editingFinished(); break;
        case 31: _t->on_doubleSpinBox_y2_editingFinished(); break;
        case 32: _t->on_doubleSpinBox_dy_editingFinished(); break;
        case 33: _t->on_spinBox_nonNegativeWidth_editingFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ExpImagingModule::*)(const RayImagingType & );
            if (_t _q_method = &ExpImagingModule::sig_setRayImagingType; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ExpImagingModule::*)(const NonNegativeImagingType & );
            if (_t _q_method = &ExpImagingModule::sig_setNonNegativeImagingType; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ExpImagingModule::*)();
            if (_t _q_method = &ExpImagingModule::sig_preShowRayImagingTAI; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ExpImagingModule::*)();
            if (_t _q_method = &ExpImagingModule::sig_preShowNonNegativeImagingTAI; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ExpImagingModule::*)();
            if (_t _q_method = &ExpImagingModule::sigCancelProgress; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ExpImagingModule::*)();
            if (_t _q_method = &ExpImagingModule::sigCancelNonNegativeImagingProgress; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ExpImagingModule::*)(QString );
            if (_t _q_method = &ExpImagingModule::sigAppendLog; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ExpImagingModule::*)();
            if (_t _q_method = &ExpImagingModule::sig_plotRayImagingTAI; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (ExpImagingModule::*)();
            if (_t _q_method = &ExpImagingModule::sig_plotNonNegativeImagingTAI; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject *ExpImagingModule::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExpImagingModule::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSExpImagingModuleENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ExpImagingModule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ExpImagingModule::sig_setRayImagingType(const RayImagingType & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ExpImagingModule::sig_setNonNegativeImagingType(const NonNegativeImagingType & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ExpImagingModule::sig_preShowRayImagingTAI()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ExpImagingModule::sig_preShowNonNegativeImagingTAI()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ExpImagingModule::sigCancelProgress()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ExpImagingModule::sigCancelNonNegativeImagingProgress()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void ExpImagingModule::sigAppendLog(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ExpImagingModule::sig_plotRayImagingTAI()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void ExpImagingModule::sig_plotNonNegativeImagingTAI()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
