#include "rendezvous.h"

rendezvous::rendezvous()
{

}
bool rendezvous::ajouter()
{
    QSqlQuery query;

        query.prepare("INSERT INTO RENDEZVOUS1(CODE,DATE1) " "VALUES (:code,:date)");
        query.bindValue(":code",code);

        query.bindValue(":date", date);

        return query.exec();
}
QSqlQueryModel * rendezvous::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from RENDEZVOUS1 ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE1"));
        return model;
}
bool rendezvous::supprimer(QString code)
{
    QSqlQuery query;
    query.prepare("Delete from RENDEZVOUS1 where CODE = :code ");
    query.bindValue(":code",code);
    return query.exec();
}
bool rendezvous::modifier(QString code )
{

        QSqlQuery query;




        query.prepare("UPDATE RENDEZVOUS1 SET   DATE1 = :date  WHERE  CODE= :code " );

         query.bindValue(":code", code);
        query.bindValue(":date", date);





        return query.exec();
}
QSqlQueryModel *rendezvous::recherche(QString code)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("SELECT * FROM RENDEZVOUS1 WHERE CODE LIKE '%"+code+"%'");
        model->query().bindValue(":CODE",code);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));

        model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE1"));

        return model;
}
