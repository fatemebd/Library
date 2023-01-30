#include "adminform.h"
#include "ui_adminform.h"
#include <editform.h>
#include <book.h>
#include <QFile>
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTextStream>
#include <QtDebug>

adminform::adminform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminform)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->setupUi(this);
     ui->table->hide();
     ui->label->hide();
     ui->rentbook->hide();
}

adminform::~adminform()
{
    delete ui;
}

void adminform::on_back_clicked()
{
    MainWindow *s =new MainWindow();
    this->close();
    s->show();
}

void adminform::on_edit_clicked()
{
    editform *s=new editform;
    this->close();
    s->show();
}

void adminform::on_add_clicked()
{
    addform *s =new addform;
    this->close();
    s->show();
}

void adminform::on_delete_2_clicked()
{
    deleteform *s=new deleteform;
    this->close();
    s->show();
}


void adminform::on_showall_clicked()
{
    for (int i = 0 ; i < 20 ; ++i )
            for (int i = 0 ; i < 20 ; ++i )
                ui->table->removeRow(i);
    QList<books> A;
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
     QTableWidgetItem* c1;
      QTableWidgetItem* c2;
       QTableWidgetItem* c3;
        QTableWidgetItem* c4;
        QTableWidgetItem* c5;
        int j=0;
    for(int i=0;i<A.size();i++){
            ui->table->insertRow(j);

            c1 = new QTableWidgetItem;
            c2 = new QTableWidgetItem;
            c3 = new QTableWidgetItem;
            c4 = new QTableWidgetItem;
            c5 = new QTableWidgetItem;


            c1->setText(A[i].name);
            c2->setText(A[i].author);
            c3->setText(A[i].publishers);
            c4->setText(A[i].category);
            c5->setText(A[i].rent);

            c1->setTextAlignment(Qt::AlignCenter);
            c2->setTextAlignment(Qt::AlignCenter);
            c3->setTextAlignment(Qt::AlignCenter);
            c4->setTextAlignment(Qt::AlignCenter);
            c5->setTextAlignment(Qt::AlignCenter);


            this->ui->table->setItem(j,0,c1);
            this->ui->table->setItem(j,1,c2);
            this->ui->table->setItem(j,2,c3);
            this->ui->table->setItem(j,3,c4);
            this->ui->table->setItem(j,4,c5);

            j++;
    }
}

void adminform::on_number_clicked()
{
    QFile file("rentedbooks.txt");
     QTextStream b(&file);
     int s;
      file.open(QFile::Text|QFile::ReadOnly);
      while(!b.atEnd())
      {
           s=b.readLine().toInt();
      }
      file.close();
    ui->rentbook->setText(QString::number(s));
}

void adminform::on_returnbook_clicked()
{
    returnbook * s=new returnbook;
    s->show();
}
