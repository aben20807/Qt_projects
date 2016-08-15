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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
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
    QPushButton *pushButton;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(346, 272);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(110, 175, 75, 31));
        QFont font;
        font.setFamily(QStringLiteral("Noto Sans T Chinese Medium"));
        font.setPointSize(12);
        pushButton->setFont(font);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setAutoDefault(false);
        pushButton->setFlat(false);
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(111, 130, 170, 27));
        QFont font1;
        font1.setFamily(QStringLiteral("Noto Sans T Chinese Medium"));
        font1.setPointSize(11);
        lineEdit_2->setFont(font1);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 131, 61));
        QFont font2;
        font2.setFamily(QStringLiteral("Noto Sans T Chinese Thin"));
        font2.setPointSize(32);
        font2.setBold(false);
        font2.setWeight(50);
        label->setFont(font2);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(111, 89, 170, 27));
        lineEdit->setFont(font1);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(204, 183, 16, 18));
        QFont font3;
        font3.setFamily(QStringLiteral("Noto Sans T Chinese Regular"));
        font3.setPointSize(10);
        label_2->setFont(font3);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setEnabled(true);
        pushButton_2->setGeometry(QRect(221, 176, 61, 27));
        QFont font4;
        font4.setFamily(QStringLiteral("Noto Sans T Chinese Bold"));
        font4.setPointSize(10);
        font4.setKerning(false);
        pushButton_2->setFont(font4);
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QStringLiteral("color: rgb(0, 85, 255);"));
        pushButton_2->setCheckable(false);
        pushButton_2->setAutoDefault(false);
        pushButton_2->setFlat(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 346, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        pushButton_2->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("MainWindow", "sign in", 0));
        lineEdit_2->setPlaceholderText(QApplication::translate("MainWindow", "password", 0));
        label->setText(QApplication::translate("MainWindow", "Sign in", 0));
        lineEdit->setPlaceholderText(QApplication::translate("MainWindow", "user name", 0));
        label_2->setText(QApplication::translate("MainWindow", "or", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "sign up", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
