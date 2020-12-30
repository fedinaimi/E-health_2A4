#ifndef ORDONNANCE_H
#define ORDONNANCE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class ordonnance
{
private:
    QString numero ;
    QString date ;
public:
    ordonnance() ;
   ordonnance (QString numero,QString date){
            this->numero=numero;
            this->date=date;
            }
    void setnumero(QString numero){this->numero=numero;}
       QString getnumero(){return this->numero;}
       void setdate(QString date){this->date=date;}
          QString getdate(){return this->date;}

           bool ajouter();
              bool modifier(QString numero);
              bool supprimer(QString numero);
              QSqlQueryModel * afficher();
              QSqlQueryModel * recherche(QString numero);


};

#endif // ORDONNANCE_H
