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

    // Association des différents éléments entre eux
    vueLecteur.setPres(presentation);
    presentation->setModele(modele);
    modele->setEtat(ModeleLecteur::Initial);
    presentation->setVue(&vueLecteur);
    modele->setLecteur(lecteur);

    // Choix diaporama pour tests
    lecteur->changerDiaporama(3);


    // Connexion des signaux et des slots

    // Présentation -> Modele
    QObject::connect(presentation, SIGNAL(faireAvancer()), modele, SLOT(demandeAvancement()));
    QObject::connect(presentation, SIGNAL(faireReculer()), modele, SLOT(demandeReculement()));
    QObject::connect(presentation, SIGNAL(faireAfficherImageDepart()), modele, SLOT(demandeAffichageImageDebut()));

    // Présentation -> vue
    QObject::connect(presentation, SIGNAL(faireOuvrirAPropos()), &vueLecteur, SLOT(afficherInformations()));

    // Modèle -> vue
    QObject::connect(modele, SIGNAL(imageChanged(QString, QString, QString)), &vueLecteur, SLOT(updateImageInfo(QString, QString, QString)));

    vueLecteur.demanderAffichageImage1();
    // Affichage de la fenetre
    vueLecteur.show();



    return a.exec();
}
