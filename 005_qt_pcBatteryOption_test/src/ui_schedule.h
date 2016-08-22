/********************************************************************************
** Form generated from reading UI file 'schedule.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHEDULE_H
#define UI_SCHEDULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Schedule
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QSlider *hSlider_1;
    QLineEdit *lEdit_1;
    QLabel *label_persent_1;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBox_action1;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QSlider *hSlider_3;
    QLineEdit *lEdit_3;
    QLabel *label_persent_3;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *comboBox_action3;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QSlider *hSlider_2;
    QLineEdit *lEdit_2;
    QLabel *label_persent_2;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *comboBox_action2;
    QGraphicsView *graphicsView;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_6;
    QSlider *hSlider_4;
    QLineEdit *lEdit_4;
    QLabel *label_persent_4;
    QSpacerItem *horizontalSpacer_4;
    QComboBox *comboBox_action4;
    QLabel *label_action;

    void setupUi(QDialog *Schedule)
    {
        if (Schedule->objectName().isEmpty())
            Schedule->setObjectName(QStringLiteral("Schedule"));
        Schedule->resize(459, 300);
        layoutWidget = new QWidget(Schedule);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 70, 316, 25));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        hSlider_1 = new QSlider(layoutWidget);
        hSlider_1->setObjectName(QStringLiteral("hSlider_1"));
        hSlider_1->setMinimumSize(QSize(121, 19));
        hSlider_1->setMaximumSize(QSize(121, 19));
        hSlider_1->setMaximum(100);
        hSlider_1->setSingleStep(1);
        hSlider_1->setValue(0);
        hSlider_1->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(hSlider_1, 0, Qt::AlignLeft);

        lEdit_1 = new QLineEdit(layoutWidget);
        lEdit_1->setObjectName(QStringLiteral("lEdit_1"));
        lEdit_1->setMinimumSize(QSize(51, 20));
        lEdit_1->setMaximumSize(QSize(51, 20));
        QFont font;
        font.setFamily(QStringLiteral("Noto Sans T Chinese Medium"));
        font.setPointSize(12);
        lEdit_1->setFont(font);
        lEdit_1->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(lEdit_1);

        label_persent_1 = new QLabel(layoutWidget);
        label_persent_1->setObjectName(QStringLiteral("label_persent_1"));
        label_persent_1->setMinimumSize(QSize(16, 20));
        label_persent_1->setMaximumSize(QSize(16, 20));
        QFont font1;
        font1.setFamily(QStringLiteral("Noto Sans T Chinese Medium"));
        font1.setPointSize(10);
        label_persent_1->setFont(font1);
        label_persent_1->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_persent_1, 0, Qt::AlignLeft);

        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        comboBox_action1 = new QComboBox(layoutWidget);
        comboBox_action1->setObjectName(QStringLiteral("comboBox_action1"));
        comboBox_action1->setMinimumSize(QSize(81, 22));
        comboBox_action1->setMaximumSize(QSize(81, 22));
        comboBox_action1->setFont(font1);

        horizontalLayout_3->addWidget(comboBox_action1);

        layoutWidget_2 = new QWidget(Schedule);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(30, 170, 316, 25));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_2);
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
        lEdit_3->setFont(font);
        lEdit_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(lEdit_3);

        label_persent_3 = new QLabel(layoutWidget_2);
        label_persent_3->setObjectName(QStringLiteral("label_persent_3"));
        label_persent_3->setMinimumSize(QSize(16, 20));
        label_persent_3->setMaximumSize(QSize(16, 20));
        label_persent_3->setFont(font1);
        label_persent_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_persent_3, 0, Qt::AlignLeft);

        horizontalSpacer_3 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        comboBox_action3 = new QComboBox(layoutWidget_2);
        comboBox_action3->setObjectName(QStringLiteral("comboBox_action3"));
        comboBox_action3->setMinimumSize(QSize(81, 22));
        comboBox_action3->setMaximumSize(QSize(81, 22));
        comboBox_action3->setFont(font1);

        horizontalLayout_5->addWidget(comboBox_action3);

        layoutWidget_3 = new QWidget(Schedule);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(30, 120, 316, 25));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        hSlider_2 = new QSlider(layoutWidget_3);
        hSlider_2->setObjectName(QStringLiteral("hSlider_2"));
        hSlider_2->setMinimumSize(QSize(121, 19));
        hSlider_2->setMaximumSize(QSize(121, 19));
        hSlider_2->setMaximum(100);
        hSlider_2->setSingleStep(1);
        hSlider_2->setValue(0);
        hSlider_2->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(hSlider_2, 0, Qt::AlignLeft);

        lEdit_2 = new QLineEdit(layoutWidget_3);
        lEdit_2->setObjectName(QStringLiteral("lEdit_2"));
        lEdit_2->setMinimumSize(QSize(51, 20));
        lEdit_2->setMaximumSize(QSize(51, 20));
        lEdit_2->setFont(font);
        lEdit_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(lEdit_2);

        label_persent_2 = new QLabel(layoutWidget_3);
        label_persent_2->setObjectName(QStringLiteral("label_persent_2"));
        label_persent_2->setMinimumSize(QSize(16, 20));
        label_persent_2->setMaximumSize(QSize(16, 20));
        label_persent_2->setFont(font1);
        label_persent_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_persent_2, 0, Qt::AlignLeft);

        horizontalSpacer_2 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        comboBox_action2 = new QComboBox(layoutWidget_3);
        comboBox_action2->setObjectName(QStringLiteral("comboBox_action2"));
        comboBox_action2->setMinimumSize(QSize(81, 22));
        comboBox_action2->setMaximumSize(QSize(81, 22));
        comboBox_action2->setFont(font1);

        horizontalLayout_4->addWidget(comboBox_action2);

        graphicsView = new QGraphicsView(Schedule);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 441, 281));
        layoutWidget_4 = new QWidget(Schedule);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(30, 220, 316, 25));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        hSlider_4 = new QSlider(layoutWidget_4);
        hSlider_4->setObjectName(QStringLiteral("hSlider_4"));
        hSlider_4->setMinimumSize(QSize(121, 19));
        hSlider_4->setMaximumSize(QSize(121, 19));
        hSlider_4->setMaximum(100);
        hSlider_4->setSingleStep(1);
        hSlider_4->setValue(0);
        hSlider_4->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(hSlider_4, 0, Qt::AlignLeft);

        lEdit_4 = new QLineEdit(layoutWidget_4);
        lEdit_4->setObjectName(QStringLiteral("lEdit_4"));
        lEdit_4->setMinimumSize(QSize(51, 20));
        lEdit_4->setMaximumSize(QSize(51, 20));
        lEdit_4->setFont(font);
        lEdit_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(lEdit_4);

        label_persent_4 = new QLabel(layoutWidget_4);
        label_persent_4->setObjectName(QStringLiteral("label_persent_4"));
        label_persent_4->setMinimumSize(QSize(16, 20));
        label_persent_4->setMaximumSize(QSize(16, 20));
        label_persent_4->setFont(font1);
        label_persent_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_persent_4, 0, Qt::AlignLeft);

        horizontalSpacer_4 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        comboBox_action4 = new QComboBox(layoutWidget_4);
        comboBox_action4->setObjectName(QStringLiteral("comboBox_action4"));
        comboBox_action4->setMinimumSize(QSize(81, 22));
        comboBox_action4->setMaximumSize(QSize(81, 22));
        comboBox_action4->setFont(font1);

        horizontalLayout_6->addWidget(comboBox_action4);

        label_action = new QLabel(Schedule);
        label_action->setObjectName(QStringLiteral("label_action"));
        label_action->setGeometry(QRect(270, 40, 81, 20));
        label_action->setFont(font1);
        label_action->setAlignment(Qt::AlignCenter);
        graphicsView->raise();
        layoutWidget->raise();
        layoutWidget_2->raise();
        layoutWidget_3->raise();
        layoutWidget_4->raise();
        label_action->raise();

        retranslateUi(Schedule);

        QMetaObject::connectSlotsByName(Schedule);
    } // setupUi

    void retranslateUi(QDialog *Schedule)
    {
        Schedule->setWindowTitle(QApplication::translate("Schedule", "Dialog", 0));
        label_persent_1->setText(QApplication::translate("Schedule", "%", 0));
        comboBox_action1->clear();
        comboBox_action1->insertItems(0, QStringList()
         << QApplication::translate("Schedule", "Nothing", 0)
        );
        label_persent_3->setText(QApplication::translate("Schedule", "%", 0));
        comboBox_action3->clear();
        comboBox_action3->insertItems(0, QStringList()
         << QApplication::translate("Schedule", "Nothing", 0)
        );
        label_persent_2->setText(QApplication::translate("Schedule", "%", 0));
        comboBox_action2->clear();
        comboBox_action2->insertItems(0, QStringList()
         << QApplication::translate("Schedule", "Nothing", 0)
        );
        label_persent_4->setText(QApplication::translate("Schedule", "%", 0));
        comboBox_action4->clear();
        comboBox_action4->insertItems(0, QStringList()
         << QApplication::translate("Schedule", "Nothing", 0)
        );
        label_action->setText(QApplication::translate("Schedule", "Action to do", 0));
    } // retranslateUi

};

namespace Ui {
    class Schedule: public Ui_Schedule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHEDULE_H
