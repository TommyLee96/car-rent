#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
class QSqlTableModel;
namespace Ui {
class admin;
}

class admin : public QDialog
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = 0);
    ~admin();
    //QVariant  var_5;
private slots:
    void on_pushButton_clicked();
    void show1();
    void show2();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void showinfo(int row);
    void showinfo2(int row);
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();

private:
    Ui::admin *ui;
   // Ui::admin *completer;
    QSqlTableModel *model;
    QSqlTableModel *model2;
    QSqlTableModel *model3;
    QSqlTableModel *model4;

};

#endif // ADMIN_H
