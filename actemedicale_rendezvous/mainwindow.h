#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include "actemedicale.h"
#include "rendezvous.h"
#include <iostream>

#include <QMessageBox>

#include  <QDebug>

#include <QRadioButton>

#include<QtPrintSupport/QPrinter>

#include<QPdfWriter>

#include <QPainter>

#include<QFileDialog>

#include<QTextDocument>

#include <QTextEdit>

#include <QtSql/QSqlQueryModel>

#include<QtPrintSupport/QPrinter>

#include <QVector2D>

#include <QVector>

#include <QSqlQuery>

#include<QDesktopServices>

#include <QMessageBox>

#include<QUrl>

#include <QPixmap>

#include <QTabWidget>

#include <QValidator>

#include <QPrintDialog>

#include<QtSql/QSqlQuery>

#include<QVariant>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_3_clicked();

    void on_modifier_clicked();

    void on_pushButton_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_2_cursorPositionChanged(int arg1, int arg2);

    void on_tableView_2_activated(const QModelIndex &index);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_lineEdit_10_textChanged(const QString &arg1);

    void on_lineEdit_4_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
actemedicale tmpacte ;
rendezvous tmprendez ;
};
#endif // MAINWINDOW_H
