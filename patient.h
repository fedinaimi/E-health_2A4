#ifndef PATIENT_H
#define PATIENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class patient
{
private:
    QString nom,prenom,sexe,num,numtel,adresse;

public:
    patient();
   patient(QString nom,QString prenom,QString sexe,QString num,QString numtel,QString adresse){

        this->nom=nom;
        this->prenom=prenom;
       this->sexe=sexe;
       this->num=num;
       this->numtel=numtel;
       this->adresse=adresse;


    }

    void setnum(QString num){this->num=num;}
    QString getnum(){return this->num;}
    void setnom(QString nom){this->nom=nom;}
    QString getnom(){return this->nom;}
    void setcode(QString prenom){this->prenom=prenom;}
    QString getprenom(){return this->prenom;}
    void setnumtel(QString numtel){this->numtel=numtel;}
    QString getadresse(){return this->adresse;}
    void setadresse(QString adresse){this->adresse=adresse;}
    QString getnumtel(){return this->numtel;}
    void setsexe(QString sexe){this->sexe=sexe;}
    QString getsexe(){return this->sexe;}


    bool ajouter();
  bool modifier(QString num);
    bool supprimer(QString num);
    QSqlQueryModel * afficher();
    QSqlQueryModel * recherche(QString num);

};






#endif // PATIENT_H
