#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

class Database
{
public:
    Database();
    ~Database();

    // Getters
    QSqlDatabase* getDatabase() const;

    // Setters
    void setDatabase(QSqlDatabase*);

    // Méthodes de manipulation de la BD
    bool openDatabase();
    bool closeDatabase();

private:
    QSqlDatabase* _mydb;
};

#endif // DATABASE_H
