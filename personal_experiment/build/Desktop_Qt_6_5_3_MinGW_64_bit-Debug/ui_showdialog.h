/********************************************************************************
** Form generated from reading UI file 'showdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWDIALOG_H
#define UI_SHOWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowDialog
{
public:
    QTableWidget *tableWidget;
    QCheckBox *checkBox;

    void setupUi(QDialog *ShowDialog)
    {
        if (ShowDialog->objectName().isEmpty())
            ShowDialog->setObjectName("ShowDialog");
        ShowDialog->resize(658, 409);
        tableWidget = new QTableWidget(ShowDialog);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 70, 621, 311));
        checkBox = new QCheckBox(ShowDialog);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(510, 40, 79, 20));

        retranslateUi(ShowDialog);

        QMetaObject::connectSlotsByName(ShowDialog);
    } // setupUi

    void retranslateUi(QDialog *ShowDialog)
    {
        ShowDialog->setWindowTitle(QCoreApplication::translate("ShowDialog", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ShowDialog", "\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ShowDialog", "\345\247\223\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ShowDialog", "\345\207\272\347\224\237\346\227\245\346\234\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ShowDialog", "\347\224\265\350\257\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ShowDialog", "\351\202\256\347\256\261", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ShowDialog", "\351\231\204\345\212\240\344\277\241\346\201\257", nullptr));
        checkBox->setText(QCoreApplication::translate("ShowDialog", "\345\210\206\347\261\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowDialog: public Ui_ShowDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWDIALOG_H
