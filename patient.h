#ifndef PATIENT_H
#define PATIENT_H
#include<QString>
#include "connexion.h"
#include <QSqlQuery>
#include <QSqlQueryModel>




class patient
{
private:
    QString nom,prenom,sexe,adresse;
    int num;

public:
    patient();
    patient(QString nom,QString prenom,QString sexe,int num,int numtel,QString adresse);



    void setnom(QString nom){this->nom=nom;}
    QString getnom(){return this->nom;}
    void setprenom(QString prenom){this->prenom=prenom;}
    QString getprenom(){return this->prenom;}
    void setsexe(QString sexe){this->sexe=sexe;}
    QString getsexe(){return this->sexe;}
    void setnum(int num){this->num=num;}
    int getnum(){return this->num;}
    void setnumtel(int numtel){this->numtel=numtel;}
    int getnumtel(){return this->numtel;}
    void setadresse(QString adresse){this->adresse=adresse;}
    QString getadresse(){return this->adresse;}


    bool ajouter();
    bool modifier(QString nom,QString prenom,QString sexe,int num,int numtel,QString adresse);
    bool supprimer(int numtel);
    QSqlQueryModel * afficher();
    QSqlQueryModel * recherche(const QString numtel);
    //QSqlQueryModel * trier(const QString nom);
    bool existance (QString num);
    QSqlQuery getQuery();

private :
    connexion cnx;
    int numtel;

};




#endif // PATIENT_H
