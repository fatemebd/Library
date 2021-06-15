#include "editform.h"
#include "ui_editform.h"
#include <book.h>
#include <QFile>
#include <QString>
#include <QList>
#include <QTextStream>
#include <QMessageBox>
editform::editform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::editform)
{
    ui->setupUi(this);
    this->ui->pname_2->setDisabled(true);
    this->ui->nname_2->setDisabled(true);
    this->ui->pauthor_2->setDisabled(true);
    this->ui->nauthor_2->setDisabled(true);
    this->ui->ppress_2->setDisabled(true);
    this->ui->npress_2->setDisabled(true);
    this->ui->pcategory->setDisabled(true);
    this->ui->ncategory->setDisabled(true);
}

editform::~editform()
{
    delete ui;
}

void editform::on_back_clicked()
{
    adminform * s=new adminform;
    this->close();
    s->show();
}

void editform::on_save_clicked()
{
    if(this->ui->book->isChecked()==true || this->ui->author->isChecked()==true || this->ui->press->isChecked()==true || this->ui->category->isChecked()==true){
        QList<books> A;
        bool name=false;
        bool author=false;
        bool press=false;
        bool category=false;
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
             A.append(tmp);
         }
         file.close();
         if(this->ui->category->isChecked()==true){
          for(int i=0;i<A.size();i++){
              if(A[i].name==this->ui->pcategory->text()){
                  category=true;
                  A[i].name=this->ui->ncategory->text();
                  break;
              }
           }
          if(category!=true)
              QMessageBox :: critical(this,"Foundation Faild","This book is not available!");
         }
         if(this->ui->book->isChecked()==true){
          for(int i=0;i<A.size();i++){
              if(A[i].name==this->ui->pname_2->text()){
                  name=true;
                  A[i].name=this->ui->nname_2->text();
                  break;
              }
           }
          if(name!=true)
              QMessageBox :: critical(this,"Foundation Faild","This book is not available!");
         }
         if(this->ui->author->isChecked()==true){
             for(int i=0;i<A.size();i++){
                 if(A[i].name==this->ui->pauthor_2->text()){
                     author=true;
                     A[i].author=this->ui->nauthor_2->text();
                     break;
                 }
              }
             if(author!=true)
                 QMessageBox :: critical(this,"Foundation Faild","This book is not available!");

         }
         if(this->ui->press->isChecked()==true){
             for(int i=0;i<A.size();i++){
                 if(A[i].name==this->ui->ppress_2->text()){
                     press=true;
                     A[i].author=this->ui->npress_2->text();
                     break;
                 }
              }
             if(press!=true)
                 QMessageBox :: critical(this,"Foundation Faild","This book is not available!");
             else if(press==true)
                 QMessageBox :: information(this,"","Your changes saved succesfully!");
         }
         file.open(QFile::Text|QFile::WriteOnly);
         for(int i=0;i<A.size();i++){
             QTextStream q(&file);
             q<<A[i].name<<"-"<<A[i].author<<"-"<<A[i].publishers<<"\r\n";
         }
         file.close();
    }
else
        QMessageBox :: critical(this,"Error","Nothing to save!");
}
