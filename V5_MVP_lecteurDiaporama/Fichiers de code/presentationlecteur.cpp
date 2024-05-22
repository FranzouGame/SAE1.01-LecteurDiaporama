#include "presentationlecteur.h"
#include "modelelecteur.h"
#include "lecteurvue.h"


/*** Implémentations ***/

// Constructeur
PresentationLecteur::PresentationLecteur() :
    _vue(nullptr),
    _modele(nullptr)
{
    // Création et connection du timer
    _timer = new QTimer(this);
    connect(_timer, &QTimer::timeout, this, &PresentationLecteur::avancerAutomatique);
}

// Getter pour LecteurVue
LecteurVue* PresentationLecteur::getVue() const {
    return _vue;
}

// Getter pour ModeleLecteur
ModeleLecteur* PresentationLecteur::getModele() const {
    return _modele;
}


// Setter pour LecteurVue
void PresentationLecteur::setVue(LecteurVue* vue) {
    _vue = vue;
    _vue->majInterface(_modele->getEtat());
}

// Setter pour ModeleLecteur
void PresentationLecteur::setModele(ModeleLecteur* modele) {
    _modele = modele;
}

void PresentationLecteur::avancerAutomatique()
{
    emit faireAvancer();
}



// Implémentation des slots
void PresentationLecteur::demanderAvancer() {
    if(getModele()->getEtat() != ModeleLecteur::Automatique)
    {
        emit faireAvancer();
    }
    else
    {
        getModele()->setEtat(ModeleLecteur::Manuel);
        demanderArretDiapo();
        getVue()->majInterface(getModele()->getEtat());
    }
}
void PresentationLecteur::demanderReculer() {
    if(getModele()->getEtat() != ModeleLecteur::Automatique)
    {
        emit faireReculer();
    }
    else
    {
        getModele()->setEtat(ModeleLecteur::Manuel);
        demanderArretDiapo();
        getVue()->majInterface(getModele()->getEtat());
    }
}


void PresentationLecteur::demanderAffichageDiapoDebut()
{
    emit faireAfficherImageDepart();
}

void PresentationLecteur::demanderArretDiapo() {

    // Arrêter le timer
    if (_timer->isActive()) {
        _timer->stop();
    }

    // Mettre à jour l'état
    getModele()->setEtat(ModeleLecteur::Manuel);
    getVue()->majInterface(getModele()->getEtat());
}

void PresentationLecteur::demanderEnleverDiaporama()
{
    // Envoi du signal + maj de l'interface & état
    emit faireEnleverDiapo();
    _modele->setEtat(ModeleLecteur::Initial);
    _vue->majInterface(_modele->getEtat());

}

void PresentationLecteur::demanderChangerVitesse() {
    // Récupérer l'ancien état et faire afficher la fenetre de choix
    ModeleLecteur::UnEtat etatPrécédent = _modele->getEtat();
    _modele->setEtat(ModeleLecteur::ChoixVitesseDefilement);
    _vue->majInterface(_modele->getEtat());

    // Remise en place de l'ancien état
    if(!(etatPrécédent == ModeleLecteur::Automatique || etatPrécédent == ModeleLecteur::Manuel)){
        etatPrécédent = ModeleLecteur::Manuel;
    }
    _modele->setEtat(etatPrécédent);
    _vue->majInterface(_modele->getEtat());
}

void PresentationLecteur::demanderChargement() {
    // Récupérer l'ancien état et faire afficher la fenetre de choix
    ModeleLecteur::UnEtat etatPrécédent = _modele->getEtat();
    _modele->setEtat(ModeleLecteur::ChoixDiaporama);
    _modele->demanderInfosDiapos();
    _vue->majInterface(_modele->getEtat());

    // Rétablir le mode si il était valide
    if(etatPrécédent == ModeleLecteur::Automatique || etatPrécédent == ModeleLecteur::Manuel)
    {
        _modele->setEtat(etatPrécédent);
    }
    else
    {
        _modele->setEtat(ModeleLecteur::Manuel);
        _vue->majInterface(_modele->getEtat());
    }

}

void PresentationLecteur::demanderLancement() {
    if (_modele->getEtat() == ModeleLecteur::Manuel)
    {
        _modele->setEtat(ModeleLecteur::Automatique);
        _vue->majInterface(_modele->getEtat());
    }

    // Récupérer la vitesse de défilement du diapo
    unsigned int vitesse = getModele()->recupereVitesseDfl();

    //remettre l'image de départ si on appuie sur le btn Lancer diapo alors que l'image actuelle n'est pas la premiere
    if(_modele->getLecteur()->getImageCourante()->getRangDansDiaporama() != _modele->getLecteur()->nbImages() - _modele->getLecteur()->nbImages()+1)
    {
        _modele->demanderRetourImage1();
    }
    if (_modele->getEtat() == ModeleLecteur::Automatique)
    {

        if (vitesse == 0) {
            _modele->getLecteur()->getDiaporama()->setVitesseDefilement(1);
        }

        if(_modele->getLecteur()->getImageCourante()->getRangDansDiaporama() <= _modele->getLecteur()->nbImages() - 1)
        {
            _timer->start(vitesse * 1000); // Lancement du timer
        }
        else
        {
            _modele->demanderRetourImage1();
            demanderArretDiapo();
        }

    }

}

void PresentationLecteur::demanderChangementModeVersManuel() {
    // Changement d'état
    _modele->setEtat(ModeleLecteur::Manuel);
    _vue->majInterface(_modele->getEtat());
}

void PresentationLecteur::demanderChangementModeVersAUtomatique() {
    // Changement d'état
    _modele->setEtat(ModeleLecteur::Automatique);
    _vue->majInterface(_modele->getEtat());
}

void PresentationLecteur::demanderAffichageInformations()
{
    // Envoyer le signal au modèle
    emit faireOuvrirAPropos();
}

void PresentationLecteur::demanderChangementDIapo(InfosDiaporama d)
{
    // Envoyer le signal au modèle
    emit faireChangerDiapo(d);
}

void PresentationLecteur::demanderChangementVitesseDfl(unsigned int pVitesse)
{
    // Envoyer le signal au modèle
    emit faireChangerVitesse(pVitesse);
}
