#ifndef CHOIXDIAPORAMA_H
#define CHOIXDIAPORAMA_H

#include <QDialog>

namespace Ui {
class ChoixDiaporama;
}

class ChoixDiaporama : public QDialog
{
    Q_OBJECT

public:
    explicit ChoixDiaporama(QWidget *parent = nullptr);
    ~ChoixDiaporama();

private:
    Ui::ChoixDiaporama *ui;
};

#endif // CHOIXDIAPORAMA_H
