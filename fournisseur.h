#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include<QString>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QPainter>
#include <QGraphicsItem>
#include <QtCharts>
#include <QBarSeries>
#include <QBarSet>


class FOURNISSEUR
{
private:
    QString nom,prenom,telf,id,facture;


public:
    FOURNISSEUR();
   FOURNISSEUR(QString nom,QString prenom ,QString telf ,QString id,QString facture){
        this->nom = nom ;
        this->prenom = prenom;
       this->telf=telf;
        this->id=id;
       this->facture=facture ;


    }
    void setnom(QString nom){this->nom=nom;}
    QString getnom(){return this->nom;}
    void setprenom(QString prenom){this->prenom=prenom;}
    QString getprenom(){return this->prenom;}
    void settelf(QString telf){this->telf=telf;}
    QString gettelf(){return this->telf;}
    void setid(QString id){this->id=id;}
    QString getid(){return this->id;}
    void setfacture(QString facture){this->facture=facture;}
    QString getfacture(){return this->facture;}
    bool ajouter();
    bool modifier(QString id);
    bool supprimer(QString id);
    void stat_grs();
    QSqlQueryModel * afficher();
    QSqlQueryModel * recherche(QString id);
};


#endif // FOURNISSEUR_H
