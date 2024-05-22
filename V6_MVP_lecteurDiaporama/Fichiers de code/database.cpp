#include "database.h"


Database::Database() {
    openDatabase();
}

QSqlDatabase Database::getDataBase() const
{
    return _mydb;
}

void Database::setDatabase(QSqlDatabase pBd)
{
    _mydb = pBd;
}

bool Database::openDatabase()
{

    _mydb = QSqlDatabase::addDatabase("QODBC");

    // Configurer les paramètres de connexion
    _mydb.setHostName("localhost");
    _mydb.setDatabaseName("nodenot_bd9");
    _mydb.setUserName("root");
    _mydb.setPassword("");

    if(_mydb.open())
    {
        qDebug() << "Database ouverte";
        return true;
    }

}

bool Database::closeDatabase()
{
    _mydb.close();
    return false;
}
