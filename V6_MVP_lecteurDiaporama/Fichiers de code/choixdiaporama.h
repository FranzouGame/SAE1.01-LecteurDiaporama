#ifndef CHOIXDIAPORAMA_H
#define CHOIXDIAPORAMA_H

#include <QDialog>
#include "modelelecteur.h"

namespace Ui {
class ChoixDiaporama;
}

class ChoixDiaporama : public QDialog
{
    Q_OBJECT

public:
    ChoixDiaporama(Diaporamas&, QWidget *parent=nullptr);
    explicit ChoixDiaporama(QWidget *parent = nullptr);
    ~ChoixDiaporama();
    // Getters
    InfosDiaporama getInfosDiapoCourant() const;
    Diaporamas getInfosDiaporamas() const;

private:
    Ui::ChoixDiaporama *ui;
    InfosDiaporama _diapoCourant;
    Diaporamas _infosDiapos;

private slots:
    void transmettreInformations();

signals:
    void transmettreInfos(InfosDiaporama);

};

#endif // CHOIXDIAPORAMA_H
