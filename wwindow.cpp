#include "wwindow.h"
#include "ui_wwindow.h"
#include "facture.h"
#include "patient.h"
#include <QDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QString>
#include <QApplication>
#include <QLineEdit>


WWindow::WWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WWindow)
{
    ui->setupUi(this);
}

WWindow::~WWindow()
{
    delete ui;
}
void WWindow::refresh(){
    ui->tableView->setModel(fct.afficher());
                       }


void WWindow::on_pushButton_clicked()
{
    QString num=ui->lineEdit->text();
    facture f ( num);
    bool test = f.ajouter();
    if (test){
        ui->tableView->setModel(fct.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajouter une facture"),
                                 QObject::tr("facture ajouté.\n"
                                             "click cancel."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("ajouter une facture"),
                                 QObject::tr("erreur\n"
                                             "click cancel."), QMessageBox::Cancel);









}

void WWindow::on_pushButton_7_clicked()
{

    QString num = ui->lineEdit->text();
            bool test=fct.supprimer(num);
            if(test)
            {ui->tableView->setModel(fct.afficher());//refresh
                /*QMessageBox::information(nullptr, QObject::tr("Supprimer une facture"),
                            QObject::tr("facture supprimé.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);*/

            }
            else
            {QMessageBox::critical(nullptr, QObject::tr("Supprimer une facture"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}



}

void WWindow::on_pushButton_6_clicked()
{

    int reponse =QMessageBox::question(this,"confirmation","vous .?", QMessageBox::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes){


    QString num;
    facture f;
    bool res;
    QModelIndex index;
    QModelIndexList selection = ui->tableView->selectionModel()->selectedRows();

    for(int i=0;i<selection.count();i++){

        index=selection.at(i);
        num=QVariant(ui->tableView->model()->index(index.row(),0).data()).toString();
        res = f.modifier(num);
        if (res == QDialog::Accepted)
        {
            ui->tableView->setModel(fct.afficher());
        }

        }
    }
    else if (reponse == QMessageBox::No)
    {
        QMessageBox::critical(this,"annulation","a ete annuler!");
    }
    refresh();





}


void WWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    ui->tableView->setModel(fct.recherche(arg1));
}



void WWindow::on_pushButton_4_clicked()
{

    ui->tableView->setModel(fct.trier(ui->comboBox_4->currentText()));
}



void WWindow::on_pushButton_15_clicked()
{
    QString nom=ui->lineEdit_3->text();
    QString prenom=ui->lineEdit_4->text();
    QString sexe=ui->lineEdit_5->text();
    int num=ui->lineEdit_6->text().toInt();
    int numtel=ui->lineEdit_7->text().toInt();
    QString adresse=ui->lineEdit_8->text();
    patient p ( nom,prenom,sexe,num,numtel,adresse);
    bool test = p.ajouter();
    if (test){
        ui->tableView_2->setModel(ptn.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajouter un patient"),
                                 QObject::tr("patient ajouté.\n"
                                             "click cancel."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("ajouter un patient"),
                                 QObject::tr("erreur\n"
                                             "click cancel."), QMessageBox::Cancel);









}

void WWindow::on_pushButton_13_clicked()
{
    QString nom=ui->lineEdit_3->text();
    QString prenom=ui->lineEdit_4->text();
    QString sexe=ui->lineEdit_5->text();
    int num=ui->lineEdit_6->text().toInt();
    int numtel=ui->lineEdit_7->text().toInt();
    QString adresse=ui->lineEdit_8->text();
    patient p ( nom,prenom,sexe,num,numtel,adresse);
    bool test = p.ajouter();
            if(test)
            {ui->tableView_2->setModel(ptn.afficher());//refresh
                /*QMessageBox::information(nullptr, QObject::tr("Supprimer une facture"),
                            QObject::tr("facture supprimé.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);*/

            }
            else
            {QMessageBox::critical(nullptr, QObject::tr("Supprimer une facture"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}

}

void WWindow::on_pushButton_12_clicked()
{

}

void WWindow::on_pushButton_16_clicked()
{

}

void WWindow::on_pushButton_10_clicked()
{

}
