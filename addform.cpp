#include "addform.h"
#include "ui_addform.h"
#include <book.h>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QMessageBox>
#include <QList>

addform::addform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addform)
{
    ui->setupUi(this);
}

addform::~addform()
{
    delete ui;
}

void addform::on_add_clicked()
{
    QList <books> A;
    QFile file("C:/Users/DANESH/Desktop/ap/1/files/booksinfo.txt");
    file.open(QFile::Append|QFile::WriteOnly);
    QTextStream q(&file);
    q<<this->ui->addname->text()<<"-"<<this->ui->addauthor->text()<<"-"<<this->ui->addpublisher->text()<<"-"<<this->ui->addcat->text()<<"-"<<"empty"<<"\r\n";
    file.close();
    QMessageBox :: information(this,"","Book added succesfully!");
}

void addform::on_back_clicked()
{
    adminform *s =new adminform;
    this->close();
    s->show();
}
