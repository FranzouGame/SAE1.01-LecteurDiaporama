#ifndef CREATIONDIAPORAMA_H
#define CREATIONDIAPORAMA_H


#include <QDialog>
#include "qdialog.h"
#include "qobject.h"
#include "diaporama.h"


namespace Ui {
class CreationDiaporama;
}

class CreationDiaporama : public QDialog
{
    Q_OBJECT


public:
    CreationDiaporama(Images, QWidget* parent = nullptr);
    ~CreationDiaporama();

private slots:
    void transmettreInformations();
    void fermerFenetre();
    void ajouterImage();
    void enableButton();

private:
    Images _imagesBD;
    Images _imagesChoisies;
    unsigned int _idDiapo;
    Ui::CreationDiaporama* ui;

signals:
    void envoyerInformations(Images, QString, unsigned int);

};



#endif // CREATIONDIAPORAMA_H
