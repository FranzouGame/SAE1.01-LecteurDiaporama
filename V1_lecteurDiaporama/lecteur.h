#ifndef LECTEUR_H
#define LECTEUR_H

#include "diaporama.h"
class Diaporama;
class Lecteur
{

private:
    unsigned int _diaporamaCourant;
public:
    Lecteur lecteur();
    void charger (Diaporama& pDiaporamas);

    void declencherAction(char pChoixAction, const Diaporamas& pDiaporamas, unsigned int& pDiaporamaCourant,
                          unsigned int& pImageCourante, const Image& pImages);
    /* Selon le pChoix fait l'utilisateur, réalise une des actions A)vancer, R)eculer, C)hoisir un autre diaporama, Q)quitter */
    void avancer(const Diaporama& pDiaporama, unsigned int& pPosImageCourante);
    void reculer(const Diaporama& pDiaporama, unsigned int& pPosImageCourante);
    Diaporama getDiaporamaCourant(const Diaporamas& pDiaporamas, unsigned int pDiaporamaCourant);
    void setDiaporamaCourant(const Diaporama pDiaporama, unsigned int pDiaporamaCourant);

    // Test
    unsigned int getDiapoCourant() const;
};
typedef vector<Diaporama> Diaporamas;
#endif // LECTEUR_H
