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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btn_signIn;
    QLineEdit *lE_password;
    QLabel *label_logo;
    QLineEdit *lE_userName;
    QGraphicsView *graphicsView;
    QPushButton *btn_signUp;
    QPushButton *btn_forget;
    QLabel *label_status;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(430, 290);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btn_signIn = new QPushButton(centralWidget);
        btn_signIn->setObjectName(QStringLiteral("btn_signIn"));
        btn_signIn->setEnabled(true);
        btn_signIn->setGeometry(QRect(100, 190, 75, 31));
        QFont font;
        font.setFamily(QStringLiteral("Noto Sans T Chinese Medium"));
        font.setPointSize(12);
        btn_signIn->setFont(font);
        btn_signIn->setCursor(QCursor(Qt::PointingHandCursor));
        btn_signIn->setStyleSheet(QLatin1String("#btn_signIn {\n"
"background-color: transparent;\n"
"border-image: url(:img/btn_signIn);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}\n"
""));
        btn_signIn->setAutoDefault(false);
        btn_signIn->setFlat(false);
        lE_password = new QLineEdit(centralWidget);
        lE_password->setObjectName(QStringLiteral("lE_password"));
        lE_password->setGeometry(QRect(100, 138, 231, 27));
        QFont font1;
        font1.setFamily(QStringLiteral("Noto Sans T Chinese Medium"));
        font1.setPointSize(11);
        lE_password->setFont(font1);
        lE_password->setEchoMode(QLineEdit::Password);
        label_logo = new QLabel(centralWidget);
        label_logo->setObjectName(QStringLiteral("label_logo"));
        label_logo->setGeometry(QRect(20, 10, 131, 61));
        QFont font2;
        font2.setFamily(QStringLiteral("Noto Sans T Chinese Thin"));
        font2.setPointSize(32);
        font2.setBold(false);
        font2.setWeight(50);
        label_logo->setFont(font2);
        lE_userName = new QLineEdit(centralWidget);
        lE_userName->setObjectName(QStringLiteral("lE_userName"));
        lE_userName->setGeometry(QRect(100, 90, 231, 27));
        lE_userName->setFont(font1);
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 431, 291));
        graphicsView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        btn_signUp = new QPushButton(centralWidget);
        btn_signUp->setObjectName(QStringLiteral("btn_signUp"));
        btn_signUp->setEnabled(true);
        btn_signUp->setGeometry(QRect(330, 23, 75, 31));
        btn_signUp->setFont(font);
        btn_signUp->setCursor(QCursor(Qt::PointingHandCursor));
        btn_signUp->setStyleSheet(QLatin1String("#btn_signUp {\n"
"background-color: transparent;\n"
"border-image: url(:img/btn_signUp);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}\n"
""));
        btn_signUp->setAutoDefault(false);
        btn_signUp->setFlat(false);
        btn_forget = new QPushButton(centralWidget);
        btn_forget->setObjectName(QStringLiteral("btn_forget"));
        btn_forget->setGeometry(QRect(190, 200, 141, 20));
        QFont font3;
        font3.setFamily(QStringLiteral("Noto Sans T Chinese Medium"));
        font3.setPointSize(10);
        btn_forget->setFont(font3);
        btn_forget->setCursor(QCursor(Qt::PointingHandCursor));
        btn_forget->setStyleSheet(QLatin1String("#btn_forget {\n"
"	color: rgb(0, 117, 169);\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        label_status = new QLabel(centralWidget);
        label_status->setObjectName(QStringLiteral("label_status"));
        label_status->setGeometry(QRect(310, 250, 111, 41));
        QFont font4;
        font4.setFamily(QStringLiteral("Noto Sans T Chinese Medium"));
        font4.setPointSize(8);
        label_status->setFont(font4);
        label_status->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        MainWindow->setCentralWidget(centralWidget);
        graphicsView->raise();
        btn_signIn->raise();
        lE_password->raise();
        label_logo->raise();
        lE_userName->raise();
        btn_signUp->raise();
        btn_forget->raise();
        label_status->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 430, 25));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        btn_signIn->setText(QString());
        lE_password->setPlaceholderText(QApplication::translate("MainWindow", "password", 0));
        label_logo->setText(QApplication::translate("MainWindow", "Sign in", 0));
        lE_userName->setPlaceholderText(QApplication::translate("MainWindow", "user name", 0));
        btn_signUp->setText(QString());
        btn_forget->setText(QApplication::translate("MainWindow", "Forget your password?", 0));
        label_status->setText(QApplication::translate("MainWindow", "[+] Status", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
