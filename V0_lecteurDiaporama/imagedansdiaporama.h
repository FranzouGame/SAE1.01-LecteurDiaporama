#ifndef IMAGEDANSDIAPORAMA_H
#define IMAGEDANSDIAPORAMA_H

// Inclusions
#include "image.h"
#include <iostream>
#include <vector>
using namespace std;


class ImageDansDiaporama : public Image
{
private:
    unsigned int _position; // rang de l'image dans le tableau d'images (vector<Images>)
                            // = ordre de chargement initial des images dans la table des images
    unsigned int _rang;     // rang de l'image dans le diaporama
                            // = ordre d'affichage choisi par l'utilisateur lors de la création du diaporama
public:

    /*** Constructeurs ***/
    ImageDansDiaporama();
    ImageDansDiaporama(unsigned int, unsigned int);
    ImageDansDiaporama(const ImageDansDiaporama&);


    /*** Getters ***/
    unsigned int getPos() const;
    unsigned int getRang() const;

    /*** Setters ***/
    void setPos(unsigned int);
    void setRang(unsigned int);


    /** Autres méthodes ***/
};

#endif // IMAGEDANSDIAPORAMA_H
