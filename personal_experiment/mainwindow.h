#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"page_login.h"
#include"person.h"

#include <QMainWindow>
#include<QTreeWidget>
#include<QVector>
#include<QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QVector<Person*> getPersonList(); //可在showdialog中调用p_List

    void on_pushButton_99_clicked(); //用于showdialog显示排序 但不调用额外窗口
public slots:
    void on_pushButton_2_clicked(); //修改联系人按钮
    void on_pushButton_3_clicked();  //添加联系人按钮
    void on_pushButton_4_clicked();  //删除联系人按钮
    void on_pushButton_5_clicked();  //查询联系人按钮
    void on_pushButton_9_clicked();  //按指定条件排序按钮
    //bool isWithinFiveDays(QDate today, QDate date);  //判断生日差值是否小于五天

private slots:
    void on_pushButton_clicked();  //主菜单右上角退出
    void on_pushButton_6_clicked();  //显示全体联系人按钮
    void on_pushButton_7_clicked(); //查询五日内过生日的同学信息
    void createFile(QVector<Person*>p,int cnt,QString name);

    void on_pushButton_8_clicked();  //查找指定月份出生的人


    void on_pushButton_10_clicked();  //写入文件按钮
    void saveToFile(QVector<Person*> list,QString filename);

    void on_pushButton_11_clicked();  //查询文件按钮
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column); //左侧树按钮

    void initialDatabase();//初始化数据库 作为成员函数

    void loadDatabaseForUser(QString username);  //链接p_List


private:
    Ui::MainWindow *ui;
    Page_login login_dlg;

    //存储全部联系人
    QVector<Person*> p_List;

    //创建数据库
    QSqlDatabase db;

    //当前用户名
    QString currentUsername;

};

#endif // MAINWINDOW_H
