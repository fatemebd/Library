#include "signup.h"
#include "ui_signup.h"

signup::signup(QWidget *parent) :
  QWidget(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
}

signup::~signup()
{
    delete ui;
}



void signup::on_back_clicked()
{
    MainWindow *s=new MainWindow;
    this->close();
    s->show();
}
