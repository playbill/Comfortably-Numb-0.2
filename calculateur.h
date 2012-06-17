#ifndef CALCULATEUR_H
#define CALCULATEUR_H
#include "command.h"
#include "pile.h"
#define PI 3.14159265

class Calculateur
{
    private :
        Pile* pileC;
        int taille;
        bool modeComplexe;
        bool modeEntier;
        bool modeDegre;
        bool modeRadian;
        bool modeRationnel;
        bool modeReel;

    public:

        Calculateur();
        Pile* getPile() {return pileC;}
        Element* cast(Element* );
        Element* addition();
        Element* multiplication();
        Element* soustraction();
        Element* division();
        Element* eval();
        Element* pow();
        Element* duplicate();
        Element* cos();
        Element* sin();
        Element* tan();
        Element* tanh();
        Element* cosh();
        Element* sinh();
        Element* ln();
        Element* log();
        Element* inv();
        Element* sqrt();
        Element* sqr();
        Element* cube();
        Element* mod();
        Element* fact();
        Element* sign();
        Element* push(Element*);
        Element* pop();
        Element* operator!();
        bool isComplexe();
        bool isEntier();
        bool isDegre();
        bool isRadian();
        bool isRationnel();
        bool isReel();
        void setToComplexe();
        void setToNoComplexe();
        void setToEntier();
        void setToDegre();
        void setToRadian();
        void setToRationnel();
        void setToReel();
        void setNoMode();
};

#endif // CALCULATEUR_H
