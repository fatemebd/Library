#include "adminform.h"
#include "ui_adminform.h"

adminform::adminform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminform)
{
    ui->setupUi(this);
}

adminform::~adminform()
{
    delete ui;
}

void adminform::on_back_clicked()
{
    MainWindow *s =new MainWindow();
    this->close();
    s->show();
}
