#ifndef MANAGER_H
#define MANAGER_H

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

private slots:
    void on_pushButton_clicked();
    void show3();
    void showinfo3(int row);
private:
    Ui::manager *ui;
    QSqlQueryModel *model;
};

#endif // MANAGER_H
