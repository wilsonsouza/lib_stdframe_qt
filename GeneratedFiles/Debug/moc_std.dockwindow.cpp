/****************************************************************************
** Meta object code from reading C++ file 'std.dockwindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/std.dockwindow.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'std.dockwindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_std__DockWindow_t {
    QByteArrayData data[16];
    char stringdata0[231];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_std__DockWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_std__DockWindow_t qt_meta_stringdata_std__DockWindow = {
    {
QT_MOC_LITERAL(0, 0, 15), // "std::DockWindow"
QT_MOC_LITERAL(1, 16, 21), // "OnAllowedAreasChanged"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 19), // "Qt::DockWidgetAreas"
QT_MOC_LITERAL(4, 59, 4), // "_dwa"
QT_MOC_LITERAL(5, 64, 11), // "DockWindow*"
QT_MOC_LITERAL(6, 76, 6), // "Sender"
QT_MOC_LITERAL(7, 83, 21), // "OnDockLocationChanged"
QT_MOC_LITERAL(8, 105, 18), // "Qt::DockWidgetArea"
QT_MOC_LITERAL(9, 124, 17), // "OnFeaturesChanged"
QT_MOC_LITERAL(10, 142, 31), // "QDockWidget::DockWidgetFeatures"
QT_MOC_LITERAL(11, 174, 2), // "_f"
QT_MOC_LITERAL(12, 177, 17), // "OnToplevelChanged"
QT_MOC_LITERAL(13, 195, 5), // "_btop"
QT_MOC_LITERAL(14, 201, 19), // "OnVisibilityChanged"
QT_MOC_LITERAL(15, 221, 9) // "_bvisible"

    },
    "std::DockWindow\0OnAllowedAreasChanged\0"
    "\0Qt::DockWidgetAreas\0_dwa\0DockWindow*\0"
    "Sender\0OnDockLocationChanged\0"
    "Qt::DockWidgetArea\0OnFeaturesChanged\0"
    "QDockWidget::DockWidgetFeatures\0_f\0"
    "OnToplevelChanged\0_btop\0OnVisibilityChanged\0"
    "_bvisible"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_std__DockWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       7,    2,   44,    2, 0x06 /* Public */,
       9,    2,   49,    2, 0x06 /* Public */,
      12,    2,   54,    2, 0x06 /* Public */,
      14,    2,   59,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 5,   11,    6,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 5,   13,    6,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 5,   15,    6,

       0        // eod
};

void std::DockWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DockWindow *_t = static_cast<DockWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnAllowedAreasChanged((*reinterpret_cast< Qt::DockWidgetAreas(*)>(_a[1])),(*reinterpret_cast< DockWindow*(*)>(_a[2]))); break;
        case 1: _t->OnDockLocationChanged((*reinterpret_cast< Qt::DockWidgetArea(*)>(_a[1])),(*reinterpret_cast< DockWindow*(*)>(_a[2]))); break;
        case 2: _t->OnFeaturesChanged((*reinterpret_cast< QDockWidget::DockWidgetFeatures(*)>(_a[1])),(*reinterpret_cast< DockWindow*(*)>(_a[2]))); break;
        case 3: _t->OnToplevelChanged((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< DockWindow*(*)>(_a[2]))); break;
        case 4: _t->OnVisibilityChanged((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< DockWindow*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DockWindow* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DockWindow* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DockWindow* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DockWindow* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DockWindow* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DockWindow::*_t)(Qt::DockWidgetAreas , DockWindow * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DockWindow::OnAllowedAreasChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (DockWindow::*_t)(Qt::DockWidgetArea , DockWindow * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DockWindow::OnDockLocationChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (DockWindow::*_t)(QDockWidget::DockWidgetFeatures , DockWindow * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DockWindow::OnFeaturesChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (DockWindow::*_t)(bool , DockWindow * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DockWindow::OnToplevelChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (DockWindow::*_t)(bool , DockWindow * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DockWindow::OnVisibilityChanged)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject std::DockWindow::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_std__DockWindow.data,
      qt_meta_data_std__DockWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *std::DockWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *std::DockWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_std__DockWindow.stringdata0))
        return static_cast<void*>(const_cast< DockWindow*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int std::DockWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
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
void std::DockWindow::OnAllowedAreasChanged(Qt::DockWidgetAreas _t1, DockWindow * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void std::DockWindow::OnDockLocationChanged(Qt::DockWidgetArea _t1, DockWindow * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void std::DockWindow::OnFeaturesChanged(QDockWidget::DockWidgetFeatures _t1, DockWindow * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void std::DockWindow::OnToplevelChanged(bool _t1, DockWindow * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void std::DockWindow::OnVisibilityChanged(bool _t1, DockWindow * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
