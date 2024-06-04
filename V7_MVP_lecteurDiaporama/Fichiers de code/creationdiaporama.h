#ifndef CREATIONDIAPORAMA_H
#define CREATIONDIAPORAMA_H




#include "qdialog.h"
#include "qobject.h"
#include "imagedansdiaporama.h"

typedef vector<ImageDansDiaporama> Images;

namespace Ui {
    class CreationDiaporama;
}

class CreationDiaporama : public QDialog
{
    Q_OBJECT

public:
    CreationDiaporama(Images, unsigned int, QWidget* parent = nullptr);
    ~CreationDiaporama();

private slots:
    void transmettreInformations();
    void fermerFenetre();
    void ajouterImage();

private:
    Images _imagesBD;
    unsigned int _idDiapo;
    Ui::CreationDiaporama* ui;
};

#endif // CREATIONDIAPORAMA_H
