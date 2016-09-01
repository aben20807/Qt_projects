#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QDebug>
#include <QTranslator>
#include <QMenu>
#include <QAction>
#include <QTimer>
#include <QSystemTrayIcon>
#include <QProcess>
#include <QtSql>
#include <QPainter>
#include <QSignalMapper>
#include "battery.h"
#include "schedule.h"
#include "cmdprocess.h"

namespace Ui {
class MainWindow;

}
class Schedule;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initMenu();
    void applyLanguage();
    void initSystemTrayIcon();
    void initBatteryDisplay();
    void displayBatteryThings(int batteryLevel, QString batteryStatus);
    void changeEvent(QEvent *event);
    void initTableDisplay();
    void initActionToDo();

    void show();

    QSqlDatabase actiondb;
    /*use for manipulare databace*/
    bool connectOpen(){
        actiondb = QSqlDatabase::addDatabase("QSQLITE");
        actiondb.setDatabaseName("./res/db/batteryAction.sqlite");
        if(!actiondb.open()){
            qDebug() << "Failed to connect db!";
            return false;
        }
        else{
            return true;
        }
    }
    void connectClose(){
        actiondb.close();
        actiondb.removeDatabase(QSqlDatabase::defaultConnection);
    }

private slots:
    void on_action_zhTW_triggered();

    void on_action_enUS_triggered();

    void on_actionQuit_triggered();

    void on_actionMinimize_triggered();

    void iconActivated(QSystemTrayIcon::ActivationReason reason);

    void updateSystemTrayIconDisplay();

    void updateBatteryDisplay();

    void updateTableDisplay();

    void updateActionToDo();

    void detectActionAndDo(const int &_numOfAction);

    void on_actionSystem_tray_triggered();

    void on_actionTaskbar_triggered();

    void close_child();

    void on_actionManage_triggered();

private:
    Ui::MainWindow *ui;
    QTranslator *translator;
    QString languageMode;
    QSystemTrayIcon *tray;
    QString minimizeMode;
    QAction *restoreAction;
    QTimer *updateTime;
    Battery *battery;
    Schedule *schedule;
    bool m_show_child;
    CmdProcess *cmdprocess;
    bool doOnce[5];
    QString _condition[5];
    int _level[5];
    QString _action[5];
    QTimer *detectTime[5];
};

#endif // MAINWINDOW_H
