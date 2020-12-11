#include "connexion.h"
#include<QDebug>

connexion::connexion()
{

}

bool connexion::ouvrirconnexion()
{
    db.setDatabaseName("E-health");//inserer le nom de la source de données ODBC
    db.setUserName("youssef1");//inserer nom de l'utilisateur
    db.setPassword("youssef1919");//inserer mot de passe de cet utilisateur
    if (db.open()){
        qDebug () << "connect ..";
        return(true);
    }
    return false;}
void connexion::fermerconnexion()
{
    db.close();
}

