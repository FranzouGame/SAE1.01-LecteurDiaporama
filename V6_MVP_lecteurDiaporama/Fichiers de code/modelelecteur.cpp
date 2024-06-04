#include "modelelecteur.h"
#include "imageDansDiaporama.h"
#include "qdebug.h"
#include "database.h"

#include <QSqlQuery>

/************************
 *    CONSTRUCTEURS     *
 ***********************/

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


    // Initialisation & ouverture de la BD
    _database = new Database();
}

ModeleLecteur::~ModeleLecteur()
{
    _database->closeDatabase();
}

/************************
 *   METHODES PRIVEES   *
 ***********************/

// Méthode d'affichage d'une image, pour éviter le duplicata de code
void ModeleLecteur::envoiImageCourante()
{
    ImageDansDiaporama* imageCourante = _lecteur->getImageCourante();
    if(imageCourante)
    {
        emit imageChanged(QString::fromStdString(imageCourante->getChemin()),
                          QString::fromStdString(imageCourante->getTitre()),
                          QString::fromStdString(imageCourante->getCategorie()));
    }
}




/***********************
 *      GETTERS        *
***********************/

ModeleLecteur::UnEtat ModeleLecteur::getEtat() const
{
    return _etat;
}

Lecteur *ModeleLecteur::getLecteur() const
{
    return _lecteur;
}

unsigned int ModeleLecteur::recupereVitesseDfl() // getter indirect
{
    return _lecteur->getDiaporama()->getVitesseDefilement();
}

Database* ModeleLecteur::getDatabase()const
{
    return _database;
}


/***********************
 *      SETTERS        *
***********************/

void ModeleLecteur::setEtat(ModeleLecteur::UnEtat e)
{
    _etat = e;
}

void ModeleLecteur::setLecteur(Lecteur *l)
{
    _lecteur = l;
}

void ModeleLecteur::setDatabase(Database* d)
{
    _database = d;
}



/**********************
 *  AUTRES METHODES   *
 *********************/


void ModeleLecteur::demanderRetourImage1()
{
    _lecteur->setPosImageCourante(0);
    envoiImageCourante();
}





/***********************
 *       SLOTS         *
***********************/

void ModeleLecteur::demandeAvancement()
{

    // Vérifier qu'on ait un lecteur et un diapo
    if (_lecteur && _lecteur->getDiaporama()) {
        // Avancer et récupérer la nouvelle image
        _lecteur->avancer();
        envoiImageCourante();
    }

}

void ModeleLecteur::demandeReculement()
{
    // Vérifier qu'on ait un lecteur et un diapo
    if (_lecteur && _lecteur->getDiaporama()) {
        // Reculer et récupérer la nouvelle image
        _lecteur->reculer();
        envoiImageCourante();
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
    envoiImageCourante();

}

void ModeleLecteur::receptionDemandeChangementVitesse(unsigned int pVitesse)
{
    _database->modifierVitesseDfl(_lecteur->getIdDiaporama(), pVitesse);
    // Vérifier si l'état est compatible et changer la vitesse de dfl
    if(getEtat() != Initial)
    {
        _lecteur->getDiaporama()->setVitesseDefilement(pVitesse);
    }

}










