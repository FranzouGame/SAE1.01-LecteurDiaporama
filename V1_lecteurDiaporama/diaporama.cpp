#include "diaporama.h"


/***********************
 *      METHODES
 **********************/


/*** Constructeurs ***/

Diaporama::Diaporama() :
    _titre(""),
    _vitesseDefilement(0),
    _posImageCourante(0)
    {}

Diaporama::Diaporama(string titre, unsigned int vitesseDefilement, vector<Image> _localisationImages, unsigned int posImgCourante) :
    _titre(titre),
    _vitesseDefilement(vitesseDefilement),
    _localisationImages(_localisationImages),
        _posImageCourante(posImgCourante){

}



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

const Image& Diaporama::getImageCourante() const
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

    cout << "Jai pas plante 1" << endl;

    cout << getImageCourante().getRang() << " sur " << getNombreImages() << " / ";


    cout << "Jai pas plante 2" << endl;

    getImageCourante().afficher();
}

void Diaporama::triCroissantRang() {
    bool estEchange = true;
    unsigned int taille = _localisationImages.size();

    // Parcourir le tableau jusqu'à ce qu'il n'y ait plus d'échanges à effectuer
    for (unsigned int i = 0; i < taille - 1 && estEchange; i++) {
        estEchange = false;
        // Parcourir le tableau à partir de la première image
        for (unsigned int j = 0; j < taille - i - 1; j++) {
            // Comparer le rang de l'image actuelle avec celui de l'image suivante
            if (_localisationImages[j].getRang() > _localisationImages[j + 1].getRang()) {
                // Échanger les deux images si l'ordre n'est pas correct
                swap(_localisationImages[j], _localisationImages[j + 1]);
                estEchange = true;
            }
        }
    }
}
