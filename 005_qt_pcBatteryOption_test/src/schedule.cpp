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
        //ui->label_connectStatus->setText("Connected!");
        ui->label_connectStatus->setText("");
    }
    readDataFromDatabase();
}

Schedule::~Schedule()
{
    delete ui;
}

void Schedule::on_buttonBox_okCancel_clicked(QAbstractButton *button)
{
    MainWindow conn;
    catchInformationsFromUi();
    if((QPushButton *)button == ui->buttonBox_okCancel->button(QDialogButtonBox::Ok)){
        //        qDebug() << "OK" << endl;
        updateDataToDatabase();
        conn.connectClose();
        if(isAllLeditCanConvertToInt()){//Only close when can apply
            this->close();
        }
    }
    else if((QPushButton *)button == ui->buttonBox_okCancel->button(QDialogButtonBox::Cancel)){
        //        qDebug() << "Cancel" << endl;
        conn.connectClose();
        this->close();
    }
    else if((QPushButton *)button == ui->buttonBox_okCancel->button(QDialogButtonBox::Apply)){
        //        qDebug() << "Apply" << endl;
        updateDataToDatabase();
    }
}

void Schedule::catchInformationsFromUi()
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

bool Schedule::isAllLeditCanConvertToInt()
{
    bool isLeditCanConvertToInt1 = true;
    bool isLeditCanConvertToInt2 = true;
    bool isLeditCanConvertToInt3 = true;
    bool isLeditCanConvertToInt4 = true;
    num_level1 = 0;
    num_level2 = 0;
    num_level3 = 0;
    num_level4 = 0;
    if(!ui->lEdit_1->text().isEmpty())num_level1 = tmp_level1.toInt(&isLeditCanConvertToInt1);
    if(!ui->lEdit_2->text().isEmpty())num_level2 = tmp_level2.toInt(&isLeditCanConvertToInt2);
    if(!ui->lEdit_3->text().isEmpty())num_level3 = tmp_level3.toInt(&isLeditCanConvertToInt3);
    if(!ui->lEdit_4->text().isEmpty())num_level4 = tmp_level4.toInt(&isLeditCanConvertToInt4);
    //    qDebug() << isLeditCanConvertToInt1 << isLeditCanConvertToInt2 <<
    //                isLeditCanConvertToInt3 << isLeditCanConvertToInt4 <<
    //                (num_level1 > 100 || num_level1 < 0) << num_level1 <<
    //                (num_level2 > 100 || num_level2 < 0) << num_level2 <<
    //                (num_level3 > 100 || num_level3 < 0) << num_level3 <<
    //                (num_level4 > 100 || num_level4 < 0) << num_level4;
    if((!isLeditCanConvertToInt1 || (isLeditCanConvertToInt1 && (num_level1 > 100 || num_level1 < 0))) ||
            (!isLeditCanConvertToInt2 || (isLeditCanConvertToInt2 && (num_level2 > 100 || num_level2 < 0))) ||
            (!isLeditCanConvertToInt3 || (isLeditCanConvertToInt3 && (num_level3 > 100 || num_level3 < 0))) ||
            (!isLeditCanConvertToInt4 || (isLeditCanConvertToInt4 && (num_level4 > 100 || num_level4 < 0)))){
        return false;
    }
    return true;
}

bool Schedule::checkRowIsFilled(int row)
{
//    switch (row) {
//    case 1:
//        if(ui->comboBox_condition1->currentText() != "Choose one" &&
//           !ui->lEdit_1->text().isEmpty() &&
//           ui->comboBox_action1->currentText() != "Nothing")
//            return true;
//        else
//            return false;
//    case 2:
//        if(ui->comboBox_condition2->currentText() != "Choose one" &&
//           !ui->lEdit_2->text().isEmpty() &&
//           ui->comboBox_action2->currentText() != "Nothing")
//            return true;
//        else
//            return false;
//    case 3:
//        if(ui->comboBox_condition3->currentText() != "Choose one" &&
//           !ui->lEdit_3->text().isEmpty() &&
//           ui->comboBox_action3->currentText() != "Nothing")
//            return true;
//        else
//            return false;
//    case 4:
//        if(ui->comboBox_condition4->currentText() != "Choose one" &&
//           !ui->lEdit_4->text().isEmpty() &&
//           ui->comboBox_action4->currentText() != "Nothing")
//            return true;
//        else
//            return false;
//    default:
//        return false;
//        break;
//    }
}

void Schedule::updateDataToDatabase()
{
    if(!isAllLeditCanConvertToInt()){
        QMessageBox::warning(this, tr("Error"), tr("Need to input legal level!"));
        return;
    }
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
        QMessageBox::critical(this, tr("Error u1::"), qry.lastError().text());
    }
    /*2*/
    qry.prepare("update data set Condition='"+tmp_condition2+"',level='"+tmp_level2+"',action='"+tmp_action2+"' where Number=2");
    if(qry.exec()){
        //        qDebug() << "Succeed to update 2" << endl;
    }
    else{
        QMessageBox::critical(this, tr("Error u2::"), qry.lastError().text());
    }
    /*3*/
    qry.prepare("update data set Condition='"+tmp_condition3+"',level='"+tmp_level3+"',action='"+tmp_action3+"' where Number=3");
    if(qry.exec()){
        //        qDebug() << "Succeed to update 3" << endl;
    }
    else{
        QMessageBox::critical(this, tr("Error u3::"), qry.lastError().text());
    }
    /*4*/
    qry.prepare("update data set Condition='"+tmp_condition4+"',level='"+tmp_level4+"',action='"+tmp_action4+"' where Number=4");
    if(qry.exec()){
        //        qDebug() << "Succeed to update 4" << endl;
    }
    else{
        QMessageBox::critical(this, tr("Error u4::"), qry.lastError().text());
    }
    conn.connectClose();
}

void Schedule::readDataFromDatabase()
{
    MainWindow conn;
    if(!conn.connectOpen()){
        qDebug() << "Fail to open db" << endl;
        return;
    }
    conn.connectOpen();
    QSqlQuery qry;
    /*1*/
    qry.prepare("select * from data where Number=1");
    if(qry.exec()){
        while(qry.next()){
            ui->comboBox_condition1->setCurrentText(qry.value(1).toString());
            ui->lEdit_1->setText(qry.value(2).toString());
            ui->comboBox_action1->setCurrentText(qry.value(3).toString());
        }
    }
    else{
        QMessageBox::critical(this, tr("Error r1::"), qry.lastError().text());
    }
    /*2*/
    qry.prepare("select * from data where Number=2");
    if(qry.exec()){
        while(qry.next()){
            ui->comboBox_condition2->setCurrentText(qry.value(1).toString());
            ui->lEdit_2->setText(qry.value(2).toString());
            ui->comboBox_action2->setCurrentText(qry.value(3).toString());
        }
    }
    else{
        QMessageBox::critical(this, tr("Error r2::"), qry.lastError().text());
    }
    /*3*/
    qry.prepare("select * from data where Number=3");
    if(qry.exec()){
        while(qry.next()){
            ui->comboBox_condition3->setCurrentText(qry.value(1).toString());
            ui->lEdit_3->setText(qry.value(2).toString());
            ui->comboBox_action3->setCurrentText(qry.value(3).toString());
        }
    }
    else{
        QMessageBox::critical(this, tr("Error r3::"), qry.lastError().text());
    }
    /*4*/
    qry.prepare("select * from data where Number=4");
    if(qry.exec()){
        while(qry.next()){
            ui->comboBox_condition4->setCurrentText(qry.value(1).toString());
            ui->lEdit_4->setText(qry.value(2).toString());
            ui->comboBox_action4->setCurrentText(qry.value(3).toString());
        }
    }
    else{
        QMessageBox::critical(this, tr("Error r4::"), qry.lastError().text());
    }
    conn.connectClose();
}

void Schedule::close_child()
{
    m_show_child = false;
}

void Schedule::closeEvent(QCloseEvent *)
{
    emit close_me();
}
