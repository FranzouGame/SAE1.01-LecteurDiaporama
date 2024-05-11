#include "presentationlecteur.h"
#include "modelelecteur.h"
#include "lecteurvue.h"

/*** Implémentations ***/

// Constructeur
PresentationLecteur::PresentationLecteur() :
    _vue(nullptr),
    _modele(nullptr){
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
    qDebug() << "Présentation : réception demande d'avancement";
    emit faireAvancer(); // Émission du signal faireAvancer()
}
void PresentationLecteur::demanderReculer() {
    qDebug() << "Présentation : réception demande de reculement";
    emit faireReculer();
}

void PresentationLecteur::demanderArretDiapo() {
    qDebug() << "Présentation : réception demande d'arret diapo";
}

void PresentationLecteur::demanderChangerVitesse() {
    qDebug() << "Présentation : réception demande de changement de vitesse";
}

void PresentationLecteur::demanderChargement() {
    qDebug() << "Présentation : réception demande de chargement";
}

void PresentationLecteur::demanderLancement() {
    qDebug() << "Présentation : réception demande de lancement";
}

void PresentationLecteur::demanderChangementModeVersManuel() {
    qDebug() << "Présentation : réception demande de passage mode manuel";
}

void PresentationLecteur::demanderChangementModeVersAUtomatique() {
    qDebug() << "Présentation : réception demande de passage mode automatique";
}
