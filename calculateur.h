#ifndef CALCULATEUR_H
#define CALCULATEUR_H

#include "pile.h"

class Calculateur
{
    private :
        Pile* pile;
        bool Complexe;
        bool Entier;
        bool Degre;
        bool Radian;
        bool Rationnel;

    public:
        Calculateur();
        Constante* addition();
        Constante* multiplication();
        Constante* soustraction();
        Constante* division();
        Constante* pow();
        Constante* cos();
        Constante* sin();
        Constante* tan();
        Constante* cosh();
        Constante* sinh();
        Constante* tanh();
        Constante* ln();
        Constante* log();
        Constante* inv();
        Constante* sqrt();
        Constante* sqr();
        Constante* operator!();
        bool isComplexe();
        bool isEntier();
        bool isDegre();
        bool isRadian();
        bool isRationnel();
        bool isReel();
};

#endif // CALCULATEUR_H
