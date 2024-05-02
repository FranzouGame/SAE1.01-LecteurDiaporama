#ifndef PRESENTATIONLECTEUR_H
#define PRESENTATIONLECTEUR_H

// Types / classes nécessaires
class ModeleLecteur;
class LecteurVue;
class Diaporama;

// Inclusions nécessaires
#include <QObject>


class PresentationLecteur : public QObject
{
    Q_OBJECT
private:
    // Attributs
    LecteurVue* _vue;         // Connexion de la vue
    ModeleLecteur* _modele;   // Connexion du modèle
    Diaporama* _diapoCourant; // Pour interragir avec le diapo courant

public:
    /*** Méthodes ***/
    PresentationLecteur();

    // Getters
    LecteurVue* getVue() const;
    ModeleLecteur* getModele() const;
    Diaporama* getDiaporama();

    // Setters
    void setVue(LecteurVue*);
    void setModele(ModeleLecteur*);
    void setDiaporama(Diaporama*);

public slots:
    // Actions relatives aux diaporamas ou à leur chargement
    void demanderAvancer();
    void demanderReculer();
    void demanderArretDiapo();
    void demanderChangerVitesse();

    // Actions liées au lecteur
    void demanderChargement();
    void demanderLancement();
    void demanderChangementModeVersManuel();
    void demanderChangementModeVersAUtomatique();
};

#endif // PRESENTATIONLECTEUR_H
