#ifndef WWINDOW_H
#define WWINDOW_H
#include "facture.h"
#include "patient.h"
#include <QMainWindow>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>
#include <QtWidgets/QApplication>
#include <QDialog>
#include "secdialog.h"
#include "patientdialog.h"

#include <QLineEdit>
namespace Ui {
class WWindow;
}

class WWindow : public QDialog
{
    Q_OBJECT

public:
    explicit WWindow(QWidget *parent = nullptr);
    ~WWindow();

private:
    Ui::WWindow *ui;
    facture fct ;
    patient ptn;
    SecDialog *secd;
PatientDialog *patd;


private slots:
    void refresh();

    void on_pushButton_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_6_clicked();
    //void on_pushButton_3_clicked();//
    void on_lineEdit_2_textChanged(const QString &arg1);
    void on_pushButton_4_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_10_clicked();
    void on_lineEdit_9_cursorPositionChanged(const QString &arg2);

    void on_tableView_2_activated(const QModelIndex &index);
    void on_pushButton_14_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_lineEdit_2_cursorPositionChanged(int arg1, int arg2);
    void on_lineEdit_9_cursorPositionChanged(int arg1, int arg2);
    void on_comboBox_activated(const QString &arg1);
    void on_comboBox_4_activated(const QString &arg1);
    void on_lineEdit_9_textChanged(const QString &arg1);
};

#endif // WWINDOW_H
