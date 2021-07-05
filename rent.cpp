#include "rent.h"
#include "ui_rent.h"
#include <book.h>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QMessageBox>
#include <QList>
#include <QDebug>
rent::rent(QWidget *parent,QString username) :
    QMainWindow(parent),
    ui(new Ui::rent)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->setupUi(this);
    this->username=username;
}

rent::~rent()
{
    delete ui;
}

void rent::on_rentbook_clicked()
{
    QList<books> A;
    bool exist=false;
   QFile file("booksinfo.txt");
    QTextStream b(&file);
     file.open(QFile::Text|QFile::ReadOnly);
    while(!b.atEnd())
    {
        QStringList s=b.readLine().split('-');
        books tmp;
        tmp.name=s[0];
        tmp.author=s[1];
        tmp.publishers=s[2];
        tmp.category=s[3];
        tmp.rent=s[4];
        A.append(tmp);
    }
    file.close();
    for(int i=0;i<A.size();i++){
        if(A[i].name==ui->bookname->text()){
            exist=true;
            if(A[i].rent!="empty"){
                QMessageBox::critical(this,"","This book is rented by someone else!");
            }
            else{
                QFile file1("rentedbooks.txt");
                 QTextStream b(&file1);
                 int s=0;
                  file1.open(QFile::Text|QFile::ReadOnly);

                  while(!b.atEnd())
                  {
                       s=b.readLine().toInt();
                  }
                  file1.close();
                  s++;
                  file1.open(QFile::Text|QFile::WriteOnly);
                  QTextStream q(&file1);
                  q<<QString::number(s);
                  file1.close();
                A[i].rent=username;
                QMessageBox::information(this,"","Book rented succesfully!");
            }
        }
    }
    if(exist!=true)
        QMessageBox::critical(this,"","This book is not available!");
    file.open(QFile::Text|QFile::WriteOnly);
    for(int i=0;i<A.size();i++){
        QTextStream q(&file);
        q<<A[i].name<<"-"<<A[i].author<<"-"<<A[i].publishers<<"-"<<A[i].category<<"-"<<A[i].rent<<"\r\n";
    }
    file.close();
}
