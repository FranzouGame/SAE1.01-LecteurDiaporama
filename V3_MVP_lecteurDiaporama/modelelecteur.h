#ifndef MODELELECTEUR_H
#define MODELELECTEUR_H

// Inclusions
#include <QObject>
#include "lecteur.h"

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

public:
    /*** Méthodes ***/

    // Constructeur
    explicit ModeleLecteur(Lecteur*, UnEtat = UnEtat::Initial);
    ModeleLecteur();

    // Getters
    UnEtat getEtat() const;
    Lecteur* getLecteur() const;

    // Setters
    void setEtat(ModeleLecteur::UnEtat);
    void setLecteur(Lecteur*);

public slots:
    void demandeAvancement();
    void demandeReculement();
};

#endif // MODELELECTEUR_H
