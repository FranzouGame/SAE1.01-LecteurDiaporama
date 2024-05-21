#include "modelelecteur.h"
#include "imageDansDiaporama.h"
#include "qdebug.h"

<<<<<<< HEAD
ModeleLecteur::ModeleLecteur(Lecteur* l, UnEtat e, Diaporamas d) :
    _etat(e),
    _lecteur(l),
    _infosDiapos(d){
=======
ModeleLecteur::ModeleLecteur(Lecteur* l, UnEtat e) :
    _etat(e),
    _lecteur(l){
>>>>>>> V4
}

ModeleLecteur::ModeleLecteur()
{
    // Valeur par défaut de l'état
    _etat = UnEtat::Initial;

    // Lecteur par défaut
    _lecteur = new Lecteur();

<<<<<<< HEAD
    // Chargement des diaporamas
    chargerDiapos();
}

ModeleLecteur::~ModeleLecteur()
{
=======
>>>>>>> V4
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

<<<<<<< HEAD
Diaporamas ModeleLecteur::getInfosDiapos()const
{
    return _infosDiapos;
}
unsigned int ModeleLecteur::recupereVitesseDfl()
{
    return _lecteur->getDiaporama()->getVitesseDefilement();
}
void ModeleLecteur::demanderRetourImage1(int pos)
{
    _lecteur->setPosImageCourante(pos);
}
=======
>>>>>>> V4


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
<<<<<<< HEAD
}

void ModeleLecteur::setInfosDiapos(Diaporamas d)
{
    _infosDiapos = d;

=======

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
>>>>>>> V4
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
<<<<<<< HEAD
=======

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

>>>>>>> V4
    }
}


<<<<<<< HEAD

void ModeleLecteur::demandeEnleverDiapo()
{
    _lecteur->viderLecteur();
}




void ModeleLecteur::demanderInfosDiapos()
{
    emit sendDiapoInfos(_infosDiapos);
}

void ModeleLecteur::receptionDemandeChangementDiaporama(InfosDiaporama d)
{
    _lecteur->changerDiaporama(d.id, d.titre, d.vitesseDefilement);

    // Envoyer le titre du diaporama
    QString titreDiapo = QString::fromStdString(_lecteur->getDiaporama()->getTitre());
    emit diapoChanged(titreDiapo);

    // Mettre à jour l'image
    _lecteur->setPosImageCourante(0);
    ImageDansDiaporama* imageCourante = _lecteur->getImageCourante();
    if(imageCourante)
    {
=======
void ModeleLecteur::demanderAffichage1erDiapo()
{
    qDebug() << "Modele : reception demande image 1";
    ImageDansDiaporama* imageCourante = _lecteur->getImageCourante();
    // Si l'image existe, l'envoyer à la vue
    if (imageCourante) {
>>>>>>> V4
        emit imageChanged(QString::fromStdString(imageCourante->getChemin()),
                          QString::fromStdString(imageCourante->getTitre()),
                          QString::fromStdString(imageCourante->getCategorie()));
    }
<<<<<<< HEAD

}

void ModeleLecteur::receptionDemandeChangementVitesse(unsigned int pVitesse)
{
    if(getEtat() != Initial)
    {
        _lecteur->getDiaporama()->setVitesseDefilement(pVitesse);
    }

}

void ModeleLecteur::chargerDiapos()
{

        InfosDiaporama infosACharger;
        // Diaporama de Pantxika
        infosACharger.id = 1;
        infosACharger.titre = "Diaporama Pantxika";
        infosACharger.vitesseDefilement = 2;
        _infosDiapos.push_back(infosACharger);

         // Diaporama de Thierry
        infosACharger.id = 2;
        infosACharger.titre = "Diaporama Thierry";
        infosACharger.vitesseDefilement = 4;
        _infosDiapos.push_back(infosACharger);

         // Diaporama de Yann
        infosACharger.id = 3;
        infosACharger.titre = "Diaporama Yann";
        infosACharger.vitesseDefilement = 2;
        _infosDiapos.push_back(infosACharger);

         // Diaporama de Manu
        infosACharger.id = 4;
        infosACharger.titre = "Diaporama Manu";
        infosACharger.vitesseDefilement = 1;
        _infosDiapos.push_back(infosACharger);

=======
>>>>>>> V4
}









