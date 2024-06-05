#include "presentationlecteur.h"
#include "modelelecteur.h"
#include "lecteurvue.h"
#include "database.h"



/***********************
 *   CONSTRUCTEURS     *
***********************/


PresentationLecteur::PresentationLecteur() :
    _vue(nullptr),
    _modele(nullptr)
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


/***********************
 *      SETTERS        *
***********************/


void PresentationLecteur::setVue(LecteurVue* vue) {
    _vue = vue;
    _vue->majInterface(_modele->getEtat());
}


void PresentationLecteur::setModele(ModeleLecteur* modele) {
    _modele = modele;
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
        _modele->demandeAvancement();
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
        _modele->demandeReculement();
    }
}



void PresentationLecteur::demanderArretDiapo() {

    // Arreter le timer
    if (_timer->isActive()) {
        _timer->stop();
    }

    // Changer d'état
    _modele->setEtat(ModeleLecteur::Manuel);
    _vue->majInterface(_modele->getEtat());
}

void PresentationLecteur::demanderEnleverDiaporama()
{
    _modele->demandeEnleverDiapo();
    _modele->setEtat(ModeleLecteur::Initial);
    _vue->majInterface(_modele->getEtat());

}

void PresentationLecteur::demanderChangerVitesse() {
    ModeleLecteur::UnEtat etatPrécédent = _modele->getEtat();
    _modele->setEtat(ModeleLecteur::ChoixVitesseDefilement);
    _vue->majInterface(_modele->getEtat());
    /*arret du diaporama pour le relancer pour pouvoir changer la vitesse de défilement
     * qui est mise à jour dans la bd puis récupérée depuis la bd pour la mettre a jour dans le lecteur*/
    demanderArretDiapo();


    if(etatPrécédent == ModeleLecteur::Automatique)
    {
        _vue->majInterface(_modele->getEtat());
        demanderLancement();
    }
    else
    {
        _modele->setEtat(etatPrécédent);
        _vue->majInterface(_modele->getEtat());
    }

}

void PresentationLecteur::demanderCreerDiaporama()
{
    ModeleLecteur::UnEtat etatPrécédent = _modele->getEtat();
    _modele->setEtat(ModeleLecteur::CreationDiaporama);
    _modele->demanderImages();
    _vue->majInterface(_modele->getEtat());

    // arret du diaporama
    demanderArretDiapo();
    _modele->setEtat(etatPrécédent);
    _vue->majInterface(_modele->getEtat());
}

void PresentationLecteur::avancerEnBoucle() // Avancer mais pour le mode auto
{
    _modele->demandeAvancement();
}


// Actions liées au lecteur

void PresentationLecteur::demanderChargement() {
    // Récupérer puis chnager l'état et mettre à jour l'interface
    ModeleLecteur::UnEtat etatPrécédent = _modele->getEtat();
    _modele->setEtat(ModeleLecteur::ChoixDiaporama);
    _modele->demanderInfosDiapos();
    _vue->majInterface(_modele->getEtat());
    demanderArretDiapo();
    // Vérifier si l'ancien mode est valide

        _modele->setEtat(ModeleLecteur::Manuel);
        _vue->majInterface(_modele->getEtat());
    if (etatPrécédent == ModeleLecteur::Automatique)
    {
        demanderLancement();
    }

}

void PresentationLecteur::demanderLancement() {
    //mettre le mode auto si le bouton lancer diapo est appuyé et que le lecteur est en manuel
    if (_modele->getEtat() == ModeleLecteur::Manuel)
    {
        _modele->setEtat(ModeleLecteur::Automatique);
        _vue->majInterface(_modele->getEtat());
    }

    // Récupérer la vitesse de défilement du diapo
    unsigned int vitesse = _modele->recupereVitesseDfl();

    //remettre l'image de départ si on appuie sur le btn Lancer diapo alors que l'image actuelle n'est pas la premiere
    if(_modele->getLecteur()->getImageCourante()->getRangDansDiaporama() != 1)
    {
        _modele->demanderRetourImage1();
    }
    //verification que le mode est bien en automatique
    if (_modele->getEtat() == ModeleLecteur::Automatique)
    {
        // Vérifier la vitesse de dfl pour éviter les erreurs
        if (vitesse == 0) {
            _modele->getLecteur()->getDiaporama()->setVitesseDefilement(1);
        }

        // Si on n'est pas à la dernière image, lancer le timer + lancer le diapo
        if(_modele->getLecteur()->getImageCourante()->getRangDansDiaporama() <= _modele->getLecteur()->nbImages() - 1)
        {
            _timer->start(1000*vitesse); // Lancement du timer
            _modele->demanderRetourImage1();
        }
        else
        {
            // Si on est à la dernière image, retour à la 1ère
            _modele->demanderRetourImage1();
            demanderArretDiapo();
            demanderChangementModeVersManuel();
        }

    }

}

void PresentationLecteur::demanderChangementModeVersManuel() {
    _modele->setEtat(ModeleLecteur::Manuel);
    _vue->majInterface(_modele->getEtat());
}

void PresentationLecteur::demanderChangementModeVersAUtomatique() {
    _modele->setEtat(ModeleLecteur::Automatique);
    _vue->majInterface(_modele->getEtat());
}


// Actions liées au fenetres externes

void PresentationLecteur::demanderAffichageInformations()
{
    _vue->afficherInformations();
}


// Actions liées aux choix utilisateur

void PresentationLecteur::demanderChangementDIapo(InfosDiaporama d)
{
    _modele->receptionDemandeChangementDiaporama(d);
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

