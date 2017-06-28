#include <QApplication>
#include <QDebug>
#include<QTime>
#include"connecttion.h"
#include"login.h"
#include"admin.h"
#include"finance.h"
#include"manager.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if (!createConnection())
    {
        return 1;
    }
    login h;



    if(h.exec()==QDialog::Accepted)
    {
        if(h.flag==0)   //财务登陆
            {
            finance finance1;
            finance1.show();
            return a.exec();
            }
        else if(h.flag==1)    //管理登录
        {
           admin admin1;
           admin1.show();
           return a.exec();
        }
         else if(h.flag==2)
        {
           manager manager1;
           manager1.show();
           return a.exec();
        }//分店登陆
    }
    return a.exec();
}
