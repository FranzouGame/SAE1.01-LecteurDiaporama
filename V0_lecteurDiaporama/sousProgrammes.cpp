#include "sousProgrammes.h"
#include <iostream>
#include <vector>
#include "image.h"
#include "typeDiaporama.h"
using namespace std;












void charger (Images& pImages) {
    Image imageACharger;
    imageACharger = creerImage ("objet", "", "C:\\cartesDisney\\Disney_tapis.gif");
    pImages.push_back(imageACharger);
    imageACharger = creerImage ("personnage", "Blanche Neige", "C:\\cartesDisney\\Disney_4.gif");
    pImages.push_back(imageACharger);
    imageACharger = creerImage ("personnage", "Alice", "C:\\cartesDisney\\Disney_2.gif");
    pImages.push_back(imageACharger);
    imageACharger = creerImage ("animal", "Mickey", "C:\\cartesDisney\\Disney_19.gif");
    pImages.push_back(imageACharger);
    imageACharger = creerImage ("personnage", "Pinnochio", "C:\\cartesDisney\\Disney_29.gif");
    pImages.push_back(imageACharger);
    imageACharger = creerImage ("objet", "chateau", "C:\\cartesDisney\\Disney_0.gif");
    pImages.push_back(imageACharger);
    imageACharger = creerImage ("personnage", "Minnie", "C:\\cartesDisney\\Disney_14.gif");
    pImages.push_back(imageACharger);
    imageACharger = creerImage ("animal", "Bambi", "C:\\cartesDisney\\Disney_3.gif");
    pImages.push_back(imageACharger);
}

/* Corps des sous-programmes utilisés par la fonction main()
 * ------------------------------------------------------- */







