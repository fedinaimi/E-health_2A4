#ifndef ACTEMEDICALE_H
#define ACTEMEDICALE_H
#include<QString>
#include<QSqlQueryModel>
#include<QSqlQuery>

class actemedicale
{
private:
    QString type ;
    float prix ;
public:
    actemedicale() ;
    actemedicale (QString type,float prix){
            this->type=type;
            this->prix=prix;
            }
    void settype(QString type){this->type=type;}
       QString gettype(){return this->type;}
       void setprix(float prix){this->prix=prix;}
           float getprix(){return this->prix;}
           bool ajouter();
              bool modifier(QString type);
              bool supprimer(QString type);
              QSqlQueryModel * afficher();
              QSqlQueryModel * recherche(QString type);


};

#endif // ACTEMEDICALE_H
