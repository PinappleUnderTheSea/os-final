/****************************************************************************
** Meta object code from reading C++ file 'hlistmodule.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../include/interface/hlistmodule.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hlistmodule.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dccV23__HListModule_t {
    QByteArrayData data[1];
    char stringdata0[20];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dccV23__HListModule_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dccV23__HListModule_t qt_meta_stringdata_dccV23__HListModule = {
    {
QT_MOC_LITERAL(0, 0, 19) // "dccV23::HListModule"

    },
    "dccV23::HListModule"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dccV23__HListModule[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void dccV23::HListModule::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject dccV23::HListModule::staticMetaObject = { {
    QMetaObject::SuperData::link<ModuleObject::staticMetaObject>(),
    qt_meta_stringdata_dccV23__HListModule.data,
    qt_meta_data_dccV23__HListModule,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *dccV23::HListModule::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dccV23::HListModule::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dccV23__HListModule.stringdata0))
        return static_cast<void*>(this);
    return ModuleObject::qt_metacast(_clname);
}

int dccV23::HListModule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ModuleObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
