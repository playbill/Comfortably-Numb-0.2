/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun 17. Jun 13:47:31 2012
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
      22,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      31,   11,   11,   11, 0x08,
      42,   11,   11,   11, 0x08,
      49,   11,   11,   11, 0x08,
      64,   11,   11,   11, 0x08,
      77,   11,   11,   11, 0x08,
      95,   11,   11,   11, 0x08,
     112,   11,   11,   11, 0x08,
     128,   11,   11,   11, 0x08,
     144,   11,   11,   11, 0x08,
     158,   11,   11,   11, 0x08,
     164,   11,   11,   11, 0x08,
     170,   11,   11,   11, 0x08,
     176,   11,   11,   11, 0x08,
     183,   11,   11,   11, 0x08,
     190,   11,   11,   11, 0x08,
     197,   11,   11,   11, 0x08,
     202,   11,   11,   11, 0x08,
     208,   11,   11,   11, 0x08,
     214,   11,   11,   11, 0x08,
     221,   11,   11,   11, 0x08,
     227,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0clickedBt(QString)\0"
    "evaluate()\0eval()\0toModeEntier()\0"
    "toModeReel()\0toModeRationnel()\0"
    "toModeComplexe()\0toModeBestFit()\0"
    "toModeRadiant()\0toModeDegre()\0cos()\0"
    "sin()\0tan()\0cosh()\0sinh()\0tanh()\0ln()\0"
    "log()\0inv()\0sqrt()\0sqr()\0sign()\0"
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
        case 2: eval(); break;
        case 3: toModeEntier(); break;
        case 4: toModeReel(); break;
        case 5: toModeRationnel(); break;
        case 6: toModeComplexe(); break;
        case 7: toModeBestFit(); break;
        case 8: toModeRadiant(); break;
        case 9: toModeDegre(); break;
        case 10: cos(); break;
        case 11: sin(); break;
        case 12: tan(); break;
        case 13: cosh(); break;
        case 14: sinh(); break;
        case 15: tanh(); break;
        case 16: ln(); break;
        case 17: log(); break;
        case 18: inv(); break;
        case 19: sqrt(); break;
        case 20: sqr(); break;
        case 21: sign(); break;
        default: ;
        }
        _id -= 22;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
