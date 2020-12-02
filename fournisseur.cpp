#include "fournisseur.h"

FOURNISSEUR::FOURNISSEUR()
{

}
bool FOURNISSEUR::ajouter()
{
    QSqlQuery query;


        query.prepare("INSERT INTO FOURNISSEUR (NOM, PRENOM, TELF,ID,FACTURE) " "VALUES (:nom, :prenom, :telf, :id, :facture)");
        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);
        query.bindValue(":telf", telf);
        query.bindValue(":id", id);
        query.bindValue(":facture", facture);
        return query.exec();
}
QSqlQueryModel * FOURNISSEUR::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from FOURNISSEUR ");


        model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("TELF"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("FACTURE"));
        model->setQuery("SELECT NOM, PRENOM, TELF,ID,FACTURE FROM FOURNISSEUR ORDER BY FACTURE ");
        return model;

}
bool FOURNISSEUR::supprimer(QString id)
{
    QSqlQuery query;
    query.prepare("Delete from FOURNISSEUR where ID = :id ");
    query.bindValue(":id",id);
    return query.exec();
}
bool FOURNISSEUR::modifier(QString id)
{

        QSqlQuery query;




        query.prepare("UPDATE FOURNISSEUR SET   FACTURE = :facture WHERE ID = :id " );

        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);
        query.bindValue(":telf", telf);
        query.bindValue(":id", id);
        query.bindValue(":facture", facture);
        return query.exec();




}
QSqlQueryModel * FOURNISSEUR::recherche(QString id)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("SELECT * FROM FOURNISSEUR WHERE ID LIKE '%"+id+"%'");
        model->query().bindValue(":id",id);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("TELF"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("FACTURE"));
        return model;
}

