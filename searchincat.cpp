#include "searchincat.h"
#include "ui_searchincat.h"
#include <book.h>
#include <QFile>
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTextStream>
searchincat::searchincat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::searchincat)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->setupUi(this);
}

searchincat::~searchincat()
{
    delete ui;
}

void searchincat::on_search_textChanged(const QString &input)
{
    for (int i = 0 ; i < 20 ; ++i )
            for (int i = 0 ; i < 20 ; ++i )
                ui->table->removeRow(i);
    QString cat=ui->cat->text();
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
        QString tmp1=A[i].name;
        QString tmp2=A[i].author;
        QString tmp3=A[i].publishers;
           if((tmp1.contains(input) || tmp2.contains(input) || tmp3.contains(input)) && (A[i].category==cat) && (!input.isEmpty())){
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
}
