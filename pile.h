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

            /**
            * \fn static Pile& donneInstance()
            * \brief Fonction :  accèder au singleton Pile
            * \return pointeur vers la pile
            */
            static Pile& donneInstance();

             /**
            * \fn static void libereInstance()
            * \brief Fonction :  remet à 0 le pointeur instanceUnique
            */
            static void libereInstance();

             /**
            * \fn Qstack<Element*> getPile()
            * \brief Fonction :  récupère un pointeur sur le haut de la pile
            * \return : pointeur vers la pile
            */
            QStack<Element*> getPile()const;

             /**
            * \fn  void empilerExpression(Expression * cons)
            * \brief Fonction : empiler un élément sur la pile
            */
            void empilerElement(Element * e);

             /**
            * \fn  void depilerElement()
            * \brief Fonction : depile l'élément le plus haut sur la pile
            * \param e l'élément à empiler
            * \return : élement dépilé
            */
            Element* depilerElement();

             /**
            * \fn  void swap(const unsigned int x,const unsigned int y)
            * \brief Fonction : inversion de l'élément numéro x et l'élément numéro y de la pile
            * \param x , y les éléments de numero x et y depuis le haut de la pile
            */
            void swap(const unsigned int x,const unsigned int y);

            /**
            * \fn  void sum(int x)
            * \brief Fonction : somme des x premiers éléments de la pile
            * \param x le nombre d'élements sommés depuis le haut de la pile
            * \deprecated
            * void sum(unsigned int x);
            */
            /**
            * \fn void mean(unsigned int x)
            * \brief Fonction : moyenne des x premiers éléments de la pile
            * \param x le nombre d'élements depuis le haut de la pile sur lesquels on fait la moyenne
            * \deprecated
            * void mean(unsigned int x);
            */
            /**
            * \fn void clear()
            * \brief Fonction : efface tous les élements de la pile
            */
            void clear();

            /**
            * \fn  void dup()
            * \brief Fonction : duplique le premier élément de la pile
            */
            void dup();

            /**
            * \fn  void drop()
            * \brief Fonction : supprime le premier élément de la pile
            */
            void drop();
};

#endif // PILE_H

