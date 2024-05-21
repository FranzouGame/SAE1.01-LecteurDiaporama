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
    modele->setEtat(ModeleLecteur::Manuel);
    presentation->setVue(&vueLecteur);

    // Connection pour le changement du nom de diapo (Temporaire)
    QObject::connect(modele, SIGNAL(diapoChanged(QString)), &vueLecteur, SLOT(updateDiapoTitle(QString)));

    // Choix diaporama pour tests
    lecteur->changerDiaporama(3, "Diapo de test", 2);

    modele->setLecteur(lecteur);

    // Connexion des signaux et des slots

    // Vue -> Présentation
    QObject::connect(&vueLecteur, SIGNAL(signalArreterLancementAutomatique()), presentation, SLOT(demanderArretDiapo()));

    // Présentation -> Modele
    QObject::connect(presentation, SIGNAL(faireAvancer()), modele, SLOT(demandeAvancement()));
    QObject::connect(presentation, SIGNAL(faireReculer()), modele, SLOT(demandeReculement()));
    QObject::connect(presentation, SIGNAL(faireAfficherImageDepart()), modele, SLOT(demandeAffichageImageDebut()));

    // Présentation -> vue
    QObject::connect(presentation, SIGNAL(faireOuvrirAPropos()), &vueLecteur, SLOT(afficherInformations()));

    // Modèle -> vue
    QObject::connect(modele, SIGNAL(imageChanged(QString, QString, QString)), &vueLecteur, SLOT(updateImageInfo(QString, QString, QString)));


    vueLecteur.demanderAffichageImage1();
    vueLecteur.majInterface(modele->getEtat());
    // Affichage de la fenetre
    vueLecteur.show();

    return a.exec();
}
