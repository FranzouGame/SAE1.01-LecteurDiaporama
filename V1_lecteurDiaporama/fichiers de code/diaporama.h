#ifndef DIAPORAMA_H
#define DIAPORAMA_H

#include <vector>
#include "image.h"
#include "imagedansdiaporama.h"

typedef vector<imageDansDiaporama> ImagesDuDiaporama;

class Diaporama {
private:
    // Attributs
    string _titre;
    unsigned int _vitesseDefilement;
    ImagesDuDiaporama _localisationImages;
    unsigned int _posImageCourante;
public:
    /*** Constructeurs ***/
    Diaporama();
    Diaporama(string, unsigned int = 1, ImagesDuDiaporama = {}, unsigned int = 0);
    Diaporama(string, unsigned int, unsigned int);

    /*** Getters ***/
    string getTitre()const;
    ImagesDuDiaporama getLocalisationImages() const;
    unsigned int getVitesseDefilement() const;
    unsigned int getNombreImages() const;
    unsigned int getPosImageCourante() const;
    imageDansDiaporama getImageCourante() const;

    /*** Setters ***/
    void setTitre(const string&);
    void setVitesseDefilement(unsigned int);
    void setLocalisationImages(const ImagesDuDiaporama&);
    void setPosImageCourante(unsigned int);

    /*** Autres méthodes ***/
    void addImage(const imageDansDiaporama&);
    void avancer();
    void reculer();
    void afficherImageCouranteDansDiaporamaCourant () const;
    void triCroissantRang ();
};





#endif // DIAPORAMA_H
