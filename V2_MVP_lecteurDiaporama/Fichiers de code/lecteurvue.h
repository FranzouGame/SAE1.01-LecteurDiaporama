#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>

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
    ~lecteurvue();

    // Getters
    PresentationLecteur* getPres() const;

    // Setters
    void setPres(PresentationLecteur*);



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
    void demanderChangementVitesseDefilementX0_5();
    void demanderChangementVitesseDefilementX0_75();
    void demanderChangementVitesseDefilementX1();
    void demanderChangementVitesseDefilementX1_25();
    void demanderChangementVitesseDefilementX1_5();
    void demanderChangementVitesseDefilementX1_75();
    void demanderChangementVitesseDefilementX2();

};
#endif // LECTEURVUE_H
