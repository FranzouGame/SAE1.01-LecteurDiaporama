#include "fenetreapropos.h"
#include "ui_fenetreapropos.h"

fenetreAPropos::fenetreAPropos(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::fenetreAPropos)
{
    ui->setupUi(this);

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
