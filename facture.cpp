#include "facture.h"
#include <QMessageBox>
#include <QDebug>
#include "connexion.h"
#include <QTextStream>
#include <QTextDocument>
#include"secdialog.h"




facture::facture()
{
}
facture::facture(QString num){
    this->num=num;
    this->cnx = connexion();
    this->cnx.ouvrirconnexion();
}

bool facture::ajouter()
{
    QSqlQuery query;

  qDebug() <<"ahla";
bool inserted = false;
if(this->cnx.db.open()){
        query.prepare("INSERT INTO FACTURE (NUM) " "VALUES (:num)");

        query.bindValue(":num", num);
        if (query.exec()){
            inserted =true;

        }
        else qDebug () << "failed";

}
else {
    qDebug() << "not open";

       }
return inserted;
}
QSqlQueryModel * facture::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from FACTURE ");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));
        model->setQuery("select * from FACTURE order by NUM ");

         model->setQuery("SELECT NUM FROM FACTURE ORDER BY NUM ");
        return model;
}
bool facture::supprimer(QString num)
{
    QSqlQuery query(this->cnx.db.database());
    QString res =num;
    query.prepare("Delete from FACTURE where NUM= :num ");
    query.bindValue(":num",res);
    return query.exec();
}
bool facture::modifier(QString num)
{

    QSqlQuery query(this->cnx.db.database());


    query.prepare("UPDATE FACTURE set   NUM=:num WHERE NUM=:num ") ;

    query.bindValue(":num", num);


    return query.exec();



}
QSqlQuery facture::getQuery(){
    return QSqlQuery(this->cnx.db.database());
}


QSqlQueryModel *facture ::recherche(QString num)
{
   QSqlQueryModel * model = new QSqlQueryModel();
   model->setQuery("select * from FACTURE where(NUM LIKE '"+num+"%')");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));
   return model;
}
bool facture::existance(QString num)
{
    QMessageBox msgBox;
    QMessageBox msgBox1;
    bool test=0;
    QSqlQuery query;
    int count=0;

    query.prepare("SELECT * FROM patient WHERE num ?");
    query.addBindValue(num);
    if(query.exec() )
    {
while (query.next())
   {
   count ++;
   }
if(count==1)
   {
    msgBox.setText("num deja existe");
    msgBox.exec();
    test=0;
   }

else if (count<1)
{
    msgBox1.setText("num disponible");
        msgBox1.exec();
        test=1;
}

    }

    return test;
}
QSqlQueryModel *facture::trier(const QString num )
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from FACTURE order by num ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));
    return model;
}
