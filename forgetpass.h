#ifndef FORGETPASS_H
#define FORGETPASS_H

#include <QWidget>
#include <mainwindow.h>
#include <signup.h>
namespace Ui {
class forgetpass;
}

class forgetpass : public QWidget
{
    Q_OBJECT

public:
    explicit forgetpass(QWidget *parent = nullptr);
    ~forgetpass();

private slots:


    void on_create_clicked();

private:
    Ui::forgetpass *ui;
};

#endif // FORGETPASS_H
