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
    PresentationLecteur* presentation = new PresentationLecteur();
    LecteurVue vueLecteur;
    Lecteur* lecteur = new Lecteur();
    Diaporamas mesDiapos;



    // Association des différents éléments entre eux
    vueLecteur.setPres(presentation);
    presentation->setLecteur(lecteur);
    presentation->setVue(&vueLecteur);

    // Connexion des signaux et des slots

    // Affichage de la fenetre
    vueLecteur.show();

    return a.exec();
}




