#ifndef MODELELECTEUR_H
#define MODELELECTEUR_H

// Inclusions
#include <QObject>
#include "lecteur.h"


struct InfosDiaporama {
    unsigned int id;    // identifiant du diaporama dans la BD
    string titre;       // titre du diaporama
<<<<<<< HEAD
    float vitesseDefilement;
=======
    unsigned int vitesseDefilement;
>>>>>>> V4
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
<<<<<<< HEAD
    Diaporamas _infosDiapos;
=======
>>>>>>> V4

public:
    /*** Méthodes ***/

    // Constructeur
<<<<<<< HEAD
    explicit ModeleLecteur(Lecteur*, UnEtat = UnEtat::Initial, Diaporamas = {});
    ModeleLecteur();
    ~ModeleLecteur();
=======
    explicit ModeleLecteur(Lecteur*, UnEtat = UnEtat::Initial);
    ModeleLecteur();
>>>>>>> V4

    // Getters
    UnEtat getEtat() const;
    Lecteur* getLecteur() const;
<<<<<<< HEAD
    Diaporamas getInfosDiapos() const;
=======
>>>>>>> V4

    // Setters
    void setEtat(ModeleLecteur::UnEtat);
    void setLecteur(Lecteur*);
<<<<<<< HEAD
    void setInfosDiapos(Diaporamas);

    // Autres méthodes
    void chargerDiapos();
=======

    // Autres méthodes
>>>>>>> V4
    unsigned int recupereVitesseDfl();
    void demanderRetourImage1(int = 0);

public slots:
    void demandeAvancement();
    void demandeReculement();
<<<<<<< HEAD
    void demandeEnleverDiapo();
    void demanderInfosDiapos();
    void receptionDemandeChangementDiaporama(InfosDiaporama);
    void receptionDemandeChangementVitesse(unsigned int);
=======
    void demandeAffichageImageDebut();
    void demanderAffichage1erDiapo();
>>>>>>> V4

signals:
    void imageChanged(const QString& chemin, const QString& titre, const QString& categorie);
    void diapoChanged(const QString& titreDiapo);
<<<<<<< HEAD
    void sendDiapoInfos(Diaporamas);
=======
>>>>>>> V4
};

#endif // MODELELECTEUR_H
