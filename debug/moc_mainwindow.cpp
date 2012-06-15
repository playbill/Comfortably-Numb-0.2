/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Fri 15. Jun 17:54:25 2012
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      31,   11,   11,   11, 0x08,
      42,   11,   11,   11, 0x08,
      48,   11,   11,   11, 0x08,
      54,   11,   11,   11, 0x08,
      60,   11,   11,   11, 0x08,
      67,   11,   11,   11, 0x08,
      74,   11,   11,   11, 0x08,
      81,   11,   11,   11, 0x08,
      86,   11,   11,   11, 0x08,
      92,   11,   11,   11, 0x08,
      98,   11,   11,   11, 0x08,
     105,   11,   11,   11, 0x08,
     111,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0clickedBt(QString)\0"
    "evaluate()\0cos()\0sin()\0tan()\0cosh()\0"
    "sinh()\0tanh()\0ln()\0log()\0inv()\0sqrt()\0"
    "sqr()\0sign()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

const QMetaObject *MainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: clickedBt((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: evaluate(); break;
        case 2: cos(); break;
        case 3: sin(); break;
        case 4: tan(); break;
        case 5: cosh(); break;
        case 6: sinh(); break;
        case 7: tanh(); break;
        case 8: ln(); break;
        case 9: log(); break;
        case 10: inv(); break;
        case 11: sqrt(); break;
        case 12: sqr(); break;
        case 13: sign(); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
