/********************************************************************************
** Form generated from reading ui file 'affichage.ui'
**
** Created: Mon 18. Jun 22:21:15 2012
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_AFFICHAGE_H
#define UI_AFFICHAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Affichage
{
public:
    QWidget *tab;
    QListWidget *listStack;
    QListWidget *listWidget_2;
    QWidget *tab1;

    void setupUi(QTabWidget *Affichage)
    {
        if (Affichage->objectName().isEmpty())
            Affichage->setObjectName(QString::fromUtf8("Affichage"));
        Affichage->resize(400, 300);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        listStack = new QListWidget(tab);
        listStack->setObjectName(QString::fromUtf8("listStack"));
        listStack->setGeometry(QRect(20, 30, 141, 192));
        listStack->setLayoutDirection(Qt::LeftToRight);
        listWidget_2 = new QListWidget(tab);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(190, 30, 151, 192));
        Affichage->addTab(tab, QString());
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        Affichage->addTab(tab1, QString());

        retranslateUi(Affichage);

        QMetaObject::connectSlotsByName(Affichage);
    } // setupUi

    void retranslateUi(QTabWidget *Affichage)
    {
        Affichage->setWindowTitle(QApplication::translate("Affichage", "TabWidget", 0, QApplication::UnicodeUTF8));
        Affichage->setTabText(Affichage->indexOf(tab), QApplication::translate("Affichage", "Tab 1", 0, QApplication::UnicodeUTF8));
        Affichage->setTabText(Affichage->indexOf(tab1), QApplication::translate("Affichage", "Tab 2", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Affichage);
    } // retranslateUi

};

namespace Ui {
    class Affichage: public Ui_Affichage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFFICHAGE_H
