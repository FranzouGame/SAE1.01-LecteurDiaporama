#include "fenetreapropos.h"
#include "ui_fenetreapropos.h"

fenetreAPropos::fenetreAPropos(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::fenetreAPropos)
{
    ui->setupUi(this);

<<<<<<< HEAD
    // Changer le nom de la fenêtre
    setWindowTitle("A propos du lecteur de diaporamas");

    // Connexion
    QObject::connect(ui->btnOk, SIGNAL(clicked()), this, SLOT(fermeture()));

    // Changer le nom de la version
    ui->version->setText(QString("V5_MVP"));
=======
    // Mise à jour de la version de l'application dans la fenetre
    ui->version->setText(QString("V4_MVP"));

    // Connexion
    QObject::connect(ui->btnOk, SIGNAL(clicked()), this, SLOT(fermeture()));
>>>>>>> V4
}

fenetreAPropos::~fenetreAPropos()
{
    delete ui;
}

void fenetreAPropos::fermeture()
{
    accept();
}
