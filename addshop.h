#ifndef ADDSHOP_H
#define ADDSHOP_H

#include <QDialog>

namespace Ui {
class addshop;
}

class addshop : public QDialog
{
    Q_OBJECT

public:
    explicit addshop(QWidget *parent = 0);
    ~addshop();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addshop *ui;
};

#endif // ADDSHOP_H
