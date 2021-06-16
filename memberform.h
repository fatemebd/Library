#ifndef MEMBERFORM_H
#define MEMBERFORM_H
#include <mainwindow.h>
#include <QMainWindow>
#include <searchform.h>
#include <showall.h>
#include <searchincat.h>
namespace Ui {
class memberform;
}

class memberform : public QMainWindow
{
    Q_OBJECT

public:
    explicit memberform(QWidget *parent = nullptr);
    ~memberform();

private slots:
    void on_search_clicked();

    void on_show_clicked();

    void on_showcat_clicked();

    void on_searchincat_clicked();

private:
    Ui::memberform *ui;
};

#endif // MEMBERFORM_H
