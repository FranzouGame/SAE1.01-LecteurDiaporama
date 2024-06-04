#ifndef DATABASE_H
#define DATABASE_H

#include "diaporama.h"
#include "modelelecteur.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

#define DATABASE_NAME "s201"
#define CONNECT_TYPE "QODBC"
class Diaporama;
class ModeleLecteur;
class Database
{
public:
    Database();
    ~Database();

    // Getters
    QSqlDatabase getDatabase() const;

    // Setters
    void setDatabase(QSqlDatabase);

    // Méthodes de manipulation de la BD
    bool openDatabase();
    bool closeDatabase();
    Diaporamas recupereDiapos();
    Diaporama* recupereImageDiapo(unsigned int);
    void modifierVitesseDfl(unsigned int idDIapo, unsigned int vitesseAApply);
    void modifTitresEtChemins();

signals:
    // Envoi des images du diaporama choisi
    void sendImagesDiapo(Diaporama*);

    // Envoi des informations des diaporamas
    void sendInfosDiapos(Diaporamas*);

private:
    QSqlDatabase _mydb;
};

#endif // DATABASE_H
