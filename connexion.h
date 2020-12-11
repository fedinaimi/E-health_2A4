#ifndef CONNEXION_H
#define CONNEXION_H

#include <QtSql/QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class connexion
{

public:
    connexion();
    void fermerconnexion();
    bool ouvrirconnexion();
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
};

#endif // CONNEXION_H
