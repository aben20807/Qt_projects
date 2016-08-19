/********************************************************************************
** Form generated from reading UI file 'operate.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPERATE_H
#define UI_OPERATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Operate
{
public:
    QGraphicsView *graphicsView;
    QLabel *label_status;
    QLabel *label_logo;
    QPushButton *btn_delete;
    QPushButton *btn_cancel;

    void setupUi(QDialog *Operate)
    {
        if (Operate->objectName().isEmpty())
            Operate->setObjectName(QStringLiteral("Operate"));
        Operate->resize(430, 350);
        graphicsView = new QGraphicsView(Operate);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 411, 331));
        label_status = new QLabel(Operate);
        label_status->setObjectName(QStringLiteral("label_status"));
        label_status->setGeometry(QRect(306, 309, 111, 41));
        QFont font;
        font.setFamily(QStringLiteral("Noto Sans T Chinese Medium"));
        font.setPointSize(8);
        label_status->setFont(font);
        label_status->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_logo = new QLabel(Operate);
        label_logo->setObjectName(QStringLiteral("label_logo"));
        label_logo->setGeometry(QRect(20, 10, 141, 61));
        QFont font1;
        font1.setFamily(QStringLiteral("Noto Sans T Chinese Thin"));
        font1.setPointSize(32);
        font1.setBold(false);
        font1.setWeight(50);
        label_logo->setFont(font1);
        btn_delete = new QPushButton(Operate);
        btn_delete->setObjectName(QStringLiteral("btn_delete"));
        btn_delete->setEnabled(true);
        btn_delete->setGeometry(QRect(40, 290, 75, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Noto Sans T Chinese Medium"));
        font2.setPointSize(12);
        btn_delete->setFont(font2);
        btn_delete->setCursor(QCursor(Qt::PointingHandCursor));
        btn_delete->setStyleSheet(QLatin1String("#btn_delete {\n"
"background-color: transparent;\n"
"border-image: url(:img/btn_delete);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}\n"
""));
        btn_delete->setAutoDefault(false);
        btn_delete->setFlat(false);
        btn_cancel = new QPushButton(Operate);
        btn_cancel->setObjectName(QStringLiteral("btn_cancel"));
        btn_cancel->setGeometry(QRect(350, 40, 61, 20));
        QFont font3;
        font3.setFamily(QStringLiteral("Noto Sans T Chinese Medium"));
        font3.setPointSize(10);
        btn_cancel->setFont(font3);
        btn_cancel->setCursor(QCursor(Qt::PointingHandCursor));
        btn_cancel->setStyleSheet(QLatin1String("#btn_cancel {\n"
"	color: rgb(0, 117, 169);\n"
"background-color: transparent;\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));

        retranslateUi(Operate);

        QMetaObject::connectSlotsByName(Operate);
    } // setupUi

    void retranslateUi(QDialog *Operate)
    {
        Operate->setWindowTitle(QApplication::translate("Operate", "Dialog", 0));
        label_status->setText(QApplication::translate("Operate", "[+] Status", 0));
        label_logo->setText(QApplication::translate("Operate", "Home", 0));
        btn_delete->setText(QString());
        btn_cancel->setText(QApplication::translate("Operate", "Sign out", 0));
    } // retranslateUi

};

namespace Ui {
    class Operate: public Ui_Operate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPERATE_H
