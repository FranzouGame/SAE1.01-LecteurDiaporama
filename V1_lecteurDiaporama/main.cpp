#include <iostream>
#include <vector>
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
    Lecteur lecteurDiapos;
    vector<Image> images;          // les images
    int attente;

    // Chargement des urls des images, chargement des diaporamas
    lecteurDiapos.charger(images);
    lecteurDiapos.chargerDiapos(images);

    cout << "J'ai chargé les images et diapos" << endl;

    //lecteurDiapos.getDiapoCourant().afficherImageCouranteDansDiaporamaCourant();
    cout << "Nombre de diapos : " << lecteurDiapos.getNombreDiapos() << endl;

    for(unsigned int i = 1; i < lecteurDiapos.getNombreDiapos(); i++)
    {
        cout << "Tri numéro " << i << endl;
        lecteurDiapos.getAllDiapos()[i].triCroissantRang();
    }

    cout << "J'ai tout trié" << endl;

    /* ---------------------
     * Lecteur de diaporamas
     * --------------------- */


    cout << "Diapo courant : "<< endl;
    lecteurDiapos.afficherDiapoCourant();



    /* Faire fonctionner le lecteur
       --------------*/
    char choixAction = ' ' ;              // pour saisir le choix de l'utilisateur dans le menu d'actions possibles
    while (true)
    {

        /* Affichage à l'écran des infos de l'image courante dans son diaporama   */
        system("cls");  // effacer l'écran

        //unsigned int position = diaporamas[diaporamaCourant].getLocalisationImages()[imageCourante].getPos();
        lecteurDiapos.getDiapoCourant().afficherImageCouranteDansDiaporamaCourant();

        /* Menu des actions possibles (saisie choix utilisateur) :
         * A-vancer, R-eculer, C-hanger de diaporama, Q-uitter */

        lecteurDiapos.saisieVerifChoixActionSurImageCourante(choixAction);

        if (choixAction == 'Q')
        {
            break;
        }

        /* Faire l'action demandée (Avancer - Reculer - Changer de Diaporama - Quitter) */
        system("cls");  // effacer l'écran
    }

    /* Fin
       --------------*/
      cout << "Au revoir " << endl;
      return 0;
}

