#include "schedule.h"
#include "ui_schedule.h"

Schedule::Schedule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Schedule)
{
    ui->setupUi(this);
}

Schedule::~Schedule()
{
    delete ui;
}

void Schedule::close_child()//
{
    m_show_child = false;
}

void Schedule::closeEvent(QCloseEvent *)//
{
    emit close_me();
}
