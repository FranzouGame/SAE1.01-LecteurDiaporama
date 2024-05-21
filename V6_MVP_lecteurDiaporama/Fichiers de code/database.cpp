#include "database.h"


database::database() {}

QSqlDatabase *database::getDataBase() const
{
    return _mydb;
}

void database::setDatabase(QSqlDatabase * pBd)
{
    _mydb = new QSqlDatabase(pBd);
}

bool database::openDatabase()
{

    _mydb::addDatabase("QMYSQL");

    // Configurer les paramètres de connexion
    db.setHostName("localhost");
    db.setDatabaseName("nodenot_bd9");
    db.setUserName("root");
    db.setPassword("");

    if(_mybd->open())
    {

    }
}

bool database::closeDatabase()
{

}
