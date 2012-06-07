#ifndef CALCULATEUR_H
#define CALCULATEUR_H

#include "pile.h"

class Calculateur
{
    private :
        Pile* pileC;
        bool Complexe;
        bool Entier;
        bool Degre;
        bool Radian;
        bool Rationnel;
        bool Reel;

    public:
        Calculateur();
        Element* cast(Element* );
        Element* addition();
        Element* multiplication();
        Element* soustraction();
        Element* division();
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
