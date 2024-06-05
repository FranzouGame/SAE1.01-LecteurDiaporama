#include "fenetreapropos.h"
#include "ui_fenetreapropos.h"

fenetreAPropos::fenetreAPropos(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::fenetreAPropos)
{
    ui->setupUi(this);

    // Changer le nom de la fenêtre
    setWindowTitle("A propos du lecteur de diaporamas");

    // Connexion
    QObject::connect(ui->btnOk, SIGNAL(clicked()), this, SLOT(fermeture()));

    // Changer le nom de la version
    ui->version->setText(QString("V6_MVP"));

    // Changer l'icône de la fenêtre
    setWindowIcon(QIcon(":/icones/icones/aboutIcon.png"));
}

fenetreAPropos::~fenetreAPropos()
{
    delete ui;
}

void fenetreAPropos::fermeture()
{
    accept();
}
