/****************************************************************************
** Meta object code from reading C++ file 'nonnegativeimagingthread.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../nonnegativeimagingthread.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nonnegativeimagingthread.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSNonNegativeImagingThreadENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSNonNegativeImagingThreadENDCLASS = QtMocHelpers::stringData(
    "NonNegativeImagingThread",
    "sigUpdateProgress",
    "",
    "sigFinishProgress",
    "sig_appendLog",
    "message",
    "sig_showRunningTime",
    "runningType",
    "runningTimes",
    "sig_plotNonNegativeImagingTAI",
    "sig_setIsUpdateNonNegativeImagingTAIFalse",
    "slotCancelNonNegativeImagingProgress"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSNonNegativeImagingThreadENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x06,    1 /* Public */,
       3,    0,   59,    2, 0x06,    3 /* Public */,
       4,    1,   60,    2, 0x06,    4 /* Public */,
       6,    2,   63,    2, 0x06,    6 /* Public */,
       9,    0,   68,    2, 0x06,    9 /* Public */,
      10,    0,   69,    2, 0x06,   10 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    0,   70,    2, 0x0a,   11 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    7,    8,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject NonNegativeImagingThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_CLASSNonNegativeImagingThreadENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSNonNegativeImagingThreadENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSNonNegativeImagingThreadENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<NonNegativeImagingThread, std::true_type>,
        // method 'sigUpdateProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'sigFinishProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sig_appendLog'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'sig_showRunningTime'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'sig_plotNonNegativeImagingTAI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sig_setIsUpdateNonNegativeImagingTAIFalse'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotCancelNonNegativeImagingProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void NonNegativeImagingThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NonNegativeImagingThread *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sigUpdateProgress((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->sigFinishProgress(); break;
        case 2: _t->sig_appendLog((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->sig_showRunningTime((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 4: _t->sig_plotNonNegativeImagingTAI(); break;
        case 5: _t->sig_setIsUpdateNonNegativeImagingTAIFalse(); break;
        case 6: _t->slotCancelNonNegativeImagingProgress(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NonNegativeImagingThread::*)(int );
            if (_t _q_method = &NonNegativeImagingThread::sigUpdateProgress; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NonNegativeImagingThread::*)();
            if (_t _q_method = &NonNegativeImagingThread::sigFinishProgress; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (NonNegativeImagingThread::*)(QString );
            if (_t _q_method = &NonNegativeImagingThread::sig_appendLog; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (NonNegativeImagingThread::*)(QString , int );
            if (_t _q_method = &NonNegativeImagingThread::sig_showRunningTime; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (NonNegativeImagingThread::*)();
            if (_t _q_method = &NonNegativeImagingThread::sig_plotNonNegativeImagingTAI; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (NonNegativeImagingThread::*)();
            if (_t _q_method = &NonNegativeImagingThread::sig_setIsUpdateNonNegativeImagingTAIFalse; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject *NonNegativeImagingThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NonNegativeImagingThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSNonNegativeImagingThreadENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int NonNegativeImagingThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void NonNegativeImagingThread::sigUpdateProgress(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NonNegativeImagingThread::sigFinishProgress()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void NonNegativeImagingThread::sig_appendLog(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void NonNegativeImagingThread::sig_showRunningTime(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void NonNegativeImagingThread::sig_plotNonNegativeImagingTAI()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void NonNegativeImagingThread::sig_setIsUpdateNonNegativeImagingTAIFalse()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
