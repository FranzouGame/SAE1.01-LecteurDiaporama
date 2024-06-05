#include "creationdiaporama.h"
#include "ui_creationdiaporama.h"
#include <QMessageBox>

// Constructeur
CreationDiaporama::CreationDiaporama(Images images, QWidget* parent) :
    QDialog(parent),
    _imagesBD(images),
    ui(new Ui::CreationDiaporama){

    // Setup l'ui
    ui->setupUi(this);

    // Changer le titre de la fenêtre
    setWindowTitle("Création d'un diaporama");
    ui->btnConfirmer->setEnabled(false);

    // Ajout d'une ligne vide en premier pour la lisibilité
    ui->comboBoxCreation->addItem("");

    for (unsigned int i = 0; i < _imagesBD.size(); i++) {
        bool titreDejaChoisi = false;
        QString titre = QString::fromStdString(images[i].getTitre());

        // Parcours des images déjà choisies pour vérifier si le titre est déjà présent
        for (unsigned int j = 0; j < _imagesChoisies.size(); j++) {
            if(QString::fromStdString(_imagesChoisies[j].getTitre()) == titre){
                titreDejaChoisi = true;
            }
        }

        if(!titreDejaChoisi)
        {ui->comboBoxCreation->addItem(titre);}
    }

    // Connexion des boutons avec les slots
    QObject::connect(ui->btnConfirmer, SIGNAL(clicked(bool)), this, SLOT(transmettreInformations()));
    QObject::connect(ui->btnAnnuler, SIGNAL(clicked(bool)), this, SLOT(fermerFenetre()));
    QObject::connect(ui->btnAjouter, SIGNAL(clicked(bool)), this, SLOT(ajouterImage()));
    QObject::connect(ui->saisievitesse, SIGNAL(textEdited(QString)), this, SLOT(enableButton()));
}

// Destructeur
CreationDiaporama::~CreationDiaporama(){
    delete ui;
}

void CreationDiaporama::transmettreInformations()
{
    // Récupérer les infos
    QString nom = ui->saisieNom_2->text();
    unsigned int vitesse = ui->saisievitesse->text().toUInt();

    if(!_imagesChoisies.empty()){
        emit envoyerInformations(_imagesChoisies, nom, vitesse);
        close();
    }
    else{
        QMessageBox::warning(this, "Erreur", "Veuillez choisir au moins une image ou annuler.");
    }
}

void CreationDiaporama::fermerFenetre()
{
    close();
}

// Slot pour ajouter une image
void CreationDiaporama::ajouterImage(){
    // Récupérer l'index de l'image
    int index = ui->comboBoxCreation->currentIndex();

    // Ajouter l'image à la liste
    _imagesChoisies.push_back(_imagesBD[index-1]);

    // Ré-afficher la première ligne vide
    ui->comboBoxCreation->setCurrentIndex(0);

    // Supprimer l'image de la liste déroulante
    ui->comboBoxCreation->removeItem(index);
}

void CreationDiaporama::enableButton()
{
    // Récupérer le nom saisi & la vitesse
    QString nom = ui->saisievitesse->text();
    unsigned int vitesse = ui->saisievitesse->text().toUInt();

    // Vérifier qu'il est plus logn que 0
    if(nom.length() > 0 && vitesse > 0){
        ui->btnConfirmer->setEnabled(true);
    }
    else{
        ui->btnConfirmer->setEnabled(false);
    }
}

