#include "diaporama.h"


/***********************
 *      METHODES
 **********************/


/*** Constructeurs ***/

Diaporama::Diaporama() :
    _titre(""),
    _vitesseDefilement(0) {}

Diaporama::Diaporama(string titre, unsigned int vitesseDefilement, vector<ImageDansDiaporama> _localisationImages) :
    _titre(titre),
    _vitesseDefilement(vitesseDefilement),
    _localisationImages(_localisationImages) {}



/*** Getters ***/

string Diaporama::getTitre() const
{
    return _titre;
}

vector<ImageDansDiaporama> Diaporama::getLocalisationImages() const
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



/*** Setters ***/

void Diaporama::setTitre(const string& titre)
{
    _titre = titre;
}

void Diaporama::setVitesseDefilement(unsigned int vitesseDefilement)
{
    _vitesseDefilement = vitesseDefilement;
}

void Diaporama::setLocalisationImages(const vector<ImageDansDiaporama>& localisationImages)
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
    cout << this->getLocalisationImages()[this->getPosImageCourante()].getRang() << " sur " <<  this->getNombreImages() << " / ";
    (this->getLocalisationImages()[this->getPosImageCourante()]).afficher();
}

void Diaporama::triCroissantRang ()
{
    unsigned int taille = this->getNombreImages();
    for (unsigned int ici = taille-1; ici >=1 ; ici--)
    {
        // faire monter la bulle ici = déplacer l'élément de rang le plus grand en position ici
        // par échanges successifs
        for (unsigned int i = 0; i < ici; i++)
        {
            if (this->getLocalisationImages()[i].getRang() > this->getLocalisationImages()[i].getRang())
            {
                // echanger les 2 éléments
                ImageDansDiaporama temp = this->getLocalisationImages()[i];
                this->getLocalisationImages()[i] = this->getLocalisationImages()[i + 1];
                this->getLocalisationImages()[i + 1] = temp;
            }
        }
    }
}


