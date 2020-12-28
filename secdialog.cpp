#include "secdialog.h"
#include "ui_secdialog.h"
#include "facture.h"
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
#include "facture.h"


SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
}

SecDialog::~SecDialog()
{
    delete ui;
}

void SecDialog::on_pushButton_clicked()
{
    QString num;

    num=ui->lineEdit->text();




     facture f(num);
    bool test= f.modifier(num);

    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("Modifier un   PRODUIT"),
                          QObject::tr("  PRODUIT Modifié.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
          ui->tableView->setModel(fct.afficher());//refresh
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un   PRODUIT"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }


}
