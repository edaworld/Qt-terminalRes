/****************************************************************************
** Meta object code from reading C++ file 'hismainwin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../hismainwin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hismainwin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HisMainWin_t {
    QByteArrayData data[7];
    char stringdata0[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HisMainWin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HisMainWin_t qt_meta_stringdata_HisMainWin = {
    {
QT_MOC_LITERAL(0, 0, 10), // "HisMainWin"
QT_MOC_LITERAL(1, 11, 24), // "on_btnReturn_his_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 23), // "on_btnCurve_his_clicked"
QT_MOC_LITERAL(4, 61, 23), // "on_btnPrint_his_clicked"
QT_MOC_LITERAL(5, 85, 23), // "on_btnClear_his_clicked"
QT_MOC_LITERAL(6, 109, 19) // "insAndupdatetblview"

    },
    "HisMainWin\0on_btnReturn_his_clicked\0"
    "\0on_btnCurve_his_clicked\0"
    "on_btnPrint_his_clicked\0on_btnClear_his_clicked\0"
    "insAndupdatetblview"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HisMainWin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HisMainWin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HisMainWin *_t = static_cast<HisMainWin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnReturn_his_clicked(); break;
        case 1: _t->on_btnCurve_his_clicked(); break;
        case 2: _t->on_btnPrint_his_clicked(); break;
        case 3: _t->on_btnClear_his_clicked(); break;
        case 4: _t->insAndupdatetblview(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject HisMainWin::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_HisMainWin.data,
      qt_meta_data_HisMainWin,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HisMainWin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HisMainWin::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HisMainWin.stringdata0))
        return static_cast<void*>(const_cast< HisMainWin*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int HisMainWin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
