#include "database.h"
#include "diaporama.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>
#include <vector>
#include <string>

Database::Database()
{
    // Initialisation de la base de données
    if (openDatabase()) {
        qDebug() << "Ouverture de la BD réussie";

    } else {
        qDebug() << "Ouverture ratée";
        qDebug() << _mydb.lastError();
    }
}

Database::~Database()
{
    // Fermer la base de données et supprimer le pointeur dans le destructeur
    closeDatabase();
}

QSqlDatabase Database::getDatabase() const
{
    return _mydb;
}

void Database::setDatabase(QSqlDatabase db)
{
    _mydb = db;
}

bool Database::openDatabase()
{
    // Définir les paramètres de connexion à la base de données
    _mydb = QSqlDatabase::addDatabase(CONNECT_TYPE);
    _mydb.setDatabaseName(DATABASE_NAME);
    if (!_mydb.open()) {
        qDebug() << "Impossible d'ouvrir la base de données:" ;
        return false;
   }

   qDebug() << "Connexion à la base de données réussie.";
   return true;
}

bool Database::closeDatabase()
{
    if (_mydb.isOpen()) {
        _mydb.close();
        QSqlDatabase::removeDatabase(CONNECT_TYPE);
        return true;
    }
    return false;
}

Diaporamas Database::recupereDiapos() {
    if(!_mydb.isOpen())
    {
        qDebug() << "Ouverture de la BD qui était fermée";
        openDatabase();
    }

    QSqlQuery query( "SELECT * FROM Diaporamas", _mydb);

    // Réinitialiser l'objet de requête
    query.clear();

    QString queryString = "SELECT * FROM Diaporamas";
    query.prepare(queryString);

    Diaporamas diaporamasInfos;

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError().text();
        return diaporamasInfos; // Retourner un vecteur vide en cas d'erreur
    }

    while (query.next()) {
        InfosDiaporama infosDiapoCourant;
        infosDiapoCourant.id = query.value(0).toUInt();
        infosDiapoCourant.titre = query.value(1).toString().toStdString();
        infosDiapoCourant.vitesseDefilement = query.value(2).toUInt();

        diaporamasInfos.push_back(infosDiapoCourant);
    }

    return diaporamasInfos;
}




Diaporama* Database::recupereImageDiapo(unsigned int numDiapo)
{
    QSqlQuery query(_mydb);
    QString queryString = "SELECT D.uriPhoto, D.titrePhoto, F.nomFamille, DDD.rang, Dia.vitesseDefilement "
                          "FROM Diapos D "
                          "JOIN DiaposDansDiaporama DDD on DDD.idDiapo = D.idphoto "
                          "JOIN Familles F on F.idFamille = D.idFam "
                          "JOIN Diaporamas Dia on Dia.idDiaporama = DDD.idDiaporama "
                          "WHERE DDD.idDiaporama = :idDiaporama "
                          "ORDER BY DDD.rang;";
    query.prepare(queryString);
    query.bindValue(":idDiaporama", numDiapo);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError().text();
        return nullptr;  // Retourner nullptr en cas d'erreur
    }

    Diaporama* diapoCharge = new Diaporama();

    // Initialisation de la vitesse de défilement au cas où il n'y aurait pas de résultats
    int vitesseDefilement = 0;

    if (query.next()) {
        vitesseDefilement = query.value(4).toInt(); // Mettre la vitesse de défilement au diapo
        query.previous(); // Revenir à la première ligne pour le traitement suivant
    }

    diapoCharge->setVitesseDefilement(vitesseDefilement);

    while (query.next()) {
        QString uriPhoto = QString(":/imagesDur") + query.value(0).toString();
        QString titrePhoto = query.value(1).toString();
        QString nomFamille = query.value(2).toString();
        int rang = query.value(3).toInt();

        ImageDansDiaporama* imageEnCharge = new ImageDansDiaporama(rang, nomFamille.toStdString(), titrePhoto.toStdString(), uriPhoto.toStdString());
        diapoCharge->ajouterImageEnFin(imageEnCharge);
    }

    return diapoCharge; // Retourner le diaporama chargé
}
void Database::modifierVitesseDfl(unsigned int idDiapo)
{

    QSqlQuery query(_mydb);

    QString queryString = "UPDATE Diaporamas SET vitesseDefilement = 10 WHERE idDiaporama = :idDiaporama";
    query.prepare(queryString);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError().text();
    }
}
