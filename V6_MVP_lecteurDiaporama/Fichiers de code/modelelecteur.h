#ifndef MODELELECTEUR_H
#define MODELELECTEUR_H

// Inclusions
#include <QObject>
#include "lecteur.h"


struct InfosDiaporama {
    unsigned int id;    // identifiant du diaporama dans la BD
    string titre;       // titre du diaporama
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
    Diaporamas _infosDiapos;

public:
    /*** Méthodes ***/

    // Constructeur
    explicit ModeleLecteur(Lecteur*, UnEtat = UnEtat::Initial, Diaporamas = {});
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
    unsigned int recupereVitesseDfl();
    void demanderRetourImage1(int = 0);

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
