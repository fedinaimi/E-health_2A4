#ifndef UTILISATEUR_H
#define UTILISATEUR_H
#include<QString>
#include <QtSql/QSqlQueryModel>

class utilisateur
{
    QString login,type,mdp;

 public:
    utilisateur();
    utilisateur(QString ,QString,QString);


    bool ajouter();
    bool testlogin(QString login);
        QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier(QString, QString, QString);
        ~ utilisateur(){}
int calculertype(QString type);
};

#endif // UTILISATEUR_H
