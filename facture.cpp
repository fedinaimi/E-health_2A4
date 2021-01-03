#include "facture.h"

facture::facture()
{

}



bool facture::ajouter()
{
    QSqlQuery query;

        query.prepare("INSERT INTO FACTURE(NUM,SOLDE) " "VALUES (:num,:solde)");
        query.bindValue(":num",num);

        query.bindValue(":solde", solde);

        return query.exec();
}
QSqlQueryModel * facture::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();


           model->setQuery("select * from FACTURE ");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("SOLDE"));
        return model;
}
bool facture::supprimer(QString num)
{
    QSqlQuery query;
    query.prepare("Delete from FACTURE where NUM = :num ");
    query.bindValue(":num",num);
    return query.exec();
}
bool facture::modifier(QString num)
{

        QSqlQuery query;




        query.prepare("UPDATE FACTURE SET   SOLDE = :solde  WHERE NUM = :num " );
        query.bindValue(":solde",solde );


        query.bindValue(":num", num);

        return query.exec();
}
QSqlQueryModel *facture::recherche(QString num)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("SELECT * FROM FACTURE WHERE NUM LIKE '%"+num+"%'");
        model->query().bindValue(":type",type);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));

        model->setHeaderData(1, Qt::Horizontal, QObject::tr("SOLDE"));

        return model;
}

