#ifndef MODELELECTEUR_H
#define MODELELECTEUR_H

// Inclusions
#include <QObject>

class ModeleLecteur : public QObject
{
    Q_OBJECT
private:
    // Type énuméré état
    enum UnEtat {Automatique, Manuel, ChoixDiaporama};
private:
    // Attributs
    UnEtat _etat;

public:
    /*** Méthodes ***/

    // Constructeur
    ModeleLecteur();

    // Getters
    UnEtat getEtat() const;

    // Setters
    void setEtat(ModeleLecteur::UnEtat);

};

#endif // MODELELECTEUR_H
