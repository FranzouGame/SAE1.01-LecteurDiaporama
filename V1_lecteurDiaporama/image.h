#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
using namespace std;

class Image
{
private:
    string _titre;
    string _categorie;
    string _chemin;
public:
    Image(string pTitre="", string pCategorie="", string pChemin = "");
    ~Image();
    string getCategorie() const; // Récupérer la catégorie
    string getTitre() const; // Récupérer le titre
    string getChemin() const; // Récupérer le chemin
    void afficher() const; // Afficher toutes les infos d'images
};

#endif // IMAGE_H
