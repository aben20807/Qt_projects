/****************************************************************************
** Meta object code from reading C++ file 'schedule.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/schedule.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'schedule.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Schedule_t {
    QByteArrayData data[8];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Schedule_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Schedule_t qt_meta_stringdata_Schedule = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Schedule"
QT_MOC_LITERAL(1, 9, 8), // "close_me"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 11), // "updateTable"
QT_MOC_LITERAL(4, 31, 11), // "close_child"
QT_MOC_LITERAL(5, 43, 29), // "on_buttonBox_okCancel_clicked"
QT_MOC_LITERAL(6, 73, 16), // "QAbstractButton*"
QT_MOC_LITERAL(7, 90, 6) // "button"

    },
    "Schedule\0close_me\0\0updateTable\0"
    "close_child\0on_buttonBox_okCancel_clicked\0"
    "QAbstractButton*\0button"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Schedule[] = {

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
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   36,    2, 0x08 /* Private */,
       5,    1,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void Schedule::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Schedule *_t = static_cast<Schedule *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->close_me(); break;
        case 1: _t->updateTable(); break;
        case 2: _t->close_child(); break;
        case 3: _t->on_buttonBox_okCancel_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Schedule::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Schedule::close_me)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Schedule::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Schedule::updateTable)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Schedule::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Schedule.data,
      qt_meta_data_Schedule,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Schedule::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Schedule::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Schedule.stringdata0))
        return static_cast<void*>(const_cast< Schedule*>(this));
    return QDialog::qt_metacast(_clname);
}

int Schedule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void Schedule::close_me()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Schedule::updateTable()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
