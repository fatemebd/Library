#ifndef EDITFORM_H
#define EDITFORM_H
#include <adminform.h>
#include <QMainWindow>
#include <book.h>
namespace Ui {
class editform;
}

class editform : public QMainWindow
{
    Q_OBJECT

public:
    explicit editform(QWidget *parent = nullptr);
    ~editform();

private slots:
    void on_back_clicked();

    void on_save_clicked();

private:
    Ui::editform *ui;
};

#endif // EDITFORM_H
