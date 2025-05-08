/****************************************************************************
** Meta object code from reading C++ file 'myfigure.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../myfigure.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myfigure.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMyFigureENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMyFigureENDCLASS = QtMocHelpers::stringData(
    "MyFigure",
    "on_toolButton_confirmTitle_clicked",
    "",
    "on_lineEdit_title_returnPressed",
    "on_saveFigButton_clicked",
    "on_toolButton_confirmColorbar_clicked",
    "on_lineEdit_xLabel_returnPressed",
    "on_lineEdit_yLabel_returnPressed",
    "checkXAxisRange",
    "QCPRange",
    "newRange",
    "checkYAxisRange",
    "on_toolButton_confirmXLabel_clicked",
    "on_toolButton_confirmYLabel_clicked",
    "on_toolButton_confirmLineStyle_clicked",
    "on_toolButton_confirmWordType_clicked",
    "on_toolButton_confirmWordSize_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMyFigureENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x08,    1 /* Private */,
       3,    0,   93,    2, 0x08,    2 /* Private */,
       4,    0,   94,    2, 0x08,    3 /* Private */,
       5,    0,   95,    2, 0x08,    4 /* Private */,
       6,    0,   96,    2, 0x08,    5 /* Private */,
       7,    0,   97,    2, 0x08,    6 /* Private */,
       8,    1,   98,    2, 0x08,    7 /* Private */,
      11,    1,  101,    2, 0x08,    9 /* Private */,
      12,    0,  104,    2, 0x08,   11 /* Private */,
      13,    0,  105,    2, 0x08,   12 /* Private */,
      14,    0,  106,    2, 0x08,   13 /* Private */,
      15,    0,  107,    2, 0x08,   14 /* Private */,
      16,    0,  108,    2, 0x08,   15 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MyFigure::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMyFigureENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMyFigureENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMyFigureENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MyFigure, std::true_type>,
        // method 'on_toolButton_confirmTitle_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_lineEdit_title_returnPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_saveFigButton_clicked'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_toolButton_confirmColorbar_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_lineEdit_xLabel_returnPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_lineEdit_yLabel_returnPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'checkXAxisRange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QCPRange &, std::false_type>,
        // method 'checkYAxisRange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QCPRange &, std::false_type>,
        // method 'on_toolButton_confirmXLabel_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_toolButton_confirmYLabel_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_toolButton_confirmLineStyle_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_toolButton_confirmWordType_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_toolButton_confirmWordSize_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MyFigure::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyFigure *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_toolButton_confirmTitle_clicked(); break;
        case 1: _t->on_lineEdit_title_returnPressed(); break;
        case 2: { bool _r = _t->on_saveFigButton_clicked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->on_toolButton_confirmColorbar_clicked(); break;
        case 4: _t->on_lineEdit_xLabel_returnPressed(); break;
        case 5: _t->on_lineEdit_yLabel_returnPressed(); break;
        case 6: _t->checkXAxisRange((*reinterpret_cast< std::add_pointer_t<QCPRange>>(_a[1]))); break;
        case 7: _t->checkYAxisRange((*reinterpret_cast< std::add_pointer_t<QCPRange>>(_a[1]))); break;
        case 8: _t->on_toolButton_confirmXLabel_clicked(); break;
        case 9: _t->on_toolButton_confirmYLabel_clicked(); break;
        case 10: _t->on_toolButton_confirmLineStyle_clicked(); break;
        case 11: _t->on_toolButton_confirmWordType_clicked(); break;
        case 12: _t->on_toolButton_confirmWordSize_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *MyFigure::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyFigure::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMyFigureENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MyFigure::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
