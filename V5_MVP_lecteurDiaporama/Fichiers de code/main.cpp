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

    // Présentation -> Modele
    QObject::connect(presentation, SIGNAL(faireAvancer()), modele, SLOT(demandeAvancement()));
    QObject::connect(presentation, SIGNAL(faireReculer()), modele, SLOT(demandeReculement()));
    QObject::connect(presentation, SIGNAL(faireChangerVitesse(unsigned int)), modele, SLOT(receptionDemandeChangementVitesse(unsigned int)));
    QObject::connect(presentation, SIGNAL(faireChangerDiapo(InfosDiaporama)), modele, SLOT(receptionDemandeChangementDiaporama(InfosDiaporama)));

    // Présentation -> vue
    QObject::connect(presentation, SIGNAL(faireOuvrirAPropos()), &vueLecteur, SLOT(afficherInformations()));

    // Modèle -> vue
    QObject::connect(modele, SIGNAL(imageChanged(QString,QString,QString)), &vueLecteur, SLOT(updateImageInfo(QString,QString,QString)));
    QObject::connect(modele, SIGNAL(diapoChanged(QString)), &vueLecteur, SLOT(updateDiapoTitle(QString)));
    QObject::connect(modele, SIGNAL(sendDiapoInfos(Diaporamas)), &vueLecteur, SLOT(receptionDiapos(Diaporamas)));

    // Affichage de la fenetre
    vueLecteur.show();

    return a.exec();
}




