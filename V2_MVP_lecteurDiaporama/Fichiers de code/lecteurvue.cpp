#include "LecteurVue.h"
#include "ui_lecteurvue.h"

/************************
 * CORPS DE LA CLASSE
 ***********************/


LecteurVue::LecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LecteurVue)
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
    QObject::connect(ui->actionModeAuto, SIGNAL(triggered()), this, SLOT(demanderChangementModeAuto()));
    QObject::connect(ui->actionModeManuel, SIGNAL(triggered()), this, SLOT(demanderChangementModeManuel()));
}

LecteurVue::~LecteurVue()
{
    delete ui;
}




/************************
 *        SLOTS         *
 ***********************/
void LecteurVue::demanderAvancer() {
    qDebug() << "Demande d'avancement dans le diaporama";
    getPres()->demanderAvancer();
}

void LecteurVue::demanderReculer() {
    qDebug() << "Demande de recul dans le diaporama";
}

void LecteurVue::demanderChangementDiaporama() {
    qDebug() << "Demande de chargement de diaporama";
}

void LecteurVue::demanderArreterDiapo() {
    qDebug() << "Demande d'arrêt de la diapositive en cours";
}

void LecteurVue::demanderLancementDiapo() {
    qDebug() << "Demande de lancement d'une diapositive";
}

void LecteurVue::demanderFermetureLecteur() {
    qDebug() << "Demande de fermeture du lecteur";
    /* Fermeture réelle
    close();
    */
}

void LecteurVue::demanderInformations() {
    qDebug() << "Demande d'informations";
}


void LecteurVue::demanderChangementModeAuto() {
    qDebug() << "Demande de passage en mode automatique";
}

void LecteurVue::demanderChangementModeManuel() {
    qDebug() << "Demande de passage en mode manuel";
}

void LecteurVue::demanderChangementVitesseDefilement()
{
    qDebug() << "Demande de changement de vitesse de défilement";
}
