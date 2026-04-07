#include "page_login.h"
#include "ui_page_login.h"
#include "registerdialog.h"

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
Page_login::Page_login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Page_login)
{
    ui->setupUi(this);
}

Page_login::~Page_login()
{
    delete ui;
}
//登录按钮
void Page_login::on_btn_login_clicked()
{
    //检验信息是否完善
    QString username =ui->username->text().trimmed();
    QString password =ui->password->text();
    if(username.isEmpty()||password.isEmpty()){
        QMessageBox::warning(this,"错误","用户名和密码不能为空");
        return;
    }
    //数据库匹配用户信息
    QSqlQuery query;
    query.prepare("SELECT password FROM users_info WHERE username = :username");
    query.bindValue(":username",username);
    if (!query.exec())
    {
        qDebug()<<"open failure!"<<query.lastError().text();
        QMessageBox::warning(this, "错误", "查询失败：");
        return;
    }
    if (!query.next()) {
        QMessageBox::warning(this, "错误", "用户不存在");
        return;
    }
    QString storedPw = query.value("password").toString();
    if (storedPw != password) {
        QMessageBox::warning(this, "错误", "密码错误");
        return;
    }
    //登录成功，传递用户名给 MainWindow
    QMessageBox::information(this, "登录成功", "欢迎，" + username);
    emit sendLoginSuccess(username);
    this->close();
}

//注册按钮
void Page_login::on_btn_logup_clicked()
{
    //在栈上创建注册对话框
    registerDialog dlg(this);
    if (dlg.exec() == QDialog::Accepted) {
        qDebug()<<"注册界面打开";
        QMessageBox::information(this, "提示", "注册成功，请登录！");
    }
}

