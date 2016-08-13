#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    flag=false;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_0_clicked()
{
    if(flag)
    {
        timer->stop();
        flag=false;
    }
    ui->progressBar->setValue(0);
}

void MainWindow::on_pushButton_100_clicked()
{
    if(flag)
    {
        timer->stop();
        flag=false;
    }
    ui->progressBar->setValue(100);
}

void MainWindow::on_pushButton_add10_clicked()
{
    if(flag)
    {
        timer->stop();
        flag=false;
    }
    ui->progressBar->setValue(ui->progressBar->value()+10);
}

void MainWindow::on_pushButton_sub10_clicked()
{
    if(flag)
    {
        timer->stop();
        flag=false;
    }
    ui->progressBar->setValue(ui->progressBar->value()-10);
}
void MainWindow::Timer()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(MySlot()));
    timer->start(100);//0.1s to add 1%
}
void MainWindow::MySlot()
{
    ui->progressBar->setValue(ui->progressBar->value()+1);
}
void MainWindow::on_pushButton_autorun_clicked()
{
    flag=true;
    Timer();  
}

void MainWindow::on_pushButton_clicked()
{
    if(flag)
    {
        timer->stop();
        flag=false;
    }
}
