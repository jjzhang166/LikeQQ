/****************************************************************************
** Meta object code from reading C++ file 'mainwidgetui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwidgetui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwidgetui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWidgetUI_t {
    QByteArrayData data[9];
    char stringdata[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWidgetUI_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWidgetUI_t qt_meta_stringdata_MainWidgetUI = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 14),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 23),
QT_MOC_LITERAL(4, 53, 21),
QT_MOC_LITERAL(5, 75, 22),
QT_MOC_LITERAL(6, 98, 22),
QT_MOC_LITERAL(7, 121, 22),
QT_MOC_LITERAL(8, 144, 22)
    },
    "MainWidgetUI\0signalNotifyUI\0\0"
    "signalResponseDataReady\0slotFinishedAnimation\0"
    "slotFinishedAnimation2\0slotFinishedAnimation3\0"
    "slotFinishedAnimation4\0slotFinishedAnimation5\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWidgetUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   49,    2, 0x05,
       3,    3,   56,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       4,    0,   63,    2, 0x0a,
       5,    0,   64,    2, 0x0a,
       6,    0,   65,    2, 0x0a,
       7,    0,   66,    2, 0x0a,
       8,    0,   67,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::Int, QMetaType::QStringList,    2,    2,    2,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int, QMetaType::QStringList,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWidgetUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWidgetUI *_t = static_cast<MainWidgetUI *>(_o);
        switch (_id) {
        case 0: _t->signalNotifyUI((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 1: _t->signalResponseDataReady((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 2: _t->slotFinishedAnimation(); break;
        case 3: _t->slotFinishedAnimation2(); break;
        case 4: _t->slotFinishedAnimation3(); break;
        case 5: _t->slotFinishedAnimation4(); break;
        case 6: _t->slotFinishedAnimation5(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWidgetUI::*_t)(bool , int , QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWidgetUI::signalNotifyUI)) {
                *result = 0;
            }
        }
        {
            typedef void (MainWidgetUI::*_t)(bool , int , QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWidgetUI::signalResponseDataReady)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject MainWidgetUI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainWidgetUI.data,
      qt_meta_data_MainWidgetUI,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWidgetUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWidgetUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWidgetUI.stringdata))
        return static_cast<void*>(const_cast< MainWidgetUI*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainWidgetUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void MainWidgetUI::signalNotifyUI(bool _t1, int _t2, QStringList _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWidgetUI::signalResponseDataReady(bool _t1, int _t2, QStringList _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
