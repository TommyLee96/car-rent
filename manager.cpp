#include "manager.h"
#include "ui_manager.h"
#include<QDateEdit>
#include <QDebug>
#include<QDate>
#include <QMessageBox>
#include<QSqlQuery >
#include <QSqlQueryModel>
#include <QSqlTableModel>
manager::manager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manager)
{
    ui->setupUi(this);
    ui->dateEdit->setCalendarPopup(true);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_2->setDate(QDate::currentDate());
    ui->dateEdit_2->setCalendarPopup(true);
    ui->dateEdit->setDisplayFormat("yyyy-MM-dd");
    ui->dateEdit_2->setDisplayFormat("yyyy-MM-dd");
    ui->dateEdit->setMinimumDate(QDate::currentDate().addDays(0));  //限制有效日期的范围
    ui->dateEdit_2->setMinimumDate(QDate::currentDate().addDays(0));  // -365天
    model = new QSqlQueryModel(this);
   model->setQuery(QString("select carid from carinfo where carid in(select carid from rentinfo where rentbegin>'%1' or preend<'%2')").arg(ui->dateEdit_2->text()).arg(ui->dateEdit->text()));
    model->setHeaderData(0, Qt::Horizontal, tr("车牌"));
    ui->tableView->setModel(model);

    ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(46,46,46),stop:1 rgb(66,66,66));color: rgb(210,210,210);;padding-left: 4px;border: 1px solid #383838;}"); //设置表头背景色
    ui->tableView->setAlternatingRowColors(true); //使用交替行颜色
    qDebug()<<ui->dateEdit->date().daysTo(ui->dateEdit_2->date())<<"oooo"<<ui->dateEdit_2->text()<<ui->dateEdit_2->text().mid(0,4).toInt()<<ui->dateEdit_2->text().mid(5,2).toInt()<<ui->dateEdit_2->text().mid(8,2).toInt();
    connect(ui->tableView, SIGNAL(clicked ( const QModelIndex &)), this,SLOT(show3()));


}
void manager::show3()
{

        int curRow = ui->tableView->currentIndex().row();
       qDebug()<<model->index(curRow,0).data().toInt()<<model->index(curRow,1).data().toString();
     showinfo3(model->index(curRow,0).data().toInt());

}

void manager::showinfo3(int row)
{
    QSqlQuery query;
    query.exec(QString("select * from carinfo where carid='%1'").arg(row));
    while(query.next())

    {
        ui->label->setText(query.value(0).toString());   //label存储点击哪一辆车
        ui->label_2->setText(query.value(1).toString());
        ui->label_3->setText(query.value(3).toString());
        ui->label_4->setText(query.value(4).toString());
        ui->label_5->setText(query.value(5).toString());
        ui->label_6->setText(query.value(6).toString());
        ui->label_7->setText(query.value(7).toString());
        ui->label_8->setText(query.value(8).toString());
        ui->label_9->setText(query.value(9).toString());
        ui->label_10->setText(query.value(10).toString());
        ui->label_11->setText(query.value(11).toString());
        QPixmap photo2;
        int g=query.value(1).toInt();
        QSqlQuery query2;
        query2.exec(QString("select carphoto from carmodel where cartypeid='%1'").arg(g));
        while(query2.next())
        {
        photo2.loadFromData(query2.value(0).toByteArray(), "jpg");
        if(photo2.isNull())
        {
            QPixmap pixmap2;
            pixmap2=QPixmap(":/1.png");
            //m_pLabel->setPixmap(pixmap);
            //QPixmap *pixmap=new QPixmap(:/1.png);
            ui->label_12->setPixmap(pixmap2);
            pixmap2.scaled(ui->label_12->size());//图像适应label大小

        }
        else
        {
            ui->label_12->setPixmap(photo2);
        }
        }
    }
}

manager::~manager()
{
    delete ui;
}

void manager::on_pushButton_clicked()
{
    qDebug()<<ui->dateEdit->date().daysTo(ui->dateEdit_2->date())<<"oooo"<<ui->dateEdit_2->text()<<ui->dateEdit_2->text().mid(0,4).toInt()<<ui->dateEdit_2->text().mid(5,2).toInt()<<ui->dateEdit_2->text().mid(8,2).toInt();
  if(ui->dateEdit->date().daysTo(ui->dateEdit_2->date())<=0)
  {
      QMessageBox::information(this,tr("提示"),tr("请输入正确时间间隔！      \n\n     "));
  }
  else     //显示可以被租出去的车
  {
      if(ui->dateEdit->date()<ui->dateEdit_2->date())
      {
      qDebug()<<"jsjsajcjs";
      }
      model->setQuery(QString("select carid from carinfo where carid in(select carid from rentinfo where rentbegin>'%1')").arg(ui->dateEdit_2->text()));
//      model->setQuery(QString("select carid from carinfo where carid in(select carid from rentinfo where rentbegin>'%1' or preend<'%2')").arg(ui->dateEdit_2->text()).arg(ui->dateEdit->text()));

      //先查所有车辆，然后在订单表子查询结束时间比订单表开始时间早或者开始时间比结束时间晚
     /* model->setFilter(QString("name like '%%1%' AND "
      "type like '%%2%' AND "
      "description like '%%3%'")
      .arg(searchitem1)
      .arg(searchitem2)
      .arg(searchitem3));
      model->select();

      model->setEditStrategy(QSqlTableModel::OnManualSubmit);*/
  }
  //model->select();
}
