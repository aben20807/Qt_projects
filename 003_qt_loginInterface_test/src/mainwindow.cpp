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

void MainWindow::showEvent(QShowEvent *)
{
    // Setting the QGraphicsScene
    int littleError = 2;//the error for graphicsView
    scene = new QGraphicsScene(0,0,ui->graphicsView->width()-littleError,ui->graphicsView->height()-littleError);
    ui->graphicsView->setScene(scene);
    //scene->setSceneRect(10,4,800,530);
}
