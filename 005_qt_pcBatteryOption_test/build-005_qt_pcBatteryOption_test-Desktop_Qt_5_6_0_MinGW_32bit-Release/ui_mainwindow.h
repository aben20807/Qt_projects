/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionMinimize;
    QAction *action_enUS;
    QAction *action_zhTW;
    QAction *actionManage;
    QAction *actionCheck_log;
    QAction *actionQuit;
    QAction *actionSystem_tray;
    QAction *actionTaskbar;
    QAction *actionError_report;
    QAction *actionAbout;
    QAction *actionAction_explaintion;
    QAction *actionAbout_Actions;
    QAction *actionReference_or_Resource;
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QTableView *tableView;
    QLabel *label_status;
    QLabel *label_batteryStatus;
    QLabel *label_batteryLevel_2;
    QLabel *label_level;
    QLabel *label_batteryLevel;
    QProgressBar *progressBar;
    QLabel *label_connectStatus;
    QMenuBar *menuBar;
    QMenu *menuWindow;
    QMenu *menuSetting;
    QMenu *submenuLanguage;
    QMenu *menuMinimize_to_2;
    QMenu *menuHelp;
    QMenu *menuSchedule;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(460, 305);
        actionMinimize = new QAction(MainWindow);
        actionMinimize->setObjectName(QStringLiteral("actionMinimize"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        font.setPointSize(10);
        actionMinimize->setFont(font);
        action_enUS = new QAction(MainWindow);
        action_enUS->setObjectName(QStringLiteral("action_enUS"));
        action_enUS->setChecked(false);
        action_enUS->setFont(font);
        action_enUS->setAutoRepeat(true);
        action_zhTW = new QAction(MainWindow);
        action_zhTW->setObjectName(QStringLiteral("action_zhTW"));
        action_zhTW->setFont(font);
        action_zhTW->setAutoRepeat(true);
        actionManage = new QAction(MainWindow);
        actionManage->setObjectName(QStringLiteral("actionManage"));
        actionManage->setFont(font);
        actionCheck_log = new QAction(MainWindow);
        actionCheck_log->setObjectName(QStringLiteral("actionCheck_log"));
        actionCheck_log->setFont(font);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionSystem_tray = new QAction(MainWindow);
        actionSystem_tray->setObjectName(QStringLiteral("actionSystem_tray"));
        actionTaskbar = new QAction(MainWindow);
        actionTaskbar->setObjectName(QStringLiteral("actionTaskbar"));
        actionError_report = new QAction(MainWindow);
        actionError_report->setObjectName(QStringLiteral("actionError_report"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAction_explaintion = new QAction(MainWindow);
        actionAction_explaintion->setObjectName(QStringLiteral("actionAction_explaintion"));
        actionAbout_Actions = new QAction(MainWindow);
        actionAbout_Actions->setObjectName(QStringLiteral("actionAbout_Actions"));
        actionReference_or_Resource = new QAction(MainWindow);
        actionReference_or_Resource->setObjectName(QStringLiteral("actionReference_or_Resource"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 441, 261));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(150, 80, 271, 171));
        tableView->setLayoutDirection(Qt::LeftToRight);
        tableView->setStyleSheet(QStringLiteral(""));
        tableView->setLineWidth(1);
        tableView->setTextElideMode(Qt::ElideLeft);
        label_status = new QLabel(centralWidget);
        label_status->setObjectName(QStringLiteral("label_status"));
        label_status->setGeometry(QRect(150, 50, 51, 21));
        label_status->setMinimumSize(QSize(51, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        font1.setPointSize(12);
        label_status->setFont(font1);
        label_status->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_batteryStatus = new QLabel(centralWidget);
        label_batteryStatus->setObjectName(QStringLiteral("label_batteryStatus"));
        label_batteryStatus->setGeometry(QRect(210, 50, 131, 21));
        label_batteryStatus->setMinimumSize(QSize(51, 21));
        label_batteryStatus->setFont(font1);
        label_batteryStatus->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_batteryLevel_2 = new QLabel(centralWidget);
        label_batteryLevel_2->setObjectName(QStringLiteral("label_batteryLevel_2"));
        label_batteryLevel_2->setGeometry(QRect(40, 130, 79, 21));
        label_batteryLevel_2->setMinimumSize(QSize(51, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        font2.setPointSize(14);
        label_batteryLevel_2->setFont(font2);
        label_batteryLevel_2->setStyleSheet(QStringLiteral(""));
        label_batteryLevel_2->setAlignment(Qt::AlignCenter);
        label_level = new QLabel(centralWidget);
        label_level->setObjectName(QStringLiteral("label_level"));
        label_level->setGeometry(QRect(150, 30, 51, 21));
        label_level->setMinimumSize(QSize(51, 21));
        label_level->setFont(font1);
        label_level->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_batteryLevel = new QLabel(centralWidget);
        label_batteryLevel->setObjectName(QStringLiteral("label_batteryLevel"));
        label_batteryLevel->setGeometry(QRect(210, 30, 121, 21));
        label_batteryLevel->setMinimumSize(QSize(51, 20));
        label_batteryLevel->setFont(font1);
        label_batteryLevel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(40, 38, 79, 211));
        progressBar->setMinimumSize(QSize(79, 171));
        QFont font3;
        font3.setFamily(QStringLiteral("Adobe Arabic"));
        progressBar->setFont(font3);
        progressBar->setLayoutDirection(Qt::LeftToRight);
        progressBar->setStyleSheet(QLatin1String("QProgressBar {\n"
"border: 1px solid black;\n"
"text-align: top;\n"
"padding: 1px;\n"
"border-top-right-radius: 7px;\n"
"border-top-left-radius: 7px;\n"
"border-bottom-right-radius: 7px;\n"
"border-bottom-left-radius: 7px;\n"
"background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,\n"
"stop: 0 #fff,\n"
"stop: 0.4999 #eee,\n"
"stop: 0.5 #ddd,\n"
"stop: 1 #eee );\n"
"width: 15px;\n"
"}\n"
"QProgressBar::chunk {\n"
"background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,\n"
"stop: 0 #78d,\n"
"stop: 0.4999 #46a,\n"
"stop: 0.5 #45a,\n"
"stop: 1 #238 );\n"
"border-bottom-right-radius: 7px;\n"
"border-bottom-left-radius: 7px;\n"
"border: 1px solid black;\n"
"}\n"
"\n"
""));
        progressBar->setValue(44);
        progressBar->setAlignment(Qt::AlignCenter);
        progressBar->setTextVisible(false);
        progressBar->setOrientation(Qt::Vertical);
        progressBar->setInvertedAppearance(false);
        progressBar->setTextDirection(QProgressBar::TopToBottom);
        label_connectStatus = new QLabel(centralWidget);
        label_connectStatus->setObjectName(QStringLiteral("label_connectStatus"));
        label_connectStatus->setGeometry(QRect(310, 10, 131, 21));
        label_connectStatus->setMinimumSize(QSize(51, 21));
        label_connectStatus->setFont(font);
        label_connectStatus->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        MainWindow->setCentralWidget(centralWidget);
        graphicsView->raise();
        tableView->raise();
        label_status->raise();
        label_batteryStatus->raise();
        label_level->raise();
        label_batteryLevel->raise();
        progressBar->raise();
        label_connectStatus->raise();
        label_batteryLevel_2->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 460, 23));
        menuBar->setFont(font);
        menuBar->setDefaultUp(false);
        menuBar->setNativeMenuBar(true);
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName(QStringLiteral("menuWindow"));
        menuWindow->setFont(font);
        menuSetting = new QMenu(menuBar);
        menuSetting->setObjectName(QStringLiteral("menuSetting"));
        menuSetting->setFont(font);
        submenuLanguage = new QMenu(menuSetting);
        submenuLanguage->setObjectName(QStringLiteral("submenuLanguage"));
        submenuLanguage->setFont(font);
        submenuLanguage->setSeparatorsCollapsible(false);
        menuMinimize_to_2 = new QMenu(menuSetting);
        menuMinimize_to_2->setObjectName(QStringLiteral("menuMinimize_to_2"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuHelp->setFont(font);
        menuSchedule = new QMenu(menuBar);
        menuSchedule->setObjectName(QStringLiteral("menuSchedule"));
        QFont font4;
        font4.setPointSize(10);
        menuSchedule->setFont(font4);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSchedule->menuAction());
        menuBar->addAction(menuWindow->menuAction());
        menuBar->addAction(menuSetting->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuWindow->addAction(actionMinimize);
        menuSetting->addAction(submenuLanguage->menuAction());
        menuSetting->addAction(menuMinimize_to_2->menuAction());
        submenuLanguage->addAction(action_zhTW);
        submenuLanguage->addAction(action_enUS);
        menuMinimize_to_2->addAction(actionSystem_tray);
        menuMinimize_to_2->addAction(actionTaskbar);
        menuHelp->addAction(actionAbout_Actions);
        menuHelp->addAction(actionAction_explaintion);
        menuHelp->addSeparator();
        menuHelp->addAction(actionReference_or_Resource);
        menuHelp->addAction(actionError_report);
        menuHelp->addAction(actionAbout);
        menuSchedule->addAction(actionManage);
        menuSchedule->addAction(actionCheck_log);
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Betterreminder", 0));
#ifndef QT_NO_TOOLTIP
        MainWindow->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        actionMinimize->setText(QApplication::translate("MainWindow", "Minimize To System Tray", 0));
        action_enUS->setText(QApplication::translate("MainWindow", "English_US", 0));
        action_zhTW->setText(QApplication::translate("MainWindow", "\347\271\201\351\253\224\344\270\255\346\226\207", 0));
        actionManage->setText(QApplication::translate("MainWindow", "Manage", 0));
        actionManage->setShortcut(QApplication::translate("MainWindow", "Ctrl+M", 0));
        actionCheck_log->setText(QApplication::translate("MainWindow", "Check Log", 0));
        actionCheck_log->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        actionSystem_tray->setText(QApplication::translate("MainWindow", "System tray", 0));
        actionTaskbar->setText(QApplication::translate("MainWindow", "Taskbar", 0));
        actionError_report->setText(QApplication::translate("MainWindow", "Error Report", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About Betterreminder", 0));
        actionAction_explaintion->setText(QApplication::translate("MainWindow", "Action Explanation", 0));
        actionAbout_Actions->setText(QApplication::translate("MainWindow", "About Actions", 0));
        actionReference_or_Resource->setText(QApplication::translate("MainWindow", "Reference or Resource", 0));
#ifndef QT_NO_TOOLTIP
        tableView->setToolTip(QApplication::translate("MainWindow", "Schedule", 0));
#endif // QT_NO_TOOLTIP
        label_status->setText(QApplication::translate("MainWindow", "Status:", 0));
        label_batteryStatus->setText(QApplication::translate("MainWindow", "[+]batteryStatus", 0));
        label_batteryLevel_2->setText(QApplication::translate("MainWindow", "%", 0));
        label_level->setText(QApplication::translate("MainWindow", "Level:", 0));
        label_batteryLevel->setText(QApplication::translate("MainWindow", "[+]batteryLevel", 0));
#ifndef QT_NO_TOOLTIP
        progressBar->setToolTip(QApplication::translate("MainWindow", "Battery level", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label_connectStatus->setToolTip(QApplication::translate("MainWindow", "The connection status to database", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_connectStatus->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_connectStatus->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label_connectStatus->setText(QApplication::translate("MainWindow", "[+]connectStatus", 0));
        menuWindow->setTitle(QApplication::translate("MainWindow", "Window", 0));
        menuSetting->setTitle(QApplication::translate("MainWindow", "Setting", 0));
        submenuLanguage->setTitle(QApplication::translate("MainWindow", "Language", 0));
        menuMinimize_to_2->setTitle(QApplication::translate("MainWindow", "Minimize To", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
        menuSchedule->setTitle(QApplication::translate("MainWindow", "Schedule", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
