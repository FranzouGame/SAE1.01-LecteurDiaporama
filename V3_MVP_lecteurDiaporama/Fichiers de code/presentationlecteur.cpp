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


void PresentationLecteur::demanderAffichageDiapoDebut()
{
    qDebug() << "Présentation : affichage image 1";
    emit faireAfficherImageDepart();
}


void PresentationLecteur::demanderAffichageDiapo1()
{
    qDebug() << "Demande de l'affichage de la 1ere diapo";

    // Émettre le signal uniquement si nécessaire
    emit demanderAffichageDiapo1();
}


void PresentationLecteur::demanderArretDiapo() {
    qDebug() << "Présentation : réception demande d'arret diapo";
    ModeleLecteur::UnEtat etatPrécédent = _modele->getEtat();
    _modele->setEtat(ModeleLecteur::Initial);
    _vue->majInterface(_modele->getEtat());
    _modele->setEtat(etatPrécédent);
}

void PresentationLecteur::demanderChangerVitesse() {
    qDebug() << "Présentation : réception demande de changement de vitesse";
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
    if (_modele->getEtat() == ModeleLecteur::Automatique) {
        qDebug() << "je rentre dans le premier if";
        if (_modele->getLecteur()->getDiaporama()->getVitesseDefilement() == 0) {
            _modele->getLecteur()->getDiaporama()->setVitesseDefilement(1);
        }
        while (true) {
            qDebug() <<" je rentre dan sla boucle";
            QTimer timer;
            QEventLoop loop;
            connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
            timer.start(2500); // 5000 ms = 5 secondes
            loop.exec(); // Bloque jusqu'à ce que le timer émette le signal timeout

            if (btnSuivClicked==true) {
                btnSuivClicked = false; // Réinitialiser la variable pour la prochaine boucle
                _modele->setEtat(ModeleLecteur::Manuel);
                qDebug() << "je sors de la boucle avec Suivant ";
                break;}
            else if (btnPredClicked==true) {
                btnPredClicked = false; // Réinitialiser la variable pour la prochaine boucle
                _modele->setEtat(ModeleLecteur::Manuel);
                qDebug() << "je sors de la boucle avec Precédent ";
                break;}
            else if (_modele->getLecteur()->getImageCourante()->getRangDansDiaporama() == _modele->getLecteur()->nbImages())
            {
                qDebug() << "je sors de la boucle avec fin de diapo";
                break;}
            emit faireAvancer();
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
void PresentationLecteur::onBtnSuivClicked() {
    qDebug()<<"Mais NONNNNNNN";
    btnSuivClicked = true; // Mettre à jour la variable d'état lorsque le bouton est cliqué
}
void PresentationLecteur::onBtnPredClicked() {
    qDebug()<<"Mais NONNNNNNN";
    btnPredClicked = true; // Mettre à jour la variable d'état lorsque le bouton est cliqué
}
