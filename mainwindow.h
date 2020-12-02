#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "produit.h"
#include "fournisseur.h"
#include <QMessageBox>
#include <QSystemTrayIcon>


#include "ui_mainwindow.h"



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
#include <QtCharts>
#include <QtDataVisualization>
#include <QGraphicsItem>
#include <QtCharts>
#include <QBarSeries>
#include <QBarSet>


using namespace QtDataVisualization;
using namespace QtCharts;


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

    void on_lineEdit_18_cursorPositionChanged(int arg1, int arg2);

    void on_tabWidget_2_currentChanged(int index);

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_widget_customContextMenuRequested(const QPoint &pos);

private:
    Ui::MainWindow *ui;
    PRODUIT tmpproduit;
    FOURNISSEUR tmpfournisseur ;
};
#endif // MAINWINDOW_H
