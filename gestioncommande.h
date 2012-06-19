#ifndef GESTIONCOMMANDE_H
#define GESTIONCOMMANDE_H
#include <QStack.h>
#include <QString.h>
#include "commandcalculateur.h"

class GestionCommande
{
private:
    QStack<Command *>* pileRedo;
    QStack<Command *>* pileUndo;
    std::set<Affichage*> list_observers;
public:
    GestionCommande();
    QStack<Command *>* getUndo(){return pileUndo; }
    QStack<Command *>* getRedo(){return pileRedo; }
    void pushCommand(Command* arg ){
        for (std::set<Affichage*>::const_iterator it = list_observers.begin(); it != list_observers.end(); ++it)
                        (*it)->pushCommand(arg->toQString());
        }

};

#endif // GESTIONCOMMANDE_H
