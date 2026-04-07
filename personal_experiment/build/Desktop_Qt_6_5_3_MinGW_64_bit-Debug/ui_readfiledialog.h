/********************************************************************************
** Form generated from reading UI file 'readfiledialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READFILEDIALOG_H
#define UI_READFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_readFileDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QTextEdit *textEdit;

    void setupUi(QDialog *readFileDialog)
    {
        if (readFileDialog->objectName().isEmpty())
            readFileDialog->setObjectName("readFileDialog");
        readFileDialog->resize(397, 353);
        verticalLayout = new QVBoxLayout(readFileDialog);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(readFileDialog);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addWidget(widget);

        textEdit = new QTextEdit(readFileDialog);
        textEdit->setObjectName("textEdit");

        verticalLayout->addWidget(textEdit);


        retranslateUi(readFileDialog);

        QMetaObject::connectSlotsByName(readFileDialog);
    } // setupUi

    void retranslateUi(QDialog *readFileDialog)
    {
        readFileDialog->setWindowTitle(QCoreApplication::translate("readFileDialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("readFileDialog", "\346\265\217\350\247\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class readFileDialog: public Ui_readFileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READFILEDIALOG_H
