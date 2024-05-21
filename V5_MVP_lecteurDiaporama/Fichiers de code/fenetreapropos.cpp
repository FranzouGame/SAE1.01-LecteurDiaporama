#include "fenetreapropos.h"
#include "ui_fenetreapropos.h"

fenetreAPropos::fenetreAPropos(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::fenetreAPropos)
{
    ui->setupUi(this);

    // Mise à jour de la version de l'application dans la fenetre
    ui->version->setText(QString("V4_MVP"));

    // Connexion
    QObject::connect(ui->btnOk, SIGNAL(clicked()), this, SLOT(fermeture()));
}

fenetreAPropos::~fenetreAPropos()
{
    delete ui;
}

void fenetreAPropos::fermeture()
{
    accept();
}
