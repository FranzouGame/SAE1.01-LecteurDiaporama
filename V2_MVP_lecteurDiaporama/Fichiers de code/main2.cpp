#include <iostream>
#include "lecteur.h"
#include "imageDansDiaporama.h"
#include "diaporama.h"

using namespace std;

/* InfosDiaporamas et Diaporamas : Types intermédiaires utiles tant
 * que le diaporama du lecteur n'est pas chargé depuis la Base de Données.
 * A éliminer lorsque le diaporama du lecteur sera chargé à partir de la BD
 * -----------------------------------------------------------------------*/
struct InfosDiaporama {
    unsigned int id;    // identifiant du diaporama dans la BD
    string titre;       // titre du diaporama
    unsigned int vitesseDefilement;
};
typedef vector<InfosDiaporama> Diaporamas;


/* Spécifications des sous-programmes utilisés par le main()
 * ---------------------------------------------------*/
void charger (Diaporamas& pDiaporamas);
/* Chargement du tableau des infos sur diaporamas avec des diaporamas préalablement construits 'en dur'.
   Dans une version ultérieure, le diaporama courant affiché par le Lecteur de diaporamas sera chargé à partir
   d'une base de données.
*/

unsigned int saisieVerifChoixDiaporama(const Diaporamas& pDiaporamas);
/* Retourne un numéro de diaporama choisi par l'utilisateur (dans la liste des diaporamas existants) */

void saisieVerifChoixActionSurImageCourante(char& pChoixAction);
/* Saisie du choix d'action de l'utilisateur vis-à-vis de l'image et diaporama courants */

void declencherAction(char pChoixAction, const Diaporamas& pDiaporamas, Lecteur& pLecteur);
/* Selon le pChoix fait l'utilisateur, réalise une des actions A)vancer, R)eculer, C)hoisir un autre diaporama, Q)quitter */


int main()
{ 
    /* Chargement des diaporamas (sans leurs images)
     * Le choix du diaporama se fera plus tard via le menu Paramètres */
    Diaporamas diaporamas;
    charger(diaporamas);

    Lecteur monLecteur;     // positionnement par défaut sur diaporama 0 et sur son unique image

    /* Faire fonctionner le lecteur
       --------------*/
    char choixAction ;              // pour saisir le choix de l'utilisateur dans le menu d'actions possibles

    monLecteur.afficher();
    while (true)
    {
        system("cls");  // effacer l'écran
        monLecteur.afficher();

        // Menu des actions possibles (saisie choix utilisateur) :
             // A-vancer, R-eculer, C-hanger de diaporama, V-vider le lecteur, Q-uitter
             // dans cette version v1, le lecteur démarre vide, cad SANS aucun diaporama préchargé

        saisieVerifChoixActionSurImageCourante(choixAction);

        if (choixAction == 'Q')
        {
            break;
        }

        // Faire l'action demandée (Avancer - Reculer - Changer de Diaporama - Quitter)
        system("cls");  // effacer l'écran
        declencherAction(choixAction, diaporamas, monLecteur); // faire action demandée
    }

    // Fin
    //   --------------
    cout << "Au revoir " << endl;
    return 0;
}

/* Corps des sous-programmes utilisés par le main()
 * -------------------------------------------------*/

void charger(Diaporamas& pDiaporamas)
{
    InfosDiaporama infosACharger;
    // Diaporama de Pantxika
    infosACharger.id = 1;
    infosACharger.titre = "Diaporama Pantxika";
    infosACharger.vitesseDefilement = 2;
    pDiaporamas.push_back(infosACharger);

     // Diaporama de Thierry
    infosACharger.id = 2;
    infosACharger.titre = "Diaporama Thierry";
    infosACharger.vitesseDefilement = 4;
    pDiaporamas.push_back(infosACharger);

     // Diaporama de Yann
    infosACharger.id = 3;
    infosACharger.titre = "Diaporama Yann";
    infosACharger.vitesseDefilement = 2;
    pDiaporamas.push_back(infosACharger);

     // Diaporama de Manu
    infosACharger.id = 4;
    infosACharger.titre = "Diaporama Manu";
    infosACharger.vitesseDefilement = 1;
    pDiaporamas.push_back(infosACharger);

}

void saisieVerifChoixActionSurImageCourante(char& pChoixAction)
{
    cout << endl << endl;
    while (true)
    {
        cout  << endl ;
        cout << "ACTIONS :" << "  A-vancer" << "  R-eculer" << "  C-hanger de diaporama " << "  V-ider le lecteur "  << "  Q-uitter .......  votre choix ? ";
        cin >> pChoixAction;
        pChoixAction = toupper(pChoixAction);

        if ((pChoixAction == 'A') || (pChoixAction == 'R') || (pChoixAction == 'C') || (pChoixAction == 'V') || (pChoixAction == 'Q'))
        {
            break;
        }
    }
}

void declencherAction(char pChoixAction, const Diaporamas& pDiaporamas, Lecteur& pLecteur)
/* Selon le pChoix fait l'utilisateur, réalise une des actions A)vancer, R)eculer, C)hoisir un autre diaporama, V)ider lecteur, Q)quitter */
{
    unsigned int choixDiaporama;
    switch (pChoixAction)
    {
    case 'A':
        pLecteur.avancer();
        pLecteur.afficher();
        break;
    case 'R':
        pLecteur.reculer();
        pLecteur.afficher();
        break;
    case 'C' :
        cout << "Choisissez un Diaporama " << endl;
        choixDiaporama = saisieVerifChoixDiaporama(pDiaporamas);
        // Changer de diaporama
        if (choixDiaporama == 0)
        {
            pLecteur.changerDiaporama(0);
            // réinitialiser les attributs du lecteur + vider son diaporama
        }
        else
        {
            pLecteur.changerDiaporama(choixDiaporama,
                                      pDiaporamas[choixDiaporama-1].titre,
                                      pDiaporamas[choixDiaporama-1].vitesseDefilement);
        }
        break;
    case 'V' :
        // Le lecteur ne sera associé plus à aucun diaporama
        pLecteur.viderLecteur();
        break;
    default : break;
    }
}

unsigned int saisieVerifChoixDiaporama(const Diaporamas& pDiaporamas)
{
    unsigned int choixSaisi;
    unsigned int choixDiaporama; // valeur retournée

    while (true)
    {
        system("cls");  // effacer l'écran
        cout << endl << endl << "CHANGEMENT DIAPORAMA : " << endl << endl;
        cout << "0 : Pas de diaporama = vider le lecteur " << endl;
        for (unsigned int num = 0; num < pDiaporamas.size(); num++)
        {
            cout << num+1 << ": " << pDiaporamas[num].titre;
            if (num != pDiaporamas.size()-1) { cout << endl; }
        }
        cout << ".......  votre choix ? "; cin >> choixSaisi;
        choixDiaporama = choixSaisi;

        if ((choixDiaporama >= 0)&&(choixDiaporama <= static_cast<unsigned int>(pDiaporamas.size())))
        {
            break;
        }
    }
    return choixDiaporama;
}


