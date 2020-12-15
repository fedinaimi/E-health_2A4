#include "commande.h"
#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QtSql/QSqlQueryModel>



commande::commande()
{

}
bool commande::ajouter()
{
    QSqlQuery query;


        query.prepare("INSERT INTO CMD (NUM, NOM, CODE,D) " "VALUES (:num, :nom, :code, :d)");
        query.bindValue(":num", num);
        query.bindValue(":nom", nom);
        query.bindValue(":code", code);
        query.bindValue(":d", d);

        return query.exec();
}
QSqlQueryModel * commande::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from CMD ");


        model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("CODE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("D"));

        model->setQuery("SELECT NUM, NOM, CODE,D FROM CMD ORDER BY D ");
        return model;

}
bool commande::supprimer(QString code)
{
    QSqlQuery query;
    query.prepare("Delete from CMD where CODE= :code ");
    query.bindValue(":code",code);
    return query.exec();
}

bool commande::modifier(QString num, QString nom, QString code, QString d )
{

    QSqlQuery query;
    query.prepare("update cmd set num = '"+num+"' , nom = '"+nom+"',d = '"+d+"'  where code = '"+code+"' ");
          return query.exec();
}


QSqlQueryModel * commande::recherche(QString code)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("SELECT * FROM CMD WHERE CODE LIKE '%"+code+"%'");
        model->query().bindValue(":code",code);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("CODE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("D"));

        return model;
}

