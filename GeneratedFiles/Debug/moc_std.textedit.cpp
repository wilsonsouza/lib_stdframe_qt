/****************************************************************************
** Meta object code from reading C++ file 'std.textedit.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/std.textedit.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'std.textedit.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_std__TextEdit_t {
    QByteArrayData data[15];
    char stringdata0[191];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_std__TextEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_std__TextEdit_t qt_meta_stringdata_std__TextEdit = {
    {
QT_MOC_LITERAL(0, 0, 13), // "std::TextEdit"
QT_MOC_LITERAL(1, 14, 15), // "OnCopyAvailable"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 4), // "bYes"
QT_MOC_LITERAL(4, 36, 9), // "TextEdit*"
QT_MOC_LITERAL(5, 46, 6), // "Sender"
QT_MOC_LITERAL(6, 53, 26), // "OnCurrentCharFormatChanged"
QT_MOC_LITERAL(7, 80, 15), // "QTextCharFormat"
QT_MOC_LITERAL(8, 96, 1), // "f"
QT_MOC_LITERAL(9, 98, 23), // "OnCursorPositionChanged"
QT_MOC_LITERAL(10, 122, 15), // "OnRedoAvailable"
QT_MOC_LITERAL(11, 138, 3), // "bOK"
QT_MOC_LITERAL(12, 142, 18), // "OnSelectionChanged"
QT_MOC_LITERAL(13, 161, 13), // "OnTextChanged"
QT_MOC_LITERAL(14, 175, 15) // "OnUndoAvailable"

    },
    "std::TextEdit\0OnCopyAvailable\0\0bYes\0"
    "TextEdit*\0Sender\0OnCurrentCharFormatChanged\0"
    "QTextCharFormat\0f\0OnCursorPositionChanged\0"
    "OnRedoAvailable\0bOK\0OnSelectionChanged\0"
    "OnTextChanged\0OnUndoAvailable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_std__TextEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       6,    2,   54,    2, 0x06 /* Public */,
       9,    1,   59,    2, 0x06 /* Public */,
      10,    2,   62,    2, 0x06 /* Public */,
      12,    1,   67,    2, 0x06 /* Public */,
      13,    1,   70,    2, 0x06 /* Public */,
      14,    2,   73,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 4,    3,    5,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 4,    8,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 4,   11,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 4,   11,    5,

       0        // eod
};

void std::TextEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TextEdit *_t = static_cast<TextEdit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnCopyAvailable((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< TextEdit*(*)>(_a[2]))); break;
        case 1: _t->OnCurrentCharFormatChanged((*reinterpret_cast< const QTextCharFormat(*)>(_a[1])),(*reinterpret_cast< TextEdit*(*)>(_a[2]))); break;
        case 2: _t->OnCursorPositionChanged((*reinterpret_cast< TextEdit*(*)>(_a[1]))); break;
        case 3: _t->OnRedoAvailable((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< TextEdit*(*)>(_a[2]))); break;
        case 4: _t->OnSelectionChanged((*reinterpret_cast< TextEdit*(*)>(_a[1]))); break;
        case 5: _t->OnTextChanged((*reinterpret_cast< TextEdit*(*)>(_a[1]))); break;
        case 6: _t->OnUndoAvailable((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< TextEdit*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TextEdit* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TextEdit* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TextEdit* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TextEdit* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TextEdit* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TextEdit* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TextEdit* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TextEdit::*_t)(bool , TextEdit * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TextEdit::OnCopyAvailable)) {
                *result = 0;
            }
        }
        {
            typedef void (TextEdit::*_t)(const QTextCharFormat & , TextEdit * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TextEdit::OnCurrentCharFormatChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (TextEdit::*_t)(TextEdit * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TextEdit::OnCursorPositionChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (TextEdit::*_t)(bool , TextEdit * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TextEdit::OnRedoAvailable)) {
                *result = 3;
            }
        }
        {
            typedef void (TextEdit::*_t)(TextEdit * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TextEdit::OnSelectionChanged)) {
                *result = 4;
            }
        }
        {
            typedef void (TextEdit::*_t)(TextEdit * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TextEdit::OnTextChanged)) {
                *result = 5;
            }
        }
        {
            typedef void (TextEdit::*_t)(bool , TextEdit * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TextEdit::OnUndoAvailable)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject std::TextEdit::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_std__TextEdit.data,
      qt_meta_data_std__TextEdit,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *std::TextEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *std::TextEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_std__TextEdit.stringdata0))
        return static_cast<void*>(const_cast< TextEdit*>(this));
    return QTextEdit::qt_metacast(_clname);
}

int std::TextEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void std::TextEdit::OnCopyAvailable(bool _t1, TextEdit * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void std::TextEdit::OnCurrentCharFormatChanged(const QTextCharFormat & _t1, TextEdit * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void std::TextEdit::OnCursorPositionChanged(TextEdit * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void std::TextEdit::OnRedoAvailable(bool _t1, TextEdit * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void std::TextEdit::OnSelectionChanged(TextEdit * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void std::TextEdit::OnTextChanged(TextEdit * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void std::TextEdit::OnUndoAvailable(bool _t1, TextEdit * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
