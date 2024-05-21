#ifndef DATABASE_H
#define DATABASE_H


#include <QSqlDatabase>


#define DATABASE_NAME "localhost"
#define CONNECT_TYPE "QMYSQL"


class database
{
public:
    database();
    // Getters
    QSqlDatabase* getDataBase() const;

    // Setters
    void setDatabase(QSqlDatabase*);

    // Méthodes de manipulation de la BD
    bool openDatabase();
    bool closeDatabase();

private:
    QSqlDatabase* _mydb;

};

#endif // DATABASE_H
