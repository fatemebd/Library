#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_signup_clicked()
{
       signupform* s=new signupform();
       this->close();
       s->show();
}

void MainWindow::on_forgetpass_clicked()
{
    forgetpass* s=new forgetpass;
    this->close();
    s->show();
}
