#include "medicament.h"
#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QtSql/QSqlQueryModel>





medicament::medicament()
{

}
bool medicament::ajouter()
{
    QSqlQuery query;

        query.prepare("INSERT INTO MEDICAMENT(NUM,NOM,PRIX) " "VALUES (:num,:nom,:prix)");
        query.bindValue(":num",num);
        query.bindValue(":nom",nom);

        query.bindValue(":prix", prix);

        return query.exec();
}
QSqlQueryModel * medicament::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("select * from MEDICAMENT ");


        model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
        return model;
}
bool medicament::supprimer(QString num)
{
    QSqlQuery query;
    query.prepare("Delete from MEDICAMENT where NUM =:num ");
    query.bindValue(":num",num);
    return query.exec();
}
bool medicament::modifier(QString num)
{

        QSqlQuery query;




        query.prepare("UPDATE MEDICAMENT SET   PRIX = :prix  WHERE NUM = :num " );
        query.bindValue(":num", num);
        query.bindValue(":nom", nom);



        query.bindValue(":prix", prix);

        return query.exec();
}
QSqlQueryModel *medicament::recherche(QString num)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("SELECT * FROM MEDICAMENT WHERE NUM LIKE '%"+num+"%'");
        model->query().bindValue(":num",num);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));

        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));

        return model;
}


