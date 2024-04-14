#include "image.h"


/********************************
 *          METHODES
 *******************************/

/*** Constructeurs ***/
Image::Image():    // Constructeur par défaut
    _titre(""),
    _categorie(""),
    _chemin(""){
}

Image::Image(const Image& origin):    // Constructeur de copie
    _titre(origin.getTitre()),
    _categorie(origin.getCategorie()),
    _chemin(origin.getChemin()){
}

Image::Image(string pTitre, string pCategorie, string pChemin):  // Constructeur complet
    _titre(pTitre),
    _categorie(pCategorie),
    _chemin(pChemin){
}



/*** Getters ***/

string Image::getCategorie() const
{
    return _categorie;
}

string Image::getTitre() const
{
    return _titre;
}

string Image::getChemin() const
{
    return _chemin;
}


/*** Setters ***/

void Image::setCategorie(string pCate)
{
    _categorie = pCate;
}

void Image::setTitre(string pTitre)
{
    _titre = pTitre;
}

void Image::setChemin(string pPath)
{
    _chemin = pPath;
}


/*** Autres méthodes ***/
void Image::afficher() const
{
    cout << "image(titre:" << (*this).getTitre() << ", categorie:"
         << (*this).getCategorie() << ", chemin:"<< (*this).getChemin() << ")" << endl;
}
