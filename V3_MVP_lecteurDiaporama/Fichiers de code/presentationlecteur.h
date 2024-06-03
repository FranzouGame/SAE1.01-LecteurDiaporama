#ifndef PRESENTATIONLECTEUR_H
#define PRESENTATIONLECTEUR_H

// Types / classes nécessaires
class ModeleLecteur;
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
    bool btnSuivClicked = false;
    bool btnPredClicked = false;

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

signals:
    void faireAfficherImageDepart();


public slots:
    // Actions relatives aux diaporamas ou à leur chargement
    void demanderAvancer();
    void demanderReculer();
    void demanderAffichageDiapoDebut();
    void demanderAffichageDiapo1();
    void demanderArretDiapo();
    void demanderChangerVitesse();

    // Actions liées au lecteur
    void demanderChargement();
    void demanderLancement();
    void demanderChangementModeVersManuel();
    void demanderChangementModeVersAUtomatique();

    // Actions liées au fenetres externes
    void demanderAffichageInformations();
    void onBtnSuivClicked();
    void onBtnPredClicked();
};

#endif // PRESENTATIONLECTEUR_H
