#include "memberform.h"
#include "ui_memberform.h"

memberform::memberform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::memberform)
{
    ui->setupUi(this);
}

memberform::~memberform()
{
    delete ui;
}
