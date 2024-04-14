#include "lecteur.h"
#include "diaporama.h"


/***********************
 *      METHODES
 **********************/


/*** Constructeurs ***/
Lecteur::Lecteur()
    : _numDiapoCourant(0) {}

Lecteur::Lecteur(Diaporama diapoCourant, unsigned int numDiapoCourant) :
     _diapoCourant(diapoCourant),
    _numDiapoCourant(numDiapoCourant) {}


/*** Getters ***/
Diaporama Lecteur::getDiapoCourant() const
{
    return _diapoCourant;
}

unsigned int Lecteur::getNumDiapoCourant() const
{
    return _numDiapoCourant;
}


/*** Setters ***/
void Lecteur::setDiapoCourant(const Diaporama& diapoCourant)
{
    this->_diapoCourant = diapoCourant;
}

void Lecteur::setNumDiapoCourant(unsigned int numDiapoCourant)
{
    _numDiapoCourant = numDiapoCourant;
}



/*** Autres méthodes ***/
void Lecteur::afficherDiapoCourant() {
    cout << "Diaporama courant :\n";
    cout << "Titre : " << _diapoCourant.getTitre() << endl;
    cout << "Vitesse de défilement : " << _diapoCourant.getVitesseDefilement() << endl;
    cout << "Contenant " << _diapoCourant.getNombreImages() << " images ";
}


void Lecteur::declencherAction(char pChoixAction)
/* Selon le pChoix fait l'utilisateur, réalise une des actions A)vancer, R)eculer, C)hoisir un autre diaporama, Q)quitter */
{
    switch (pChoixAction)
    {
    case 'A':
        _allDiapos[getNumDiapoCourant()].avancer();
        position = pDiaporamas[pDiaporamaCourant].localisationImages[pImageCourante].pos;
        afficherImageCouranteDansDiaporamaCourant (pDiaporamas[pDiaporamaCourant], pImageCourante, pImages[position]);
        break;
    case 'R':
        _allDiapos[getNumDiapoCourant()].reculer();
        position = pDiaporamas[pDiaporamaCourant].localisationImages[pImageCourante].pos;
        afficherImageCouranteDansDiaporamaCourant (pDiaporamas[pDiaporamaCourant], pImageCourante, pImages[position]);
        break;
    case 'C' :
        cout << "Choisissez un Diaporama " << endl;
        choixDiaporama = saisieVerifChoixDiaporama(pDiaporamas);
        // Changer de diaporama
        pDiaporamaCourant = choixDiaporama;
        pImageCourante = 0;
        break;

    default : break;
    }
}

void Lecteur::saisieVerifChoixActionSurImageCourante(char& pChoixAction)
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
            declencherAction(pChoixAction);
            break;
        }
    }
}
unsigned int Lecteur::saisieVerifChoixDiaporama()
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

void charger (Images& pImages) {
    Image imageACharger("objet", "", "C:\\cartesDisney\\Disney_tapis.gif");
    pImages.push_back(imageACharger);
    Image imageACharger("personnage", "Blanche Neige", "C:\\cartesDisney\\Disney_4.gif");
    pImages.push_back(imageACharger);
    Image imageACharger("personnage", "Alice", "C:\\cartesDisney\\Disney_2.gif");
    pImages.push_back(imageACharger);
    Image imageACharger("animal", "Mickey", "C:\\cartesDisney\\Disney_19.gif");
    pImages.push_back(imageACharger);
    Image imageACharger("personnage", "Pinnochio", "C:\\cartesDisney\\Disney_29.gif");
    pImages.push_back(imageACharger);
    Image imageACharger("objet", "chateau", "C:\\cartesDisney\\Disney_0.gif");
    pImages.push_back(imageACharger);
    Image imageACharger("personnage", "Minnie", "C:\\cartesDisney\\Disney_14.gif");
    pImages.push_back(imageACharger);
    Image imageACharger("animal", "Bambi", "C:\\cartesDisney\\Disney_3.gif");
    pImages.push_back(imageACharger);
}
