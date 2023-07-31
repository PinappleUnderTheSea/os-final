/****************************************************************************
** Meta object code from reading C++ file 'moduledatamodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/interface/moduledatamodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'moduledatamodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dccV23__ModuleDataModel_t {
    QByteArrayData data[9];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dccV23__ModuleDataModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dccV23__ModuleDataModel_t qt_meta_stringdata_dccV23__ModuleDataModel = {
    {
QT_MOC_LITERAL(0, 0, 23), // "dccV23::ModuleDataModel"
QT_MOC_LITERAL(1, 24, 22), // "newModuleDislayNameLen"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 13), // "onDataChanged"
QT_MOC_LITERAL(4, 62, 3), // "obj"
QT_MOC_LITERAL(5, 66, 13), // "onInsertChild"
QT_MOC_LITERAL(6, 80, 18), // "ModuleObject*const"
QT_MOC_LITERAL(7, 99, 6), // "module"
QT_MOC_LITERAL(8, 106, 14) // "onRemovedChild"

    },
    "dccV23::ModuleDataModel\0newModuleDislayNameLen\0"
    "\0onDataChanged\0obj\0onInsertChild\0"
    "ModuleObject*const\0module\0onRemovedChild"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dccV23__ModuleDataModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   37,    2, 0x0a /* Public */,
       5,    1,   40,    2, 0x0a /* Public */,
       8,    1,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QObjectStar,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void dccV23::ModuleDataModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ModuleDataModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->newModuleDislayNameLen((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onDataChanged((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 2: _t->onInsertChild((*reinterpret_cast< ModuleObject*const(*)>(_a[1]))); break;
        case 3: _t->onRemovedChild((*reinterpret_cast< ModuleObject*const(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ModuleDataModel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModuleDataModel::newModuleDislayNameLen)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject dccV23::ModuleDataModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractItemModel::staticMetaObject>(),
    qt_meta_stringdata_dccV23__ModuleDataModel.data,
    qt_meta_data_dccV23__ModuleDataModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *dccV23::ModuleDataModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dccV23::ModuleDataModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dccV23__ModuleDataModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractItemModel::qt_metacast(_clname);
}

int dccV23::ModuleDataModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemModel::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void dccV23::ModuleDataModel::newModuleDislayNameLen(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
