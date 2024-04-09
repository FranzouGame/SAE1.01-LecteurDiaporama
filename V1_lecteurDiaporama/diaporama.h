#ifndef DIAPORAMA_H
#define DIAPORAMA_H
#include <vector>
#include "image.h"
#include "imagedansdiaporama.h"
class Diaporama
{
private :
    string _titre ;  // titre du diaporama
    unsigned int _vitesseDefilement; // vitesse de défilement des images du diaporama
    vector <ImageDansDiaporama> _localisationImages; // images du diaporama
public:
    void creerDiaporama (Diaporama* );
    Diaporama(string="", unsigned int=0, vector<ImageDansDiaporama> );

};

typedef vector<Diaporama> Diaporamas;

#endif // DIAPORAMA_H
