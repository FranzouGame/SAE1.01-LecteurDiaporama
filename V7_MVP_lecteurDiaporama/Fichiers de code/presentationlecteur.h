#ifndef PRESENTATIONLECTEUR_H
#define PRESENTATIONLECTEUR_H

// Types / classes nécessaires
#include "modelelecteur.h"
class LecteurVue;
class Diaporama;

// Inclusions nécessaires
#include <QObject>
#include <QTimer>
#include <QEventLoop>
class PresentationLecteur : public QObject
{
    Q_OBJECT
private:
    // Attributs
    LecteurVue* _vue;         // Connexion de la vue
    ModeleLecteur* _modele;   // Connexion du modèle
    QTimer* _timer;           // Timer pour le mode automatique

public:
    /*** Méthodes ***/
    PresentationLecteur();

    // Getters
    LecteurVue* getVue() const;
    ModeleLecteur* getModele() const;

    // Setters
    void setVue(LecteurVue*);
    void setModele(ModeleLecteur*);

signals:
    void faireAvancer();
    void faireReculer();
    void faireOuvrirAPropos();
    void faireEnleverDiapo();
    void faireChangerDiapo(InfosDiaporama);
    void faireChangerVitesse(unsigned int);

signals:
    void faireAfficherImageDepart();


public slots:
    // Actions relatives aux diaporamas ou à leur chargement
    void demanderAvancer();
    void demanderReculer();
    void demanderArretDiapo();
    void demanderEnleverDiaporama();
    void demanderChangerVitesse();
    void demanderCreerDiaporama();
    void avancerEnBoucle(); // Avancer mais pour le mode auto

    // Actions liées au lecteur
    void demanderChargement();
    void demanderLancement();
    void demanderChangementModeVersManuel();
    void demanderChangementModeVersAUtomatique();

    // Actions liées au fenetres externes
    void demanderAffichageInformations();

    // Actions liées aux choix utilisateur
    void demanderChangementDIapo(InfosDiaporama);
    void demanderChangementVitesseDfl(unsigned int);
    void demanderCreationDiaporama(Images, QString, unsigned int);
};

#endif // PRESENTATIONLECTEUR_H
