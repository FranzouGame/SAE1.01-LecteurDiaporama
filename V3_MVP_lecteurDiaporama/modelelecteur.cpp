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

    // Lorsque vous changez l'image courante, émettez le signal avec les nouvelles informations
    if (_lecteur && _lecteur->getDiaporama()) {
        ImageDansDiaporama* imageCourante = _lecteur->getImageCourante();
        if (imageCourante) {
            emit imageChanged(QString::fromStdString(imageCourante->getChemin()),
                              QString::fromStdString(imageCourante->getTitre()),
                              QString::fromStdString(imageCourante->getCategorie()));
        }
    }

}

void ModeleLecteur::demandeReculement()
{
    qDebug() << "Modele : On me demande de reculer";
}







