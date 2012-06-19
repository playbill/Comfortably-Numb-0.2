/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Tue 19. Jun 05:21:14 2012
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
      27,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      19,   11,   11,   11, 0x08,
      26,   11,   11,   11, 0x08,
      45,   11,   11,   11, 0x08,
      56,   11,   11,   11, 0x08,
      63,   11,   11,   11, 0x08,
      75,   11,   11,   11, 0x08,
      82,   11,   11,   11, 0x08,
      90,   11,   11,   11, 0x08,
     105,   11,   11,   11, 0x08,
     118,   11,   11,   11, 0x08,
     136,   11,   11,   11, 0x08,
     153,   11,   11,   11, 0x08,
     169,   11,   11,   11, 0x08,
     185,   11,   11,   11, 0x08,
     199,   11,   11,   11, 0x08,
     205,   11,   11,   11, 0x08,
     211,   11,   11,   11, 0x08,
     217,   11,   11,   11, 0x08,
     224,   11,   11,   11, 0x08,
     231,   11,   11,   11, 0x08,
     238,   11,   11,   11, 0x08,
     243,   11,   11,   11, 0x08,
     249,   11,   11,   11, 0x08,
     255,   11,   11,   11, 0x08,
     262,   11,   11,   11, 0x08,
     268,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0undo()\0redo()\0clickedBt(QString)\0"
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
        case 0: undo(); break;
        case 1: redo(); break;
        case 2: clickedBt((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: evaluate(); break;
        case 4: eval(); break;
        case 5: duplicate(); break;
        case 6: drop(); break;
        case 7: clear(); break;
        case 8: toModeEntier(); break;
        case 9: toModeReel(); break;
        case 10: toModeRationnel(); break;
        case 11: toModeComplexe(); break;
        case 12: toModeBestFit(); break;
        case 13: toModeRadiant(); break;
        case 14: toModeDegre(); break;
        case 15: cos(); break;
        case 16: sin(); break;
        case 17: tan(); break;
        case 18: cosh(); break;
        case 19: sinh(); break;
        case 20: tanh(); break;
        case 21: ln(); break;
        case 22: log(); break;
        case 23: inv(); break;
        case 24: sqrt(); break;
        case 25: sqr(); break;
        case 26: sign(); break;
        default: ;
        }
        _id -= 27;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
