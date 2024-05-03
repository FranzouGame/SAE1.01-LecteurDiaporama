#include "modelelecteur.h"

ModeleLecteur::ModeleLecteur() :
    _etat(UnEtat::Initial){

}

void ModeleLecteur::setEtat(UnEtat e)
{
    _etat = e;
}

UnEtat ModeleLecteur::getEtat() const
{
    return _etat;
}
