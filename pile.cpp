/**
 * \file pile.cpp
 * \brief Contient l'implementation des fonctions de Pile.h
 * \author Charrier Lucas et Rossier Titouan
 * \version 0.1
 * \date 31 Mai 2012
 *
 */

#include "pile.h"


Pile* Pile::instanceUnique = 0; /*! Mise à 0 de l'element instanceUnique */


Pile::Pile(): pile(new QStack<Element*>()){}


Pile::~Pile(){
    pile->clear();
    delete pile;}


Pile* Pile::donneInstance(){
    if(instanceUnique == 0)
        instanceUnique = new Pile;
    return instanceUnique;
}


void Pile::libereInstance(){
    if(instanceUnique != 0)
        delete instanceUnique;
    instanceUnique = 0;
}


QStack<Element*> Pile::getPile()const{return *pile;}

void Pile::empilerElement(Element * e){
    pile->push(e);
}


Element* Pile::depilerElement(){
    if(!pile->isEmpty())
        return pile->pop();
        return 0;
}


void Pile::swap(const unsigned int x,const unsigned int y){

    if(!pile->isEmpty()){
 //\todo gestion erreur
        qDebug()<<pile->at(4)->toQString();
        if( (x <pile->size()) && (y<pile->size())){
            Element * e = pile->at(x);
            pile->replace(x, pile->at(y));
            pile->replace(y,e);
        }
    }
}


void Pile::clear(){
pile->clear();
}



void Pile::drop(){
delete pile->pop(); /*! on enleve l'element du haut de la pile et on le delete */
}

Element* Pile::pop()
{
    return pile->pop();
}

void Pile::push(Element* e)
{
    pile->push(e);
}

int Pile::size()
{
    return pile->size();
}

Element* Pile::top()
{
    return pile->top();
}








