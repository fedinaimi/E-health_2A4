#include "login.h"
#include "ui_login.h"

/*Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}*/

Login::~Login()
{
    delete ui;
}

void Login::on_label1_linkActivated(const QString &link)
{

}
