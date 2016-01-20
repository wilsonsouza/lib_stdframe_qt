/****************************************************************************
** Meta object code from reading C++ file 'stdx.action.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/stdx.action.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stdx.action.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_stdx__Action_t {
    QByteArrayData data[14];
    char stringdata[138];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_stdx__Action_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_stdx__Action_t qt_meta_stringdata_stdx__Action = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 10),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 7),
QT_MOC_LITERAL(4, 33, 6),
QT_MOC_LITERAL(5, 40, 12),
QT_MOC_LITERAL(6, 53, 17),
QT_MOC_LITERAL(7, 71, 12),
QT_MOC_LITERAL(8, 84, 3),
QT_MOC_LITERAL(9, 88, 9),
QT_MOC_LITERAL(10, 98, 9),
QT_MOC_LITERAL(11, 108, 9),
QT_MOC_LITERAL(12, 118, 8),
QT_MOC_LITERAL(13, 127, 9)
    },
    "stdx::Action\0OnUpdateUI\0\0Action*\0"
    "Sender\0number<bool>\0bEnabledOrChecked\0"
    "number<uint>\0uID\0OnChanged\0OnHovered\0"
    "OnToggled\0bChecked\0OnCommand\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_stdx__Action[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   39,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       9,    1,   46,    2, 0x0a,
      10,    1,   49,    2, 0x0a,
      11,    2,   52,    2, 0x0a,
      13,    2,   57,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 7,    4,    6,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 3,   12,    4,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 3,   12,    4,

       0        // eod
};

void stdx::Action::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Action *_t = static_cast<Action *>(_o);
        switch (_id) {
        case 0: _t->OnUpdateUI((*reinterpret_cast< Action*(*)>(_a[1])),(*reinterpret_cast< number<bool>(*)>(_a[2])),(*reinterpret_cast< number<uint>(*)>(_a[3]))); break;
        case 1: _t->OnChanged((*reinterpret_cast< Action*(*)>(_a[1]))); break;
        case 2: _t->OnHovered((*reinterpret_cast< Action*(*)>(_a[1]))); break;
        case 3: _t->OnToggled((*reinterpret_cast< number<bool>(*)>(_a[1])),(*reinterpret_cast< Action*(*)>(_a[2]))); break;
        case 4: _t->OnCommand((*reinterpret_cast< number<bool>(*)>(_a[1])),(*reinterpret_cast< Action*(*)>(_a[2]))); break;
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
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Action* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Action* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Action* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Action* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Action::*_t)(Action * , number<bool> const & , number<unsigned int> const & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Action::OnUpdateUI)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject stdx::Action::staticMetaObject = {
    { &QAction::staticMetaObject, qt_meta_stringdata_stdx__Action.data,
      qt_meta_data_stdx__Action,  qt_static_metacall, 0, 0}
};


const QMetaObject *stdx::Action::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *stdx::Action::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_stdx__Action.stringdata))
        return static_cast<void*>(const_cast< Action*>(this));
    return QAction::qt_metacast(_clname);
}

int stdx::Action::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAction::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void stdx::Action::OnUpdateUI(Action * _t1, number<bool> const & _t2, number<unsigned int> const & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
