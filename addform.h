#ifndef ADDFORM_H
#define ADDFORM_H
#include <adminform.h>
#include <QMainWindow>

namespace Ui {
class addform;
}

class addform : public QMainWindow
{
    Q_OBJECT

public:
    explicit addform(QWidget *parent = nullptr);
    ~addform();

private slots:
    void on_add_clicked();

    void on_back_clicked();

private:
    Ui::addform *ui;
};

#endif // ADDFORM_H
