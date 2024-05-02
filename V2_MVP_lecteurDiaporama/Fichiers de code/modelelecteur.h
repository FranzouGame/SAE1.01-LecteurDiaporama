#ifndef MODELELECTEUR_H
#define MODELELECTEUR_H


class ModeleLecteur
{

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
