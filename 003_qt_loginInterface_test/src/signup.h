#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
//#include <QGraphicsScene>
//#include <QDebug>
//#include <QMessageBox>
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

private slots:
    void on_btn_signUp_conf_clicked();

private:
    Ui::SignUp *ui;
};

#endif // SIGNUP_H
