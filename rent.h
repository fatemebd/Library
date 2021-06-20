#ifndef RENT_H
#define RENT_H

#include <QMainWindow>

namespace Ui {
class rent;
}

class rent : public QMainWindow
{
    Q_OBJECT
    QString *username;

public:
    explicit rent(QWidget *parent = nullptr,QString* username=nullptr);
    ~rent();

private slots:
    void on_rentbook_clicked();

private:
    Ui::rent *ui;
};

#endif // RENT_H
