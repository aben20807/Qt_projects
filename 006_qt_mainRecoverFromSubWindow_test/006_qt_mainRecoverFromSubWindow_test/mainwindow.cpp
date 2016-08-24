#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::close_child()//MainWindow 就是主視窗的 class
{
    m_show_child = false;
}

void MainWindow::gotoSubWindow()
{
    SubWindow subWindow;//SubWindow 就是副視窗的 class
    this->hide();
    QObject::connect(&subWindow,SIGNAL(close_me()),this,SLOT(close_child()));
    m_show_child = true;
    while (m_show_child)
    {
        subWindow.exec();
    }
    this->show();
}
void MainWindow::on_pushButton_clicked()
{
    gotoSubWindow();
}
