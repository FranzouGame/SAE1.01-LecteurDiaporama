#include <iostream>
#include "diaporama.h"
#include "lecteur.h"
using namespace std;



int main()
{
    /* -------------------------------------------------------------------------------------
     * Charge les images et les diaporamas 'en dur' ... en attendant l'implantation de la BD :
     * - Charger les images et diaporamas
     * Dans un second temps, ces contenus proviendront d'une base de données
     --------------------------------------------------------------------------------------*/
    Lecteur lecteurDiapos;         // Le lecteur

    // Chargement des urls des images, chargement des diaporamas
    lecteurDiapos.charger();
    lecteurDiapos.chargerDiapos();


    //lecteurDiapos.getDiapoCourant().afficherImageCouranteDansDiaporamaCourant();
    cout << "Nombre de diapos : " << lecteurDiapos.getNombreDiapos() << endl;

    // Trier les diapos en fonction du rang des images dans celles-ci
    for(unsigned int i = 1; i < lecteurDiapos.getNombreDiapos(); i++)
    {
        cout << "Tri numéro " << i << endl;
        lecteurDiapos.getAllDiapos()[i].triCroissantRang();
    }


    /* ---------------------
     * Lecteur de diaporamas
     * --------------------- */


    // Faire fonctionner le lecteur
    char choixAction = ' ' ;              // Pour saisir le choix de l'utilisateur dans le menu d'actions possibles
    while (true)
    {

        // Effacer l'écran
        system("cls");

        // Afficher l'image courante
        lecteurDiapos.getDiapoCourant().afficherImageCouranteDansDiaporamaCourant();

        // Saisie-vérification du choix de l'utilisateur
        lecteurDiapos.saisieVerifChoixActionSurImageCourante(choixAction);

        if (choixAction == 'Q')
        {
            break;
        }
    }

    /* Fin
       --------------*/
    cout << "Au revoir " << endl;
    return 0;
}

