#ifndef PAGE_LOGIN_H
#define PAGE_LOGIN_H

#include <QWidget>
#include <QString>
namespace Ui {
class Page_login;
}

class Page_login : public QWidget
{
    //启用信号与槽系统，必须用于包含 signals/slots 的类
    Q_OBJECT

public:
    explicit Page_login(QWidget *parent = nullptr);
    ~Page_login();

private slots:
    void on_btn_login_clicked();//登录按钮

    void on_btn_logup_clicked(); //注册按钮
signals:
    void sendLoginSuccess(QString username);

private:
    Ui::Page_login *ui;
};

#endif // PAGE_LOGIN_H
