#include "operate.h"
#include "ui_operate.h"

Operate::Operate(QWidget *parent, QString username, QString password) :
    QDialog(parent),
    ui(new Ui::Operate), _username(username) ,_password(password)
{
    ui->setupUi(this);

    Qt::WindowFlags flags = 0;
    flags |= Qt::WindowMinimizeButtonHint;
    flags |= Qt::WindowCloseButtonHint;
    setWindowFlags(flags); //Maximize ban
    setFixedSize(QWidget::geometry().width(),QWidget::geometry().height()); //Prohibition on changing the window size

    MainWindow conn;
    if(!conn.connectOpen()){
        ui->label_status->setText("Failed to connect db!");
    }
    else{
        ui->label_status->setText("Connected!");
    }
}

Operate::~Operate()
{
    delete ui;
}

void Operate::on_btn_cancel_clicked()
{
    this->close();
}

void Operate::close_child()
{
    m_show_child = false;
}

void Operate::closeEvent(QCloseEvent *)
{
    emit close_me();
}



void Operate::on_btn_delete_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm Delete", "Sure to delete this account?",
                                  QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::No){

    }
    else{
        MainWindow conn;
        if(!conn.connectOpen()){
            qDebug() << "Fail to open db" << endl;
            return;
        }

//        qDebug() << _username << " " << _password << endl;
        conn.connectOpen();
        QSqlQuery qry;
        qry.prepare("Delete from data where username = '"+_username+"'");
        if(qry.exec()){
            QMessageBox::information(this, "OuO", "Succeed to delete!");
            conn.connectClose();
            this->close();
        }
        else{
            QMessageBox::critical(this, tr("Error::"), qry.lastError().text());
        }
    }
}
