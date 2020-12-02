#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->tableView->setModel(tmpproduit.afficher());
     ui->tableView_2->setModel(tmpfournisseur.afficher());//refresh
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
    close();
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
                        <<  QString("<title>%1</title>\n").arg("strTitle")
                        <<  "</head>\n"
                        "<body bgcolor=#ffffff link=#5000A0>\n"

                       //     "<align='right'> " << datefich << "</align>"
                        "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

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


