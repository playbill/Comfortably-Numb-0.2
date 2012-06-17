/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun 17. Jun 03:20:22 2012
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
      21,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      31,   11,   11,   11, 0x08,
      42,   11,   11,   11, 0x08,
      57,   11,   11,   11, 0x08,
      70,   11,   11,   11, 0x08,
      88,   11,   11,   11, 0x08,
     105,   11,   11,   11, 0x08,
     121,   11,   11,   11, 0x08,
     137,   11,   11,   11, 0x08,
     151,   11,   11,   11, 0x08,
     157,   11,   11,   11, 0x08,
     163,   11,   11,   11, 0x08,
     169,   11,   11,   11, 0x08,
     176,   11,   11,   11, 0x08,
     183,   11,   11,   11, 0x08,
     190,   11,   11,   11, 0x08,
     195,   11,   11,   11, 0x08,
     201,   11,   11,   11, 0x08,
     207,   11,   11,   11, 0x08,
     214,   11,   11,   11, 0x08,
     220,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0clickedBt(QString)\0"
    "evaluate()\0toModeEntier()\0toModeReel()\0"
    "toModeRationnel()\0toModeComplexe()\0"
    "toModeBestFit()\0toModeRadiant()\0"
    "toModeDegre()\0cos()\0sin()\0tan()\0cosh()\0"
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
        case 2: toModeEntier(); break;
        case 3: toModeReel(); break;
        case 4: toModeRationnel(); break;
        case 5: toModeComplexe(); break;
        case 6: toModeBestFit(); break;
        case 7: toModeRadiant(); break;
        case 8: toModeDegre(); break;
        case 9: cos(); break;
        case 10: sin(); break;
        case 11: tan(); break;
        case 12: cosh(); break;
        case 13: sinh(); break;
        case 14: tanh(); break;
        case 15: ln(); break;
        case 16: log(); break;
        case 17: inv(); break;
        case 18: sqrt(); break;
        case 19: sqr(); break;
        case 20: sign(); break;
        default: ;
        }
        _id -= 21;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
