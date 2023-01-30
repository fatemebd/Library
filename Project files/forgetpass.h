#ifndef FORGETPASS_H
#define FORGETPASS_H
#include <signupform.h>
#include <QMainWindow>
#include <mainwindow.h>

namespace Ui {
class forgetpass;
}

class forgetpass : public QMainWindow
{
    Q_OBJECT

public:
    explicit forgetpass(QWidget *parent = nullptr);
    ~forgetpass();

private slots:
    void on_back_clicked();

    void on_create_clicked();

    void on_change_clicked();

private:
    Ui::forgetpass *ui;
};

#endif // FORGETPASS_H
