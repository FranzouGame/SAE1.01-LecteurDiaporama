#include "modelelecteur.h"

ModeleLecteur::ModeleLecteur() :
    _etat(UnEtat::Initial){

}

void ModeleLecteur::setEtat(ModeleLecteur::UnEtat e)
{
    _etat = e;
}

ModeleLecteur::UnEtat ModeleLecteur::getEtat() const
{
    return _etat;
}
