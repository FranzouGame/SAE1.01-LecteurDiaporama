#include "choixdiaporama.h"
#include "ui_choixdiaporama.h"
#include "modelelecteur.h"

ChoixDiaporama::ChoixDiaporama(Diaporamas& d, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChoixDiaporama)
{
    ui->setupUi(this);

    // Ajout des informations
    for (unsigned int i = 0 ; i < d.size(); i++)
    {
        QString id = QString::number(d[i].id);
        QString titre = QString::fromStdString(d[i].titre);
        QString chainePourAffichage = id + " - " + titre;
        ui->comboBoxDiaporamas->addItem(chainePourAffichage);
    }

    // Connexion de l'acceptation avec la procédure de récupération
    QObject::connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &ChoixDiaporama::transmettreInformations);
}

ChoixDiaporama::ChoixDiaporama(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChoixDiaporama)
{
    ui->setupUi(this);

    // Ajout des informations nécessaires
}

ChoixDiaporama::~ChoixDiaporama()
{
    delete ui;
}

void ChoixDiaporama::transmettreInformations()
{
    // Récupérer le contenu de la comboBox
    QString choix = ui->comboBoxDiaporamas->currentText();

    // Extraire le premier caractère de la chaîne et le convertir en entier
    int choixInt = choix.left(1).toInt();

    // Trouver la position du premier tiret
    int positionTiret = choix.indexOf('-');

    // Extraire la partie après le tiret (nom du diaporama)
    QString nomDiaporama = choix.mid(positionTiret + 1).trimmed();

    qDebug() << "Chaine récupérée : " << nomDiaporama;

    // Envoyer l'information
    emit transmettreInfos(choixInt, nomDiaporama);
}
