#include "readfiledialog.h"
#include "ui_readfiledialog.h"

#include <QPushButton>
#include <QFileDialog>
#include <QFile>

readFileDialog::readFileDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::readFileDialog)
{
    ui->setupUi(this);
    //点击浏览按钮选取文件
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        QString path=QFileDialog::getOpenFileName(this,"打开文件","C:\\Users\\thinkbook\\Desktop\\Starey\\CS\\Qt\\Code\\personal_mg\\txt");
        ui->lineEdit->setText(path);
        QFile file(path);
        file.open(QIODevice::ReadOnly);
        QByteArray array= file.readAll();
        //文件数据类型转换成可读入
        ui->textEdit->setText(QString::fromUtf8(array));
    });
}

readFileDialog::~readFileDialog()
{
    delete ui;
}
