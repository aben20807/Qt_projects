#include "log.h"
#include "ui_log.h"

Log::Log(QWidget *parent, QString allLog) :
    QDialog(parent),
    ui(new Ui::Log)
{
    ui->setupUi(this);
    ui->textBrowser_log->setText(allLog);
}

Log::~Log()
{
    delete ui;
}

void Log::close_child()
{
    m_show_child = false;
}

void Log::closeEvent(QCloseEvent *)
{
    emit close_me();
}
