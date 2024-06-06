#include "presentationlecteur.h"
#include "modelelecteur.h"
#include "lecteurvue.h"
#include "database.h"



/***********************
 *   CONSTRUCTEURS     *
***********************/


Images PresentationLecteur::getImages()
{
    return _database->recupereImages();
}

PresentationLecteur::PresentationLecteur() :
    _vue(nullptr),
    _modele(nullptr),
    _etat(Initial)
{
    // Initialisation du timer
    _timer = new QTimer(this);
    connect(_timer, &QTimer::timeout, this, &PresentationLecteur::avancerEnBoucle);
}



/***********************
 *      GETTERS        *
***********************/


LecteurVue* PresentationLecteur::getVue() const {
    return _vue;
}


ModeleLecteur* PresentationLecteur::getModele() const {
    return _modele;
}

PresentationLecteur::UnEtat PresentationLecteur::getEtat() const
{
    return _etat;
}

Lecteur *PresentationLecteur::getLecteur() const
{
    return _lecteur;
}

Database *PresentationLecteur::getDatabase() const
{
    return _database;
}

unsigned int PresentationLecteur::recupereVitesseDfl()
{
    return _lecteur->getDiaporama()->getVitesseDefilement();
}


/***********************
 *      SETTERS        *
***********************/


void PresentationLecteur::setVue(LecteurVue* vue) {
    _vue = vue;
    _vue->majInterface(Initial);
}


void PresentationLecteur::setModele(ModeleLecteur* modele) {
    _modele = modele;
}

void PresentationLecteur::setEtat(UnEtat e)
{
    _etat = e;
}

void PresentationLecteur::setLecteur(Lecteur *l)
{
     _lecteur = l;
}

void PresentationLecteur::setDatabase(Database *d)
{
    _database = d;
}



/***********************
 *       SLOTS         *
***********************/


// Actions relatives aux diaporamas ou à leur chargement

void PresentationLecteur::demanderAvancer() {

    // Vérifier le mode, arrêter si automatique
    if(getModele()->getEtat() == ModeleLecteur::Automatique)
    {
        demanderArretDiapo();
    }
    else
    {
        // Vérifier qu'on ait un lecteur et un diapo
        if (_lecteur && _lecteur->getDiaporama()) {
            // Avancer et récupérer la nouvelle image
            _lecteur->avancer();
            ImageDansDiaporama* imageCourante = getImageCourante();
            _vue->updateImageInfo(QString::fromStdString(imageCourante->getChemin()),
                                  QString::fromStdString(imageCourante->getTitre()),
                                  QString::fromStdString(imageCourante->getCategorie()));
        }
    }
}

void PresentationLecteur::demanderReculer() {

    // Vérifier le mode, arrêter si automatique
    if(getModele()->getEtat() == ModeleLecteur::Automatique)
    {
        demanderArretDiapo();
    }
    else
    {
        // Vérifier qu'on ait un lecteur et un diapo
        if (_lecteur && _lecteur->getDiaporama()) {
            // Avancer et récupérer la nouvelle image
            _lecteur->reculer();
            ImageDansDiaporama* imageCourante = getImageCourante();
            _vue->updateImageInfo(QString::fromStdString(imageCourante->getChemin()),
                                  QString::fromStdString(imageCourante->getTitre()),
                                  QString::fromStdString(imageCourante->getCategorie()));
        }
    }
}



void PresentationLecteur::demanderArretDiapo() {

    // Arreter le timer
    if (_timer->isActive()) {
        _timer->stop();
    }

    // Changer d'état
    setEtat(Manuel);
    _vue->majInterface(getEtat());
}

void PresentationLecteur::demanderEnleverDiaporama()
{
    _lecteur->viderLecteur();
    setEtat(Initial);
    _vue->majInterface(getEtat());

}

void PresentationLecteur::demanderChangerVitesse() {
    UnEtat etatPrécédent = getEtat();
    setEtat(ChoixVitesseDefilement);
    _vue->majInterface(getEtat());
    /*arret du diaporama pour le relancer pour pouvoir changer la vitesse de défilement
     * qui est mise à jour dans la bd puis récupérée depuis la bd pour la mettre a jour dans le lecteur*/
    demanderArretDiapo();


    if(etatPrécédent == Automatique)
    {
        _vue->majInterface(getEtat());
        demanderLancement();
    }
    else
    {
        setEtat(etatPrécédent);
        _vue->majInterface(getEtat());
    }

}

void PresentationLecteur::demanderCreerDiaporama()
{
    UnEtat etatPrécédent = getEtat();
    setEtat(CreationDiaporama);
    _vue->setImages(getImages());
    _vue->majInterface(getEtat());

    // arret du diaporama
    demanderArretDiapo();
    setEtat(etatPrécédent);
    _vue->majInterface(getEtat());
}

void PresentationLecteur::avancerEnBoucle() // Avancer mais pour le mode auto
{
    _modele->demandeAvancement();
}

void PresentationLecteur::demanderRetourImage1()
{
    _lecteur->setPosImageCourante(0);
    ImageDansDiaporama* imageCourante = getImageCourante();
    _vue->updateImageInfo(QString::fromStdString(imageCourante->getChemin()),
                          QString::fromStdString(imageCourante->getTitre()),
                          QString::fromStdString(imageCourante->getCategorie()));
}


// Actions liées au lecteur

void PresentationLecteur::demanderChargement() {
    // Récupérer puis chnager l'état et mettre à jour l'interface
    UnEtat etatPrécédent = getEtat();
    setEtat(ChoixDiaporama);
    _infosDiaporamas = recupInfosDiaporamas();
    _vue->majInterface(getEtat(), _infosDiaporamas);
    demanderArretDiapo();
    // Vérifier si l'ancien mode est valide

        setEtat(Manuel);
        _vue->majInterface(getEtat());
    if (etatPrécédent == Automatique)
    {
        demanderLancement();
    }

}

void PresentationLecteur::demanderLancement() {
    //mettre le mode auto si le bouton lancer diapo est appuyé et que le lecteur est en manuel
    if (getEtat() == Manuel)
    {
        setEtat(Automatique);
        _vue->majInterface(getEtat());
    }

    // Récupérer la vitesse de défilement du diapo
    unsigned int vitesse = recupereVitesseDfl();

    //remettre l'image de départ si on appuie sur le btn Lancer diapo alors que l'image actuelle n'est pas la premiere
    if(getLecteur()->getImageCourante()->getRangDansDiaporama() != 1)
    {
        demanderRetourImage1();
    }
    //verification que le mode est bien en automatique
    if (getEtat() == Automatique)
    {
        // Vérifier la vitesse de dfl pour éviter les erreurs
        if (vitesse == 0) {
            getLecteur()->getDiaporama()->setVitesseDefilement(1);
        }

        // Si on n'est pas à la dernière image, lancer le timer + lancer le diapo
        if(getLecteur()->getImageCourante()->getRangDansDiaporama() <= ->getLecteur()->nbImages() - 1)
        {
            _timer->start(1000*vitesse); // Lancement du timer
            demanderRetourImage1();
        }
        else
        {
            // Si on est à la dernière image, retour à la 1ère
            demanderRetourImage1();
            demanderArretDiapo();
            demanderChangementModeVersManuel();
        }

    }

}

void PresentationLecteur::demanderChangementModeVersManuel() {
    setEtat(Manuel);
    _vue->majInterface(getEtat());
}

void PresentationLecteur::demanderChangementModeVersAUtomatique() {
    setEtat(Automatique);
    _vue->majInterface(getEtat());
}


// Actions liées au fenetres externes

void PresentationLecteur::demanderAffichageInformations()
{
    _vue->afficherInformations();
}


// Actions liées aux choix utilisateur

void PresentationLecteur::demanderChangementDIapo(InfosDiaporama d)
{
    _lecteur->changerDiaporama(1, d.titre, d.vitesseDefilement);

    // Envoyer le titre du diaporama
    QString titreDiapo = QString::fromStdString(_lecteur->getDiaporama()->getTitre());
    _vue->updateDiapoTitle(titreDiapo);

    // Récupérer les images du diaporama
    Diaporama * diapoChoisi = _database->recupereImageDiapo(d.id);
    _lecteur->setDiaporama(diapoChoisi);

    // Mettre à jour l'image
    _lecteur->setPosImageCourante(0);
    ImageDansDiaporama* imageCourante = getImageCourante();
    _vue->updateImageInfo(QString::fromStdString(imageCourante->getChemin()),
                          QString::fromStdString(imageCourante->getTitre()),
                          QString::fromStdString(imageCourante->getCategorie()));

}

void PresentationLecteur::demanderChangementVitesseDfl(unsigned int pVitesse)
{
    _modele->receptionDemandeChangementVitesse(pVitesse);
}

void PresentationLecteur::demanderCreationDiaporama(Images img, QString titre, unsigned int vitesse)
{
    _modele->demanderCreationDiaporama(img, titre, vitesse);
}

void PresentationLecteur::transmettreInfosImage(const QString &chemin, const QString &titre, const QString &categorie)
{
    _vue->updateImageInfo(chemin, titre, categorie);
}

void PresentationLecteur::transmettreTitreDiapo(const QString &titre)
{
    _vue->updateDiapoTitle(titre);
}

void PresentationLecteur::transmettreInfosDiapos(Diaporamas d)
{
    _vue->receptionDiapos(d);
}

void PresentationLecteur::transmettreImages(Images img)
{
    _vue->receptionImages(img);
}

