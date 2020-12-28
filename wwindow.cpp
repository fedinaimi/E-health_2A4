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
#include <QFile>
#include <QTextEdit>
#include <QTextStream>
#include <QFileDialog>







WWindow::WWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(fct.afficher());

}


WWindow::~WWindow()
{
    delete ui;
}
void WWindow::refresh(){
    ui->tableView->setModel(fct.afficher());
     ui->tableView_2->setModel(ptn.afficher());                  }


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




void WWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    ui->tableView->setModel(fct.recherche(arg1));
}



void WWindow::on_pushButton_4_clicked()
{

    ui->tableView->setModel(fct.afficher());
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

    int numtel=ui->lineEdit_7->text().toInt();


    bool test = ptn.supprimer(numtel);
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



void WWindow::on_pushButton_10_clicked()
{
    ui->tableView_2->setModel(ptn.afficher());

}



void WWindow::on_pushButton_14_clicked()
{
    QTableView *table;

                    table = ui->tableView_2;


                    QString filters("Excel Files (.xls)");

                    QString defaultFilter("Excel Files (*.xls)");

                    QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),

                                       filters, &defaultFilter);

                    QFile file(fileName);


                    QAbstractItemModel *model =  table->model();

                    if (file.open(QFile::WriteOnly | QFile::Truncate)) {

                        QTextStream data(&file);

                        QStringList strList;

                        for (int i = 0; i < model->columnCount(); i++) {

                            if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)

                                strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");

                            else

                                strList.append("");

                        }

                        data << strList.join(";") << "\n";

                        for (int i = 0; i < model->rowCount(); i++) {

                            strList.clear();

                            for (int j = 0; j < model->columnCount(); j++) {


                                if (model->data(model->index(i, j)).toString().length() > 0)

                                    strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");

                                else

                                    strList.append("");

                            }

                            data << strList.join(";") + "\n";

                        }

                        file.close();

                        QMessageBox::information(nullptr, QObject::tr("Export excel"),

                                                  QObject::tr("Export avec succes .\n"

                                                              "Click OK to exit."), QMessageBox::Ok);
    }
}

void WWindow::on_pushButton_8_clicked()
{
    QTableView *table;

                    table = ui->tableView;


                    QString filters("Excel Files (.xls)");

                    QString defaultFilter("Excel Files (*.xls)");

                    QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),

                                       filters, &defaultFilter);

                    QFile file(fileName);


                    QAbstractItemModel *model =  table->model();

                    if (file.open(QFile::WriteOnly | QFile::Truncate)) {

                        QTextStream data(&file);

                        QStringList strList;

                        for (int i = 0; i < model->columnCount(); i++) {

                            if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)

                                strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");

                            else

                                strList.append("");

                        }

                        data << strList.join(";") << "\n";

                        for (int i = 0; i < model->rowCount(); i++) {

                            strList.clear();

                            for (int j = 0; j < model->columnCount(); j++) {


                                if (model->data(model->index(i, j)).toString().length() > 0)

                                    strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");

                                else

                                    strList.append("");

                            }

                            data << strList.join(";") + "\n";

                        }

                        file.close();

                        QMessageBox::information(nullptr, QObject::tr("Export excel"),

                                                  QObject::tr("Export avec succes .\n"

                                                              "Click OK to exit."), QMessageBox::Ok);
    }

}

void WWindow::on_pushButton_6_clicked()
{
    hide();
secd = new SecDialog(this);
secd->show();
}


void WWindow::on_pushButton_2_clicked()
{
  close();
}



void WWindow::on_pushButton_16_clicked()
{
close();
}

void WWindow::on_pushButton_12_clicked()
{
    hide();
    patd = new PatientDialog(this);
    patd->show();
}
