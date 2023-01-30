#ifndef SEARCHINCAT_H
#define SEARCHINCAT_H

#include <QMainWindow>

namespace Ui {
class searchincat;
}

class searchincat : public QMainWindow
{
    Q_OBJECT

public:
    explicit searchincat(QWidget *parent = nullptr);
    ~searchincat();

private slots:
    void on_search_textChanged(const QString &arg1);

private:
    Ui::searchincat *ui;
};

#endif // SEARCHINCAT_H
