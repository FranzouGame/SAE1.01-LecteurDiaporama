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

        /*** Cette procédure est à décommenter pour la modification de la base,
         * Nous l'avons ommentée puisque notre base était déjà modifiée, et c'était donc inutile de la re-modifier.***/

        modifTitresEtChemins();
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
    bool cheminComplet = false;
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
        // Mettre la vitesse de défilement au diapo
        vitesseDefilement = query.value(4).toInt();

        // Vérifier le début des chemins pour simplifier la suite
        if(query.value(0).toString().startsWith(":/imagesDur")) {
            cheminComplet = true;
        }

        query.previous(); // Revenir à la première ligne pour le traitement suivant
    }

    diapoCharge->setVitesseDefilement(vitesseDefilement);

    while (query.next()) {
        QString uriPhoto;
        // Vérifier si le début de l'url est celui du chemin absolu ou relatif
        if(cheminComplet) {
            uriPhoto = query.value(0).toString();
        } else {
            uriPhoto = ":/imagesDur" + query.value(0).toString();
        }
        // Récupérer les autres données
        QString titrePhoto = query.value(1).toString();
        QString nomFamille = query.value(2).toString();
        int rang = query.value(3).toInt();

        ImageDansDiaporama* imageEnCharge = new ImageDansDiaporama(rang, nomFamille.toStdString(), titrePhoto.toStdString(), uriPhoto.toStdString());
        diapoCharge->ajouterImageEnFin(imageEnCharge);
    }

    return diapoCharge; // Retourner le diaporama chargé
}
void Database::modifierVitesseDfl(unsigned int idDiapo, unsigned int vitesseAApply)
{

    QSqlQuery query(_mydb);

    QString queryString = "UPDATE Diaporamas SET vitesseDefilement = :vitesse WHERE idDiaporama = :idDiaporama";
    query.prepare(queryString);
    query.bindValue(":idDiaporama", idDiapo);
    query.bindValue(":vitesse", vitesseAApply);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError().text();
    }
    query.exec();
    _mydb.commit();
}

void Database::modifTitresEtChemins()
{
    // Tableau des noms de personnages
    const int taille = 54;
    QString personnages[taille] = {
                                   "Chateau Disney",
                                   "Dalmatiens",
                                   "Alice",
                                   "Bambi",
                                   "Blanche Neige",
                                   "Daisy-Duck",
                                   "La Belle et le clochard",
                                   "Jasmine",
                                   "Donald",
                                   "Angry Donald",
                                   "Mushu",
                                   "Dumbo",
                                   "Fievel",
                                   "Figaro",
                                   "Minnie-Mouse",
                                   "Dingo et son crayon",
                                   "Dingo et sa peinture",
                                   "Riri-Duck",
                                   "Baloo et Mowgli",
                                   "Mickey Mouse",
                                   "Dingo en catastrophe",
                                   "Cendrillon  dans un cadre",
                                   "Minnie à la plage",
                                   "Rafiki",
                                   "Mulan",
                                   "Jiminy Cricket",
                                   "Jock",
                                   "Winnie l'Ourson",
                                   "Porcinet",
                                   "Pinocchio",
                                   "Pluto",
                                   "Pumba",
                                   "Nala",
                                   "Simba",
                                   "Hopper",
                                   "Les chats siamois",
                                   "Ariel et les poissons",
                                   "Stitch",
                                   "Tarzan",
                                   "Tigrou",
                                   "Timon",
                                   "Buzz & Woody",
                                   "Alien",
                                   "Mickey, Dingo & Donald",
                                   "La Belle en robe jaune",
                                   "Cendrillon avec un bouquet de fleurs",
                                   "Cendrillon",
                                   "La Belle avec des fleurs",
                                   "Blanche Neige et ses papillons",
                                   "Aurore avec une rose",
                                   "Ariel",
                                   "Blanche Neige",
                                   "La Belle",
                                   "Aurore"
    };

    // Requête de récup des données
    QSqlQuery requeteRecupDonnees(_mydb);
    QString requeteRecup = "SELECT * FROM diapos ORDER BY uriPhoto";
    requeteRecupDonnees.prepare(requeteRecup);

    // Exécuter la requête
    if (!requeteRecupDonnees.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête de récupération:" << requeteRecupDonnees.lastError().text();
        return;
    }

    // Parcourir les résultats
    while (requeteRecupDonnees.next()) {
        // Récupérer les informations de l'enregistrement courant
        int id = requeteRecupDonnees.value(0).toInt();
        QString chemin = requeteRecupDonnees.value(3).toString();
        if(!chemin.startsWith(":/imagesDur")){
            chemin = QString(":/imagesDur") + requeteRecupDonnees.value(3).toString();
        }
        QString titre = personnages[id - 1]; // Utiliser modulo pour éviter l'indexation hors limites

        // Update la BD avec ces données
        QSqlQuery requeteUpdate(_mydb);
        QString requeteUpdateStr = "UPDATE diapos SET titrePhoto = :titre, uriPhoto = :chemin WHERE idPhoto = :id";
        requeteUpdate.prepare(requeteUpdateStr);

        // Ajouter les paramètres
        requeteUpdate.bindValue(":titre", titre);
        requeteUpdate.bindValue(":chemin", chemin);
        requeteUpdate.bindValue(":id", id);

        // Exécuter la requête d'update
        if (!requeteUpdate.exec()) {
            qDebug() << "Erreur lors de l'exécution de la requête d'update:" << requeteUpdate.lastError().text();
        }
    }

    // Commit les changements
    if (!_mydb.commit()) {
        qDebug() << "Erreur lors du commit:" << _mydb.lastError().text();
    } else {
        qDebug() << "Commit réussi";
    }
}

