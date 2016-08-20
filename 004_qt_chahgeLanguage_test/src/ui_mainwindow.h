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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QComboBox *comboBox;
    QPushButton *btn_ok;
    QLabel *label_hello;
    QLabel *label_ouo;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 0, 381, 281));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(120, 10, 131, 30));
        QFont font;
        font.setFamily(QStringLiteral("Noto Sans T Chinese Medium"));
        font.setPointSize(12);
        comboBox->setFont(font);
        btn_ok = new QPushButton(centralWidget);
        btn_ok->setObjectName(QStringLiteral("btn_ok"));
        btn_ok->setGeometry(QRect(270, 10, 111, 30));
        btn_ok->setFont(font);
        label_hello = new QLabel(centralWidget);
        label_hello->setObjectName(QStringLiteral("label_hello"));
        label_hello->setGeometry(QRect(40, 100, 321, 131));
        QFont font1;
        font1.setFamily(QStringLiteral("Noto Sans T Chinese Regular"));
        font1.setPointSize(45);
        label_hello->setFont(font1);
        label_hello->setAlignment(Qt::AlignCenter);
        label_ouo = new QLabel(centralWidget);
        label_ouo->setObjectName(QStringLiteral("label_ouo"));
        label_ouo->setGeometry(QRect(20, 10, 81, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Noto Sans T Chinese Thin"));
        font2.setPointSize(30);
        label_ouo->setFont(font2);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\344\270\273\350\246\226\347\252\227", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\350\253\213\351\201\270\346\223\207\350\252\236\350\250\200", 0)
         << QApplication::translate("MainWindow", "\347\271\201\351\253\224\344\270\255\346\226\207", 0)
         << QApplication::translate("MainWindow", "English", 0)
         << QApplication::translate("MainWindow", "\346\227\245\346\234\254\350\252\236", 0)
        );
        btn_ok->setText(QApplication::translate("MainWindow", "\347\242\272\350\252\215", 0));
        label_hello->setText(QApplication::translate("MainWindow", "\344\275\240\345\245\275", 0));
        label_ouo->setText(QApplication::translate("MainWindow", "OuO", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
