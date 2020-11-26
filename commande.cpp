#include "commande.h"
#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QtSql/QSqlQueryModel>


commande::commande()
{
    num="";  nom=""; code="",d="";
}

commande::commande(QString num,  QString nom,  QString code,QString d)

{
this->num=num;
this->nom=nom;
this->code=code;
this->d=d;
}

bool commande::ajouter()
{



            QSqlQuery query;
            query.prepare("insert into cmd (num ,nom,code,d)"
                          " values(:num,:nom,:code,:d) ");
           query.bindValue(":num", num);
          query.bindValue(":nom", nom);
          query.bindValue(":code",code);
          query.bindValue(":d",d);


          return query.exec();
}

QSqlQueryModel * commande::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
          model->setQuery("select * from cmd");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("code"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("d"));

          return model;

}

bool commande::supprimer(QString code)
{
QSqlQuery query;
QString res3= code;
query.prepare("Delete from cmd where code =?");
query.addBindValue(res3);
return    query.exec();
}

bool commande::modifier(QString num, QString nom, QString code, QString d )
{

    QSqlQuery query;
    query.prepare("update cmd set num = '"+num+"' , nom = '"+nom+"',d = '"+d+"'  where code = '"+code+"' ");
          return query.exec();
}




