#ifndef LECTEUR_H
#define LECTEUR_H

// Inclusions
#include <vector>
#include "diaporama.h"
using namespace std;




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
    Lecteur(vector<Diaporama>, unsigned int, unsigned int);


    /*** Getters ***/
    vector<Diaporama> getAllDiapos() const;
    Diaporama getDiapoCourant() const;
    unsigned int getNumDiapoCourant() const;
    unsigned int getNombreDiapos() const;

    /*** Setters ***/
    void setAllDiapos(const vector<Diaporama>&);
    void setNumDiapoCourant(unsigned int);
    void setNombreDiapos(unsigned int);

    /*** Autres méthodes ***/
    void declencherAction(char pChoixAction);
    char saisieVerifChoixActionSurImageCourante();
    unsigned int saisieVerifChoixDiaporama();
    void charger(Images&);
    void chargerDiapos(Images&);
    void afficherDiapoCourant();
};



#endif // LECTEUR_H
