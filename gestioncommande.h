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
    void addAffichage(Affichage* affichage)
    {
            // Ajouter un observer a la liste
            list_observers.insert(affichage);
    }

    void removeAffichage(Affichage* affichage)
    {
            // Enlever un observer a la liste
            list_observers.erase(affichage);
    }
    void afficheCommand(Command* c){
    for (std::set<Affichage*>::const_iterator it = list_observers.begin(); it != list_observers.end(); ++it)
                (*it)->afficheCommand(c->toQString());
    }
    void popCommand(){
        for (std::set<Affichage*>::const_iterator it = list_observers.begin(); it != list_observers.end(); ++it)
                (*it)->popCommand();
    }

};

#endif // GESTIONCOMMANDE_H
