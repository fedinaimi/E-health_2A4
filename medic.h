#ifndef MEDIC_H
#define MEDIC_H

#include <QDialog>
#include "menu.h"
#include "Medicament.h"
namespace Ui {
class medic;
}

class medic : public QDialog
{
    Q_OBJECT

public:
    explicit medic(QWidget *parent = nullptr);
    ~medic();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

    void on_pb_ajouter_3_clicked();

    void on_pb_supprimer_3_clicked();


    void on_lineEdit_6_textChanged(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::medic *ui;
Medicament etmp;

};



#endif // MEDIC_H
