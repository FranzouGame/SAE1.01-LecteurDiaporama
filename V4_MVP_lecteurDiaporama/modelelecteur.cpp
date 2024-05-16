#include "modelelecteur.h"
#include "imageDansDiaporama.h"
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

    // Envoyer le signal
    QString titreDiapo = QString::fromStdString(_lecteur->getDiaporama()->getTitre());
    emit diapoChanged(titreDiapo);


}

unsigned int ModeleLecteur::recupereVitesseDfl()
{
    return _lecteur->getDiaporama()->getVitesseDefilement();
}

void ModeleLecteur::demanderRetourImage1(int pos)
{
    _lecteur->setPosImageCourante(pos);
}



/***********************
 *       Slots         *
***********************/

void ModeleLecteur::demandeAvancement()
{

    // Vérifier qu'on ait un lecteur et un diapo
    if (_lecteur && _lecteur->getDiaporama()) {
        // Avancer et récupérer la nouvelle image
        _lecteur->avancer();
        ImageDansDiaporama* imageCourante = _lecteur->getImageCourante();
        // Si l'image existe, l'envoyer à la vue
        if (imageCourante) {
            emit imageChanged(QString::fromStdString(imageCourante->getChemin()),
                              QString::fromStdString(imageCourante->getTitre()),
                              QString::fromStdString(imageCourante->getCategorie()));
        }
    }

}

void ModeleLecteur::demandeReculement()
{
    // Vérifier qu'on ait un lecteur et un diapo
    if (_lecteur && _lecteur->getDiaporama()) {
        // Reculer et récupérer la nouvelle image
        _lecteur->reculer();
        ImageDansDiaporama* imageCourante = _lecteur->getImageCourante();
        // Si l'image existe, l'envoyer à la vue
        if (imageCourante) {
            emit imageChanged(QString::fromStdString(imageCourante->getChemin()),
                              QString::fromStdString(imageCourante->getTitre()),
                              QString::fromStdString(imageCourante->getCategorie()));
        }

    }


}

void ModeleLecteur::demandeAffichageImageDebut()
{
    qDebug() << "Debug";
    // Vérifier qu'on ait un lecteur et un diapo
    if (_lecteur && _lecteur->getDiaporama()) {
        ImageDansDiaporama* imageCourante = _lecteur->getImageCourante();
        // Si l'image existe, l'envoyer à la vue
        if (imageCourante) {
            emit imageChanged(QString::fromStdString(imageCourante->getChemin()),
                              QString::fromStdString(imageCourante->getTitre()),
                              QString::fromStdString(imageCourante->getCategorie()));
        }

    }
}


void ModeleLecteur::demanderAffichage1erDiapo()
{
    qDebug() << "Modele : reception demande image 1";
    ImageDansDiaporama* imageCourante = _lecteur->getImageCourante();
    // Si l'image existe, l'envoyer à la vue
    if (imageCourante) {
        emit imageChanged(QString::fromStdString(imageCourante->getChemin()),
                          QString::fromStdString(imageCourante->getTitre()),
                          QString::fromStdString(imageCourante->getCategorie()));
    }
}









