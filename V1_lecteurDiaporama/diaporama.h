#ifndef DIAPORAMA_H
#define DIAPORAMA_H

#include <vector>
#include "image.h"
#include "imagedansdiaporama.h"


class Diaporama {
private:
    // Attributs
    string _titre;
    unsigned int _vitesseDefilement;
    vector<imageDansDiaporama> _localisationImages;
    unsigned int _posImageCourante;
public:
    /*** Constructeurs ***/
    Diaporama();
    Diaporama(string, unsigned int, vector<imageDansDiaporama>, unsigned int);

    /*** Getters ***/
    string getTitre()const;
    vector<imageDansDiaporama> getLocalisationImages() const;
    unsigned int getVitesseDefilement() const;
    unsigned int getNombreImages() const;
    unsigned int getPosImageCourante() const;
    imageDansDiaporama getImageCourante() const;

    /*** Setters ***/
    void setTitre(const string&);
    void setVitesseDefilement(unsigned int);
    void setLocalisationImages(const vector<imageDansDiaporama>&);
    void setPosImageCourante(unsigned int);

    /*** Autres méthodes ***/
    void addImage(const imageDansDiaporama&);
    void avancer();
    void reculer();
    void afficherImageCouranteDansDiaporamaCourant () const;
    void triCroissantRang ();
};





#endif // DIAPORAMA_H
