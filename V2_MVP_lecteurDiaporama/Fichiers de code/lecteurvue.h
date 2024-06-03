#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>
#include "modelelecteur.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class LecteurVue;
}
QT_END_NAMESPACE

// Classe nécessaire
class PresentationLecteur;


class LecteurVue : public QMainWindow
{
    Q_OBJECT


private:
    // Design de la vue
    Ui::LecteurVue *ui;
    // Presentation de la vue
    PresentationLecteur* _pres;

public:
    // Constructeur & Destructeur
    LecteurVue(QWidget *parent = nullptr);
    ~LecteurVue();

    // Getters
    PresentationLecteur* getPres() const;

    // Setters
    void setPres(PresentationLecteur*);

    // Autres méthodes
    void majInterface(ModeleLecteur::UnEtat);

public slots:
    // Pour faire le lien avec les diaporamas
    void demanderAvancer();
    void demanderReculer();
    void demanderArreterDiapo();

    // Pour gérer les actions propres au lecteur
    void demanderChangementDiaporama();
    void demanderLancementDiapo();
    void demanderFermetureLecteur();
    void demanderInformations();
    void demanderChangementModeAuto();
    void demanderChangementModeManuel();

    //Pour changer la vitesse de défilement
    void demanderChangementVitesseDefilement();
};
#endif // LECTEURVUE_H
