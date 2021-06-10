#ifndef ADMINFORM_H
#define ADMINFORM_H
#include <mainwindow.h>
#include <QMainWindow>

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

private:
    Ui::adminform *ui;
};

#endif // ADMINFORM_H
