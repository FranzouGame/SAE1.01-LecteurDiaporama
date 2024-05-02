#ifndef IMAGEDANSDIAPORAMA_H
#define IMAGEDANSDIAPORAMA_H

#include "image.h"
#include <vector>

// Types et classes nécessaires
typedef vector<Image> Images;

class imageDansDiaporama : public Image
{   
private:
    // Attributs
    unsigned int _rang; // Rang de l'image dans le tableau d'images
    unsigned int _pos; // Rang de l'image dans le diaporama

public:
    /*** Constructeurs ***/
    imageDansDiaporama();
    imageDansDiaporama(const Image&, unsigned int, unsigned int);
    imageDansDiaporama(Images&, unsigned int, unsigned int);

    /*** Getters ***/
    unsigned int getRang() const;
    unsigned int getPos() const;
    const Image& getImage() const;

    /*** Setters ***/
    void setRang(unsigned int);
    void setPos(unsigned int);

    /*** Autres méthodes ***/
    void afficherImageCourante() const;

};

#endif // IMAGEDANSDIAPORAMA_H
