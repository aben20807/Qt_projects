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

void MainWindow::on_btn_create_clicked()
{
    ui->result_print->clear();
    bool ok_from, ok_to, ok_num;//QString can be converted into int
    //get number form lineEdit
    i_from = ui->lEdit_from->text().toInt(&ok_from);
    i_to = ui->lEdit_to->text().toInt(&ok_to);
    i_num = ui->lEdit_num->text().toInt(&ok_num);

    if(ok_from && ok_to && ok_num){
        if(i_to < i_from){
            QMessageBox::warning(this, "Error", "From x to y, then x cannot less than y!");
        }
        else if(!(ui->radioBtn_repeat->isChecked()) && (i_to - i_from + 1 < i_num)){
            QMessageBox::warning(this, "Error", "If not allow repeat, it needs enought numbers!");
        }
        else{
            QString s_result;
            int result[i_num];
            qsrand(time(NULL));
            for(int i = 0; i < i_num; i++){
                if(!(ui->radioBtn_repeat->isChecked())){
                    result[i] = qrand()%(i_to - i_from + 1) + i_from;
                    for(int j = 0; j < i; j++){
                        if(result[i] == result[j]){
                            i--;
                            continue;
                        }
                    }
                }
                else{
                    result[i] = qrand()%(i_to - i_from + 1) + i_from;
                }

            }
            for(int i = 0; i < i_num; i++){
                s_result += (QString::number(result[i])+((i == i_num - 1)?"":",  "));
            }
//            qDebug() << s_result << endl;
            ui->result_print->setWordWrap(true);//can wrap a new line
            ui->result_print->setText(s_result);
        }
    }
    else{
        QMessageBox::warning(this, "Error", "Need to input legal number!");
    }
}

void MainWindow::on_btn_reset_clicked()
{
    ui->lEdit_from->clear();
    ui->lEdit_to->clear();
    ui->lEdit_num->setText("1");
    ui->result_print->clear();
    ui->radioBtn_repeat->setChecked(true);
}
