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

    void setupUi(QDialog *SignUp)
    {
        if (SignUp->objectName().isEmpty())
            SignUp->setObjectName(QStringLiteral("SignUp"));
        SignUp->resize(430, 290);
        label_logo = new QLabel(SignUp);
        label_logo->setObjectName(QStringLiteral("label_logo"));
        label_logo->setGeometry(QRect(10, 10, 141, 61));
        QFont font;
        font.setFamily(QStringLiteral("Noto Sans T Chinese Thin"));
        font.setPointSize(32);
        font.setBold(false);
        font.setWeight(50);
        label_logo->setFont(font);
        btn_signUp_conf = new QPushButton(SignUp);
        btn_signUp_conf->setObjectName(QStringLiteral("btn_signUp_conf"));
        btn_signUp_conf->setEnabled(true);
        btn_signUp_conf->setGeometry(QRect(100, 190, 75, 31));
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
        graphicsView->setGeometry(QRect(0, 0, 431, 291));
        graphicsView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        graphicsView->raise();
        label_logo->raise();
        btn_signUp_conf->raise();
        lE_password->raise();
        lE_userName->raise();

        retranslateUi(SignUp);

        QMetaObject::connectSlotsByName(SignUp);
    } // setupUi

    void retranslateUi(QDialog *SignUp)
    {
        SignUp->setWindowTitle(QApplication::translate("SignUp", "Sign up", 0));
        label_logo->setText(QApplication::translate("SignUp", "Sign up", 0));
        btn_signUp_conf->setText(QString());
        lE_password->setPlaceholderText(QApplication::translate("SignUp", "password", 0));
        lE_userName->setPlaceholderText(QApplication::translate("SignUp", "user name", 0));
    } // retranslateUi

};

namespace Ui {
    class SignUp: public Ui_SignUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
