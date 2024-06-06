#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>
#include <QLabel>
#include "modelelecteur.h"
#include "presentationlecteur.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class LecteurVue;
}
QT_END_NAMESPACE




class LecteurVue : public QMainWindow
{
    Q_OBJECT


private:
    // Design de la vue
    Ui::LecteurVue *ui;
    // Presentation de la vue
    PresentationLecteur* _pres;
    // Informations des diaporamas
    Diaporamas _infosDiapos;
    // Informations des images
    Images _images;
    // Label d'état
    QLabel* _labelEtat;

    // Méthode d'animation
    void animerChangementImage(const QString& cheminImage);




public:
    // Constructeur & Destructeur
    LecteurVue(QWidget *parent = nullptr);
    ~LecteurVue();

    // Getters
    PresentationLecteur* getPres() const;

    // Setters
    void setPres(PresentationLecteur*);
    void setImages(Images);

    // Autres méthodes
    void majInterface(PresentationLecteur::UnEtat, Diaporamas = {});

    // Réception des informations
    void afficherInformations(); // Fenetre A propos
    void updateImageInfo(const QString& chemin, const QString& titre, const QString& categorie); // Image mise à jour
    void updateDiapoTitle(const QString& titreDiapo);
    void receptionDiapos(Diaporamas);
    void receptionImages(Images);

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
    void demanderCreationDiaporama();

    //Pour changer la vitesse de défilement
    void demanderChangementVitesseDefilement();
    void demanderEnleverDiaporama();

    // Récupérer les choix utilisateurs
    void recupereInfosDiapoChoisi(InfosDiaporama);
    void recupereVitesseDefilement(unsigned int);
    void recupereImages(Images, QString, unsigned int);
};
#endif // LECTEURVUE_H
