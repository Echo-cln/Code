/********************************************************************************
** Form generated from reading UI file 'modifypersondialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYPERSONDIALOG_H
#define UI_MODIFYPERSONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModifyPersonDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_name;
    QComboBox *comboBox_type;
    QLineEdit *lineEdit_exIn;
    QLineEdit *lineEdit_email;
    QLineEdit *lineEdit_phone;
    QDateEdit *dateEdit_birthday;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_date;
    QLabel *label_type;
    QLabel *label_phone;
    QLabel *label_email;
    QLabel *label_exIn;

    void setupUi(QDialog *ModifyPersonDialog)
    {
        if (ModifyPersonDialog->objectName().isEmpty())
            ModifyPersonDialog->setObjectName("ModifyPersonDialog");
        ModifyPersonDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(ModifyPersonDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget_2 = new QWidget(ModifyPersonDialog);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(120, 20, 181, 231));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName("gridLayout");
        lineEdit_name = new QLineEdit(widget_2);
        lineEdit_name->setObjectName("lineEdit_name");

        gridLayout->addWidget(lineEdit_name, 0, 0, 1, 1);

        comboBox_type = new QComboBox(widget_2);
        comboBox_type->setObjectName("comboBox_type");

        gridLayout->addWidget(comboBox_type, 2, 0, 1, 1);

        lineEdit_exIn = new QLineEdit(widget_2);
        lineEdit_exIn->setObjectName("lineEdit_exIn");

        gridLayout->addWidget(lineEdit_exIn, 5, 0, 1, 1);

        lineEdit_email = new QLineEdit(widget_2);
        lineEdit_email->setObjectName("lineEdit_email");

        gridLayout->addWidget(lineEdit_email, 4, 0, 1, 1);

        lineEdit_phone = new QLineEdit(widget_2);
        lineEdit_phone->setObjectName("lineEdit_phone");

        gridLayout->addWidget(lineEdit_phone, 3, 0, 1, 1);

        dateEdit_birthday = new QDateEdit(widget_2);
        dateEdit_birthday->setObjectName("dateEdit_birthday");

        gridLayout->addWidget(dateEdit_birthday, 1, 0, 1, 1);

        widget = new QWidget(ModifyPersonDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(40, 20, 66, 221));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName("gridLayout_2");
        label = new QLabel(widget);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_date = new QLabel(widget);
        label_date->setObjectName("label_date");

        gridLayout_2->addWidget(label_date, 1, 0, 1, 1);

        label_type = new QLabel(widget);
        label_type->setObjectName("label_type");

        gridLayout_2->addWidget(label_type, 2, 0, 1, 1);

        label_phone = new QLabel(widget);
        label_phone->setObjectName("label_phone");

        gridLayout_2->addWidget(label_phone, 3, 0, 1, 1);

        label_email = new QLabel(widget);
        label_email->setObjectName("label_email");

        gridLayout_2->addWidget(label_email, 4, 0, 1, 1);

        label_exIn = new QLabel(widget);
        label_exIn->setObjectName("label_exIn");

        gridLayout_2->addWidget(label_exIn, 5, 0, 1, 1);


        retranslateUi(ModifyPersonDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ModifyPersonDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ModifyPersonDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ModifyPersonDialog);
    } // setupUi

    void retranslateUi(QDialog *ModifyPersonDialog)
    {
        ModifyPersonDialog->setWindowTitle(QCoreApplication::translate("ModifyPersonDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ModifyPersonDialog", "\345\247\223\345\220\215", nullptr));
        label_date->setText(QCoreApplication::translate("ModifyPersonDialog", "\345\207\272\347\224\237\346\227\245\346\234\237", nullptr));
        label_type->setText(QCoreApplication::translate("ModifyPersonDialog", "\347\261\273\345\236\213", nullptr));
        label_phone->setText(QCoreApplication::translate("ModifyPersonDialog", "\347\224\265\350\257\235", nullptr));
        label_email->setText(QCoreApplication::translate("ModifyPersonDialog", "\351\202\256\347\256\261", nullptr));
        label_exIn->setText(QCoreApplication::translate("ModifyPersonDialog", "\351\231\204\345\212\240\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModifyPersonDialog: public Ui_ModifyPersonDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYPERSONDIALOG_H
