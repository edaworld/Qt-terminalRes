/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[27];
    char stringdata0[399];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "isReceiveData"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "notifyhiswin"
QT_MOC_LITERAL(4, 39, 12), // "notifycurwin"
QT_MOC_LITERAL(5, 52, 19), // "notifywinUpdatecurv"
QT_MOC_LITERAL(6, 72, 14), // "startCalibrate"
QT_MOC_LITERAL(7, 87, 14), // "openSerialPort"
QT_MOC_LITERAL(8, 102, 15), // "closeSerialPort"
QT_MOC_LITERAL(9, 118, 5), // "about"
QT_MOC_LITERAL(10, 124, 9), // "writeData"
QT_MOC_LITERAL(11, 134, 4), // "data"
QT_MOC_LITERAL(12, 139, 8), // "readData"
QT_MOC_LITERAL(13, 148, 14), // "timeoutdisplay"
QT_MOC_LITERAL(14, 163, 14), // "processrevdata"
QT_MOC_LITERAL(15, 178, 11), // "updatecurve"
QT_MOC_LITERAL(16, 190, 16), // "calibrateProcess"
QT_MOC_LITERAL(17, 207, 16), // "btnConfigProcess"
QT_MOC_LITERAL(18, 224, 11), // "handleError"
QT_MOC_LITERAL(19, 236, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(20, 265, 5), // "error"
QT_MOC_LITERAL(21, 271, 21), // "on_btnHistory_clicked"
QT_MOC_LITERAL(22, 293, 18), // "on_btnExit_clicked"
QT_MOC_LITERAL(23, 312, 21), // "on_btnConnect_clicked"
QT_MOC_LITERAL(24, 334, 24), // "on_btnDisconnect_clicked"
QT_MOC_LITERAL(25, 359, 17), // "on_btnSet_clicked"
QT_MOC_LITERAL(26, 377, 21) // "on_btnCalibra_clicked"

    },
    "MainWindow\0isReceiveData\0\0notifyhiswin\0"
    "notifycurwin\0notifywinUpdatecurv\0"
    "startCalibrate\0openSerialPort\0"
    "closeSerialPort\0about\0writeData\0data\0"
    "readData\0timeoutdisplay\0processrevdata\0"
    "updatecurve\0calibrateProcess\0"
    "btnConfigProcess\0handleError\0"
    "QSerialPort::SerialPortError\0error\0"
    "on_btnHistory_clicked\0on_btnExit_clicked\0"
    "on_btnConnect_clicked\0on_btnDisconnect_clicked\0"
    "on_btnSet_clicked\0on_btnCalibra_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  124,    2, 0x06 /* Public */,
       3,    0,  125,    2, 0x06 /* Public */,
       4,    0,  126,    2, 0x06 /* Public */,
       5,    0,  127,    2, 0x06 /* Public */,
       6,    0,  128,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,  129,    2, 0x08 /* Private */,
       8,    0,  130,    2, 0x08 /* Private */,
       9,    0,  131,    2, 0x08 /* Private */,
      10,    1,  132,    2, 0x08 /* Private */,
      12,    0,  135,    2, 0x08 /* Private */,
      13,    0,  136,    2, 0x08 /* Private */,
      14,    0,  137,    2, 0x08 /* Private */,
      15,    0,  138,    2, 0x08 /* Private */,
      16,    0,  139,    2, 0x08 /* Private */,
      17,    0,  140,    2, 0x08 /* Private */,
      18,    1,  141,    2, 0x08 /* Private */,
      21,    0,  144,    2, 0x08 /* Private */,
      22,    0,  145,    2, 0x08 /* Private */,
      23,    0,  146,    2, 0x08 /* Private */,
      24,    0,  147,    2, 0x08 /* Private */,
      25,    0,  148,    2, 0x08 /* Private */,
      26,    0,  149,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->isReceiveData(); break;
        case 1: _t->notifyhiswin(); break;
        case 2: _t->notifycurwin(); break;
        case 3: _t->notifywinUpdatecurv(); break;
        case 4: _t->startCalibrate(); break;
        case 5: _t->openSerialPort(); break;
        case 6: _t->closeSerialPort(); break;
        case 7: _t->about(); break;
        case 8: _t->writeData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 9: _t->readData(); break;
        case 10: _t->timeoutdisplay(); break;
        case 11: _t->processrevdata(); break;
        case 12: _t->updatecurve(); break;
        case 13: _t->calibrateProcess(); break;
        case 14: _t->btnConfigProcess(); break;
        case 15: _t->handleError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 16: _t->on_btnHistory_clicked(); break;
        case 17: _t->on_btnExit_clicked(); break;
        case 18: _t->on_btnConnect_clicked(); break;
        case 19: _t->on_btnDisconnect_clicked(); break;
        case 20: _t->on_btnSet_clicked(); break;
        case 21: _t->on_btnCalibra_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::isReceiveData)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::notifyhiswin)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::notifycurwin)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::notifywinUpdatecurv)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::startCalibrate)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::isReceiveData()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MainWindow::notifyhiswin()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MainWindow::notifycurwin()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MainWindow::notifywinUpdatecurv()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void MainWindow::startCalibrate()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
