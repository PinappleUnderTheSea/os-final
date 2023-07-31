/****************************************************************************
** Meta object code from reading C++ file 'dccdbusinterface_p.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/widgets/dccdbusinterface_p.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dccdbusinterface_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dccV23__DCCDBusInterfacePrivate_t {
    QByteArrayData data[15];
    char stringdata0[229];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dccV23__DCCDBusInterfacePrivate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dccV23__DCCDBusInterfacePrivate_t qt_meta_stringdata_dccV23__DCCDBusInterfacePrivate = {
    {
QT_MOC_LITERAL(0, 0, 31), // "dccV23::DCCDBusInterfacePrivate"
QT_MOC_LITERAL(1, 32, 19), // "onPropertiesChanged"
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 13), // "interfaceName"
QT_MOC_LITERAL(4, 67, 17), // "changedProperties"
QT_MOC_LITERAL(5, 85, 21), // "invalidatedProperties"
QT_MOC_LITERAL(6, 107, 23), // "onAsyncPropertyFinished"
QT_MOC_LITERAL(7, 131, 24), // "QDBusPendingCallWatcher*"
QT_MOC_LITERAL(8, 156, 1), // "w"
QT_MOC_LITERAL(9, 158, 18), // "onDBusNameHasOwner"
QT_MOC_LITERAL(10, 177, 5), // "valid"
QT_MOC_LITERAL(11, 183, 22), // "onDBusNameOwnerChanged"
QT_MOC_LITERAL(12, 206, 4), // "name"
QT_MOC_LITERAL(13, 211, 8), // "oldOwner"
QT_MOC_LITERAL(14, 220, 8) // "newOWner"

    },
    "dccV23::DCCDBusInterfacePrivate\0"
    "onPropertiesChanged\0\0interfaceName\0"
    "changedProperties\0invalidatedProperties\0"
    "onAsyncPropertyFinished\0"
    "QDBusPendingCallWatcher*\0w\0"
    "onDBusNameHasOwner\0valid\0"
    "onDBusNameOwnerChanged\0name\0oldOwner\0"
    "newOWner"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dccV23__DCCDBusInterfacePrivate[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   34,    2, 0x08 /* Private */,
       6,    1,   41,    2, 0x08 /* Private */,
       9,    1,   44,    2, 0x08 /* Private */,
      11,    3,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QVariantMap, QMetaType::QStringList,    3,    4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   12,   13,   14,

       0        // eod
};

void dccV23::DCCDBusInterfacePrivate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DCCDBusInterfacePrivate *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onPropertiesChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariantMap(*)>(_a[2])),(*reinterpret_cast< const QStringList(*)>(_a[3]))); break;
        case 1: _t->onAsyncPropertyFinished((*reinterpret_cast< QDBusPendingCallWatcher*(*)>(_a[1]))); break;
        case 2: _t->onDBusNameHasOwner((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->onDBusNameOwnerChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusPendingCallWatcher* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject dccV23::DCCDBusInterfacePrivate::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_dccV23__DCCDBusInterfacePrivate.data,
    qt_meta_data_dccV23__DCCDBusInterfacePrivate,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *dccV23::DCCDBusInterfacePrivate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dccV23::DCCDBusInterfacePrivate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dccV23__DCCDBusInterfacePrivate.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int dccV23::DCCDBusInterfacePrivate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
