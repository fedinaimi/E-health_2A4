#include "medic.h"
#include "ui_medic.h"
#include <QMessageBox>

medic::medic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::medic)
{
    ui->setupUi(this);
    ui->tableView->setModel(etmp.afficher());
    ui->tableView_3->setModel(etmp.afficher());
    ui->tableView_4->setModel(etmp.afficher());
}

medic::~medic()
{
    delete ui;
}
void medic::on_pushButton_clicked()
{
    hide();
     menu m;
     m.setModal(true);
     m.exec();
}

void medic::on_pushButton_29_clicked()
{
      ui->stackedWidget->setCurrentIndex(0);
}

void medic::on_pushButton_32_clicked()
{
      ui->stackedWidget->setCurrentIndex(0);
}

void medic::on_pushButton_35_clicked()
{
      ui->stackedWidget->setCurrentIndex(0);
}

void medic::on_pushButton_36_clicked()
{
      ui->stackedWidget->setCurrentIndex(0);
}

void medic::on_pushButton_25_clicked()
{
      ui->stackedWidget->setCurrentIndex(1);
}

void medic::on_pushButton_26_clicked()
{
      ui->stackedWidget->setCurrentIndex(2);
}

void medic::on_pushButton_27_clicked()
{
      ui->stackedWidget->setCurrentIndex(3);
}

void medic::on_pushButton_28_clicked()
{
      ui->stackedWidget->setCurrentIndex(4);
}



void medic::on_pb_ajouter_3_clicked()
{
    //recupération des informations dans les 3 champs
    int numero=ui->line_id_3->text().toInt();
    QString nom=ui->lineEdit_7->text();
    int prix=ui->lineEdit_8->text().toInt();
    Medicament M(numero,nom,prix);
    bool test=M.ajouter();
    if(test)// si requéte executée ==>QMessageBox::information
    {
          ui->tableView->setModel(etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("ajout effectué\n"
                                             "click cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                QObject::tr("ajout non effectué. \n"
                            "click cancel to exit."),QMessageBox::Cancel);


}




void medic::on_pb_supprimer_3_clicked()
{

    int numero =ui->lineEdit_9->text().toInt();
    bool test=etmp.supprimer(numero);
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





void medic::on_lineEdit_6_textChanged(const QString &arg1)
{
    Medicament m;
    int id = ui->lineEdit_6->text().toInt();


    ui->tableView_3->setModel(m.recherche(id));
}

void medic::on_pushButton_4_clicked()
{
          ui->stackedWidget->setCurrentIndex(5);
}

void medic::on_pushButton_5_clicked()
{
    Medicament M;
    int numero=ui->lineEdit_17->text().toInt();
    QString nom=ui->lineEdit_12->text();
    M.setNom(nom);
   int prix=ui->lineEdit_15->text().toInt();
    M.setPrix(prix);


    bool test=M.modifier(numero);
    if(test)
    {
        ui->tableView_4->setModel(etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("modifier un medicament"),
                    QObject::tr("medicament modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("modifier un medicament"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
}



void medic::on_pushButton_37_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void medic::on_pushButton_3_clicked()
{
     ui->tableView->setModel(etmp.afficherselonnumero());
}

void medic::on_pushButton_6_clicked()
{
         ui->tableView-> setModel(etmp.afficherselonnom());
}

void medic::on_pushButton_7_clicked()
{
         ui->tableView->setModel(etmp.afficherselonprix());
}
