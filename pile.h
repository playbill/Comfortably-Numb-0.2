#ifndef PILE_H
#define PILE_H
#include <QStack> /*!< Pour pouvoir utiliser Qstack*/
#include <iostream>
#include <affichage.h>
#include "element.h"
#include <QDEBUG>
#include "observable.h"


/**
 * \class Pile
 * \brief Classe permetant de gérer une pile d'élément.
 * Implémentation avec le design patern singleton
 */

class Pile {

    private:

        QStack<Element*>* pile; /*!< Implémentation de Qstack pour la pile, pile de pointeur de valeur*/
        static Pile* instanceUnique;/*!< Pointeur unique sur instance */
        std::set<Affichage*> list_observers;
        Pile();
        Pile(const Pile&);
        ~Pile();

    public:

        static Pile* donneInstance();
        static void libereInstance();
        QStack<Element*> getPile()const;
        void empilerElement(Element * e);
        Element* depilerElement();
        void swap(const unsigned int x,const unsigned int y);
        Element* pop();
        Element* top();
        void push(Element*);
        void dup();
        void drop();
        void clear();
        int size();
                void addAffichage(Affichage* affichage)
        {
                // Ajouter un observer a la liste
                list_observers.insert(affichage);
        }


        void removeAffichage(Affichage* affichage)
        {
                // Enlever un observer a la liste
                list_observers.erase(affichage);
        }
        void notify(void (Affichage::*m)(QString, QString),QString arg1 = 0, QString arg2 = 0){
        for (std::set<Affichage*>::const_iterator it = list_observers.begin(); it != list_observers.end(); ++it)
                        (*it->*m)(arg1,arg2);
        }
        void add(QString stringElement)
        {   qDebug()<<"add stringelement";
                notify(&Affichage::push, stringElement);
        }
        void del()
        {
                notify(&Affichage::pop);
        }
        void exchange(QString arg1,QString arg2)
        {
                notify(&Affichage::swap,arg1,arg2);
        }

};

#endif // PILE_H

