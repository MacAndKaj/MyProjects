/****************************************************************************
** Meta object code from reading C++ file 'qbalancewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WDSApp/qbalancewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qbalancewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QBalanceWidget_t {
    QByteArrayData data[9];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QBalanceWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QBalanceWidget_t qt_meta_stringdata_QBalanceWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "QBalanceWidget"
QT_MOC_LITERAL(1, 15, 11), // "RollChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 4), // "int&"
QT_MOC_LITERAL(4, 33, 3), // "ang"
QT_MOC_LITERAL(5, 37, 12), // "PitchChanged"
QT_MOC_LITERAL(6, 50, 10), // "ChangeRoll"
QT_MOC_LITERAL(7, 61, 9), // "uint16_t&"
QT_MOC_LITERAL(8, 71, 11) // "ChangePitch"

    },
    "QBalanceWidget\0RollChanged\0\0int&\0ang\0"
    "PitchChanged\0ChangeRoll\0uint16_t&\0"
    "ChangePitch"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QBalanceWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       5,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   40,    2, 0x0a /* Public */,
       8,    1,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 7,    2,

       0        // eod
};

void QBalanceWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QBalanceWidget *_t = static_cast<QBalanceWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RollChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->PitchChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->ChangeRoll((*reinterpret_cast< uint16_t(*)>(_a[1]))); break;
        case 3: _t->ChangePitch((*reinterpret_cast< uint16_t(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QBalanceWidget::*_t)(int & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QBalanceWidget::RollChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (QBalanceWidget::*_t)(int & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QBalanceWidget::PitchChanged)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject QBalanceWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QBalanceWidget.data,
      qt_meta_data_QBalanceWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QBalanceWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QBalanceWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QBalanceWidget.stringdata0))
        return static_cast<void*>(const_cast< QBalanceWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int QBalanceWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QBalanceWidget::RollChanged(int & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QBalanceWidget::PitchChanged(int & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE