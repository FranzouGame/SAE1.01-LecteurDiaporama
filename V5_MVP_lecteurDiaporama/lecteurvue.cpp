#include "LecteurVue.h"
#include "ui_lecteurvue.h"
#include "presentationlecteur.h"
#include "fenetreapropos.h"
#include "choixdiaporama.h"
#include "choixvitessedefilement.h"

/************************
 * CORPS DE LA CLASSE
 ***********************/


LecteurVue::LecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LecteurVue)
    , _infosDiapos({})
{
    ui->setupUi(this);

    // Connections

    // Boutons
    QObject::connect(ui->btnLancerDiapo, SIGNAL(clicked()), this, SLOT(demanderLancementDiapo()));
    QObject::connect(ui->btnSuiv, SIGNAL(clicked()), this, SLOT(demanderAvancer()));
    QObject::connect(ui->btnPrec, SIGNAL(clicked()), this, SLOT(demanderReculer()));
    QObject::connect(ui->btnArreterDiapo, SIGNAL(clicked()), this, SLOT(demanderArreterDiapo()));

    // Actions des menus
    QObject::connect(ui->actionChangerVitesseDefilement, SIGNAL(triggered()), this, SLOT(demanderChangementVitesseDefilement()));
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(demanderFermetureLecteur()));
    QObject::connect(ui->actionA_propos_de, SIGNAL(triggered()), this, SLOT(demanderInformations()));
    QObject::connect(ui->actionModeAuto, SIGNAL(triggered()), this, SLOT(demanderChangementModeAuto()));
    QObject::connect(ui->actionCharger_Diaporama, SIGNAL(triggered()), this, SLOT(demanderChangementDiaporama()));
    QObject::connect(ui->actionModeManuel, SIGNAL(triggered()), this, SLOT(demanderChangementModeManuel()));
    QObject::connect(ui->actionEnleverDiaporama, SIGNAL(triggered(bool)), this ,SLOT(demanderEnleverDiaporama()));
}

LecteurVue::~LecteurVue()
{
    delete ui;
}




/************************
 *        SLOTS         *
 ***********************/
void LecteurVue::demanderAvancer() {
    getPres()->demanderAvancer();
}

void LecteurVue::demanderReculer() {
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
    getPres()->demanderChangerVitesse();
}

void LecteurVue::demanderEnleverDiaporama()
{
    getPres()->demanderEnleverDiaporama();
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

        // Réinitialiser les valeurs des labels
        ui->titreDiapo->setText(QString("Titre du diaporama"));
        ui->titreImage->setText(QString("Titre de l'image"));
        ui->catImage->setText(QString("Catégorie de l'image"));
        ui->image->setText(QString(" "));
        ui->btnArreterDiapo->setEnabled(false);
        ui->btnLancerDiapo->setEnabled(false);
        ui->actionChangerVitesseDefilement->setEnabled(false);

        break;
    case ModeleLecteur::Manuel:


        break;
    case ModeleLecteur::Automatique:
        // Implémentation à faire
        break;
    case ModeleLecteur::ChoixDiaporama:
        {
            ChoixDiaporama* fenetreChoix = new ChoixDiaporama(_infosDiapos, this);

            // Connexion pour la récupération d'informaitons
            QObject::connect(fenetreChoix, SIGNAL(transmettreInfos(InfosDiaporama)), this, SLOT(recupereInfosDiapoChoisi(InfosDiaporama)));

            // Afficher la fenêtre
            fenetreChoix->exec();
        }
        break;
    case ModeleLecteur::ChoixVitesseDefilement:
        {
            // Création de la fenêtre
            choixVitesseDefilement fenetreChoix(this);

            // Connexion pour la récupération d'informations
            QObject::connect(&fenetreChoix, SIGNAL(envoyerVitesseDfl(float)), this, SLOT(recupereVitesseDefilement(float)));

            qDebug() << "Vue majI";
            // Ouvrir la fenêtre de choix
            fenetreChoix.exec();
        }
        break;
    default:
        break;
    }
}


void LecteurVue::demanderAffichageImage1()
{
    getPres()->demanderAffichageDiapoDebut();
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
}

void LecteurVue::recupereInfosDiapoChoisi(InfosDiaporama d)
{
    getPres()->demanderChangementDIapo(d);
}

void LecteurVue::recupereVitesseDefilement(float pVitesse)
{
    qDebug() << "vue";
    getPres()->demanderChangementVitesseDfl(pVitesse);
}





