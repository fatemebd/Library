#ifndef RETURNBOOK_H
#define RETURNBOOK_H

#include <QMainWindow>

namespace Ui {
class returnbook;
}

class returnbook : public QMainWindow
{
    Q_OBJECT

public:
    explicit returnbook(QWidget *parent = nullptr);
    ~returnbook();

private slots:
    void on_returnb_clicked();

private:
    Ui::returnbook *ui;
};

#endif // RETURNBOOK_H
