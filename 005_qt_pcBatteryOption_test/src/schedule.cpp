#include "schedule.h"
#include "ui_schedule.h"

Schedule::Schedule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Schedule)
{
    ui->setupUi(this);

    MainWindow conn;
    if(!conn.connectOpen()){
        ui->label_connectStatus->setText("Failed to connect db!");
    }
    else{
        ui->label_connectStatus->setText("Connected!");
    }
}

Schedule::~Schedule()
{
    delete ui;
}



void Schedule::on_buttonBox_okCancel_clicked(QAbstractButton *button)
{
    catchInformations();
    if((QPushButton *)button == ui->buttonBox_okCancel->button(QDialogButtonBox::Ok)){
//        qDebug() << "OK" << endl;
        updateDataToDatabase();
        this->close();
    }
    else if((QPushButton *)button == ui->buttonBox_okCancel->button(QDialogButtonBox::Cancel)){
//        qDebug() << "Cancel" << endl;
        this->close();
    }
    else if((QPushButton *)button == ui->buttonBox_okCancel->button(QDialogButtonBox::Apply)){
//        qDebug() << "Apply" << endl;
        updateDataToDatabase();
    }
}

void Schedule::catchInformations()
{
    tmp_condition1 = ui->comboBox_condition1->currentText();
    tmp_level1 = ui->lEdit_1->text();
    tmp_action1 = ui->comboBox_action1->currentText();
    tmp_condition2 = ui->comboBox_condition2->currentText();
    tmp_level2 = ui->lEdit_2->text();
    tmp_action2 = ui->comboBox_action2->currentText();
    tmp_condition3 = ui->comboBox_condition3->currentText();
    tmp_level3 = ui->lEdit_3->text();
    tmp_action3 = ui->comboBox_action3->currentText();
    tmp_condition4 = ui->comboBox_condition4->currentText();
    tmp_level4 = ui->lEdit_4->text();
    tmp_action4 = ui->comboBox_action4->currentText();
}

void Schedule::updateDataToDatabase()
{
    MainWindow conn;
    if(!conn.connectOpen()){
        qDebug() << "Fail to open db" << endl;
        return;
    }
    conn.connectOpen();
    QSqlQuery qry;
    /*1*/
    qry.prepare("update data set Condition='"+tmp_condition1+"',level='"+tmp_level1+"',action='"+tmp_action1+"' where Number=1");
    if(qry.exec()){
//        qDebug() << "Succeed to update 1" << endl;
    }
    else{
        QMessageBox::critical(this, tr("Error 1::"), qry.lastError().text());
    }
    /*2*/
    qry.prepare("update data set Condition='"+tmp_condition2+"',level='"+tmp_level2+"',action='"+tmp_action2+"' where Number=2");
    if(qry.exec()){
//        qDebug() << "Succeed to update 2" << endl;
    }
    else{
        QMessageBox::critical(this, tr("Error 2::"), qry.lastError().text());
    }
    /*3*/
    qry.prepare("update data set Condition='"+tmp_condition3+"',level='"+tmp_level3+"',action='"+tmp_action3+"' where Number=3");
    if(qry.exec()){
//        qDebug() << "Succeed to update 3" << endl;
    }
    else{
        QMessageBox::critical(this, tr("Error 3::"), qry.lastError().text());
    }
    /*4*/
    qry.prepare("update data set Condition='"+tmp_condition4+"',level='"+tmp_level4+"',action='"+tmp_action4+"' where Number=4");
    if(qry.exec()){
//        qDebug() << "Succeed to update 4" << endl;
    }
    else{
        QMessageBox::critical(this, tr("Error 4::"), qry.lastError().text());
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
