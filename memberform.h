#ifndef MEMBERFORM_H
#define MEMBERFORM_H
#include <mainwindow.h>
#include <QMainWindow>

namespace Ui {
class memberform;
}

class memberform : public QMainWindow
{
    Q_OBJECT

public:
    explicit memberform(QWidget *parent = nullptr);
    ~memberform();

private:
    Ui::memberform *ui;
};

#endif // MEMBERFORM_H
