
#include "imageDansDiaporama.h"
#include "qdebug.h"
#include "database.h"



ModeleLecteur::ModeleLecteur(Lecteur* l, UnEtat e) :
    _etat(e),
    _lecteur(l),
    _database(new Database())
{
    // Ouvrir la BD
    _database->openDatabase();
}

ModeleLecteur::ModeleLecteur()
{
    // Valeur par défaut de l'état
    _etat = UnEtat::Initial;

    // Lecteur par défaut
    _lecteur = new Lecteur();

    // Chargement des diaporamas
    // chargerDiapos();

    // Initialisation & ouverture de la BD
    _database = new Database();
    // _database->openDatabase();

}

ModeleLecteur::~ModeleLecteur()
{
}

/***********************
*       Getters        *
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

    // Vérifier qu'on ait un lecteur et un diapo
    if (_lecteur && _lecteur->getDiaporama()) {
        // Avancer et récupérer la nouvelle image
        _lecteur->avancer();
        envoieImageCourante();
    }
}

void ModeleLecteur::demandeReculement()
{
    // Vérifier qu'on ait un lecteur et un diapo
    if (_lecteur && _lecteur->getDiaporama()) {
        // Reculer et récupérer la nouvelle image
        _lecteur->reculer();
        envoieImageCourante();
    }
}



void ModeleLecteur::demandeEnleverDiapo()
{
    _lecteur->viderLecteur();
}

void ModeleLecteur::demanderInfosDiapos()
{
    // Récupérer les infos
    Diaporamas infosDiapos = _database->recupereDiapos();

    // Envoyer les informations
    emit sendDiapoInfos(infosDiapos);
}

// Réception du retour utilisateur (fait depuis la vue)
void ModeleLecteur::receptionDemandeChangementDiaporama(InfosDiaporama d)
{
    _lecteur->changerDiaporama(d.id, d.titre, d.vitesseDefilement);

    // Envoyer le titre du diaporama
    QString titreDiapo = QString::fromStdString(_lecteur->getDiaporama()->getTitre());
    emit diapoChanged(titreDiapo);

    // Récupérer les images du diaporama
    Diaporama * diapoChoisi = _database->recupereImageDiapo(d.id);
    _lecteur->setDiaporama(diapoChoisi);

    // Mettre à jour l'image
    _lecteur->setPosImageCourante(0);
    envoieImageCourante();
}


void ModeleLecteur::envoieImageCourante()
{
    ImageDansDiaporama* imageCourante = _lecteur->getImageCourante();
    // Si l'image existe, l'envoyer à la vue
    if (imageCourante) {
        emit imageChanged(QString::fromStdString(imageCourante->getChemin()),
                          QString::fromStdString(imageCourante->getTitre()),
                          QString::fromStdString(imageCourante->getCategorie()));
    }
}


void ModeleLecteur::receptionDemandeChangementVitesse(float pVitesse)
{
    if(getEtat() != Initial)
    {
        _lecteur->getDiaporama()->setVitesseDefilement(pVitesse);
    }

}











