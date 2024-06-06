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

public slots:


    // transmission des infos à la vue
    void transmettreInfosImage(const QString& chemin, const QString& titre, const QString& categorie);
    void transmettreTitreDiapo(const QString& titre);
    void transmettreInfosDiapos(Diaporamas);
    void transmettreImages(Images);
};

#endif // PRESENTATIONLECTEUR_H
