#include "finance.h"
#include "ui_finance.h"

finance::finance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::finance)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit->setCalendarPopup(true);
    ui->dateEdit->setDisplayFormat("yyyy-MM-dd");
    ui->dateEdit_2->setDate(QDate::currentDate());
    ui->dateEdit_2->setCalendarPopup(true);
    ui->dateEdit_2->setDisplayFormat("yyyy-MM-dd");
}

finance::~finance()
{
    delete ui;
}
