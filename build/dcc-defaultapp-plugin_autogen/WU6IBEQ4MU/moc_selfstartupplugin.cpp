/****************************************************************************
** Meta object code from reading C++ file 'selfstartupplugin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/plugin-defaultapp/window/selfstartupplugin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selfstartupplugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SelfStartupPlugin_t {
    QByteArrayData data[1];
    char stringdata0[18];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SelfStartupPlugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SelfStartupPlugin_t qt_meta_stringdata_SelfStartupPlugin = {
    {
QT_MOC_LITERAL(0, 0, 17) // "SelfStartupPlugin"

    },
    "SelfStartupPlugin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SelfStartupPlugin[] = {

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

void SelfStartupPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject SelfStartupPlugin::staticMetaObject = { {
    QMetaObject::SuperData::link<dccV23::PluginInterface::staticMetaObject>(),
    qt_meta_stringdata_SelfStartupPlugin.data,
    qt_meta_data_SelfStartupPlugin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SelfStartupPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SelfStartupPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SelfStartupPlugin.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "org.deepin.dde.ControlCenter.Plugin/1.4"))
        return static_cast< dccV23::PluginInterface*>(this);
    return dccV23::PluginInterface::qt_metacast(_clname);
}

int SelfStartupPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = dccV23::PluginInterface::qt_metacall(_c, _id, _a);
    return _id;
}

QT_PLUGIN_METADATA_SECTION
static constexpr unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x27,  'c',  'o',  'm',  '.',  'd', 
    'e',  'e',  'p',  'i',  'n',  '.',  'd',  'd', 
    'e',  '.',  'C',  'o',  'n',  't',  'r',  'o', 
    'l',  'C',  'e',  'n',  't',  'e',  'r',  '.', 
    'S',  'e',  'l',  'f',  'S',  'a',  'r',  't', 
    'u',  'p', 
    // "className"
    0x03,  0x71,  'S',  'e',  'l',  'f',  'S',  't', 
    'a',  'r',  't',  'u',  'p',  'P',  'l',  'u', 
    'g',  'i',  'n', 
    // "MetaData"
    0x04,  0xa1,  0x63,  'a',  'p',  'i',  0x65,  '1', 
    '.',  '0',  '.',  '0', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(SelfStartupPlugin, SelfStartupPlugin)

struct qt_meta_stringdata_SelfStartupModule_t {
    QByteArrayData data[1];
    char stringdata0[18];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SelfStartupModule_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SelfStartupModule_t qt_meta_stringdata_SelfStartupModule = {
    {
QT_MOC_LITERAL(0, 0, 17) // "SelfStartupModule"

    },
    "SelfStartupModule"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SelfStartupModule[] = {

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

void SelfStartupModule::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject SelfStartupModule::staticMetaObject = { {
    QMetaObject::SuperData::link<dccV23::PageModule::staticMetaObject>(),
    qt_meta_stringdata_SelfStartupModule.data,
    qt_meta_data_SelfStartupModule,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SelfStartupModule::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SelfStartupModule::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SelfStartupModule.stringdata0))
        return static_cast<void*>(this);
    return dccV23::PageModule::qt_metacast(_clname);
}

int SelfStartupModule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = dccV23::PageModule::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_SelfStartupDetailModule_t {
    QByteArrayData data[1];
    char stringdata0[24];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SelfStartupDetailModule_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SelfStartupDetailModule_t qt_meta_stringdata_SelfStartupDetailModule = {
    {
QT_MOC_LITERAL(0, 0, 23) // "SelfStartupDetailModule"

    },
    "SelfStartupDetailModule"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SelfStartupDetailModule[] = {

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

void SelfStartupDetailModule::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject SelfStartupDetailModule::staticMetaObject = { {
    QMetaObject::SuperData::link<dccV23::ModuleObject::staticMetaObject>(),
    qt_meta_stringdata_SelfStartupDetailModule.data,
    qt_meta_data_SelfStartupDetailModule,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SelfStartupDetailModule::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SelfStartupDetailModule::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SelfStartupDetailModule.stringdata0))
        return static_cast<void*>(this);
    return dccV23::ModuleObject::qt_metacast(_clname);
}

int SelfStartupDetailModule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = dccV23::ModuleObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
