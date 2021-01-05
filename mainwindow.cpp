#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginsystem.h"
#include <QPropertyAnimation>
#include <QMediaPlayer>
#include <QSound>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPercentBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

QT_CHARTS_USE_NAMESPACE



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

  /*int con=a.connect_arduino();
    switch (con){
       case 0:qDebug()<<"Arduino found and connected";break;
       case 1:qDebug()<<"Arduino found but not connected";break;
       case -1:qDebug()<<"Arduino not found and not connected";break;
    }
    QObject::connect(a.getserial(),SIGNAL(readyRead()),this,SLOT(read_botton()));*/

 ui->tableView_11->setModel(ajt.afficher());
 QPixmap pix7("C:/Users/fadi/Desktop/QT/integration/Resources/Background_color.png");
              int w7 = ui->label_47->width();
              int h7 = ui->label_47->height();
              ui->label_47->setPixmap(pix7.scaled(w7,h7,Qt::IgnoreAspectRatio));
              ui->tableView->setModel(tmpproduit.afficher());

               ui->tableView_2->setModel(tmpfournisseur.afficher());//refresh
               ui->tableView_9->setModel(tmprendez.afficher());//refresh

              ui->tableView_7->setModel(tmpacte.afficher());//refresh
              ui->tableView_14->setModel(tmpord.afficher());//refresh
              ui->tableView_16->setModel(m.afficher());//refresh
                ui->tableView_20->setModel(p.afficher());//refresh
                ui->tableView_23->setModel(tmpf.afficher());//refresh

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_11_clicked()
{
    close();
}

void MainWindow::on_pushButton_10_clicked()
{

    QString type = ui->lineEdit_21->text();
        actemedicale a;
        bool test=a.supprimer(type);
        ui->tableView_7->setModel(tmpacte.afficher());//refresh
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("Supprimer un acte médicale"),
                        QObject::tr("acte médicale supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void MainWindow::on_pushButton_clicked()
{
    MainWindow::notif("PRODUIT","Ajout d'un produit est reussite");

    if( ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty()|| ui->lineEdit_3->text().isEmpty()|| ui->lineEdit_4->text().isEmpty()|| ui->lineEdit_5->text().isEmpty()  )
    {
        ui->tableView->setModel(tmpproduit.afficher());//refresh
            QMessageBox::warning(nullptr, QObject::tr("Attention"),
                        QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
    }
    else
    {
    PRODUIT p(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text().toLong(),ui->lineEdit_5->text().toInt());
    bool test=p.ajouter();
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajouter un PRODUIT"),
                          QObject::tr("PRODUIT ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(tmpproduit.afficher());
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un PRODUIT"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    }
}
void MainWindow::on_pushButton_9_clicked()
{
    QString nom,prenom,telf,id,facture;


    MainWindow::notif("FOURNISSEUR","Ajout d'un fournisseur est reussite");

    if( ui->lineEdit_9->text().isEmpty() || ui->lineEdit_10->text().isEmpty()|| ui->lineEdit_8->text().isEmpty()|| ui->lineEdit_13->text().isEmpty() )
    {
        ui->tableView_2->setModel(tmpfournisseur.afficher());//refresh
            QMessageBox::warning(nullptr, QObject::tr("Attention"),
                        QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
    }
    else{
        nom=ui->lineEdit_9->text();
       prenom=ui->lineEdit_10->text();
        telf=ui->lineEdit_8->text();
        id=ui->lineEdit_13->text();


         if (ui->comboBox->currentIndex()==0)
            facture="payee";
         else {
             facture="non payee";
         }


    FOURNISSEUR f( nom,prenom,telf,id,facture );
    bool test=f.ajouter();

    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajouter un  FOURNISSEUR"),
                          QObject::tr(" FOURNISSEUR ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_2->setModel(tmpfournisseur.afficher());
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un FOURNISSEUR"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    }
}

void MainWindow::notif(QString t,QString m)
{
    QPixmap p(32,32);
    p.load("://sources/LOGO.png");
    QIcon icon(p);
    QSystemTrayIcon n(icon);
    n.setVisible(true);
    n.showMessage(t,m,QSystemTrayIcon::Information,1000);

}

void MainWindow::on_pushButton_3_clicked()
{
    QString ref = ui->lineEdit_6->text();
    PRODUIT P;
    bool test=P.supprimer(ref);
    ui->tableView->setModel(tmpproduit.afficher());//refresh
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("produit supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_lineEdit_6_cursorPositionChanged(int arg1, int arg2)
{

}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{

}

void MainWindow::on_pushButton_2_clicked()
{


    QString ref,nom,fournisseur;
        float prix;
        int stock;

        ref=ui->lineEdit_17->text();
       // nom=ui->lineEdit_12->text();
        //fournisseur=ui->lineEdit_14->text();
        prix=ui->lineEdit_15->text().toLong();
        stock=ui->lineEdit_16->text().toInt();



         PRODUIT p(nom,ref,fournisseur,prix,stock);
        bool test= p.modifier(ref);

        if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("Modifier un   PRODUIT"),
                              QObject::tr("  PRODUIT Modifié.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
              ui->tableView->setModel(tmpproduit.afficher());//refresh
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Modifier un   PRODUIT"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void MainWindow::on_lineEdit_15_cursorPositionChanged(int arg1, int arg2)
{

}

void MainWindow::on_lineEdit_6_textChanged(const QString &arg1)
{
    ui->tableView_3->setModel(tmpproduit.recherche(ui->lineEdit_6->text()));
}

void MainWindow::on_lineEdit_17_cursorPositionChanged(int arg1, int arg2)
{
    ui->tableView_4->setModel(tmpproduit.recherche(ui->lineEdit_17->text()));
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{

}

void MainWindow::on_lineEdit_17_returnPressed()
{

}

void MainWindow::on_pushButton_7_clicked()
{
    QString id = ui->lineEdit_7->text();
    FOURNISSEUR f;
    bool test=f.supprimer(id);
    ui->tableView_2->setModel(tmpfournisseur.afficher());//refresh
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("produit supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}



void MainWindow::on_lineEdit_7_textChanged(const QString &arg1)
{
     ui->tableView_5->setModel(tmpfournisseur.recherche(ui->lineEdit_7->text()));
}

void MainWindow::on_pushButton_4_clicked()
{
    QString nom,prenom,telf,id,facture;


      id=ui->lineEdit_18->text();

      if (ui->comboBox_2->currentIndex()==0)
          facture="payee";
       else {
           facture="non payee";
       }



     FOURNISSEUR f(nom,prenom,telf,id,facture);
    bool test= f.modifier(id);

    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("Modifier un   FOURNISSEUR"),
                          QObject::tr("  FOURNISSEUR Modifié.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
          ui->tableView_2->setModel(tmpfournisseur.afficher());//refresh
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un   FOURNISSEUR"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_lineEdit_18_cursorPositionChanged(int arg1, int arg2)
{
     ui->tableView_6->setModel(tmpfournisseur.recherche(ui->lineEdit_18->text()));
}




void MainWindow::on_pushButton_5_clicked()
{
    QString strStream;
                    QTextStream out(&strStream);

                    const int rowCount = ui->tableView_2->model()->rowCount();
                    const int columnCount = ui->tableView_2->model()->columnCount();

                    out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>acte médicale</title>\n").arg("strTitle")
                        <<  "</head>\n"
                        "<body bgcolor=#ffffff link=#5000A0>\n"

                       //     "<align='left'> " << datefich << "</align>"
                        "<center> <H1>liste des fournisseurs </h2></br></br><table border=4 cellspacing=1 cellpadding=2>\n";

                    // headers
                    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tableView_2->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";

                    // data table
                    for (int row = 0; row < rowCount; row++) {
                        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                        for (int column = 0; column < columnCount; column++) {
                            if (!ui->tableView_2->isColumnHidden(column)) {
                                QString data = ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
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

    QPrinter printer;

    printer.setPrinterName("desiered printer name");

  QPrintDialog dialog(&printer,this);

    if(dialog.exec()== QDialog::Rejected)

        return;
}



void MainWindow::on_pushButton_8_clicked()
{

    if( ui->lineEdit_12->text().isEmpty()|| ui->lineEdit_14->text().isEmpty())
    {
        ui->tableView_7->setModel(tmpacte.afficher());//refresh
            QMessageBox::warning(nullptr, QObject::tr("Attention"),
                        QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
    }
    else
    {
    actemedicale a(ui->lineEdit_12->text(),ui->lineEdit_14->text().toLong());
    bool test=a.ajouter();
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajouter un acte médicale"),
                          QObject::tr("acte médicale ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_7->setModel(tmpacte.afficher());
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


        type=ui->lineEdit_19->text();

        prix=ui->lineEdit_20->text().toLong();




         actemedicale a(type,prix);
        bool test= a.modifier(type);
        ui->tableView_7->setModel(tmpacte.afficher());//refresh

        if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("Modifier un   acte médicale"),
                              QObject::tr("  acte médicale Modifié.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
              ui->tableView_7->setModel(tmpacte.afficher());//refresh
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Modifier un   acte médicale"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }

}

void MainWindow::on_lineEdit_21_textChanged(const QString &arg1)
{
     ui->tableView_8->setModel(tmpacte.recherche(ui->lineEdit_21->text()));
}

void MainWindow::on_pushButton_12_clicked()
{
    {


            if( ui->lineEdit_22->text().isEmpty()|| ui->lineEdit_23->text().isEmpty())
            {
                ui->tableView_9->setModel(tmprendez.afficher());//refresh
                    QMessageBox::warning(nullptr, QObject::tr("Attention"),
                                QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
            }
            else
            {
            rendezvous r(ui->lineEdit_22->text(),ui->lineEdit_23->text());
            bool test=r.ajouter();
            if (test)
            {
                QMessageBox::information(nullptr, QObject::tr("Ajouter un rendez-vous"),
                                  QObject::tr("rendez-vous ajouté.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
                ui->tableView_9->setModel(tmprendez.afficher());
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

void MainWindow::on_pushButton_15_clicked()
{
    QString code,date;



        code=ui->lineEdit_24->text();

        date=ui->lineEdit_25->text();




         rendezvous r(code,date);
        bool test= r.modifier(code);

        if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("Modifier un  rendez-vous"),
                              QObject::tr("  rendez-vous Modifié.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
              ui->tableView_9->setModel(tmprendez.afficher());//refresh
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Modifier un  rendez-vous"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }


}

void MainWindow::on_pushButton_16_clicked()
{
    QString code = ui->lineEdit_26->text();
       rendezvous r;
       bool test=r.supprimer(code);
       ui->tableView_9->setModel(tmprendez.afficher());//refresh
       if(test)
       {
           QMessageBox::information(nullptr, QObject::tr("Supprimer un rendez-vous"),
                       QObject::tr("rendez-vous supprimé.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       }
}


void MainWindow::on_lineEdit_26_textChanged(const QString &arg1)
{
       ui->tableView_10->setModel(tmprendez.recherche(ui->lineEdit_26->text()));
}

void MainWindow::on_pushButton_13_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tableView_9->model()->rowCount();
        const int columnCount = ui->tableView_9->model()->columnCount();

        out <<  "<html>\n"
            "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg("strTitle")
            <<  "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"

           //     "<align='right'> " << datefich << "</align>"
            "<center> <H1>Liste des actes medicaux </H3></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

        // headers
        out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tableView_9->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tableView_7->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tableView_9->isColumnHidden(column)) {
                    QString data = ui->tableView_9->model()->data(ui->tableView_9->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_pushButton_17_clicked()
{
    MainWindow::notif("CMD","Ajout d'un produit est commande");

    if( ui->lineEdit_27->text().isEmpty() || ui->lineEdit_28->text().isEmpty()|| ui->lineEdit_29->text().isEmpty()|| ui->lineEdit_30->text().isEmpty())
    {
        ui->tableView_11->setModel(ajt.afficher());//refresh
            QMessageBox::warning(nullptr, QObject::tr("Attention"),
                        QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
    }
    else
    {
    commande c(ui->lineEdit_27->text(),ui->lineEdit_28->text(),ui->lineEdit_29->text(),ui->lineEdit_30->text());
    bool test=c.ajouter();
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajouter un commande"),
                          QObject::tr("commande ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_11->setModel(ajt.afficher());
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un commande"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    }
}

void MainWindow::on_pushButton_21_clicked()
{



    ui->tableView_11->setModel(ajt.afficher());
        ui->tableView_11->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        QString num=ui->lineEdit_34->text();
        QString nom=ui->lineEdit_35->text();
        QString code=ui->lineEdit_32->text();
        QString d=ui->lineEdit_33->text();

        commande c ;
        bool test=c.modifier(num,nom,code,d);
        QMessageBox msBox;
        if(test)
        {
            ui->tableView_11->setModel(c.afficher());
            ui->tableView_11->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            msBox.setText("modification reussite");
            msBox.exec();
        }
        else
        {
            msBox.setText("ERREUR");
            msBox.exec();
        }
        ui->lineEdit_34->clear();
        ui->lineEdit_35->clear();
        ui->lineEdit_32->clear();
        ui->lineEdit_33->clear();

}

void MainWindow::on_pushButton_20_clicked()
{
    QString code = ui->lineEdit_31->text();
       commande c;
       bool test=c.supprimer(code);
       ui->tableView_11->setModel(c.afficher());//refresh
       if(test)
       {
           QMessageBox::information(nullptr, QObject::tr("Supprimer une commande"),
                       QObject::tr("commande supprimé.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       }
}

void MainWindow::on_lineEdit_31_textChanged(const QString &arg1)
{
       ui->tableView_12->setModel(ajt.recherche(ui->lineEdit_31->text()));
}
#include "utilisateur.h"

void MainWindow::on_pushButton_22_clicked()
{
    QString login=ui->lineEdit_36->text();
      QString type ;

      if( ui->lineEdit_36->text().isEmpty() || ui->lineEdit_37->text().isEmpty())
      {
           ui->tableView_13->setModel(psm.afficher());
              QMessageBox::warning(nullptr, QObject::tr("Attention"),
                          QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
      }


    if( ui->comboBox_3->currentIndex()==0 )
        type="medecin";

                else {

                type="secretaire";
                }
    QString mdp=ui->lineEdit_37->text();
    utilisateur u(login,type,mdp);
    bool test=u.ajouter();
    ui->tableView_13->setModel(psm.afficher());
    QMessageBox msgBox;
    if (test)
    {
        ui->tableView_13->setModel(psm.afficher());
        msgBox.setText("Ajout avec succés.");
        msgBox.exec();
    }

    ui->lineEdit_36->clear();
    ui->comboBox_3->clear();
    ui->lineEdit_37->clear();
}

void MainWindow::on_pushButton_23_clicked()
{
    ui->tableView_13->setModel(psm.afficher());
        ui->tableView_13->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        QString login=ui->lineEdit_36->text();
        QString type ;
      if( ui->comboBox_3->currentIndex()==0 )
          type="medecin";

                  else {

                  type="secretaire";
                  }
        QString mdp=ui->lineEdit_37->text();

        utilisateur u ;
        bool test=u.modifier(login,type,mdp);
        QMessageBox msBox;
        if(test)
        {
            ui->tableView_13->setModel(u.afficher());
            ui->tableView_13->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            msBox.setText("modification reussite");
            msBox.exec();
        }
        else
        {
            msBox.setText("ERREUR");
            msBox.exec();
        }
        ui->lineEdit_36->clear();
        ui->comboBox_3->clear();
        ui->lineEdit_8->clear();

}

void MainWindow::on_pushButton_24_clicked()
{
     ui->tableView_13->setModel(psm.afficher());
}

void MainWindow::on_pushButton_25_clicked()
{
    QMessageBox msgBox ;
    QString login = ui->lineEdit_36->text();
            bool test=psm.supprimer(login);
            if(test)
            {ui->tableView_13->setModel(psm.afficher());//refresh
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
            ui->lineEdit_36->clear();
            ui->comboBox_3->clear();
            ui->lineEdit_37->clear();

}

void MainWindow::on_pushButton_29_clicked()
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

void MainWindow::on_pushButton_32_clicked()
{
    if( ui->line_id_3->text().isEmpty()|| ui->lineEdit_38->text().isEmpty()||ui->lineEdit_44->text().isEmpty())
    {

            QMessageBox::warning(nullptr, QObject::tr("Attention"),
                        QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
            ui->tableView_16->setModel(m.afficher());//refresh
    }
    else
    {
   medicament me(ui->line_id_3->text(),ui->lineEdit_38->text(),ui->lineEdit_44->text());
    bool test=me.ajouter();
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajouter un medicament"),
                          QObject::tr(" MEDICAMENT ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_16->setModel(m.afficher());
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une un medicament"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    }
}


void MainWindow::on_pb_ajouter_clicked()
{


    if( ui->line_id->text().isEmpty()|| ui->lineEdit_50->text().isEmpty())
    {
        ui->tableView_14->setModel(tmpord.afficher());//refresh
            QMessageBox::warning(nullptr, QObject::tr("Attention"),
                        QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
    }
    else
    {
    ordonnance o(ui->line_id->text() , ui->lineEdit_50->text());
    bool test=o.ajouter();
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajouter uneORDONNANCE"),
                          QObject::tr(" ORDONNANCE ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_14->setModel(tmpord.afficher());
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une ORDONNANCE"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    }
}

void MainWindow::on_pushButton_34_clicked()
{
    QString numero,date;



        numero=ui->lineEdit_39->text();

        date=ui->lineEdit_59->text();




         ordonnance o(numero,date) ;
        bool test= o.modifier(numero);


        if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("Modifier une ordonnance"),
                              QObject::tr("  ordonnance Modifié.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_14->setModel(tmpord.afficher());//refresh

        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Modifier une ordonnance"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }

}

void MainWindow::on_pushButton_31_clicked()
{
    QString numero = ui->lineEdit_41->text();
       ordonnance o;
       bool test=o.supprimer(numero);
       ui->tableView_14->setModel(tmpord.afficher());//refresh
       if(test)
       {
           QMessageBox::information(nullptr, QObject::tr("Supprimer un ordonnance"),
                       QObject::tr("ordennance supprimé.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       }
}

void MainWindow::on_lineEdit_39_textChanged(const QString &arg1)
{
     ui->tableView_15->setModel(tmpord.recherche(ui->lineEdit_39->text()));
}

void MainWindow::on_lineEdit_41_textChanged(const QString &arg1)
{
     ui->tableView_19->setModel(tmpord.recherche(ui->lineEdit_41->text()));
}

void MainWindow::on_modifier_3_clicked()
{

        QString num=ui->lineEdit_56->text();
        QString nom ;


        QString prix=ui->lineEdit_58->text();

        medicament m(num,nom,prix);
       bool test= m.modifier(num);
       ui->tableView_16->setModel(m.afficher());//refresh

       if (test)
       {
           QMessageBox::information(nullptr, QObject::tr("Modifier un   medicament"),
                             QObject::tr("  medicament Modifié.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
             ui->tableView_16->setModel(m.afficher());//refresh
       }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("Modifier un   medicament"),
                             QObject::tr("Erreur !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
       }

}

void MainWindow::on_pushButton_33_clicked()
{
    QMessageBox msgBox ;
    QString num = ui->line_id_4->text();
            bool test=m.supprimer(num);
            if(test)
            {ui->tableView_16->setModel(m.afficher());//refresh
                /*QMessageBox::information(nullptr, QObject::tr("Supprimer un medicament"),
                            QObject::tr("medicament supprimé.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);*/
                msgBox.setText("medicament supprimé.");
                msgBox.exec();
            }
            else
            {QMessageBox::critical(nullptr, QObject::tr("Supprimer un medicament"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}


}

void MainWindow::on_pushButton_35_clicked()
{
    QString nom=ui->lineEdit_40->text();
      QString prenom=ui->lineEdit_42->text();
    QString sexe=ui->lineEdit_43->text();
    QString num=ui->lineEdit_45->text();
      QString numtel=ui->lineEdit_46->text();
    QString adresse=ui->lineEdit_47->text();
    patient p (nom,prenom,sexe,num,numtel,adresse);
    bool test=p.ajouter();
    ui->tableView_20->setModel(p.afficher());
    QMessageBox msgBox;
    if (test)
    {
        ui->tableView_20->setModel(p.afficher());
        msgBox.setText("Ajout avec succés.");
        msgBox.exec();
    }

    ui->lineEdit_40->clear();
    ui->lineEdit_42->clear();
    ui->lineEdit_43->clear();
    ui->lineEdit_45->clear();
    ui->lineEdit_46->clear();
    ui->lineEdit_47->clear();
}


void MainWindow::on_pushButton_36_clicked()
{
    ui->tableView_20->setModel(p.afficher());
        ui->tableView_20->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        QString nom;
        QString prenom;
        QString sexe;
        QString num=ui->lineEdit_52->text();
        QString numtel=ui->lineEdit_48->text();
        QString adresse=ui->lineEdit_54->text();


        patient p(nom,prenom,sexe,num,numtel,adresse) ;
        bool test=p.modifier(num);
        QMessageBox msBox;
        if(test)
        {
            ui->tableView_20->setModel(p.afficher());
            ui->tableView_20->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            msBox.setText("modification reussite");
            msBox.exec();
        }
        else
        {
            msBox.setText("ERREUR");
            msBox.exec();
        }


}





void MainWindow::on_pushButton_37_clicked()
{
    QString num = ui->lineEdit_55->text();
        patient p ;
        bool test=p.supprimer(num);
        ui->tableView_20->setModel(p.afficher());//refresh
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("Supprimer un patient"),
                        QObject::tr("acte médicale supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
}


void MainWindow::on_lineEdit_56_textChanged(const QString &arg1)
{
    ui->tableView_17->setModel(m.recherche(ui->lineEdit_56->text()));
}

void MainWindow::on_line_id_4_textChanged(const QString &arg1)
{
    ui->tableView_18->setModel(m.recherche(ui->line_id_4->text()));
}

void MainWindow::on_lineEdit_52_textChanged(const QString &arg1)
{
    ui->tableView_21->setModel(p.recherche(ui->lineEdit_52->text()));
}

void MainWindow::on_lineEdit_55_textChanged(const QString &arg1)
{
   ui->tableView_22->setModel(p.recherche(ui->lineEdit_55->text()));
}

void MainWindow::on_pushButton_38_clicked()
{

    if( ui->lineEdit_49->text().isEmpty()|| ui->lineEdit_51->text().isEmpty())
    {
        ui->tableView_23->setModel(tmpf.afficher());//refresh
            QMessageBox::warning(nullptr, QObject::tr("Attention"),
                        QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
    }
    else
    {
       facture f(ui->lineEdit_49->text(),ui->lineEdit_51->text());
    bool test=f.ajouter();
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajouter une facture"),
                          QObject::tr("une facture ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_23->setModel(tmpf.afficher());
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une facture"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    }
}

void MainWindow::on_pushButton_39_clicked()
{

        QString num=ui->lineEdit_63->text();
        QString solde=ui->lineEdit_61->text();




  facture f(num,solde);
       bool test= f.modifier(num);
       ui->tableView_23->setModel(tmpf.afficher());//refresh

       if (test)
       {
           QMessageBox::information(nullptr, QObject::tr("Modifier un   facture "),
                             QObject::tr("  facture Modifié.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
             ui->tableView_23->setModel(tmpf.afficher());//refresh
       }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("Modifier un   facture"),
                             QObject::tr("Erreur !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
       }

}

void MainWindow::on_pushButton_40_clicked()
{

    QString num = ui->lineEdit_64->text();
        facture f;
        bool test=f.supprimer(num);
        ui->tableView_23->setModel(tmpf.afficher());//refresh
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("Supprimer une facture"),
                        QObject::tr("facture supprimée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
}
void MainWindow::on_lineEdit_64_textChanged(const QString &arg1)
{
   ui->tableView_25->setModel(tmpf.recherche(ui->lineEdit_64->text()));
}

void MainWindow::on_lineEdit_63_textChanged(const QString &arg1)
{
    ui->tableView_24->setModel(tmpf.recherche(ui->lineEdit_63->text()));
}

void MainWindow::on_pushButton_41_clicked()
{
    QString strStream;
                    QTextStream out(&strStream);

                    const int rowCount = ui->tableView_23->model()->rowCount();
                    const int columnCount = ui->tableView_23->model()->columnCount();

                    out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("strTitle")
                        <<  "</head>\n"
                        "<body bgcolor=#ffffff link=#5000A0>\n"

                       //     "<align='right'> " << datefich << "</align>"
                        "<center> <H1>Liste des factures </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                    // headers
                    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tableView_23->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tableView_23->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";

                    // data table
                    for (int row = 0; row < rowCount; row++) {
                        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                        for (int column = 0; column < columnCount; column++) {
                            if (!ui->tableView_23->isColumnHidden(column)) {
                                QString data = ui->tableView_23->model()->data(ui->tableView_23->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_pushButton_14_clicked()
{
    QString strStream;
                    QTextStream out(&strStream);

                    const int rowCount = ui->tableView_9->model()->rowCount();
                    const int columnCount = ui->tableView_9->model()->columnCount();

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
                        if (!ui->tableView_9->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tableView_9->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";

                    // data table
                    for (int row = 0; row < rowCount; row++) {
                        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                        for (int column = 0; column < columnCount; column++) {
                            if (!ui->tableView_9->isColumnHidden(column)) {
                                QString data = ui->tableView_9->model()->data(ui->tableView_9->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_pushButton_42_clicked()
{
    QTableView *table;

                    table = ui->tableView_7;


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

void MainWindow::on_pushButton_27_clicked()
{






//![1]
    QBarSet *set0 = new QBarSet("facture");
    QBarSet *set1 = new QBarSet("produit");
    QBarSet *set2 = new QBarSet("commande");
    QBarSet *set3 = new QBarSet("patient");
    QBarSet *set4 = new QBarSet("rendez_vous");

    *set0 << 1 << 2 << 3 << 4 << 5 << 6;
    *set1 << 5 << 0 << 0 << 4 << 0 << 7;
    *set2 << 3 << 5 << 8 << 13 << 8 << 5;
    *set3 << 5 << 6 << 7 << 3 << 4 << 5;
    *set4 << 9 << 7 << 5 << 3 << 1 << 2;
//![1]

//![2]
    QPercentBarSeries *series = new QPercentBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);
//![2]

//![3]
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statestique du cabinet");
    chart->setAnimationOptions(QChart::SeriesAnimations);
//![3]

//![4]
    QStringList categories;
    categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
//![4]

//![5]
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
//![5]

//![6]
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
//![6]

//![7]

    window=new MainWindow(this);

    window->setCentralWidget(chartView);
    window->resize(420, 300);
    window->show();
//![7]

}


void MainWindow::on_pushButton_30_clicked()
{
    QString strStream;
                    QTextStream out(&strStream);

                    const int rowCount = ui->tableView_14->model()->rowCount();
                    const int columnCount = ui->tableView_14->model()->columnCount();

                    out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("strTitle")
                        <<  "</head>\n"
                        "<body bgcolor=#ffffff link=#5000A0>\n"

                       //     "<align='right'> " << datefich << "</align>"
                        "<center> <H1>Liste des ordonnances </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                    // headers
                    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tableView_14->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tableView_14->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";

                    // data table
                    for (int row = 0; row < rowCount; row++) {
                        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                        for (int column = 0; column < columnCount; column++) {
                            if (!ui->tableView_14->isColumnHidden(column)) {
                                QString data = ui->tableView_23->model()->data(ui->tableView_14->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_pushButton_19_clicked()
{

    QTableView *table;

                    table = ui->tableView_13;


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
void MainWindow::read_botton(){
   /* arduino a ;
    data1=a.read_from_arduino();
    a.connect_arduino();
    qDebug()<<"data"<<data1;
    if(data1=="2"){


        QMessageBox::information(nullptr, QObject::tr("ARDUINO"),

                                  QObject::tr("PATIENT SUIVANT .\n"

                                              "Click OK to exit."), QMessageBox::Ok);*/

   }



