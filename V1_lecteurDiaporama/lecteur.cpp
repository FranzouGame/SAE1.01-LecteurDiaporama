#include "lecteur.h"
#include "diaporama.h"


void Lecteur::avancer(const Diaporama& pDiaporama, unsigned int& pPosImageCourante)
// avance à l'image suivante de l'image courante. Revient à l'image de rang 1 si terminé
{
    if (pPosImageCourante == pDiaporama.getPosCourante() - 1)
    {
        pPosImageCourante = pDiaporama.getPosCourante();
    }
    else {
        pPosImageCourante = pPosImageCourante + 1;
    }
}
void Lecteur::reculer(const Diaporama& pDiaporama, unsigned int& pPosImageCourante)
{
    if (pPosImageCourante == 0)
    {
        pPosImageCourante = pDiaporama.getPosCourante() - 1;
    }
    else {
        pPosImageCourante = pPosImageCourante - 1;
    }
}

unsigned int Lecteur::getDiapoCourant() const
{
    return _diaporamaCourant;
}

void Lecteur::declencherAction(char pChoixAction, const Diaporamas& pDiaporamas, unsigned int& pDiaporamaCourant,
                                    unsigned int& pImageCourante, const Image& pImages)
/* Selon le pChoix fait l'utilisateur, réalise une des actions A)vancer, R)eculer, C)hoisir un autre diaporama, Q)quitter */
{
    unsigned int position;
    unsigned int choixDiaporama;
    switch (pChoixAction)
    {
    case 'A':
        avancer(pDiaporamas[pDiaporamaCourant].getDiaporama(), pImageCourante);
        position = pDiaporamas[pDiaporamaCourant].getPosCourante();
        afficherImageCouranteDansDiaporamaCourant (pDiaporamas[pDiaporamaCourant].getDiaporama(), pDiaporamas[pDiaporamaCourant].getImageCourante(), pDiaporamas[pDiaporamaCourant].getDiaporama().getImageCourante());
        break;
    case 'R':
        reculer(pDiaporamas[pDiaporamaCourant].getDiaporama(), pImageCourante);
        position = pDiaporamas[pDiaporamaCourant].getPosCourante();
        afficherImageCouranteDansDiaporamaCourant (pDiaporamas[pDiaporamaCourant].getDiaporama(), pDiaporamas.Image::getImage(), pDiaporama.getDiaporama().getLocalisationImages()[position]);
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
