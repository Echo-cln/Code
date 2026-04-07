#include "registerdialog.h"
#include "ui_registerdialog.h"

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
registerDialog::registerDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
}

registerDialog::~registerDialog()
{
    delete ui;
}

//注册界面
void registerDialog::on_btn_logup_clicked()
{
    //检测注册信息是否合理
    QString username =ui->username->text().trimmed();
    QString password =ui->password->text();
    QString password_ensure =ui->password_ensure->text();
    if(username.isEmpty()||password.isEmpty()||password_ensure.isEmpty())
    {
        QMessageBox::warning(this,"错误","用户名和密码不能为空");
        return; //不继续执行后面的注册逻辑
    }
    if(password!=password_ensure)
    {
        QMessageBox::warning(this,"错误","两次密码输入应相同");
        return;
    }
    //数据库检测用户信息是否能成功录入
    QSqlQuery query_info;
    // 检查是否已存在该用户名
    query_info.prepare("SELECT username FROM users_info WHERE username = :username");
    query_info.bindValue(":username",username);
    if (!query_info.exec())
    {
        qDebug()<<"open failure!"<<query_info.lastError().text();
        QMessageBox::warning(this, "错误", "查询失败：");
        return;
    }
    if (query_info.next()) {
        QMessageBox::warning(this, "错误", "该用户名已存在");
        return;
    }
    // 写入新用户
    query_info.prepare("INSERT INTO users_info(username, password) VALUES(:username, :password)");
    query_info.bindValue(":username",username);
    query_info.bindValue(":password",password);
    if (!query_info.exec()) {
        QMessageBox::warning(this, "错误", "注册失败：" + query_info.lastError().text());
        return;
    }
    // 创建该用户的通讯录表（以用户名为后缀）
    QString tableName = QString("user_%1").arg(username);
    QString sqlCreate_user =
    QString(R"(CREATE TABLE IF NOT EXISTS %1 (
                id integer primary key autoincrement,
                类型 char(4),
                姓名 varchar(20),
                出生日期 date,
                电话 varchar(20),
                邮箱 varchar(50),
                附加信息 varchar(50)
            ))").arg(tableName);
    if (!query_info.exec(sqlCreate_user)) {
        QMessageBox::warning(this, "错误", "创建用户数据表失败：" + query_info.lastError().text());
        return;
    }

    QMessageBox::information(this, "成功", "注册成功！");
    this->accept();  //关闭对话窗口且exec()返回真值

}

void registerDialog::on_btn_cancel_clicked()
{
    close();  //可以关闭
}

