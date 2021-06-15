#include "searchform.h"
#include "ui_searchform.h"

searchform::searchform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::searchform)
{
    ui->setupUi(this);
}

searchform::~searchform()
{
    delete ui;
}
