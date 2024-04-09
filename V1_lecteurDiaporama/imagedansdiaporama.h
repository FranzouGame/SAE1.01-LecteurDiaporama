#ifndef IMAGEDANSDIAPORAMA_H
#define IMAGEDANSDIAPORAMA_H
#include "image.h"

class ImageDansDiaporama : public Image
{
public:
    ImageDansDiaporama(unsigned int pPos, unsigned int pRang);
    int getRang();
    int getPos();
private:
    unsigned int _pos;  // rang de l'image dans le tableau d'images (vector<Images>)
    unsigned int rang; // = ordre de chargement initial des images dans la table des images
};

typedef vector<Image> Images;
typedef vector<Diaporama> Diaporamas;

#endif // IMAGEDANSDIAPORAMA_H
