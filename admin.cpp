#include "admin.h"
#include "ui_admin.h"
#include<QFile>
#include<QSqlQuery>
#include<QFileDialog>
QVariant  var_5(1000000);
admin::admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
   //  QVariant  var_5(100);
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
                    "Document files (*.jpg *.png);;All files(*.*)");
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
      //  QSqlQuery query2;//password  username useridnum usersex  usertel
       // query2.prepare("insert into carmodel(carphoto) values(?)");
       // query2.addBindValue(id);

        //query2.exec();
        QSqlQuery query;
        query.prepare("UPDATE carmodel SET carphoto=? where cartypeid='1'");
        //query.addBindValue(password);
        //query.prepare("INSERT INTO carmodel(carphoto) where cartypeid='1'" );

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
            photo.loadFromData(query.value(8).toByteArray(), "jpg"); //从数据库中读出图片为二进制数据，图片格式为png，然后显示到QLabel里
            ui->label_2->setPixmap(photo);

        }
}
