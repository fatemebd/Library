#ifndef SIGNUPFORM_H
#define SIGNUPFORM_H
#include <mainwindow.h>
#include <QMainWindow>

namespace Ui {
class signupform;
}

class signupform : public QMainWindow
{
    Q_OBJECT

public:
    explicit signupform(QWidget *parent = nullptr);
    ~signupform();

private slots:
    void on_back_clicked();


    void on_signup_clicked();

private:
    Ui::signupform *ui;
};

#endif // SIGNUPFORM_H
