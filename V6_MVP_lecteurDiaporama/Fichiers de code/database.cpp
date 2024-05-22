#include "database.h"

Database::Database()
    : _mydb(new QSqlDatabase(QSqlDatabase::addDatabase("QMYSQL", "mycntr")))
{
    // Initialisation de la base de données
    if (openDatabase()) {
        qDebug() << "Ouverture de la BD réussie";
    } else {
        qDebug() << "Ouverture ratée";
    }
}

Database::~Database()
{
    // Fermer la base de données et supprimer le pointeur dans le destructeur
    closeDatabase();
    delete _mydb;
}

QSqlDatabase* Database::getDatabase() const
{
    return _mydb;
}

void Database::setDatabase(QSqlDatabase* db)
{
    if (_mydb != db) {
        delete _mydb;
        _mydb = db;
    }
}

bool Database::openDatabase()
{
    // Configurer les paramètres de connexion
    _mydb->setHostName("localhost");
    _mydb->setDatabaseName("bd sae");
    _mydb->setUserName("root");
    _mydb->setPassword("");

    if (_mydb->open()) {
        return true;
    } else {
        qDebug() << "Ouverture ratée : " << _mydb->lastError().text();
        return false;
    }
}

bool Database::closeDatabase()
{
    if (_mydb->isOpen()) {
        _mydb->close();
        QSqlDatabase::removeDatabase("mycntr");
        return true;
    }
    return false;
}
