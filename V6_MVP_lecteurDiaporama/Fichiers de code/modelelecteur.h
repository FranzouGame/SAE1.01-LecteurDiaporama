#ifndef MODELELECTEUR_H
#define MODELELECTEUR_H

// Inclusions
#include <QObject>
#include "lecteur.h"

// Classe nécessaires
class Database;


struct InfosDiaporama {
    unsigned int id;    // identifiant du diaporama dans la BD
    std::string titre;       // titre du diaporama
    float vitesseDefilement;
};

// Type nécessaire
typedef vector<InfosDiaporama> Diaporamas;



class ModeleLecteur : public QObject
{
    Q_OBJECT
public:
    // Type énuméré état
    enum UnEtat {Automatique, Manuel, ChoixDiaporama, Initial, ChoixVitesseDefilement};
private:
    // Attributs
    UnEtat _etat;
    Lecteur* _lecteur;
    Database* _database;

    // Méthode d'envoie de l'image courante
    void envoieImageCourante();

public:
    /*** Méthodes ***/

    // Constructeur
    explicit ModeleLecteur(Lecteur*, UnEtat = UnEtat::Initial);
    ModeleLecteur();
    ~ModeleLecteur();

    // Getters
    UnEtat getEtat() const;
    Lecteur* getLecteur() const;
    Diaporamas getInfosDiapos() const;

    // Setters
    void setEtat(ModeleLecteur::UnEtat);
    void setLecteur(Lecteur*);
    void setInfosDiapos(Diaporamas);

    // Autres méthodes
    void chargerDiapos();

public slots:
    void demandeAvancement();
    void demandeReculement();
    void demandeEnleverDiapo();
    void demanderInfosDiapos();
    void receptionDemandeChangementDiaporama(InfosDiaporama);
    void receptionDemandeChangementVitesse(float);

signals:
    void imageChanged(const QString& chemin, const QString& titre, const QString& categorie);
    void diapoChanged(const QString& titreDiapo);
    void sendDiapoInfos(Diaporamas);

private slots:
    // void recupereDiaposDepuisBD(Diaporamas);
    void recupereImagesDiapoDepuisBD(Diaporama);
};

#endif // MODELELECTEUR_H
