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
/*
----------------------------------------
Getter de la class Diaporama
----------------------------------------
*/
string Diaporama::getTitre() const {
    return _titre;
}

unsigned int Diaporama::getVitesseDefilement() const {
    return this->_vitesseDefilement;
}
unsigned int Diaporama::getPosCourante() const {
    return this->_posCourante;
}
ImageDansDiaporama Diaporama::getImageCourante() const {
    return this->_localisationImages[getPosCourante()];
}
unsigned int Diaporama::getNbImages()const{
    return this->_nbImages;
}
/*
----------------------------------------
Setter de la class Diaporama
----------------------------------------
*/
void Diaporama::setPosCourante(unsigned int pPosCourante){
    this->_posCourante = pPosCourante;
}
void Diaporama::setNbImages(unsigned int pNbImages){
    this->_nbImages = pNbImages;
}
void Diaporama::setVitesseDefilement(unsigned int pVitesseDefilement){
    this->_vitesseDefilement = pVitesseDefilement;
}
void Diaporama::setTitre(string pTitre){
    this->_titre = pTitre;
}
void Diaporama::setImageCourante(ImageDansDiaporama pImageCourante){
    this->_localisationImages[getPosCourante()] = pImageCourante;
}
void afficherImageCouranteDansDiaporamaCourant (const Diaporama& pDiaporama, const Image& pImage)
{
    cout << endl << endl;
    cout << "DIAPORAMA : " << pDiaporama.Diaporama::getTitre() << endl << endl;
    cout << pDiaporama.getImageCourante().getRang() << " sur " <<  pDiaporama.getNbImages() << " / ";
    pImage.afficher();
}
void charger (Images& pImages) {
    Image imageACharger;
    imageACharger = Image( "","objet", "C:\\cartesDisney\\Disney_tapis.gif");
    pImages.push_back(imageACharger);
    imageACharger = Image ( "Blanche Neige","personnage", "C:\\cartesDisney\\Disney_4.gif");
    pImages.push_back(imageACharger);
    imageACharger = Image ( "Alice","personnage", "C:\\cartesDisney\\Disney_2.gif");
    pImages.push_back(imageACharger);
    imageACharger = Image ( "Mickey","animal", "C:\\cartesDisney\\Disney_19.gif");
    pImages.push_back(imageACharger);
    imageACharger = Image ( "Pinnochio","personnage", "C:\\cartesDisney\\Disney_29.gif");
    pImages.push_back(imageACharger);
    imageACharger = Image ( "chateau","objet", "C:\\cartesDisney\\Disney_0.gif");
    pImages.push_back(imageACharger);
    imageACharger = Image ( "Minnie","personnage", "C:\\cartesDisney\\Disney_14.gif");
    pImages.push_back(imageACharger);
    imageACharger = Image ( "Bambi","animal", "C:\\cartesDisney\\Disney_3.gif");
    pImages.push_back(imageACharger);
}
