/****************************************************************************
** Meta object code from reading C++ file 'std.toolbar.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/std.toolbar.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'std.toolbar.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_std__ToolBar_t {
    QByteArrayData data[24];
    char stringdata0[318];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_std__ToolBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_std__ToolBar_t qt_meta_stringdata_std__ToolBar = {
    {
QT_MOC_LITERAL(0, 0, 12), // "std::ToolBar"
QT_MOC_LITERAL(1, 13, 9), // "OnCommand"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "Action*"
QT_MOC_LITERAL(4, 32, 7), // "pAction"
QT_MOC_LITERAL(5, 40, 8), // "ToolBar*"
QT_MOC_LITERAL(6, 49, 7), // "pSender"
QT_MOC_LITERAL(7, 57, 21), // "OnAllowedAreasChanged"
QT_MOC_LITERAL(8, 79, 16), // "Qt::ToolBarAreas"
QT_MOC_LITERAL(9, 96, 7), // "tbAreas"
QT_MOC_LITERAL(10, 104, 17), // "OnIconSizeChanged"
QT_MOC_LITERAL(11, 122, 9), // "sIconsize"
QT_MOC_LITERAL(12, 132, 16), // "OnMovableChanged"
QT_MOC_LITERAL(13, 149, 8), // "bMovable"
QT_MOC_LITERAL(14, 158, 20), // "OnOrientationChanged"
QT_MOC_LITERAL(15, 179, 15), // "Qt::Orientation"
QT_MOC_LITERAL(16, 195, 12), // "oOrientation"
QT_MOC_LITERAL(17, 208, 24), // "OnToolButtonStyleChanged"
QT_MOC_LITERAL(18, 233, 19), // "Qt::ToolButtonStyle"
QT_MOC_LITERAL(19, 253, 7), // "tbStyle"
QT_MOC_LITERAL(20, 261, 17), // "OnTopLevelChanged"
QT_MOC_LITERAL(21, 279, 9), // "bTopLevel"
QT_MOC_LITERAL(22, 289, 19), // "OnVisibilityChanged"
QT_MOC_LITERAL(23, 309, 8) // "bVisible"

    },
    "std::ToolBar\0OnCommand\0\0Action*\0pAction\0"
    "ToolBar*\0pSender\0OnAllowedAreasChanged\0"
    "Qt::ToolBarAreas\0tbAreas\0OnIconSizeChanged\0"
    "sIconsize\0OnMovableChanged\0bMovable\0"
    "OnOrientationChanged\0Qt::Orientation\0"
    "oOrientation\0OnToolButtonStyleChanged\0"
    "Qt::ToolButtonStyle\0tbStyle\0"
    "OnTopLevelChanged\0bTopLevel\0"
    "OnVisibilityChanged\0bVisible"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_std__ToolBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,
       7,    2,   59,    2, 0x06 /* Public */,
      10,    2,   64,    2, 0x06 /* Public */,
      12,    2,   69,    2, 0x06 /* Public */,
      14,    2,   74,    2, 0x06 /* Public */,
      17,    2,   79,    2, 0x06 /* Public */,
      20,    2,   84,    2, 0x06 /* Public */,
      22,    2,   89,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 5,    9,    6,
    QMetaType::Void, QMetaType::QSize, 0x80000000 | 5,   11,    6,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 5,   13,    6,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 5,   16,    6,
    QMetaType::Void, 0x80000000 | 18, 0x80000000 | 5,   19,    6,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 5,   21,    6,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 5,   23,    6,

       0        // eod
};

void std::ToolBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ToolBar *_t = static_cast<ToolBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnCommand((*reinterpret_cast< Action*(*)>(_a[1])),(*reinterpret_cast< ToolBar*(*)>(_a[2]))); break;
        case 1: _t->OnAllowedAreasChanged((*reinterpret_cast< Qt::ToolBarAreas(*)>(_a[1])),(*reinterpret_cast< ToolBar*(*)>(_a[2]))); break;
        case 2: _t->OnIconSizeChanged((*reinterpret_cast< const QSize(*)>(_a[1])),(*reinterpret_cast< ToolBar*(*)>(_a[2]))); break;
        case 3: _t->OnMovableChanged((*reinterpret_cast< const bool(*)>(_a[1])),(*reinterpret_cast< ToolBar*(*)>(_a[2]))); break;
        case 4: _t->OnOrientationChanged((*reinterpret_cast< Qt::Orientation(*)>(_a[1])),(*reinterpret_cast< ToolBar*(*)>(_a[2]))); break;
        case 5: _t->OnToolButtonStyleChanged((*reinterpret_cast< Qt::ToolButtonStyle(*)>(_a[1])),(*reinterpret_cast< ToolBar*(*)>(_a[2]))); break;
        case 6: _t->OnTopLevelChanged((*reinterpret_cast< const bool(*)>(_a[1])),(*reinterpret_cast< ToolBar*(*)>(_a[2]))); break;
        case 7: _t->OnVisibilityChanged((*reinterpret_cast< const bool(*)>(_a[1])),(*reinterpret_cast< ToolBar*(*)>(_a[2]))); break;
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
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ToolBar* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ToolBar* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ToolBar* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ToolBar* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ToolBar* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ToolBar* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ToolBar* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ToolBar* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ToolBar::*_t)(Action * , ToolBar * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBar::OnCommand)) {
                *result = 0;
            }
        }
        {
            typedef void (ToolBar::*_t)(Qt::ToolBarAreas , ToolBar * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBar::OnAllowedAreasChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (ToolBar::*_t)(const QSize & , ToolBar * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBar::OnIconSizeChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (ToolBar::*_t)(bool const & , ToolBar * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBar::OnMovableChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (ToolBar::*_t)(Qt::Orientation , ToolBar * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBar::OnOrientationChanged)) {
                *result = 4;
            }
        }
        {
            typedef void (ToolBar::*_t)(Qt::ToolButtonStyle , ToolBar * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBar::OnToolButtonStyleChanged)) {
                *result = 5;
            }
        }
        {
            typedef void (ToolBar::*_t)(bool const & , ToolBar * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBar::OnTopLevelChanged)) {
                *result = 6;
            }
        }
        {
            typedef void (ToolBar::*_t)(bool const & , ToolBar * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBar::OnVisibilityChanged)) {
                *result = 7;
            }
        }
    }
}

const QMetaObject std::ToolBar::staticMetaObject = {
    { &QToolBar::staticMetaObject, qt_meta_stringdata_std__ToolBar.data,
      qt_meta_data_std__ToolBar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *std::ToolBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *std::ToolBar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_std__ToolBar.stringdata0))
        return static_cast<void*>(const_cast< ToolBar*>(this));
    return QToolBar::qt_metacast(_clname);
}

int std::ToolBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void std::ToolBar::OnCommand(Action * _t1, ToolBar * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void std::ToolBar::OnAllowedAreasChanged(Qt::ToolBarAreas _t1, ToolBar * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void std::ToolBar::OnIconSizeChanged(const QSize & _t1, ToolBar * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void std::ToolBar::OnMovableChanged(bool const & _t1, ToolBar * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void std::ToolBar::OnOrientationChanged(Qt::Orientation _t1, ToolBar * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void std::ToolBar::OnToolButtonStyleChanged(Qt::ToolButtonStyle _t1, ToolBar * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void std::ToolBar::OnTopLevelChanged(bool const & _t1, ToolBar * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void std::ToolBar::OnVisibilityChanged(bool const & _t1, ToolBar * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
