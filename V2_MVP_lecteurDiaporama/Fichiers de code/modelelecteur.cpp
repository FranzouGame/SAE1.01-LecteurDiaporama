#include "modelelecteur.h"
#include "imagedansdiaporama.h"
#include "qdebug.h"

ModeleLecteur::ModeleLecteur(Lecteur* l, UnEtat e) :
    _etat(e),
    _lecteur(l){
}

ModeleLecteur::ModeleLecteur()
{
    // Valeur par défaut de l'état
    _etat = UnEtat::Initial;

    // Lecteur par défaut
    _lecteur = new Lecteur();
}

/***********************
 *      Getters        *
***********************/

ModeleLecteur::UnEtat ModeleLecteur::getEtat() const
{
    return _etat;
}

Lecteur *ModeleLecteur::getLecteur() const
{
    return _lecteur;
}



/***********************
 *      Setters        *
***********************/

void ModeleLecteur::setEtat(ModeleLecteur::UnEtat e)
{
    _etat = e;
}

void ModeleLecteur::setLecteur(Lecteur *l)
{
    _lecteur = l;
}



/***********************
 *       Slots         *
***********************/

void ModeleLecteur::demandeAvancement()
{
    qDebug() << "Modele : On me demande d'avancer";
}

void ModeleLecteur::demandeReculement()
{
    qDebug() << "Modele : On me demande de reculer";
}





