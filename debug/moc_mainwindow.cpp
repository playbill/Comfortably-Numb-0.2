/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Tue 19. Jun 15:22:38 2012
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
      30,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      22,   11,   11,   11, 0x08,
      32,   11,   11,   11, 0x08,
      42,   11,   11,   11, 0x08,
      49,   11,   11,   11, 0x08,
      56,   11,   11,   11, 0x08,
      75,   11,   11,   11, 0x08,
      86,   11,   11,   11, 0x08,
      93,   11,   11,   11, 0x08,
     105,   11,   11,   11, 0x08,
     112,   11,   11,   11, 0x08,
     120,   11,   11,   11, 0x08,
     135,   11,   11,   11, 0x08,
     148,   11,   11,   11, 0x08,
     166,   11,   11,   11, 0x08,
     183,   11,   11,   11, 0x08,
     199,   11,   11,   11, 0x08,
     215,   11,   11,   11, 0x08,
     229,   11,   11,   11, 0x08,
     235,   11,   11,   11, 0x08,
     241,   11,   11,   11, 0x08,
     247,   11,   11,   11, 0x08,
     254,   11,   11,   11, 0x08,
     261,   11,   11,   11, 0x08,
     268,   11,   11,   11, 0x08,
     273,   11,   11,   11, 0x08,
     279,   11,   11,   11, 0x08,
     285,   11,   11,   11, 0x08,
     292,   11,   11,   11, 0x08,
     298,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0clavier()\0effacer()\0"
    "addpile()\0undo()\0redo()\0clickedBt(QString)\0"
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
        case 0: clavier(); break;
        case 1: effacer(); break;
        case 2: addpile(); break;
        case 3: undo(); break;
        case 4: redo(); break;
        case 5: clickedBt((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: evaluate(); break;
        case 7: eval(); break;
        case 8: duplicate(); break;
        case 9: drop(); break;
        case 10: clear(); break;
        case 11: toModeEntier(); break;
        case 12: toModeReel(); break;
        case 13: toModeRationnel(); break;
        case 14: toModeComplexe(); break;
        case 15: toModeBestFit(); break;
        case 16: toModeRadiant(); break;
        case 17: toModeDegre(); break;
        case 18: cos(); break;
        case 19: sin(); break;
        case 20: tan(); break;
        case 21: cosh(); break;
        case 22: sinh(); break;
        case 23: tanh(); break;
        case 24: ln(); break;
        case 25: log(); break;
        case 26: inv(); break;
        case 27: sqrt(); break;
        case 28: sqr(); break;
        case 29: sign(); break;
        default: ;
        }
        _id -= 30;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
