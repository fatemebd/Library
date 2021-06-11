#ifndef DELETEFORM_H
#define DELETEFORM_H
#include <adminform.h>
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

private slots:
    void on_back_clicked();

    void on_deletepush_clicked();

private:
    Ui::deleteform *ui;
};

#endif // DELETEFORM_H
