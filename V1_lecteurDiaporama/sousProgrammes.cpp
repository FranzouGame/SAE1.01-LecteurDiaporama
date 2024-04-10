#include "sousProgrammes.h"
#include <iostream>
#include <vector>
#include "image.h"
using namespace std;





void saisieVerifChoixActionSurImageCourante(char& pChoixAction)
{
    cout << endl << endl;
    while (true)
    {
        cout  << endl ;
        cout << "ACTIONS :" << "  A-vancer" << "  R-eculer" << "  C-hanger de diaporama " << "  Q-uitter .......  votre choix ? ";
        cin >> pChoixAction;
        pChoixAction = toupper(pChoixAction);

        if ((pChoixAction == 'A') || (pChoixAction == 'R') || (pChoixAction == 'C') || (pChoixAction == 'Q'))
        {
            break;
        }
    }
}
unsigned int saisieVerifChoixDiaporama(const Diaporamas& pDiaporamas)
{
    unsigned int choixSaisi;
    int choixDiaporama; // valeur retournée

    while (true)
    {
        system("cls");  // effacer l'écran
         cout << endl << endl << "CHANGEMENT DIAPORAMA : " << endl << endl;
        for (unsigned int num = 1; num < pDiaporamas.size(); num++)
        {
            cout << num << ": " << pDiaporamas[num].titre;
            if (num != pDiaporamas.size()-1) { cout << endl; }
        }
        cout << ".......  votre choix ? "; cin >> choixSaisi;
        choixDiaporama = choixSaisi;

        if ((choixDiaporama >= 1)&&(choixDiaporama < static_cast<unsigned int>(pDiaporamas.size())))
        {
            break;
        }
    }
    return choixDiaporama;
}



void charger(Diaporamas& pDiaporamas)
{
    Image imageACharger;
    ImageDansDiaporama imageDansDiapo;
    Diaporama diaporama;

    // Diaporama par défaut
    diaporama.titre = "Diaporama par defaut";
    diaporama.vitesseDefilement = 1;

    // L'unique image du diaporama par défaut
    imageDansDiapo.pos = 0;
    imageDansDiapo.rang = 1;
    diaporama.localisationImages.push_back(imageDansDiapo);
    // ajout du diaporama dans le tableau de diaporamas
    pDiaporamas.push_back(diaporama);
    // vider la variable temporaire avant de la remplir avec le diaporama suivant
    diaporama.localisationImages.clear();

    // Diaporama de Pantxika
    diaporama.titre = "Diaporama Pantxika";
    diaporama.vitesseDefilement = 2;

    // Les images du diaporama de Pantxika
    imageDansDiapo.pos = 4;
    imageDansDiapo.rang = 3;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 1;
    imageDansDiapo.rang = 2;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 2;
    imageDansDiapo.rang = 4;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 3;
    imageDansDiapo.rang = 1;
    diaporama.localisationImages.push_back(imageDansDiapo);
    // ajout du diaporama dans le tableau de diaporamas
    pDiaporamas.push_back(diaporama);
    // vider la variable temporaire avant de la remplir avec le diaporama suivant
    diaporama.localisationImages.clear();

    // Diaporama de Thierry
    diaporama.titre = "Diaporama Thierry";
    diaporama.vitesseDefilement = 4;

    // Les images du diaporama de Thierry
    imageDansDiapo.pos = 4;
    imageDansDiapo.rang = 1;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 1;
    imageDansDiapo.rang = 2;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 2;
    imageDansDiapo.rang = 3;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 3;
    imageDansDiapo.rang = 4;
    diaporama.localisationImages.push_back(imageDansDiapo);
    // ajout du diaporama dans le tableau de diaporamas
    pDiaporamas.push_back(diaporama);
    // vider la variable temporaire avant de la remplir avec le diaporama suivant
    diaporama.localisationImages.clear();

    // Diaporama de Yann
    diaporama.titre = "Diaporama Yann";
    diaporama.vitesseDefilement = 3;

    // Les images du diaporama de Yann
    imageDansDiapo.pos = 4;
    imageDansDiapo.rang = 2;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 1;
    imageDansDiapo.rang = 1;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 2;
    imageDansDiapo.rang = 4;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 3;
    imageDansDiapo.rang = 3;
    diaporama.localisationImages.push_back(imageDansDiapo);
    // ajout du diaporama dans le tableau de diaporamas
    pDiaporamas.push_back(diaporama);
    // vider la variable temporaire avant de la remplir avec le diaporama suivant
    diaporama.localisationImages.clear();

    // Diaporama de Manu
    diaporama.titre = "Diaporama Manu";
    diaporama.vitesseDefilement = 1;

    // Les images du diaporama de Yann
    imageDansDiapo.pos = 4;
    imageDansDiapo.rang = 4;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 1;
    imageDansDiapo.rang = 3;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 2;
    imageDansDiapo.rang = 2;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 3;
    imageDansDiapo.rang = 1;
    diaporama.localisationImages.push_back(imageDansDiapo);
    // ajout du diaporama dans le tableau de diaporamas
    pDiaporamas.push_back(diaporama);
    // vider la variable temporaire avant de la remplir avec le diaporama suivant
    diaporama.localisationImages.clear();

}

/* Corps des sous-programmes utilisés par la fonction main()
 * ------------------------------------------------------- */



unsigned int nbImages(const Diaporama& pDiaporama)
{
    return pDiaporama.localisationImages.size();
}


void triCroissantRang (Diaporama &pDiaporama)
{   // par la méthode du triBulle
    unsigned int taille = pDiaporama.localisationImages.size();
    ImageDansDiaporama imageDansDiapo;
    for (unsigned int ici = taille-1; ici >=1 ; ici--)
    {
        // faire monter la bulle ici = déplacer l'élément de rang le plus grand en position ici
        // par échanges successifs
        for (unsigned int i = 0; i < ici; i++)
        {
            if (pDiaporama.localisationImages[i].rang > pDiaporama.localisationImages[i+1].rang)
            {
                // echanger les 2 éléments
                imageDansDiapo = pDiaporama.localisationImages[i];
                pDiaporama.localisationImages[i] = pDiaporama.localisationImages[i+1];
                pDiaporama.localisationImages[i+1] = imageDansDiapo;
            }
        }
    }
}

