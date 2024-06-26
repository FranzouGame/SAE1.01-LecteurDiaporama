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
    QObject::connect(ui->actionChangerVitesseDefilement, SIGNAL(triggered()), this, SLOT(demanderChangementVitesseDefilement()));
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(demanderFermetureLecteur()));
    QObject::connect(ui->actionA_propos_de, SIGNAL(triggered()), this, SLOT(demanderInformations()));
    QObject::connect(ui->actionModeAuto, SIGNAL(triggered()), this, SLOT(demanderChangementModeAuto()));
    QObject::connect(ui->actionModeManuel, SIGNAL(triggered()), this, SLOT(demanderChangementModeManuel()));
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

void lecteurvue::demanderChangementDiaporama() {
    qDebug() << "Demande de chargement de diaporama";
}

void lecteurvue::demanderArreterDiapo() {
    qDebug() << "Demande d'arrêt du diaporama en cours";
}

void lecteurvue::demanderLancementDiapo() {
    qDebug() << "Demande de lancement d'un diaporama";
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



void lecteurvue::demanderChangementModeAuto() {
    qDebug() << "Demande de passage en mode automatique";
}

void lecteurvue::demanderChangementModeManuel() {
    qDebug() << "Demande de passage en mode manuel";
}

void lecteurvue::demanderChangementVitesseDefilement()
{
    qDebug() << "Je change la vitesse de défilement";
}
