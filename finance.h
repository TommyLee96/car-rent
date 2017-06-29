#ifndef FINANCE_H
#define FINANCE_H

#include <QDialog>

namespace Ui {
class finance;
}

class finance : public QDialog
{
    Q_OBJECT

public:
    explicit finance(QWidget *parent = 0);
    ~finance();

private slots:
    void show1(int state);
    void show2(int state);
    void show3(int state);

    void on_pushButton_clicked();

private:
    Ui::finance *ui;
};

#endif // FINANCE_H
