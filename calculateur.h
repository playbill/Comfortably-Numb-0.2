/**
 * \file calculateur.h
 * \brief Contient la declaration de la classe calculateur
 *
 * \author Charrier Lucas et Rossier Titouan
 * \version 0.1
 * \date 31 Mai 2012
 *
 */

#ifndef CALCULATEUR_H
#define CALCULATEUR_H
#include "command.h"
#include "pile.h"
#define PI 3.14159265

class Calculateur
{

    /**
     * \class Calculateur
     * \brief La classe calculateur contient une pile et permet de realiser toutes les operations mathematiques sur les elements de cette pile -
     * Elle permet de faire le lien entre l'interface graphique et les fonctions implementees dans toutes les sous classes de la classe Element
     *
     *
     */
    private :
        Pile* pileC; //! Pointeur vers la pile qui compose le calculateur
        int taille;
        bool modeComplexe;
        bool modeEntier;
        bool modeDegre;
        bool modeRadian;
        bool modeRationnel;
        bool modeReel;

    public:
        /**
         * \fn Calculateur()
         * \brief Constructeur de la classe Calculateur
         *
         *
         */
        Calculateur();

        /**
         * \fn Pile* getPile()
         * \brief Accesseur pour la pile associee
         * \return pointeur vers la pile associee
         *
         */
        Pile* getPile() {return pileC;}

        /**
         * \fn Element* cast(Element* )
         * \brief La fonction cast permet de caster un element en fonction du mode de la calculatrice
         */
        Element* cast(Element* );

        /**
         * \fn Element* addition()
         * \brief Permet l'addition des deux derniers elements de la pile
         */
        Element* addition();

        /**
         * \fn Element* multiplication()
         * \brief Permet la multiplication des deux derniers elements de la pile
         */
        Element* multiplication();

        /**
         * \fn Element* soustraction()
         * \brief Permet la soustraction des deux derniers elements de la pile
         */
        Element* soustraction();

        /**
         * \fn Element* division()
         * \brief Permet la division des deux derniers elements de la pile
         */
        Element* division();

        /**
         * \fn Element* eval()
         * \brief permet d'evaluer une expression
         * \deprecated N'est plus utilisee dans cette version (evaluation dans la classe MainWindow, car recuperation directe du QString depuis le champ de saisie du MainWindows
         */
        Element* eval();

        /**
         * \fn Element* pow()
         * \brief Permet de faire l'operation a^b avec a avant dernier element et b dernier element de la pile
         */
        Element* pow();

        /**
         * \fn Element* duplicate()
         * \brief Permet de dupliquer le dernier element de la pile et de la pusher sur celle-ci
         */
        Element* duplicate();

        /**
         * \fn Element* cos()
         * \brief Permet de calculer le cosinus du dernier element de la pile
         */
        Element* cos();

        /**
         * \fn Element* sin()
         * \brief Permet de calculer le sinus du dernier element de la pile
         */
        Element* sin();

        /**
         * \fn Element* tan()
         * \brief Permet de calculer la tangente du dernier element de la pile
         */
        Element* tan();

        /**
         * \fn Element* tanh()
         * \brief Permet de calculer la tangente hyperbolique du dernier element de la pile
         */
        Element* tanh();

        /**
         * \fn Element* cosh()
         * \brief Permet de calculer le cosinus hyperbolique du dernier element de la pile
         */
        Element* cosh();

        /**
         * \fn Element* sinh()
         * \brief Permet de calculer le sinus hyperbolique du dernier element de la pile
         */
        Element* sinh();

        /**
         * \fn Element* ln()
         * \brief Permet de calculer le logarithme neperien du dernier element de la pile
         */
        Element* ln();

        /**
         * \fn Element* log()
         * \brief Permet de calculer le logarithme decimal du dernier element de la pile
         */
        Element* log();

        /**
         * \fn Element* inv()
         * \brief Permet de calculer l'inverse du dernier element de la pile
         */
        Element* inv();

        /**
         * \fn Element* sqrt()
         * \brief Permet de calculer la racine carree du dernier element de la pile
         */
        Element* sqrt();

        /**
         * \fn Element* sqr()
         * \brief Permet de calculer le carre (puissance 2) du dernier element de la pile
         */
        Element* sqr();

        /**
         * \fn Element* cube()
         * \brief Permet de calculer le cube (puissance 3) du dernier element de la pile
         */
        Element* cube();

        /**
         * \fn Element* mod()
         * \brief Permet de calculer a modulo b avec a avant dernier element de la pile et b dernier element de la pile
         */
        Element* mod();

        /**
         * \fn Element* fact()
         * \brief Permet de calculer a factorielle du dernier element de la pile a (a!)
         */
        Element* fact();

        /**
         * \fn Element* sign()
         * \brief Permet de calculer l'opposer du dernier element de la pile
         */
        Element* sign();

        /**
         * \fn Element* swap()
         * \brief Permet d'echanger deux elements de la pile
         */
        Element* swap();

        /**
         * \fn Element* dup()
         * \brief
         */
        Element* dup();

        /**
         * \fn Element* drop()
         * \brief Permet de supprimer le dernier element de la pile
         */
        Element* drop();

        /**
         * \fn Element* sum()
         * \brief Permet de calculer la somme des x derniers elements de la pile
         */
        Element* sum();

        /**
         * \fn Element* mean()
         * \brief Permet de calculer la moyenne des x derniers elements de la pile
         */
        Element* mean();

        /**
         * \fn Element* clear()
         * \brief Permet de supprimer tous les elements de la pile
         */
        Element* clear();

        /**
         * \fn Element* push(Element*)
         * \brief Permet de pusher un element sur la pile
         */
        Element* push(Element*);

        /**
         * \fn Element* pop()
         * \brief Permet de recuperer le dernier element sur la pile
         */
        Element* pop();

        /**
         * \fn Element* operator!()
         *
         * \deprecated Plus utiliser dans cette version -
         * Remplacer par l'operateur fact
         */
        Element* operator!();

        /**
         * \fn bool isComplexe()
         * \brief Permet de tester si la calculatrice est en mode complexe
         * \return True si la calulatrice est en mode complexe, False sinon
         */
        bool isComplexe();

        /**
         * \fn bool isEntier()
         * \brief Permet de tester si la calculatrice est en mode entier
         * \return True si la calulatrice est en mode entier, False sinon
         */
        bool isEntier();

        /**
         * \fn bool isDegre()
         * \brief Permet de tester si la calculatrice est en mode degre
         * \return True si la calulatrice est en mode degre, False sinon
         */
        bool isDegre();

        /**
         * \fn bool isRadian()
         * \brief Permet de tester si la calculatrice est en mode radian
         * \return True si la calulatrice est en mode radian, False sinon
         */
        bool isRadian();

        /**
         * \fn bool isRationnel()
         * \brief Permet de tester si la calculatrice est en mode rationnel
         * \return True si la calulatrice est en mode rationnel, False sinon
         */
        bool isRationnel();

        /**
         * \fn bool isReel()
         * \brief Permet de tester si la calculatrice est en mode reel
         * \return True si la calulatrice est en mode reel, False sinon
         */
        bool isReel();

        /**
         * \fn void setToComplexe()
         * \brief Permet d'activer le mode complexe de la calculatrice
         *
         */
        void setToComplexe();

        /**
         * \fn void setToNoComplexe()
         * \brief Permet de desactiver le mode complexe de la calculatrice
         *
         */
        void setToNoComplexe();

        /**
         * \fn void setToEntier()
         * \brief Permet d'activer le mode entier de la calculatrice
         *
         */
        void setToEntier();

        /**
         * \fn void setToDegre()
         * \brief Permet d'activer le mode degre de la calculatrice
         *
         */
        void setToDegre();

        /**
         * \fn void setToRadian()
         * \brief Permet d'activer le mode radian de la calculatrice
         *
         */
        void setToRadian();

        /**
         * \fn void setToRationnel()
         * \brief Permet d'activer le mode rationnel de la calculatrice
         *
         */
        void setToRationnel();

        /**
         * \fn void setToReel()
         * \brief Permet d'activer le mode reel de la calculatrice
         *
         */
        void setToReel();

        /**
         * \fn void setNoMode()
         * \brief Permet de desactiver les mode reel, rationnel et entier de la calculatrice
         *
         */
        void setNoMode();
};

#endif // CALCULATEUR_H
