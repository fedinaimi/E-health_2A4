#include "mainwindow.h"
#include <QApplication>
#include<QMessageBox>
#include<QDebug>
#include "connexion.h"
int main(int argc, char *argv[])
{
    QApplication a(argc ,argv);
    connexion c ;
    bool test=c.ouvrirconnexion();
    MainWindow w ;

    if(test)
    {
        QMessageBox::question(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successfull.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        w.show();}
    else
            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("connection failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);



        return a.exec();


}


