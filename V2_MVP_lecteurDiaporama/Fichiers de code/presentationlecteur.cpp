#include "presentationlecteur.h"
#include "modelelecteur.h"
#include "lecteurvue.h"

/*** Implémentations ***/

// Constructeur
PresentationLecteur::PresentationLecteur() :
    _vue(nullptr),
    _modele(nullptr),
    _lecteur(nullptr){
}

// Getter pour LecteurVue
LecteurVue* PresentationLecteur::getVue() const {
    return _vue;
}

// Getter pour ModeleLecteur
ModeleLecteur* PresentationLecteur::getModele() const {
    return _modele;
}

// Getter pour Diaporama
Lecteur* PresentationLecteur::getLecteur() {
    return _lecteur;
}

// Setter pour LecteurVue
void PresentationLecteur::setVue(LecteurVue* vue) {
    _vue = vue;
}

// Setter pour ModeleLecteur
void PresentationLecteur::setModele(ModeleLecteur* modele) {
    _modele = modele;
}

// Setter pour Diaporama
void PresentationLecteur::setLecteur(Lecteur* pLecteur) {
    _lecteur = pLecteur;
    _lecteur->charger();
    _lecteur->chargerDiapos();
}

// Implémentation des slots
void PresentationLecteur::demanderAvancer() {
    _lecteur->getDiapoCourant().avancer();
}

void PresentationLecteur::demanderReculer() {
    _lecteur->getDiapoCourant().reculer();
}

void PresentationLecteur::demanderArretDiapo() {
    _lecteur->setNumDiapoCourant(0);
    _lecteur->getDiapoCourant().afficherImageCouranteDansDiaporamaCourant();
}

void PresentationLecteur::demanderChangerVitesse() {
    _modele->setEtat(ModeleLecteur::ChoixVitesseDefilement);
    _vue->majInterface(ModeleLecteur::ChoixVitesseDefilement);
}

void PresentationLecteur::demanderChargement() {
    // Implémentation à faire
    // Ouvrir la pop-up de choix des diaporamas
    _modele->setEtat(ModeleLecteur::ChoixDiaporama);
    _vue->majInterface(ModeleLecteur::ChoixDiaporama);
}

void PresentationLecteur::demanderLancement() {
    // Implémentation à faire
    // A réfléchir
}

void PresentationLecteur::demanderChangementModeVersManuel() {
    // Implémentation à faire
    _modele->setEtat(ModeleLecteur::Manuel);
    _vue->majInterface(_modele->getEtat());
}

void PresentationLecteur::demanderChangementModeVersAUtomatique() {
    // Implémentation à faire
    _modele->setEtat(ModeleLecteur::Automatique);
    _vue->majInterface(_modele->getEtat());
}
