#include "presentationlecteur.h"
#include "modelelecteur.h"
#include "lecteurvue.h"




/***********************
 *   CONSTRUCTEURS     *
***********************/


PresentationLecteur::PresentationLecteur() :
    _vue(nullptr),
    _modele(nullptr)
{
    // Initialisation du timer
    _timer = new QTimer(this);
    connect(_timer, &QTimer::timeout, this, &PresentationLecteur::avancerEnBoucle);
}



/***********************
 *      GETTERS        *
***********************/


LecteurVue* PresentationLecteur::getVue() const {
    return _vue;
}


ModeleLecteur* PresentationLecteur::getModele() const {
    return _modele;
}


/***********************
 *      SETTERS        *
***********************/


void PresentationLecteur::setVue(LecteurVue* vue) {
    _vue = vue;
    _vue->majInterface(_modele->getEtat());
}


void PresentationLecteur::setModele(ModeleLecteur* modele) {
    _modele = modele;
}



/***********************
 *       SLOTS         *
***********************/


// Actions relatives aux diaporamas ou à leur chargement

void PresentationLecteur::demanderAvancer() {
    if(getModele()->getEtat() == ModeleLecteur::Automatique)
    {
        demanderArretDiapo();
    }
    else
    {
        emit faireAvancer();
    }
}

void PresentationLecteur::demanderReculer() {
    if(getModele()->getEtat() == ModeleLecteur::Automatique)
    {
        demanderArretDiapo();
    }
    else
    {
        emit faireReculer();
    }
}



void PresentationLecteur::demanderArretDiapo() {

    // Arreter le timer
    if (_timer->isActive()) {
        _timer->stop();
    }

    // Changer d'état
    _modele->setEtat(ModeleLecteur::Manuel);
    _vue->majInterface(_modele->getEtat());
}

void PresentationLecteur::demanderEnleverDiaporama()
{
    emit faireEnleverDiapo();
    _modele->setEtat(ModeleLecteur::Initial);
    _vue->majInterface(_modele->getEtat());

}

void PresentationLecteur::demanderChangerVitesse() {
    ModeleLecteur::UnEtat etatPrécédent = _modele->getEtat();
    _modele->setEtat(ModeleLecteur::ChoixVitesseDefilement);
    _vue->majInterface(_modele->getEtat());
    _modele->setEtat(etatPrécédent);
}

void PresentationLecteur::avancerEnBoucle() // Avancer mais pour le mode auto
{
    emit faireAvancer();
}


// Actions liées au lecteur

void PresentationLecteur::demanderChargement() {
    ModeleLecteur::UnEtat etatPrécédent = _modele->getEtat();
    _modele->setEtat(ModeleLecteur::ChoixDiaporama);
    _modele->demanderInfosDiapos();
    _vue->majInterface(_modele->getEtat());
    if(etatPrécédent == ModeleLecteur::Automatique || etatPrécédent == ModeleLecteur::Manuel)
    {
        _modele->setEtat(etatPrécédent);
    }
    else
    {
        _modele->setEtat(ModeleLecteur::Manuel);
        _vue->majInterface(_modele->getEtat());
    }

}

void PresentationLecteur::demanderLancement() {
    if (_modele->getEtat() == ModeleLecteur::Manuel)
    {
        _modele->setEtat(ModeleLecteur::Automatique);
        _vue->majInterface(_modele->getEtat());
    }

    // Récupérer la vitesse de défilement du diapo (sera utile quand les diapos seront entièrement chargés, ce qui n'est pas encore le cas)
    unsigned int vitesse = _modele->recupereVitesseDfl();

    //remettre l'image de départ si on appuie sur le btn Lancer diapo alors que l'image actuelle n'est pas la premiere
    if(_modele->getLecteur()->getImageCourante()->getRangDansDiaporama() != _modele->getLecteur()->nbImages() - _modele->getLecteur()->nbImages()+1)
    {
        _modele->demanderRetourImage1();
    }

    if (_modele->getEtat() == ModeleLecteur::Automatique)
    {
        if (vitesse == 0) {
            _modele->getLecteur()->getDiaporama()->setVitesseDefilement(1);
        }

        if(_modele->getLecteur()->getImageCourante()->getRangDansDiaporama() <= _modele->getLecteur()->nbImages() - 1)
        {
            _timer->start(2000); // Lancement du timer
            emit faireAfficherImageDepart();
        }
        else
        {
            _modele->demanderRetourImage1();
            demanderArretDiapo();
            demanderChangementModeVersManuel();
        }

    }

}

void PresentationLecteur::demanderChangementModeVersManuel() {
    _modele->setEtat(ModeleLecteur::Manuel);
    _vue->majInterface(_modele->getEtat());
}

void PresentationLecteur::demanderChangementModeVersAUtomatique() {
    _modele->setEtat(ModeleLecteur::Automatique);
    _vue->majInterface(_modele->getEtat());
}


// Actions liées au fenetres externes

void PresentationLecteur::demanderAffichageInformations()
{
    emit faireOuvrirAPropos();
}


// Actions liées aux choix utilisateur

void PresentationLecteur::demanderChangementDIapo(InfosDiaporama d)
{
    emit faireChangerDiapo(d);
}

void PresentationLecteur::demanderChangementVitesseDfl(unsigned int pVitesse)
{
    emit faireChangerVitesse(pVitesse);
}
