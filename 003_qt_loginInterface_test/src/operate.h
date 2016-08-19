#ifndef OPERATE_H
#define OPERATE_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Operate;
}

class Operate : public QDialog
{
    Q_OBJECT

public:
    explicit Operate(QWidget *parent = 0, QString username = NULL, QString password = NULL);
    ~Operate();

protected:
    void closeEvent(QCloseEvent *);

private slots:
    void close_child();

    void on_btn_cancel_clicked();

    void on_btn_delete_clicked();

signals:
    void close_me();

private:
    Ui::Operate *ui;
    bool m_show_child;
    QString _username;
    QString _password;
};

#endif // OPERATE_H
