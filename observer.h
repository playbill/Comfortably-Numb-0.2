#ifndef OBSERVER_H
#define OBSERVER_H
#include <QString.h>

class Observer{

public :

        virtual void update(QString data, QString) = 0;
        virtual void push(QString data, QString) = 0;
        virtual void pop(QString data, QString) = 0;
        virtual void swap(QString data, QString) = 0;
};
#endif // OBSERVER_H
