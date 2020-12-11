#include "utilisateur.h"
#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QtSql/QSqlQueryModel>



utilisateur::utilisateur()
{
    login="";  type=""; mdp="";
}


utilisateur::utilisateur(QString login,  QString type,  QString mdp)
{

this->login=login;
this->type=type;
this->mdp=mdp;
}

bool utilisateur::ajouter()
{

    QSqlQuery query;
            query.prepare("insert into utilisateur (login ,type,mdp)"
                          " values(:login,:type,:mdp) ");
           query.bindValue(":login", login);
          query.bindValue(":type", type);
          query.bindValue(":mdp",mdp);

          return query.exec();
}
bool utilisateur::testlogin(QString login)
{
    QSqlQuery querytest;
    querytest.prepare("select * from utilisateur where login=:login");
    querytest.bindValue(":login", login);
    querytest.exec();
    int count=0;
    while(querytest.next())
    {
        count++;
    }
    if(count>0){
        return true;
    }
    else{
        return false;
    }
}

QSqlQueryModel * utilisateur::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
          model->setQuery("select * from utilisateur");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("login"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("mdp"));

          return model;

}
bool utilisateur::modifier(QString login, QString type, QString mdp )
{

    QSqlQuery query;
    query.prepare("update utilisateur set  type = '"+type+"',mdp = '"+mdp+"'  where login = '"+login+"' ");
          return query.exec();
}



bool utilisateur::supprimer(QString login)
{
QSqlQuery query;
QString res3= login;
query.prepare("Delete from utilisateur where login =?");
query.addBindValue(res3);
return    query.exec();
}


int utilisateur::calculertype(QString type){
    QSqlQuery query;
    query.prepare("select * from utilisateur where type=:type");
    query.bindValue(":type",type);
    query.exec();
    int total=0;
    while(query.next()){
        total++;
    }


    return total;
 }


