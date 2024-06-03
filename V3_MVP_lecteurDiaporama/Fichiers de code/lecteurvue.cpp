#include "LecteurVue.h"
#include "ui_lecteurvue.h"
#include "presentationlecteur.h"
#include "fenetreapropos.h"
#include "choixdiaporama.h"

/************************
 * CORPS DE LA CLASSE
 ***********************/


LecteurVue::LecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LecteurVue)
<<<<<<< HEAD
    , _infosDiapos({})
=======
    , _pres(new PresentationLecteur())
>>>>>>> V4
{
    ui->setupUi(this);
    btnSuiv = ui->btnSuiv;
    btnPrec = ui->btnPrec;
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

    QObject::connect(ui->btnSuiv, SIGNAL(clicked()), _pres, SLOT(onBtnSuivClicked()));
    QObject::connect(ui->btnPrec, SIGNAL(clicked()), _pres, SLOT(onBtnPredClicked()));
}

LecteurVue::~LecteurVue()
{
    delete _pres;
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
    getPres()->demanderReculer();
}

void LecteurVue::demanderChangementDiaporama() {
    getPres()->demanderChargement();
}

void LecteurVue::demanderArreterDiapo() {
    qDebug() << "Demande d'arrêt de la diapositive en cours";
    getPres()->demanderArretDiapo();
}

void LecteurVue::demanderLancementDiapo() {
    qDebug() << "Demande de lancement d'une diapositive";
    getPres()->demanderLancement();
}

void LecteurVue::demanderFermetureLecteur() {
    close();
}

void LecteurVue::demanderInformations() {
    _pres->demanderAffichageInformations();
}


void LecteurVue::demanderChangementModeAuto() {
    qDebug() << "Demande de passage en mode automatique";
    getPres()->demanderChangementModeVersAUtomatique();
}


void LecteurVue::demanderChangementModeManuel() {
    qDebug() << "Demande de passage en mode manuel";
    getPres()->demanderChangementModeVersManuel();
}

void LecteurVue::demanderChangementVitesseDefilement()
{
    qDebug() << "Demande de changement de vitesse de défilement";
    getPres()->demanderChangerVitesse();
}

void LecteurVue::afficherInformations()
{
    // Instanciation de la fenêtre demandée
    fenetreAPropos infosApp;

    // Afficher la fenetre
    infosApp.exec();
}



/************************
 *        GETTERS       *
 ***********************/

PresentationLecteur* LecteurVue::getPres() const {
    return _pres;
}

/************************
 *        SETTERS       *
 ***********************/

void LecteurVue::setPres(PresentationLecteur* pres) {
    _pres = pres;
}



/************************
 *    MAJ INTERFACE     *
 ***********************/


void LecteurVue::majInterface(ModeleLecteur::UnEtat e)
{
    switch(e)
    {
    case ModeleLecteur::Initial:
        break;
    case ModeleLecteur::Manuel:
        // Implémentation à faire
        break;
    case ModeleLecteur::Automatique:
        // Implémentation à faire

        break;
    case ModeleLecteur::ChoixDiaporama:
        {
            ChoixDiaporama fenetreChoix(_infosDiapos);

            // Afficher la fenêtre
            fenetreChoix.exec();
        }
        break;
    case ModeleLecteur::ChoixVitesseDefilement:
        // Implémentation à faire
        break;
    default:
        break;
    }
}


void LecteurVue::demanderAffichageImage1()
{
    getPres()->demanderAffichageDiapoDebut();
}

void LecteurVue::demanderAffichage1ereImage()
{
    qDebug() << "Vue : Affichage image 1";
    getPres()->demanderAffichageDiapo1();
}




void LecteurVue::updateImageInfo(const QString& chemin, const QString& titre, const QString& categorie)
{
    // Mettre à jour l'interface avec les nouvelles informations de l'image// Création d'un QPixmap à partir de votre image
    QPixmap pixmap(chemin);

    // Vérification que l'image a été chargée correctement
    if (!pixmap.isNull()) {
        // Affichage de l'image dans le QLabel
        ui->image->setPixmap(pixmap);
    }
    else {
        qDebug() << "Erreur : Impossible de charger l'image.";
    }
    ui->titreImage->setText(titre);
    ui->catImage->setText(categorie);
}

void LecteurVue::updateDiapoTitle(const QString &titreDiapo)
{
    ui->titreDiapo->setText(titreDiapo);
}

void LecteurVue::receptionDiapos(Diaporamas d)
{
    _infosDiapos = d;

    qDebug() << "Vue taille : " << d.size();
}





