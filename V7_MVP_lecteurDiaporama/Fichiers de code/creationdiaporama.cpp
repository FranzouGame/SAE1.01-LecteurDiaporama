#include "creationdiaporama.h"
#include "ui_creationdiaporama.h"

// Matching constructor
CreationDiaporama::CreationDiaporama(Images images, unsigned int idDiapo, QWidget* parent) :
    QDialog(parent),
    _imagesBD(images),
    _idDiapo(idDiapo),
    ui(new Ui::CreationDiaporama){

    // Setup l'ui
    ui->setupUi(this);

    // Changer le titre de la fenêtre
    setWindowTitle("Création d'un diaporama");

    // Ajout des informations
    for (unsigned int i = 0; i < images.size(); i++) {
        QString titre = QString::fromStdString(images[i].getTitre());
        ui->comboBox->addItem(titre);
    }

    // Connexion des boutons avec les slots
    QObject::connect(ui->btnConfirmer, SIGNAL(clicked(bool)), this, SLOT(transmettreInformations()));
    QObject::connect(ui->btnAnnuler, SIGNAL(clicked(bool)), this, SLOT(fermerFenetre()));
    QObject::connect(ui->btnAjouter, SIGNAL(clicked(bool)), this, SLOT(ajouterImage()));
}

// Destructeur
CreationDiaporama::~CreationDiaporama(){
    delete ui;
}

// Slot pour ajouter une image
void CreationDiaporama::ajouterImage(){
    // Récupérer l'index de l'image à ajouter
    unsigned int index = ui->comboBox->currentIndex();
    // Ajouter l'image à la liste
    _images.push_back(_imagesBD[index]);
    // Ajouter le titre de l'image à la liste
    ui->listWidget->addItem(ui->comboBox->currentText());
}
