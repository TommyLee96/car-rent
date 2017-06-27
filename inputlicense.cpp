#include "inputlicense.h"
#include "ui_inputlicense.h"
#include"inputlicense.h"
#include"global.h"
#include"manager.h"
#include <QMessageBox>
#include <QDebug>
#include<QSqlQuery>
#include<QDate>
inputlicense::inputlicense(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inputlicense)
{
    ui->setupUi(this);
    manager* manager1 = new manager();//实例化类的对象
    connect(ui->pushButton, SIGNAL(clicked()), manager1, SLOT(getcar()));
    ui->dateEdit->setCalendarPopup(true);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_2->setDate(QDate::currentDate());
    ui->dateEdit_2->setCalendarPopup(true);
    ui->dateEdit->setDisplayFormat("yyyy-MM-dd");
    ui->dateEdit_2->setDisplayFormat("yyyy-MM-dd");
    ui->label_2->setText(licensenumber);
    ui->spinBox->setRange(0,100);
}

inputlicense::~inputlicense()
{
    delete ui;
}

void inputlicense::on_pushButton_clicked()
{
    if(ui->lineEdit->text().length()==0||ui->lineEdit_2->text().length()==0)
    {
       QMessageBox::information(this,tr("提示"),tr("请输入完整信息！      \n\n     "));
    }
    else
    {
       QSqlQuery query;
       query.prepare("INSERT INTO licenseid(licensenum,licensetype,drivername,sex,driveage,legaldate,illegaldate,creater,amenddate) values(:licensenum,:licensetype,:drivername,:sex,:driveage,:legaldate,:illegaldate,:creater,:amenddate)");
       query.bindValue(":licensenum",ui->label_2->text());
       query.bindValue(":licensetype",QString(ui->lineEdit->text()));
       query.bindValue(":drivername",QString(ui->lineEdit_2->text()));
       query.bindValue(":sex",QString(ui->comboBox->currentText()));
       query.bindValue(":driveage",ui->spinBox->value());
       query.bindValue(":legaldate",ui->dateEdit->text());
       query.bindValue(":illegaldate",ui->dateEdit_2->text());
       query.bindValue(":creater",creator);
       query.bindValue(":amenddate",QString(QDateTime::currentDateTime().toString("yyyy-MM-dd")));
       query.exec();
       this->close();
       /*下面是租车操作，同inputlicense类，
        * 需要manager类传递 开始，结束，驾驶证号三个信息
        *
        *
        *
        *
        * */
    }
}
