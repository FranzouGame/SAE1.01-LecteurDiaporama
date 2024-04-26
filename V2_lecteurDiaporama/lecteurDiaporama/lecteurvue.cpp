#include "lecteurvue.h"
#include "ui_lecteurvue.h"

/************************
 * CORPS DE LA CLASSE
 ***********************/


lecteurvue::lecteurvue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::lecteurvue)
{
    ui->setupUi(this);

    // Connections
    QObject::connect(ui->btnLancerDiapo, SIGNAL(clicked()), this, SLOT(demanderLancementDiapo()));
    QObject::connect(ui->btnSuiv, SIGNAL(clicked()), this, SLOT(demanderAvancer()));
    QObject::connect(ui->btnPrec, SIGNAL(clicked()), this, SLOT(demanderReculer()));
    QObject::connect(ui->actionCharger_Diaporama, SIGNAL(triggered()), this, SLOT(demanderChangementDiaporama()));
    QObject::connect(ui->btnArreterDiapo, SIGNAL(clicked()), this, SLOT(demanderArreterDiapo()));
    QObject::connect(ui->actionChanger_Vitesse_Defilement, SIGNAL(triggered()), this, SLOT(demanderChangementVitesseDefilement()));
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(demanderFermetureLecteur()));
    QObject::connect(ui->actionA_propos_de, SIGNAL(triggered()), this, SLOT(demanderInformations()));
}

lecteurvue::~lecteurvue()
{
    delete ui;
}




/************************
 *        SLOTS         *
 ***********************/
void lecteurvue::demanderAvancer() {
    qDebug() << "Demande d'avancement dans le diaporama";
}

void lecteurvue::demanderReculer() {
    qDebug() << "Demande de recul dans le diaporama";
}

void lecteurvue::demanderChangementVitesseDefilement() {
    qDebug() << "Demande de changement de vitesse de défilement du diaporama";
}

void lecteurvue::demanderChangementDiaporama() {
    qDebug() << "Demande de chargement de diaporama";
}

void lecteurvue::demanderArreterDiapo() {
    qDebug() << "Demande d'arrêt de la diapositive en cours";
}

void lecteurvue::demanderLancementDiapo() {
    qDebug() << "Demande de lancement d'une diapositive";
}

void lecteurvue::demanderFermetureLecteur() {
    qDebug() << "Demande de fermeture du lecteur";
    /* Fermeture réelle
    close();
    */
}

void lecteurvue::demanderInformations() {
    qDebug() << "Demande d'informations";
}
