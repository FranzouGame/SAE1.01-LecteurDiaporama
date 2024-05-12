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
    Lecteur* lecteur = nullptr;

    // Association des différents éléments entre eux
    vueLecteur.setPres(presentation);
    presentation->setModele(modele);
    modele->setEtat(ModeleLecteur::Initial);
    presentation->setVue(&vueLecteur);
    modele->setLecteur(lecteur);

    // Choix diaporama pour tests
    lecteur->changerDiaporama(2);

    // Affichage de la fenetre
    vueLecteur.show();

    // Connexion des signaux et des slots
    QObject::connect(presentation, SIGNAL(faireAvancer()), modele, SLOT(demandeAvancement()));
    QObject::connect(presentation, SIGNAL(faireReculer()), modele, SLOT(demandeReculement()));
    QObject::connect(presentation, SIGNAL(faireOuvrirAPropos()), &vueLecteur, SLOT(afficherInformations()));
    QObject::connect(modele, SIGNAL(imageChanged(QString, QString, QString)), &vueLecteur, SLOT(updateImageInfo(QString, QString, QString)));
    QObject::connect(modele, SIGNAL(diaporamasChanged(QList<Diaporama*>)), &vueLecteur, SLOT(updateDiaporamasList(QList<Diaporama*>)));


    return a.exec();
}
