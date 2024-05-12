#include "choixdiaporama.h"
#include "ui_choixdiaporama.h"

ChoixDiaporama::ChoixDiaporama(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChoixDiaporama)
{
    ui->setupUi(this);
}

ChoixDiaporama::~ChoixDiaporama()
{
    delete ui;
}
