/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/frame/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dccV23__MainWindow_t {
    QByteArrayData data[15];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dccV23__MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dccV23__MainWindow_t qt_meta_stringdata_dccV23__MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 18), // "dccV23::MainWindow"
QT_MOC_LITERAL(1, 19, 11), // "onAddModule"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 18), // "ModuleObject*const"
QT_MOC_LITERAL(4, 51, 6), // "module"
QT_MOC_LITERAL(5, 58, 14), // "onRemoveModule"
QT_MOC_LITERAL(6, 73, 11), // "onTriggered"
QT_MOC_LITERAL(7, 85, 19), // "onChildStateChanged"
QT_MOC_LITERAL(8, 105, 5), // "child"
QT_MOC_LITERAL(9, 111, 8), // "uint32_t"
QT_MOC_LITERAL(10, 120, 4), // "flag"
QT_MOC_LITERAL(11, 125, 5), // "state"
QT_MOC_LITERAL(12, 131, 19), // "onModuleDataChanged"
QT_MOC_LITERAL(13, 151, 18), // "updateModuleConfig"
QT_MOC_LITERAL(14, 170, 3) // "key"

    },
    "dccV23::MainWindow\0onAddModule\0\0"
    "ModuleObject*const\0module\0onRemoveModule\0"
    "onTriggered\0onChildStateChanged\0child\0"
    "uint32_t\0flag\0state\0onModuleDataChanged\0"
    "updateModuleConfig\0key"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dccV23__MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       5,    1,   47,    2, 0x08 /* Private */,
       6,    0,   50,    2, 0x08 /* Private */,
       7,    3,   51,    2, 0x08 /* Private */,
      12,    0,   58,    2, 0x08 /* Private */,
      13,    1,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 9, QMetaType::Bool,    8,   10,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,

       0        // eod
};

void dccV23::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onAddModule((*reinterpret_cast< ModuleObject*const(*)>(_a[1]))); break;
        case 1: _t->onRemoveModule((*reinterpret_cast< ModuleObject*const(*)>(_a[1]))); break;
        case 2: _t->onTriggered(); break;
        case 3: _t->onChildStateChanged((*reinterpret_cast< ModuleObject*const(*)>(_a[1])),(*reinterpret_cast< uint32_t(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 4: _t->onModuleDataChanged(); break;
        case 5: _t->updateModuleConfig((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject dccV23::MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<Dtk::Widget::DMainWindow::staticMetaObject>(),
    qt_meta_stringdata_dccV23__MainWindow.data,
    qt_meta_data_dccV23__MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *dccV23::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dccV23::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dccV23__MainWindow.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QDBusContext"))
        return static_cast< QDBusContext*>(this);
    return Dtk::Widget::DMainWindow::qt_metacast(_clname);
}

int dccV23::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Dtk::Widget::DMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
