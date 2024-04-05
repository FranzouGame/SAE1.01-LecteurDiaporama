#include "diaporama.h"

Diaporama::Diaporama(string pTitre, unsigned int pVitesseDefilement, vector<ImageDansDiaporama> pLocalisationImages):
    _titre(pTitre),
    _vitesseDefilement(pVitesseDefilement),
    _localisationImages(pLocalisationImages)

{}

void Diaporama::creerDiaporama (Diaporama* pDiaporama){
    _titre = pDiaporama->_titre;
    _vitesseDefilement = pDiaporama ->_vitesseDefilement;
    _localisationImages = pDiaporama ->_localisationImages;
}
