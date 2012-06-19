/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Tue 19. Jun 01:36:18 2012
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
      25,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      31,   11,   11,   11, 0x08,
      42,   11,   11,   11, 0x08,
      49,   11,   11,   11, 0x08,
      61,   11,   11,   11, 0x08,
      68,   11,   11,   11, 0x08,
      76,   11,   11,   11, 0x08,
      91,   11,   11,   11, 0x08,
     104,   11,   11,   11, 0x08,
     122,   11,   11,   11, 0x08,
     139,   11,   11,   11, 0x08,
     155,   11,   11,   11, 0x08,
     171,   11,   11,   11, 0x08,
     185,   11,   11,   11, 0x08,
     191,   11,   11,   11, 0x08,
     197,   11,   11,   11, 0x08,
     203,   11,   11,   11, 0x08,
     210,   11,   11,   11, 0x08,
     217,   11,   11,   11, 0x08,
     224,   11,   11,   11, 0x08,
     229,   11,   11,   11, 0x08,
     235,   11,   11,   11, 0x08,
     241,   11,   11,   11, 0x08,
     248,   11,   11,   11, 0x08,
     254,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0clickedBt(QString)\0"
    "evaluate()\0eval()\0duplicate()\0drop()\0"
    "clear()\0toModeEntier()\0toModeReel()\0"
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
        case 2: eval(); break;
        case 3: duplicate(); break;
        case 4: drop(); break;
        case 5: clear(); break;
        case 6: toModeEntier(); break;
        case 7: toModeReel(); break;
        case 8: toModeRationnel(); break;
        case 9: toModeComplexe(); break;
        case 10: toModeBestFit(); break;
        case 11: toModeRadiant(); break;
        case 12: toModeDegre(); break;
        case 13: cos(); break;
        case 14: sin(); break;
        case 15: tan(); break;
        case 16: cosh(); break;
        case 17: sinh(); break;
        case 18: tanh(); break;
        case 19: ln(); break;
        case 20: log(); break;
        case 21: inv(); break;
        case 22: sqrt(); break;
        case 23: sqr(); break;
        case 24: sign(); break;
        default: ;
        }
        _id -= 25;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
