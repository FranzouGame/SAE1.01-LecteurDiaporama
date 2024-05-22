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
    connect(_timer, &QTimer::timeout, this, &PresentationLecteur::demanderAvancer);
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



// Implémentation des slots
void PresentationLecteur::demanderAvancer() {
    emit faireAvancer();
}
void PresentationLecteur::demanderReculer() {
    emit faireReculer();
}


void PresentationLecteur::demanderAffichageDiapoDebut()
{
    emit faireAfficherImageDepart();
}

void PresentationLecteur::demanderArretDiapo() {
    if (_timer->isActive()) {
        _timer->stop();
    }
}

void PresentationLecteur::demanderEnleverDiaporama()
{
    emit faireEnleverDiapo();
    _modele->setEtat(ModeleLecteur::Initial);
    _vue->majInterface(_modele->getEtat());

}

void PresentationLecteur::demanderChangerVitesse() {
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
    unsigned int vitesse = _modele->recupereVitesseDfl();

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
    _modele->setEtat(ModeleLecteur::Manuel);
    _vue->majInterface(_modele->getEtat());
}

void PresentationLecteur::demanderChangementModeVersAUtomatique() {
    _modele->setEtat(ModeleLecteur::Automatique);
    _vue->majInterface(_modele->getEtat());
}

void PresentationLecteur::demanderAffichageInformations()
{
    emit faireOuvrirAPropos();
}

void PresentationLecteur::demanderChangementDIapo(InfosDiaporama d)
{
    emit faireChangerDiapo(d);
}

void PresentationLecteur::demanderChangementVitesseDfl(unsigned int pVitesse)
{
    emit faireChangerVitesse(pVitesse);
}
