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
    QFile file("C:/Users/DANESH/Desktop/ap/1/files/usersinfo.txt");
     QTextStream a(&file);
      file.open(QFile::Append|QFile::ReadOnly);
     while(!a.atEnd())
     {
         QStringList s=a.readLine().split('-');
         user tmp;
         tmp.firs=s[0];
         tmp.last=s[1];
         tmp.username=s[2];
         tmp.password=s[3];
         tmp.keyword=s[4];
         A.append(tmp);
     }
     file.close();
     for(int i=0;i<A.size();i++){
         user tmp=A[i];
         if(tmp.username==this->ui->username->text()){
             index=i;
             if(tmp.password==this->ui->password->text())
                 contain=true;
             else{
                 QMessageBox::critical(this,"Password Error","The password is not correct!");
             }
             break;
         }
         else{
             QMessageBox::critical(this,"Username Error","The username is not available!");
         }
     }
}
