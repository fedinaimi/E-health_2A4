#ifndef ORDON_H
#define ORDON_H

#include <QDialog>
#include "menu.h"
#include "ordonnance.h"
namespace Ui {
class ordon;
}

class ordon : public QDialog
{
    Q_OBJECT

public:
    explicit ordon(QWidget *parent = nullptr);
    ~ordon();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_14_clicked();

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();



    void on_pushButton_66_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_12_clicked();

private:
    Ui::ordon *ui;
    Ordonnance otmp;

};

#endif // ORDON_H
