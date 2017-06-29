#ifndef MANAGER_H
#define MANAGER_H
#include"rotatedproxymodel.h"
#include <QDialog>
class QSqlTableModel;
class QSqlQueryModel;
namespace Ui {
class manager;
}

class manager : public QDialog
{
    Q_OBJECT

public:
    explicit manager(QWidget *parent = 0);
    ~manager();
    //QSqlQueryModel *model;

private slots:
    void on_pushButton_clicked();
    void show3();
    void show4();
    void show5(int state);
    void show6(int state);
    void showinfo3(int row);
    void showinfo4(int row);
    void on_pushButton_2_clicked();
    void getcar();

    void on_pushButton_3_clicked();
    void on_tableView_2_clicked(const QModelIndex &index);
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();



private:
    Ui::manager *ui;
    QSqlQueryModel *model;//租车
    QSqlQueryModel *model2; //还车
    RotatedProxyModel *standardModel;

};

#endif // MANAGER_H
