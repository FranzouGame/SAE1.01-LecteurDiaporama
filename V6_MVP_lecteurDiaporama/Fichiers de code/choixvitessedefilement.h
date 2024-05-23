#ifndef CHOIXVITESSEDEFILEMENT_H
#define CHOIXVITESSEDEFILEMENT_H

#include <QDialog>

namespace Ui {
class choixVitesseDefilement;
}

class choixVitesseDefilement : public QDialog
{
    Q_OBJECT

public:
    explicit choixVitesseDefilement(QWidget *parent = nullptr);
    ~choixVitesseDefilement();

private:
    Ui::choixVitesseDefilement *ui;

private slots:
    void enableButton();
    void demanderEnvoiValeur();

signals:
    void envoyerVitesseDfl(unsigned int);
};

#endif // CHOIXVITESSEDEFILEMENT_H
