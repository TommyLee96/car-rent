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
    // connect(ui->pushButton_5, SIGNAL(clicked ( const QModelIndex &)), this,SLOT(show1()));
     //connect(dataTabView_, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(slotRowDoubleClicked(const QModelIndex &)));
    qDebug()<<"currentTime0--"<<QTime::currentTime().toString(Qt::ISODate);

/*  model = new QSqlTableModel(this);
//  model->setQuery("select * from shopinfo");
    model->setTable("carmodel");
    model->select();
    // 设置编辑策略
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setModel(model);
//  ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  //设置表格列宽度自适应
//  ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
//  ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(46,46,46),stop:1 rgb(66,66,66));color: rgb(210,210,210);;padding-left: 4px;border: 1px solid #383838;}"); //设置表头背景色
    qDebug()<<"currentTime1--"<<QTime::currentTime().toString(Qt::ISODate)
            <<QDateTime::currentDateTime().toString(Qt::ISODate)
            <<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz");
*/
    model2 = new QSqlTableModel(this);
//  model3->setFilter(QString("carid = '1'"));
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
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  //设置表格列宽度自适应
    //ui->tableView_2->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tableView_2->verticalHeader()->setVisible(false);
    ui->tableView_2->setSelectionBehavior ( QAbstractItemView::SelectRows);
    //ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_2->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(46,46,46),stop:1 rgb(66,66,66));color: rgb(210,210,210);;padding-left: 4px;border: 1px solid #383838;}"); //设置表头背景色
    ui->tableView_2->setAlternatingRowColors(true); //使用交替行颜色
    qDebug()<<"currentTime2--"<<QTime::currentTime().toString(Qt::ISODate);

   /* model3 = new QSqlTableModel(this);
    model3->setTable("carinfo");
    //model3->setFilter(QString("carid = '1'"));
    model3->select();
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
    model4->select();
    model4->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView_4->setModel(model4);
    ui->tableView_4->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  //设置表格列宽度自适应
    ui->tableView_4->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tableView_4->resizeColumnsToContents();
    ui->tableView_4->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(46,46,46),stop:1 rgb(66,66,66));color: rgb(210,210,210);;padding-left: 4px;border: 1px solid #383838;}"); //设置表头背景色
    ui->tableView_4->setAlternatingRowColors(true); //使用交替行颜色
    qDebug()<<"currentTime4--"<<QTime::currentTime().toString(Qt::ISODate)
            <<QDateTime::currentDateTime().toString(Qt::ISODate)
            <<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz");
    //ui->tableView_4->setUpdatesEnabled(false);
    //ui->tableView_3->setUpdatesEnabled(false);
   // ui->tableView_2->setUpdatesEnabled(false);
    //ui->tableView->setUpdatesEnabled(false);
*/

   // QSqlQuery query6;
    qDebug()<<model2->index(0,0).data().toString();
  showinfo(model2->index(15,0).data().toInt());
  ui->lineEdit->setStyleSheet("background-color:transparent");
   ui->lineEdit_2->setStyleSheet("background-color:transparent");
    ui->lineEdit_3->setStyleSheet("background-color:transparent");
     ui->lineEdit_4->setStyleSheet("background-color:transparent");
      ui->lineEdit_5->setStyleSheet("background-color:transparent");
       ui->lineEdit_6->setStyleSheet("background-color:transparent");
    //query6.exec(QString("select * from carmodel where cartypeid='%1'").arg(model2->index(0,0).data().toString()));

}

admin::~admin()
{
    delete ui;
}
void admin::show1()
{
    int curRow = ui->tableView_2->currentIndex().row();
    QSqlQuery query;
     qDebug()<<model2->index(curRow,0).data().toString();
     showinfo(model2->index(curRow,0).data().toInt());


}
void admin::on_pushButton_clicked()
{
    int curRow = ui->tableView_2->currentIndex().row();
    qDebug()<<curRow<<model2->index(curRow,0).data().toString();

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
   /* QString uuu=ui->lineEdit->text();
    QString uuu2=ui->lineEdit_2->text();
    int uuu3=ui->lineEdit_3->text().toInt();
    int uuu4=ui->lineEdit_4->text().toInt();
    int uuu5=ui->lineEdit_5->text().toInt();
    int uuu6=ui->lineEdit_6->text().toInt();
    QString uuu7=creator;
    QString uuu8=ui->label->text();
    QString uuu9=QDateTime::currentDateTime().toString("yyyy-MM-dd");
   */
    //query.prepare("UPDATE carmodel SET carmodel=? and fuelid=? where cartypeid=?");
    query.prepare("UPDATE carmodel SET carmodel=?,fuelid=?,rentmoney=?,dayrentmoney=?,avgkilm=?,overkilmmoney=?,creater=?,amenddate=? where cartypeid=?");

    //query.prepare("UPDATE carmodel SET carmodel=? and fuelid=? and rentmoney=? and dayrentmoney=? and avgkilm=? and overkilmmoney=? and creater=?  where cartypeid=?");
    query.addBindValue(QString(ui->lineEdit->text()));
    query.addBindValue(QString(ui->lineEdit_2->text()));
    query.addBindValue(ui->lineEdit_3->text().toInt());
    query.addBindValue(ui->lineEdit_4->text().toInt());
    query.addBindValue(ui->lineEdit_5->text().toInt());
    query.addBindValue(ui->lineEdit_6->text().toInt());
    query.addBindValue(creator);
    query.addBindValue(QString(QDateTime::currentDateTime().toString("yyyy-MM-dd")));
    query.addBindValue(QString(ui->label->text()));
    // model2->setTable("carmodel");
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
    //QUrl url(baseUrl);
    qDebug() <<baseUrl;
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
        // ui->label->hide();
         ui->lineEdit->setText(query.value(1).toString());
         ui->lineEdit_2->setText(query.value(2).toString());
         ui->lineEdit_3->setText(query.value(3).toString());
         ui->lineEdit_4->setText(query.value(4).toString());
         ui->lineEdit_5->setText(query.value(5).toString());
         ui->lineEdit_6->setText(query.value(6).toString());
         ui->label_3->setText(query.value(8).toString());
         ui->label_4->setText(query.value(9).toString());
         QPixmap photo;
         photo.loadFromData(query.value(7).toByteArray(), "jpg"); //从数据库中读出图片为二进制数据，图片格式为png，然后显示到QLabel里

         if(photo.isNull())
         {
             QPixmap pixmap;
             pixmap=QPixmap(":/1.png");


             //m_pLabel->setPixmap(pixmap);
             //QPixmap *pixmap=new QPixmap(:/1.png);
             ui->label_2->setPixmap(pixmap);
              qDebug() <<"6665";
             pixmap.scaled(ui->label_2->size());//图像适应label大小

         }
         else
         {

             ui->label_2->setPixmap(photo);
             qDebug() <<"555";
         }
     }
}
void admin::on_pushButton_3_clicked()
{
    QSqlQuery query;
    query.exec("insert into carmodel(carmodel) values('请编辑')");
    model2->select();
    //int rowNum = model2->rowCount();
    qDebug()<<"第几行啊";
    /* QString info="请编辑";
        // 添加一行
    model2->insertRow(rowNum);
    //model2->setData(model2->index(rowNum, 1), info);
        //ui->tableView_2->setFocujajj s();

   ui->tableView_2->selectRow(model2->rowCount());
    model2->select();
    showinfo(model2->rowCount());*/
    /*int rowNum = model2->rowCount();
    QString info="请编辑";
    // 添加一行
    model2->insertRow(rowNum);
    model2->setData(model2->index(rowNum, 1), info);
    model2->select();
    qDebug()<<rowNum<<"fengexian"<<ui->tableView_2->model()->rowCount();
    showinfo(ui->tableView_2->model()->rowCount()+3);
    //model2->select();
    */
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
