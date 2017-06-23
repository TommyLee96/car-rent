#ifndef CONNECTTION
#define CONNECTTION
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QDebug>
#include"connecttion.h"
extern bool connected;
bool connected=false;
static bool createConnection()
{

    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName(QString("DRIVER={SQL SERVER};"
                                           "SERVER=%1;" //服务器名称
                                           "DATABASE=%2;"//数据库名
                                           "UID=%3;"
                                           "PWD=%4;"
                                           ).arg("106.14.165.15")//服务器名称106.14.165.15
                                   .arg("SqlProjectDesign")//数据库名
                                   .arg("han")//登录名
                                   .arg("123123")//密码
                                   );
    QSqlQuery search(db);
    if(!db.open())
    {
        connected=false;
        //QMessageBox::information(this,tr("提示"),tr("数据库连接失败！       \n\n请检查网络，重新连接数据库！       "));
        //return;
    }
    //检查此车辆是否合法
    QString clientid="111";
    search.exec(QString("select * from clientinfo where clientid='%1'").arg(clientid));
    while(search.next())
    {
     qDebug()<<search.value(1).toString();
    }
    search.exec();
    return connected=true;
    return true;
}

#endif // CONNECTTION

