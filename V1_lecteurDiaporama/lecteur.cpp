#include "lecteur.h"
#include "diaporama.h"
#include "image.h"
#include <limits>

/***********************
 *      METHODES
 **********************/


/*** Constructeurs ***/
Lecteur::Lecteur():
    _numDiapoCourant(0),
    _nombreDiapos(0)
{}

Lecteur::Lecteur(vector<Diaporama> diapos, unsigned int numDiapoCourant, unsigned int nbDiapos) :
    _allDiapos(diapos),
    _numDiapoCourant(numDiapoCourant),
    _nombreDiapos(nbDiapos)
{}


/*** Getters ***/
vector<Diaporama> Lecteur::getAllDiapos() const
{
    return _allDiapos;
}

Diaporama Lecteur::getDiapoCourant() const
{
    return _allDiapos[getNumDiapoCourant()];
}

unsigned int Lecteur::getNumDiapoCourant() const
{
    return _numDiapoCourant;
}

unsigned int Lecteur::getNombreDiapos() const
{
    return _nombreDiapos;
}


/*** Setters ***/
void Lecteur::setAllDiapos(const vector<Diaporama>& vecteurDiapos)
{
    _allDiapos = vecteurDiapos;
}

void Lecteur::setNumDiapoCourant(unsigned int numDiapoCourant)
{
    _numDiapoCourant = numDiapoCourant;
}

void Lecteur::setNombreDiapos(unsigned int nbDiapos)
{
    _nombreDiapos = nbDiapos;
}


/*** Autres méthodes ***/
void Lecteur::afficherDiapoCourant() {
    cout << "Diaporama courant :\n";
    cout << "Titre : " << getDiapoCourant().getTitre() << endl;
    cout << "Vitesse de défilement : " << getDiapoCourant().getVitesseDefilement() << endl;
    cout << "Contenant " << getDiapoCourant().getNombreImages() << " images ";
}

void Lecteur::declencherAction(char pChoixAction)
{
    unsigned int choixDiaporama; // Déclaration de la variable choixDiaporama
    switch (pChoixAction)
    {
    case 'A':
        getDiapoCourant().avancer();
        this->getDiapoCourant().getLocalisationImages()[getDiapoCourant().getPosImageCourante()].afficher();
        break;
    case 'R':
        getDiapoCourant().reculer();
        this->getDiapoCourant().getLocalisationImages()[getDiapoCourant().getPosImageCourante()].afficher();
        break;
    case 'C':
        cout << "Choisissez un Diaporama " << endl;
        choixDiaporama = saisieVerifChoixDiaporama(); // Vous n'avez pas besoin de passer pDiaporamas ici
        // Changer de diaporama
        setNumDiapoCourant(choixDiaporama);
        _allDiapos[getNumDiapoCourant()].setPosImageCourante(0);
        break;

    default:
        break;
    }
}

char Lecteur::saisieVerifChoixActionSurImageCourante()
{
    char pChoixAction;

    cout << endl << endl;
    while (true)
    {
        cout << endl << endl;
        cout << "ACTIONS : A-vancer  R-eculer  C-hanger de diaporama  Q-uitter .......  votre choix ? ";
        cin >> pChoixAction;
        pChoixAction = toupper(pChoixAction);

        // Vérifier si l'entrée a réussi
        if (cin.fail()) {
            // Réinitialiser l'état d'erreur de cin et vider le tampon d'entrée
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Saisie invalide. Veuillez saisir une action valide." << endl;
            continue; // Reprendre la boucle pour demander une nouvelle saisie
        }

        if ((pChoixAction == 'A') || (pChoixAction == 'R') || (pChoixAction == 'C') || (pChoixAction == 'Q'))
        {
            declencherAction(pChoixAction);
            break;
        }
        else
        {
            cout << "Action non reconnue. Veuillez saisir une action valide." << endl;
        }
    }

    return pChoixAction;
}

unsigned int Lecteur::saisieVerifChoixDiaporama()
{
    unsigned int choixSaisi;
    int choixDiaporama; // valeur retournée

    while (true)
    {
        system("cls");  // effacer l'écran
        cout << endl << endl << "CHANGEMENT DIAPORAMA : " << endl << endl;
        for (unsigned int num = 1; num < this->getNombreDiapos(); num++)
        {
            cout << num << ": " << this->getDiapoCourant().getTitre();
            if (num != this->getNombreDiapos() - 1)
            {
                cout << endl;
            }
        }
        cout << ".......  votre choix ? "; cin >> choixSaisi;
        choixDiaporama = choixSaisi;

        if ((choixDiaporama >= 1)&&(choixDiaporama < static_cast<unsigned int>(this->getNombreDiapos())))
        {
            break;
        }
    }
    return choixDiaporama;
}

void Lecteur::charger(Images& images) {
    Image imageACharger("objet", "", "C:\\cartesDisney\\Disney_tapis.gif");
    images.push_back(imageACharger);

    imageACharger = Image("personnage", "Blanche Neige", "C:\\cartesDisney\\Disney_4.gif");
    images.push_back(imageACharger);

    imageACharger = Image("personnage", "Alice", "C:\\cartesDisney\\Disney_2.gif");
    images.push_back(imageACharger);

    imageACharger = Image("animal", "Mickey", "C:\\cartesDisney\\Disney_19.gif");
    images.push_back(imageACharger);

    imageACharger = Image("personnage", "Pinnochio", "C:\\cartesDisney\\Disney_29.gif");
    images.push_back(imageACharger);

    imageACharger = Image("objet", "chateau", "C:\\cartesDisney\\Disney_0.gif");
    images.push_back(imageACharger);

    imageACharger = Image("personnage", "Minnie", "C:\\cartesDisney\\Disney_14.gif");
    images.push_back(imageACharger);

    imageACharger = Image("animal", "Bambi", "C:\\cartesDisney\\Disney_3.gif");
    images.push_back(imageACharger);
}

void Lecteur::chargerDiapos(Images& images)
{
    Image image;
    imageDansDiaporama imageDansDiapo;

    // Diaporama par défaut
    Diaporama diapoDefaut;
    diapoDefaut.setTitre("Diaporama par defaut");
    diapoDefaut.setVitesseDefilement(1);

    // Ajout de l'unique image du diaporama par défaut
    imageDansDiapo = imageDansDiaporama(images,0,1);
    diapoDefaut.addImage(imageDansDiapo);

    // Ajout du diaporama dans le tableau de diaporamas
    _allDiapos.push_back(diapoDefaut);
    setNombreDiapos(getNombreDiapos() + 1);

    // Diaporama de Pantxika
    Diaporama diapoPantxika;
    diapoPantxika.setTitre("Diaporama Pantxika");
    diapoPantxika.setVitesseDefilement(2);

    // Les images du diaporama de Pantxika
    imageDansDiapo = imageDansDiaporama(images, 4, 3);
    diapoPantxika.addImage(imageDansDiapo);

    imageDansDiapo = imageDansDiaporama(images,1 ,2);
    diapoPantxika.addImage(imageDansDiapo);

    imageDansDiapo = imageDansDiaporama(images,2, 4);
    diapoPantxika.addImage(imageDansDiapo);

    imageDansDiapo = imageDansDiaporama(images,3 ,1);
    diapoPantxika.addImage(imageDansDiapo);

    // Ajout du diaporama dans le tableau de diaporamas
    _allDiapos.push_back(diapoPantxika);
    setNombreDiapos(getNombreDiapos() + 1);


    // Diaporama de Thierry
    Diaporama diapoThierry;
    diapoThierry.setTitre("Diaporama Thierry");
    diapoThierry.setVitesseDefilement(4);

    // Les images du diaporama de Thierry
    imageDansDiapo = imageDansDiaporama(images,4 ,1);
    diapoThierry.addImage(imageDansDiapo);

    imageDansDiapo = imageDansDiaporama(images,1 ,2);
    diapoThierry.addImage(imageDansDiapo);

   imageDansDiapo = imageDansDiaporama(images,2 ,3);
    diapoThierry.addImage(imageDansDiapo);

    imageDansDiapo = imageDansDiaporama(images,3 ,4);
    diapoThierry.addImage(imageDansDiapo);

    // Ajout du diaporama dans le tableau de diaporamas
    _allDiapos.push_back(diapoThierry);
    setNombreDiapos(getNombreDiapos() + 1);

    // Diaporama de Yann
    Diaporama DiapoYann;
    DiapoYann.setTitre("Diaporama Yann");
    DiapoYann.setVitesseDefilement(3);

    // Les images du diaporama de Yann
    imageDansDiapo = imageDansDiaporama(images,4 ,2);
    DiapoYann.addImage(imageDansDiapo);

    imageDansDiapo = imageDansDiaporama(images,1 ,1);
    DiapoYann.addImage(imageDansDiapo);

    imageDansDiapo = imageDansDiaporama(images,2 ,4);
    DiapoYann.addImage(imageDansDiapo);

    imageDansDiapo = imageDansDiaporama(images,3 ,3);
    DiapoYann.addImage(imageDansDiapo);

    // Ajout du diaporama dans le tableau de diaporamas
    _allDiapos.push_back(DiapoYann);
    setNombreDiapos(getNombreDiapos() + 1);


    // Diaporama de Manu
    Diaporama DiapoManu;
    DiapoManu.setTitre("Diaporama Manu");
    DiapoManu.setVitesseDefilement(1);

    // Les images du diaporama de Manu
    imageDansDiapo = imageDansDiaporama(images,4 ,4);
    DiapoManu.addImage(imageDansDiapo);

    imageDansDiapo = imageDansDiaporama(images,1 ,3);
    DiapoManu.addImage(imageDansDiapo);

    imageDansDiapo = imageDansDiaporama(images,2 ,2);
    DiapoManu.addImage(imageDansDiapo);

    imageDansDiapo = imageDansDiaporama(images,3 ,1);
    DiapoManu.addImage(imageDansDiapo);

    // Ajout du diaporama dans le tableau de diaporamas
    _allDiapos.push_back(DiapoManu);
    setNombreDiapos(getNombreDiapos() + 1);

}

