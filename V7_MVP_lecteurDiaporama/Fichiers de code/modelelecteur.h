#ifndef MODELELECTEUR_H
#define MODELELECTEUR_H

// Inclusions
#include <QObject>
#include "lecteur.h"
#include <QSqlDatabase>



struct InfosDiaporama {
    unsigned int id;    // identifiant du diaporama dans la BD
    string titre;       // titre du diaporama
    float vitesseDefilement;
};

// Types nécessaires
typedef vector<InfosDiaporama> Diaporamas;
class Database;

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

    // Méthode d'affichage d'une image, pour éviter le duplicata de code
    void envoiImageCourante();

public:
    /*** Méthodes ***/

    // Constructeur
    explicit ModeleLecteur(Lecteur*, UnEtat = UnEtat::Initial);
    ModeleLecteur();
    ~ModeleLecteur();

    // Getters
    UnEtat getEtat() const;
    Lecteur* getLecteur() const;
    Database* getDatabase() const;
    unsigned int recupereVitesseDfl(); // getter indirect

    // Setters
    void setEtat(ModeleLecteur::UnEtat);
    void setLecteur(Lecteur*);
    void setDatabase(Database*);

    // Autres méthodes
    void demanderRetourImage1();

public slots:
    void demandeAvancement();
    void demandeReculement();
    void demandeEnleverDiapo();
    void demanderInfosDiapos();
    void receptionDemandeChangementDiaporama(InfosDiaporama);
    void receptionDemandeChangementVitesse(unsigned int);

signals:
    void imageChanged(const QString& chemin, const QString& titre, const QString& categorie);
    void diapoChanged(const QString& titreDiapo);
    void sendDiapoInfos(Diaporamas);
};

#endif // MODELELECTEUR_H
