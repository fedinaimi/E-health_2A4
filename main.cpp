#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include <QtDebug>
#include <QtUiTools/QtUiTools>
#include <QPushButton>
#include "connexion.h"
#include "wwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WWindow wwindow;
    QMainWindow window;
    try {
        wwindow.show();



} catch (QString s) {
    qDebug()<<s;

}
    return a.exec();
}
