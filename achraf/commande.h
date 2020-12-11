#ifndef COMMANDE_H

#define COMMANDE_H

#include<QString>

#include <QtSql/QSqlQueryModel>

class commande
{
    QString num,nom , code,d;

 public:
    commande();
    commande(QString ,QString,QString,QString);


    bool ajouter();
        QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier(QString, QString, QString,QString);
        ~ commande(){}
};



#endif // COMMANDE_H
