#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <QDebug>
#include <time.h>//for qsrand

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

void MainWindow::on_btn_create_clicked()
{
    bool ok_from, ok_to, ok_num;//QString can be converted into int
    //get number form lineEdit
    i_from = ui->lEdit_from->text().toInt(&ok_from);
    i_to = ui->lEdit_to->text().toInt(&ok_to);
    i_num = ui->lEdit_num->text().toInt(&ok_num);

    if(ok_from && ok_to && ok_num){
        if(i_to < i_from){
            QMessageBox::warning(this, "Error", "from x to y, then x can't less than y!");
        }
        else{
            QString s_result = "";
            int result[i_num];
            qsrand(time(NULL));
            for(int i = 0; i < i_num; i++){
                result[i] = qrand()%(i_to - i_from + 1) + i_from;
                s_result += (QString::number(result[i])+((i == i_num - 1)?"":",  "));
            }
//            qDebug() << s_result << endl;
            ui->result_print->setWordWrap(true);//can wrap a new line
            ui->result_print->setText(s_result);
        }
    }
    else{
        QMessageBox::warning(this, "Error", "Need to input number!");
    }
}
