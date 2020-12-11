#ifndef MAINWINDOW1_H
#define MAINWINDOW1_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow1; }
QT_END_NAMESPACE

class mainwindow1: public QMainWindow
{
    Q_OBJECT

public:
   mainwindow1(QWidget *parent = nullptr);
    ~mainwindow1();

private slots:
    void on_MainWindow1_iconSizeChanged(const QSize &iconSize);

    void on_pushButton_clicked();

private:
    Ui::mainwindow1 *ui;
};
#endif // MAINWINDOW_H
