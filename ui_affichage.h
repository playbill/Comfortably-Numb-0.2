/********************************************************************************
** Form generated from reading ui file 'affichage.ui'
**
** Created: Tue 19. Jun 14:47:05 2012
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
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Affichage
{
public:
    QWidget *pile;
    QListWidget *listStack;
    QListWidget *listWidget_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QTabWidget *Affichage)
    {
        if (Affichage->objectName().isEmpty())
            Affichage->setObjectName(QString::fromUtf8("Affichage"));
        Affichage->resize(400, 300);
        pile = new QWidget();
        pile->setObjectName(QString::fromUtf8("pile"));
        listStack = new QListWidget(pile);
        listStack->setObjectName(QString::fromUtf8("listStack"));
        listStack->setGeometry(QRect(20, 30, 141, 192));
        listStack->setLayoutDirection(Qt::LeftToRight);
        listWidget_2 = new QListWidget(pile);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(190, 30, 151, 192));
        label = new QLabel(pile);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 10, 31, 20));
        label_2 = new QLabel(pile);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(240, 10, 61, 20));
        Affichage->addTab(pile, QString());

        retranslateUi(Affichage);

        Affichage->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Affichage);
    } // setupUi

    void retranslateUi(QTabWidget *Affichage)
    {
        Affichage->setWindowTitle(QApplication::translate("Affichage", "TabWidget", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Affichage", "PILE", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Affichage", "Commande", 0, QApplication::UnicodeUTF8));
        Affichage->setTabText(Affichage->indexOf(pile), QApplication::translate("Affichage", "pile 1", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Affichage);
    } // retranslateUi

};

namespace Ui {
    class Affichage: public Ui_Affichage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFFICHAGE_H
