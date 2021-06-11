#ifndef DELETEFORM_H
#define DELETEFORM_H

#include <QMainWindow>

namespace Ui {
class deleteform;
}

class deleteform : public QMainWindow
{
    Q_OBJECT

public:
    explicit deleteform(QWidget *parent = nullptr);
    ~deleteform();

private:
    Ui::deleteform *ui;
};

#endif // DELETEFORM_H
