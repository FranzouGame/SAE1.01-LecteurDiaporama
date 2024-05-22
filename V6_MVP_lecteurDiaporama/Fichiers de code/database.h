#ifndef DATABASE_H
#define DATABASE_H

#include "diaporama.h"
#include "modelelecteur.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

#define DATABASE_NAME "BDS2.01" // Pc Maxime fixe
#define CONNECT_TYPE "QODBC"

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
    void recupereImageDiapo(unsigned int);

signals:
    // Envoi des images du diaporama choisi
    void sendImagesDiapo(Diaporama*);

    // Envoi des informations des diaporamas
    void sendInfosDiapos(Diaporamas*);

private:
    QSqlDatabase _mydb;
};

#endif // DATABASE_H
