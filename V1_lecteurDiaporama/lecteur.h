#ifndef LECTEUR_H
#define LECTEUR_H

#include "diaporama.h"

class lecteur
{

private:

public:
    lecteur();
    void charger (Diaporama& pDiaporamas);
};
typedef vector<Diaporama> Diaporamas;
#endif // LECTEUR_H
