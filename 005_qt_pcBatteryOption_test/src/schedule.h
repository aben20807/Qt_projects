#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QDialog>
#include <QDebug>
#include <QAbstractButton>
#include <QMessageBox>
#include "mainwindow.h"

namespace Ui {
class Schedule;
}

class Schedule : public QDialog
{
    Q_OBJECT

public:
    explicit Schedule(QWidget *parent = 0);
    ~Schedule();
    void catchInformationsFromUi();
    void updateDataToDatabase();
    void readDataFromDatabase();
    bool isAllLeditCanConvertToInt();
    QString translateCondition(QString condition) const;
    QString translateAction(QString action) const;


protected:
    void closeEvent(QCloseEvent *);

signals:
    void close_me();
    void updateTable();

private slots:
    void close_child();

    void on_buttonBox_okCancel_clicked(QAbstractButton *button);

private:
    Ui::Schedule *ui;
    bool m_show_child;

    QString tmp_condition1;
    QString tmp_level1;
    int num_level1;
    QString tmp_action1;
    QString tmp_condition2;
    QString tmp_level2;
    int num_level2;
    QString tmp_action2;
    QString tmp_condition3;
    QString tmp_level3;
    int num_level3;
    QString tmp_action3;
    QString tmp_condition4;
    QString tmp_level4;
    int num_level4;
    QString tmp_action4;
};

#endif // SCHEDULE_H
