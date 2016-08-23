#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QDebug>
#include <QTranslator>
#include <QMenu>
#include <QAction>
#include <QSystemTrayIcon>
#include <QProcess>
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
    void displaySchedule();

private slots:
    void on_action_zhTW_triggered();

    void on_action_enUS_triggered();

    void on_actionQuit_triggered();

    void on_actionMinimize_triggered();

    void iconActivated(QSystemTrayIcon::ActivationReason reason);

    void updateDisplay();

private:
    Ui::MainWindow *ui;
    QTranslator *translator;
    QString languageMode;
    QSystemTrayIcon *tray;
    QTimer *updateTime;
    Battery *battery;
};

#endif // MAINWINDOW_H
