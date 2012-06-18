/**
 * \file commandcalculateur.h
 * \brief Contient la declaration des sous classes de la classe Command -
 * CommandUnArg, CommandPush, CommandDeuxArg, et CommandPolyArg
 *
 * \author Charrier Lucas et Rossier Titouan
 * \version 0.1
 * \date 31 Mai 2012
 *
 */
#ifndef COMMANDCALCULATEUR_H
#define COMMANDCALCULATEUR_H
#include "command.h"
#include "calculateur.h"
#include <QDEBUG>


class CommandUnArg : public Command
{

    /**
     * \class CommandUnArg
     * \brief La classe permet de gérer toutes les commandes de la calculatrice qui s'appliquent a un seul element de la pile
     */
private:
    Calculateur* cal; ///cal : Pointeur de Calculateur sur lequel s'applique ces commandes
    Element* arg; ///arg : pointeur d'element correspondant a l'element sur lequel s'applique ces commandes
    Element* (Calculateur::*method)(); /// Pointe sur une methode particuliere de la classe calculateur
public:
    /**
     * \fn CommandUnArg(Calculateur*,Element*(Calculateur::*)()=0)
     * \brief Constructeur de la classe CommandUnArg -
     * Prend un pointeur de calculateur et de methode associee a ce calculateur en argument
     */
    CommandUnArg(Calculateur*,Element*(Calculateur::*)()=0);

    /**
     * \fn  virtual ~CommandUnArg()
     * \brief Destructeur de la classe CommandUnArg -
     * Destruction de l'argument arg
     */
    virtual ~CommandUnArg();

    /**
     * \fn  void Execute()
     * \brief Execution de la methode du calculateur associee
     */
    void Execute();
};

class CommandPush : public Command
{

    /**
     * \class CommandPush
     * \brief La classe permet de gérer la commande qui push simplement un element sur la pile du calculateur -
     * exple de commande associee : 1 ENTER (push 1 sur la pile)
     *
     */
private:
    Calculateur* cal; ///cal : Pointeur de Calculateur sur lequel s'appliquent ces commandes
    Element* arg; ///arg : pointeur d'element correspondant a l'element sur lequel s'applique ces commandes
public:

    /**
     * \fn CommandPush(Calculateur*,Element*)
     * \brief Constructeur de la classe CommandPush -
     * \param Cacluateur*, Element * -> Prend un pointeur de calculateur et d'element
     */
    CommandPush(Calculateur*,Element*);

    /**
     * \fn virtual ~CommandPush()
     * \brief Destructeur de la classe CommandPush -
     * Destruction de l'argument arg associe a la commande
     */
    virtual ~CommandPush();

    /**
     * \fn  void Execute()
     * \brief Execution de la methode push du calculateur cal
     */
    void Execute();
};


class CommandDeuxArg : public Command
{

    /**
     * \class CommandDeuxArg
     * \brief La classe permet de gérer toutes les commandes de la calculatrice qui s'appliquent a deux elements de la pile
     */
private:
    Calculateur* cal; ///cal : Pointeur de Calculateur sur lequel s'applique ces commandes
    Element* arg1; ///arg1 : pointeur d'element correspondant au premier element sur lequel s'applique ces commandes
    Element* arg2; ///arg2 : pointeur d'element correspondant au deuxieme element sur lequel s'applique ces commandes
    Element* (Calculateur::*method)(); /// Pointe sur une methode particuliere de la classe calculateur

public:

    /**
     * \fn CommandDeuxArg(Calculateur*,Element*,Element*,Element*(Calculateur::*)())
     * \brief Constructeur de la classe CommandDeuxArg -
     * \param Calulateur*, Element*, Element*, Calculateur::*method -> pointeur de calculateur, 2 pointeurs d'elements et un pointeur de methodes associee
     */
    CommandDeuxArg(Calculateur*,Element*,Element*,Element*(Calculateur::*)());

    /**
     * \fn virtual ~CommandDeuxArg()
     * \brief Destructeur de la classe CommandDeuxArg -
     * destruction des deux arguments associes
     */
    virtual ~CommandDeuxArg();

    /**
     * \fn  void Execute()
     * \brief Execution de la methode associee du calculateur
     */
    void Execute();
};

class CommandPolyArg : public Command
{

    /**
     * \class CommandPolyArg
     * \brief La classe permet de gérer toutes les commandes de la calculatrice qui s'appliquent a plus de deux elements de la pile -
     * a savoir les fonctions mean() et sum()
     */
private:
    Calculateur* cal; ///cal : pointeur de calculateur
    Element** tab; ///tab : Tableau de pointeurs d'elements
    unsigned int nElements;
    Element* (Calculateur::*method)();
public:

    /**
     * \fn CommandPolyArg(Calculateur*,unsigned int taille,unsigned int depart,Element*(Calculateur::*)()
     * \brief Constructeur de la classe CommandPolyArg
     * \param Calculateur*, taille, depart, pointeur de methode Calculateur::*method
     */
    CommandPolyArg(Calculateur*,unsigned int taille,unsigned int depart,Element*(Calculateur::*)());

    /**
     * \fn virtual ~CommandPolyArg()
     * \brief destructeur de la classe CommandPolyArg()
     */
    virtual ~CommandPolyArg();

    /**
     * \fn  void Execute()
     * \brief Execution de la methode associee du calculateur
     */
    void Execute();
};

#endif // COMMANDCALCULATEUR_H
