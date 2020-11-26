#include "stat.h"
#include "ui_stat.h"

stat::stat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::stat)
{
    ui->setupUi(this);
}

stat::~stat()
{
    delete ui;
}
