#include "forgetpass.h"
#include "ui_forgetpass.h"
#include <users.h>
#include<QFile>
#include<QString>
#include <QList>
#include<QDebug>
#include <QMessageBox>

forgetpass::forgetpass(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::forgetpass)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->setupUi(this);
}

forgetpass::~forgetpass()
{
    delete ui;
}

void forgetpass::on_back_clicked()
{
    MainWindow * s=new MainWindow();
    this->close();
    s->show();
}

void forgetpass::on_create_clicked()
{
    signupform *s =new signupform();
    this->close();
    s->show();
}

void forgetpass::on_change_clicked()
{
    QList <user> A;
    bool contain=false;
    bool key=false;
    bool confirm=false;
    int index;
    QString str=this->ui->userr->text();
    QString strkey=this->ui->keyword->text();
    QString strpass=this->ui->newpass->text();
    QString strpassc=this->ui->newpassconf->text();

    QFile file("usersinfo.txt");
     QTextStream a(&file);
      file.open(QFile::Text|QFile::ReadOnly);
     while(!a.atEnd())
     {
         QStringList s=a.readLine().split('-');
         user tmp;
         tmp.firs=s[0];
         tmp.last=s[1];
         tmp.username=s[2];
         tmp.password=s[3];
         tmp.keyword=s[4];
         tmp.role=s[5];

         A.append(tmp);
     }
     file.close();
     for(int i=0;i<A.size();i++){
         user tmp=A[i];
         if(tmp.username==str){
             index=i;
             contain=true;
             if(strpass==strpassc)
                 confirm=true;
             else{
                 QMessageBox::critical(this,"confirm Eror","The password is not correct!");
                 break;
             }
             if(strkey==tmp.keyword)
                 key=true;
             else{
                 QMessageBox::critical(this,"Keyword Eror","The keyword is not correct!");
                 break;
             }
             if((confirm) && (key)){
                A[i].password=strpassc;
                file.open(QFile::Text|QFile::WriteOnly);
                for(int i=0;i<A.size();i++){
                QTextStream q(&file);
                q<<A[i].firs<<"-"<<A[i].last<<"-"<<A[i].username<<"-"<<A[i].password<<"-"<<A[i].keyword<<"-"<<A[i].role<<"\r\n";
               }
                file.close();
                QMessageBox::information(this,"Change password","Password changed succesfully!");
             }
             break;
         }
         if(contain!=true){
                  QMessageBox::critical(this,"Username Error","The username is not available!");
          }
     }
}
