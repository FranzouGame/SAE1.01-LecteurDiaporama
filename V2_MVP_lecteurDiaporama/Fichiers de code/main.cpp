    /*** Inclusions requises ***/
// Fichiers
#include "lecteurvue.h"
#include "modelelecteur.h"
#include "presentationlecteur.h"

// Bibliothèques
#include <QApplication>

int main(int argc, char *argv[])
{
    // Gestion des fenêtre
    QApplication a(argc, argv);

    // Création des variables
    LecteurVue vueLecteur;
    ModeleLecteur* modele = new ModeleLecteur();
    PresentationLecteur* presentation = new PresentationLecteur();

    // Association des différents éléments entre eux
    vueLecteur.setPres(presentation);
    presentation->setModele(modele);
    presentation->setVue(&vueLecteur);

    // Affichage de la fenetre
    vueLecteur.show();
    return a.exec();
}
