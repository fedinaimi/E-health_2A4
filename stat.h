#ifndef STAT_H
#define STAT_H

#include <QMainWindow>

namespace Ui {
class stat;
}

class stat : public QMainWindow
{
    Q_OBJECT

public:
    explicit stat(QWidget *parent = nullptr);
    ~stat();

private:
    Ui::stat *ui;
};

#endif // STAT_H
