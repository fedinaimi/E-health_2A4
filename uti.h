#ifndef UTIL_H
#define UTIL_H
#include<QString>
#include <QtSql/QSqlQueryModel>

class util
{
    QString login,type,mdp;

 public:
    util();
    util(QString ,QString,QString);


    bool ajouter();
    bool testlogin(QString login);
        QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier(QString, QString, QString);
        ~ util(){}
int calculertype(QString type);
};

#endif // UTILISATEUR_H
