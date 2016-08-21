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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QComboBox *comboBox_language;
    QLabel *label_action;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QSlider *hSlider_2;
    QLineEdit *lEdit_2;
    QLabel *label_persent_2;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *comboBox_action2;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QSlider *hSlider_3;
    QLineEdit *lEdit_3;
    QLabel *label_persent_3;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *comboBox_action3;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_6;
    QSlider *hSlider_4;
    QLineEdit *lEdit_4;
    QLabel *label_persent_4;
    QSpacerItem *horizontalSpacer_4;
    QComboBox *comboBox_action4;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_batteryStatus;
    QProgressBar *progressBar;
    QLabel *label_persent_status;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_3;
    QSlider *hSlider_1;
    QLineEdit *lEdit_1;
    QLabel *label_persent_1;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBox_action1;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(460, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 441, 281));
        comboBox_language = new QComboBox(centralWidget);
        comboBox_language->setObjectName(QStringLiteral("comboBox_language"));
        comboBox_language->setGeometry(QRect(350, 20, 91, 24));
        QFont font;
        font.setFamily(QStringLiteral("Noto Sans T Chinese Medium"));
        font.setPointSize(10);
        comboBox_language->setFont(font);
        label_action = new QLabel(centralWidget);
        label_action->setObjectName(QStringLiteral("label_action"));
        label_action->setGeometry(QRect(350, 60, 81, 20));
        label_action->setFont(font);
        label_action->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(120, 130, 311, 25));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        hSlider_2 = new QSlider(layoutWidget);
        hSlider_2->setObjectName(QStringLiteral("hSlider_2"));
        hSlider_2->setMinimumSize(QSize(121, 19));
        hSlider_2->setMaximumSize(QSize(121, 19));
        hSlider_2->setMaximum(100);
        hSlider_2->setSingleStep(1);
        hSlider_2->setValue(0);
        hSlider_2->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(hSlider_2, 0, Qt::AlignLeft);

        lEdit_2 = new QLineEdit(layoutWidget);
        lEdit_2->setObjectName(QStringLiteral("lEdit_2"));
        lEdit_2->setMinimumSize(QSize(51, 20));
        lEdit_2->setMaximumSize(QSize(51, 20));
        QFont font1;
        font1.setFamily(QStringLiteral("Noto Sans T Chinese Medium"));
        font1.setPointSize(12);
        lEdit_2->setFont(font1);
        lEdit_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(lEdit_2);

        label_persent_2 = new QLabel(layoutWidget);
        label_persent_2->setObjectName(QStringLiteral("label_persent_2"));
        label_persent_2->setMinimumSize(QSize(16, 20));
        label_persent_2->setMaximumSize(QSize(16, 20));
        label_persent_2->setFont(font);
        label_persent_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_persent_2, 0, Qt::AlignLeft);

        horizontalSpacer_2 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        comboBox_action2 = new QComboBox(layoutWidget);
        comboBox_action2->setObjectName(QStringLiteral("comboBox_action2"));
        comboBox_action2->setMinimumSize(QSize(81, 22));
        comboBox_action2->setMaximumSize(QSize(81, 22));
        comboBox_action2->setFont(font);

        horizontalLayout_4->addWidget(comboBox_action2);

        layoutWidget_2 = new QWidget(centralWidget);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(120, 180, 311, 25));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        hSlider_3 = new QSlider(layoutWidget_2);
        hSlider_3->setObjectName(QStringLiteral("hSlider_3"));
        hSlider_3->setMinimumSize(QSize(121, 19));
        hSlider_3->setMaximumSize(QSize(121, 19));
        hSlider_3->setMaximum(100);
        hSlider_3->setSingleStep(1);
        hSlider_3->setValue(0);
        hSlider_3->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(hSlider_3, 0, Qt::AlignLeft);

        lEdit_3 = new QLineEdit(layoutWidget_2);
        lEdit_3->setObjectName(QStringLiteral("lEdit_3"));
        lEdit_3->setMinimumSize(QSize(51, 20));
        lEdit_3->setMaximumSize(QSize(51, 20));
        lEdit_3->setFont(font1);
        lEdit_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(lEdit_3);

        label_persent_3 = new QLabel(layoutWidget_2);
        label_persent_3->setObjectName(QStringLiteral("label_persent_3"));
        label_persent_3->setMinimumSize(QSize(16, 20));
        label_persent_3->setMaximumSize(QSize(16, 20));
        label_persent_3->setFont(font);
        label_persent_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_persent_3, 0, Qt::AlignLeft);

        horizontalSpacer_3 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        comboBox_action3 = new QComboBox(layoutWidget_2);
        comboBox_action3->setObjectName(QStringLiteral("comboBox_action3"));
        comboBox_action3->setMinimumSize(QSize(81, 22));
        comboBox_action3->setMaximumSize(QSize(81, 22));
        comboBox_action3->setFont(font);

        horizontalLayout_5->addWidget(comboBox_action3);

        layoutWidget_3 = new QWidget(centralWidget);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(120, 230, 311, 25));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        hSlider_4 = new QSlider(layoutWidget_3);
        hSlider_4->setObjectName(QStringLiteral("hSlider_4"));
        hSlider_4->setMinimumSize(QSize(121, 19));
        hSlider_4->setMaximumSize(QSize(121, 19));
        hSlider_4->setMaximum(100);
        hSlider_4->setSingleStep(1);
        hSlider_4->setValue(0);
        hSlider_4->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(hSlider_4, 0, Qt::AlignLeft);

        lEdit_4 = new QLineEdit(layoutWidget_3);
        lEdit_4->setObjectName(QStringLiteral("lEdit_4"));
        lEdit_4->setMinimumSize(QSize(51, 20));
        lEdit_4->setMaximumSize(QSize(51, 20));
        lEdit_4->setFont(font1);
        lEdit_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(lEdit_4);

        label_persent_4 = new QLabel(layoutWidget_3);
        label_persent_4->setObjectName(QStringLiteral("label_persent_4"));
        label_persent_4->setMinimumSize(QSize(16, 20));
        label_persent_4->setMaximumSize(QSize(16, 20));
        label_persent_4->setFont(font);
        label_persent_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_persent_4, 0, Qt::AlignLeft);

        horizontalSpacer_4 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        comboBox_action4 = new QComboBox(layoutWidget_3);
        comboBox_action4->setObjectName(QStringLiteral("comboBox_action4"));
        comboBox_action4->setMinimumSize(QSize(81, 22));
        comboBox_action4->setMaximumSize(QSize(81, 22));
        comboBox_action4->setFont(font);

        horizontalLayout_6->addWidget(comboBox_action4);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 50, 53, 226));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_batteryStatus = new QLabel(widget);
        label_batteryStatus->setObjectName(QStringLiteral("label_batteryStatus"));
        label_batteryStatus->setMinimumSize(QSize(51, 21));
        label_batteryStatus->setMaximumSize(QSize(51, 21));
        label_batteryStatus->setFont(font1);
        label_batteryStatus->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_batteryStatus);

        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setMinimumSize(QSize(51, 171));
        progressBar->setMaximumSize(QSize(51, 171));
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

        label_persent_status = new QLabel(widget);
        label_persent_status->setObjectName(QStringLiteral("label_persent_status"));
        label_persent_status->setMinimumSize(QSize(51, 20));
        label_persent_status->setMaximumSize(QSize(51, 20));
        label_persent_status->setFont(font1);
        label_persent_status->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_persent_status);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(120, 80, 311, 25));
        horizontalLayout_3 = new QHBoxLayout(widget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        hSlider_1 = new QSlider(widget1);
        hSlider_1->setObjectName(QStringLiteral("hSlider_1"));
        hSlider_1->setMinimumSize(QSize(121, 19));
        hSlider_1->setMaximumSize(QSize(121, 19));
        hSlider_1->setMaximum(100);
        hSlider_1->setSingleStep(1);
        hSlider_1->setValue(0);
        hSlider_1->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(hSlider_1, 0, Qt::AlignLeft);

        lEdit_1 = new QLineEdit(widget1);
        lEdit_1->setObjectName(QStringLiteral("lEdit_1"));
        lEdit_1->setMinimumSize(QSize(51, 20));
        lEdit_1->setMaximumSize(QSize(51, 20));
        lEdit_1->setFont(font1);
        lEdit_1->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(lEdit_1);

        label_persent_1 = new QLabel(widget1);
        label_persent_1->setObjectName(QStringLiteral("label_persent_1"));
        label_persent_1->setMinimumSize(QSize(16, 20));
        label_persent_1->setMaximumSize(QSize(16, 20));
        label_persent_1->setFont(font);
        label_persent_1->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_persent_1, 0, Qt::AlignLeft);

        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        comboBox_action1 = new QComboBox(widget1);
        comboBox_action1->setObjectName(QStringLiteral("comboBox_action1"));
        comboBox_action1->setMinimumSize(QSize(81, 22));
        comboBox_action1->setMaximumSize(QSize(81, 22));
        comboBox_action1->setFont(font);

        horizontalLayout_3->addWidget(comboBox_action1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 460, 25));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        comboBox_language->clear();
        comboBox_language->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Language", 0)
         << QApplication::translate("MainWindow", "\347\271\201\351\253\224\344\270\255\346\226\207", 0)
         << QApplication::translate("MainWindow", "English", 0)
        );
        label_action->setText(QApplication::translate("MainWindow", "Action to do", 0));
        label_persent_2->setText(QApplication::translate("MainWindow", "%", 0));
        comboBox_action2->clear();
        comboBox_action2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Nothing", 0)
        );
        label_persent_3->setText(QApplication::translate("MainWindow", "%", 0));
        comboBox_action3->clear();
        comboBox_action3->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Nothing", 0)
        );
        label_persent_4->setText(QApplication::translate("MainWindow", "%", 0));
        comboBox_action4->clear();
        comboBox_action4->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Nothing", 0)
        );
        label_batteryStatus->setText(QApplication::translate("MainWindow", "Status", 0));
        label_persent_status->setText(QApplication::translate("MainWindow", "24%", 0));
        label_persent_1->setText(QApplication::translate("MainWindow", "%", 0));
        comboBox_action1->clear();
        comboBox_action1->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Nothing", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
