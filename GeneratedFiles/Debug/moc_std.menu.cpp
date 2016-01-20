/****************************************************************************
** Meta object code from reading C++ file 'std.menu.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/std.menu.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'std.menu.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_std__Menu_t {
    QByteArrayData data[10];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_std__Menu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_std__Menu_t qt_meta_stringdata_std__Menu = {
    {
QT_MOC_LITERAL(0, 0, 9), // "std::Menu"
QT_MOC_LITERAL(1, 10, 13), // "OnAbouttoHide"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 5), // "Menu*"
QT_MOC_LITERAL(4, 31, 6), // "Sender"
QT_MOC_LITERAL(5, 38, 13), // "OnAbouttoShow"
QT_MOC_LITERAL(6, 52, 9), // "OnHovered"
QT_MOC_LITERAL(7, 62, 7), // "Action*"
QT_MOC_LITERAL(8, 70, 7), // "pAction"
QT_MOC_LITERAL(9, 78, 9) // "OnCommand"

    },
    "std::Menu\0OnAbouttoHide\0\0Menu*\0Sender\0"
    "OnAbouttoShow\0OnHovered\0Action*\0pAction\0"
    "OnCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_std__Menu[] = {

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
       1,    1,   34,    2, 0x06 /* Public */,
       5,    1,   37,    2, 0x06 /* Public */,
       6,    2,   40,    2, 0x06 /* Public */,
       9,    2,   45,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 3,    8,    4,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 3,    8,    4,

       0        // eod
};

void std::Menu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Menu *_t = static_cast<Menu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnAbouttoHide((*reinterpret_cast< Menu*(*)>(_a[1]))); break;
        case 1: _t->OnAbouttoShow((*reinterpret_cast< Menu*(*)>(_a[1]))); break;
        case 2: _t->OnHovered((*reinterpret_cast< Action*(*)>(_a[1])),(*reinterpret_cast< Menu*(*)>(_a[2]))); break;
        case 3: _t->OnCommand((*reinterpret_cast< Action*(*)>(_a[1])),(*reinterpret_cast< Menu*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Menu* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Menu* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Menu* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Menu* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Menu::*_t)(Menu * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Menu::OnAbouttoHide)) {
                *result = 0;
            }
        }
        {
            typedef void (Menu::*_t)(Menu * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Menu::OnAbouttoShow)) {
                *result = 1;
            }
        }
        {
            typedef void (Menu::*_t)(Action * , Menu * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Menu::OnHovered)) {
                *result = 2;
            }
        }
        {
            typedef void (Menu::*_t)(Action * , Menu * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Menu::OnCommand)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject std::Menu::staticMetaObject = {
    { &QMenu::staticMetaObject, qt_meta_stringdata_std__Menu.data,
      qt_meta_data_std__Menu,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *std::Menu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *std::Menu::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_std__Menu.stringdata0))
        return static_cast<void*>(const_cast< Menu*>(this));
    return QMenu::qt_metacast(_clname);
}

int std::Menu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
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
void std::Menu::OnAbouttoHide(Menu * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void std::Menu::OnAbouttoShow(Menu * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void std::Menu::OnHovered(Action * _t1, Menu * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void std::Menu::OnCommand(Action * _t1, Menu * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
