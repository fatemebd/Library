#include "adminform.h"
#include "ui_adminform.h"
#include <editform.h>
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

void adminform::on_edit_clicked()
{
    editform *s=new editform;
    this->close();
    s->show();
}

void adminform::on_add_clicked()
{
    addform *s =new addform;
    this->close();
    s->show();
}

void adminform::on_delete_2_clicked()
{
    deleteform *s=new deleteform;
    this->close();
    s->show();
}
