    /*** Inclusions requises ***/
// Fichiers
#include "lecteurvue.h"
#include "modelelecteur.h"
#include "presentationlecteur.h"

// Bibliothèques
#include <QApplication>



void chargerDiapos(Diaporamas& diapos);


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
    /*chargerDiapos(mesDiapos);
    int taille = mesDiapos.size();
    qDebug() << "Taille du vecteur : " << taille << "  ";*/

    // Association des différents éléments entre eux
    // modele->setInfosDiapos(mesDiapos);
    //modele->chargerDiapos();
    vueLecteur.setPres(presentation);
    presentation->setModele(modele);
    modele->setEtat(ModeleLecteur::Initial);
    presentation->setVue(&vueLecteur);

    // Connection pour le changement du nom de diapo (Temporaire)
    QObject::connect(modele, SIGNAL(diapoChanged(QString)), &vueLecteur, SLOT(updateDiapoTitle(QString)));

    // Choix diaporama pour tests
    lecteur->changerDiaporama(3, "Diapo de test", 2);

    modele->setLecteur(lecteur);




    // Connexion des signaux et des slots

    // Présentation -> Modele
    QObject::connect(presentation, SIGNAL(faireAvancer()), modele, SLOT(demandeAvancement()));
    QObject::connect(presentation, SIGNAL(faireReculer()), modele, SLOT(demandeReculement()));
    QObject::connect(presentation, SIGNAL(faireAfficherImageDepart()), modele, SLOT(demandeAffichageImageDebut()));

    // Présentation -> vue
    QObject::connect(presentation, SIGNAL(faireOuvrirAPropos()), &vueLecteur, SLOT(afficherInformations()));

    // Modèle -> vue
    QObject::connect(modele, SIGNAL(imageChanged(QString, QString, QString)), &vueLecteur, SLOT(updateImageInfo(QString, QString, QString)));
    QObject::connect(modele, SIGNAL(sendDiapoInfos(Diaporamas)), &vueLecteur, SLOT(receptionDiapos(Diaporamas)));

    vueLecteur.demanderAffichageImage1();
    // Affichage de la fenetre
    vueLecteur.show();

    return a.exec();
}



void chargerDiapos(Diaporamas& diapos)
{
    InfosDiaporama infosACharger;
    // Diaporama de Pantxika
    infosACharger.id = 1;
    infosACharger.titre = "Diaporama Pantxika";
    infosACharger.vitesseDefilement = 2;
    diapos.push_back(infosACharger);

    // Diaporama de Thierry
    infosACharger.id = 2;
    infosACharger.titre = "Diaporama Thierry";
    infosACharger.vitesseDefilement = 4;
    diapos.push_back(infosACharger);

    // Diaporama de Yann
    infosACharger.id = 3;
    infosACharger.titre = "Diaporama Yann";
    infosACharger.vitesseDefilement = 2;
    diapos.push_back(infosACharger);

    // Diaporama de Manu
    infosACharger.id = 4;
    infosACharger.titre = "Diaporama Manu";
    infosACharger.vitesseDefilement = 1;
    diapos.push_back(infosACharger);

    qDebug() << "Chargement terminé";

}
