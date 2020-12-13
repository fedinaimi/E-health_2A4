#include "Medicament.h"

Medicament::Medicament(int numero,QString nom,int prix)
{
    this ->numero=numero;
    this ->nom=nom;
    this ->prix=prix;

}
bool Medicament::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(numero);
     QString res2 = QString::number(prix);
    //prepare() prend la renquéte en paramétre pour la prepare a l'execution
    query.prepare("INSERT INTO medicament (NUMERO, NOM, PRIX) "
                        "VALUES (:numero, :nom, :prix)");
    //creation des variables liées
    query.bindValue(":numero", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prix", prix);

    return query.exec(); //exec() envoie la requéte pour l'exécuter


}
bool Medicament::supprimer(int numero)
{
    QSqlQuery query;
    QString res=QString::number(numero);
    query.prepare("delete from medicament where NUMERO = numero ");
    query.bindValue(":numero",res);
    return query.exec();
}
QSqlQueryModel * Medicament::afficher()
 {QSqlQueryModel * model= new QSqlQueryModel();

 model->setQuery("select * from medicament");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
 model->setQuery("SELECT NUMERO,NOM,PRIX FROM MEDICAMENT ORDER BY NOM ");
     return model;
 }
QSqlQueryModel *Medicament ::recherche(int numero)
{
    QString res= QString::number(numero);
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from MEDICAMENT where NUMERO = '"+res+"'  ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));


    return model;
}
bool Medicament::modifier(int numero)
{

    QSqlQuery Q;
    QString res= QString::number(numero);
    Q.prepare("UPDATE  MEDICAMENT set NOM=:nom,PRIX=:prix where NUMERO=:numero");
    Q.bindValue(":numero", res);
    Q.bindValue(":nom", nom);
    Q.bindValue(":prix", prix);


    return    Q.exec();


}
QSqlQueryModel* Medicament::afficherselonnumero()// triii
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
   QSqlQuery *query=new QSqlQuery;
   query->prepare("select * from MEDICAMENT ORDER BY NUMERO") ;
   query->exec() ;
   model->setQuery(*query) ;



return model;

}
QSqlQueryModel* Medicament::afficherselonnom()// triii
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
   QSqlQuery *query=new QSqlQuery;
   query->prepare("select * from MEDICAMENT ORDER BY NOM") ;
   query->exec() ;
   model->setQuery(*query) ;



return model;

}

QSqlQueryModel* Medicament::afficherselonprix()// triii
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
   QSqlQuery *query=new QSqlQuery;
   query->prepare("select * from MEDICAMENT ORDER BY PRIX") ;
   query->exec() ;
   model->setQuery(*query) ;



return model;

}



