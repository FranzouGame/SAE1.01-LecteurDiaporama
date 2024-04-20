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


public:
    /*** Constructeurs ***/
    Lecteur();
    Lecteur(vector<Diaporama>, unsigned int);


    /*** Getters ***/
    vector<Diaporama> getAllDiapos() const;
    Diaporama& getDiapoCourant();
    unsigned int getNumDiapoCourant() const;
    unsigned int getNombreDiapos() const;

    /*** Setters ***/
    void setAllDiapos(const vector<Diaporama>&);
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
