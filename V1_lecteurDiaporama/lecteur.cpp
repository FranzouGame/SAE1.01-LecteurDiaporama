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
Diaporamas Lecteur::getAllDiapos() const
{
    return _allDiapos;
}

Diaporama Lecteur::getDiapoCourant() const
{
    return _diapoCourant;
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
void Lecteur::setAllDiapos(const Diaporamas& vecteurDiapos)
{
    _allDiapos = vecteurDiapos;
}

void Lecteur::setDiapoCourant(const Diaporama& diapoCourant)
{
    this->_diapoCourant = diapoCourant;
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
    cout << "Titre : " << _diapoCourant.getTitre() << endl;
    cout << "Vitesse de défilement : " << _diapoCourant.getVitesseDefilement() << endl;
    cout << "Contenant " << _diapoCourant.getNombreImages() << " images ";
}

void Lecteur::declencherAction(char pChoixAction)
{
    unsigned int choixDiaporama; // Déclaration de la variable choixDiaporama
    switch (pChoixAction)
    {
    case 'A':
        _diapoCourant.avancer();
        this->getDiapoCourant().getLocalisationImages()[getDiapoCourant().getPosImageCourante()].afficher();
        break;
    case 'R':
        _diapoCourant.reculer();
        this->getDiapoCourant().getLocalisationImages()[getDiapoCourant().getPosImageCourante()].afficher();
        break;
    case 'C':
        cout << "Choisissez un Diaporama " << endl;
        choixDiaporama = saisieVerifChoixDiaporama(); // Vous n'avez pas besoin de passer pDiaporamas ici
        // Changer de diaporama
        setNumDiapoCourant(choixDiaporama);
        _diapoCourant = _allDiapos[choixDiaporama];
        _diapoCourant.setPosImageCourante(0);
        break;

    default:
        break;
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
        for (unsigned int num = 1; num < this->getNombreDiapos(); num++)
        {
            cout << num << ": " << this->getAllDiapos()[this->getNumDiapoCourant()].getTitre();
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

void Lecteur::charger(Images& pImages) {
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

void Lecteur::charger(Diaporamas& pDiaporamas)
{
    Image imageACharger;
    ImageDansDiaporama imageDansDiapo;
    Diaporama diaporama;
    Images images;

    // Diaporama par défaut
    diaporama.setTitre("Diaporama par defaut");
    diaporama.setVitesseDefilement(1);

    // Ajout de l'unique image du diaporama par défaut
    imageDansDiapo.setPos(0);
    imageDansDiapo.setRang(1);
    diaporama.setLocalisationImages({imageDansDiapo});

    // Ajout du diaporama dans le tableau de diaporamas
    pDiaporamas.push_back(diaporama);

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
    pDiaporamas.push_back(diaporama);
    diaporama.setLocalisationImages({});

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
    pDiaporamas.push_back(diaporama);
    diaporama.setLocalisationImages({});

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
    pDiaporamas.push_back(diaporama);
    diaporama.setLocalisationImages({});

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
    pDiaporamas.push_back(diaporama);
    diaporama.setLocalisationImages({});

}
