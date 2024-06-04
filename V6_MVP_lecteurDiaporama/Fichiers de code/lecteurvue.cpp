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
    ,_labelEtat(new QLabel(this))
{
    ui->setupUi(this);

    // Changer le nom de la fenêtre
    setWindowTitle("Lecteur de diaporama - S2.01");

    // Ajouter un label à droite de la barre de statut
    _labelEtat->setText("Mode : Initial");
    statusBar()->addPermanentWidget(_labelEtat);

    // Appliquer un stylesheet pour rendre la barre de statut grisée
    statusBar()->setStyleSheet("QStatusBar { background-color: lightgray; }");

    // Changer l'icône de la fenêtre, qui se situe dans ressources et icones, qui est lefichier mainIcon.png
    setWindowIcon(QIcon(":/icones/icones/mainIcon.png")); // Ca ne marche pas


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
    getPres()->demanderArretDiapo();
}

void LecteurVue::demanderLancementDiapo() {
    getPres()->demanderLancement();
}

void LecteurVue::demanderFermetureLecteur() {
    close();
}

void LecteurVue::demanderInformations() {
    _pres->demanderAffichageInformations();
}


void LecteurVue::demanderChangementModeAuto() {
    getPres()->demanderChangementModeVersAUtomatique();
}


void LecteurVue::demanderChangementModeManuel() {
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

        // Changer la dispo des boutons
        ui->btnArreterDiapo->setEnabled(false);
        ui->btnLancerDiapo->setEnabled(false);
        ui->actionChangerVitesseDefilement->setEnabled(false);

        // Maj de la barre d'état
        _labelEtat->setText(QString("Mode : Initial"));
        break;
    case ModeleLecteur::Manuel:
        // Changer la dispo des boutons
        ui->btnLancerDiapo->setEnabled(true);
        ui->btnArreterDiapo->setEnabled(false);
        ui->actionChangerVitesseDefilement->setEnabled(false);

        // Maj de la barre d'état
        _labelEtat->setText(QString("Mode : Manuel"));
        break;
    case ModeleLecteur::Automatique:

        // Changer la dispo des boutons
        ui->btnArreterDiapo->setEnabled(true);
        ui->btnLancerDiapo->setEnabled(true);
        ui->actionChangerVitesseDefilement->setEnabled(true);

        // Maj de la barre d'état
        _labelEtat->setText(QString("Mode : Automatique"));
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
            QObject::connect(&fenetreChoix, SIGNAL(envoyerVitesseDfl(unsigned int)), this, SLOT(recupereVitesseDefilement(unsigned int)));

            // Ouvrir la fenêtre de choix
            fenetreChoix.exec();
        }
        break;
    default:
        break;
    }
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

void LecteurVue::recupereVitesseDefilement(unsigned int pVitesse)
{
    getPres()->demanderChangementVitesseDfl(pVitesse);
}





