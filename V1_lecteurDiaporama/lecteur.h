#ifndef LECTEUR_H
#define LECTEUR_H

// Inclusions
#include <vector>
#include "diaporama.h"
using namespace std;


// Types et classes nécessaires

class Image;

class Lecteur
{
private:
    vector<Diaporama> _allDiapos;
    unsigned int _numDiapoCourant;
    unsigned int _nombreDiapos;

public:
    /*** Constructeurs ***/
    Lecteur(); // Constructeur par défaut
    Lecteur(vector<Diaporama> diapos, unsigned int numDiapoCourant, unsigned int nbDiapos);


    /*** Getters ***/
    Diaporamas getAllDiapos() const;
    Diaporama getDiapoCourant() const;
    unsigned int getNumDiapoCourant() const;
    unsigned int getNombreDiapos() const;

    /*** Setters ***/
    void setAllDiapos(const vector<Diaporama>&);
    void setDiapoCourant(const Diaporama&);
    void setNumDiapoCourant(unsigned int);
    void setNombreDiapos(unsigned int);

    /*** Autres méthodes ***/
    void declencherAction(char pChoixAction);
    void saisieVerifChoixActionSurImageCourante(char&);
    unsigned int saisieVerifChoixDiaporama();
    void charger (Images&);
    void charger(Diaporamas&);
    void afficherDiapoCourant();
    void changerDiapo();
};



#endif // LECTEUR_H
