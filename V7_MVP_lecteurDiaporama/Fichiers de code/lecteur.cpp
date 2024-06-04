#include "lecteur.h"
#include "qdebug.h"
#include "qlogging.h"

Lecteur::Lecteur() : idDiaporama(2), diaporama(nullptr)
{
    // posImageCourante indéfini
}

Lecteur::~Lecteur()
{
    if (getDiaporama() != nullptr)
    {
        viderLecteur();
        delete diaporama;
    }
}

unsigned int Lecteur::getIdDiaporama() const
{
    return idDiaporama; // valeur >= 0
}

Diaporama* Lecteur::getDiaporama()
{
    return diaporama;   // peut être nullptr
}

unsigned int Lecteur::getPosImageCourante() const
{
    if (lecteurVide() ||
        (!lecteurVide() && nbImages() == 0 ))
    {
        throw string ("pas d'image courante : lecteur vide ou diaporama vide");
    }
    return posImageCourante;
}

bool Lecteur::lecteurVide() const
{
    return(diaporama == nullptr);
}

ImageDansDiaporama *Lecteur::getImageCourante() const
{
    if (lecteurVide() ||
        (!lecteurVide() && nbImages() == 0 ))
    {
        return nullptr;
    }

    return diaporama->getImages().at(getPosImageCourante());
}


unsigned int Lecteur::nbImages() const
{
    if (lecteurVide())
    {
        throw string ("lecteur vide");
    }
    return diaporama->nbImages();
}

void Lecteur::afficher()
{
    /* affichen selon le cas :
     * - lecteur vide
     * ou bien
     * - le numéro de diaporama affiché
     * - et l'image courante ou bien 'diaporama vide' */

    string info;
    if (lecteurVide())
    {
        info = "Lecteur vide = pas de diaporama charge ";
        cout << info << endl;
    }

    else
    {
        info = "Diaporama num. " + std::to_string(getIdDiaporama()) + " - "  + getDiaporama()->getTitre() + "\n";

        // Afficher l'image courante du diaporama chargé
        if (nbImages() == 0)
        {
            info.append("Diaporama vide \n");
            cout << info;
        }
        else
        {
            info.append(std::to_string(diaporama->getImages()[posImageCourante]->getRangDansDiaporama()));
            info.append(" sur ");
            info.append((std::to_string(diaporama->getImages().size())));
            info.append(" / ");
            cout << info;
            diaporama->getImages()[posImageCourante]->afficher();
        }
    }
}

void Lecteur::setIdDiaporama(unsigned int pIdDiaporama)
{
    idDiaporama = pIdDiaporama;
}

void Lecteur::setDiaporama(Diaporama* pDiaporama)
{
    diaporama = pDiaporama;
}

void Lecteur::setPosImageCourante(unsigned int pPosImageCourante)
{
    posImageCourante = pPosImageCourante;
}

void Lecteur::changerDiaporama(unsigned int pId, string pTitre, float pVitesse)
{
    /* Chargement des informations et images images associées au diaporama courant
       Dans une version ultérieure, le seul paramètre sera le numéro ou identifiant du diaporama choisi,
       les autres informations proviendront de la Base de Données */

    if (pId != 0)
    {

        // Si le diaporama n'est pas vide, le vider
        if (!lecteurVide())
        {
            if (diaporama != nullptr)
            {

                diaporama->vider();
            }
            else
            {
                // Créer un nouveau diaporama s'il n'existe pas
                diaporama = new Diaporama();

            }
        }
        else
        {
            // Créer un nouveau diaporama si le lecteur est vide
            diaporama = new Diaporama();
        }

        // Assigner les valeurs à l'objet diaporama
        setIdDiaporama(pId);
        diaporama->setId(pId);
        diaporama->setTitre(pTitre);
        diaporama->setVitesseDefilement(pVitesse);

        // Charger les informations du diaporama
        chargerDiaporamaCourant();
    }
    else
    {
        // Vider le lecteur s'il est déjà initialisé
        if (!lecteurVide())
        {
            viderLecteur();
        }
    }
}

void Lecteur::avancer()
{
    if (!lecteurVide())
    {
        if (getPosImageCourante() == nbImages()- 1)
        {
            setPosImageCourante(0);
        }
        else {
            setPosImageCourante(getPosImageCourante() + 1);
        }
    }
}

void Lecteur::reculer()
{
    if (!lecteurVide())
    {
        if (getPosImageCourante() == 0)
        {
            setPosImageCourante(nbImages()- 1);
        }
        else {
            setPosImageCourante(getPosImageCourante() - 1);
        }
    }
}

void Lecteur::chargerDiaporamaCourant()
{
    /* Chargement des images associées au diaporama courant */
    diaporama->charger();
    if (nbImages() != 0)
    { setPosImageCourante(0) ;}
}

void Lecteur::viderLecteur()
{
    // supprime les images du diaporama,  et réinitialise les attributs du lecteur
    if (!lecteurVide())
    {
        diaporama->vider();
        setDiaporama(nullptr);
        setIdDiaporama(0);
    }
}





