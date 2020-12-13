#include "ordon.h"
#include "ui_ordon.h"
#include <QMessageBox>

ordon::ordon(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ordon)
{
    ui->setupUi(this);
    ui->tableView->setModel(otmp.afficher());
}

ordon::~ordon()
{
    delete ui;
}

void ordon::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void ordon::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void ordon::on_pushButton_4_clicked()
{
        ui->stackedWidget->setCurrentIndex(3);
}

void ordon::on_pushButton_11_clicked()
{
        ui->stackedWidget->setCurrentIndex(2);
}

void ordon::on_pushButton_3_clicked()
{
        ui->stackedWidget->setCurrentIndex(5);
}

void ordon::on_pushButton_6_clicked()
{
        ui->stackedWidget->setCurrentIndex(4);
}

void ordon::on_pushButton_7_clicked()
{
        ui->stackedWidget->setCurrentIndex(0);
}

void ordon::on_pushButton_8_clicked()
{
        ui->stackedWidget->setCurrentIndex(0);
}

void ordon::on_pushButton_10_clicked()
{
        ui->stackedWidget->setCurrentIndex(0);
}

void ordon::on_pushButton_9_clicked()
{
        ui->stackedWidget->setCurrentIndex(0);
}

void ordon::on_pushButton_14_clicked()
{
    hide();
     menu m;
     m.setModal(true);
     m.exec();
}

void ordon::on_pb_ajouter_clicked()
{
    //recupération des informations dans les 3 champs
    int numero=ui->line_id->text().toInt();
    QString date=ui->lineEdit_50->text();
    Ordonnance O(numero,date);
    bool test=O.ajouter();
    if(test)// si requéte executée ==>QMessageBox::information
    {
           ui->tableView->setModel(otmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("ajout effectué\n"
                                             "click cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                QObject::tr("ajout non effectué. \n"
                            "click cancel to exit."),QMessageBox::Cancel);


}

void ordon::on_pb_supprimer_clicked()
{
    int numero =ui->lineEdit_2->text().toInt();
    bool test=otmp.supprimer(numero);
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),
                 QObject::tr("suppression effectué \n"
                             "Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("suppression non effectuée. \n"
                                          "Click Cancel to exit."),QMessageBox::Cancel);
}





void ordon::on_pushButton_66_clicked()
{

        Ordonnance O;
        int numero_ord=ui->lineEdit_4->text().toInt();
        QString date_ord=ui->lineEdit_52->text();
        O.setDate_ord(date_ord);



        bool test=O.modifier(numero_ord);
        if(test)
        {
            ui->tableView_2->setModel(otmp.afficher());
            QMessageBox::information(nullptr, QObject::tr("modifier une ordonnance"),
                        QObject::tr("ordonnance modifié.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("modifier une ordonnance"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
}

void ordon::on_pushButton_15_clicked()
{
       ui->stackedWidget->setCurrentIndex(0);
}

void ordon::on_pushButton_12_clicked()
{
    Ordonnance o ;
    QString num=ui->lineEdit_3->text() ;
    QString text=o.apercu(num);
    ui->textEdit->setText(text);

  //  QPrinter printer ;
  //  printer.setPrinterName("nom");
  //
  //  ui ->textEdit->print(&printer);
}
