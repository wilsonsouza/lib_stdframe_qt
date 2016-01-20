/****************************************************************************
** Meta object code from reading C++ file 'std.treeview.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/std.treeview.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'std.treeview.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_std__TreeView_t {
    QByteArrayData data[15];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_std__TreeView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_std__TreeView_t qt_meta_stringdata_std__TreeView = {
    {
QT_MOC_LITERAL(0, 0, 13), // "std::TreeView"
QT_MOC_LITERAL(1, 14, 11), // "OnCollapsed"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "Index"
QT_MOC_LITERAL(4, 33, 9), // "TreeView*"
QT_MOC_LITERAL(5, 43, 6), // "Sender"
QT_MOC_LITERAL(6, 50, 10), // "OnExpanded"
QT_MOC_LITERAL(7, 61, 11), // "OnActivated"
QT_MOC_LITERAL(8, 73, 9), // "OnClicked"
QT_MOC_LITERAL(9, 83, 15), // "OnDoubleClicked"
QT_MOC_LITERAL(10, 99, 9), // "OnEntered"
QT_MOC_LITERAL(11, 109, 9), // "OnPressed"
QT_MOC_LITERAL(12, 119, 17), // "OnViewportEntered"
QT_MOC_LITERAL(13, 137, 28), // "OnCustomContextMenuRequested"
QT_MOC_LITERAL(14, 166, 2) // "pt"

    },
    "std::TreeView\0OnCollapsed\0\0Index\0"
    "TreeView*\0Sender\0OnExpanded\0OnActivated\0"
    "OnClicked\0OnDoubleClicked\0OnEntered\0"
    "OnPressed\0OnViewportEntered\0"
    "OnCustomContextMenuRequested\0pt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_std__TreeView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,
       6,    2,   64,    2, 0x06 /* Public */,
       7,    2,   69,    2, 0x06 /* Public */,
       8,    2,   74,    2, 0x06 /* Public */,
       9,    2,   79,    2, 0x06 /* Public */,
      10,    2,   84,    2, 0x06 /* Public */,
      11,    2,   89,    2, 0x06 /* Public */,
      12,    1,   94,    2, 0x06 /* Public */,
      13,    2,   97,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QModelIndex, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QModelIndex, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QModelIndex, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QModelIndex, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QModelIndex, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QModelIndex, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QModelIndex, 0x80000000 | 4,    3,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::QPoint, 0x80000000 | 4,   14,    5,

       0        // eod
};

void std::TreeView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TreeView *_t = static_cast<TreeView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnCollapsed((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< TreeView*(*)>(_a[2]))); break;
        case 1: _t->OnExpanded((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< TreeView*(*)>(_a[2]))); break;
        case 2: _t->OnActivated((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< TreeView*(*)>(_a[2]))); break;
        case 3: _t->OnClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< TreeView*(*)>(_a[2]))); break;
        case 4: _t->OnDoubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< TreeView*(*)>(_a[2]))); break;
        case 5: _t->OnEntered((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< TreeView*(*)>(_a[2]))); break;
        case 6: _t->OnPressed((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< TreeView*(*)>(_a[2]))); break;
        case 7: _t->OnViewportEntered((*reinterpret_cast< TreeView*(*)>(_a[1]))); break;
        case 8: _t->OnCustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1])),(*reinterpret_cast< TreeView*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TreeView* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TreeView* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TreeView* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TreeView* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TreeView* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TreeView* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TreeView* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TreeView* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TreeView* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TreeView::*_t)(const QModelIndex & , TreeView * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TreeView::OnCollapsed)) {
                *result = 0;
            }
        }
        {
            typedef void (TreeView::*_t)(const QModelIndex & , TreeView * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TreeView::OnExpanded)) {
                *result = 1;
            }
        }
        {
            typedef void (TreeView::*_t)(const QModelIndex & , TreeView * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TreeView::OnActivated)) {
                *result = 2;
            }
        }
        {
            typedef void (TreeView::*_t)(const QModelIndex & , TreeView * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TreeView::OnClicked)) {
                *result = 3;
            }
        }
        {
            typedef void (TreeView::*_t)(const QModelIndex & , TreeView * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TreeView::OnDoubleClicked)) {
                *result = 4;
            }
        }
        {
            typedef void (TreeView::*_t)(const QModelIndex & , TreeView * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TreeView::OnEntered)) {
                *result = 5;
            }
        }
        {
            typedef void (TreeView::*_t)(const QModelIndex & , TreeView * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TreeView::OnPressed)) {
                *result = 6;
            }
        }
        {
            typedef void (TreeView::*_t)(TreeView * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TreeView::OnViewportEntered)) {
                *result = 7;
            }
        }
        {
            typedef void (TreeView::*_t)(QPoint const & , TreeView * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TreeView::OnCustomContextMenuRequested)) {
                *result = 8;
            }
        }
    }
}

const QMetaObject std::TreeView::staticMetaObject = {
    { &QTreeView::staticMetaObject, qt_meta_stringdata_std__TreeView.data,
      qt_meta_data_std__TreeView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *std::TreeView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *std::TreeView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_std__TreeView.stringdata0))
        return static_cast<void*>(const_cast< TreeView*>(this));
    return QTreeView::qt_metacast(_clname);
}

int std::TreeView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void std::TreeView::OnCollapsed(const QModelIndex & _t1, TreeView * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void std::TreeView::OnExpanded(const QModelIndex & _t1, TreeView * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void std::TreeView::OnActivated(const QModelIndex & _t1, TreeView * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void std::TreeView::OnClicked(const QModelIndex & _t1, TreeView * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void std::TreeView::OnDoubleClicked(const QModelIndex & _t1, TreeView * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void std::TreeView::OnEntered(const QModelIndex & _t1, TreeView * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void std::TreeView::OnPressed(const QModelIndex & _t1, TreeView * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void std::TreeView::OnViewportEntered(TreeView * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void std::TreeView::OnCustomContextMenuRequested(QPoint const & _t1, TreeView * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
