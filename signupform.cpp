#include "signupform.h"
#include "ui_signupform.h"
#include <users.h>
#include<QFile>
#include<QString>
#include <QList>
#include<QDebug>
#include <QMessageBox>
signupform::signupform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::signupform)
{
    ui->setupUi(this);
}

signupform::~signupform()
{
    delete ui;
}

void signupform::on_back_clicked()
{
    MainWindow *s =new MainWindow();
    this->close();
    s->show();
}



void signupform::on_signup_clicked()
{
    QList <user> A;

    QFile file("C:/Users/DANESH/Desktop/ap/1/files/usersinfo.txt");

    bool confirm=false;
    bool exist=true;
     if(this->ui->confirm->text()==this->ui->pass->text())
         confirm=true;
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
         if(tmp.username==this->ui->user->text())
             exist=false;
         break;
     }
     if(exist==false){
         QMessageBox :: critical(this,"Exist Eror","This username is not available, Please choose another one and try again!");

     }
     if(confirm==false){
         QMessageBox :: critical(this,"confirm Eror","The password is not correct!");
     }

    else if(confirm==true && exist == true){
        file.open(QFile::Append|QFile::WriteOnly);
        QTextStream q(&file);
        q<<endl<<this->ui->first->text()<<"-"<<this->ui->last->text()<<"-"<<this->ui->user->text()<<"-"<<this->ui->pass->text()<<"-"<<this->ui->keyword->text()<<"-"<<this->ui->role->currentText()<<"\r\n";
        file.close();
        MainWindow * b=new MainWindow();
        this->close();
        b->show();

    }

}
