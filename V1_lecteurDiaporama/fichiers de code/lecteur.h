#ifndef LECTEUR_H
#define LECTEUR_H

// Inclusions
#include <vector>
#include "diaporama.h"
using namespace std;


typedef vector<Diaporama> Diaporamas;

class Image;

class Lecteur
{
private:
    Diaporamas _allDiapos;
    unsigned int _numDiapoCourant;


public:
    /*** Constructeurs ***/
    Lecteur();
    Lecteur(Diaporamas, unsigned int);


    /*** Getters ***/
    Diaporamas getAllDiapos() const;
    Diaporama& getDiapoCourant();
    unsigned int getNumDiapoCourant() const;
    unsigned int getNombreDiapos() const;

    /*** Setters ***/
    void setAllDiapos(const Diaporamas&);
    void setNumDiapoCourant(unsigned int);

    /*** Autres méthodes ***/
    void declencherAction(char);
    void saisieVerifChoixActionSurImageCourante(char&);
    unsigned int saisieVerifChoixDiaporama();
    void charger(Images&);
    void chargerDiapos(Images);
    void afficherDiapoCourant();
};



#endif // LECTEUR_H
