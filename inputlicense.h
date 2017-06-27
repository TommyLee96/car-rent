#ifndef INPUTLICENSE_H
#define INPUTLICENSE_H

#include <QDialog>

namespace Ui {
class inputlicense;
}

class inputlicense : public QDialog
{
    Q_OBJECT

public:
    explicit inputlicense(QWidget *parent = 0);
    ~inputlicense();

private slots:
    void on_pushButton_clicked();

private:
    Ui::inputlicense *ui;
};

#endif // INPUTLICENSE_H
