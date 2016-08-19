#include "signup.h"
#include "ui_signup.h"

SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);

    MainWindow conn;
    if(!conn.connectOpen()){
        ui->label_status->setText("Failed to connect db!");
    }
    else{
        ui->label_status->setText("Connected!");
    }
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_btn_signUp_conf_clicked()
{
    /*TODO INSERT INTO data (number, username, password, signUpTime) VALUES (2, "ab", "12", "12")*/
    MainWindow conn;
    if(!conn.connectOpen()){
        qDebug() << "Fail to open db" << endl;
        return;
    }

    QString username, password, password_conf, fullname;
    username = ui->lE_userName->text();
    password = ui->lE_password->text();
    password_conf = ui->lE_password_conf->text();
    fullname = ui->lE_fullName->text();

    if(username == NULL || password == NULL || password_conf == NULL || fullname == NULL){
        QMessageBox::warning(this, "Error", "Do not allow any blank!");
    }
    else if(password != password_conf){
        QMessageBox::warning(this, "Error", "The confirm password was incorrect!");
    }
    else{
        QDateTime time = QDateTime::currentDateTime();//get time now
        QString str_time = time.toString("yyyy-MM-dd ddd hh:mm:ss"); //set the display format

//        qDebug() << str_time << endl;
        conn.connectOpen();
        QSqlQuery qry;
        qry.prepare("select * from data where username = '"+username+"'");
        if(qry.exec()){//to check if username has existed
            int count = 0;
            while(qry.next()){
                count++;
            }
            if(count != 0){
                QMessageBox::warning(this, "Error", "Duplicate user!");
            }
            else{
                qry.prepare("insert into data (username, password, signUpTime, fullname) values ('"+username+"' , '"+password+"' , '"+str_time+"' , '"+fullname+"' )");
                if(qry.exec()){
                    QMessageBox::information(this, "OuO", "Succeed to sign up !");
                    conn.connectClose();
                }
                else{
                    QMessageBox::critical(this, tr("Error::"), qry.lastError().text());
                }

                this->close();
//                MainWindow->show();
            }
        }
    }
}
