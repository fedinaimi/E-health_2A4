#include "menu.h"
#include "ui_menu.h"
#include "ordon.h"
#include "medic.h"
menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_pushButton_clicked()
{
    hide();
     ordon o;
     o.setModal(true);
     o.exec();
}

void menu::on_pushButton_3_clicked()
{
    hide();
     medic m;
     m.setModal(true);
     m.exec();
}

void menu::on_pushButton_2_clicked()
{
    exit(0);
}
