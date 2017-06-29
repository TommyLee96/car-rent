#include "finance.h"
#include "ui_finance.h"
#include <QDebug>
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
    connect(ui->checkBox,SIGNAL(stateChanged(int)),this,SLOT(show1(int)));
    connect(ui->checkBox_2,SIGNAL(stateChanged(int)),this,SLOT(show2(int)));
    connect(ui->checkBox_3,SIGNAL(stateChanged(int)),this,SLOT(show3(int)));

}

finance::~finance()
{
    delete ui;
}
void finance::show1(int state)
{
    //ui->dateEdit_4->setEnabled(0);
           // ui->dateEdit_5->setEnabled(1);
        if (state == Qt::Checked) // "选中"
        {
            ui->dateEdit->setEnabled(0);
            ui->dateEdit_2->setEnabled(0);
        }
        else if(state == Qt::PartiallyChecked) // "半选"
        {
            ui->dateEdit->setEnabled(0);
            ui->dateEdit_2->setEnabled(0);
        }
        else // 未选中 - Qt::Unchecked
        {
           ui->dateEdit->setEnabled(1);
           ui->dateEdit_2->setEnabled(1);
        }

    qDebug()<<"响应时间";

}
void finance::show2(int state)
{
    //ui->dateEdit_4->setEnabled(0);
           // ui->dateEdit_5->setEnabled(1);
        if (state == Qt::Checked) // "选中"
        {
            ui->comboBox->setEnabled(0);
            //ui->dateEdit_5->setEnabled(0);
        }
        else if(state == Qt::PartiallyChecked) // "半选"
        {
            ui->comboBox->setEnabled(0);
        }
        else // 未选中 - Qt::Unchecked
        {
           ui->comboBox->setEnabled(1);
        }

    qDebug()<<"响应时间";

}
void finance::show3(int state)
{
    //ui->dateEdit_4->setEnabled(0);
           // ui->dateEdit_5->setEnabled(1);
        if (state == Qt::Checked) // "选中"
        {
            ui->comboBox_2->setEnabled(0);
            //ui->dateEdit_5->setEnabled(0);
        }
        else if(state == Qt::PartiallyChecked) // "半选"
        {
            ui->comboBox_2->setEnabled(0);
        }
        else // 未选中 - Qt::Unchecked
        {
           ui->comboBox_2->setEnabled(1);
        }

    qDebug()<<"响应时间";

}
