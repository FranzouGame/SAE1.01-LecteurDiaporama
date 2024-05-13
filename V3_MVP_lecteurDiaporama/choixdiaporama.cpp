#include "choixdiaporama.h"
#include "ui_choixdiaporama.h"
#include "modelelecteur.h".h"

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
