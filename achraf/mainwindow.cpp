#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"
#include "utilisateur.h"
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
#include <QComboBox>
#include <QWidget>
#include "QValueAxis"
#include <QSound>





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(ajt.afficher());
    QPixmap pix7("C:/Users/Admin/Documents/achraf/Ressource/Background_color.png");
             int w7 = ui->label_10->width();
             int h7 = ui->label_10->height();
             ui->label_10->setPixmap(pix7.scaled(w7,h7,Qt::IgnoreAspectRatio));
             ui->pushButton->setStyleSheet("border-image: url(C:/Users/Admin/Documents/achraf/Ressource/button_init.png)3 10 3 10; font: 12pt Bahnschrift;");
ui->pushButton_2->setStyleSheet("border-image: url(C:/Users/Admin/Documents/achraf/Ressource/Ressource/button_init.png)3 10 3 10; font: 12pt Bahnschrift;");
ui->pushButton_3->setStyleSheet("border-image: url(C:/Users/Admin/Documents/achraf/Ressource/Ressource/button_init.png)3 10 3 10; font: 12pt Bahnschrift;");
ui->pushButton_4->setStyleSheet("border-image: url(C:/Users/Admin/Documents/achraf/Ressource/button_init.png)3 10 3 10; font: 12pt Bahnschrift;");
ui->pushButton_5->setStyleSheet("border-image: url(C:/Users/Admin/Documents/achraf/Ressource/button_init.png)3 10 3 10; font: 12pt Bahnschrift;");
ui->pushButton_6->setStyleSheet("border-image: url(C:/Users/Admin/Documents/achraf/Ressource/button_init.png)3 10 3 10; font: 12pt Bahnschrift;");
ui->pushButton_8->setStyleSheet("border-image: url(C:/Users/Admin/Documents/achraf/Ressource/button_init.png)3 10 3 10; font: 12pt Bahnschrift;");
ui->pushButton_9->setStyleSheet("border-image: url(C:/Users/Admin/Documents/achraf/Ressource/button_init.png)3 10 3 10; font: 12pt Bahnschrift;");
ui->pushButton_10->setStyleSheet("border-image: url(C:/Users/Admin/Documents/achraf/Ressource/button_init.png)3 10 3 10; font: 12pt Bahnschrift;");
ui->pushButton_7->setStyleSheet("border-image: url(C:/Users/Admin/Documents/achraf/Ressource/button_init.png)3 10 3 10; font: 12pt Bahnschrift;");
QPixmap pix("C:/Users/Admin/Documents/achraf/Ressource/Background_color.png");
 int w6 = ui->label_11->width();
 int h6 = ui->label_11->height();
 ui->label_11->setPixmap(pix.scaled(w6,h6,Qt::IgnoreAspectRatio));
         ui->pushButton_11->setStyleSheet("border-image: url(C:/Users/Admin/Documents/achraf/Ressource/button_init.png)3 10 3 10; font: 12pt Bahnschrift;");
         ui->pushButton_12->setStyleSheet("border-image: url(C:/Users/Admin/Documents/achraf/Ressource/button_init.png)3 10 3 10; font: 12pt Bahnschrift;");
         ui->pushButton_13->setStyleSheet("border-image: url(C:/Users/Admin/Documents/achraf/Ressource/button_init.png)3 10 3 10; font: 10pt Bahnschrift;");
         ui->pushButton_14->setStyleSheet("border-image: url(C:/Users/Admin/Documents/achraf/Ressource/button_init.png)3 10 3 10; font: 10pt Bahnschrift;");
         ui->pushButton_15->setStyleSheet("border-image: url(C:/Users/Admin/Documents/achraf/Ressource/button_init.png)3 10 3 10; font: 8pt Bahnschrift;");
         ui->pushButton_16->setStyleSheet("border-image: url(C:/Users/Admin/Documents/achraf/Ressource/button_init.png)3 10 3 10; font: 10pt Bahnschrift;");
         ui->pushButton_17->setStyleSheet("border-image: url(C:/Users/Admin/Documents/achraf/Ressource/button_init.png)3 10 3 10; font: 8pt Bahnschrift;");


clickSound=new QSound(":/sounds/click.wav");

// arduino
      int ret=A.connect_arduino();
      switch(ret){
      case(0):qDebug()<< "arduino is availble and connected to :"<< A.getarduino_port_name();
          break;
      case(1):qDebug()<< "arduino is availble but not connected to :"<< A.getarduino_port_name();
          break;
      case(-1):qDebug()<< "arduino is not availble";
      }
      QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));

      //fin arduino


}

MainWindow::~MainWindow()
{

    delete ui;

}


//arduino

void MainWindow::update_label()
{
    data=A.read_from_arduino();
    QString DataAsString = QString(data);
    qDebug()<< data;

     ui->label_2->setText("temp : "+data);

    if (data=="21"||data=="22"||data=="23"||data=="24"||data=="25"||data=="26"||data=="27"){
        if (messageboxactive==0){
            alert=1;
        }


    }
    if (alert==1){
         alert=0;
         messageboxactive=1;
        int reponse = QMessageBox::question(this, "led", "allumer led", QMessageBox::Yes |  QMessageBox::No);
                                   if (reponse == QMessageBox::Yes)
                                   {
                                     led=1;
                                   }
                                   if (reponse == QMessageBox::No)
                                   {
                                      led=0;
                                   }

    }
    if (led==1){
        A.write_to_arduino("1");
    }
    if (data=="20"||data=="19"||data=="18"||data=="17"||data=="16"||data=="15"||data=="14 "){
        A.write_to_arduino("0");
        led=0;
    }

}

//fin arduino


void MainWindow::on_pushButton_clicked()
{
clickSound->play();
      QString num=ui->lineEdit->text();
      QString Nom=ui->lineEdit_2->text();
      QString code=ui->lineEdit_3->text();
      QString d=ui->lineEdit_4->text();

      commande c(num,Nom,code,d);

bool test=c.ajouter();

if (        ui->lineEdit->text()!= "" &&
        ui->lineEdit_2->text()!= "" &&
        ui->lineEdit_3->text() !="" &&
        ui->lineEdit_4->text() != "" )



{
               if (test)
               {

                   ui->tableView->setModel(c.afficher());

                   QMessageBox::information(nullptr, QObject::tr("Ajouter client"),
                                           QObject::tr("client ajouté.\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);
                           }
                          else{
                               QMessageBox::information(nullptr, QObject::tr("Ajouter client"),
                                           QObject::tr("Ajout echoué.\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);
                           }
                        }




else {{  QMessageBox::critical(nullptr, QObject::tr("Ajouter client"),
                               QObject::tr("Ajout echoué ! Cases vides ! .\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

}
                  }}









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
                ui->lineEdit_4->setDate (QDate::fromString(qry.value(3).toString(),"dd/MM/yyyy"));


            }
        }
}

void MainWindow::on_pushButton_5_clicked()
{


    clickSound->play();
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
{  clickSound->play();
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
                ui->lineEdit_4->setDate (QDate::fromString(qry.value(3).toString(),"dd/MM/yyyy"));
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



void MainWindow::on_pushButton_11_clicked()
{

               QString login=ui->lineEdit_6->text();
                  QString type ;
               if( ui->comboBox->currentIndex()==0 )
                   type="medecin";

                           else {

                           type="secretaire";
                           }
               QString mdp=ui->lineEdit_8->text();
               utilisateur u(login,type,mdp);
               bool test=u.ajouter();
               ui->tableView_2->setModel(psm.afficher());
               QMessageBox msgBox;
               if (test)
               {
                   ui->tableView_2->setModel(psm.afficher());
                   msgBox.setText("Ajout avec succés.");
                   msgBox.exec();
               }

               ui->lineEdit_6->clear();
               ui->comboBox->clear();
               ui->lineEdit_8->clear();
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->tableView_2->setModel(psm.afficher());
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->tableView_2->setModel(psm.afficher());
        ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        QString login=ui->lineEdit_6->text();
        QString type ;
      if( ui->comboBox->currentIndex()==0 )
          type="medecin";

                  else {

                  type="secretaire";
                  }
        QString mdp=ui->lineEdit_8->text();

        utilisateur u ;
        bool test=u.modifier(login,type,mdp);
        QMessageBox msBox;
        if(test)
        {
            ui->tableView_2->setModel(u.afficher());
            ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            msBox.setText("modification reussite");
            msBox.exec();
        }
        else
        {
            msBox.setText("ERREUR");
            msBox.exec();
        }
        ui->lineEdit_6->clear();
        ui->comboBox->clear();
        ui->lineEdit_8->clear();

}



void MainWindow::on_pushButton_14_clicked()
{
    QMessageBox msgBox ;
    QString login = ui->lineEdit_6->text();
            bool test=psm.supprimer(login);
            if(test)
            {ui->tableView_2->setModel(psm.afficher());//refresh
                /*QMessageBox::information(nullptr, QObject::tr("Supprimer un utilisateur"),
                            QObject::tr("utilisateur supprimé.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);*/
                msgBox.setText("utilisateur supprimé.");
                msgBox.exec();
            }
            else
            {QMessageBox::critical(nullptr, QObject::tr("Supprimer un utilisateur"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
            ui->lineEdit_6->clear();
            ui->comboBox->clear();
            ui->lineEdit_8->clear();

}



void MainWindow::on_lineEdit_6_textChanged(const QString &arg1)
{
    if(psm.testlogin(ui->lineEdit_6->text())){
        ui->label_6->setText("le login doit etre unique");
    }
    else {
        ui->label_6->setText("");
    }
}







void MainWindow::on_pushButton_18_clicked()
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