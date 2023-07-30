/****************************************************************************
** Meta object code from reading C++ file 'lineeditwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../include/widgets/lineeditwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lineeditwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dccV23__ErrorTip_t {
    QByteArrayData data[3];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dccV23__ErrorTip_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dccV23__ErrorTip_t qt_meta_stringdata_dccV23__ErrorTip = {
    {
QT_MOC_LITERAL(0, 0, 16), // "dccV23::ErrorTip"
QT_MOC_LITERAL(1, 17, 16), // "appearIfNotEmpty"
QT_MOC_LITERAL(2, 34, 0) // ""

    },
    "dccV23::ErrorTip\0appearIfNotEmpty\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dccV23__ErrorTip[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void dccV23::ErrorTip::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ErrorTip *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->appearIfNotEmpty(); break;
        default: ;
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject dccV23::ErrorTip::staticMetaObject = { {
    QMetaObject::SuperData::link<Dtk::Widget::DArrowRectangle::staticMetaObject>(),
    qt_meta_stringdata_dccV23__ErrorTip.data,
    qt_meta_data_dccV23__ErrorTip,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *dccV23::ErrorTip::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dccV23::ErrorTip::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dccV23__ErrorTip.stringdata0))
        return static_cast<void*>(this);
    return Dtk::Widget::DArrowRectangle::qt_metacast(_clname);
}

int dccV23::ErrorTip::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Dtk::Widget::DArrowRectangle::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_dccV23__LineEditWidget_t {
    QByteArrayData data[7];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dccV23__LineEditWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dccV23__LineEditWidget_t qt_meta_stringdata_dccV23__LineEditWidget = {
    {
QT_MOC_LITERAL(0, 0, 22), // "dccV23::LineEditWidget"
QT_MOC_LITERAL(1, 23, 8), // "setTitle"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 5), // "title"
QT_MOC_LITERAL(4, 39, 7), // "setText"
QT_MOC_LITERAL(5, 47, 4), // "text"
QT_MOC_LITERAL(6, 52, 18) // "setPlaceholderText"

    },
    "dccV23::LineEditWidget\0setTitle\0\0title\0"
    "setText\0text\0setPlaceholderText"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dccV23__LineEditWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       4,    1,   32,    2, 0x0a /* Public */,
       6,    1,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,

       0        // eod
};

void dccV23::LineEditWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LineEditWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->setText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->setPlaceholderText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject dccV23::LineEditWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<SettingsItem::staticMetaObject>(),
    qt_meta_stringdata_dccV23__LineEditWidget.data,
    qt_meta_data_dccV23__LineEditWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *dccV23::LineEditWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dccV23::LineEditWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dccV23__LineEditWidget.stringdata0))
        return static_cast<void*>(this);
    return SettingsItem::qt_metacast(_clname);
}

int dccV23::LineEditWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SettingsItem::qt_metacall(_c, _id, _a);
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
