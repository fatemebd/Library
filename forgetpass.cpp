#include "forgetpass.h"
#include "ui_forgetpass.h"

forgetpass::forgetpass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::forgetpass)
{
    ui->setupUi(this);
}

forgetpass::~forgetpass()
{
    delete ui;
}

void forgetpass::on_create_clicked()
{
    signup *s=new signup();
    this->close();
    s->show();
}
