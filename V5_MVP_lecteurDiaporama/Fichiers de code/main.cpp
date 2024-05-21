    /*** Inclusions requises ***/
// Fichiers
#include "lecteurvue.h"
#include "modelelecteur.h"
#include "presentationlecteur.h"

// Bibliothèques
#include <QApplication>




<<<<<<< HEAD
=======


>>>>>>> V4
int main(int argc, char *argv[])
{
    // Gestion des fenêtre
    QApplication a(argc, argv);

<<<<<<< HEAD

=======
>>>>>>> V4
    // Création des variables
    ModeleLecteur* modele = new ModeleLecteur();
    PresentationLecteur* presentation = new PresentationLecteur();
    LecteurVue vueLecteur;
    Lecteur* lecteur = new Lecteur();
<<<<<<< HEAD
    Diaporamas mesDiapos;


=======
>>>>>>> V4

    // Association des différents éléments entre eux
    vueLecteur.setPres(presentation);
    presentation->setModele(modele);
<<<<<<< HEAD
    modele->setEtat(ModeleLecteur::Initial);
    presentation->setVue(&vueLecteur);
=======
    modele->setEtat(ModeleLecteur::Manuel);
    presentation->setVue(&vueLecteur);

    // Connection pour le changement du nom de diapo (Temporaire)
    QObject::connect(modele, SIGNAL(diapoChanged(QString)), &vueLecteur, SLOT(updateDiapoTitle(QString)));

    // Choix diaporama pour tests
    lecteur->changerDiaporama(3, "Diapo de test", 2);

>>>>>>> V4
    modele->setLecteur(lecteur);

    // Connexion des signaux et des slots

<<<<<<< HEAD
    // Présentation -> Modele
    QObject::connect(presentation, SIGNAL(faireAvancer()), modele, SLOT(demandeAvancement()));
    QObject::connect(presentation, SIGNAL(faireReculer()), modele, SLOT(demandeReculement()));
    QObject::connect(presentation, SIGNAL(faireChangerVitesse(unsigned int)), modele, SLOT(receptionDemandeChangementVitesse(unsigned int)));
    QObject::connect(presentation, SIGNAL(faireChangerDiapo(InfosDiaporama)), modele, SLOT(receptionDemandeChangementDiaporama(InfosDiaporama)));
=======
    // Vue -> Présentation
    QObject::connect(&vueLecteur, SIGNAL(signalArreterLancementAutomatique()), presentation, SLOT(demanderArretDiapo()));

    // Présentation -> Modele
    QObject::connect(presentation, SIGNAL(faireAvancer()), modele, SLOT(demandeAvancement()));
    QObject::connect(presentation, SIGNAL(faireReculer()), modele, SLOT(demandeReculement()));
    QObject::connect(presentation, SIGNAL(faireAfficherImageDepart()), modele, SLOT(demandeAffichageImageDebut()));
>>>>>>> V4

    // Présentation -> vue
    QObject::connect(presentation, SIGNAL(faireOuvrirAPropos()), &vueLecteur, SLOT(afficherInformations()));

    // Modèle -> vue
<<<<<<< HEAD
    QObject::connect(modele, SIGNAL(imageChanged(QString,QString,QString)), &vueLecteur, SLOT(updateImageInfo(QString,QString,QString)));
    QObject::connect(modele, SIGNAL(diapoChanged(QString)), &vueLecteur, SLOT(updateDiapoTitle(QString)));
    QObject::connect(modele, SIGNAL(sendDiapoInfos(Diaporamas)), &vueLecteur, SLOT(receptionDiapos(Diaporamas)));

=======
    QObject::connect(modele, SIGNAL(imageChanged(QString, QString, QString)), &vueLecteur, SLOT(updateImageInfo(QString, QString, QString)));


    vueLecteur.demanderAffichageImage1();
    vueLecteur.majInterface(modele->getEtat());
>>>>>>> V4
    // Affichage de la fenetre
    vueLecteur.show();

    return a.exec();
}
<<<<<<< HEAD




=======
>>>>>>> V4
