#ifndef FENETREAPROPOS_H
#define FENETREAPROPOS_H

#include <QDialog>

namespace Ui {
class fenetreAPropos;
}

class fenetreAPropos : public QDialog
{
    Q_OBJECT

public:
    explicit fenetreAPropos(QWidget *parent = nullptr);
    ~fenetreAPropos();

private:
    Ui::fenetreAPropos *ui;

private slots:
    void fermeture();
};

#endif // FENETREAPROPOS_H
