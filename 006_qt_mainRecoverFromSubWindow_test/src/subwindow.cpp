#include "subwindow.h"
#include "ui_subwindow.h"

SubWindow::SubWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SubWindow)
{
    ui->setupUi(this);
}

SubWindow::~SubWindow()
{
    delete ui;
}

void SubWindow::close_child()
{
    m_show_child = false;
}

void SubWindow::closeEvent(QCloseEvent *)
{
    emit close_me();
}
