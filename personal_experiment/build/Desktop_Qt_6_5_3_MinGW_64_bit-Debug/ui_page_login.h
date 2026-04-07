/********************************************************************************
** Form generated from reading UI file 'page_login.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE_LOGIN_H
#define UI_PAGE_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Page_login
{
public:
    QLabel *label_3;
    QWidget *widget;
    QPushButton *pushButton_2;
    QPushButton *btn_login;
    QWidget *widget_2;
    QLineEdit *username;
    QLineEdit *password;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Page_login)
    {
        if (Page_login->objectName().isEmpty())
            Page_login->setObjectName("Page_login");
        Page_login->resize(400, 250);
        Page_login->setMinimumSize(QSize(400, 250));
        Page_login->setMaximumSize(QSize(400, 250));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/20210217235610_b6ddc (1).jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        Page_login->setWindowIcon(icon);
        label_3 = new QLabel(Page_login);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 30, 241, 41));
        QFont font;
        font.setPointSize(14);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        widget = new QWidget(Page_login);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(51, 149, 340, 82));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(170, 50, 123, 31));
        QFont font1;
        font1.setPointSize(11);
        pushButton_2->setFont(font1);
        btn_login = new QPushButton(widget);
        btn_login->setObjectName("btn_login");
        btn_login->setGeometry(QRect(10, 50, 123, 31));
        btn_login->setFont(font1);
        widget_2 = new QWidget(Page_login);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(20, 80, 371, 80));
        username = new QLineEdit(widget_2);
        username->setObjectName("username");
        username->setGeometry(QRect(60, 20, 241, 20));
        password = new QLineEdit(widget_2);
        password->setObjectName("password");
        password->setGeometry(QRect(60, 60, 241, 20));
        password->setEchoMode(QLineEdit::Password);
        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setGeometry(QRect(-15, 20, 61, 20));
        label->setFont(font1);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 60, 51, 20));
        label_2->setFont(font1);
        label_2->setScaledContents(false);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(Page_login);

        QMetaObject::connectSlotsByName(Page_login);
    } // setupUi

    void retranslateUi(QWidget *Page_login)
    {
        Page_login->setWindowTitle(QCoreApplication::translate("Page_login", "\347\231\273\345\275\225", nullptr));
#if QT_CONFIG(tooltip)
        Page_login->setToolTip(QCoreApplication::translate("Page_login", "\350\277\231\346\230\257\347\231\273\345\275\225\347\252\227\345\217\243", nullptr));
#endif // QT_CONFIG(tooltip)
        label_3->setText(QCoreApplication::translate("Page_login", "            \344\270\252\344\272\272\351\200\232\350\256\257\345\275\225\347\263\273\347\273\237", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Page_login", "\351\200\200\345\207\272", nullptr));
        btn_login->setText(QCoreApplication::translate("Page_login", "\347\231\273\345\275\225", nullptr));
        username->setPlaceholderText(QCoreApplication::translate("Page_login", "\350\257\267\350\276\223\345\205\245", nullptr));
        password->setPlaceholderText(QCoreApplication::translate("Page_login", "\350\257\267\350\276\223\345\205\245", nullptr));
        label->setText(QCoreApplication::translate("Page_login", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("Page_login", "\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Page_login: public Ui_Page_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE_LOGIN_H
