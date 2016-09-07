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
#include <QSettings>
#include <QFile>
#include <QTextStream>

#include "battery.h"
#include "schedule.h"
#include "cmdprocess.h"
#include "log.h"

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
    inline void loadSettingIni();
    inline void saveSettingIni(QString _languageMode, QString _minimizeMode);
    inline void initMenu();
    inline void applyLanguage();
    inline void applyMinimize();
    inline void initSystemTrayIcon();
    inline void initBatteryDisplay();
    inline void displayBatteryThings(int batteryLevel, QString batteryStatus);
    void changeEvent(QEvent *event);
    inline void initTableDisplay();
    inline void initActionToDo();
    inline void writeLog(QString actionRecord, QString filename = "./res/log/log.txt");
    inline QString readLog(QString filename);
    void show();

    QSqlDatabase actiondb;
    /*use for manipulare databace*/
    inline bool connectOpen(){
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
    inline void connectClose(){
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

    void on_actionError_report_triggered();

    void on_actionAbout_triggered();

    void on_actionAction_explaintion_triggered();

    void on_actionAbout_Actions_triggered();

    void on_actionReference_or_Resource_triggered();

    void on_actionCheck_log_triggered();

private:
    Ui::MainWindow *ui;
    QTranslator *translator;
    QString languageMode;
    QSystemTrayIcon *tray;
    QMenu *trayIconMenu;//the menu of QSystemTrayIcon
    QString minimizeMode;
    QAction *restoreAction;
    QTimer *updateTime;
    Battery *battery;
    Schedule *schedule;
    Log *log;
    QSqlQueryModel *model;
    bool m_show_child;
    CmdProcess *cmdprocess;
    bool doOnce[5];
    QSignalMapper *signalMapper;
    QString _condition[5];
    int _level[5];
    QString _action[5];
    QTimer *detectTime[5];
};

#endif // MAINWINDOW_H
