#ifndef SOUS_PROGRAMMES_POUR_VERSIONS_INITIALES_H
#define SOUS_PROGRAMMES_POUR_VERSIONS_INITIALES_H
#include <iostream>
#include <vector>
#include "image.h"
#include "diaporama.h"
#include "imagedansdiaporama.h"
#include "image.h"
using namespace std;


/* Sous-programmes provisoires pour versions Non encore graphiques
 * -------------------------------------------------------------- */

void saisieVerifChoixActionSurImageCourante(char& pChoixAction);
// Saisie du choix d'action de l'utilisateur vis-à-vis de l'image et diaporama courants

unsigned int saisieVerifChoixDiaporama(const Diaporamas& pDiaporamas);
// Retourne un numéro de diaporama choisi par l'utilisateur (dans la liste des diaporamas existants)

void declencherAction(char pChoixAction, const Diaporamas& pDiaporamas, unsigned int& pDiaporamaCourant,
                      unsigned int& pImageCourante, const Image& pImages);
/* Selon le pChoix fait l'utilisateur, réalise une des actions A)vancer, R)eculer, C)hoisir un autre diaporama, Q)quitter */


/* Sous-programmes provisoires pour versions antérieures à l'implantation de la BD
----------------------------------------------------------------------------------*/



/* Chargement du tableau des diaporamas avec des diaporamas préalablement construits 'en dur'.
   Dans une version ultérieure, le diaporama courant affiché par le Lecteur de diaporamas sera chargé à partir
   d'une base de données.
*/


/* Déclarations des sous-programmes utilisés par le lecteur de diaporamas
 * ---------------------------------------------------------------------- */




/* Tri du diaporama pDiaporama par ordre croissant de *rang* des ses images
   A garder aussi lors de l'implémentation de la BD */

#endif // SOUS_PROGRAMMES_POUR_VERSIONS_INITIALES_H
