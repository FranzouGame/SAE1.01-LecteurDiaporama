#ifndef DIAPORAMA_H
#define DIAPORAMA_H

#include <vector>
#include "image.h"


typedef vector<Image> Images;

class Diaporama {
private:
    // Attributs
    string _titre;
    unsigned int _vitesseDefilement;
    vector<Image> _localisationImages;
    unsigned int _posImageCourante;
public:
    /*** Constructeurs ***/
    Diaporama();
    Diaporama(string, unsigned int, vector<Image>);

    /*** Getters ***/
    string getTitre()const;
    vector<Image> getLocalisationImages() const;
    unsigned int getVitesseDefilement() const;
    unsigned int getNombreImages() const;
    unsigned int getPosImageCourante() const;
    Diaporama getDiaporamaCourant() const;
    Image getImageCourante() const;

    /*** Setters ***/
    void setTitre(const string&);
    void setVitesseDefilement(unsigned int);
    void setLocalisationImages(const vector<Image>&);
    void setPositionImageDansVecteur(unsigned int);
    void setPosImageCourante(unsigned int);

    /*** Autres méthodes ***/
    void avancer();
    void reculer();
    void afficherImageCouranteDansDiaporamaCourant () const;
    void triCroissantRang ();
};





#endif // DIAPORAMA_H
