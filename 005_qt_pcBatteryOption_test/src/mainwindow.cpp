#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*set not to change the size of window*/
    Qt::WindowFlags flags = 0;
    flags |= Qt::WindowMinimizeButtonHint;
    flags |= Qt::WindowCloseButtonHint;
    setWindowFlags(flags);//Maximize ban
    setFixedSize(QWidget::geometry().width(), QWidget::geometry().height());//Prohibition on changing the window size

    /*database connect*/
    if(!connectOpen()){
        ui->label_connectStatus->setText(tr("Failed to connect db!"));
    }
    else{
        ui->label_connectStatus->setText(tr("Connected!"));
    }

    /*init*/
    battery = new Battery;
    //    schedule = new Schedule;
    initMenu();
    updateTime = new QTimer;//the period of update battery level and status
    updateTime->start(1000);
    initSystemTrayIcon();
    initBatteryDisplay();
    initTableDisplay();
    initActionToDo();
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
    updateSystemTrayIconDisplay();
    connect(tray,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));

    /*TODO find restore icon*/
    restoreAction = new QAction(QIcon(":/img/flag_taiwan"), "Restore", this);
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(show()));
    connect(restoreAction, SIGNAL(triggered()), tray, SLOT(hide()));

    QMenu *trayIconMenu;//the menu of QSystemTrayIcon
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(restoreAction);
    trayIconMenu->addAction(ui->actionQuit);//quit action from ui
    tray->setContextMenu(trayIconMenu);
    connect(updateTime, SIGNAL(timeout()),
            this, SLOT(updateSystemTrayIconDisplay()));//Update icon every second
}

void MainWindow::updateSystemTrayIconDisplay()
{
    QPixmap pixmap(26,26);//icon size
    if(battery->getBatteryLevel() < 30){//icon backround
        pixmap.fill(QColor("#e60012"));//red
    }
    else if(battery->getBatteryStatus() == "Battery using"){
        pixmap.fill(QColor("#22ac38"));//green
    }
    else{
        pixmap.fill(QColor("#0075a9"));//blue
    }
    QPainter painter(&pixmap);
    QFont font = painter.font();
    if(battery->getBatteryLevel() == 100){
        font.setPointSize(12);
    }
    else{
        font.setPointSize(14);
    }
    font.setBold(true);
    font.setFamily("Microsoft JhengHei");//微軟正黑體
    painter.setFont(font);
    QPen penHText(QColor("#ffffff"));//white text
    painter.setPen(penHText);
    painter.drawText(pixmap.rect(),Qt::AlignCenter,QString::number(battery->getBatteryLevel()));
    //    qDebug() << QString::number(battery->getBatteryLevel());
    tray->setIcon((pixmap));
    tray->setToolTip(("Battery : " + QString::number(battery->getBatteryLevel())));
    /*TODO beautiful tooltip, add picture?*/
}

void MainWindow::initBatteryDisplay()
{
    updateBatteryDisplay();//init when begin
    connect(updateTime, SIGNAL(timeout()),
            this, SLOT(updateBatteryDisplay()));
}

void MainWindow::updateBatteryDisplay()
{
    displayBatteryThings(battery->getBatteryLevel(),battery->getBatteryStatus());
}

void MainWindow::initTableDisplay()
{
    updateTableDisplay();//init when begin
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->setColumnWidth(0, ui->tableView->width()/3);
    ui->tableView->setColumnWidth(1, ui->tableView->width()/4);
    ui->tableView->setColumnWidth(2, ui->tableView->width()/3);
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
    /*TODO center the text*/
}

void MainWindow::initActionToDo()
{
    for(int i = 0; i < 5; i++){
        doOnce[i] = true;
    }
    updateActionToDo();
}

void MainWindow::updateActionToDo()
{
    QSignalMapper *signalMapper = new QSignalMapper;
    connectOpen();
    bool ok;
    QSqlQuery qry;
    /*1*/
    qry.prepare("select * from data where Number=1");
    if(qry.exec()){
        while(qry.next()){
            if(qry.value(1).toString() != "Choose one" && (qry.value(2).toString() != "") && qry.value(3).toString() != "Nothing"){
                //qDebug() << s1 << s2 << s3 << "Do action1";//for debug
                _condition[1] = qry.value(1).toString();
                _level[1] = qry.value(2).toString().toInt(&ok);
                _action[1] = qry.value(3).toString();
                connect(updateTime, SIGNAL(timeout()), signalMapper, SLOT(map()));
                signalMapper->setMapping(updateTime, 1);
                connect(signalMapper, SIGNAL(mapped(const int &)), this, SLOT(detectActionAndDo(const int &)));
            }
        }
    }
    else{
        QMessageBox::critical(this, tr("Error a1::"), qry.lastError().text());
    }
    /*2*/
    qry.prepare("select * from data where Number=2");
    if(qry.exec()){
        while(qry.next()){
            if(qry.value(1).toString() != "Choose one" && (qry.value(2).toString() != "") && qry.value(3).toString() != "Nothing"){
                //qDebug() << "Do action2";
                _condition[2] = qry.value(1).toString();
                _level[2] = qry.value(2).toString().toInt(&ok);
                _action[2] = qry.value(3).toString();
                connect(updateTime, SIGNAL(timeout()), signalMapper, SLOT(map()));
                signalMapper->setMapping(updateTime, 2);
                connect(signalMapper, SIGNAL(mapped(const int &)), this, SLOT(detectActionAndDo(const int &)));
            }
        }
    }
    else{
        QMessageBox::critical(this, tr("Error a2::"), qry.lastError().text());
    }
    /*3*/
    qry.prepare("select * from data where Number=3");
    if(qry.exec()){
        while(qry.next()){
            if(qry.value(1).toString() != "Choose one" && (qry.value(2).toString() != "") && qry.value(3).toString() != "Nothing"){
                //qDebug() << "Do action3";
                _condition[3] = qry.value(1).toString();
                _level[3] = qry.value(2).toString().toInt(&ok);
                _action[3] = qry.value(3).toString();
                connect(updateTime, SIGNAL(timeout()), signalMapper, SLOT(map()));
                signalMapper->setMapping(updateTime, 3);
                connect(signalMapper, SIGNAL(mapped(const int &)), this, SLOT(detectActionAndDo(const int &)));
            }
        }
    }
    else{
        QMessageBox::critical(this, tr("Error a3::"), qry.lastError().text());
    }
    /*4*/
    qry.prepare("select * from data where Number=4");
    if(qry.exec()){
        while(qry.next()){
            if(qry.value(1).toString() != "Choose one" && (qry.value(2).toString() != "") && qry.value(3).toString() != "Nothing"){
                //qDebug() << "Do action4";
                _condition[4] = qry.value(1).toString();
                _level[4] = qry.value(2).toString().toInt(&ok);
                _action[4] = qry.value(3).toString();
                connect(updateTime, SIGNAL(timeout()), signalMapper, SLOT(map()));
                signalMapper->setMapping(updateTime, 4);
                connect(signalMapper, SIGNAL(mapped(const int &)), this, SLOT(detectActionAndDo(const int &)));
            }
        }
    }
    else{
        QMessageBox::critical(this, tr("Error a4::"), qry.lastError().text());
    }
}

void MainWindow::detectActionAndDo(const int &_numOfAction)
{
    int _nowLevel = battery->getBatteryLevel();
    if(_condition[_numOfAction] == "If level >"){
        if(_nowLevel >= _level[_numOfAction] && doOnce[_numOfAction] == true){
            doOnce[_numOfAction] = false;
            if(_action[_numOfAction] == "Remind"){
                cmdprocess->doAction("RemindMorethan", _level[_numOfAction]);
                //qDebug() << "Do Remind";
            }
            else if(_action[_numOfAction] == "Shut down"){
                cmdprocess->doAction("Shutdown", _level[_numOfAction]);
            }
            else if(_action[_numOfAction] == "Sleep"){
                cmdprocess->doAction("Sleep", _level[_numOfAction]);
            }
            else if(_action[_numOfAction] == "Hibernate"){
                cmdprocess->doAction("Hibernate", _level[_numOfAction]);
            }
        }
        else if(_nowLevel < _level[_numOfAction] && doOnce[_numOfAction] == false){
            doOnce[_numOfAction] = true;
        }
    }
    else if(_condition[_numOfAction] == "If level <"){
        if(_nowLevel <= _level[_numOfAction] && doOnce[_numOfAction] == true){
            doOnce[_numOfAction] = false;
            if(_action[_numOfAction] == "Remind"){
                cmdprocess->doAction("RemindLessthan", _level[_numOfAction]);
            }
            else if(_action[_numOfAction] == "Shut down"){
                cmdprocess->doAction("Shutdown", _level[_numOfAction]);
            }
            else if(_action[_numOfAction] == "Sleep"){
                cmdprocess->doAction("Sleep", _level[_numOfAction]);
            }
            else if(_action[_numOfAction] == "Hibernate"){
                cmdprocess->doAction("Hibernate", _level[_numOfAction]);
            }
        }
        else if(_nowLevel > _level[_numOfAction] && doOnce[_numOfAction] == false){
            doOnce[_numOfAction] = true;
        }
    }
    doOnce[_numOfAction] = false;
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
            ui->actionMinimize->trigger();//minimize to tray when ischecked
        }
        else if( windowState() == Qt::WindowNoState ){
        }
        QMainWindow::changeEvent(event);
    }
}

void MainWindow::show()//Overriding show()
{
    QWidget::show();
    this->setWindowState(Qt::WindowNoState);//set the window open in the screen
}

void MainWindow::on_actionQuit_triggered()
{
    this->close();
}

void MainWindow::on_actionMinimize_triggered()
{
    tray->setVisible(true);
    this->hide();
    //    tray->showMessage(tr("Info"),tr("Minimize to system tray!"),
    //                      QSystemTrayIcon::Information, 5000);
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case (QSystemTrayIcon::DoubleClick):
        this->show();
        tray->setVisible(false);
        break;
        //    case (QSystemTrayIcon::Critical):
        //        tray->showMessage(tr("Barrery"), "level : "+(QString::number(battery->getBatteryLevel()))+"%",
        //                          QSystemTrayIcon::Information, 5000);
        //        break;
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

void MainWindow::close_child()
{
    m_show_child = false;
}

void MainWindow::on_actionManage_triggered()
{
    connectClose();

    schedule = new Schedule;
    this->hide();
    QObject::connect(schedule,SIGNAL(close_me()),this,SLOT(close_child()));
    m_show_child = true;
    while (m_show_child)
    {
        schedule->exec();
    }
    updateTableDisplay();//update table when mainwindow reopen
    updateActionToDo();//update action when mainwindow reopen
    updateActionToDo();
    for(int i = 0; i < 5; i++){
        doOnce[i] = true;
    }
    this->show();
}
