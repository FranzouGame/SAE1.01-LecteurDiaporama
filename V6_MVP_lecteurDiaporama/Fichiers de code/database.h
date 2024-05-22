#ifndef DATABASE_H
#define DATABASE_H


#include <QSqlDatabase>
#include <QDebug>

#define DATABASE_NAME "localhost"
#define CONNECT_TYPE "QODBC"


class Database
{
public:
    //constructeur
    Database();
    // Getters
    QSqlDatabase getDataBase() const;

    // Setters
    void setDatabase(QSqlDatabase pBd);

    // Méthodes de manipulation de la BD
    bool openDatabase();
    bool closeDatabase();

private:
    QSqlDatabase _mydb;

};

#endif // DATABASE_H
