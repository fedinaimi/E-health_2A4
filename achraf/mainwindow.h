#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "commande.h"
#include "utilisateur.h"
#include <QDialog>
#include <QMainWindow>
#include <QSound>
#include "arduino.h"





QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{

    Q_OBJECT;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int led,alert,messageboxactive;


private slots:
    //arduino
         void update_label();
         //finarduino

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_14_clicked();

    void on_lineEdit_6_textChanged(const QString &arg1);



    void on_pushButton_15_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_18_clicked();

private:

    Ui::MainWindow *ui;
    commande ajt ;
    utilisateur psm ;
QSound*clickSound;
//arduino
      QByteArray data;
      Arduino A;

};

#endif // MAINWINDOW_H