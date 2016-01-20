/****************************************************************************
** Meta object code from reading C++ file 'std.combobox.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/std.combobox.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'std.combobox.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_std__ComboBox_t {
    QByteArrayData data[12];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_std__ComboBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_std__ComboBox_t qt_meta_stringdata_std__ComboBox = {
    {
QT_MOC_LITERAL(0, 0, 13), // "std::ComboBox"
QT_MOC_LITERAL(1, 14, 21), // "OnCurrentIndexChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 6), // "nIndex"
QT_MOC_LITERAL(4, 44, 9), // "ComboBox*"
QT_MOC_LITERAL(5, 54, 6), // "Sender"
QT_MOC_LITERAL(6, 61, 17), // "OnEditTextChanged"
QT_MOC_LITERAL(7, 79, 12), // "std::ustring"
QT_MOC_LITERAL(8, 92, 7), // "strText"
QT_MOC_LITERAL(9, 100, 11), // "OnActivated"
QT_MOC_LITERAL(10, 112, 19), // "OnUpdateCurrentData"
QT_MOC_LITERAL(11, 132, 7) // "strData"

    },
    "std::ComboBox\0OnCurrentIndexChanged\0"
    "\0nIndex\0ComboBox*\0Sender\0OnEditTextChanged\0"
    "std::ustring\0strText\0OnActivated\0"
    "OnUpdateCurrentData\0strData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_std__ComboBox[] = {

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
       9,    2,   44,    2, 0x06 /* Public */,
      10,    2,   49,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 4,    8,    5,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 7,    5,   11,

       0        // eod
};

void std::ComboBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ComboBox *_t = static_cast<ComboBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnCurrentIndexChanged((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< ComboBox*(*)>(_a[2]))); break;
        case 1: _t->OnEditTextChanged((*reinterpret_cast< const std::ustring(*)>(_a[1])),(*reinterpret_cast< ComboBox*(*)>(_a[2]))); break;
        case 2: _t->OnActivated((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< ComboBox*(*)>(_a[2]))); break;
        case 3: _t->OnUpdateCurrentData((*reinterpret_cast< ComboBox*(*)>(_a[1])),(*reinterpret_cast< const std::ustring(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ComboBox* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ComboBox* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ComboBox* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ComboBox* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ComboBox::*_t)(int const & , ComboBox * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ComboBox::OnCurrentIndexChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (ComboBox::*_t)(std::ustring const & , ComboBox * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ComboBox::OnEditTextChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (ComboBox::*_t)(int const & , ComboBox * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ComboBox::OnActivated)) {
                *result = 2;
            }
        }
        {
            typedef void (ComboBox::*_t)(ComboBox * , std::ustring const & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ComboBox::OnUpdateCurrentData)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject std::ComboBox::staticMetaObject = {
    { &QComboBox::staticMetaObject, qt_meta_stringdata_std__ComboBox.data,
      qt_meta_data_std__ComboBox,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *std::ComboBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *std::ComboBox::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_std__ComboBox.stringdata0))
        return static_cast<void*>(const_cast< ComboBox*>(this));
    return QComboBox::qt_metacast(_clname);
}

int std::ComboBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QComboBox::qt_metacall(_c, _id, _a);
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
void std::ComboBox::OnCurrentIndexChanged(int const & _t1, ComboBox * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void std::ComboBox::OnEditTextChanged(std::ustring const & _t1, ComboBox * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void std::ComboBox::OnActivated(int const & _t1, ComboBox * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void std::ComboBox::OnUpdateCurrentData(ComboBox * _t1, std::ustring const & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
