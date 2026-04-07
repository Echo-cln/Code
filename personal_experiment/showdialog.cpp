#include "showdialog.h"
#include "ui_showdialog.h"
#include "person.h"
#include "mainwindow.h"
#include<QVector>

ShowDialog::ShowDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ShowDialog)
{
    ui->setupUi(this);
    // 从 MainWindow 获取完整数据
    MainWindow* mw = qobject_cast<MainWindow*>(this->parent());
    connect(ui->checkBox,&QCheckBox::stateChanged,this,&ShowDialog::onCheckBoxStateChanged);
    connect(ui->pushButton_add,     &QPushButton::clicked, mw, &MainWindow::on_pushButton_3_clicked); // 添加
    connect(ui->pushButton_mod,   &QPushButton::clicked, mw, &MainWindow::on_pushButton_2_clicked); // 修改
    connect(ui->pushButton_del,   &QPushButton::clicked, mw, &MainWindow::on_pushButton_4_clicked); // 删除
    connect(ui->pushButton_sort,   &QPushButton::clicked, mw, &MainWindow::on_pushButton_99_clicked); // 排序
    //ui->pushButton_sort->hide();
}

ShowDialog::~ShowDialog()
{
    delete ui;
}

void ShowDialog::setData(QVector<Person*> list)
{
    //同步列表数据到tableWidget显示
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(list.size());
    ui->tableWidget->setColumnCount(6);
    for(int i=0;i<list.size();++i){
        Person *p=list[i];
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(p->getType()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(p->getName()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(p->getBirthday().toString("yyyy-MM-dd")));
        ui->tableWidget->setItem(i,3, new QTableWidgetItem(p->getPhone()));
        ui->tableWidget->setItem(i,4, new QTableWidgetItem(p->getEmail()));
        ui->tableWidget->setItem(i,5, new QTableWidgetItem(p->getExIn()));
    }
    ui->tableWidget->resizeColumnsToContents();
}
void ShowDialog::hideFindButton()
{
    ui->widget->hide();
    ui->pushButton_find->hide();
}
void ShowDialog::resetHeaderLabels(QString header){
    ui->tableWidget->setHorizontalHeaderLabels({ "类型","姓名", "出生日期", "电话", "Email",header});
}

void ShowDialog::onCheckBoxStateChanged(int state)
{
    // 从 MainWindow 获取完整数据
    MainWindow* mw = qobject_cast<MainWindow*>(this->parent());
    if (!mw) return;

    // 获取完整联系人列表
    QVector<Person*> filtered = classify(mw->getPersonList());   // 分类筛选
    setData(filtered);
}


QVector<Person*> ShowDialog::classify(QVector<Person*>list)
{
    QVector<Person*> displayed;

    if (ui->checkBox->isChecked())
    {
        for (const QString &type : {"同学", "同事", "朋友", "亲戚"})
        {
            for (Person* p : list)
            {
                if (p->getType() == type)
                    displayed.append(p);
            }
        }
    }
    else
    {
        displayed = list;  // 不筛选全部显示
    }
    return displayed;
}




void ShowDialog::on_pushButton_find_clicked()
{
    MainWindow* mw = qobject_cast<MainWindow*>(this->parent());
    if (!mw) return;
    QVector<Person*> filtered = classify(mw->getPersonList());   // 分类筛选

    setData(filtered);
}


