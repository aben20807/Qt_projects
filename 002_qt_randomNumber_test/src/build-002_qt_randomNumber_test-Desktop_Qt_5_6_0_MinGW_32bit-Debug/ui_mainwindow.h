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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btn_create;
    QLabel *l_num;
    QLabel *l_result;
    QLineEdit *lEdit_num;
    QLabel *result_print;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *l_from;
    QLineEdit *lEdit_from;
    QLabel *l_to;
    QLineEdit *lEdit_to;
    QMenuBar *menuBar;
    QMenu *menuCreate;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(455, 307);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btn_create = new QPushButton(centralWidget);
        btn_create->setObjectName(QStringLiteral("btn_create"));
        btn_create->setGeometry(QRect(360, 50, 75, 34));
        QFont font;
        font.setFamily(QStringLiteral("Noto Sans T Chinese Regular"));
        font.setPointSize(14);
        btn_create->setFont(font);
        l_num = new QLabel(centralWidget);
        l_num->setObjectName(QStringLiteral("l_num"));
        l_num->setGeometry(QRect(11, 53, 105, 26));
        l_num->setFont(font);
        l_result = new QLabel(centralWidget);
        l_result->setObjectName(QStringLiteral("l_result"));
        l_result->setGeometry(QRect(10, 90, 70, 26));
        l_result->setFont(font);
        lEdit_num = new QLineEdit(centralWidget);
        lEdit_num->setObjectName(QStringLiteral("lEdit_num"));
        lEdit_num->setGeometry(QRect(123, 53, 111, 28));
        QFont font1;
        font1.setFamily(QStringLiteral("Noto Sans T Chinese Regular"));
        font1.setPointSize(12);
        lEdit_num->setFont(font1);
        lEdit_num->setAlignment(Qt::AlignCenter);
        result_print = new QLabel(centralWidget);
        result_print->setObjectName(QStringLiteral("result_print"));
        result_print->setGeometry(QRect(10, 120, 431, 121));
        result_print->setFont(font);
        result_print->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        result_print->setWordWrap(true);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(11, 11, 426, 30));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        l_from = new QLabel(widget);
        l_from->setObjectName(QStringLiteral("l_from"));
        l_from->setFont(font);

        horizontalLayout->addWidget(l_from);

        lEdit_from = new QLineEdit(widget);
        lEdit_from->setObjectName(QStringLiteral("lEdit_from"));
        lEdit_from->setFont(font1);
        lEdit_from->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lEdit_from);

        l_to = new QLabel(widget);
        l_to->setObjectName(QStringLiteral("l_to"));
        l_to->setFont(font);

        horizontalLayout->addWidget(l_to);

        lEdit_to = new QLineEdit(widget);
        lEdit_to->setObjectName(QStringLiteral("lEdit_to"));
        lEdit_to->setFont(font1);
        lEdit_to->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lEdit_to);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 455, 25));
        menuCreate = new QMenu(menuBar);
        menuCreate->setObjectName(QStringLiteral("menuCreate"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuCreate->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        btn_create->setText(QApplication::translate("MainWindow", "create", 0));
        l_num->setText(QApplication::translate("MainWindow", "How many?", 0));
        l_result->setText(QApplication::translate("MainWindow", "result\357\274\232", 0));
        lEdit_num->setText(QApplication::translate("MainWindow", "1", 0));
        result_print->setText(QString());
        l_from->setText(QApplication::translate("MainWindow", "From", 0));
        l_to->setText(QApplication::translate("MainWindow", "to", 0));
        menuCreate->setTitle(QApplication::translate("MainWindow", "create random numbers", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
