#ifndef MEMBERFORM_H
#define MEMBERFORM_H
#include <mainwindow.h>
#include <QMainWindow>
#include <searchform.h>
#include <showall.h>
#include <searchincat.h>
#include <rent.h>

namespace Ui {
class memberform;
}

class memberform : public QMainWindow
{
    Q_OBJECT
QString * username;
public:
explicit memberform(QWidget *parent = nullptr,QString* username=nullptr);
    ~memberform();

private slots:
    void on_search_clicked();

    void on_show_clicked();

    void on_showcat_clicked();

    void on_searchincat_clicked();

    void on_rent_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::memberform *ui;
};

#endif // MEMBERFORM_H
