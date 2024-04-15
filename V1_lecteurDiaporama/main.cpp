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
    Images images;          // les images


    // Chargement des urls des images, chargement des diaporamas
    lecteurDiapos.charger(images);
    lecteurDiapos.chargerDiapos();

    cout << "J'ai chargé les images et diapos" << endl;

    //lecteurDiapos.getDiapoCourant().afficherImageCouranteDansDiaporamaCourant();
    cout << "Nombre de diapos : " << lecteurDiapos.getNombreDiapos() << endl;

    for(int i = 1; i < lecteurDiapos.getNombreDiapos(); i++)
    {
        cout << "Tri numéro " << i << endl;
        lecteurDiapos.getAllDiapos()[i].triCroissantRang();
    }

    cout << "J'ai tout trié" << endl;

    /* ---------------------
     * Lecteur de diaporamas
     * --------------------- */

    // Elements autres que les images et diaporamas
    unsigned int diaporamaCourant ; // identifiant du diaporama courant = indice dans le tableau diaporamas
    unsigned int imageCourante ;    // identifiant de l'image courante du diaporama courant
                                    // = indice de l'image dans le tableau diaporamas[diaporamaCourant].images, trié par ordre croissant de rang

    /* Initialiser le diaporama et l'image courants
     * ---------------
       Les valeurs courantes sont définies par défaut
       --> cela suppose qu'il y a toujours au moins 1 diaporama avec au moins 1 image dedans.
       Autre option (meilleure, à mettre en place dans la version graphique)) :
       - pas de diaporama courant au lancement de l'application
       - le diaporama courant est choisi par l'utilisateur parmi une liste de diaporamas disponibles. */






    /* Faire fonctionner le lecteur
       --------------*/
    char choixAction ;              // pour saisir le choix de l'utilisateur dans le menu d'actions possibles
    unsigned int choixDiaporama = 0 ;  // pour saisir le numéro de diaporama choisi par l'utilisiateur
    while (true)
    {

        /* Affichage à l'écran des infos de l'image courante dans son diaporama   */
        system("cls");  // effacer l'écran

        cout << "J'ai efface" << endl;

        //unsigned int position = diaporamas[diaporamaCourant].getLocalisationImages()[imageCourante].getPos();
        (lecteurDiapos.getAllDiapos()[choixDiaporama]).afficherImageCouranteDansDiaporamaCourant ();

        cout << "Step 1 passee " << endl;

        /* Menu des actions possibles (saisie choix utilisateur) :
         * A-vancer, R-eculer, C-hanger de diaporama, Q-uitter */

        lecteurDiapos.saisieVerifChoixActionSurImageCourante(choixAction);
        if (choixAction == 'Q')
        {
            break;
        }

        /* Faire l'action demandée (Avancer - Reculer - Changer de Diaporama - Quitter) */
        system("cls");  // effacer l'écran
        lecteurDiapos.declencherAction(choixAction);
    }

    /* Fin
       --------------*/
      cout << "Au revoir " << endl;
      return 0;
}

