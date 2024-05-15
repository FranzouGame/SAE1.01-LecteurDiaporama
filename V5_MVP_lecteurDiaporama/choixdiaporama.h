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

private:
    Ui::ChoixDiaporama *ui;

private slots:
    void transmettreInformations();

signals:
    void transmettreInfos(int);

};

#endif // CHOIXDIAPORAMA_H
