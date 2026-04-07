/********************************************************************************
** Form generated from reading UI file 'mainwindow_copy.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_COPY_H
#define UI_MAINWINDOW_COPY_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTreeWidget *treeWidget;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QWidget *widget_4;
    QWidget *widget_5;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QWidget *widget_6;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(40, 45));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/20210217235610_b6ddc (1).jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        treeWidget = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setGeometry(QRect(10, 170, 111, 281));
        treeWidget->setStyleSheet(QString::fromUtf8("font: 13pt \"\344\273\277\345\256\213\";"));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 20, 711, 60));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);\n"
""));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName("gridLayout_2");
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setMinimumSize(QSize(250, 0));
        widget_2->setMaximumSize(QSize(250, 16777215));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName("gridLayout");
        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(70, 0));
        pushButton->setMaximumSize(QSize(80, 16777215));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font.setPointSize(13);
        font.setBold(false);
        font.setItalic(false);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("font: 13pt \"\345\256\213\344\275\223\";"));

        gridLayout->addWidget(pushButton, 0, 3, 1, 1);

        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setMinimumSize(QSize(40, 45));
        label->setMaximumSize(QSize(40, 45));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/image/20210217235642_90671.jpeg);"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(70, 16777215));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(13);
        font1.setBold(false);
        font1.setItalic(false);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("font: 13pt \"Times New Roman\";"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);


        gridLayout_2->addWidget(widget_2, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(128, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(300, 0));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font2.setPointSize(24);
        font2.setBold(false);
        font2.setItalic(false);
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("\n"
"\n"
"font: 24pt \"\345\256\213\344\275\223\";"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_3, 0, 1, 1, 1);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(150, 100, 581, 381));
        page = new QWidget();
        page->setObjectName("page");
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        widget_4 = new QWidget(page_2);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(0, 0, 561, 391));
        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(70, 30, 211, 351));
        gridLayout_4 = new QGridLayout(widget_5);
        gridLayout_4->setObjectName("gridLayout_4");
        pushButton_3 = new QPushButton(widget_5);
        pushButton_3->setObjectName("pushButton_3");

        gridLayout_4->addWidget(pushButton_3, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(widget_5);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout_4->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton_4 = new QPushButton(widget_5);
        pushButton_4->setObjectName("pushButton_4");

        gridLayout_4->addWidget(pushButton_4, 2, 0, 1, 1);

        pushButton_5 = new QPushButton(widget_5);
        pushButton_5->setObjectName("pushButton_5");

        gridLayout_4->addWidget(pushButton_5, 3, 0, 1, 1);

        pushButton_6 = new QPushButton(widget_5);
        pushButton_6->setObjectName("pushButton_6");

        gridLayout_4->addWidget(pushButton_6, 4, 0, 1, 1);

        widget_6 = new QWidget(widget_4);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(310, 30, 211, 351));
        gridLayout_5 = new QGridLayout(widget_6);
        gridLayout_5->setObjectName("gridLayout_5");
        pushButton_7 = new QPushButton(widget_6);
        pushButton_7->setObjectName("pushButton_7");

        gridLayout_5->addWidget(pushButton_7, 0, 0, 1, 1);

        pushButton_8 = new QPushButton(widget_6);
        pushButton_8->setObjectName("pushButton_8");

        gridLayout_5->addWidget(pushButton_8, 1, 0, 1, 1);

        pushButton_9 = new QPushButton(widget_6);
        pushButton_9->setObjectName("pushButton_9");

        gridLayout_5->addWidget(pushButton_9, 2, 0, 1, 1);

        pushButton_10 = new QPushButton(widget_6);
        pushButton_10->setObjectName("pushButton_10");

        gridLayout_5->addWidget(pushButton_10, 3, 0, 1, 1);

        pushButton_11 = new QPushButton(widget_6);
        pushButton_11->setObjectName("pushButton_11");

        gridLayout_5->addWidget(pushButton_11, 4, 0, 1, 1);

        stackedWidget->addWidget(page_2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\344\270\252\344\272\272\351\200\232\350\256\257\345\275\225\347\263\273\347\273\237", nullptr));
#if QT_CONFIG(tooltip)
        MainWindow->setToolTip(QCoreApplication::translate("MainWindow", "\350\277\231\346\230\257\345\255\246\347\224\237\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\350\217\234\345\215\225\345\212\237\350\203\275\351\233\206", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\345\205\250\344\275\223\344\272\272\345\221\230\344\277\241\346\201\257", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "\346\237\245\346\211\2765\345\244\251\345\206\205\350\277\207\347\224\237\346\227\245\347\232\204\344\272\272\345\221\230\344\277\241\346\201\257", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "\347\273\237\350\256\241\346\214\207\345\256\232\346\234\210\344\273\275\345\207\272\347\224\237\344\272\272\346\225\260", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "\346\214\211\347\205\247\346\214\207\345\256\232\346\235\241\344\273\266\346\216\222\345\272\217", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "\345\206\231\345\205\245\346\226\207\344\273\266", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_COPY_H
