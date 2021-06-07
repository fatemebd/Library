#include "signupform.h"
#include "ui_signupform.h"

signupform::signupform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::signupform)
{
    ui->setupUi(this);
}

signupform::~signupform()
{
    delete ui;
}

void signupform::on_back_clicked()
{
    MainWindow *s =new MainWindow();
    this->close();
    s->show();
}
