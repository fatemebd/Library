#include "memberform.h"
#include "ui_memberform.h"
#include <book.h>
#include <QFile>
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTextStream>

memberform::memberform(QWidget *parent, QString  username) :
    QMainWindow(parent),
    ui(new Ui::memberform)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->setupUi(this);
    ui->table->hide();
    this->username=username;
}

memberform::~memberform()
{
    delete ui;
}

void memberform::on_search_clicked()
{
    searchform * s=new searchform;
    s->show();
}

void memberform::on_show_clicked()
{

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

        int j=0;
    for(int i=0;i<A.size();i++){
            ui->table->insertRow(j);

            c1 = new QTableWidgetItem;
            c2 = new QTableWidgetItem;
            c3 = new QTableWidgetItem;
            c4 = new QTableWidgetItem;


            c1->setText(A[i].name);
            c2->setText(A[i].author);
            c3->setText(A[i].publishers);
            c4->setText(A[i].category);


            c1->setTextAlignment(Qt::AlignCenter);
            c2->setTextAlignment(Qt::AlignCenter);
            c3->setTextAlignment(Qt::AlignCenter);
            c4->setTextAlignment(Qt::AlignCenter);


            this->ui->table->setItem(j,0,c1);
            this->ui->table->setItem(j,1,c2);
            this->ui->table->setItem(j,2,c3);
            this->ui->table->setItem(j,3,c4);

            j++;
    }
}

void memberform::on_showcat_clicked()
{
    showall *s =new showall;
    s->show();
}

void memberform::on_searchincat_clicked()
{
    searchincat * s=new searchincat;
    s->show();
}

void memberform::on_rent_clicked()
{
    rent * s=new rent(this, this->username);
    s->show();
}

void memberform::on_pushButton_3_clicked()
{
    MainWindow * s=new MainWindow;
    this->close();
    s->show();
}
