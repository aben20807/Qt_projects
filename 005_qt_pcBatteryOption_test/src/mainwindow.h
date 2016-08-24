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
#include <QSqlDatabase>
#include "battery.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initMenu();
    void applyLanguage();
    void initSystemTrayIcon();
    void initDisplay();
    void displayBatteryThings(int batteryLevel, QString batteryStatus);
    void changeEvent(QEvent *event);
    void show();

    void displaySchedule();

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

    void updateDisplay();

    void on_actionSystem_tray_triggered();

    void on_actionTaskbar_triggered();

private:
    Ui::MainWindow *ui;
    QTranslator *translator;
    QString languageMode;
    QSystemTrayIcon *tray;
    QString minimizeMode;
    QAction *restoreAction;
    QTimer *updateTime;
    Battery *battery;
};

#endif // MAINWINDOW_H
