#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"
#include <iostream>
#include <QMessageBox>
#include  <QDebug>
#include <QRadioButton>
#include<QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include <QPainter>
#include<QFileDialog>
#include<QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include<QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QVector>
#include <QSqlQuery>
#include<QDesktopServices>
#include <QMessageBox>
#include<QUrl>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>
#include <QPrintDialog>
#include<QtSql/QSqlQuery>
#include<QVariant>





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(ajt.afficher());
}

MainWindow::~MainWindow()
{

    delete ui;

}



void MainWindow::on_pushButton_clicked()
{
    QString num=ui->lineEdit->text();
               QString nom=ui->lineEdit_2->text();
               QString code=ui->lineEdit_3->text();
               QString d=ui->lineEdit_4->text();


               commande c(num, nom, code,d );
               bool test=c.ajouter();
               ui->tableView->setModel(ajt.afficher());
               QMessageBox msgBox;
               if (test)
               {
                   ui->tableView->setModel(ajt.afficher());
                   msgBox.setText("Ajout avec succés.");
                   msgBox.exec();
               }

               ui->lineEdit->clear();
               ui->lineEdit_2->clear();
               ui->lineEdit_3->clear();
               ui->lineEdit_4->clear();
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->tableView->setModel(ajt.afficher());
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        QString num=ui->lineEdit->text();
        QString nom=ui->lineEdit_2->text();
        QString code=ui->lineEdit_3->text();
        QString d=ui->lineEdit_4->text();

        commande c ;
        bool test=c.modifier(num,nom,code,d);
        QMessageBox msBox;
        if(test)
        {
            ui->tableView->setModel(c.afficher());
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


}



void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
    QSqlQuery qry;
        qry.prepare("select * from cmd where code='"+val+"'  " );

        if(qry.exec())
        {
            while(qry.next())
            {
                ui->lineEdit->setText(qry.value(0).toString());
                ui->lineEdit_2->setText(qry.value(1).toString());
                ui->lineEdit_3->setText(qry.value(2).toString());
                ui->lineEdit_4->setText(qry.value(3).toString());


            }
        }
}

void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox msgBox ;
    QString code = ui->lineEdit_3->text();
            bool test=ajt.supprimer(code);
            if(test)
            {ui->tableView->setModel(ajt.afficher());//refresh
                /*QMessageBox::information(nullptr, QObject::tr("Supprimer un commande"),
                            QObject::tr("commande supprimé.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);*/
                msgBox.setText("commande supprimé.");
                msgBox.exec();
            }
            else
            {QMessageBox::critical(nullptr, QObject::tr("Supprimer un commande"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();

}

void MainWindow::on_pushButton_3_clicked()
{
    ui->tableView->setModel(ajt.afficher());

}


void MainWindow::on_pushButton_9_clicked()
{
    QMessageBox msgBox ;
    QSqlQueryModel *model = new QSqlQueryModel();
        QString code;
        code = ui->lineEdit_5->text();
        model->setQuery("Select * from cmd where code = '"+code+"' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("code"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("d"));
        ui->tableView->setModel(model);
        ui->tableView->show();
        msgBox.setText("commande trouvé.");
        msgBox.exec();
        ui->lineEdit_5->clear();
        QSqlQuery qry;
        qry.prepare("select * from cmd where code='"+code+"'  " );

        if(qry.exec())
        {
            while(qry.next())
            {
                ui->lineEdit->setText(qry.value(0).toString());
                ui->lineEdit_2->setText(qry.value(1).toString());
                ui->lineEdit_3->setText(qry.value(2).toString());
                ui->lineEdit_4->setText(qry.value(3).toString());
    }}
}

void MainWindow::on_pushButton_10_clicked()
{
    QMessageBox msgBox ;

    QSqlQueryModel *model = new QSqlQueryModel();
             model->setQuery("select * from cmd order by code ASC");
             model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
             model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
             model->setHeaderData(2, Qt::Horizontal, QObject::tr("code"));
             model->setHeaderData(3, Qt::Horizontal, QObject::tr("d"));
             ui->tableView->setModel(model);
             ui->tableView->show();
             msgBox.setText("Tri avec succés.");
             msgBox.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
   close() ;
}

void MainWindow::on_pushButton_8_clicked()
{
    QString strStream;
                 QTextStream out(&strStream);

                 const int rowCount = ui->tableView->model()->rowCount();
                 const int columnCount = ui->tableView->model()->columnCount();

                 out <<  "<html>\n"
                     "<head>\n"
                     "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                     <<  QString("<title>%1</title>\n").arg("strTitle")
                     <<  "</head>\n"
                     "<body bgcolor=#ffffff link=#5000A0>\n"

                    //     "<align='right'> " << datefich << "</align>"
                     "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                 // headers
                 out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                 for (int column = 0; column < columnCount; column++)
                     if (!ui->tableView->isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";

                 // data table
                 for (int row = 0; row < rowCount; row++) {
                     out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                     for (int column = 0; column < columnCount; column++) {
                         if (!ui->tableView->isColumnHidden(column)) {
                             QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                         }
                     }
                     out << "</tr>\n";
                 }
                 out <<  "</table> </center>\n"
                     "</body>\n"
                     "</html>\n";

           QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
             if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

            QPrinter printer (QPrinter::PrinterResolution);
             printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setPaperSize(QPrinter::A4);
           printer.setOutputFileName(fileName);

            QTextDocument doc;
             doc.setHtml(strStream);
             doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
             doc.print(&printer);

    }


void MainWindow::on_pushButton_6_clicked()
{
    //imprimer
    QPrinter printer;
    printer.setPrinterName("desiered printer name");
  QPrintDialog dialog(&printer,this);
    if(dialog.exec()== QDialog::Rejected)
        return;
}



...



