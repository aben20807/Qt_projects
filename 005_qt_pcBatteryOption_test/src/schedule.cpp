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

void Schedule::on_buttonBox_okCancel_clicked(QAbstractButton *button)
{
    QString tmp_condition1 = ui->comboBox_condition1->currentText();
    QString tmp_level1 = ui->lEdit_1->text();
    QString tmp_action1 = ui->comboBox_action1->currentText();
    QString tmp_condition2 = ui->comboBox_condition2->currentText();
    QString tmp_level2 = ui->lEdit_2->text();
    QString tmp_action2 = ui->comboBox_action2->currentText();
    QString tmp_condition3 = ui->comboBox_condition3->currentText();
    QString tmp_level3 = ui->lEdit_3->text();
    QString tmp_action3 = ui->comboBox_action3->currentText();
    QString tmp_condition4 = ui->comboBox_condition4->currentText();
    QString tmp_level4 = ui->lEdit_4->text();
    QString tmp_action4 = ui->comboBox_action4->currentText();

    if((QPushButton *)button == ui->buttonBox_okCancel->button(QDialogButtonBox::Ok)){
//        qDebug() << "OK" << endl;
    }
    else if((QPushButton *)button == ui->buttonBox_okCancel->button(QDialogButtonBox::Cancel)){
//        qDebug() << "Cancel" << endl;
        this->close();
    }
    else if((QPushButton *)button == ui->buttonBox_okCancel->button(QDialogButtonBox::Apply)){
//        qDebug() << "Apply" << endl;
    }
}

void Schedule::close_child()//
{
    m_show_child = false;
}

void Schedule::closeEvent(QCloseEvent *)//
{
    emit close_me();
}
