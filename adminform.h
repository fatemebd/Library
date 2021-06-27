#ifndef ADMINFORM_H
#define ADMINFORM_H
#include <mainwindow.h>
#include <QMainWindow>
#include <addform.h>
#include <deleteform.h>
#include <returnbook.h>
namespace Ui {
class adminform;
}

class adminform : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminform(QWidget *parent = nullptr);
    ~adminform();
private slots:
    void on_back_clicked();

    void on_edit_clicked();

    void on_add_clicked();

    void on_delete_2_clicked();

    void on_showall_clicked();

    void on_number_clicked();

    void on_returnbook_clicked();

private:
    Ui::adminform *ui;
};

#endif // ADMINFORM_H
