#include "patient.h"

#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QtSql/QSqlQueryModel>




patient::patient()
{

}



bool patient::ajouter()
{

    QSqlQuery query;
            query.prepare("INSERT INTO PATIENT ( NOM,PRENOM,SEXE,NUM,NUMTEL,ADRESSE)" " values(:nom,:prenom,:sexe,:num,:numtel,:adresse) ");
           query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":sexe",sexe);
          query.bindValue(":num", num);
         query.bindValue(":numtel", numtel);
         query.bindValue(":adresse",adresse);

          return query.exec();
}

QSqlQueryModel * patient::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
          model->setQuery("select * from patient");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("sexe"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("num"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("numtel"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));

          return model;

}
bool patient::modifier(QString num)
{

    QSqlQuery query;
    query.prepare("update patient set numtel = '"+numtel+"',adresse = '"+adresse+"'  where num = '"+num+"' ");
          return query.exec();
}



bool patient::supprimer(QString num)
{
QSqlQuery query;

query.prepare("Delete from patient where NUM =:num");
    query.bindValue(":num",num);
return    query.exec();
}
QSqlQueryModel *patient::recherche(QString num)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("SELECT * FROM PATIENT WHERE NUM LIKE '%"+num+"%'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("sexe"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("num"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("numtel"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));

        return model;
}
