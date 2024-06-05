#ifndef CREATIONDIAPORAMA_H
#define CREATIONDIAPORAMA_H

#include <QDialog>

namespace Ui {
class CreationDiaporama;
}

class CreationDiaporama : public QDialog
{
    Q_OBJECT
public:
    CreationDiaporama();
private:
    Ui::CreationDiaporama *ui;

};



#endif // CREATIONDIAPORAMA_H
