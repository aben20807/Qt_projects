#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initMenu();
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
    tray = new QSystemTrayIcon(this);
    tray->setIcon(QIcon(":/img/flag_taiwan"));
    tray->setVisible(true);
    this->hide();
    tray->showMessage(tr("Info"),tr("Minimize to system tray!"));

    QAction *restoreAction;
    restoreAction = new QAction(QIcon(":/img/flag_taiwan"), "Restore", this);
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(show()));

    QMenu *trayIconMenu;
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(restoreAction);
    tray->setContextMenu(trayIconMenu);
//    if(tray->ActivationReason == QSystemTrayIcon::DoubleClick){
//        this->show();
//    }

}
