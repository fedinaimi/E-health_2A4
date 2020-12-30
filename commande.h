#ifndef COMMANDE_H

#define COMMANDE_H

#include<QString>

#include <QtSql/QSqlQueryModel>

class commande
{
private:
    QString num,nom,code,d;

public:
    commande();
   commande(QString num,QString nom,QString code,QString d){
        this->num=num;
        this->nom=nom;
        this->code=code;
        this->d=d;

    }
    void setnum(QString num){this->num=num;}
    QString getnum(){return this->num;}
    void setnom(QString nom){this->nom=nom;}
    QString getnom(){return this->nom;}
    void setcode(QString code){this->code=code;}
    QString getcode(){return this->code;}
    void setd(QString d){this->d=d;}
    QString getd(){return this->d;}


    bool ajouter();
  bool modifier(QString, QString, QString,QString);
    bool supprimer(QString code);
    QSqlQueryModel * afficher();
    QSqlQueryModel * recherche(QString code);
};



#endif // COMMANDE_H
