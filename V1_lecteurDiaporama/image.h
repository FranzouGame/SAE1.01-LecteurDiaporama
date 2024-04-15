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
    unsigned int _rang;
    unsigned int _pos;

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
    unsigned int getRang() const;
    unsigned int getPos() const;

    /*** SETTERS ***/
    void setCategorie(string);
    void setTitre(string);
    void setChemin(string);
    void setRang(unsigned int);
    void setPos(unsigned int);

    /*** AUTRES METHODES ***/
    void afficher() const;
};


#endif // IMAGE_H
