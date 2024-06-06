#include "LecteurVue.h"
#include "ui_lecteurvue.h"
#include "presentationlecteur.h"
#include "fenetreapropos.h"
#include "choixdiaporama.h"
#include "choixvitessedefilement.h"
#include "creationdiaporama.h"
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>

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

    // Changer l'icone de la fenetre
    setWindowIcon(QIcon(":/icones/icones/mainIcon.png"));

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
    QObject::connect(ui->actionCreerDiaporama, SIGNAL(triggered()), this, SLOT(demanderCreationDiaporama()));

    // Ajouter un label à droite de la barre de statut
    _labelEtat->setText("Mode : Initial");
    statusBar()->addPermanentWidget(_labelEtat);

    // Appliquer un stylesheet pour rendre la barre de statut grisée
    statusBar()->setStyleSheet("QStatusBar { background-color: lightgray; }");

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
    qDebug() << "1, taille : " << _infosDiapos.size();
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

void LecteurVue::demanderCreationDiaporama()
{
    getPres()->demanderCreerDiaporama();
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

void LecteurVue::setImages(Images img)
{
    _images = img;
}

void LecteurVue::setDiaporamas(Diaporamas infosDiapos)
{
    _infosDiapos = infosDiapos;
}



/************************
 *    MAJ INTERFACE     *
 ***********************/


void LecteurVue::majInterface(PresentationLecteur::UnEtat e, Diaporamas d)
{
    switch(e)
    {
    case PresentationLecteur::Initial:

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
    case PresentationLecteur::Manuel:
        // Changer la dispo des boutons
        ui->btnLancerDiapo->setEnabled(true);
        ui->btnArreterDiapo->setEnabled(false);

        // Maj de la barre d'état
        _labelEtat->setText(QString("Mode : Manuel"));
        break;
    case PresentationLecteur::Automatique:

        // Changer la dispo des boutons
        ui->btnArreterDiapo->setEnabled(true);
        ui->btnLancerDiapo->setEnabled(true);
        ui->actionChangerVitesseDefilement->setEnabled(true);

        // Maj de la barre d'état
        _labelEtat->setText(QString("Mode : Automatique"));
        break;
    case PresentationLecteur::ChoixDiaporama:
        {
            ChoixDiaporama* fenetreChoix = new ChoixDiaporama(_infosDiapos, this);

            qDebug() << "2, taille : " << _infosDiapos.size();

            // Connexion pour la récupération d'informaitons
            QObject::connect(fenetreChoix, SIGNAL(transmettreInfos(InfosDiaporama)), this, SLOT(recupereInfosDiapoChoisi(InfosDiaporama)));

            // Afficher la fenêtre
            fenetreChoix->exec();
        }
        break;
    case PresentationLecteur::ChoixVitesseDefilement:
        {
            // Création de la fenêtre
            choixVitesseDefilement fenetreChoix(this);

            // Connexion pour la récupération d'informations
            QObject::connect(&fenetreChoix, SIGNAL(envoyerVitesseDfl(unsigned int)), this, SLOT(recupereVitesseDefilement(unsigned int)));

            // Ouvrir la fenêtre de choix
            fenetreChoix.exec();
        }
        break;

    case PresentationLecteur::CreationDiaporama:
        {
            // Créer la fenetre de création de diaporama
            CreationDiaporama* fenetreCreation = new CreationDiaporama(_images, this);

            // Connecter la récupération d'informations
            QObject::connect(fenetreCreation, SIGNAL(envoyerInformations(Images, QString, unsigned int)), this, SLOT(recupereImages(Images, QString, unsigned int)));

            // Afficher la fenêtre
            fenetreCreation->exec();
    }
    default:
        break;
    }
}


void LecteurVue::updateImageInfo(const QString& chemin, const QString& titre, const QString& categorie)
{
    animerChangementImage(chemin);

    ui->titreImage->setText(titre);
    ui->catImage->setText(categorie);

    // Mettre à jour l'interface avec les nouvelles informations de l'image// Création d'un QPixmap à partir de votre image
    QPixmap pixmap(chemin);

    // Vérification que l'image a été chargée correctement
    if (!pixmap.isNull()) {
        // Affichage de l'image dans le QLabel
        ui->image->setPixmap(pixmap);
        ui->image->setAlignment(Qt::AlignCenter);
    }
    else {
        qDebug() << "Erreur : Impossible de charger l'image.";
    }
}



void LecteurVue::animerChangementImage(const QString& cheminImage)
{
    QGraphicsOpacityEffect* effect = new QGraphicsOpacityEffect(this);
    ui->image->setGraphicsEffect(effect);

    QPropertyAnimation* animation = new QPropertyAnimation(effect, "opacity");
    animation->setDuration(500);
    animation->setStartValue(0.0);
    animation->setEndValue(1.0);

    connect(animation, &QPropertyAnimation::finished, [=]() {
        QPixmap pixmap(cheminImage);
        ui->image->setPixmap(pixmap);
        ui->image->setAlignment(Qt::AlignCenter);
        ui->image->setGraphicsEffect(nullptr);
    });

    animation->start(QAbstractAnimation::DeleteWhenStopped);
}



void LecteurVue::updateDiapoTitle(const QString &titreDiapo)
{
    ui->titreDiapo->setText(titreDiapo);
}

void LecteurVue::receptionDiapos(Diaporamas d)
{
    _infosDiapos = d;
}

void LecteurVue::receptionImages(Images images)
{
    _images = images;
}





void LecteurVue::recupereInfosDiapoChoisi(InfosDiaporama d)
{
    getPres()->demanderChangementDIapo(d);
}

void LecteurVue::recupereVitesseDefilement(unsigned int pVitesse)
{
    getPres()->demanderChangementVitesseDfl(pVitesse);
}

void LecteurVue::recupereImages(Images img, QString titre, unsigned int vitesse)
{
    getPres()->demanderCreationDiaporama(img, titre, vitesse);
}








