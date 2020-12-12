#ifndef FACTURE_H
#define FACTURE_H
#include<QString>
#include "connexion.h"
#include <QSqlQuery>
#include <QSqlQueryModel>


/*aaaaaaaaaaa*/

class facture
{
private:
    QString num;

public:
    facture();
    facture(QString num);



    void setnum(QString num){this->num=num;}
    QString getnum(){return this->num;}


    bool ajouter();
    bool modifier(QString num);
    bool supprimer(QString num);
    QSqlQueryModel * afficher();
    QSqlQueryModel * recherche(const QString num);
    QSqlQueryModel * trier(const QString num);
    bool existance (QString num);
    QSqlQuery getQuery();

private :
    connexion cnx;

};





#endif // FACTURE_H
