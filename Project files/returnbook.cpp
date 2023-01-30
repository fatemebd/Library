#include "returnbook.h"
#include "ui_returnbook.h"
#include <book.h>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QMessageBox>
#include <QList>
#include <QDebug>

returnbook::returnbook(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::returnbook)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->setupUi(this);
}

returnbook::~returnbook()
{
    delete ui;
}

void returnbook::on_returnb_clicked()
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
        if(A[i].name==ui->bookn->text()){
            exist=true;

                QFile file1("rentedbooks.txt");
                 QTextStream b(&file1);
                 int s;
                  file1.open(QFile::Text|QFile::ReadOnly);
                  while(!b.atEnd())
                  {
                       s=b.readLine().toInt();
                  }
                  file1.close();
                  s--;
                  file1.open(QFile::Text|QFile::WriteOnly);
                  QTextStream q(&file1);
                  q<<QString::number(s);
                  file1.close();
                A[i].rent="empty";
                //qDebug()<<A[i].rent;
                QMessageBox::information(this,"","Book returned succesfully!");
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
