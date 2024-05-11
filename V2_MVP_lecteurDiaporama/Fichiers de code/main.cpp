    /*** Inclusions requises ***/
// Fichiers
#include "lecteurvue.h"
#include "modelelecteur.h"
#include "presentationlecteur.h"

// Bibliothèques
#include <QApplication>


struct InfosDiaporama {
    unsigned int id;    // identifiant du diaporama dans la BD
    string titre;       // titre du diaporama
    unsigned int vitesseDefilement;
};

// Type nécessaire
typedef vector<InfosDiaporama> Diaporamas;



int main(int argc, char *argv[])
{
    // Gestion des fenêtre
    QApplication a(argc, argv);

    // Création des variables
    ModeleLecteur* modele = new ModeleLecteur();
    PresentationLecteur* presentation = new PresentationLecteur();
    LecteurVue vueLecteur;

    // Association des différents éléments entre eux
    vueLecteur.setPres(presentation);
    presentation->setModele(modele);
    modele->setEtat(ModeleLecteur::Initial);
    presentation->setVue(&vueLecteur);

    // Affichage de la fenetre
    vueLecteur.show();

    // Connexion des signaux et des slots
    QObject::connect(presentation, SIGNAL(faireAvancer()), modele, SLOT(demandeAvancement()));
    QObject::connect(presentation, SIGNAL(faireReculer()), modele, SLOT(demandeReculement()));

    return a.exec();
}
