#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QString>
#include <QList>
#include<QDebug>
#include <QMessageBox>
#include <users.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_signup_clicked()
{
       signupform* s=new signupform();
       this->close();
       s->show();
}

void MainWindow::on_forgetpass_clicked()
{
    forgetpass* s=new forgetpass;
    this->close();
    s->show();
}

void MainWindow::on_login_clicked()
{
    QList <user> A;
    bool contain=false;
    int index;
    QString str=this->ui->usernamee->text();
    QString strpass=this->ui->passwordd->text();
    QFile file("C:/Users/DANESH/Desktop/ap/1/files/usersinfo.txt");
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
             if(tmp.password==strpass){
                 if(tmp.role=="Admin"){
                     adminform * s=new adminform;
                     this->close();
                     s->show();
                 }
                 else{
                     memberform * s= new memberform;
                     this->close();
                     s->show();
                 }
             }
             else{
                 QMessageBox::critical(this,"Password Error","The password is not correct!");
             }
             break;
         }

     }
    if(contain!=true){
             QMessageBox::critical(this,"Username Error","The username is not available!");
     }

}
