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
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Schedule
{
public:
    QGraphicsView *graphicsView;
    QLabel *label_action_to_do;
    QComboBox *comboBox_condition1;
    QLabel *label_level;
    QLabel *label_condition;
    QLineEdit *lEdit_1;
    QLabel *label_persent_1;
    QComboBox *comboBox_action1;
    QLabel *label_number1;
    QDialogButtonBox *buttonBox_okCancel;
    QLineEdit *lEdit_2;
    QLabel *label_persent_2;
    QComboBox *comboBox_condition2;
    QComboBox *comboBox_action2;
    QLabel *label_number2;
    QLineEdit *lEdit_3;
    QLabel *label_persent_3;
    QComboBox *comboBox_condition3;
    QComboBox *comboBox_action3;
    QLabel *label_number3;
    QLineEdit *lEdit_4;
    QLabel *label_persent_4;
    QComboBox *comboBox_condition4;
    QComboBox *comboBox_action4;
    QLabel *label_number4;
    QLabel *label_connectStatus;

    void setupUi(QDialog *Schedule)
    {
        if (Schedule->objectName().isEmpty())
            Schedule->setObjectName(QStringLiteral("Schedule"));
        Schedule->resize(460, 305);
        graphicsView = new QGraphicsView(Schedule);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 8, 441, 291));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        graphicsView->setFont(font);
        label_action_to_do = new QLabel(Schedule);
        label_action_to_do->setObjectName(QStringLiteral("label_action_to_do"));
        label_action_to_do->setGeometry(QRect(290, 40, 81, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        font1.setPointSize(10);
        label_action_to_do->setFont(font1);
        label_action_to_do->setAlignment(Qt::AlignCenter);
        comboBox_condition1 = new QComboBox(Schedule);
        comboBox_condition1->setObjectName(QStringLiteral("comboBox_condition1"));
        comboBox_condition1->setGeometry(QRect(90, 70, 101, 22));
        comboBox_condition1->setFont(font1);
        label_level = new QLabel(Schedule);
        label_level->setObjectName(QStringLiteral("label_level"));
        label_level->setGeometry(QRect(210, 40, 31, 20));
        label_level->setFont(font1);
        label_level->setAlignment(Qt::AlignCenter);
        label_condition = new QLabel(Schedule);
        label_condition->setObjectName(QStringLiteral("label_condition"));
        label_condition->setGeometry(QRect(90, 40, 61, 20));
        label_condition->setFont(font1);
        label_condition->setAlignment(Qt::AlignCenter);
        lEdit_1 = new QLineEdit(Schedule);
        lEdit_1->setObjectName(QStringLiteral("lEdit_1"));
        lEdit_1->setGeometry(QRect(210, 70, 41, 22));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        font2.setPointSize(12);
        lEdit_1->setFont(font2);
        lEdit_1->setAlignment(Qt::AlignCenter);
        label_persent_1 = new QLabel(Schedule);
        label_persent_1->setObjectName(QStringLiteral("label_persent_1"));
        label_persent_1->setGeometry(QRect(250, 70, 16, 22));
        label_persent_1->setFont(font1);
        label_persent_1->setAlignment(Qt::AlignCenter);
        comboBox_action1 = new QComboBox(Schedule);
        comboBox_action1->setObjectName(QStringLiteral("comboBox_action1"));
        comboBox_action1->setGeometry(QRect(290, 70, 91, 22));
        comboBox_action1->setFont(font1);
        label_number1 = new QLabel(Schedule);
        label_number1->setObjectName(QStringLiteral("label_number1"));
        label_number1->setGeometry(QRect(70, 70, 16, 22));
        label_number1->setFont(font2);
        label_number1->setAlignment(Qt::AlignCenter);
        buttonBox_okCancel = new QDialogButtonBox(Schedule);
        buttonBox_okCancel->setObjectName(QStringLiteral("buttonBox_okCancel"));
        buttonBox_okCancel->setGeometry(QRect(200, 260, 241, 23));
        buttonBox_okCancel->setFont(font1);
        buttonBox_okCancel->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lEdit_2 = new QLineEdit(Schedule);
        lEdit_2->setObjectName(QStringLiteral("lEdit_2"));
        lEdit_2->setGeometry(QRect(210, 110, 41, 22));
        lEdit_2->setFont(font2);
        lEdit_2->setAlignment(Qt::AlignCenter);
        label_persent_2 = new QLabel(Schedule);
        label_persent_2->setObjectName(QStringLiteral("label_persent_2"));
        label_persent_2->setGeometry(QRect(250, 110, 16, 22));
        label_persent_2->setFont(font1);
        label_persent_2->setAlignment(Qt::AlignCenter);
        comboBox_condition2 = new QComboBox(Schedule);
        comboBox_condition2->setObjectName(QStringLiteral("comboBox_condition2"));
        comboBox_condition2->setGeometry(QRect(90, 110, 101, 22));
        comboBox_condition2->setFont(font1);
        comboBox_action2 = new QComboBox(Schedule);
        comboBox_action2->setObjectName(QStringLiteral("comboBox_action2"));
        comboBox_action2->setGeometry(QRect(290, 110, 91, 22));
        comboBox_action2->setFont(font1);
        label_number2 = new QLabel(Schedule);
        label_number2->setObjectName(QStringLiteral("label_number2"));
        label_number2->setGeometry(QRect(70, 110, 16, 22));
        label_number2->setFont(font2);
        label_number2->setAlignment(Qt::AlignCenter);
        lEdit_3 = new QLineEdit(Schedule);
        lEdit_3->setObjectName(QStringLiteral("lEdit_3"));
        lEdit_3->setGeometry(QRect(210, 150, 41, 22));
        lEdit_3->setFont(font2);
        lEdit_3->setAlignment(Qt::AlignCenter);
        label_persent_3 = new QLabel(Schedule);
        label_persent_3->setObjectName(QStringLiteral("label_persent_3"));
        label_persent_3->setGeometry(QRect(250, 150, 16, 22));
        label_persent_3->setFont(font1);
        label_persent_3->setAlignment(Qt::AlignCenter);
        comboBox_condition3 = new QComboBox(Schedule);
        comboBox_condition3->setObjectName(QStringLiteral("comboBox_condition3"));
        comboBox_condition3->setGeometry(QRect(90, 150, 101, 22));
        comboBox_condition3->setFont(font1);
        comboBox_action3 = new QComboBox(Schedule);
        comboBox_action3->setObjectName(QStringLiteral("comboBox_action3"));
        comboBox_action3->setGeometry(QRect(290, 150, 91, 22));
        comboBox_action3->setFont(font1);
        label_number3 = new QLabel(Schedule);
        label_number3->setObjectName(QStringLiteral("label_number3"));
        label_number3->setGeometry(QRect(70, 150, 16, 22));
        label_number3->setFont(font2);
        label_number3->setAlignment(Qt::AlignCenter);
        lEdit_4 = new QLineEdit(Schedule);
        lEdit_4->setObjectName(QStringLiteral("lEdit_4"));
        lEdit_4->setGeometry(QRect(210, 190, 41, 22));
        lEdit_4->setFont(font2);
        lEdit_4->setAlignment(Qt::AlignCenter);
        label_persent_4 = new QLabel(Schedule);
        label_persent_4->setObjectName(QStringLiteral("label_persent_4"));
        label_persent_4->setGeometry(QRect(250, 190, 16, 22));
        label_persent_4->setFont(font1);
        label_persent_4->setAlignment(Qt::AlignCenter);
        comboBox_condition4 = new QComboBox(Schedule);
        comboBox_condition4->setObjectName(QStringLiteral("comboBox_condition4"));
        comboBox_condition4->setGeometry(QRect(90, 190, 101, 22));
        comboBox_condition4->setFont(font1);
        comboBox_action4 = new QComboBox(Schedule);
        comboBox_action4->setObjectName(QStringLiteral("comboBox_action4"));
        comboBox_action4->setGeometry(QRect(290, 190, 91, 22));
        comboBox_action4->setFont(font1);
        label_number4 = new QLabel(Schedule);
        label_number4->setObjectName(QStringLiteral("label_number4"));
        label_number4->setGeometry(QRect(70, 190, 16, 22));
        label_number4->setFont(font2);
        label_number4->setAlignment(Qt::AlignCenter);
        label_connectStatus = new QLabel(Schedule);
        label_connectStatus->setObjectName(QStringLiteral("label_connectStatus"));
        label_connectStatus->setGeometry(QRect(310, 10, 131, 21));
        label_connectStatus->setMinimumSize(QSize(51, 21));
        label_connectStatus->setFont(font1);
        label_connectStatus->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        graphicsView->raise();
        lEdit_1->raise();
        label_persent_1->raise();
        comboBox_action1->raise();
        label_action_to_do->raise();
        comboBox_condition1->raise();
        label_level->raise();
        label_condition->raise();
        label_number1->raise();
        buttonBox_okCancel->raise();
        lEdit_2->raise();
        label_persent_2->raise();
        comboBox_condition2->raise();
        comboBox_action2->raise();
        label_number2->raise();
        lEdit_3->raise();
        label_persent_3->raise();
        comboBox_condition3->raise();
        comboBox_action3->raise();
        label_number3->raise();
        lEdit_4->raise();
        label_persent_4->raise();
        comboBox_condition4->raise();
        comboBox_action4->raise();
        label_number4->raise();
        label_connectStatus->raise();

        retranslateUi(Schedule);

        QMetaObject::connectSlotsByName(Schedule);
    } // setupUi

    void retranslateUi(QDialog *Schedule)
    {
        Schedule->setWindowTitle(QApplication::translate("Schedule", "Schedule", 0));
        label_action_to_do->setText(QApplication::translate("Schedule", "Action to do", 0));
        comboBox_condition1->clear();
        comboBox_condition1->insertItems(0, QStringList()
         << QApplication::translate("Schedule", "Choose one", 0)
         << QApplication::translate("Schedule", "If level >", 0)
         << QApplication::translate("Schedule", "If level <", 0)
        );
        label_level->setText(QApplication::translate("Schedule", "Level", 0));
        label_condition->setText(QApplication::translate("Schedule", "Condition", 0));
        label_persent_1->setText(QApplication::translate("Schedule", "%", 0));
        comboBox_action1->clear();
        comboBox_action1->insertItems(0, QStringList()
         << QApplication::translate("Schedule", "Nothing", 0)
         << QApplication::translate("Schedule", "Remind", 0)
         << QApplication::translate("Schedule", "Shut down", 0)
         << QApplication::translate("Schedule", "Sleep", 0)
         << QApplication::translate("Schedule", "Hibernate", 0)
        );
        label_number1->setText(QApplication::translate("Schedule", "1.", 0));
        label_persent_2->setText(QApplication::translate("Schedule", "%", 0));
        comboBox_condition2->clear();
        comboBox_condition2->insertItems(0, QStringList()
         << QApplication::translate("Schedule", "Choose one", 0)
         << QApplication::translate("Schedule", "If level >", 0)
         << QApplication::translate("Schedule", "If level <", 0)
        );
        comboBox_action2->clear();
        comboBox_action2->insertItems(0, QStringList()
         << QApplication::translate("Schedule", "Nothing", 0)
         << QApplication::translate("Schedule", "Remind", 0)
         << QApplication::translate("Schedule", "Shut down", 0)
         << QApplication::translate("Schedule", "Sleep", 0)
         << QApplication::translate("Schedule", "Hibernate", 0)
        );
        label_number2->setText(QApplication::translate("Schedule", "2.", 0));
        label_persent_3->setText(QApplication::translate("Schedule", "%", 0));
        comboBox_condition3->clear();
        comboBox_condition3->insertItems(0, QStringList()
         << QApplication::translate("Schedule", "Choose one", 0)
         << QApplication::translate("Schedule", "If level >", 0)
         << QApplication::translate("Schedule", "If level <", 0)
        );
        comboBox_action3->clear();
        comboBox_action3->insertItems(0, QStringList()
         << QApplication::translate("Schedule", "Nothing", 0)
         << QApplication::translate("Schedule", "Remind", 0)
         << QApplication::translate("Schedule", "Shut down", 0)
         << QApplication::translate("Schedule", "Sleep", 0)
         << QApplication::translate("Schedule", "Hibernate", 0)
        );
        label_number3->setText(QApplication::translate("Schedule", "3.", 0));
        label_persent_4->setText(QApplication::translate("Schedule", "%", 0));
        comboBox_condition4->clear();
        comboBox_condition4->insertItems(0, QStringList()
         << QApplication::translate("Schedule", "Choose one", 0)
         << QApplication::translate("Schedule", "If level >", 0)
         << QApplication::translate("Schedule", "If level <", 0)
        );
        comboBox_action4->clear();
        comboBox_action4->insertItems(0, QStringList()
         << QApplication::translate("Schedule", "Nothing", 0)
         << QApplication::translate("Schedule", "Remind", 0)
         << QApplication::translate("Schedule", "Shut down", 0)
         << QApplication::translate("Schedule", "Sleep", 0)
         << QApplication::translate("Schedule", "Hibernate", 0)
        );
        label_number4->setText(QApplication::translate("Schedule", "4.", 0));
#ifndef QT_NO_TOOLTIP
        label_connectStatus->setToolTip(QApplication::translate("Schedule", "The connection status to database", 0));
#endif // QT_NO_TOOLTIP
        label_connectStatus->setText(QApplication::translate("Schedule", "[+]connectStatus", 0));
    } // retranslateUi

};

namespace Ui {
    class Schedule: public Ui_Schedule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHEDULE_H
