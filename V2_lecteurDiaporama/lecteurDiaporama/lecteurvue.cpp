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
    //QObject::connect(ui->actionChanger_Vitesse_Defilement, SIGNAL(triggered()), this, SLOT(demanderChangementVitesseDefilement()));
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(demanderFermetureLecteur()));
    QObject::connect(ui->actionA_propos_de, SIGNAL(triggered()), this, SLOT(demanderInformations()));
    QObject::connect(ui->actionX0_5, SIGNAL(triggered()), this, SLOT(demanderChangementVitesseDefilementX0_5()));
    QObject::connect(ui->actionX0_75, SIGNAL(triggered()), this, SLOT(demanderChangementVitesseDefilementX0_75()));
    QObject::connect(ui->actionX1, SIGNAL(triggered()), this, SLOT(demanderChangementVitesseDefilementX1()));
    QObject::connect(ui->actionX1_25, SIGNAL(triggered()), this, SLOT(demanderChangementVitesseDefilementX1_25()));
    QObject::connect(ui->actionX1_5, SIGNAL(triggered()), this, SLOT(demanderChangementVitesseDefilementX1_5()));
    QObject::connect(ui->actionX1_75, SIGNAL(triggered()), this, SLOT(demanderChangementVitesseDefilementX1_75()));
    QObject::connect(ui->actionX2, SIGNAL(triggered()), this, SLOT(demanderChangementVitesseDefilementX2()));
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
void lecteurvue::demanderChangementVitesseDefilementX0_5() {
    qDebug() << "Demande de changement de vitesse de défilement du diaporama à 0.5";
}
void lecteurvue::demanderChangementVitesseDefilementX0_75() {
    qDebug() << "Demande de changement de vitesse de défilement du diaporama à 0.75";
}
void lecteurvue::demanderChangementVitesseDefilementX1() {
    qDebug() << "Demande de changement de vitesse de défilement du diaporama à 1";
}
void lecteurvue::demanderChangementVitesseDefilementX1_25() {
    qDebug() << "Demande de changement de vitesse de défilement du diaporama à 1.25";
}
void lecteurvue::demanderChangementVitesseDefilementX1_5() {
    qDebug() << "Demande de changement de vitesse de défilement du diaporama à 1.5";
}
void lecteurvue::demanderChangementVitesseDefilementX1_75() {
    qDebug() << "Demande de changement de vitesse de défilement du diaporama à 1.75";
}
void lecteurvue::demanderChangementVitesseDefilementX2() {
    qDebug() << "Demande de changement de vitesse de défilement du diaporama à 2";
}

