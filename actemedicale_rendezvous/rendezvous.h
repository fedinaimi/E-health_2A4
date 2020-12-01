#ifndef RENDEZVOUS_H
#define RENDEZVOUS_H
#include<QString>
#include<QSqlQueryModel>
#include<QSqlQuery>


class rendezvous
{
private:
    QString code ;
    QString date ;
public:
    rendezvous();
    rendezvous (QString code,QString date){
            this->code=code;
            this->date=date;
            }
    void setcode(QString code){this->code=code;}
       QString getcode(){return this->code;}
       void setdate(QString date){this->date=date;}
           QString getdate(){return this->date;}
           bool ajouter();
              bool modifier(QString code);
              bool supprimer(QString code);
              QSqlQueryModel * afficher();
              QSqlQueryModel * recherche(QString code);


};

#endif // RENDEZVOUS_H
