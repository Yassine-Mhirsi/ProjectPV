#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>

namespace Ui {
class Welcome;
}

class Welcome : public QWidget
{
    Q_OBJECT

public:
    explicit Welcome(QWidget *parent = nullptr);
    ~Welcome();
    void showEvent(QShowEvent *event);
    void on_welcome_clicked();

private slots:


private:
    Ui::Welcome *ui;
};

#endif // WELCOME_H
