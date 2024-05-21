#include "choixdiaporama.h"
#include "ui_choixdiaporama.h"
#include "modelelecteur.h"
<<<<<<< HEAD

ChoixDiaporama::ChoixDiaporama(Diaporamas& d, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChoixDiaporama)
{
    ui->setupUi(this);

    qDebug() << "Tu es peut etre le probleme // taille : " << d.size();

    // Ajout des informations
    for (unsigned int i = 0 ; i < d.size(); i++)
    {
        QString id = QString::number(d[i].id);
        QString titre = QString::fromStdString(d[i].titre);
        QString chainePourAffichage = id + " - " + titre;
        ui->comboBoxDiaporamas->addItem(chainePourAffichage);
    }

    qDebug() << "Tu n'es pas le probleme";

}
=======
>>>>>>> V4

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
