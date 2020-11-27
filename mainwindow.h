#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "produit.h"
#include "fournisseur.h"
#include <QMessageBox>
#include <QSystemTrayIcon>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void notif(QString t,QString m);

private slots:
    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_lineEdit_6_cursorPositionChanged(int arg1, int arg2);

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_lineEdit_15_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_6_textChanged(const QString &arg1);

    void on_lineEdit_17_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_6_selectionChanged();

    void on_pushButton_9_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_lineEdit_17_returnPressed();

    void on_pushButton_7_clicked();

    void on_lineEdit_7_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_7_textChanged(const QString &arg1);

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    PRODUIT tmpproduit;
    FOURNISSEUR tmpfournisseur ;
};
#endif // MAINWINDOW_H
