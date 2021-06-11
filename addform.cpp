#include "addform.h"
#include "ui_addform.h"

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
