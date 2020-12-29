#include "patient.h"
#include <QMessageBox>
#include <QDebug>
#include "connexion.h"
#include <QTextStream>
#include <QTextDocument>




patient::patient()
{
}
patient::patient(QString nom,QString prenom,QString sexe,int num,int numtel,QString adresse){
    this->nom=nom;
    this->prenom=prenom;
    this->sexe=sexe;
    this->num=num;
    this->numtel=numtel;
    this->adresse=adresse;
    this->cnx = connexion();
    this->cnx.ouvrirconnexion();
}

bool patient::ajouter()
{
    QSqlQuery query;

  qDebug() <<"ahla";
bool inserted = false;
if(this->cnx.db.open()){
        query.prepare("INSERT INTO PATIENT (NOM,PRENOM,SEXE,NUM,NUMTEL,ADRESSE) " "VALUES (:nom,:prenom,:sexe,:num,:numtel,:adresse)");

        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);
        query.bindValue(":sexe", sexe);
        query.bindValue(":num", num);
        query.bindValue(":numtel", numtel);
        query.bindValue(":adresse", adresse);

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
QSqlQueryModel * patient::afficher()
{ QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from PATIENT ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("SEXE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUM"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUMTEL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));

    model->setQuery("select * from PATIENT order by NUMTEL ");

     model->setQuery("SELECT NOM, PRENOM, SEXE, NUM, NUMTEL, ADRESSE FROM PATIENT ORDER BY NUMTEL ");
    return model;

}
bool patient::supprimer(int numtel)
{
    QSqlQuery query(this->cnx.db.database());
    int res=numtel;

    query.prepare("Delete from PATIENT where NUMTEL= numtel ");

    query.bindValue(":numtel",res);

    return query.exec();
}

bool patient::modifier(QString nom,QString prenom,QString sexe,int num,int numtel,QString adresse)
{

    QSqlQuery query(this->cnx.db.database());
    int res=numtel;


    query.prepare("Update FACTURE set   NOM = :nom, PRENOM = :prenom, SEXE = :sexe, NUM = :num, NUMTEL = :numtel, ADRESSE = :adresse, where NUMTEL = :numtel ") ;

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":sexe", sexe);
    query.bindValue(":num", num);
    query.bindValue(":numtel", res);
    query.bindValue(":adresse", adresse);


    return query.exec();



}
QSqlQuery patient::getQuery(){
    return QSqlQuery(this->cnx.db.database());
}


QSqlQueryModel *patient ::recherche(QString numtel)
{
    QSqlQueryModel * model= new QSqlQueryModel();

           model->setQuery("SELECT * FROM PATIENT WHERE NUMTEL LIKE '%"+numtel+"%'");
           model->query().bindValue(":numtel",numtel);
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
                   model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
                   model->setHeaderData(2, Qt::Horizontal, QObject::tr("SEXE"));
                   model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUM"));
                   model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUMTEL"));
                   model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));
    return model;
}
bool patient::existance(QString num)
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
