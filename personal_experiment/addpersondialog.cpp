#include "addpersondialog.h"
#include "ui_addpersondialog.h"
#include "person_factory.h"
//把add 和 modify合成一个？
AddPersonDialog::AddPersonDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddPersonDialog)
{
    ui->setupUi(this);

    //添加联系人类型
    ui->comboBox_type->addItems({"同学","同事","朋友","亲戚"});

    //设置默认日期为今天
    ui->dateEdit_birthday->setDate(QDate::currentDate());

    //连接下拉框变化信号：通过currentText的变化，改变需要添加的附加信息的名称
    connect(ui->comboBox_type,&QComboBox::currentTextChanged,this,&AddPersonDialog::typeChanged);

    //初始化一次
    typeChanged(ui->comboBox_type->currentText());
}

AddPersonDialog::~AddPersonDialog()
{
    delete ui;
}

Person * AddPersonDialog::getData()
{
    Person *p;
    p=createPerson(ui->lineEdit_name->text(),
        ui->dateEdit_birthday->date(),
        ui->lineEdit_phone->text(),
        ui->lineEdit_email->text(),
        ui->comboBox_type->currentText(),
        ui->lineEdit_exIn->text()
    );
    return p;
}

void AddPersonDialog::typeChanged(QString type)
{
    if(type=="同学")
    {
        ui->label_exIn->setText("学校名称：");
        ui->lineEdit_exIn->setPlaceholderText("请输入学校名称");
    }
    else if(type=="同事")
    {
        ui->label_exIn->setText("单位名称：");
        ui->lineEdit_exIn->setPlaceholderText("请输入单位名称");
    }
    else if (type == "亲戚") {
        ui->label_exIn->setText("称呼：");
        ui->lineEdit_exIn->setPlaceholderText("请输入与您的关系称呼");
    }
    else if (type == "朋友") {
        ui->label_exIn->setText("相识地点：");
        ui->lineEdit_exIn->setPlaceholderText("请输入相识地点");
    }

}
//保留并直接显示原有信息
void AddPersonDialog::setData(Person* p)
{
    //默认显示原有信息
    ui->comboBox_type->setCurrentText(p->getType());
    ui->lineEdit_email->setText(p->getEmail());
    ui->lineEdit_exIn->setText(p->getExIn());
    ui->lineEdit_phone->setText(p->getPhone());
    ui->lineEdit_name->setText(p->getName());
    ui->dateEdit_birthday->setDate(p->getBirthday());
    //禁止修改姓名和生日
    ui->lineEdit_name->setEnabled(false);
    ui->dateEdit_birthday->setEnabled(false);
    //初始化附加信息内容
    typeChanged(p->getType());
}

