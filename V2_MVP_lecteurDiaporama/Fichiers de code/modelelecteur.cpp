#include "modelelecteur.h"
#include "imagedansdiaporama.h"

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

void ModeleLecteur::setEtat(ModeleLecteur::UnEtat e)
{
    _etat = e;
}

void ModeleLecteur::setLecteur(Lecteur *l)
{
    _lecteur = l;
}

void ModeleLecteur::demandeAvancement()
{
    ImageDansDiaporama* imageCourante = _lecteur->getImageCourante();
    if (imageCourante) {
        _lecteur->reculer();
        emit envoyerInfosMajInterface(imageCourante);
    }
}

void ModeleLecteur::demandeReculement()
{
    ImageDansDiaporama* imageCourante = _lecteur->getImageCourante();
    if (imageCourante) {
        _lecteur->reculer();
        emit envoyerInfosMajInterface(imageCourante);
    }
}





ModeleLecteur::UnEtat ModeleLecteur::getEtat() const
{
    return _etat;
}

Lecteur *ModeleLecteur::getLecteur() const
{
    return _lecteur;
}




