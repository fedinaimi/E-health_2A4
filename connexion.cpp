#include "connexion.h"




connexion::connexion()
{}
bool connexion::ouvrirconnexion()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("source_Project2A");
    db.setUserName("fedi");
    db.setPassword("fedi");
    if(db.open())
        test=true;
    return test;

}
void connexion::fermerconnexion()
{db.close();}



