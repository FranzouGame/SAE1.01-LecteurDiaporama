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
    ModeleLecteur* modele = new ModeleLecteur();
    PresentationLecteur* presentation = new PresentationLecteur();
    LecteurVue vueLecteur;
    Lecteur* lecteur = new Lecteur();
    Diaporamas mesDiapos;



    // Association des différents éléments entre eux
    vueLecteur.setPres(presentation);
    presentation->setModele(modele);
    modele->setEtat(ModeleLecteur::Initial);
    presentation->setVue(&vueLecteur);
    modele->setLecteur(lecteur);

    // Connexion des signaux et des slots

    // Modèle -> vue
    QObject::connect(modele, SIGNAL(imageChanged(QString,QString,QString)), presentation, SLOT(transmettreInfosImage(QString,QString,QString)));
    QObject::connect(modele, SIGNAL(diapoChanged(QString)), presentation, SLOT(transmettreTitreDiapo(QString)));
    QObject::connect(modele, SIGNAL(sendDiapoInfos(Diaporamas)), presentation, SLOT(transmettreInfosDiapos(Diaporamas)));
    QObject::connect(modele, SIGNAL(sendImages(Images)), presentation, SLOT(transmettreImages(Images)));

    // Affichage de la fenetre
    vueLecteur.show();

    return a.exec();
}




