/**
 * \file pile.cpp
 * \brief Contient l'implémentation des fonctions de Pile.h
 * \author Charrier Lucas et Rossier Titouan
 * \version 0.1
 * \date 31 Mai 2012
 *
 */

#include "pile.h"


Pile* Pile::instanceUnique = 0;/*!< mise à 0 de l'élement instanceUnique */

/**
* \fn Pile()
* \brief Fonction :  constructeur, construit la pile
*/
Pile::Pile(): pile(new QStack<Element*>()){}

/**
* \fn ~Pile()
* \brief Fonction :  constructeur, construit la pile
*/
Pile::~Pile(){delete pile;}

/**
* \fn  Pile& donneInstance()
* \brief Fonction :  accèder au singleton Pile
* \return pointeur vers la pile
*/
Pile& Pile::donneInstance(){
    if(instanceUnique == 0)
        instanceUnique = new Pile;
    return *instanceUnique;
}

/**
* \fn static void libereInstance()
* \brief Fonction :  remet à 0 le pointeur instanceUnique
*/
void Pile::libereInstance(){
    if(instanceUnique != 0)
        delete instanceUnique;
    instanceUnique = 0;
}

/**
* \fn Qstack<Element*> getPile()
* \brief Fonction :  récupère un pointeur sur le haut de la pile
* \return : pointeur vers la pile
*/
QStack<Element*> Pile::getPile()const{return *pile;}// /todo à remplacer par une fonction retournant un pointeur vers le haut de la pile

/**
* \fn  void empilerExpression(Expression * cons)
* \brief Fonction : empiler un élément sur la pile
 */
void Pile::empilerElement(Element * e){
    pile->push(e);
}

 /**
* \fn  void depilerElement()
* \brief Fonction : depile l'élément le plus haut sur la pile
* \param e l'élément à empiler
* \return : élement dépilé
*/
Element* Pile::depilerElement(){
    if(!pile->isEmpty())
        return pile->pop();
        return 0;
}

 /**
* \fn  void swap(const unsigned int x,const unsigned int y)
* \brief Fonction : inversion de l'élément numéro x et l'élément numéro y de la pile
* \param x , y les éléments de numero x et y depuis le haut de la pile
*/
void Pile::swap(const unsigned int x,const unsigned int y){
    if(!pile->isEmpty()){
        if( (x <pile->size()) && (y<pile->size())){
            Element * e = pile->at(x);
            pile->replace(x,pile->at(y));
            pile->replace(y,e);
        }
    }
}

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

/**
* \fn void clear()
* \brief Fonction : efface tous les élements de la pile
*/
void Pile::clear(){
pile->clear();
}

/**
* \fn  void dup()
* \brief Fonction : duplique le premier élément de la pile
*/
void Pile::dup(){
if(!pile->isEmpty()){
Element* e= *(new Element*(pile->top()));/*!< on crée dynamyquement un pointeur d'élément */
pile->push(e); /*!< on le met sur le haut de la pile */
}
}

/**
* \fn  void drop()
* \brief Fonction : supprime le premier élément de la pile
*/
void Pile::drop(){
delete pile->pop(); /*!< on enlève l'élement du haut de la pile et on le delete */
}

