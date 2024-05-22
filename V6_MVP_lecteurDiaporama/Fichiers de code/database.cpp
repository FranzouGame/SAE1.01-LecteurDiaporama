#include "database.h"
#include "diaporama.h"

Database::Database()
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
        QSqlDatabase::removeDatabase("mycntr");
        return true;
    }
    return false;
}

Diaporamas Database::recupereDiapos()
{
    QSqlQuery query(_mydb);
    QString queryString = "SELECT * FROM Diaporamas";
    query.prepare(queryString);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError().text();
    }
    else
    {
        Diaporamas diaporamasInfos;
        while(query.next())
        {
            // Instanciations nécessaires

            InfosDiaporama infosDiapoCourant;

            // Créer le diaporama
            infosDiapoCourant.id = query.value(0).toInt();
            infosDiapoCourant.titre = (query.value(1).toString()).toStdString(); // Conversion directe
            infosDiapoCourant.vitesseDefilement = query.value(2).toInt();

            // Ajouter les infos dans le vecteur
            diaporamasInfos.push_back(infosDiapoCourant);
        }

        // Retourner les informations des diaporamas
        return diaporamasInfos;
    }
}

void Database::recupereImageDiapo(unsigned int numDiapo)
{
    QSqlQuery query(_mydb);
    QString queryString = "SELECT D.uriPhoto, D.titrePhoto, F.nomFamille, DDD.rang, Dia.vitesseDefilement "
                          "FROM Diapos D "
                          "JOIN DiaposDansDiaporama DDD on DDD.idDiapo = D.idphoto "
                          "JOIN Familles F on F.idFamille = D.idFam "
                          "JOIN Diaporamas Dia on Dia.idDiaporama = DDD.idDiaporama"
                          "WHERE DDD.idDiaporama = :idDiaporama "
                          "ORDER BY DDD.rang;";
    query.prepare(queryString);
    query.bindValue(":idDiaporama", numDiapo);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError().text();
    } else {
        Diaporama* diapoCharge = new Diaporama();
        diapoCharge->setVitesseDefilement(query.value(4).toInt()); // Mettre la vitese de défilement au diapo
        while (query.next()) {
            QString uriPhoto = query.value(0).toString();
            QString titrePhoto = query.value(1).toString();
            QString nomFamille = query.value(2).toString();
            int rang = query.value(3).toInt();


            ImageDansDiaporama* imageEnCharge = new ImageDansDiaporama(rang, nomFamille.toStdString(), titrePhoto.toStdString(), uriPhoto.toStdString());
            diapoCharge->ajouterImageEnFin(imageEnCharge);
        }
    }
}
