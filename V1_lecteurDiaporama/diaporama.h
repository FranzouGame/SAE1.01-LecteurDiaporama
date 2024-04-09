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
    unsigned int _posCourante; //position courante du diaporama
    unsigned int _nbImages; //nombre d'images du diaporama
public:
    void creerDiaporama (Diaporama* );
    Diaporama(string="", unsigned int=0, vector<ImageDansDiaporama> images = vector<ImageDansDiaporama>());
    string getTitre() const ;
    //getter du titre
    unsigned int getVitesseDefilement() const ;
    //getter de la vitesse de filement
    unsigned int getPosCourante() const ;
    //getter de la position courante
    ImageDansDiaporama getImageCourante() const ;
    //getter des images
    unsigned int getNbImages()const;
    //retourne le nombre d'images du diaporama
    void afficherImageCouranteDansDiaporamaCourant (const Diaporama& pDiaporama, const Image& pImage);
    /* Affichage à l'acran des infos de l'image courante dans son diaporama
 *    - titre du diaporama
      - image courante : titre, famille, contenu
      - rang de l'image courante dans le diaporama / nbre total d'images du diaporama */

};
typedef vector<Image> Images;
typedef vector<Diaporama> Diaporamas;

#endif // DIAPORAMA_H
