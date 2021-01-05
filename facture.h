#ifndef FACTURE_H
#define FACTURE_H



#include<QString>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QPainter>
#include <QGraphicsItem>
#include <QtCharts>
#include <QBarSeries>
#include <QBarSet>


class facture
{
private:
    QString num,solde,type;


public:
  facture();
   facture(QString num,QString solde  ){
        this->num = num ;
        this->solde = solde;



    }
    void setnum(QString num){this->num=num;}
    QString getnum(){return this->num;}
    void setsolde(QString solde){this->solde=solde;}
    QString getsolde(){return this->solde;}

    bool ajouter();
    bool modifier(QString num);
    bool supprimer(QString num);
    void stat_grs();
    QSqlQueryModel * afficher();
    QSqlQueryModel * recherche(QString num);
};




#endif // FACTURE_H
