#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
using namespace std;

// Module de manipulation d'éléments de type Image

class Image
{
private:
    // Attributs
    string _titre;              // intitulé de l'image
    string _categorie;          // catégorie de l'image (personne, animal, objet)
    string _chemin;

public:
    // Constructeurs
    Image();
    Image(const Image&);
    Image(string, string, string);

    // Méthodes
    /*** GETTERS ***/
    string getCategorie() const;
    string getTitre() const;
    string getChemin() const;

    /*** SETTERS ***/
    void setCategorie(string);
    void setTitre(string);
    void setChemin(string);

    /*** AUTRES METHODES ***/
    void afficher() const;
};


#endif // IMAGE_H
