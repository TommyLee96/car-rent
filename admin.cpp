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
QVariant  var_5(100);
admin::admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
    connect(ui->tableView_2, SIGNAL(clicked ( const QModelIndex &)), this,SLOT(show1()));
    model2 = new QSqlTableModel(this);
    model2->setTable("carmodel");
    model2->select();
    QApplication::processEvents();
    model2->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView_2->setModel(model2);
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
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  //设置表格列宽度自适应
    ui->tableView_2->verticalHeader()->setVisible(false);
    ui->tableView_2->setSelectionBehavior ( QAbstractItemView::SelectRows);
    ui->tableView_2->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(46,46,46),stop:1 rgb(66,66,66));color: rgb(210,210,210);;padding-left: 4px;border: 1px solid #383838;}"); //设置表头背景色
    ui->tableView_2->setAlternatingRowColors(true); //使用交替行颜色
    qDebug()<<"currentTime2--"<<QTime::currentTime().toString(Qt::ISODate);
    connect(ui->tableView, SIGNAL(clicked ( const QModelIndex &)), this,SLOT(show2()));
    model3 = new QSqlTableModel(this);
    model3->setTable("carinfo");
    model3->select();
    model3->setEditStrategy(QSqlTableModel::OnManualSubmit);
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
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  //设置表格列宽度自适应
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(46,46,46),stop:1 rgb(66,66,66));color: rgb(210,210,210);;padding-left: 4px;border: 1px solid #383838;}"); //设置表头背景色
    ui->tableView->setAlternatingRowColors(true); //使用交替行颜色
    showinfo(model2->index(15,0).data().toInt());
    ui->lineEdit->setStyleSheet("background-color:transparent");
    ui->lineEdit_2->setStyleSheet("background-color:transparent");
    ui->lineEdit_3->setStyleSheet("background-color:transparent");
    ui->lineEdit_4->setStyleSheet("background-color:transparent");
    ui->lineEdit_5->setStyleSheet("background-color:transparent");
    ui->lineEdit_6->setStyleSheet("background-color:transparent");


}

admin::~admin()
{
    delete ui;
    //delete completer;
}
void admin::show1()
{
    int curRow = ui->tableView_2->currentIndex().row();
    //QSqlQuery query;
    showinfo(model2->index(curRow,0).data().toInt());
}
void admin::show2()
{
    int curRow = ui->tableView->currentIndex().row();
    QSqlQuery query;
    showinfo2(model3->index(curRow,0).data().toInt());
}
void admin::on_pushButton_clicked()
{
    int curRow = ui->tableView_2->currentIndex().row();
    qDebug()<<model2->index(curRow,0).data().toString();

    //  model3->index(rowidx,1).data().toString();
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
    model2->select();
    QString hehe=creator+"修改信息了";
    // 基本 URL
    QString baseUrl = "https://sc.ftqq.com/SCU8983Tc368ce0619fe334835f91607b35602d659391d20345f6.send?text=";
    // 设置发送的数据
    QByteArray bytes;
    // bytes.append("type=content&");
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
         ui->lineEdit_8->setText(query.value(1).toString());
         ui->lineEdit_9->setText(query.value(3).toString());
         ui->lineEdit_10->setText(query.value(4).toString());
         ui->lineEdit_11->setText(query.value(5).toString());
         ui->lineEdit_12->setText(query.value(6).toString());
         ui->lineEdit_13->setText(query.value(7).toString());
         ui->lineEdit_14->setText(query.value(8).toString());
         ui->lineEdit_15->setText(query.value(9).toString());
         ui->label_15->setText(query.value(10).toString());
         ui->label_15->setText(query.value(11).toString());
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
     query3.exec(QString("select * from insuranceinfo where insuranceid='%1'").arg(row));
     while(query3.next())
     {
         ui->lineEdit_16->setText(query3.value(1).toString());
         ui->lineEdit_17->setText(query3.value(2).toString());
         ui->lineEdit_18->setText(query3.value(3).toString());
         ui->lineEdit_19->setText(query3.value(4).toString());
         ui->lineEdit_20->setText(query3.value(5).toString());
     }
}

void admin::on_pushButton_3_clicked()
{
    QSqlQuery query;
    query.exec("insert into carmodel(carmodel) values('请编辑')");
    model2->select();
    QModelIndex ii=model2->index(model2->columnCount(),0);
    ui->tableView_2->scrollTo(ii);
    //ui->tableView_2->scrollTo(model2->index(2,0));
}

void admin::on_pushButton_5_clicked()
{
    int curRow = ui->tableView_2->currentIndex().row();
    int h=model2->index(curRow,0).data().toInt();
    if(h!=0)
    {
    QSqlQuery query;//model2->index(curRow,0).data().toInt()
    qDebug()<<model2->index(curRow,0).data().toString()<<"fdvdfsdfsd"<<h;
    query.exec(QString("delete from carmodel where cartypeid='%1'").arg(h)) ;//"delete from carmodel where carmodelid=")
    QMessageBox::information(this,tr("提示"),tr("修改成功！      \n\n     "));
    model2->select();
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
    query.prepare("UPDATE carinfo SET cartypeid=?,carnumber=?,carcolor=?,carage=?,carbodyid=?,carbuyday=?,carstatus=?,carbuyfrom=?,creater=?,amenddate=? where carid=?");
    query.addBindValue(ui->lineEdit_8->text().toInt());
    query.addBindValue(QString(ui->lineEdit_9->text()));
    query.addBindValue(QString(ui->lineEdit_10->text()));
    query.addBindValue(ui->lineEdit_11->text().toInt());
    query.addBindValue(QString(ui->lineEdit_12->text()));
    query.addBindValue(QString(ui->lineEdit_13->text()));
    query.addBindValue(QString(ui->lineEdit_14->text()));
    query.addBindValue(QString(ui->lineEdit_15->text()));
    query.addBindValue(creator);
    query.addBindValue(QString(QDateTime::currentDateTime().toString("yyyy-MM-dd")));
    query.addBindValue(QString(ui->label_14->text()));
    ui->label_3->setText(creator);
    ui->label_4->setText(QString(QDateTime::currentDateTime().toString("yyyy-MM-dd")));
    query.exec();
    QSqlQuery query2;
    query2.prepare("UPDATE insuranceinfo SET insurancenum=?,insurancecompany=?,insurancebegain=?,insuranceend=?,insurancetype=?,creater=?,amenddate=? where insuranceid=?");
    query2.addBindValue(QString(ui->lineEdit_16->text()));
    query2.addBindValue(QString(ui->lineEdit_17->text()));
    query2.addBindValue(QString(ui->lineEdit_18->text()));
    query2.addBindValue(QString(ui->lineEdit_19->text()));
    query2.addBindValue(QString(ui->lineEdit_20->text()));
    query2.addBindValue(creator);
    query2.addBindValue(QString(QDateTime::currentDateTime().toString("yyyy-MM-dd")));
    query2.addBindValue(QString(ui->label_14->text()).toInt());
    query2.exec();
    model3->select();
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
    query.exec("insert into carinfo(carnumber) values('请编辑车牌号')");
    model3->select();
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
    model3->select();
}
    /* QStringList strings;


        QSqlQuery query5("SELECT carmodel  FROM cartypeinfo");
        while (query5.next()) {
            QString goodsno = query5.value(0).toString();
            strings.append(goodsno);
        }

             ui->comboBox->clear();
             ui->comboBox->setModel(model2);*/


void admin::on_pushButton_7_clicked()
{
    int curRow = ui->tableView->currentIndex().row();
    int h=model3->index(curRow,0).data().toInt();
    if(h!=0)
    {
    QSqlQuery query2;//model2->index(curRow,0).data().toInt()
    query2.exec(QString("delete from insuranceinfo where insuranceid='%1'").arg(h)) ;//"delete from carmodel where carmodelid=")
    QSqlQuery query;//model2->index(curRow,0).data().toInt()
    query.exec(QString("delete from carinfo where carid='%1'").arg(h)) ;//"delete from carmodel where carmodelid=")
    QMessageBox::information(this,tr("提示"),tr("修改成功！      \n\n     "));
    model3->select();
    showinfo2(model3->index(1,0).data().toInt());
    }
    else
    {
        QMessageBox::information(this,tr("提示"),tr("请选择要删除的车型！      \n\n     "));
    }
}
