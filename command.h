#ifndef COMMAND_H
#define COMMAND_H
#include <QString.h>

class Command
{
public:
        virtual ~Command();
        virtual void Execute() = 0;
        virtual QString toQString() = 0;
protected:
        Command();
};

#endif // COMMAND_H
