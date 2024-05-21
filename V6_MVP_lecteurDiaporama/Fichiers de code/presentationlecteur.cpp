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





void PresentationLecteur::demanderArretDiapo() {
    qDebug() << "Présentation : réception demande d'arret diapo";
    ModeleLecteur::UnEtat etatPrécédent = _modele->getEtat();
    _modele->setEtat(ModeleLecteur::Initial);
    _vue->majInterface(_modele->getEtat());
    _modele->setEtat(etatPrécédent);
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
    _modele->setEtat(etatPrécédent);
}

void PresentationLecteur::demanderChargement() {
    ModeleLecteur::UnEtat etatPrécédent = _modele->getEtat();
    _modele->setEtat(ModeleLecteur::ChoixDiaporama);
    _modele->demanderInfosDiapos();
    _vue->majInterface(_modele->getEtat());
    _modele->setEtat(etatPrécédent);
}

void PresentationLecteur::demanderLancement() {
    qDebug() << "Présentation : réception demande de lancement";
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

void PresentationLecteur::demanderChangementDIapo(InfosDiaporama d)
{
    emit faireChangerDiapo(d);
}

void PresentationLecteur::demanderChangementVitesseDfl(float pVitesse)
{
    emit faireChangerVitesse(pVitesse);
}