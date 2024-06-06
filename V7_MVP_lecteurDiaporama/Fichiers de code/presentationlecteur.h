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

public:
    // Type énuméré état
    enum UnEtat {Automatique, Manuel, ChoixDiaporama, Initial, ChoixVitesseDefilement, CreationDiaporama};

private:
    // Attributs
    LecteurVue* _vue;         // Connexion de la vue
    QTimer* _timer;           // Timer pour le mode automatique

    Diaporamas _infosDiaporamas;
    UnEtat _etat;
    Lecteur* _lecteur;
    Database* _database;



    // récupérer infos diaporamas
    Diaporamas recupInfosDiaporamas();
    Images getImages();

public:
    // récupérer l'image courante
    ImageDansDiaporama* getImageCourante();

    /*** Méthodes ***/
    PresentationLecteur();

    // Getters
    LecteurVue* getVue() const;
    UnEtat getEtat() const;
    Lecteur* getLecteur() const;
    Database* getDatabase() const;
    unsigned int recupereVitesseDfl(); // getter indirect

    // Setters
    void setVue(LecteurVue*);
    void setEtat(UnEtat);
    void setLecteur(Lecteur*);
    void setDatabase(Database*);

    // Actions relatives aux diaporamas ou à leur chargement
    void demanderAvancer();
    void demanderReculer();
    void demanderArretDiapo();
    void demanderEnleverDiaporama();
    void demanderChangerVitesse();
    void demanderCreerDiaporama();
    void avancerEnBoucle(); // Avancer mais pour le mode auto
    void demanderRetourImage1();

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

    // Réception des retours utilisateur
    void receptionDemandeChangementVitesse(unsigned int);
    void receptionDemandeChangementDiapo(InfosDiaporama);
    void receptionDemandeCreationDiaporama(Images, QString, unsigned int);



public slots:


    // transmission des infos à la vue
    void transmettreInfosImage(const QString& chemin, const QString& titre, const QString& categorie);
    void transmettreTitreDiapo(const QString& titre);
    void transmettreInfosDiapos(Diaporamas);
    void transmettreImages(Images);
};

#endif // PRESENTATIONLECTEUR_H
