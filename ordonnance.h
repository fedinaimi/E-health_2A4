#ifndef ORDONNANCE_H
#define ORDONNANCE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class Ordonnance
{
    QString date_ord;
    int numero_ord;
public:
    Ordonnance(){};
    Ordonnance(int,QString);
    int getNumero_ord(){return numero_ord;}
    QString getDate_ord(){return date_ord;}


    void setNumero_ord(int nm_ord){numero_ord=nm_ord;}
    void setDate_ord(QString Date_ord){date_ord=Date_ord;}







    //fonctionnalités de base relative a l'entité odonnance
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
     bool modifier(int);
      QString  apercu(QString numero);
};

#endif // ORDONNANCE_H
