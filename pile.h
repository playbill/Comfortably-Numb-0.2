/**
 * \file pile.h
 * \brief Contient la declaration de la classe Pile
 *
 * \author Charrier Lucas et Rossier Titouan
 * \version 0.1
 * \date 31 Mai 2012
 *
 */
#ifndef PILE_H
#define PILE_H
#include <QStack> /*!< Pour pouvoir utiliser Qstack*/
#include <iostream>
#include "element.h"
#include <QDEBUG>

/**
 * \class Pile
 * \brief Classe permettant de gerer une pile d'elements -
 * Implementation avec le design pattern singleton
 */

class Pile{

    private:

        QStack<Element*>* pile; /*! Implémentation de Qstack pour la pile, pile de pointeur de valeur*/
        static Pile* instanceUnique;/*! Pointeur unique sur instance */
        Pile();
        Pile(const Pile&);
        ~Pile();

    public:
        /**
         * \fn static Pile* donneInstance()
         * \brief Fonction qui creer une pile si seulement si aucune pile n'est deja existante
         * \return pointeur sur la pile nouvellement creee
         */
        static Pile* donneInstance();

        /**
        * \fn static void libereInstance()
        * \brief La fonction remet a 0 le pointeur instanceUnique
        */
        static void libereInstance();

        /**
        * \fn Qstack<Element*> getPile() const
        * \brief Recupere un pointeur sur le haut de la pile
        * \return : pointeur vers la pile
        */
        QStack<Element*> getPile()const;

        /**
        * \fn  void empilerExpression(Expression * e)
        * \brief Fonction : empiler un element e sur la pile
        * \param e l'element a empiler
         */
        void empilerElement(Element * e);

        /**
       * \fn  Element* depilerElement()
       * \brief Depile le dernier element de la pile
       * \param e l'element a depiler
       * \return : pointeur sur l'element depile
       */
        Element* depilerElement();

        /**
       * \fn  void swap(const unsigned int x,const unsigned int y)
       * \brief Inversion de l'element numero x et l'element numero y de la pile
       * \param x , y -> les elements de numero x et y depuis le haut de la pile
       */
        void swap(const unsigned int x,const unsigned int y);


        Element* pop();
        Element* top();
        void push(Element*);

        /**
        * \fn  void dup()
        * \brief Duplique le dernier element de la pile
        */
        void dup();

        /**
        * \fn  void drop()
        * \brief Supprime le dernier element de la pile
        */
        void drop();

        /**
        * \fn void clear()
        * \brief Efface tous les elements de la pile
        */
        void clear();

        /**
        * \fn  int size()
        * \brief Permet de recuperer la taille de la pile
        * \return int -> taille de la pile
        */
        int size();


        /**
        * \fn  void sum(int x)
        * \brief Fonction : somme des x premiers éléments de la pile
        * \param x le nombre d'élements sommés depuis le haut de la pile
        */

        /** Sum dépend du mode dans lequel est configurée la calculatrice
          * On implémentera cette fonction dans la classe Calculateur
          * \deprecated
          * void Pile::sum(unsigned int x){
          * QVectorIterator<Element*> i(*pile);!< Implémentation de QVectorIterator
          * On parcours toutes la pile \todo modifié pour ne prendre que les x premier éléments
          * if(Element* sum;
          * do{
          * sum = sum + *(i.next());
          * while (i.next() != pile->at(x));
          * }
        */

        /** Mean dépend du mode dans lequel est configurée la calculatrice
          * On implémentera cete fonction dans la classe Calculateur
          * \deprecated
          * \fn void mean(unsigned int x)
          * \brief Fonction : moyenne des x premiers éléments de la pile
          * \param x le nombre d'élements depuis le haut de la pile sur lesquels on fait la moyenne
          * void Pile::mean(unsigned int x){
          * \todo implémenter la fonction mean
          * }
        */

};

#endif // PILE_H

