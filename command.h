/**
 * \file command.h
 * \brief Contient la declaration de la classe Command
 *
 * \author Charrier Lucas et Rossier Titouan
 * \version 0.1
 * \date 31 Mai 2012
 *
 */
#ifndef COMMAND_H
#define COMMAND_H

class Command
{

    /**
     * \class Command
     * \brief La classe Command est une classe abstraite -
     * C'est la classe mere des classes CommandUnArg, CommandPush, CommandDeuxArg et CommandPolyArg
     */

public:
        virtual ~Command();
        virtual void Execute() = 0;
protected:
        Command();
};

#endif // COMMAND_H
