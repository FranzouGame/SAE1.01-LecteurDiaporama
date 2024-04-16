#include "lecteur.h"
#include "diaporama.h"
#include "image.h"

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

void Lecteur::charger(vector<Image>& pImages) {
    Image imageACharger("objet", "", "C:\\cartesDisney\\Disney_tapis.gif");
    pImages.push_back(imageACharger);

    imageACharger = Image("personnage", "Blanche Neige", "C:\\cartesDisney\\Disney_4.gif");
    pImages.push_back(imageACharger);

    imageACharger = Image("personnage", "Alice", "C:\\cartesDisney\\Disney_2.gif");
    pImages.push_back(imageACharger);

    imageACharger = Image("animal", "Mickey", "C:\\cartesDisney\\Disney_19.gif");
    pImages.push_back(imageACharger);

    imageACharger = Image("personnage", "Pinnochio", "C:\\cartesDisney\\Disney_29.gif");
    pImages.push_back(imageACharger);

    imageACharger = Image("objet", "chateau", "C:\\cartesDisney\\Disney_0.gif");
    pImages.push_back(imageACharger);

    imageACharger = Image("personnage", "Minnie", "C:\\cartesDisney\\Disney_14.gif");
    pImages.push_back(imageACharger);

    imageACharger = Image("animal", "Bambi", "C:\\cartesDisney\\Disney_3.gif");
    pImages.push_back(imageACharger);
}

void Lecteur::chargerDiapos()
{
    Image imageDansDiapo;
    Diaporama diaporama;

    // Diaporama par défaut
    diaporama.setTitre("Diaporama par defaut");
    diaporama.setVitesseDefilement(1);

    // Ajout de l'unique image du diaporama par défaut
    imageDansDiapo.setPos(0);
    imageDansDiapo.setRang(1);
    diaporama.setLocalisationImages({imageDansDiapo});

    // Ajout du diaporama dans le tableau de diaporamas
    _allDiapos.push_back(diaporama);
    setNombreDiapos(getNombreDiapos() + 1);

    // Diaporama de Pantxika
    diaporama.setTitre("Diaporama Pantxika");
    diaporama.setVitesseDefilement(2);

    // Les images du diaporama de Pantxika
    imageDansDiapo.setPos(4);
    imageDansDiapo.setRang(3);
    diaporama.setLocalisationImages({imageDansDiapo});

    imageDansDiapo.setPos(1);
    imageDansDiapo.setRang(2);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);

    imageDansDiapo.setPos(2);
    imageDansDiapo.setRang(4);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);

    imageDansDiapo.setPos(3);
    imageDansDiapo.setRang(1);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);

    // Ajout du diaporama dans le tableau de diaporamas
    _allDiapos.push_back(diaporama);
    setNombreDiapos(getNombreDiapos() + 1);

    // Diaporama de Thierry
    diaporama.setTitre("Diaporama Thierry");
    diaporama.setVitesseDefilement(4);

    // Les images du diaporama de Thierry
    imageDansDiapo.setPos(4);
    imageDansDiapo.setRang(1);
    diaporama.setLocalisationImages({imageDansDiapo});

    imageDansDiapo.setPos(1);
    imageDansDiapo.setRang(2);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);

    imageDansDiapo.setPos(2);
    imageDansDiapo.setRang(3);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);

    imageDansDiapo.setPos(3);
    imageDansDiapo.setRang(4);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);

    // Ajout du diaporama dans le tableau de diaporamas
    _allDiapos.push_back(diaporama);
    setNombreDiapos(getNombreDiapos() + 1);

    // Diaporama de Yann
    diaporama.setTitre("Diaporama Yann");
    diaporama.setVitesseDefilement(3);

    // Les images du diaporama de Yann
    imageDansDiapo.setPos(4);
    imageDansDiapo.setRang(2);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);

    imageDansDiapo.setPos(1);
    imageDansDiapo.setRang(1);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);

    imageDansDiapo.setPos(2);
    imageDansDiapo.setRang(4);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);

    imageDansDiapo.setPos(3);
    imageDansDiapo.setRang(3);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);

    // Ajout du diaporama dans le tableau de diaporamas
    _allDiapos.push_back(diaporama);
    setNombreDiapos(getNombreDiapos() + 1);

    // Diaporama de Manu
    // Diaporama de Manu
    diaporama.setTitre("Diaporama Manu");
    diaporama.setVitesseDefilement(1);

    // Les images du diaporama de Manu
    imageDansDiapo.setPos(4);
    imageDansDiapo.setRang(4);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);

    imageDansDiapo.setPos(1);
    imageDansDiapo.setRang(3);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);

    imageDansDiapo.setPos(2);
    imageDansDiapo.setRang(2);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);

    imageDansDiapo.setPos(3);
    imageDansDiapo.setRang(1);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);

    // Ajout du diaporama dans le tableau de diaporamas
    _allDiapos.push_back(diaporama);
    setNombreDiapos(getNombreDiapos() + 1);

}

