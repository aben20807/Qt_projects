#include "signup.h"
#include "ui_signup.h"

SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_btn_signUp_conf_clicked()
{
    /*TODO INSERT INTO data (number, username, password, signUpTime) VALUES (2, "ab", "12", "12")*/
}
