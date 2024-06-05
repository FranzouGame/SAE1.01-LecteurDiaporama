#include "choixdiaporama.h"
#include "ui_choixdiaporama.h"
#include "modelelecteur.h"

ChoixDiaporama::ChoixDiaporama(Diaporamas& d, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChoixDiaporama)
    , _infosDiapos(d)
{
    ui->setupUi(this);

    // Changer le titre de la fenêtre
    setWindowTitle("Charger un diaporama");

    // Changer l'icone de la fenêtre
    setWindowIcon(QIcon(":/icones/icones/iconeChoix.jpg"));

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

InfosDiaporama ChoixDiaporama::getInfosDiapoCourant() const
{
    return _diapoCourant;
}

Diaporamas ChoixDiaporama::getInfosDiaporamas() const
{
    return _infosDiapos;
}


void ChoixDiaporama::transmettreInformations()
{
    // récupérer le n° de la ligne choisie
    int index = ui->comboBoxDiaporamas->currentIndex();

    // Vérifier si l'indice est valide
    if (index >= 0 && index < static_cast<int>(_infosDiapos.size())) {
        // Récupérer l'objet InfosDiaporama correspondant à l'élément sélectionné
        InfosDiaporama diaporamaSelectionne = _infosDiapos[index];

        // Émettre un signal avec les informations du diaporama sélectionné
        emit transmettreInfos(diaporamaSelectionne);
    }

    // Envoyer l'information

}
