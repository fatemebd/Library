#ifndef ADDFORM_H
#define ADDFORM_H

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

private:
    Ui::addform *ui;
};

#endif // ADDFORM_H
