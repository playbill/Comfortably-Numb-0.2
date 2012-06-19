#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include <QString.h>
#include <set>
#include <iostream>
#include "observer.h"

class Observable
{
protected:
        std::set<Observer*> list_observers;

public:

        void addObserver(Observer* observer)
        {
                // Ajouter un observer a la liste
                list_observers.insert(observer);
        }

        void removeObserver(Observer* observer)
        {
                // Enlever un observer a la liste
                list_observers.erase(observer);
        }
        void notify(void (Observer::*m)(QString),QString arg1){
        for (std::set<Observer*>::const_iterator it = list_observers.begin(); it != list_observers.end(); ++it)
                        (*it->*m)(arg1);
        }
};


#endif // OBSERVABLE_H
