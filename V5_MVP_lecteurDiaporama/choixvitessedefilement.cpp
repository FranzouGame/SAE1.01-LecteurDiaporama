#include "choixvitessedefilement.h"
#include "ui_choixvitessedefilement.h"

choixVitesseDefilement::choixVitesseDefilement(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::choixVitesseDefilement)
{
    ui->setupUi(this);
}

choixVitesseDefilement::~choixVitesseDefilement()
{
    delete ui;
}
