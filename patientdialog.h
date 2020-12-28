#ifndef PATIENTDIALOG_H
#define PATIENTDIALOG_H

#include <QDialog>
#include "patient.h"
#include "wwindow.h"

namespace Ui {
class PatientDialog;
}

class PatientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PatientDialog(QWidget *parent = nullptr);
    ~PatientDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::PatientDialog *ui;
    patient ptn;
};

#endif // PATIENTDIALOG_H
