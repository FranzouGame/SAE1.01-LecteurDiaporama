#include "fenetreapropos.h"
#include "ui_fenetreapropos.h"

fenetreAPropos::fenetreAPropos(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::fenetreAPropos)
{
    ui->setupUi(this);
}

fenetreAPropos::~fenetreAPropos()
{
    delete ui;
}
