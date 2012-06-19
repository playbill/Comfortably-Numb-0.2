#include "gestioncommande.h"

GestionCommande::GestionCommande():pileUndo(new QStack<Command*>()),pileRedo(new QStack<Command*>())
{
}

