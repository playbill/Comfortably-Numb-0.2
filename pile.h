#ifndef PILE_H
#define PILE_H
#include <QStack> /*!< Pour pouvoir utiliser Qstack*/
#include <iostream>
#include "element.h"

/**
 * \class Pile
 * \brief Classe permetant de gérer une pile d'élément.
 * Implémentation avec le design patern singleton
 */

class Pile{

    private:

        QStack<Element*>* pile; /*!< Implémentation de Qstack pour la pile, pile de pointeur de valeur*/
        static Pile* instanceUnique;/*!< Pointeur unique sur instance */
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

};

#endif // PILE_H

