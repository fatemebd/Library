#ifndef SHOWALL_H
#define SHOWALL_H

#include <QMainWindow>

namespace Ui {
class showall;
}

class showall : public QMainWindow
{
    Q_OBJECT

public:
    explicit showall(QWidget *parent = nullptr);
    ~showall();

private slots:
    void on_search_textChanged(const QString &arg1);

private:
    Ui::showall *ui;
};

#endif // SHOWALL_H
