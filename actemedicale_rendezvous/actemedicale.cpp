#include "actemedicale.h"

actemedicale::actemedicale()
{

}
bool actemedicale::ajouter()
{
    QSqlQuery query;
        QString pri= QString::number(prix);
        query.prepare("INSERT INTO ACTEMEDICALE(TYPE,PRIX) " "VALUES (:type,:prix)");
        query.bindValue(":type",type);

        query.bindValue(":prix", pri);

        return query.exec();
}
QSqlQueryModel * actemedicale::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      //  model->setQuery("select * from ACTEMEDICALE ");//
           model->setQuery("select * from ACTEMEDICALE ORDER BY  PRIX ");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRIX"));
        return model;
}
bool actemedicale::supprimer(QString type)
{
    QSqlQuery query;
    query.prepare("Delete from ACTEMEDICALE where TYPE = :type ");
    query.bindValue(":type",type);
    return query.exec();
}
bool actemedicale::modifier(QString type)
{

        QSqlQuery query;
        QString pri= QString::number(prix);



        query.prepare("UPDATE ACTEMEDICALE SET   PRIX = :prix  WHERE TYPE = :type " );
        query.bindValue(":type", type);


        query.bindValue(":prix", pri);

        return query.exec();
}
QSqlQueryModel *actemedicale::recherche(QString type)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("SELECT * FROM ACTEMEDICALE WHERE TYPE LIKE '%"+type+"%'");
        model->query().bindValue(":type",type);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("type"));

        model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));

        return model;
}
