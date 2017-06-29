#include "finance.h"
#include "ui_finance.h"
#include<global.h>
#include <QDebug>
#include<QSqlQuery>
#include<QMessageBox>
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
    QSqlQuery query11;
    query11.exec(QString("select cartypeid,carmodel from carmodel"));
    while(query11.next())
    {
       ui->comboBox_2->addItem(query11.value(0).toString()+'-'+query11.value(1).toString());

    }
    QSqlQuery query12;
    query12.exec(QString("select shopid,shopaddress from shopinfo"));
    while(query12.next())
    {
       ui->comboBox->addItem(query12.value(0).toString()+'-'+query12.value(1).toString());

    }
    ui->tableWidget->verticalHeader()->setVisible(false); //设置垂直头不可见
    ui->tableWidget->horizontalHeader()->setVisible(false);
}

finance::~finance()
{
    delete ui;
}
void finance::show1(int state)
{

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

        if (state == Qt::Checked) // "选中"
        {
            ui->comboBox_2->setEnabled(0);
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
void finance::show3(int state)
{

        if (state == Qt::Checked) // "选中"
        {
            ui->comboBox->setEnabled(0);
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

void finance::on_pushButton_clicked()
{
    ui->tableWidget->setRowCount(3);  //行
    ui->tableWidget->setColumnCount(2); // 列

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("订单数量"));
    ui->tableWidget->setItem(1,0,new QTableWidgetItem("总金额"));
    ui->tableWidget->setItem(2,0,new QTableWidgetItem("均价"));

    /*订单数量
     * q.exec("select count(id) as iCount from xx");
     if (q.next())
     {
      q.value(0).toInt();
     }
     */

    QString strqueryOrders=QString("select realmoney from rentinfo where rentstatus='1'");

   /* if(ui->comboBoxVtypeS->currentIndex()>0)
    strqueryOrders.append(QString(" and VtypeID=%1").arg(ui->comboBoxVtypeS->currentIndex()));
    if(!ui->lineEditCarnoS->text().trimmed().isEmpty())
    strqueryOrders.append(QString(" and Vno='%1'").arg(ui->lineEditCarnoS->text().trimmed()));
    qDebug()<<"debug1"<<strqueryOrders;
*/
    if(ui->checkBox->isChecked())     //所有时间
    {
      qDebug()<<"所有时间"<<"debug2";
    }
    else                              //获取时间段，时间段开始小于结束判断
    {
        if(ui->dateEdit->date().daysTo(ui->dateEdit_2->date())<=0)
        {
             QMessageBox::information(this,tr("提示"),tr("请输入正确时间间隔！      \n\n     "));
        }
        else  //时间间隔正确
        {
            qDebug()<<"按时间段"<<"debug3";
            strqueryOrders.append(QString(" and rentbegin='%1'' and realend='%2'").arg(ui->dateEdit->text()).arg(ui->dateEdit_2->text()));

        }
    }
    if(ui->checkBox_2->isChecked())   //所有车型
    {
          qDebug()<<"debug4"<<"所有车型";
    }
    else                              //获取车型
    {
          QString a=ui->comboBox_2->currentText();
          QString first = a.split('-', QString::SkipEmptyParts).first();
          QString second = a.split('-', QString::SkipEmptyParts).last();
          strqueryOrders.append(QString(" and carid='%1'").arg(first.toInt()));
          qDebug()<<"按车型"<<"debug5";
          qDebug()<<first.toInt()<<second<<"hehhehe";
    }
    if(ui->checkBox_3->isChecked())   //所有门店
    {
          qDebug()<<"debug4"<<"所有门店";
    }
    else                              //获取门店
    {
        QString b=ui->comboBox->currentText();
        QString first = b.split('-', QString::SkipEmptyParts).first();
        QString second = b.split('-', QString::SkipEmptyParts).last();
        strqueryOrders.append(QString(" and shopid='%1'").arg(first.toInt()));
        qDebug()<<"按车型"<<"debug5";

        qDebug()<<"获取门店hehhehe"<<first.toInt();
    }
    qDebug()<<shopid<<strqueryOrders<<"debug6";
    QSqlQuery query3;
    query3.exec(strqueryOrders) ;//"delete from carmodel where carmodelid=")
    int num=0;
    int total=0;
    while(query3.next())
    {
        num++;
        total=query3.value(0).toInt()+total;
        qDebug()<< query3.value(0).toInt();
    }
    ui->tableWidget->setItem(0,1,new QTableWidgetItem(QString::number(num)));
    ui->tableWidget->setItem(1,1,new QTableWidgetItem(QString::number(total)));
    if(total!=0)
    {
        ui->tableWidget->setItem(2,1,new QTableWidgetItem(QString::number(total/num)));
    }
    else
    {
        ui->tableWidget->setItem(2,1,new QTableWidgetItem("没有记录"));
    }
        qDebug()<<"total money"<<num<<total;

}
