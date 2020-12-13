#ifndef MEDICAMENT_H
#define MEDICAMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>




class Medicament
{
    QString nom;
    int numero;
    int prix;
public:
    Medicament(){}
    Medicament(int,QString,int);


        int getNumero(){return numero;}
        QString getNom(){return nom;}
        int getPrix(){return prix;}

        void setNumero(int nm){nom=nm;}
        void setNom(QString Nom){nom=Nom;}
         void setPrix(int Prix){prix=Prix;}

    //fonctionnalités de base relative a l'entité medicament
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel *recherche(int numero);
    bool modifier(int);
      QSqlQueryModel* afficherselonnumero();
      QSqlQueryModel* afficherselonnom();
      QSqlQueryModel* afficherselonprix();
};

#endif // MEDICAMENT_H
