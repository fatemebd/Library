#include "deleteform.h"
#include "ui_deleteform.h"
#include <book.h>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QMessageBox>
#include <QList>
deleteform::deleteform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::deleteform)
{
    ui->setupUi(this);
}

deleteform::~deleteform()
{
    delete ui;
}

void deleteform::on_back_clicked()
{
    adminform *s =new adminform;
    this->close();
    s->show();
}

void deleteform::on_deletepush_clicked()
{
     QList<books> A;
     bool exist=false;
    QFile file("C:/Users/DANESH/Desktop/ap/1/files/booksinfo.txt");
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
         if(A[i].name==this->ui->delname->text()){
              A.removeAt(i);
              exist=true;
              break;
         }
     }
     if(exist!=true)
         QMessageBox :: critical(this,"Foundation Error","This book is not available!");
     else if(exist==true)
         QMessageBox :: information(this,"","Book deleted succesfully!");
     file.open(QFile::Text|QFile::WriteOnly);
     for(int i=0;i<A.size();i++){
         QTextStream q(&file);
         q<<A[i].name<<"-"<<A[i].author<<"-"<<A[i].publishers<<"-"<<A[i].category<<"-"<<A[i].rent<<"\r\n";
     }
     file.close();
}
