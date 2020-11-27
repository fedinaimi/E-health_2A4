#ifndef PRODUIT_H
#define PRODUIT_H
#include<QString>
#include<QSqlQueryModel>
#include<QSqlQuery>


class PRODUIT
{
private:
    QString nom,ref,fournisseur;
    float prix;
    int stock;
public:
    PRODUIT();
    PRODUIT(QString nom,QString ref,QString fournisseur,float prix,int stock){
        this->nom=nom;
        this->ref=ref;
        this->fournisseur=fournisseur;
        this->prix=prix;
        this->stock=stock;
    }
    void setnom(QString nom){this->nom=nom;}
    QString getnom(){return this->nom;}
    void setref(QString ref){this->ref=ref;}
    QString getref(){return this->ref;}
    void setfournisseur(QString fournisseur){this->fournisseur=fournisseur;}
    QString getfournisseur(){return this->fournisseur;}
    void setprix(float prix){this->prix=prix;}
    float getprix(){return this->prix;}
    void setstock(int stock){this->stock=stock;}
    int getstock(){return this->stock;}
    bool ajouter();
    bool modifier(QString ref);
    bool supprimer(QString ref);
    QSqlQueryModel * afficher();
    QSqlQueryModel * recherche(QString ref);
};

#endif // PRODUIT_H
