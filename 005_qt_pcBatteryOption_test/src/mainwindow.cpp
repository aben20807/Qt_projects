#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Qt::WindowFlags flags = 0;
        flags |= Qt::WindowMinimizeButtonHint;
        flags |= Qt::WindowCloseButtonHint;
        setWindowFlags(flags);//Maximize ban
        setFixedSize(QWidget::geometry().width(), QWidget::geometry().height());//Prohibition on changing the window size

    battery = new Battery;
    initMenu();
    initSystemTrayIcon();
    updateTime = new QTimer;
    updateTime->start(1000);
    initBatteryDisplay();
    initTableDisplay();

    /*database connect*/
    if(!connectOpen()){
        ui->label_connectStatus->setText(tr("Failed to connect db!"));
    }
    else{
        ui->label_connectStatus->setText(tr("Connected!"));
    }
//    QProcess * cmdProcess = new QProcess;
//    cmdProcess->start("shutdown /h");
//    cmdProcess->waitForFinished(-1); // will wait forever until finished
//    QString out = cmdProcess->readAllStandardOutput();
//    qDebug() << "out:" << out << endl;
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
    ui->action_enUS->setChecked(true);

    ui->actionSystem_tray->setCheckable(true);
    ui->actionTaskbar->setCheckable(true);
    minimizeMode = "Taskbar";
    ui->actionTaskbar->setChecked(true);
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


    restoreAction = new QAction(QIcon(":/img/flag_taiwan"), "Restore", this);
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(show()));
    connect(restoreAction, SIGNAL(triggered()), tray, SLOT(hide()));
//    connect(restoreAction, SIGNAL(triggered()), this, SLOT(()));

    QMenu *trayIconMenu;//the menu of QSystemTrayIcon
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(restoreAction);
    trayIconMenu->addAction(ui->actionQuit);//quit action from ui
    tray->setContextMenu(trayIconMenu);

    tray->setToolTip(("Battery : " + QString::number(battery->getBatteryLevel())));//"<br>""level : "+battery->getBatteryLevel());
    /*TODO beautiful tooltip*/
}

void MainWindow::initBatteryDisplay()
{
    updateBatteryDisplay();//init when begin
    connect(updateTime, SIGNAL(timeout()),
            this, SLOT(updateBatteryDisplay()));
}

void MainWindow::updateBatteryDisplay()
{
    int _level = battery->getBatteryLevel();
    QString _status = battery->getBatteryStatus();
    displayBatteryThings(_level,_status);
}

void MainWindow::initTableDisplay()
{
    updateTableDisplay();//init when begin
//    Schedule schedule;
//    connect(&schedule, SIGNAL(updateTable()),
//            this, SLOT(updateTableDisplay()));
}

void MainWindow::updateTableDisplay()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    connectOpen();
    QSqlQuery *qry = new QSqlQuery(actiondb);
    qry->prepare("select Condition,level,action from data");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
    connectClose();
//    qDebug() << model->rowCount();
}

void MainWindow::displayBatteryThings(int batteryLevel, QString batteryStatus)
{
    ui->progressBar->setValue(batteryLevel);
    ui->label_batteryLevel->setText(QString::number(batteryLevel) + "%");
    ui->label_batteryLevel_2->setText(QString::number(batteryLevel) + "%");
    ui->label_batteryLevel_2->raise();
    if(batteryLevel >= 55){
        ui->label_batteryLevel_2->setStyleSheet("color: rgb(255, 255, 255)");//white
    }
    else{
        ui->label_batteryLevel_2->setStyleSheet("color: rgb(0, 0, 0)");//black
    }
    ui->label_batteryStatus->setText(batteryStatus);
    /*TODO when low battery, change color of progressBar*/
}

void MainWindow::changeEvent(QEvent *event)
{
    if( event->type() == QEvent::WindowStateChange )
    {
        if( windowState() == Qt::WindowMinimized && minimizeMode == "System_tray"){
            ui->actionMinimize->trigger();
        }
        else if( windowState() == Qt::WindowNoState ){
        }
        QMainWindow::changeEvent(event);
    }
}

void MainWindow::show()//Overriding show()
{
    QWidget::show();
    this->setWindowState(Qt::WindowNoState);
}

void MainWindow::displaySchedule()
{
    //number condition level action
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
    tray->showMessage(tr("Info"),tr("Minimize to system tray!"),
                      QSystemTrayIcon::Information, 5000);
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case (QSystemTrayIcon::DoubleClick):
        this->show();
        tray->setVisible(false);
        break;
    case (QSystemTrayIcon::Critical):
        tray->showMessage(tr("Barrery"), "level : "+(QString::number(battery->getBatteryLevel()))+"%",
                          QSystemTrayIcon::Information, 5000);
        break;
    default:
        break;
    }
}

void MainWindow::on_actionSystem_tray_triggered()
{
    if(minimizeMode != "System_tray"){
        minimizeMode = "System_tray";
        ui->actionSystem_tray->setChecked(true);
        ui->actionTaskbar->setChecked(false);
    }
}

void MainWindow::on_actionTaskbar_triggered()
{
    if(minimizeMode != "Taskbar"){
        minimizeMode = "Taskbar";
        ui->actionSystem_tray->setChecked(false);
        ui->actionTaskbar->setChecked(true);
    }
}

void MainWindow::close_child()//
{
    m_show_child = false;
}

void MainWindow::on_actionManage_triggered()//
{
    connectClose();

    Schedule schedule;
    this->hide();
    QObject::connect(&schedule,SIGNAL(close_me()),this,SLOT(close_child()));
    m_show_child = true;
    while (m_show_child)
    {
        schedule.exec();
    }
    updateTableDisplay();//init table when mainwindow reopen
    this->show();
}
