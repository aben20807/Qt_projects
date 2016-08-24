/********************************************************************************
** Form generated from reading UI file 'subwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBWINDOW_H
#define UI_SUBWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_SubWindow
{
public:
    QLabel *label;

    void setupUi(QDialog *SubWindow)
    {
        if (SubWindow->objectName().isEmpty())
            SubWindow->setObjectName(QStringLiteral("SubWindow"));
        SubWindow->resize(400, 300);
        QFont font;
        font.setPointSize(8);
        SubWindow->setFont(font);
        label = new QLabel(SubWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 110, 301, 91));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        font1.setPointSize(13);
        label->setFont(font1);
        label->setWordWrap(true);

        retranslateUi(SubWindow);

        QMetaObject::connectSlotsByName(SubWindow);
    } // setupUi

    void retranslateUi(QDialog *SubWindow)
    {
        SubWindow->setWindowTitle(QApplication::translate("SubWindow", "SubWindow", 0));
        label->setText(QApplication::translate("SubWindow", "I am SubWindow.                                   You can leave by closing this window.", 0));
    } // retranslateUi

};

namespace Ui {
    class SubWindow: public Ui_SubWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBWINDOW_H
