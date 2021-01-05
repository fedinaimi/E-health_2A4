#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "commande.h"
#include <QDialog>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{

    Q_OBJECT;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

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

private:
    Ui::MainWindow *ui;
    commande ajt ;

};
#endif // MAINWINDOW_H


.....
