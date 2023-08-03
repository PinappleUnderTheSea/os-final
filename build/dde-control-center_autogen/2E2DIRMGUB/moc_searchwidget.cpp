/****************************************************************************
** Meta object code from reading C++ file 'searchwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/frame/searchwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'searchwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dccV23__DccCompleterStyledItemDelegate_t {
    QByteArrayData data[1];
    char stringdata0[39];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dccV23__DccCompleterStyledItemDelegate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dccV23__DccCompleterStyledItemDelegate_t qt_meta_stringdata_dccV23__DccCompleterStyledItemDelegate = {
    {
QT_MOC_LITERAL(0, 0, 38) // "dccV23::DccCompleterStyledIte..."

    },
    "dccV23::DccCompleterStyledItemDelegate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dccV23__DccCompleterStyledItemDelegate[] = {

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

void dccV23::DccCompleterStyledItemDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject dccV23::DccCompleterStyledItemDelegate::staticMetaObject = { {
    QMetaObject::SuperData::link<QStyledItemDelegate::staticMetaObject>(),
    qt_meta_stringdata_dccV23__DccCompleterStyledItemDelegate.data,
    qt_meta_data_dccV23__DccCompleterStyledItemDelegate,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *dccV23::DccCompleterStyledItemDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dccV23::DccCompleterStyledItemDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dccV23__DccCompleterStyledItemDelegate.stringdata0))
        return static_cast<void*>(this);
    return QStyledItemDelegate::qt_metacast(_clname);
}

int dccV23::DccCompleterStyledItemDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStyledItemDelegate::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_dccV23__SearchWidget_t {
    QByteArrayData data[8];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dccV23__SearchWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dccV23__SearchWidget_t qt_meta_stringdata_dccV23__SearchWidget = {
    {
QT_MOC_LITERAL(0, 0, 20), // "dccV23::SearchWidget"
QT_MOC_LITERAL(1, 21, 15), // "notifySearchUrl"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 3), // "url"
QT_MOC_LITERAL(4, 42, 15), // "onReturnPressed"
QT_MOC_LITERAL(5, 58, 18), // "onSearchTextChange"
QT_MOC_LITERAL(6, 77, 4), // "text"
QT_MOC_LITERAL(7, 82, 14) // "onAutoComplete"

    },
    "dccV23::SearchWidget\0notifySearchUrl\0"
    "\0url\0onReturnPressed\0onSearchTextChange\0"
    "text\0onAutoComplete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dccV23__SearchWidget[] = {

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
       4,    0,   37,    2, 0x08 /* Private */,
       5,    1,   38,    2, 0x08 /* Private */,
       7,    1,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void dccV23::SearchWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SearchWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->notifySearchUrl((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onReturnPressed(); break;
        case 2: _t->onSearchTextChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onAutoComplete((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SearchWidget::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SearchWidget::notifySearchUrl)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject dccV23::SearchWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<Dtk::Widget::DSearchEdit::staticMetaObject>(),
    qt_meta_stringdata_dccV23__SearchWidget.data,
    qt_meta_data_dccV23__SearchWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *dccV23::SearchWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dccV23::SearchWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dccV23__SearchWidget.stringdata0))
        return static_cast<void*>(this);
    return Dtk::Widget::DSearchEdit::qt_metacast(_clname);
}

int dccV23::SearchWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Dtk::Widget::DSearchEdit::qt_metacall(_c, _id, _a);
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
void dccV23::SearchWidget::notifySearchUrl(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
