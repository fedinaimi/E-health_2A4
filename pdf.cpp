#include <QDebug>
#include <string>
#include "pdf.h"
#include "ui_pdf.h"
#include "chambre_lampe.h"
#include <QPrinter>
pdf::pdf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pdf)
{
    ui->setupUi(this);
}

pdf::~pdf()
{
    delete ui;
}

void pdf::on_pushButton_clicked()
{
    chambre_lampe cl ;
    QString Id_lampe=ui->lineEdit->text() ;
    QString text=cl.apercu(Id_lampe);
    ui->textEdit->setText(text);

    QPrinter printer ;
  //  printer.setPrinterName("nom");
    ui ->textEdit->print(&printer);
}

void pdf::on_pushButton_2_clicked()
{
    parentWidget()->show();
    this->deleteLater();
}




