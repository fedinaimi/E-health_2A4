#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "mainwindow1.h"
#include <QtTextToSpeech/QTextToSpeech>
#include <QTextDocument>
#include "connection.h"
#include <QObject>
#include <QString>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnect();
    MainWindow w;
    if(test)
    {
        w.show();
        /*QTextToSpeech*m_speech=new QTextToSpeech();
        m_speech->say("database is open ");*/

        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}