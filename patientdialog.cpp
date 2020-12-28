#include "patientdialog.h"
#include "ui_patientdialog.h"
#include "patient.h"
#include "wwindow.h"
#include <QDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QString>
#include <QApplication>
#include <QLineEdit>
#include <QFile>
#include <QTextEdit>
#include <QTextStream>
#include <QFileDialog>

PatientDialog::PatientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientDialog)
{
    ui->setupUi(this);
}

PatientDialog::~PatientDialog()
{
    delete ui;
}

void PatientDialog::on_pushButton_clicked()
{
    QString nom;QString prenom;QString sexe;int num;int numtel;QString adresse;

    nom=ui->lineEdit->text();
    prenom=ui->lineEdit_2->text();
    sexe=ui->lineEdit_3->text();
    num=ui->lineEdit_4->text().toInt();
    numtel=ui->lineEdit_5->text().toInt();
    adresse=ui->lineEdit_6->text();




     patient p(nom,prenom,sexe,num,numtel,adresse);
    bool test= p.modifier(nom,prenom,sexe,num,numtel,adresse);

    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("Modifier un   PATIENT"),
                          QObject::tr("  PRODUIT Modifié.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
          ui->tableView->setModel(ptn.afficher());//refresh
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un   PATIENT"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }

}
