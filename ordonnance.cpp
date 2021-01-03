#include "ordonnance.h"


ordonnance::ordonnance()
{

}
bool ordonnance::ajouter()
{
    QSqlQuery query;
 query.prepare("INSERT INTO ORDONNANCE (NUMERO,DATEORD) " "VALUES (:numero,:date )");
        query.bindValue(":numero", numero );

        query.bindValue(":date", date );

           return query.exec(); //exec() envoie la requéte pour l'exécuter
}
QSqlQueryModel * ordonnance::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      //  model->setQuery("select * from ORDONNANCE ");
           model->setQuery("select * from ORDONNANCE ORDER BY  NUMERO ");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMERO"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATEORD"));
        return model;
}
bool ordonnance::supprimer(QString numero)
{
    QSqlQuery query;
    query.prepare("Delete from ORDONNANCE where NUMERO = :numero ");
    query.bindValue(":numero",numero);
    return query.exec();
}
bool ordonnance::modifier(QString numero)
{

        QSqlQuery query;




        query.prepare("UPDATE ORDONNANCE SET   DATEORD = :date  where NUMERO = :numero " );
        query.bindValue(":numero",numero);


        query.bindValue(":date",date);

        return query.exec();
}
QSqlQueryModel *ordonnance::recherche(QString numero)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("SELECT * FROM ORDONNANCE WHERE NUMERO LIKE '%"+numero+"%'");
        model->query().bindValue(":numero",numero);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));

        model->setHeaderData(1, Qt::Horizontal, QObject::tr("date"));

        return model;
}

