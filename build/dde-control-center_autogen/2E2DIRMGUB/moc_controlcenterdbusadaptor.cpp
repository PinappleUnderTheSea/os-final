/****************************************************************************
** Meta object code from reading C++ file 'controlcenterdbusadaptor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/frame/controlcenterdbusadaptor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controlcenterdbusadaptor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dccV23__ControlCenterDBusAdaptor_t {
    QByteArrayData data[12];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dccV23__ControlCenterDBusAdaptor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dccV23__ControlCenterDBusAdaptor_t qt_meta_stringdata_dccV23__ControlCenterDBusAdaptor = {
    {
QT_MOC_LITERAL(0, 0, 32), // "dccV23::ControlCenterDBusAdaptor"
QT_MOC_LITERAL(1, 33, 15), // "D-Bus Interface"
QT_MOC_LITERAL(2, 49, 29), // "org.deepin.dde.ControlCenter1"
QT_MOC_LITERAL(3, 79, 4), // "Exit"
QT_MOC_LITERAL(4, 84, 0), // ""
QT_MOC_LITERAL(5, 85, 4), // "Hide"
QT_MOC_LITERAL(6, 90, 4), // "Show"
QT_MOC_LITERAL(7, 95, 8), // "ShowHome"
QT_MOC_LITERAL(8, 104, 8), // "ShowPage"
QT_MOC_LITERAL(9, 113, 3), // "url"
QT_MOC_LITERAL(10, 117, 6), // "Toggle"
QT_MOC_LITERAL(11, 124, 12) // "GetAllModule"

    },
    "dccV23::ControlCenterDBusAdaptor\0"
    "D-Bus Interface\0org.deepin.dde.ControlCenter1\0"
    "Exit\0\0Hide\0Show\0ShowHome\0ShowPage\0url\0"
    "Toggle\0GetAllModule"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dccV23__ControlCenterDBusAdaptor[] = {

 // content:
       8,       // revision
       0,       // classname
       1,   14, // classinfo
       7,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,

 // slots: name, argc, parameters, tag, flags
       3,    0,   51,    4, 0x0a /* Public */,
       5,    0,   52,    4, 0x0a /* Public */,
       6,    0,   53,    4, 0x0a /* Public */,
       7,    0,   54,    4, 0x0a /* Public */,
       8,    1,   55,    4, 0x0a /* Public */,
      10,    0,   58,    4, 0x0a /* Public */,
      11,    0,   59,    4, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::QString,

       0        // eod
};

void dccV23::ControlCenterDBusAdaptor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ControlCenterDBusAdaptor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Exit(); break;
        case 1: _t->Hide(); break;
        case 2: _t->Show(); break;
        case 3: _t->ShowHome(); break;
        case 4: _t->ShowPage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->Toggle(); break;
        case 6: { QString _r = _t->GetAllModule();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject dccV23::ControlCenterDBusAdaptor::staticMetaObject = { {
    QMetaObject::SuperData::link<QDBusAbstractAdaptor::staticMetaObject>(),
    qt_meta_stringdata_dccV23__ControlCenterDBusAdaptor.data,
    qt_meta_data_dccV23__ControlCenterDBusAdaptor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *dccV23::ControlCenterDBusAdaptor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dccV23::ControlCenterDBusAdaptor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dccV23__ControlCenterDBusAdaptor.stringdata0))
        return static_cast<void*>(this);
    return QDBusAbstractAdaptor::qt_metacast(_clname);
}

int dccV23::ControlCenterDBusAdaptor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractAdaptor::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
struct qt_meta_stringdata_dccV23__DBusControlCenterGrandSearchService_t {
    QByteArrayData data[8];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dccV23__DBusControlCenterGrandSearchService_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dccV23__DBusControlCenterGrandSearchService_t qt_meta_stringdata_dccV23__DBusControlCenterGrandSearchService = {
    {
QT_MOC_LITERAL(0, 0, 43), // "dccV23::DBusControlCenterGran..."
QT_MOC_LITERAL(1, 44, 15), // "D-Bus Interface"
QT_MOC_LITERAL(2, 60, 41), // "org.deepin.dde.ControlCenter1..."
QT_MOC_LITERAL(3, 102, 6), // "Search"
QT_MOC_LITERAL(4, 109, 0), // ""
QT_MOC_LITERAL(5, 110, 4), // "json"
QT_MOC_LITERAL(6, 115, 4), // "Stop"
QT_MOC_LITERAL(7, 120, 6) // "Action"

    },
    "dccV23::DBusControlCenterGrandSearchService\0"
    "D-Bus Interface\0"
    "org.deepin.dde.ControlCenter1.GrandSearch\0"
    "Search\0\0json\0Stop\0Action"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dccV23__DBusControlCenterGrandSearchService[] = {

 // content:
       8,       // revision
       0,       // classname
       1,   14, // classinfo
       3,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,

 // slots: name, argc, parameters, tag, flags
       3,    1,   31,    4, 0x0a /* Public */,
       6,    1,   34,    4, 0x0a /* Public */,
       7,    1,   37,    4, 0x0a /* Public */,

 // slots: parameters
    QMetaType::QString, QMetaType::QString,    5,
    QMetaType::Bool, QMetaType::QString,    5,
    QMetaType::Bool, QMetaType::QString,    5,

       0        // eod
};

void dccV23::DBusControlCenterGrandSearchService::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DBusControlCenterGrandSearchService *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { QString _r = _t->Search((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->Stop((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->Action((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject dccV23::DBusControlCenterGrandSearchService::staticMetaObject = { {
    QMetaObject::SuperData::link<QDBusAbstractAdaptor::staticMetaObject>(),
    qt_meta_stringdata_dccV23__DBusControlCenterGrandSearchService.data,
    qt_meta_data_dccV23__DBusControlCenterGrandSearchService,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *dccV23::DBusControlCenterGrandSearchService::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dccV23::DBusControlCenterGrandSearchService::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dccV23__DBusControlCenterGrandSearchService.stringdata0))
        return static_cast<void*>(this);
    return QDBusAbstractAdaptor::qt_metacast(_clname);
}

int dccV23::DBusControlCenterGrandSearchService::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractAdaptor::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
