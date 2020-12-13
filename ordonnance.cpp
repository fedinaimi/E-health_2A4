#include "ordonnance.h"

Ordonnance::Ordonnance(int numero_ord,QString date_ord)
{
     this ->numero_ord=numero_ord;
     this ->date_ord=date_ord;
}
bool Ordonnance::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(numero_ord);

    //prepare() prend la renquéte en paramétre pour la prepare a l'execution
    query.prepare("INSERT INTO ORONNANCE (NUMERO,DATEORD)" "VALUES(:numero, :date)");
    //creation des variables liées
    query.bindValue(":numero",res);
    query.bindValue(":date",date_ord);


    return query.exec(); //exec() envoie la requéte pour l'exécuter


}
bool Ordonnance::supprimer(int numero)
{
    QSqlQuery query;
    QString res=QString::number(numero);
    query.prepare("delete from ordonnance where numero= numero ");
    query.bindValue(":numero",res);
    return query.exec();
}
QSqlQueryModel * Ordonnance::afficher()
 {QSqlQueryModel * model= new QSqlQueryModel();

 model->setQuery("select * from ORDONNANCE");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("dateord"));

     return model;
 }

bool Ordonnance::modifier(int numero_ord)
{

    QSqlQuery Q;
    QString res= QString::number(numero_ord);
    Q.prepare("UPDATE  ORDONNANCE set DATE=:date where NUMERO=:numero_ord");
    Q.bindValue(":numero_ord", res);
    Q.bindValue(":date", date_ord);



    return    Q.exec();


}

QString Ordonnance :: apercu(QString num)
{

        QSqlQuery query ;
        QString numero;
        QString date;
        query.prepare("SELECT * FROM MEDICAMENT WHERE NUMERO =:numero" );
        query.bindValue(":numero", num);
        query.exec();
        if(query.next())
        {
            numero=query.value(0).toString();
            date=query.value(1).toString();


        }
        QString text ;
        text= "ORDONNANCE\n ID de la ORDONNANCE:"+numero+"\n ETAT : "+date;
       return text ;
}
