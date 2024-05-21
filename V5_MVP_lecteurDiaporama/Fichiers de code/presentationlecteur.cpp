#include "presentationlecteur.h"
#include "modelelecteur.h"
#include "lecteurvue.h"
/*** Implémentations ***/

// Constructeur
PresentationLecteur::PresentationLecteur() :
    _vue(nullptr),
    _modele(nullptr){

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
}

// Setter pour ModeleLecteur
void PresentationLecteur::setModele(ModeleLecteur* modele) {
    _modele = modele;
}



// Implémentation des slots
void PresentationLecteur::demanderAvancer() {
    emit faireAvancer(); // Émission du signal faireAvancer()
}
void PresentationLecteur::demanderReculer() {
    emit faireReculer();
}


void PresentationLecteur::demanderAffichageDiapoDebut()
{
    qDebug() << "Présentation : affichage image 1";
    emit faireAfficherImageDepart();
}

void PresentationLecteur::demanderArretDiapo() {

    if (_timer->isActive()) {
        _timer->stop();
    }
}

void PresentationLecteur::demanderChangerVitesse() {
    qDebug() << "Présentation : réception demande de changement de vitesse";
    ModeleLecteur::UnEtat etatPrécédent = _modele->getEtat();
    _modele->setEtat(ModeleLecteur::ChoixVitesseDefilement);
    _vue->majInterface(_modele->getEtat());
    _modele->setEtat(etatPrécédent);
    _vue->majInterface(_modele->getEtat());
}

void PresentationLecteur::demanderChargement() {
    ModeleLecteur::UnEtat etatPrécédent = _modele->getEtat();
    _modele->setEtat(ModeleLecteur::ChoixDiaporama);
    _vue->majInterface(_modele->getEtat());
    _modele->setEtat(etatPrécédent);
    _vue->majInterface(_modele->getEtat());
}

void PresentationLecteur::demanderLancement() {
    if (_modele->getEtat() == ModeleLecteur::Manuel)
    {
        _modele->setEtat(ModeleLecteur::Automatique);
        _vue->majInterface(_modele->getEtat());
    }

    // Récupérer la vitesse de défilement du diapo (sera utile quand les diapos seront entièrement chargés, ce qui n'est pas encore le cas)
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
            _timer->start(2000); // Lancement du timer
            emit faireAfficherImageDepart();
        }
        else
        {
            _modele->demanderRetourImage1();
            demanderArretDiapo();
            demanderChangementModeVersManuel();
        }

    }


}

void PresentationLecteur::demanderChangementModeVersManuel() {
    qDebug() << "Présentation : réception demande de passage mode manuel";
    _modele->setEtat(ModeleLecteur::Manuel);
    _vue->majInterface(_modele->getEtat());
}

void PresentationLecteur::demanderChangementModeVersAUtomatique() {
    qDebug() << "Présentation : réception demande de passage mode automatique";
    _modele->setEtat(ModeleLecteur::Automatique);
    _vue->majInterface(_modele->getEtat());
}

void PresentationLecteur::demanderAffichageInformations()
{
    emit faireOuvrirAPropos();
}
