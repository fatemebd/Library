#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <signupform.h>
#include <QMainWindow>
#include <forgetpass.h>
#include <adminform.h>
#include <memberform.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_signup_clicked();



    void on_forgetpass_clicked();

    void on_login_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
