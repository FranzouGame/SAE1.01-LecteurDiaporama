#include "diaporama.h"


/***********************
 *      METHODES
 **********************/


/*** Constructeurs ***/

Diaporama::Diaporama() :
    _titre(""),
    _vitesseDefilement(0) {}

Diaporama::Diaporama(string titre, unsigned int vitesseDefilement, vector<Image> _localisationImages) :
    _titre(titre),
    _vitesseDefilement(vitesseDefilement),
    _localisationImages(_localisationImages) {}



/*** Getters ***/

string Diaporama::getTitre() const
{
    return _titre;
}

vector<Image> Diaporama::getLocalisationImages() const
{
    return _localisationImages;
}

unsigned int Diaporama::getVitesseDefilement() const
{
    return _vitesseDefilement;
}

unsigned int Diaporama::getNombreImages() const
{
    return _localisationImages.size();
}

unsigned int Diaporama::getPosImageCourante() const
{
    return _posImageCourante;
}
Diaporama Diaporama::getDiaporamaCourant() const
{
    return *this;
}

Image Diaporama::getImageCourante() const
{
    return getLocalisationImages()[getPosImageCourante()];
}



/*** Setters ***/

void Diaporama::setTitre(const string& titre)
{
    _titre = titre;
}

void Diaporama::setVitesseDefilement(unsigned int vitesseDefilement)
{
    _vitesseDefilement = vitesseDefilement;
}

void Diaporama::setLocalisationImages(const vector<Image>& localisationImages)
{
    _localisationImages = localisationImages;
}

void Diaporama::setPosImageCourante(unsigned int pPosCourante)
{
    _posImageCourante = pPosCourante;
}

void setPositionImageDansVecteur(unsigned int)
{

}




/*** Autres méthodes ***/


void Diaporama::avancer()
{
    // Vérifier la postion actuelle, si on est à la dernière image du diaporama, on passe à 0 , sinon on avance d'une image
    if (this->getPosImageCourante() == this->getNombreImages() - 1)
    {
        this->setPosImageCourante(0);
    }
    else {
        this->setPosImageCourante(getPosImageCourante() + 1);
    }
}

void Diaporama::reculer()
{
    // Vérifier la postion actuelle, si on est à 0, on passe à la dernière image du diaporama, sinon on recule d'une image
    if (this->getPosImageCourante() == 0)
    {
       this->setPosImageCourante(getNombreImages() - 1);
    }
    else
    {
        this->setPosImageCourante(getPosImageCourante() - 1);
    }
}

void Diaporama::afficherImageCouranteDansDiaporamaCourant () const
{
    cout << endl << endl;
    cout << "DIAPORAMA : " << this->getTitre() << endl << endl;
    cout << getImageCourante().getRang() << " sur " <<  this->getNombreImages() << " / ";
    getImageCourante().afficher();
}

void Diaporama::triCroissantRang()
{
    unsigned int taille = this->getNombreImages();
    for (unsigned int ici = taille - 1; ici >= 1; ici--)
    {
        // Parcourir le tableau et échanger les éléments adjacents si nécessaire
        for (unsigned int i = 0; i < ici; i++)
        {
            // Vérifier si l'élément actuel a un rang supérieur à l'élément suivant
            if (this->getLocalisationImages()[i].getRang() > this->getLocalisationImages()[i + 1].getRang())
            {
                // Échanger les deux éléments
                Image temp = this->getLocalisationImages()[i];
                this->getLocalisationImages()[i] = this->getLocalisationImages()[i + 1];
                this->getLocalisationImages()[i + 1] = temp;
            }
        }
    }
}
