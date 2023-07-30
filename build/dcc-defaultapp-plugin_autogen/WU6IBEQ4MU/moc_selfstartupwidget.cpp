/****************************************************************************
** Meta object code from reading C++ file 'selfstartupwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/plugin-defaultapp/window/selfstartupwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selfstartupwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SelfStartupDetailWidget_t {
    QByteArrayData data[16];
    char stringdata0[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SelfStartupDetailWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SelfStartupDetailWidget_t qt_meta_stringdata_SelfStartupDetailWidget = {
    {
QT_MOC_LITERAL(0, 0, 23), // "SelfStartupDetailWidget"
QT_MOC_LITERAL(1, 24, 11), // "reverseItem"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 8), // "category"
QT_MOC_LITERAL(4, 46, 3), // "App"
QT_MOC_LITERAL(5, 50, 4), // "item"
QT_MOC_LITERAL(6, 55, 17), // "requestDelUserApp"
QT_MOC_LITERAL(7, 73, 4), // "name"
QT_MOC_LITERAL(8, 78, 13), // "onReverseItem"
QT_MOC_LITERAL(9, 92, 17), // "onListViewClicked"
QT_MOC_LITERAL(10, 110, 11), // "QModelIndex"
QT_MOC_LITERAL(11, 122, 5), // "index"
QT_MOC_LITERAL(12, 128, 15), // "onDelBtnClicked"
QT_MOC_LITERAL(13, 144, 10), // "onClearAll"
QT_MOC_LITERAL(14, 155, 14), // "getAppListview"
QT_MOC_LITERAL(15, 170, 23) // "Dtk::Widget::DListView*"

    },
    "SelfStartupDetailWidget\0reverseItem\0"
    "\0category\0App\0item\0requestDelUserApp\0"
    "name\0onReverseItem\0onListViewClicked\0"
    "QModelIndex\0index\0onDelBtnClicked\0"
    "onClearAll\0getAppListview\0"
    "Dtk::Widget::DListView*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SelfStartupDetailWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       6,    2,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   59,    2, 0x0a /* Public */,
       9,    1,   60,    2, 0x0a /* Public */,
      12,    0,   63,    2, 0x0a /* Public */,
      13,    0,   64,    2, 0x0a /* Public */,
      14,    0,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    7,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 15,

       0        // eod
};

void SelfStartupDetailWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SelfStartupDetailWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->reverseItem((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const App(*)>(_a[2]))); break;
        case 1: _t->requestDelUserApp((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const App(*)>(_a[2]))); break;
        case 2: _t->onReverseItem(); break;
        case 3: _t->onListViewClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->onDelBtnClicked(); break;
        case 5: _t->onClearAll(); break;
        case 6: { Dtk::Widget::DListView* _r = _t->getAppListview();
            if (_a[0]) *reinterpret_cast< Dtk::Widget::DListView**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SelfStartupDetailWidget::*)(const QString & , const App & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SelfStartupDetailWidget::reverseItem)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SelfStartupDetailWidget::*)(const QString & , const App & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SelfStartupDetailWidget::requestDelUserApp)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SelfStartupDetailWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_SelfStartupDetailWidget.data,
    qt_meta_data_SelfStartupDetailWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SelfStartupDetailWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SelfStartupDetailWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SelfStartupDetailWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SelfStartupDetailWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void SelfStartupDetailWidget::reverseItem(const QString & _t1, const App & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SelfStartupDetailWidget::requestDelUserApp(const QString & _t1, const App & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
