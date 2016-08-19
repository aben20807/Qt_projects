#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    connectOpen();//connect database
    if(!connectOpen()){
        ui->label_status->setText("Failed to connect db!");
    }
    else{
        ui->label_status->setText("Connected!");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    // Setting the QGraphicsScene
    int littleError = 2;//the error for graphicsView
    scene = new QGraphicsScene(0,0,ui->graphicsView->width()-littleError,ui->graphicsView->height()-littleError);
    ui->graphicsView->setScene(scene);
    //scene->setSceneRect(10,4,800,530);
}

void MainWindow::on_btn_signIn_clicked()
{
    if(!connectOpen()){
        qDebug() << "Fail to open db" << endl;
        return;
    }

    QString username, password;
    username = ui->lE_userName->text();
    password = ui->lE_password->text();

    connectOpen();
    QSqlQuery qry;
    qry.prepare("select * from data where username = '"+username+"' and password = '"+password+"'");
    if(qry.exec()){
        int count = 0;
        while(qry.next()){
            count++;
        }
        switch (count) {
        case 0:
            QMessageBox::warning(this, "Error", "Wrong user name or password!");
            break;
        case 1:
            QMessageBox::information(this, "OuO", "Succeed to sign in!");
            break;
        default:
            QMessageBox::warning(this, "Error", "Duplicate user!");
            break;
        }
    }
}

void MainWindow::on_btn_signUp_clicked()
{
    connectClose();
    this->hide();
    SignUp signUp;
    signUp.setModal(true);
    signUp.exec();
}
