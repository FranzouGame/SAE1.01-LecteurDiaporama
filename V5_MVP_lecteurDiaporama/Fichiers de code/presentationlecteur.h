#ifndef PRESENTATIONLECTEUR_H
#define PRESENTATIONLECTEUR_H

// Types / classes nécessaires
<<<<<<< HEAD
#include "modelelecteur.h"
=======
class ModeleLecteur;
>>>>>>> V4
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
<<<<<<< HEAD
    QTimer* _timer;
=======
    QTimer* _timer;           // Timer pour le mode Automatique
>>>>>>> V4

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
<<<<<<< HEAD
    void faireOuvrirAPropos();
    void faireEnleverDiapo();
    void faireChangerDiapo(InfosDiaporama);
    void faireChangerVitesse(unsigned int);
=======
    void faireAfficherPremiere();
    void faireOuvrirAPropos();
>>>>>>> V4

signals:
    void faireAfficherImageDepart();


public slots:
    // Actions relatives aux diaporamas ou à leur chargement
    void demanderAvancer();
    void demanderReculer();
<<<<<<< HEAD
    void demanderArretDiapo();
    void demanderEnleverDiaporama();
=======
    void demanderAffichageDiapoDebut();
    void demanderArretDiapo();
>>>>>>> V4
    void demanderChangerVitesse();

    // Actions liées au lecteur
    void demanderChargement();
    void demanderLancement();
    void demanderChangementModeVersManuel();
    void demanderChangementModeVersAUtomatique();

    // Actions liées au fenetres externes
    void demanderAffichageInformations();
<<<<<<< HEAD

    // Actions liées aux choix utilisateur
    void demanderChangementDIapo(InfosDiaporama);
    void demanderChangementVitesseDfl(unsigned int);
=======
>>>>>>> V4
};

#endif // PRESENTATIONLECTEUR_H
