#ifndef SIGNUP_H
#define SIGNUP_H
#include<mainwindow.h>
#include <QWidget>

namespace Ui {
class signup;
}

class signup : public QWidget
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:


    void on_back_clicked();

private:
    Ui::signup *ui;
};

#endif // SIGNUP_H
