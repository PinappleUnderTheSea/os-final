/****************************************************************************
** Meta object code from reading C++ file 'defappworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/plugin-defaultapp/operation/defappworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'defappworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DefAppWorker_t {
    QByteArrayData data[13];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DefAppWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DefAppWorker_t qt_meta_stringdata_DefAppWorker = {
    {
QT_MOC_LITERAL(0, 0, 12), // "DefAppWorker"
QT_MOC_LITERAL(1, 13, 16), // "onReverseUserApp"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 8), // "category"
QT_MOC_LITERAL(4, 40, 3), // "App"
QT_MOC_LITERAL(5, 44, 4), // "item"
QT_MOC_LITERAL(6, 49, 13), // "onGetListApps"
QT_MOC_LITERAL(7, 63, 12), // "onDelUserApp"
QT_MOC_LITERAL(8, 76, 4), // "mine"
QT_MOC_LITERAL(9, 81, 13), // "onAddUserFile"
QT_MOC_LITERAL(10, 95, 4), // "mime"
QT_MOC_LITERAL(11, 100, 9), // "QFileInfo"
QT_MOC_LITERAL(12, 110, 4) // "info"

    },
    "DefAppWorker\0onReverseUserApp\0\0category\0"
    "App\0item\0onGetListApps\0onDelUserApp\0"
    "mine\0onAddUserFile\0mime\0QFileInfo\0"
    "info"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DefAppWorker[] = {

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
       1,    2,   34,    2, 0x0a /* Public */,
       6,    0,   39,    2, 0x0a /* Public */,
       7,    2,   40,    2, 0x0a /* Public */,
       9,    2,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    8,    5,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 11,   10,   12,

       0        // eod
};

void DefAppWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DefAppWorker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onReverseUserApp((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const App(*)>(_a[2]))); break;
        case 1: _t->onGetListApps(); break;
        case 2: _t->onDelUserApp((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const App(*)>(_a[2]))); break;
        case 3: _t->onAddUserFile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QFileInfo(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DefAppWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DefAppWorker.data,
    qt_meta_data_DefAppWorker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DefAppWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DefAppWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DefAppWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DefAppWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
