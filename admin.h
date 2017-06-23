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

    void on_pushButton_2_clicked();

private:
    Ui::admin *ui;
    QSqlTableModel *model;
    QSqlTableModel *model2;
    QSqlTableModel *model3;
    QSqlTableModel *model4;

};

#endif // ADMIN_H
