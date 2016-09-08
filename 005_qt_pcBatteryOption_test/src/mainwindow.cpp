#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/img/icon.ico"));

    /*set not to change the size of window*/
    Qt::WindowFlags flags = 0;
    flags |= Qt::WindowMinimizeButtonHint;
    flags |= Qt::WindowCloseButtonHint;
    setWindowFlags(flags);//Maximize ban
    setFixedSize(QWidget::geometry().width(), QWidget::geometry().height());//Prohibition on changing the window size

    /*init*/
    battery = new Battery(this);
    cmdprocess = new CmdProcess(this);
    translator =  new  QTranslator(qApp);
    initMenu();
    loadSettingIni();
    updateTime = new QTimer(this);//the period of update battery level and status
    updateTime->start(1000);
    initSystemTrayIcon();
    initBatteryDisplay();
    initTableDisplay();
    initActionToDo();
    QFile _file("./res/log/log.txt");//Create log file at first
    if(!_file.open(QFile::Append | QFile::Text)){
        QMessageBox::warning(this, tr("Error"), tr("Failed to create log file!"));
        //qDebug() << "Failed to open log to write";
    }
    _file.flush();
    _file.close();

    /*database connect*/
    if(!connectOpen()){
        ui->label_connectStatus->setText(tr("Failed to connect db!"));
    }
    else{
        //ui->label_connectStatus->setText(tr("Connected!"));
        ui->label_connectStatus->setText(tr(""));
    }
}
MainWindow::~MainWindow()
{
    //qDebug() << "Main dtor";
    delete battery;
    delete cmdprocess;
    delete updateTime;
    for(int i = 0; i < 5; i++){
        delete detectTime[i];
    }
    delete translator;
    delete tray;
    delete trayIconMenu;
    delete restoreAction;
    delete signalMapper;
    delete model;
    saveSettingIni(minimizeMode, languageMode);
    delete ui;
}

void MainWindow::loadSettingIni()
{
    QString path = QApplication::applicationDirPath();
    path += "./res/ini/setting.ini";
    QSettings setting(path,QSettings::IniFormat);
    setting.beginGroup("MainWindow");
    /*init mode from .ini*/
    minimizeMode = setting.value("languageMode", "Taskbar").toString();
    languageMode = setting.value("minimizeMode", "enUS").toString();
    setting.endGroup();
    applyLanguage();
    applyMinimize();
}

void MainWindow::saveSettingIni(QString const _languageMode, QString const _minimizeMode) const
{
    QString path = QApplication::applicationDirPath();
    path += "./res/ini/setting.ini";
    QSettings setting(path,QSettings::IniFormat);
    setting.beginGroup("MainWindow");
    setting.setValue("minimizeMode", _minimizeMode);
    setting.setValue("languageMode", _languageMode);
    setting.endGroup();
}

void inline MainWindow::initMenu() const
{
    ui->action_zhTW->setIcon(QIcon(":/img/flag_taiwan"));
    ui->action_enUS->setIcon(QIcon(":/img/flag_usa"));
    ui->action_zhTW->setCheckable(true);
    ui->action_enUS->setCheckable(true);
    ui->actionSystem_tray->setCheckable(true);
    ui->actionTaskbar->setCheckable(true);
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

void inline MainWindow::applyLanguage()
{
    if(languageMode == "zhTW"){
        //qDebug() << "change to 繁體中文" << endl;
        translator->load(QString("./res/language/zh_TW"));

//        ui->retranslateUi(this);
        ui->action_zhTW->setChecked(true);
        ui->action_enUS->setChecked(false);
    }
    else if(languageMode == "enUS"){
        //qDebug() << "change to English" << endl;
        translator->load(QString("./res/language/en_US"));
//        ui->retranslateUi(this);
        ui->action_enUS->setChecked(true);
        ui->action_zhTW->setChecked(false);
    }
    qApp->installTranslator(translator);
    ui->retranslateUi(this);

    /*database connect*/
    if(!connectOpen()){
        ui->label_connectStatus->setText(tr("Failed to connect db!"));
    }
    else{
        //ui->label_connectStatus->setText(tr("Connected!"));
        ui->label_connectStatus->setText(tr(""));
    }
}

void MainWindow::on_actionSystem_tray_triggered()
{
    if(minimizeMode != "System_tray"){
        minimizeMode = "System_tray";
        applyMinimize();
    }
}

void MainWindow::on_actionTaskbar_triggered()
{
    if(minimizeMode != "Taskbar"){
        minimizeMode = "Taskbar";
        applyMinimize();
    }
}

void MainWindow::applyMinimize() const
{
    if(minimizeMode == "Taskbar"){
        //qDebug() << "change to Taskbar" << endl;
        ui->actionTaskbar->setChecked(true);
        ui->actionSystem_tray->setChecked(false);
    }
    else if(minimizeMode == "System_tray"){
        //qDebug() << "change to System_tray" << endl;
        ui->actionSystem_tray->setChecked(true);
        ui->actionTaskbar->setChecked(false);
    }
}

void inline MainWindow::initSystemTrayIcon()
{
    tray = new QSystemTrayIcon(this);
    updateSystemTrayIconDisplay();
    connect(tray,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));

    restoreAction = new QAction(QIcon(":/img/restore"), "Restore", this);
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(show()));
    connect(restoreAction, SIGNAL(triggered()), tray, SLOT(hide()));

    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(restoreAction);
    trayIconMenu->addAction(ui->actionQuit);//quit action from ui
    tray->setContextMenu(trayIconMenu);
    connect(updateTime, SIGNAL(timeout()),
            this, SLOT(updateSystemTrayIconDisplay()));//Update icon every second
}

void MainWindow::updateSystemTrayIconDisplay()
{
    QPixmap pixmap(32, 32);//icon size
    if(battery->getBatteryStatus() == "AC charging"){//icon backround
        pixmap.fill(QColor("#0077aa"));//blue
    }
    else if(battery->getBatteryLevel() < 30){
        pixmap.fill(QColor("#e60012"));//red
    }
    else{
        pixmap.fill(QColor("#22af38"));//green
    }
    QPainter painter(&pixmap);
    QFont font = painter.font();

    if(battery->getBatteryLevel() == 100){
        font.setPointSize(14);
    }
    else{
        font.setPointSize(18);
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

void inline MainWindow::initBatteryDisplay() const
{
    updateBatteryDisplay();//init when begin
    connect(updateTime, SIGNAL(timeout()),
            this, SLOT(updateBatteryDisplay()));
}

void MainWindow::updateBatteryDisplay() const
{
    displayBatteryThings(battery->getBatteryLevel(),battery->getBatteryStatus());
}

void inline MainWindow::displayBatteryThings(int const batteryLevel, QString const batteryStatus) const
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
    if(languageMode == "enUS"){
        ui->label_batteryStatus->setText(batteryStatus);
    }
    else if(languageMode == "zhTW"){
        if(batteryStatus == "Battery using"){
            ui->label_batteryStatus->setText("電池使用中");
        }
        else if(batteryStatus == "AC charging"){
            ui->label_batteryStatus->setText("正在充電");
        }
    }

    if(battery->getBatteryStatus() == "AC charging"){//change color of progressBar
        ui->progressBar->setStyleSheet("QProgressBar {border: 1px solid black;text-align: top;"
                                       "padding: 1px;border-top-right-radius: 7px;border-top-left-radius: 7px;"
                                       "border-bottom-right-radius: 7px;border-bottom-left-radius: 7px;"
                                       "background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,"
                                       "stop: 0 #fff,stop: 0.4999 #eee,stop: 0.5 #ddd,stop: 1 #eee );"
                                       "width: 15px;}"
                                       "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,"
                                       "stop: 0 #78d,stop: 0.4999 #46a,stop: 0.5 #45a,stop: 1 #238 );"
                                       "border-bottom-right-radius: 7px;border-bottom-left-radius: 7px;border: 1px solid black;}"
                                       );
    }
    else if(battery->getBatteryLevel() < 30){
        ui->progressBar->setStyleSheet("QProgressBar {border: 1px solid black;text-align: top;"
                                       "padding: 1px;border-top-right-radius: 7px;border-top-left-radius: 7px;"
                                       "border-bottom-right-radius: 7px;border-bottom-left-radius: 7px;"
                                       "background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,"
                                       "stop: 0 #fff,stop: 0.4999 #eee,stop: 0.5 #ddd,stop: 1 #eee );"
                                       "width: 15px;}"
                                       "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,"
                                       "stop: 0 #f78,stop: 0.4999 #d46,stop: 0.5 #d45,stop: 1 #b23 );"
                                       "border-bottom-right-radius: 7px;border-bottom-left-radius: 7px;border: 1px solid black;}"
                                       );
    }
    else{
        ui->progressBar->setStyleSheet("QProgressBar {border: 1px solid black;text-align: top;"
                                       "padding: 1px;border-top-right-radius: 7px;border-top-left-radius: 7px;"
                                       "border-bottom-right-radius: 7px;border-bottom-left-radius: 7px;"
                                       "background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,"
                                       "stop: 0 #fff,stop: 0.4999 #eee,stop: 0.5 #ddd,stop: 1 #eee );"
                                       "width: 15px;}"
                                       "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,"
                                       "stop: 0 #7d8,stop: 0.4999 #4a6,stop: 0.5 #4a5,stop: 1 #283 );"
                                       "border-bottom-right-radius: 7px;border-bottom-left-radius: 7px;border: 1px solid black;}"
                                       );
    }
}

void inline MainWindow::initTableDisplay()
{
    updateTableDisplay();//init when begin
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->setColumnWidth(0, ui->tableView->width()/3);
    ui->tableView->setColumnWidth(1, ui->tableView->width()/4);
    ui->tableView->setColumnWidth(2, ui->tableView->width()/3);
}

void MainWindow::updateTableDisplay()
{
    model = new CustomSqlModel();
    connectOpen();
    QSqlQuery qry(actiondb);
    qry.prepare("select Condition,level,action from data");
    qry.exec();
    model->setQuery(qry);
    ui->tableView->setModel(model);
    connectClose();
    //qDebug() << model->rowCount();
}

void inline MainWindow::initActionToDo()
{
    for(int i = 0; i < 5; i++){
        detectTime[i] = new QTimer(this);
        detectTime[i]->start(1000);
        doOnce[i] = true;
    }
    signalMapper = new QSignalMapper(this);
    updateActionToDo();
}

void MainWindow::updateActionToDo()
{
    connectOpen();
    bool ok;
    QSqlQuery qry;
    for(int i = 1; i < 5; i++){//detect 4 action by for loop
        qry.prepare("select * from data where Number='"+QString::number(i)+"'");
        if(qry.exec()){
            while(qry.next()){
                if(qry.value(1).toString() != "Choose one" && (qry.value(2).toString() != "") && qry.value(3).toString() != "Nothing"){
                    //qDebug() << "Do action1";//for debug
                    _condition[i] = qry.value(1).toString();
                    _level[i] = qry.value(2).toString().toInt(&ok);
                    _action[i] = qry.value(3).toString();
                    //qDebug() << _condition[1] << _level[1] << _action[1];
                    detectTime[i]->start();
                    connect(detectTime[i], SIGNAL(timeout()), signalMapper, SLOT(map()));
                    signalMapper->setMapping(detectTime[i], i);
                    connect(signalMapper, SIGNAL(mapped(const int &)), this, SLOT(detectActionAndDo(const int &)));
                }
                else{
                    //qDebug() << "else";
                    detectTime[i]->stop();
                }
            }
        }
        else{
            QMessageBox::critical(this, tr("Error a::"), qry.lastError().text());
        }
    }
    connectClose();
}

void MainWindow::detectActionAndDo(int const &_numOfAction)
{
    //qDebug() << _numOfAction << doOnce[_numOfAction];
    int _nowLevel = battery->getBatteryLevel();
    if(_condition[_numOfAction] == "If level >"){
        if(_nowLevel >= _level[_numOfAction] && doOnce[_numOfAction] == true){
            doOnce[_numOfAction] = false;
            if(_action[_numOfAction] == "Remind"){
                writeLog("Remind When > " + QString::number(_level[_numOfAction]) + "%");
                cmdprocess->doAction("RemindMorethan", _level[_numOfAction], this);
                //qDebug() << "Do Remind";
            }
            else if(_action[_numOfAction] == "Shut down"){
                writeLog("Shutdown When > " + QString::number(_level[_numOfAction]) + "%");
                cmdprocess->doAction("Shutdown", _level[_numOfAction], this);
            }
            else if(_action[_numOfAction] == "Sleep"){
                writeLog("Sleep When > " + QString::number(_level[_numOfAction]) + "%");
                cmdprocess->doAction("Sleep", _level[_numOfAction], this);
            }
            else if(_action[_numOfAction] == "Hibernate"){
                writeLog("Hibernate When > " + QString::number(_level[_numOfAction]) + "%");
                cmdprocess->doAction("Hibernate", _level[_numOfAction], this);
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
                writeLog("Remind When < " + QString::number(_level[_numOfAction]) + "%");
                cmdprocess->doAction("RemindLessthan", _level[_numOfAction], this);
                //qDebug() << "Do Remind";
            }
            else if(_action[_numOfAction] == "Shut down"){
                writeLog("Shutdown When < " + QString::number(_level[_numOfAction]) + "%");
                cmdprocess->doAction("Shutdown", _level[_numOfAction], this);
            }
            else if(_action[_numOfAction] == "Sleep"){
                writeLog("Sleep When < " + QString::number(_level[_numOfAction]) + "%");
                cmdprocess->doAction("Sleep", _level[_numOfAction], this);
            }
            else if(_action[_numOfAction] == "Hibernate"){
                writeLog("Hibernate When < " + QString::number(_level[_numOfAction]) + "%");
                cmdprocess->doAction("Hibernate", _level[_numOfAction], this);
            }
        }
        else if(_nowLevel > _level[_numOfAction] && doOnce[_numOfAction] == false){
            doOnce[_numOfAction] = true;
        }
    }
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
//        if (event->type() == QEvent::LanguageChange)
//        {
//            // retranslate designer form (single inheritance approach)
//            ui->retranslateUi(this);
//        }
        QMainWindow::changeEvent(event);
    }
}

void MainWindow::show()//Overriding show()
{
    QWidget::show();
    this->setWindowState(Qt::WindowNoState);//set the window open in the screen
}

QString MainWindow::getLanguageMode() const
{
    return languageMode;
}

void MainWindow::on_actionQuit_triggered()
{
    /*Set program can be closed after qmessagebox when not hide in system tray*/
    qApp->setQuitOnLastWindowClosed(true);
    this->close();
}

void MainWindow::on_actionMinimize_triggered()
{
    /*Set program not to close after qmessagebox when hide in system tray*/
    qApp->setQuitOnLastWindowClosed(false);
    tray->setVisible(true);
    this->hide();
    //tray->showMessage(tr("Info"),tr("Minimize to system tray!"),
    //                      QSystemTrayIcon::Information, 5000);
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason const reason)
{
    switch (reason) {
    case (QSystemTrayIcon::DoubleClick):
        /*Set program can be closed after qmessagebox when not hide in system tray*/
        qApp->setQuitOnLastWindowClosed(true);
        this->show();
        tray->setVisible(false);
        break;
        //case (QSystemTrayIcon::Critical):
        //  tray->showMessage(tr("Barrery"), "level : "+(QString::number(battery->getBatteryLevel()))+"%",
        //      QSystemTrayIcon::Information, 5000);
        //  break;
    default:
        break;
    }
}

void MainWindow::writeLog(QString const actionRecord, QString const filename)
{
    QFile _file(filename);
    if(!_file.open(QFile::Append | QFile::Text)){
        QMessageBox::warning(this, tr("Error"), tr("Failed to open log to write!"));
        //qDebug() << "Failed to open log to write";
        return;
    }
    QTextStream out(&_file);
    QDateTime time = QDateTime::currentDateTime();//get time now
    QString str_time = time.toString("yyyy-MM-dd ddd hh:mm:ss"); //set the display format
    out << str_time << " - " << actionRecord << endl;
    _file.flush();
    _file.close();
}

QString MainWindow::readLog(QString const filename)
{
    QFile _file(filename);
    if(!_file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, tr("Error"), tr("Failed to open log to read!"));
        //qDebug() << "Failed to open log to read";
        return "";
    }
    QTextStream in(&_file);
    QString str_log = in.readAll();
    //qDebug() << str_log;
    //while(!in.atEnd())
    //{
        //QString line = in.readLine();
        //qDebug() << line;
    //}
    _file.close();
    return str_log;
}

void MainWindow::on_actionCheck_log_triggered()
{
    QString filename = "./res/log/log.txt";
    QString str_log = readLog(filename);

    connectClose();

    log = new Log(this, str_log);
    this->hide();
    QObject::connect(log,SIGNAL(close_me()),this,SLOT(close_child()));
    m_show_child = true;
    while (m_show_child)
    {
        log->exec();
    }
    delete log;
    this->show();
}

void MainWindow::on_actionError_report_triggered()
{
    QMessageBox errorReport;
    QFont font = errorReport.font();
    font.setPointSize(10);
    font.setFamily("Microsoft JhengHei");//微軟正黑體
    errorReport.setFont(font);
    errorReport.setWindowTitle(tr("Error Report"));
    errorReport.setText(tr("Let me know by following method\nGitHub : https://github.com/aben20807"));
    errorReport.setStandardButtons(QMessageBox::Ok);
    errorReport.show();
    errorReport.exec();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox about;
    QFont font = about.font();
    font.setPointSize(10);
    font.setFamily("Microsoft JhengHei");//微軟正黑體
    about.setFont(font);
    about.setWindowTitle(tr("About Betterreminder"));
    about.setIconPixmap(QPixmap(":/img/icon.png").scaled(48, 48));
    about.setText(tr("aben20807's Program\n"
                     "\nBetterreminder is for Better Battery Reminder\n"
                     "LICENSE : GPLv3\nI wrote this program for practicing. OuO"));
    about.setStandardButtons(QMessageBox::Ok);
    about.show();
    about.exec();
}

void MainWindow::on_actionAction_explaintion_triggered()
{
    QMessageBox explaintion;
    QFont font = explaintion.font();
    font.setPointSize(10);
    font.setFamily("Microsoft JhengHei");//微軟正黑體
    explaintion.setFont(font);
    explaintion.setWindowTitle(tr("Action Explaintion"));
    explaintion.setIconPixmap(QPixmap(":/img/explaintion"));
    explaintion.setStandardButtons(QMessageBox::Ok);
    explaintion.show();
    explaintion.exec();
}

void MainWindow::on_actionAbout_Actions_triggered()
{
    QMessageBox aboutActions;
    QFont font = aboutActions.font();
    font.setPointSize(10);
    font.setFamily("Microsoft JhengHei");//微軟正黑體
    aboutActions.setFont(font);
    aboutActions.setWindowTitle(tr("About Actions"));
    aboutActions.setText(tr("\nI will say strongly recommend you just to use \"Remind\" action\n"
                            "\"Help -> Action Explaintion\" are my experiences or data form website\n"
                            "Score : 5 -> Good, 1 -> Bad\n"));
    aboutActions.setStandardButtons(QMessageBox::Ok);
    aboutActions.show();
    aboutActions.exec();
}

void MainWindow::on_actionReference_or_Resource_triggered()
{
    QMessageBox referenceResource;
    QFont font = referenceResource.font();
    font.setPointSize(8);
    font.setFamily("Microsoft JhengHei");//微軟正黑體
    referenceResource.setFont(font);
    referenceResource.setWindowTitle(tr("Reference or Resource"));
    referenceResource.setText(tr("Action Explaintion : https://www.foolegg.com/what-are-the-differences-between-shut-down-standby-sleep-hibernate-and-hybrid-sleep/\n"
                                 "Language Icon : https://www.iconfinder.com/iconsets/142-mini-country-flags-16x16px\n"
                                 "Other Icon : material-design-icons-2.2.0 form https://design.google.com/icons/"));
    referenceResource.setStandardButtons(QMessageBox::Ok);
    referenceResource.show();
    referenceResource.exec();
}

void MainWindow::close_child()
{
    m_show_child = false;
}

void MainWindow::on_actionManage_triggered()
{
    connectClose();

    schedule = new Schedule(this);
    this->hide();
    QObject::connect(schedule,SIGNAL(close_me()),this,SLOT(close_child()));
    m_show_child = true;
    while (m_show_child)
    {
        schedule->exec();
    }
    updateTableDisplay();//update table when mainwindow reopen
    updateActionToDo();//update action when mainwindow reopen
    for(int i = 0; i < 5; i++){
        doOnce[i] = true;
    }
    delete schedule;
    this->show();
}

QVariant CustomSqlModel::data(const QModelIndex &item, int role) const
{
    if(!item.isValid())
        return QVariant();
    if (item.column() == 1) {
        if (role == Qt::TextAlignmentRole)
             return Qt::AlignCenter;
    }
    return QSqlQueryModel::data(item,role);
}
