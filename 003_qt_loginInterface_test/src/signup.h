#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = 0);
    ~SignUp();

protected:
    void closeEvent(QCloseEvent *);

private slots:
    void on_btn_signUp_conf_clicked();

    void close_child();

    void on_btn_cancel_clicked();

signals:
    void close_me();

private:
    Ui::SignUp *ui;
    bool m_show_child;
};

#endif // SIGNUP_H
