#ifndef LECTEUR_H
#define LECTEUR_H

// Inclusions
#include "typeDiaporama.h"
#include <vector>
using namespace std;

// Types et classes nécessaires
class Diaporama;
typedef vector<Diaporama> Diaporamas;
typedef vector<Image> Images;


class Lecteur
{
private:
    Diaporamas _allDiapos;
    Diaporama _diapoCourant;
    unsigned int _numDiapoCourant;

public:
    /*** Constructeurs ***/
    Lecteur(); // Constructeur par défaut
    Lecteur(Diaporama diapoCourant, unsigned int numDiapoCourant);

    /*** Getters ***/
    Diaporama getDiapoCourant() const;
    unsigned int getNumDiapoCourant() const;

    /*** Setters ***/
    void setDiapoCourant(const Diaporama& diapoCourant);
    void setNumDiapoCourant(unsigned int numDiapoCourant);

    /*** Autres méthodes ***/
    void declencherAction(char pChoixAction);
    void saisieVerifChoixActionSurImageCourante(char& pChoixAction);
    unsigned int saisieVerifChoixDiaporama();





    void afficherDiapoCourant();
    void changerDiapo();
};



#endif // LECTEUR_H
