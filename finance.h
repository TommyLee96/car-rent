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

private:
    Ui::finance *ui;
};

#endif // FINANCE_H
