#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initMenu();
    initSystemTrayIcon();
    initDisplay();
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMenu()
{
    ui->action_zhTW->setIcon(QIcon(":/img/flag_taiwan"));
    ui->action_enUS->setIcon(QIcon(":/img/flag_usa"));
    ui->action_enUS->setCheckable(true);
    ui->action_enUS->setCheckable(true);
    languageMode = "enUS";
}

void MainWindow::on_action_zhTW_triggered()
{
    if(languageMode != "zhTW"){
        languageMode = "zhTW";
        applyLanguage();
    }
}

void MainWindow::on_action_enUS_triggered()
{
    if(languageMode != "enUS"){
        languageMode = "enUS";
        applyLanguage();
    }
}

void MainWindow::applyLanguage()
{
    if(languageMode == "zhTW"){
        qDebug() << "change to 繁體中文" << endl;
//        translator->load(QString("./language/zh_TW"));
        ui->action_zhTW->setChecked(true);
        ui->action_enUS->setChecked(false);
    }
    else if(languageMode == "enUS"){
        qDebug() << "change to English" << endl;
//        translator->load(QString("./language/en_US"));
        ui->action_enUS->setChecked(true);
        ui->action_zhTW->setChecked(false);
    }
//    qApp->installTranslator(translator);
    //initGui
}

void MainWindow::initSystemTrayIcon()
{
    tray = new QSystemTrayIcon(this);
    tray->setIcon(QIcon(":/img/flag_taiwan"));/*TODO find icon*/
    connect(tray,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));

    QAction *restoreAction;
    restoreAction = new QAction(QIcon(":/img/flag_taiwan"), "Restore", this);
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(show()));
    connect(restoreAction, SIGNAL(triggered()), tray, SLOT(hide()));

    QMenu *trayIconMenu;//the menu of QSystemTrayIcon
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(restoreAction);
    trayIconMenu->addAction(ui->actionQuit);//quit action from ui
    tray->setContextMenu(trayIconMenu);
}

void MainWindow::initDisplay()
{
    updateTime = new QTimer;
    updateTime->start(1000);
    connect(updateTime, SIGNAL(timeout()),
            this, SLOT(updateDisplay()));
}

int MainWindow::getBatteryLevel()
{
    QProcess * cmdProcess = new QProcess;
    cmdProcess->start("WMIC PATH Win32_Battery Get EstimatedChargeRemaining");
    cmdProcess->waitForFinished(-1); // will wait forever until finished

    QString out = cmdProcess->readAllStandardOutput();
    QString err = cmdProcess->readAllStandardError();
//    for(int i = 0; i < out.length(); i++){//test the string of output
//        qDebug() << i << out[i] << endl;
//    }
//    qDebug() << out[29] << out[30] << endl;
    if(err != ""){
        qDebug() << "err:" << err << endl;
    }
    int batteryLevel = (out[29].unicode()-48)*10 + (out[30].unicode()-48);
//    qDebug() << batteryLevel << endl;
    return batteryLevel;
}

QString MainWindow::getBatteryStatus()
{
    QProcess * cmdProcess = new QProcess;
    cmdProcess->start("WMIC Path Win32_Battery Get BatteryStatus");
    cmdProcess->waitForFinished(-1); // will wait forever until finished

    QString out = cmdProcess->readAllStandardOutput();
    QString err = cmdProcess->readAllStandardError();
//    for(int i = 0; i < out.length(); i++){//test the string of output
//        qDebug() << i << out[i] << endl;
//    }
//    qDebug() << out[18] << endl;
    if(err != ""){
        qDebug() << "err:" <<err << endl;
    }
    switch (out[18].unicode()-48) {
    case 1:
        return "Battery using";
    case 2:
        return "AC charging";
    default:
        return "Error!!";
    }
}

void MainWindow::displayBatteryThings(int batteryLevel, QString batteryStatus)
{
    ui->progressBar->setValue(batteryLevel);
    ui->label_batteryLevel->setText(QString::number(batteryLevel) + "%");
    ui->label_batteryLevel_2->setText(QString::number(batteryLevel) + "%");
    ui->label_batteryLevel_2->raise();
    if(batteryLevel >= 55){
        ui->label_batteryLevel_2->setStyleSheet("color: rgb(255, 255, 255)");
    }
    ui->label_batteryStatus->setText(batteryStatus);
}

void MainWindow::displaySchedule()
{
//    ui->tableView->setHorizontalHeader();
}

void MainWindow::on_actionQuit_triggered()
{
    this->close();
}

void MainWindow::on_actionMinimize_triggered()
{
    tray->setVisible(true);
    this->hide();
    tray->showMessage(tr("Info"),tr("Minimize to system tray!")); 
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case (QSystemTrayIcon::DoubleClick):
        this->show();
        tray->setVisible(false);
        break;
//    case (QSystemTrayIcon::Trigger):
//        tray->showMessage(tr("Info"),tr("Minimize to system tray!"));
    default:
        break;
    }
}

void MainWindow::updateDisplay()
{
    displayBatteryThings(getBatteryLevel(),getBatteryStatus());
}
