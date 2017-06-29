#include "addshop.h"
#include "ui_addshop.h"
#include<QMessageBox>
#include<QSqlQuery>
#include<QDate>
#include"global.h"
#include <QDebug>

addshop::addshop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addshop)
{
    ui->setupUi(this);
}

addshop::~addshop()
{
    delete ui;
}

void addshop::on_pushButton_clicked()
{
    if(ui->lineEdit->text().isEmpty()||ui->lineEdit_2->text().isEmpty()||ui->lineEdit_3->text().isEmpty()||ui->lineEdit_4->text().isEmpty()||ui->lineEdit_5->text().isEmpty())
    {
        QMessageBox::information(this,tr("提示"),tr("请输入完整信息！      \n\n     "));

    }
    else
    {
        QSqlQuery query2;
        query2.exec(QString("select clientid from clientinfo"));
        int flagshop=0;
        while(query2.next())
        {
            qDebug()<<"flagggggggggg1"<<query2.value(0).toInt()<<ui->lineEdit->text().toInt();
            if(query2.value(0).toInt()==ui->lineEdit->text().toInt())
            {
               flagshop=1;
               qDebug()<<"flagshop1"<<flagshop<<QTime::currentTime().toString(Qt::ISODate);
            }

        }
        qDebug()<<"flagshop2"<<flagshop<<QTime::currentTime().toString(Qt::ISODate);

        if(flagshop==1)
        {
            QMessageBox::information(this,tr("提示"),tr("该用户名已经注册，请换一个！      \n\n     "));

        }
        else
        {
            QSqlQuery query2;
            query2.prepare("insert into clientinfo(clientid,password,type,creater,amenddate,flag) values(?,?,?,?,?,?)");
            query2.addBindValue(ui->lineEdit->text());
            query2.addBindValue(ui->lineEdit_2->text());
            query2.addBindValue(2);
            query2.addBindValue(creator);
            query2.addBindValue(QString(QDateTime::currentDateTime().toString("yyyy-MM-dd")));
            query2.addBindValue(0);
            query2.exec();
            QSqlQuery query3;
            query3.prepare("insert into shopinfo(shopkeeper,shopaddress,shoptel,creater,amenddate,flag,ownername) values(?,?,?,?,?,?,?)");
            query3.addBindValue(ui->lineEdit->text());
            query3.addBindValue(ui->lineEdit_3->text());
            query3.addBindValue(ui->lineEdit_4->text());
            query3.addBindValue(creator);
            query3.addBindValue(QString(QDateTime::currentDateTime().toString("yyyy-MM-dd")));
            query3.addBindValue(0);
            query3.addBindValue(ui->lineEdit_5->text());
            qDebug()<<ui->lineEdit->text().toInt()<<ui->lineEdit_3->text()<<ui->lineEdit_4->text()<<creator<<"傻逼习近平9999999999";
            query3.exec();
            this->close();
        }
    }
}
