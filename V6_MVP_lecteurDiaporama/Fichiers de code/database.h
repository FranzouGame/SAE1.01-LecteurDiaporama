#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

#define DATABASE_NAME "mbourciez_bd"
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

private:
    QSqlDatabase _mydb;
};

#endif // DATABASE_H
