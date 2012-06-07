#ifndef CALCULATEUR_H
#define CALCULATEUR_H

#include "pile.h"

class Calculateur
{
    private :
        Pile* pileC;
        bool modeComplexe;
        bool modeEntier;
        bool modeDegre;
        bool modeRadian;
        bool modeRationnel;
        bool modeReel;

    public:
        Calculateur();
        Element* cast(Element* );
        void addition();
        void multiplication();
        void soustraction();
        void division();
        Element* pow();
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
