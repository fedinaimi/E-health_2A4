#include "produit.h"

PRODUIT::PRODUIT()
{

}
bool PRODUIT::ajouter()
{
    QSqlQuery query;
        QString pri= QString::number(prix);
        QString sto= QString::number(stock);
        query.prepare("INSERT INTO PRODUIT (NOM, REF, FOURNISSEUR,PRIX,STOCK) " "VALUES (:nom, :ref, :fournisseur, :prix, :stock)");
        query.bindValue(":nom", nom);
        query.bindValue(":ref", ref);
        query.bindValue(":fournisseur", fournisseur);
        query.bindValue(":prix", pri);
        query.bindValue(":stock", sto);
        return query.exec();
}
QSqlQueryModel * PRODUIT::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from PRODUIT ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("REF"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("FOURNISSEUR"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("STOCK"));
        model->setQuery("SELECT NOM, REF, FOURNISSEUR,PRIX,STOCK FROM PRODUIT ORDER BY STOCK ");//trier
        return model;
}
bool PRODUIT::supprimer(QString ref)
{
    QSqlQuery query;
    query.prepare("Delete from PRODUIT where REF = :ref ");
    query.bindValue(":ref",ref);
    return query.exec();
}
bool PRODUIT::modifier(QString ref)
{

        QSqlQuery query;
        QString pri= QString::number(prix);
        QString sto= QString::number(stock);


        query.prepare("UPDATE PRODUIT SET PRIX = :prix , STOCK = :stock  WHERE REF = :ref ");
        query.bindValue(":nom", nom);
        query.bindValue(":ref", ref);
        query.bindValue(":fournisseur", fournisseur);
        query.bindValue(":prix", pri);
        query.bindValue(":stock", sto);
        return query.exec();


}
QSqlQueryModel * PRODUIT::recherche(QString ref)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("SELECT * FROM PRODUIT WHERE REF LIKE '%"+ref+"%'");
        //model->query().bindValue(":ref",ref);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("REF"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("FOURNISSEUR"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("STOCK"));
        return model;
}
