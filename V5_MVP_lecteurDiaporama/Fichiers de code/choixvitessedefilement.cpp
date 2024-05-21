#include "choixvitessedefilement.h"
#include "qpushbutton.h"
#include "ui_choixvitessedefilement.h"

choixVitesseDefilement::choixVitesseDefilement(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::choixVitesseDefilement)
{
    ui->setupUi(this);

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
        float vitesse = userInput.toFloat(&conversionOk);

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
    float userInput = ui->choixUtilisateur->text().toFloat();

    // Vérifier la valeur saisie
    emit envoyerVitesseDfl(userInput);

}
