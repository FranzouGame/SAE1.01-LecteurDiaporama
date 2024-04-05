#ifndef IMAGEDANSDIAPORAMA_H
#define IMAGEDANSDIAPORAMA_H

class ImageDansDiaporama
{
public:
    ImageDansDiaporama(unsigned int pPos, unsigned int pRang);
private:
    unsigned int pos;  // rang de l'image dans le tableau d'images (vector<Images>)
    unsigned int rang; // = ordre de chargement initial des images dans la table des images
    int getRang();
    int getPos();
};

#endif // IMAGEDANSDIAPORAMA_H
