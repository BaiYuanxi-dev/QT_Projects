/****************************************************************************
** Meta object code from reading C++ file 'regis.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../starMazer_3/regis.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'regis.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_regis_t {
    QByteArrayData data[14];
    char stringdata0[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_regis_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_regis_t qt_meta_stringdata_regis = {
    {
QT_MOC_LITERAL(0, 0, 5), // "regis"
QT_MOC_LITERAL(1, 6, 18), // "on_confirm_clicked"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 17), // "on_cancel_clicked"
QT_MOC_LITERAL(4, 44, 16), // "on_head1_clicked"
QT_MOC_LITERAL(5, 61, 16), // "on_head2_clicked"
QT_MOC_LITERAL(6, 78, 16), // "on_head3_clicked"
QT_MOC_LITERAL(7, 95, 16), // "on_head4_clicked"
QT_MOC_LITERAL(8, 112, 16), // "on_head5_clicked"
QT_MOC_LITERAL(9, 129, 16), // "on_head6_clicked"
QT_MOC_LITERAL(10, 146, 18), // "on_confirm_pressed"
QT_MOC_LITERAL(11, 165, 19), // "on_confirm_released"
QT_MOC_LITERAL(12, 185, 17), // "on_cancel_pressed"
QT_MOC_LITERAL(13, 203, 18) // "on_cancel_released"

    },
    "regis\0on_confirm_clicked\0\0on_cancel_clicked\0"
    "on_head1_clicked\0on_head2_clicked\0"
    "on_head3_clicked\0on_head4_clicked\0"
    "on_head5_clicked\0on_head6_clicked\0"
    "on_confirm_pressed\0on_confirm_released\0"
    "on_cancel_pressed\0on_cancel_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_regis[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void regis::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<regis *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_confirm_clicked(); break;
        case 1: _t->on_cancel_clicked(); break;
        case 2: _t->on_head1_clicked(); break;
        case 3: _t->on_head2_clicked(); break;
        case 4: _t->on_head3_clicked(); break;
        case 5: _t->on_head4_clicked(); break;
        case 6: _t->on_head5_clicked(); break;
        case 7: _t->on_head6_clicked(); break;
        case 8: _t->on_confirm_pressed(); break;
        case 9: _t->on_confirm_released(); break;
        case 10: _t->on_cancel_pressed(); break;
        case 11: _t->on_cancel_released(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject regis::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_regis.data,
    qt_meta_data_regis,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *regis::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *regis::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_regis.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int regis::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
