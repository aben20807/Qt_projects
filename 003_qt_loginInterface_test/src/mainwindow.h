#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>
#include <QMessageBox>
#include <QString>
#include <QCryptographicHash>
#include "signup.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);

    QSqlDatabase signIndb;
    /*use for manipulare databace*/
    bool connectOpen(){
        signIndb = QSqlDatabase::addDatabase("QSQLITE");
        signIndb.setDatabaseName("./res/db/signIn.sqlite");
        if(!signIndb.open()){
//            qDebug() << "Failed to connect db!";
            return false;
        }
        else{
//            qDebug() << "Connected!";
            return true;
        }
    }
    void connectClose(){
        signIndb.close();
        signIndb.removeDatabase(QSqlDatabase::defaultConnection);
    }

private slots:
    void on_btn_signIn_clicked();

    void on_btn_signUp_clicked();

    void close_child();

    void on_btn_cancel_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    bool m_show_child;
};

#endif // MAINWINDOW_H
