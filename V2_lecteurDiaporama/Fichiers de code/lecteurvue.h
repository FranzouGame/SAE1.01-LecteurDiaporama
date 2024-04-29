#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class lecteurvue;
}
QT_END_NAMESPACE

class lecteurvue : public QMainWindow
{
    Q_OBJECT

public:
    // Constructeur & Destructeur
    lecteurvue(QWidget *parent = nullptr);
    ~lecteurvue();

private:
    // Design de la fenêtre
    Ui::lecteurvue *ui;

public slots:
    // Pour faire le lien avec les diaporamas
    void demanderAvancer();
    void demanderReculer();
<<<<<<< HEAD
    void demanderChangementVitesseDefilement();
=======
>>>>>>> 4a61c008d2df54e393f53ab6cc1cfffdacd379bc
    void demanderArreterDiapo();

    // Pour gérer les actions propres au lecteur
    void demanderChangementDiaporama();
    void demanderLancementDiapo();
    void demanderFermetureLecteur();
    void demanderInformations();
<<<<<<< HEAD
=======
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
>>>>>>> 4a61c008d2df54e393f53ab6cc1cfffdacd379bc

};
#endif // LECTEURVUE_H
