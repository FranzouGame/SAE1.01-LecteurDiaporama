#include "choixvitessedefilement.h"
#include "qpushbutton.h"
#include "ui_choixvitessedefilement.h"

choixVitesseDefilement::choixVitesseDefilement(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::choixVitesseDefilement)
{
    ui->setupUi(this);

    // Changer le nom de la fenêtre
    setWindowTitle("Changement de la vitesse de défilement");

    // Changer l'icône de la fenêtre
    setWindowIcon(QIcon(":/icones/icones/iconChgt.png"));

    // Mise à jour de l'interface pour empêcher une mauvaise saisie
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

    // Connexions
    QObject::connect(ui->choixUtilisateur, SIGNAL(textEdited(QString)), this, SLOT(enableButton()));
    QObject::connect(this, SIGNAL(accepted()), this, SLOT(demanderEnvoiValeur()));

}

choixVitesseDefilement::~choixVitesseDefilement()
{
    delete ui;
}

void choixVitesseDefilement::enableButton()
{
    // Récupérer la saisie utilisateur
    QString userInput = ui->choixUtilisateur->text();

    // Vérifier si la saisie utilisateur n'est pas vide
    if (!userInput.isEmpty())
    {
        // Essayer de convertir la saisie
        bool conversionOk;
        float vitesse = userInput.toInt(&conversionOk);

        // Vérifier si la conversion s'est bien déroulée
        if (conversionOk && (vitesse >= 0.2 && vitesse <= 5.0))
        {
            // Activer le bouton Ok si la conversion est réussie
            ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
        }
        else
        {
            // Désactiver le bouton Ok si la saisie n'est pas un nombre valide
            ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
        }
    }
    else
    {
        // Désactiver le bouton Ok si la saisie est vide
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    }


}

void choixVitesseDefilement::demanderEnvoiValeur()
{
    unsigned int userInput = static_cast<int>(ui->choixUtilisateur->text().toInt());

    // Vérifier la valeur saisie
    emit envoyerVitesseDfl(userInput);

}
