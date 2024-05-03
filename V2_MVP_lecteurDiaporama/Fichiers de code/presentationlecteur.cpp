#include "presentationlecteur.h"

/*** Implémentations ***/

// Constructeur
PresentationLecteur::PresentationLecteur() :
    _vue(nullptr),
    _modele(nullptr),
    _diapoCourant(nullptr) {}

// Getter pour LecteurVue
LecteurVue* PresentationLecteur::getVue() const {
    return _vue;
}

// Getter pour ModeleLecteur
ModeleLecteur* PresentationLecteur::getModele() const {
    return _modele;
}

// Getter pour Diaporama
Diaporama* PresentationLecteur::getDiaporama() {
    return _diapoCourant;
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
void PresentationLecteur::setDiaporama(Diaporama* diaporama) {
    _diapoCourant = diaporama;
}

// Implémentation des slots
void PresentationLecteur::demanderAvancer() {
    // Implémentation à faire
}

void PresentationLecteur::demanderReculer() {
    // Implémentation à faire
}

void PresentationLecteur::demanderArretDiapo() {
    // Implémentation à faire
}

void PresentationLecteur::demanderChangerVitesse() {
    // Implémentation à faire
}

void PresentationLecteur::demanderChargement() {
    // Implémentation à faire
}

void PresentationLecteur::demanderLancement() {
    // Implémentation à faire
}

void PresentationLecteur::demanderChangementModeVersManuel() {
    // Implémentation à faire
}

void PresentationLecteur::demanderChangementModeVersAUtomatique() {
    // Implémentation à faire
}
