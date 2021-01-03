#ifndef MEDICAMENT_H
#define MEDICAMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>



class medicament
{
private:
    QString num ;
    QString nom ;
     QString prix ;
public:
    medicament() ;
   medicament (QString num,QString nom , QString prix){
            this->num=num;
            this->nom=nom;
            this->prix=prix;
            }
    void setnum(QString num){this->num=num;}
       QString getnum(){return this->num;}
       void setnom(QString nom){this->nom=nom;}
          QString getnom(){return this->nom;}
          void setprix(QString prix){this->prix=prix;}
             QString getprix(){return this->prix;}

           bool ajouter();
              bool modifier(QString num);
              bool supprimer(QString num);
              QSqlQueryModel * afficher();
              QSqlQueryModel * recherche(QString num);


};









#endif // MEDICAMENT_H
