#include "showall.h"
#include "ui_showall.h"
#include <book.h>
#include <QFile>
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTextStream>
showall::showall(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::showall)
{
    ui->setupUi(this);
}

showall::~showall()
{
    delete ui;
}

void showall::on_search_textChanged(const QString &input)
{

    for (int i = 0 ; i < 20 ; ++i )
            for (int i = 0 ; i < 20 ; ++i )
                ui->table->removeRow(i);
    QList<books> A;
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
     QTableWidgetItem* c1;
      QTableWidgetItem* c2;
       QTableWidgetItem* c3;

        int j=0;
    for(int i=0;i<A.size();i++){
        QString tmp=A[i].category;
           if( tmp.contains(input) && !input.isEmpty()){
               ui->table->insertRow(j);

               c1 = new QTableWidgetItem;
               c2 = new QTableWidgetItem;
               c3 = new QTableWidgetItem;


               c1->setText(A[i].name);
               c2->setText(A[i].author);
               c3->setText(A[i].publishers);


               c1->setTextAlignment(Qt::AlignCenter);
               c2->setTextAlignment(Qt::AlignCenter);
               c3->setTextAlignment(Qt::AlignCenter);


               this->ui->table->setItem(j,0,c1);
               this->ui->table->setItem(j,1,c2);
               this->ui->table->setItem(j,2,c3);

               j++;
           }
    }
}
