#include<QFile>
#include<QTime>
#include<QSqlQuery>
#include<QFileDialog>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QTableView>
#include <QDebug>
//#include <QMessageBox>
//#include <QSqlError>
#include "admin.h"
#include "ui_admin.h"
QVariant  var_5(100);
admin::admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
    qDebug()<<"currentTime0--"<<QTime::currentTime().toString(Qt::ISODate)
            <<QDateTime::currentDateTime().toString(Qt::ISODate)
            <<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz");
    model = new QSqlTableModel(this);
    model->setTable("shopinfo");
    //model->select();
    // 设置编辑策略
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  //设置表格列宽度自适应
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(46,46,46),stop:1 rgb(66,66,66));color: rgb(210,210,210);;padding-left: 4px;border: 1px solid #383838;}"); //设置表头背景色
    qDebug()<<"currentTime1--"<<QTime::currentTime().toString(Qt::ISODate)
            <<QDateTime::currentDateTime().toString(Qt::ISODate)
            <<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz");

    model2 = new QSqlTableModel(this);
    model2->setTable("carmodel");
    //model2->select();
    model2->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView_2->setModel(model2);
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  //设置表格列宽度自适应
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tableView_2->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(46,46,46),stop:1 rgb(66,66,66));color: rgb(210,210,210);;padding-left: 4px;border: 1px solid #383838;}"); //设置表头背景色
    ui->tableView_2->setAlternatingRowColors(true); //使用交替行颜色
    qDebug()<<"currentTime2--"<<QTime::currentTime().toString(Qt::ISODate)
            <<QDateTime::currentDateTime().toString(Qt::ISODate)
            <<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz");

    model3 = new QSqlTableModel(this);
    model3->setTable("carinfo");
    //model3->select();
    model3->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView_3->setModel(model3);
    ui->tableView_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  //设置表格列宽度自适应
    ui->tableView_3->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tableView_3->resizeColumnsToContents();
    ui->tableView_3->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(46,46,46),stop:1 rgb(66,66,66));color: rgb(210,210,210);;padding-left: 4px;border: 1px solid #383838;}"); //设置表头背景色
    ui->tableView_3->setAlternatingRowColors(true); //使用交替行颜色
    qDebug()<<"currentTime3--"<<QTime::currentTime().toString(Qt::ISODate)
            <<QDateTime::currentDateTime().toString(Qt::ISODate)
            <<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz");

    model4 = new QSqlTableModel(this);
    model4->setTable("rentinfo");
   // model4->select();
    model4->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView_4->setModel(model4);
    ui->tableView_4->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  //设置表格列宽度自适应
    ui->tableView_4->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tableView_4->resizeColumnsToContents();
    ui->tableView_4->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(46,46,46),stop:1 rgb(66,66,66));color: rgb(210,210,210);;padding-left: 4px;border: 1px solid #383838;}"); //设置表头背景色
    ui->tableView_4->setAlternatingRowColors(true); //使用交替行颜色*/
    qDebug()<<"currentTime4--"<<QTime::currentTime().toString(Qt::ISODate)
            <<QDateTime::currentDateTime().toString(Qt::ISODate)
            <<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz");
}

admin::~admin()
{
    delete ui;
}

void admin::on_pushButton_clicked()
{
    QByteArray data;
        QString filename = QFileDialog::getOpenFileName(
                    this,
                    "Open Document",
                    QDir::currentPath(),
                    "Document files (*.jpg *.png);;All files(*.*)");//"Document files (*.jpg *.png);;All files(*.*)");
        if (!filename.isEmpty())
        {
            QPixmap *pixmap=new QPixmap(filename);
            ui->label->setPixmap(pixmap->scaled(ui->label->width(),ui->label->height()));
            QFile *file=new QFile(filename); //fileName为二进制数据文件名
            file->open(QIODevice::ReadOnly);
            data = file->readAll();
            QVariant  var_0_0(data);
            var_5=var_0_0;
            file->close();
        }
        QSqlQuery query;
        query.prepare("UPDATE carmodel SET carphoto=? where cartypeid='1'");
        query.addBindValue(var_5);
        query.exec();
}

void admin::on_pushButton_2_clicked()
{
    QSqlQuery query;
       query.exec("select * from carmodel where cartypeid='1' ");


           // qDebug()<<"ok";
        while(query.next())
        {
            QPixmap photo;
            photo.loadFromData(query.value(7).toByteArray(), "jpg"); //从数据库中读出图片为二进制数据，图片格式为png，然后显示到QLabel里
            ui->label_2->setPixmap(photo);

        }
}
