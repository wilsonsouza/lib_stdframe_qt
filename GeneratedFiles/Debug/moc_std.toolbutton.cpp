/****************************************************************************
** Meta object code from reading C++ file 'std.toolbutton.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/std.toolbutton.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'std.toolbutton.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_std__ToolButton_t {
    QByteArrayData data[11];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_std__ToolButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_std__ToolButton_t qt_meta_stringdata_std__ToolButton = {
    {
QT_MOC_LITERAL(0, 0, 15), // "std::ToolButton"
QT_MOC_LITERAL(1, 16, 9), // "OnClicked"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 7), // "Action*"
QT_MOC_LITERAL(4, 35, 7), // "pAction"
QT_MOC_LITERAL(5, 43, 11), // "ToolButton*"
QT_MOC_LITERAL(6, 55, 6), // "Sender"
QT_MOC_LITERAL(7, 62, 10), // "OnUpdateUI"
QT_MOC_LITERAL(8, 73, 7), // "lpOwner"
QT_MOC_LITERAL(9, 81, 4), // "oOld"
QT_MOC_LITERAL(10, 86, 4) // "oNew"

    },
    "std::ToolButton\0OnClicked\0\0Action*\0"
    "pAction\0ToolButton*\0Sender\0OnUpdateUI\0"
    "lpOwner\0oOld\0oNew"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_std__ToolButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,
       7,    3,   29,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::QVariant, QMetaType::QVariant,    8,    9,   10,

       0        // eod
};

void std::ToolButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ToolButton *_t = static_cast<ToolButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnClicked((*reinterpret_cast< Action*(*)>(_a[1])),(*reinterpret_cast< ToolButton*(*)>(_a[2]))); break;
        case 1: _t->OnUpdateUI((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])),(*reinterpret_cast< QVariant(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Action* >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ToolButton* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ToolButton::*_t)(Action * , ToolButton * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolButton::OnClicked)) {
                *result = 0;
            }
        }
        {
            typedef void (ToolButton::*_t)(QObject * , QVariant , QVariant );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolButton::OnUpdateUI)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject std::ToolButton::staticMetaObject = {
    { &QToolButton::staticMetaObject, qt_meta_stringdata_std__ToolButton.data,
      qt_meta_data_std__ToolButton,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *std::ToolButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *std::ToolButton::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_std__ToolButton.stringdata0))
        return static_cast<void*>(const_cast< ToolButton*>(this));
    return QToolButton::qt_metacast(_clname);
}

int std::ToolButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void std::ToolButton::OnClicked(Action * _t1, ToolButton * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void std::ToolButton::OnUpdateUI(QObject * _t1, QVariant _t2, QVariant _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
