/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SignUp
{
public:
    QLabel *label_logo;
    QPushButton *btn_signUp_conf;
    QLineEdit *lE_password;
    QLineEdit *lE_userName;
    QGraphicsView *graphicsView;
    QLineEdit *lE_password_conf;
    QLineEdit *lE_fullName;
    QPushButton *btn_cancel;
    QLabel *label_status;

    void setupUi(QDialog *SignUp)
    {
        if (SignUp->objectName().isEmpty())
            SignUp->setObjectName(QStringLiteral("SignUp"));
        SignUp->resize(430, 350);
        label_logo = new QLabel(SignUp);
        label_logo->setObjectName(QStringLiteral("label_logo"));
        label_logo->setGeometry(QRect(20, 10, 141, 61));
        QFont font;
        font.setFamily(QStringLiteral("Noto Sans T Chinese Thin"));
        font.setPointSize(32);
        font.setBold(false);
        font.setWeight(50);
        label_logo->setFont(font);
        btn_signUp_conf = new QPushButton(SignUp);
        btn_signUp_conf->setObjectName(QStringLiteral("btn_signUp_conf"));
        btn_signUp_conf->setEnabled(true);
        btn_signUp_conf->setGeometry(QRect(100, 290, 75, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Noto Sans T Chinese Medium"));
        font1.setPointSize(12);
        btn_signUp_conf->setFont(font1);
        btn_signUp_conf->setCursor(QCursor(Qt::PointingHandCursor));
        btn_signUp_conf->setStyleSheet(QLatin1String("#btn_signUp_conf {\n"
"background-color: transparent;\n"
"border-image: url(:img/btn_signUp);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}\n"
""));
        btn_signUp_conf->setAutoDefault(false);
        btn_signUp_conf->setFlat(false);
        lE_password = new QLineEdit(SignUp);
        lE_password->setObjectName(QStringLiteral("lE_password"));
        lE_password->setGeometry(QRect(100, 138, 231, 27));
        QFont font2;
        font2.setFamily(QStringLiteral("Noto Sans T Chinese Medium"));
        font2.setPointSize(11);
        lE_password->setFont(font2);
        lE_password->setEchoMode(QLineEdit::Password);
        lE_userName = new QLineEdit(SignUp);
        lE_userName->setObjectName(QStringLiteral("lE_userName"));
        lE_userName->setGeometry(QRect(100, 90, 231, 27));
        lE_userName->setFont(font2);
        graphicsView = new QGraphicsView(SignUp);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 411, 331));
        graphicsView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        lE_password_conf = new QLineEdit(SignUp);
        lE_password_conf->setObjectName(QStringLiteral("lE_password_conf"));
        lE_password_conf->setGeometry(QRect(100, 190, 231, 27));
        lE_password_conf->setFont(font2);
        lE_password_conf->setEchoMode(QLineEdit::Password);
        lE_fullName = new QLineEdit(SignUp);
        lE_fullName->setObjectName(QStringLiteral("lE_fullName"));
        lE_fullName->setGeometry(QRect(100, 240, 231, 27));
        lE_fullName->setFont(font2);
        btn_cancel = new QPushButton(SignUp);
        btn_cancel->setObjectName(QStringLiteral("btn_cancel"));
        btn_cancel->setGeometry(QRect(280, 300, 61, 20));
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
        label_status = new QLabel(SignUp);
        label_status->setObjectName(QStringLiteral("label_status"));
        label_status->setGeometry(QRect(306, 309, 111, 41));
        QFont font4;
        font4.setFamily(QStringLiteral("Noto Sans T Chinese Medium"));
        font4.setPointSize(8);
        label_status->setFont(font4);
        label_status->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        graphicsView->raise();
        label_logo->raise();
        btn_signUp_conf->raise();
        lE_password->raise();
        lE_userName->raise();
        lE_password_conf->raise();
        lE_fullName->raise();
        btn_cancel->raise();
        label_status->raise();

        retranslateUi(SignUp);

        QMetaObject::connectSlotsByName(SignUp);
    } // setupUi

    void retranslateUi(QDialog *SignUp)
    {
        SignUp->setWindowTitle(QApplication::translate("SignUp", "Sign up", 0));
        label_logo->setText(QApplication::translate("SignUp", "Sign up", 0));
        btn_signUp_conf->setText(QString());
        lE_password->setPlaceholderText(QApplication::translate("SignUp", "Password", 0));
        lE_userName->setPlaceholderText(QApplication::translate("SignUp", "User name", 0));
        lE_password_conf->setPlaceholderText(QApplication::translate("SignUp", "Confirm password", 0));
        lE_fullName->setPlaceholderText(QApplication::translate("SignUp", "Full name", 0));
        btn_cancel->setText(QApplication::translate("SignUp", "Cancel", 0));
        label_status->setText(QApplication::translate("SignUp", "[+] Status", 0));
    } // retranslateUi

};

namespace Ui {
    class SignUp: public Ui_SignUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
