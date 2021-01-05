#include "mainwindow.h"
#include <QApplication>
#include<QMessageBox>
#include<QDebug>
#include "connexion.h"
#include "loginsystem.h"
#include<QtTextToSpeech/QTextToSpeech>
#include <QMediaPlayer>


int main(int argc, char *argv[])
{

    QApplication a(argc ,argv);
    connexion c ;


    bool test=c.ouvrirconnexion();
    QMediaPlayer * player = new QMediaPlayer();

 // MainWindow w;
  //w.show();
   // return a.exec();


   LoginSystem l;


    if(test)
    {
        QMessageBox::question(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successfull.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);





        l.show();
        player->setMedia(QUrl("qrc:/new/prefix1/Resources/afterinfinity-science-medicine-royalty-free-music.mp3"));
        player->setVolume(100);
        player->play();









    }
       else
            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("connection failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);



        return a.exec();


}


