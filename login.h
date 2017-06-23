#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();
    int flag;  //  2 为财务 1为管理员   0用户

private slots:
    void on_pushButton_clicked();

private:
    Ui::login *ui;
    int flag_finance;
    int flag_admin;
    int flag_manager;
};

#endif // LOGIN_H
