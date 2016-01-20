/****************************************************************************
** Meta object code from reading C++ file 'std.tabbed.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/std.tabbed.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'std.tabbed.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_std__Tabbed_t {
    QByteArrayData data[12];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_std__Tabbed_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_std__Tabbed_t qt_meta_stringdata_std__Tabbed = {
    {
QT_MOC_LITERAL(0, 0, 11), // "std::Tabbed"
QT_MOC_LITERAL(1, 12, 16), // "OnCurrentChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 6), // "nIndex"
QT_MOC_LITERAL(4, 37, 7), // "Tabbed*"
QT_MOC_LITERAL(5, 45, 6), // "Sender"
QT_MOC_LITERAL(6, 52, 19), // "OnTabCloseRequested"
QT_MOC_LITERAL(7, 72, 10), // "OnTabMoved"
QT_MOC_LITERAL(8, 83, 4), // "from"
QT_MOC_LITERAL(9, 88, 2), // "to"
QT_MOC_LITERAL(10, 91, 10), // "OnUpdateUI"
QT_MOC_LITERAL(11, 102, 8) // "bEnabled"

    },
    "std::Tabbed\0OnCurrentChanged\0\0nIndex\0"
    "Tabbed*\0Sender\0OnTabCloseRequested\0"
    "OnTabMoved\0from\0to\0OnUpdateUI\0bEnabled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_std__Tabbed[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       6,    2,   39,    2, 0x06 /* Public */,
       7,    3,   44,    2, 0x06 /* Public */,
      10,    2,   51,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 4,    8,    9,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,   11,

       0        // eod
};

void std::Tabbed::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Tabbed *_t = static_cast<Tabbed *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnCurrentChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Tabbed*(*)>(_a[2]))); break;
        case 1: _t->OnTabCloseRequested((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Tabbed*(*)>(_a[2]))); break;
        case 2: _t->OnTabMoved((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< Tabbed*(*)>(_a[3]))); break;
        case 3: _t->OnUpdateUI((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Tabbed* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Tabbed* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Tabbed* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Tabbed::*_t)(int , Tabbed * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tabbed::OnCurrentChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (Tabbed::*_t)(int , Tabbed * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tabbed::OnTabCloseRequested)) {
                *result = 1;
            }
        }
        {
            typedef void (Tabbed::*_t)(int const & , int const & , Tabbed * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tabbed::OnTabMoved)) {
                *result = 2;
            }
        }
        {
            typedef void (Tabbed::*_t)(int const & , bool const & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tabbed::OnUpdateUI)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject std::Tabbed::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_std__Tabbed.data,
      qt_meta_data_std__Tabbed,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *std::Tabbed::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *std::Tabbed::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_std__Tabbed.stringdata0))
        return static_cast<void*>(const_cast< Tabbed*>(this));
    return QTabWidget::qt_metacast(_clname);
}

int std::Tabbed::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void std::Tabbed::OnCurrentChanged(int _t1, Tabbed * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void std::Tabbed::OnTabCloseRequested(int _t1, Tabbed * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void std::Tabbed::OnTabMoved(int const & _t1, int const & _t2, Tabbed * _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void std::Tabbed::OnUpdateUI(int const & _t1, bool const & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
