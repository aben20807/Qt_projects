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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionMinimize;
    QAction *action_enUS;
    QAction *action_zhTW;
    QAction *actionAdd_new;
    QAction *actionManage;
    QAction *actionCheck_log;
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_batteryStatus;
    QProgressBar *progressBar;
    QLabel *label_persent_status;
    QMenuBar *menuBar;
    QMenu *menuWindow;
    QMenu *menuSetting;
    QMenu *submenuLanguage;
    QMenu *menuHelp;
    QMenu *menuSchedule;

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
        action_enUS->setCheckable(true);
        action_enUS->setChecked(true);
        action_enUS->setFont(font);
        action_enUS->setAutoRepeat(true);
        action_zhTW = new QAction(MainWindow);
        action_zhTW->setObjectName(QStringLiteral("action_zhTW"));
        action_zhTW->setCheckable(true);
        action_zhTW->setFont(font);
        action_zhTW->setAutoRepeat(true);
        actionAdd_new = new QAction(MainWindow);
        actionAdd_new->setObjectName(QStringLiteral("actionAdd_new"));
        actionAdd_new->setFont(font);
        actionManage = new QAction(MainWindow);
        actionManage->setObjectName(QStringLiteral("actionManage"));
        actionManage->setFont(font);
        actionCheck_log = new QAction(MainWindow);
        actionCheck_log->setObjectName(QStringLiteral("actionCheck_log"));
        actionCheck_log->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 441, 261));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 40, 81, 226));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_batteryStatus = new QLabel(layoutWidget);
        label_batteryStatus->setObjectName(QStringLiteral("label_batteryStatus"));
        label_batteryStatus->setMinimumSize(QSize(51, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        font1.setPointSize(12);
        label_batteryStatus->setFont(font1);
        label_batteryStatus->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_batteryStatus);

        progressBar = new QProgressBar(layoutWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setMinimumSize(QSize(79, 171));
        QFont font2;
        font2.setFamily(QStringLiteral("Adobe Arabic"));
        progressBar->setFont(font2);
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
        progressBar->setValue(24);
        progressBar->setAlignment(Qt::AlignCenter);
        progressBar->setTextVisible(false);
        progressBar->setOrientation(Qt::Vertical);
        progressBar->setInvertedAppearance(false);
        progressBar->setTextDirection(QProgressBar::TopToBottom);

        verticalLayout->addWidget(progressBar);

        label_persent_status = new QLabel(layoutWidget);
        label_persent_status->setObjectName(QStringLiteral("label_persent_status"));
        label_persent_status->setMinimumSize(QSize(51, 20));
        label_persent_status->setFont(font1);
        label_persent_status->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_persent_status);

        MainWindow->setCentralWidget(centralWidget);
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
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuHelp->setFont(font);
        menuSchedule = new QMenu(menuBar);
        menuSchedule->setObjectName(QStringLiteral("menuSchedule"));
        QFont font3;
        font3.setPointSize(10);
        menuSchedule->setFont(font3);
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuSchedule->menuAction());
        menuBar->addAction(menuWindow->menuAction());
        menuBar->addAction(menuSetting->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuWindow->addAction(actionMinimize);
        menuSetting->addAction(submenuLanguage->menuAction());
        submenuLanguage->addAction(action_zhTW);
        submenuLanguage->addAction(action_enUS);
        menuSchedule->addAction(actionAdd_new);
        menuSchedule->addAction(actionManage);
        menuSchedule->addAction(actionCheck_log);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionMinimize->setText(QApplication::translate("MainWindow", "Minimize", 0));
        action_enUS->setText(QApplication::translate("MainWindow", "English", 0));
        action_zhTW->setText(QApplication::translate("MainWindow", "\347\271\201\351\253\224\344\270\255\346\226\207", 0));
        actionAdd_new->setText(QApplication::translate("MainWindow", "Add new", 0));
        actionAdd_new->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", 0));
        actionManage->setText(QApplication::translate("MainWindow", "Manage", 0));
        actionManage->setShortcut(QApplication::translate("MainWindow", "Ctrl+M", 0));
        actionCheck_log->setText(QApplication::translate("MainWindow", "Check log", 0));
        actionCheck_log->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0));
        label_batteryStatus->setText(QApplication::translate("MainWindow", "Status", 0));
        label_persent_status->setText(QApplication::translate("MainWindow", "24%", 0));
        menuWindow->setTitle(QApplication::translate("MainWindow", "Window", 0));
        menuSetting->setTitle(QApplication::translate("MainWindow", "Setting", 0));
        submenuLanguage->setTitle(QApplication::translate("MainWindow", "Language", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
        menuSchedule->setTitle(QApplication::translate("MainWindow", "Schedule", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
