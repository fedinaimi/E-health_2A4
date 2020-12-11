#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "facture.h"
#include "patient.h"
#include <QDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QString>
#include <QApplication>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
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

void MainWindow::on_pushButton_2_clicked()
{
close() ;
}

void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox msgBox ;
    QSqlQueryModel *model = new QSqlQueryModel();
        QString num;
        num = ui->lineEdit_5->text();
        model->setQuery("Select * from facture where num = '"+num+"' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
        ui->tableView->setModel(model);
        ui->tableView->show();
        msgBox.setText("facture trouvé.");
        msgBox.exec();
        ui->lineEdit_5->clear();
        QSqlQuery qry;
        qry.prepare("select * from facture where code='"+num+"'  " );

        if(qry.exec())
        {
            while(qry.next())
            {
                ui->lineEdit->setText(qry.value(0).toString());

    }}
}

void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox msgBox ;

    QSqlQueryModel *model = new QSqlQueryModel();
             model->setQuery("select * from facture order by code ASC");
             model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));

             ui->tableView->show();
             msgBox.setText("Tri avec succés.");
             msgBox.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
 ui->tableView_2->setModel(fct.afficher());
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->tableView->setModel(fct.afficher());
               ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
               QString num=ui->lineEdit->text();

               facture f ;
               bool test=f.modifier(num);
               QMessageBox msBox;
               if(test)
               {
                   ui->tableView->setModel(f.afficher());
                   ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                   msBox.setText("modification reussite");
                   msBox.exec();
               }
               else
               {
                   msBox.setText("ERREUR");
                   msBox.exec();
               }
               ui->lineEdit->clear();

}

void MainWindow::on_pushButton_7_clicked()
{
    QMessageBox msgBox ;
    QString num = ui->lineEdit_3->text();
            bool test=fct.supprimer(num);
            if(test)
            {ui->tableView->setModel(fct.afficher());//refresh
                /*QMessageBox::information(nullptr, QObject::tr("Supprimer une facture"),
                            QObject::tr("facture supprimé.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);*/
                msgBox.setText("facture supprimé.");
                msgBox.exec();
            }
            else
            {QMessageBox::critical(nullptr, QObject::tr("Supprimer une facture"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
            ui->lineEdit->clear();

}

void MainWindow::on_pushButton_8_clicked()
{

}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
       QSqlQuery qry;
           qry.prepare("select * from patient where num='"+val+"'  " );

           if(qry.exec())
           {
               while(qry.next())
               {
                   ui->lineEdit->setText(qry.value(0).toString());

}
}
}



void MainWindow::on_pushButton_15_clicked()
{
    QString nom=ui->lineEdit->text();
                   QString prenom=ui->lineEdit_2->text();
                   QString sexe=ui->lineEdit_3->text();
                   QString num=ui->lineEdit_4->text();
                   QString numtel=ui->lineEdit_5->text();
                   QString adresse=ui->lineEdit_6->text();


                   patient p(nom,prenom,sexe,num,numtel,adresse);
                   bool test=p.ajouter();
                   ui->tableView->setModel(ptn.afficher());
                   QMessageBox msgBox;
                   if (test)
                   {
                       ui->tableView->setModel(ptn.afficher());
                       msgBox.setText("Ajout avec succés.");
                       msgBox.exec();
                   }


                   ui->lineEdit->clear();
                   ui->lineEdit_2->clear();
                   ui->lineEdit_3->clear();
                   ui->lineEdit_4->clear();
                   ui->lineEdit_5->clear();
                   ui->lineEdit_6->clear();
}

void MainWindow::on_pushButton_16_clicked()
{
    close() ;
}

void MainWindow::on_pushButton_9_clicked()
{
    QMessageBox msgBox ;
    QSqlQueryModel *model = new QSqlQueryModel();
        QString num;
        num = ui->lineEdit_5->text();
        model->setQuery("Select * from patient where num = '"+num+"' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("sexe"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("num"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("numtel"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));
        ui->tableView->setModel(model);
        ui->tableView->show();
        msgBox.setText("patient trouvé.");
        msgBox.exec();
        ui->lineEdit_5->clear();
        QSqlQuery qry;
        qry.prepare("select * from patient where num='"+num+"'  " );

        if(qry.exec())
        {
            while(qry.next())
            {
                ui->lineEdit->setText(qry.value(0).toString());
                ui->lineEdit_2->setText(qry.value(1).toString());
                ui->lineEdit_3->setText(qry.value(2).toString());
                ui->lineEdit_4->setText(qry.value(3).toString());
                ui->lineEdit_5->setText(qry.value(4).toString());
                ui->lineEdit_6->setText(qry.value(5).toString());
    }}
}

void MainWindow::on_pushButton_10_clicked()
{
    QMessageBox msgBox ;

    QSqlQueryModel *model = new QSqlQueryModel();
             model->setQuery("select * from patient order by adresse ASC");
             model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
             model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
             model->setHeaderData(2, Qt::Horizontal, QObject::tr("sexe"));
             model->setHeaderData(3, Qt::Horizontal, QObject::tr("num"));
             model->setHeaderData(4, Qt::Horizontal, QObject::tr("numtel"));
             model->setHeaderData(5, Qt::Horizontal, QObject::tr("sexe"));
             ui->tableView->setModel(model);
             ui->tableView->show();
             msgBox.setText("Tri avec succés.");
             msgBox.exec();
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->tableView_2->setModel(ptn.afficher());
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->tableView->setModel(ptn.afficher());
           ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
           QString nom=ui->lineEdit->text();
           QString prenom=ui->lineEdit_2->text();
           QString sexe=ui->lineEdit_3->text();
           QString num=ui->lineEdit_4->text();
           QString numtel=ui->lineEdit_5->text();
           QString adresse=ui->lineEdit_6->text();

           patient p ;
           bool test=p.modifier(nom,prenom,sexe,num,numtel,adresse);
           QMessageBox msBox;
           if(test)
           {
               ui->tableView->setModel(p.afficher());
               ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
               msBox.setText("modification reussite");
               msBox.exec();
           }
           else
           {
               msBox.setText("ERREUR");
               msBox.exec();
           }
           ui->lineEdit->clear();
           ui->lineEdit_2->clear();
           ui->lineEdit_3->clear();
           ui->lineEdit_4->clear();
           ui->lineEdit_5->clear();
           ui->lineEdit_6->clear();
}

void MainWindow::on_pushButton_13_clicked()
{
    QMessageBox msgBox ;
    QString num = ui->lineEdit_3->text();
            bool test=ptn.supprimer(nom,prenom,sexe,num,numtel,adresse);
            if(test)
            {ui->tableView->setModel(ptn.afficher());//refresh
                /*QMessageBox::information(nullptr, QObject::tr("Supprimer un patient"),
                            QObject::tr("patient supprimé.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);*/
                msgBox.setText("patient supprimé.");
                msgBox.exec();
            }
            else
            {QMessageBox::critical(nullptr, QObject::tr("Supprimer un patient"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
            ui->lineEdit_5->clear();
            ui->lineEdit_6->clear();
}

void MainWindow::on_pushButton_14_clicked()
{

}


void MainWindow::on_tableView_2_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
    QSqlQuery qry;
        qry.prepare("select * from patient where num='"+val+"'  " );

        if(qry.exec())
        {
            while(qry.next())
            {
                ui->lineEdit->setText(qry.value(0).toString());
}
}
}
