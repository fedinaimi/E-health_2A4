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
private slots:
    void refresh();

    void on_pushButton_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_3_clicked();
    void on_lineEdit_2_textChanged(const QString &arg1);
    void on_pushButton_4_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_10_clicked();
};

#endif // WWINDOW_H
