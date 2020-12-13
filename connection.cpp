#include "connection.h"
//test
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("e-helth");//inserer le nom de la source de données ODBC
db.setUserName("fedi");//inserer nom de l'utilisateur
db.setPassword("fedi29537066");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
