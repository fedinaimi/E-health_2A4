#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QMessageBox>
#include <iostream>
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

ui->tableView_3->setModel(tmprendez.afficher());//refresh
ui->tableView_2->setModel(tmpacte.afficher());//refresh
QPixmap pix7("C:/Users/MSI/Desktop/actemedicale_rendezvous/Resources/Background_color.png");
             int w7 = ui->label_11->width();
             int h7 = ui->label_11->height();
             ui->label_11->setPixmap(pix7.scaled(w7,h7,Qt::IgnoreAspectRatio));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{


if (ui->lineEdit->text().isEmpty()||ui->lineEdit_3->text().isEmpty())


        {
            ui->tableView_2->setModel(tmpacte.afficher());//refresh
                QMessageBox::warning(nullptr, QObject::tr("Attention"),
                            QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
        }
        else
        {
        actemedicale a(ui->lineEdit->text(),ui->lineEdit_3->text().toLong());
        bool test=a.ajouter();
        if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("Ajouter un acte médicale"),
                              QObject::tr("acte médicale ajouté.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_2->setModel(tmpacte.afficher());
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Ajouter un acte médicale"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        }
}

void MainWindow::on_modifier_clicked()
{
    QString type;
        float prix;


        type=ui->lineEdit_4->text();

        prix=ui->lineEdit_5->text().toLong();




         actemedicale a(type,prix);
        bool test= a.modifier(type);
        ui->tableView_2->setModel(tmpacte.afficher());//refresh

        if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("Modifier un   acte médicale"),
                              QObject::tr("  acte médicale Modifié.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
              ui->tableView->setModel(tmpacte.afficher());//refresh
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Modifier un   acte médicale"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }

}


void MainWindow::on_pushButton_clicked()
{
    QString type = ui->lineEdit_2->text();
        actemedicale a;
        bool test=a.supprimer(type);
        ui->tableView_2->setModel(tmpacte.afficher());//refresh
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("Supprimer un acte médicale"),
                        QObject::tr("acte médicale supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
}





void MainWindow::on_pushButton_4_clicked()
{{


        if( ui->lineEdit_6->text().isEmpty()|| ui->lineEdit_7->text().isEmpty())
        {
            ui->tableView_3->setModel(tmprendez.afficher());//refresh
                QMessageBox::warning(nullptr, QObject::tr("Attention"),
                            QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
        }
        else
        {
        rendezvous r(ui->lineEdit_6->text(),ui->lineEdit_7->text());
        bool test=r.ajouter();
        if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("Ajouter un rendez-vous"),
                              QObject::tr("rendez-vous ajouté.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_3->setModel(tmprendez.afficher());
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Ajouter un rendez-vous"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        }
}

}

void MainWindow::on_pushButton_5_clicked()
{
        QString code,date;



            code=ui->lineEdit_8->text();

            date=ui->lineEdit_9->text();




             rendezvous r(code,date);
            bool test= r.modifier(code);

            if (test)
            {
                QMessageBox::information(nullptr, QObject::tr("Modifier un  rendez-vous"),
                                  QObject::tr("  rendez-vous Modifié.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
                  ui->tableView_3->setModel(tmprendez.afficher());//refresh
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("Modifier un  rendez-vous"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
            }




}

void MainWindow::on_pushButton_6_clicked()
{ QString code = ui->lineEdit_10->text();
    rendezvous r;
    bool test=r.supprimer(code);
    ui->tableView_3->setModel(tmprendez.afficher());//refresh
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer un rendez-vous"),
                    QObject::tr("rendez-vous supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void MainWindow::on_lineEdit_10_textChanged(const QString &arg1)
{
   ui->tableView_4->setModel(tmprendez.recherche(ui->lineEdit_10->text()));
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
   ui->tableView->setModel(tmpacte.recherche(ui->lineEdit_2->text()));
}

void MainWindow::on_lineEdit_4_cursorPositionChanged(int arg1, int arg2)
{

}

void MainWindow::on_pushButton_2_clicked()
{QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView_3->model()->rowCount();
    const int columnCount = ui->tableView_3->model()->columnCount();

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
        if (!ui->tableView_3->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView_3->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableView_3->isColumnHidden(column)) {
                QString data = ui->tableView_3->model()->data(ui->tableView_3->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_pushButton_7_clicked()
{


        QPrinter printer;

        printer.setPrinterName("desiered printer name");

      QPrintDialog dialog(&printer,this);

        if(dialog.exec()== QDialog::Rejected)

            return;
}

void MainWindow::on_pushButton_8_clicked()

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

