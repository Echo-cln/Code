#ifndef SHOWDIALOG_H
#define SHOWDIALOG_H

#include"person.h"
#include <QDialog>
#include<QVector>

namespace Ui {
class ShowDialog;
}

class ShowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowDialog(QWidget *parent = nullptr);
    ~ShowDialog();
    void hideFindButton();
    void setData(QVector<Person*> list);//数据表的数据显示
    void setData2(QVector<Person*> list); //分类的数据显示
    void resetHeaderLabels(QString header); //重新修改树控件的表头
    QVector<Person*> classify(QVector<Person*>list); //分类显示

private slots:


    void on_pushButton_find_clicked();

signals:

private:
    void onCheckBoxStateChanged(int state);

    QVector<Person*> p_List;  // 这里保存传过来的联系人列表
    Ui::ShowDialog *ui;

};

#endif // SHOWDIALOG_H
