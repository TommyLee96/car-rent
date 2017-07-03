#include<QFile>
#include<QTime>
#include<QSqlQuery>
#include<QFileDialog>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QTableView>
#include <QSqlError>
#include <QDebug>
#include<QString>
#include <QMessageBox>
#include <QtNetwork>
//#include <QSqlError>
#include "admin.h"
#include "ui_admin.h"
#include"global.h"
#include"addshop.h"
#include <QSqlRelationalDelegate>
#include<QDate>
QVariant  var_5(100);
admin::admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
    connect(ui->tableView_2, SIGNAL(clicked ( const QModelIndex &)), this,SLOT(show1()));
    model2 = new QSqlQueryModel(this);
    model2->setQuery(QString("select * from carmodel where flag!=1"));
   // model2->sort(0,Qt::AscendingOrder);
   // model2->sort(0, Qt::DescendingOrder);
    ui->tableView_2->setModel(model2);
    //model2->sort(0, Qt::DescendingOrder);
    model2->sort(0,Qt::AscendingOrder);
    ui->tableView_2->hideColumn(0);
    ui->tableView_2->hideColumn(2);
    ui->tableView_2->hideColumn(3);
    ui->tableView_2->hideColumn(4);
    ui->tableView_2->hideColumn(5);
    ui->tableView_2->hideColumn(6);
    ui->tableView_2->hideColumn(7);
    ui->tableView_2->hideColumn(8);
    ui->tableView_2->hideColumn(9);
    ui->tableView_2->hideColumn(10);
    ui->tableView_2->hideColumn(11);
    //model2->setHeaderData(1, Qt::Horizontal, tr("车型"));
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  //设置表格列宽度自适应
    ui->tableView_2->verticalHeader()->setVisible(false);
    ui->tableView_2->setSelectionBehavior ( QAbstractItemView::SelectRows);
    ui->tableView_2->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(46,46,46),stop:1 rgb(66,66,66));color: rgb(210,210,210);;padding-left: 4px;border: 1px solid #383838;}"); //设置表头背景色
    ui->tableView_2->setAlternatingRowColors(true); //使用交替行颜色
    qDebug()<<"currentTime2--"<<QTime::currentTime().toString(Qt::ISODate);
    connect(ui->tableView, SIGNAL(clicked ( const QModelIndex &)), this,SLOT(show2()));
    model3 = new QSqlQueryModel(this);
    model3->setQuery(QString("select * from carinfo where flag!=1"));   //flag=0说明没有被删除
    model3->sort(0,Qt::DescendingOrder);
    ui->label->hide();
    ui->label_14->hide();
    ui->label_15->hide();
    ui->label_16->hide();
    ui->label_40->hide();
    ui->tableView->setModel(model3);
    ui->tableView->hideColumn(0);
    ui->tableView->hideColumn(1);
    ui->tableView->hideColumn(2);
    ui->tableView->hideColumn(4);
    ui->tableView->hideColumn(5);
    ui->tableView->hideColumn(6);
    ui->tableView->hideColumn(7);
    ui->tableView->hideColumn(8);
    ui->tableView->hideColumn(9);
    ui->tableView->hideColumn(10);
    ui->tableView->hideColumn(11);
    ui->tableView->hideColumn(12);
    ui->tableView->hideColumn(13);
    //model3->setHeaderData(3, Qt::Horizontal, tr("车牌"));
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  //设置表格列宽度自适应
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(46,46,46),stop:1 rgb(66,66,66));color: rgb(210,210,210);;padding-left: 4px;border: 1px solid #383838;}"); //设置表头背景色
    ui->tableView->setAlternatingRowColors(true); //使用交替行颜色
    showinfo(model2->index(15,0).data().toInt());
    showinfo2(model2->index(5,0).data().toInt());
    ui->lineEdit->setStyleSheet("background-color:transparent");
    ui->lineEdit_2->setStyleSheet("background-color:transparent");
    ui->lineEdit_3->setStyleSheet("background-color:transparent");
    ui->lineEdit_4->setStyleSheet("background-color:transparent");
    ui->lineEdit_5->setStyleSheet("background-color:transparent");
    ui->lineEdit_6->setStyleSheet("background-color:transparent");
    //model5 = new QSqlQueryModel(this);
    ui->dateEdit->setCalendarPopup(true);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_2->setDate(QDate::currentDate());
    ui->dateEdit_2->setCalendarPopup(true);
    ui->dateEdit->setDisplayFormat("yyyy-MM-dd");
    ui->dateEdit_2->setDisplayFormat("yyyy-MM-dd");
    ui->dateEdit_3->setCalendarPopup(true);
    ui->dateEdit_3->setDate(QDate::currentDate());
    ui->dateEdit_3->setDisplayFormat("yyyy-MM-dd");
    ui->comboBox->setModel(model2);
    connect(ui->tableView_3, SIGNAL(clicked ( const QModelIndex &)), this,SLOT(show3()));

    model4 = new QSqlQueryModel(this);
    model4->setQuery(QString("select * from shopinfo where flag=0"));
    ui->tableView_3->setModel(model4);
    /*ui->tableView_3->hideColumn(0);
    ui->tableView_3->hideColumn(1);
    ui->tableView_3->hideColumn(3);
    ui->tableView_3->hideColumn(4);
    ui->tableView_3->hideColumn(5);
    ui->tableView_3->hideColumn(6);*/
}

admin::~admin()
{
    delete ui;
}
void admin::show1()
{
    int curRow = ui->tableView_2->currentIndex().row();
    qDebug()<<curRow<<"jianjiannian";
    showinfo(model2->index(curRow,0).data().toInt());
}
void admin::show2()
{
    int curRow = ui->tableView->currentIndex().row();
    qDebug()<<curRow<<"%$^$TGFDGE";
    showinfo2(model3->index(curRow,0).data().toInt());
}
void admin::show3()
{
    int curRow = ui->tableView_3->currentIndex().row();
    qDebug()<<curRow<<model4->index(curRow,0).data().toInt()<<model4->index(curRow,1).data().toInt();

    showinfo3(model4->index(curRow,1).data().toInt(),model4->index(curRow,0).data().toInt());
}
void admin::on_pushButton_clicked()
{
    int curRow = ui->tableView_2->currentIndex().row();
    QByteArray data;
    QString filename = QFileDialog::getOpenFileName(
                    this,
                    "Open Document",
                    QDir::currentPath(),
                    "Document files (*.jpg *.png);;All files(*.*)");//"Document files (*.jpg *.png);;All files(*.*)");
        if (!filename.isEmpty())
        {
            QPixmap *pixmap=new QPixmap(filename);
            ui->label_2->setPixmap(pixmap->scaled(ui->label_2->width(),ui->label_2->height()));
            QFile *file=new QFile(filename); //fileName为二进制数据文件名
            file->open(QIODevice::ReadOnly);
            data = file->readAll();
            QVariant  var_0_0(data);
            var_5=var_0_0;
            file->close();
        }
        QSqlQuery query;
        qDebug()<<model2->index(curRow,0).data().toString();
        query.prepare("UPDATE carmodel SET carphoto=? where cartypeid=?");
        query.addBindValue(var_5);
        query.addBindValue(model2->index(curRow,0).data().toString());
        query.exec();
        QMessageBox::information(this,tr("提示"),tr("修改成功！      \n\n     "));

}



void admin::on_pushButton_2_clicked()
{
    QSqlQuery query;
    query.prepare("UPDATE carmodel SET carmodel=?,fuelid=?,rentmoney=?,dayrentmoney=?,avgkilm=?,overkilmmoney=?,creater=?,amenddate=?,overdatemoney=? where cartypeid=?");
    query.addBindValue(QString(ui->lineEdit->text()));
    query.addBindValue(QString(ui->lineEdit_2->text()));
    query.addBindValue(ui->lineEdit_3->text().toInt());
    query.addBindValue(ui->lineEdit_4->text().toInt());
    query.addBindValue(ui->lineEdit_5->text().toInt());
    query.addBindValue(ui->lineEdit_6->text().toInt());
    query.addBindValue(creator);
    query.addBindValue(QString(QDateTime::currentDateTime().toString("yyyy-MM-dd")));
    query.addBindValue(ui->lineEdit_7->text().toInt());
    query.addBindValue(QString(ui->label->text()));
    ui->label_3->setText(creator);
    ui->label_4->setText(QString(QDateTime::currentDateTime().toString("yyyy-MM-dd")));
    query.exec();
    model2->setQuery(QString("select * from carmodel where flag!=1"));
    //ui->tableView_2->setModel(model2);
    QString hehe=creator+"修改信息了";
    // 基本 URL
    QString baseUrl = "https://sc.ftqq.com/SCU8983Tc368ce0619fe334835f91607b35602d659391d20345f6.send?text=";
    // 设置发送的数据
    QByteArray bytes;
    bytes.append(QString("%1").arg(hehe));  // Qt 作为变量输入
    // 组合 URL
    baseUrl += bytes;
    QNetworkAccessManager* manager=new QNetworkAccessManager(this);
        QNetworkRequest request;
        request.setUrl(baseUrl);
        QNetworkReply* reply=manager->get(request);
    QMessageBox::information(this,tr("提示"),tr("修改成功！      \n\n     "));
}
void admin::showinfo(int row){
     QSqlQuery query;
     qDebug()<<row;

     query.exec(QString("select * from carmodel where cartypeid='%1'").arg(row));
     while(query.next())
     {
         ui->label->setText(query.value(0).toString());   //label存储点击哪一辆车
         ui->lineEdit->setText(query.value(1).toString());
         ui->lineEdit_2->setText(query.value(2).toString());
         ui->lineEdit_3->setText(query.value(3).toString());
         ui->lineEdit_4->setText(query.value(4).toString());
         ui->lineEdit_5->setText(query.value(5).toString());
         ui->lineEdit_6->setText(query.value(6).toString());
         ui->lineEdit_7->setText(query.value(10).toString());
         ui->label_3->setText(query.value(8).toString());
         ui->label_4->setText(query.value(9).toString());
         QPixmap photo;
         photo.loadFromData(query.value(7).toByteArray(), "jpg"); //从数据库中读出图片为二进制数据，图片格式为png，然后显示到QLabel里

         if(photo.isNull())
         {
             QPixmap pixmap;
             pixmap=QPixmap(":/1.png");
             ui->label_2->setPixmap(pixmap);
             pixmap.scaled(ui->label_2->size());//图像适应label大小

         }
         else
         {
             ui->label_2->setPixmap(photo);
         }
     }
}

void admin::showinfo2(int row){
     QSqlQuery query;
     query.exec(QString("select * from carinfo where carid='%1'").arg(row));
     while(query.next())

     {
         ui->label_14->setText(query.value(0).toString());   //label存储点击哪一辆车
         ui->comboBox->setCurrentText(query.value(1).toString());
         ui->lineEdit_9->setText(query.value(3).toString());
         ui->lineEdit_10->setText(query.value(4).toString());
         ui->lineEdit_11->setText(query.value(5).toString());
         ui->lineEdit_12->setText(query.value(6).toString());
         ui->dateEdit->setDate(query.value(7).toDate());
         ui->lineEdit_14->setText(query.value(8).toString());
         ui->lineEdit_15->setText(query.value(9).toString());
         ui->label_15->setText(query.value(10).toString());
         ui->label_16->setText(query.value(11).toString());
         ui->lineEdit_21->setText(query.value(12).toString());
         QPixmap photo2;
         int g=query.value(1).toInt();
         qDebug()<<"flag1--";

         QSqlQuery query2;
         query2.exec(QString("select carphoto from carmodel where cartypeid='%1'").arg(g));
         while(query2.next())
         {
             qDebug()<<"flag2--";
         photo2.loadFromData(query2.value(0).toByteArray(), "jpg");
         if(photo2.isNull())
         {
             QPixmap pixmap2;
             pixmap2=QPixmap(":/1.png");
             ui->label_13->setPixmap(pixmap2);
             pixmap2.scaled(ui->label_13->size());//图像适应label大小
         }
         else
         {
             ui->label_13->setPixmap(photo2);
         }
         }
     }
     QSqlQuery query3;
     qDebug()<<"flag3--";
     query3.exec(QString("select * from insuranceinfo where insuranceid='%1'").arg(row));
     while(query3.next())
     {
         qDebug()<<"flag4--";
         ui->lineEdit_16->setText(query3.value(1).toString());
         qDebug()<<"flag6--";
         ui->lineEdit_17->setText(query3.value(2).toString());
         qDebug()<<"flag7--";
         ui->dateEdit_2->setDate(query.value(3).toDate());
         qDebug()<<"flag8--";
         ui->dateEdit_3->setDate(query.value(4).toDate());
         qDebug()<<"flag9--";
         ui->lineEdit_20->setText(query3.value(5).toString());
         qDebug()<<"flag5--";
     }
}

void admin::showinfo3(int row,int x){
     QSqlQuery query;
     query.exec(QString("select * from clientinfo where clientid='%1'").arg(row));
     qDebug()<<row<<x;
     //ui->label_40->setText(x);
     while(query.next())

     {

         ui->lineEdit_8->setText(query.value(0).toString());
         ui->lineEdit_13->setText(query.value(1).toString());
     }
         QSqlQuery query2;
         query2.exec(QString("select * from shopinfo where shopid='%1'").arg(x));
         while(query2.next())
         {
             qDebug()<<"flag2--";
             ui->label_40->setText(query2.value(0).toString());
             ui->lineEdit_22->setText(query2.value(7).toString());
             ui->lineEdit_18->setText(query2.value(2).toString());
             ui->lineEdit_19->setText(query2.value(3).toString());
             ui->label_37->setText(query2.value(4).toString());
             ui->label_38->setText(query2.value(5).toString());


         }


}


void admin::on_pushButton_3_clicked()
{
    QSqlQuery query;
    query.exec("insert into carmodel(carmodel,flag) values('请编辑',0)");
    model2->setQuery(QString("select * from carmodel where flag!=1"));
    //QModelIndex ii=model2->index(model2->columnCount(),0);
    //ui->tableView_2->scrollTo(ii);
}

void admin::on_pushButton_5_clicked()
{
    int curRow = ui->tableView_2->currentIndex().row();
    int h=model2->index(curRow,0).data().toInt();
    if(h!=0)
    {
    QSqlQuery query;//model2->index(curRow,0).data().toInt()
    qDebug()<<model2->index(curRow,0).data().toString()<<"fdvdfsdfsd"<<h;
    query.prepare("UPDATE carmodel SET flag=? where cartypeid=?");
    query.addBindValue(1);
    query.addBindValue(h);
    query.exec();//"delete from carmodel where carmodelid=")
    QMessageBox::information(this,tr("提示"),tr("修改成功！      \n\n     "));
    model2->setQuery(QString("select * from carmodel where flag!=1"));

   // model2->select();
    showinfo(model2->index(1,0).data().toInt());
    }
    else
    {
        QMessageBox::information(this,tr("提示"),tr("请选择要删除的车型！      \n\n     "));
    }
}

void admin::on_pushButton_4_clicked()
{
    QSqlQuery query;
    query.prepare("UPDATE carinfo SET cartypeid=?,carnumber=?,carcolor=?,carage=?,carbodyid=?,carbuyday=?,carstatus=?,carbuyfrom=?,creater=?,amenddate=?,runkilm=? where carid=?");
   // query.addBindValue(ui->lineEdit_8->text().toInt());
    query.addBindValue(ui->comboBox->currentText());
    query.addBindValue(QString(ui->lineEdit_9->text()));
    query.addBindValue(QString(ui->lineEdit_10->text()));
    query.addBindValue(ui->lineEdit_11->text().toInt());
    query.addBindValue(QString(ui->lineEdit_12->text()));
    query.addBindValue(ui->dateEdit->text());
    query.addBindValue(QString(ui->lineEdit_14->text()));
    query.addBindValue(QString(ui->lineEdit_15->text()));
    query.addBindValue(creator);
    query.addBindValue(QString(QDateTime::currentDateTime().toString("yyyy-MM-dd")));
    query.addBindValue(QString(ui->lineEdit_21->text()));
    query.addBindValue(QString(ui->label_14->text()));

    ui->label_3->setText(creator);
    ui->label_4->setText(QString(QDateTime::currentDateTime().toString("yyyy-MM-dd")));
    query.exec();
    QSqlQuery query2;
    query2.prepare("UPDATE insuranceinfo SET insurancenum=?,insurancecompany=?,insurancebegain=?,insuranceend=?,insurancetype=?,creater=?,amenddate=? where insuranceid=?");
    query2.addBindValue(QString(ui->lineEdit_16->text()));
    query2.addBindValue(QString(ui->lineEdit_17->text()));
    query2.addBindValue(ui->dateEdit_2->text());
    query2.addBindValue(ui->dateEdit_3->text());

    //query2.addBindValue(QString(ui->lineEdit_18->text()));
    //query2.addBindValue(QString(ui->lineEdit_19->text()));
    query2.addBindValue(QString(ui->lineEdit_20->text()));
    query2.addBindValue(creator);
    query2.addBindValue(QString(QDateTime::currentDateTime().toString("yyyy-MM-dd")));
    query2.addBindValue(QString(ui->label_14->text()).toInt());
    query2.exec();
    model3->setQuery(QString("select * from carinfo where flag!=1"));   //flag=0说明没有被删除

    //model3->select();
    showinfo2(QString(ui->label_14->text()).toInt());
    QString hehe=creator+"修改车辆信息啦";
    // 基本 URL
    QString baseUrl = "https://sc.ftqq.com/SCU8983Tc368ce0619fe334835f91607b35602d659391d20345f6.send?text=";
    // 设置发送的数据
    QByteArray bytes;
   // bytes.append("type=content&");
    bytes.append(QString("%1").arg(hehe));  // Qt 作为变量输入
    // 组合 URL
    baseUrl += bytes;
    //QUrl url(baseUrl);
    QNetworkAccessManager* manager=new QNetworkAccessManager(this);
        QNetworkRequest request;
        request.setUrl(baseUrl);
        QNetworkReply* reply=manager->get(request);
    QMessageBox::information(this,tr("提示"),tr("修改成功！      \n\n     "));

}

void admin::on_pushButton_6_clicked()
{
    QSqlQuery query;
    query.exec("insert into carinfo(carnumber,flag) values('请编辑车牌号',0)");
    model3->setQuery(QString("select * from carinfo where flag!=1"));   //flag=0说明没有被删除

    //model3->select();
    int curRow = ui->tableView->model()->rowCount();
    // int curRow = model3->rowCount();
    QSqlQuery query2;
    query2.prepare("insert into insuranceinfo(insuranceid) values(?)");
    query2.addBindValue(model3->index(curRow-1,0).data().toInt());
    query2.exec();
    QSqlQuery query3;
    query3.prepare("UPDATE carinfo SET insuranceid=? where carid=?");
    query3.addBindValue(model3->index(curRow-1,0).data().toInt());
    query3.addBindValue(model3->index(curRow-1,0).data().toInt());
    query3.exec();
    model3->setQuery(QString("select * from carinfo where flag!=1"));   //flag=0说明没有被删除

    //model3->select();
}

void admin::on_pushButton_7_clicked()
{
    int curRow = ui->tableView->currentIndex().row();
    int h=model3->index(curRow,0).data().toInt();
    if(h!=0)
    {
    QSqlQuery query;//model2->index(curRow,0).data().toInt()
    query.prepare("UPDATE carinfo SET flag=? where carid=?");
    query.addBindValue(1);
    query.addBindValue(h);
    query.exec();//"delete from carmodel where carmodelid=")

   // query.exec(QString("delete from carinfo where carid='%1'").arg(h));//"delete from carmodel where carmodelid=")
    QMessageBox::information(this,tr("提示"),tr("修改成功！      \n\n     "));
    //QSqlQuery query2;//model2->index(curRow,0).data().toInt()
    qDebug()<<"删除"<<h;
    //query2.exec(QString("delete from insuranceinfo where insuranceid='%1'").arg(h));//"delete from carmodel where carmodelid=")
    model3->setQuery(QString("select * from carinfo where flag!=1"));   //flag=0说明没有被删除

    //model3->select();
    showinfo2(model3->index(1,0).data().toInt());
    }
    else
    {
        QMessageBox::information(this,tr("提示"),tr("请选择要删除的车型！      \n\n     "));
    }
}



void admin::on_pushButton_8_clicked()
{
   addshop shop1;
   shop1.exec();
   qDebug()<<"结束";
   model4->setQuery(QString("select * from shopinfo where flag=0"));

}

void admin::on_pushButton_9_clicked()
{
    QSqlQuery query;
    query.prepare("UPDATE clientinfo SET password=? where clientid=?");
    query.addBindValue(QString(ui->lineEdit_13->text()));
    query.addBindValue(ui->lineEdit_8->text().toInt());
    query.exec();
    qDebug()<<ui->lineEdit_13->text()<<ui->label_40->text().toInt()<<QString(ui->lineEdit_22->text());
    qDebug()<<QString(ui->lineEdit_18->text())<<QString(ui->lineEdit_19->text())<<ui->lineEdit_8->text().toInt();
    QSqlQuery query2;
    query2.prepare("UPDATE shopinfo SET ownername=?,shopaddress=?,shoptel=? where shopid=?");
    query2.addBindValue(QString(ui->lineEdit_22->text()));
    query2.addBindValue(QString(ui->lineEdit_18->text()));
    query2.addBindValue(QString(ui->lineEdit_19->text()));
    query2.addBindValue(ui->label_40->text().toInt());
     qDebug()<<ui->lineEdit_8->text().toInt()<<"hahahahhaahha";

    query2.exec();
    model4->setQuery(QString("select * from shopinfo where flag=0"));
    QMessageBox::information(this,tr("提示"),tr("修改成功！      \n\n     "));

}
