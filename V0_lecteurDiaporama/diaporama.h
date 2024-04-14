#ifndef DIAPORAMA_H
#define DIAPORAMA_H

#include "imagedansdiaporama.h"
#include "lecteur.h"


class Diaporama {
private:
    // Attributs
    string _titre;
    unsigned int _vitesseDefilement;
    vector<ImageDansDiaporama> _localisationImages;
    unsigned int _posImageCourante;
public:
    /*** Constructeurs ***/
    Diaporama();
    Diaporama(string, unsigned int, vector<ImageDansDiaporama>);

    /*** Getters ***/
    string getTitre()const;
    vector<ImageDansDiaporama> getLocalisationImages() const;
    unsigned int getVitesseDefilement() const;
    unsigned int getNombreImages() const;
    unsigned int getPosImageCourante() const;

    /*** Setters ***/
    void setTitre(const string&);
    void setVitesseDefilement(unsigned int);
    void setLocalisationImages(const vector<ImageDansDiaporama>&);
    void setPosImageCourante(unsigned int);

    /*** Autres méthodes ***/
    void avancer();
    void reculer();
    void charger (Images& pImages);
    void afficherImageCouranteDansDiaporamaCourant () const;
    void triCroissantRang ();
};


#endif // DIAPORAMA_H
