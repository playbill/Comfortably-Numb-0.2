/****************************************************************************
** Meta object code from reading C++ file 'affichage.h'
**
** Created: Tue 19. Jun 13:53:43 2012
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../affichage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'affichage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Affichage[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

       0        // eod
};

static const char qt_meta_stringdata_Affichage[] = {
    "Affichage\0"
};

const QMetaObject Affichage::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_Affichage,
      qt_meta_data_Affichage, 0 }
};

const QMetaObject *Affichage::metaObject() const
{
    return &staticMetaObject;
}

void *Affichage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Affichage))
        return static_cast<void*>(const_cast< Affichage*>(this));
    if (!strcmp(_clname, "Observer"))
        return static_cast< Observer*>(const_cast< Affichage*>(this));
    return QTabWidget::qt_metacast(_clname);
}

int Affichage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
