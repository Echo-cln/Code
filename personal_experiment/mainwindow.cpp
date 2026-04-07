#include "mainwindow.h"
#include "person.h"
#include "person_factory.h"

#include "ui_mainwindow.h"
#include "addpersondialog.h"
#include "showdialog.h"

#include "readfiledialog.h"
#include<QMessageBox>
#include<QInputDialog>
#include<QMessageBox>
#include<QStringList>
#include<QFile>
#include<QTextStream>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    login_dlg.show();
    ui->treeWidget->clear();
    connect(&login_dlg, &Page_login::sendLoginSuccess, this, [=](QString username){
        this->loadDatabaseForUser(username);
        ui->label_username->setText(username);
        ui->treeWidget->header()->hide();
        this->show();
    });

    QStringList l;
    l<<"联系人显示分类";
    QTreeWidgetItem *pf=new QTreeWidgetItem(ui->treeWidget,l);
    l.clear();
    l<<"同学";
    QTreeWidgetItem *p1;
    p1=new QTreeWidgetItem(pf,l);
    l.clear();
    l<<"同事";
    p1=new QTreeWidgetItem(pf,l);
    ui->treeWidget->setColumnCount(1);
    l.clear();
    l<<"朋友";
    p1=new QTreeWidgetItem(pf,l);
    l.clear();
    l<<"亲戚";
    p1=new QTreeWidgetItem(pf,l);
    ui->treeWidget->expandAll();

    //数据库初始化
    initialDatabase();



}

MainWindow::~MainWindow()
{

    for(Person *p:p_List)
    {
        delete p;
        p=NULL;
    }
    delete ui;
}

//数据库初始化
void MainWindow::initialDatabase(){
    QSqlDatabase db =QSqlDatabase ::addDatabase("QSQLITE");
    //创建数据库 用于存储用户通讯录信息与用户登录信息
    db.setDatabaseName("Person_mg.db");
    if(!db.open())
    {
        qDebug()<<"Error faile to open"<<db.lastError().text();
    }
    else{
        qDebug()<<"open success!";
        //创建存储账户信息表
        QSqlQuery query_info;
        QString slqCreate_info=R"(CREATE TABLE IF NOT EXITS users_info(
                            username varchar(50) primary key,
                            password varchar(50)
                            ))";
        if(!query_info.exec(slqCreate_info))
        {
            qDebug()<<"Table create failed:"<<query_info.lastError().text();
        }

    }
}

void MainWindow::loadDatabaseForUser(QString username) {
    //确认用户通讯录信息表
    currentUsername = username;
    QString tableName = QString("user_%1").arg(username);
    p_List.clear();
    QSqlQuery query(QString("SELECT 类型, 姓名, 出生日期, 电话, 邮箱, 附加信息 FROM %1").arg(tableName));
    while (query.next()) {
        QString type =query.value(0).toString();
        QString name =query.value(1).toString();
        QDate birthday =QDate::fromString(query.value(2).toString(),"yyyy-MM-dd");
        QString phone=query.value(3).toString();
        QString email = query.value(4).toString();
        QString exIn = query.value(5).toString();
        Person *p = NULL;
        //导入数据至QVector容器
        if(type== "亲戚")
        {
            p =new Relative(name, birthday,phone, email, type,exIn);
        }
        else if (type == "朋友") {
            p = new Friend(name, birthday,phone, email, type,exIn);
        } else if (type == "同事") {
            p = new Colleague(name, birthday,phone, email, type,exIn);
        } else if (type == "同学") {
            p = new Schoolfellow(name, birthday,phone, email, type,exIn);
        }
        p_List.append(p);
    }
}

//主菜单右上角退出
void MainWindow::on_pushButton_clicked()
{
    exit(0);
}


//左侧树按钮  分别显示每一类的信息
void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem*item,int)
{
    loadDatabaseForUser(currentUsername);
    QString type =item->text(0);
    //根据不同类联系人定位
    if(type=="同学"||type=="同事"||type=="朋友"||type=="亲戚"){
        QVector<Person*> displayed;
        QString type_exIn;
        if(type=="同学"){type_exIn="学校名称"; }
        else if(type=="同事"){type_exIn="单位名称"; }
        else if(type=="朋友"){type_exIn="相识地点"; }
        else if(type=="亲戚"){type_exIn="称谓"; }
        for(Person *p:p_List){
            if(p->getType()==type){
                displayed.append(p);
            }
        }
        //创建显示联系人窗口
        ShowDialog *dlg=new ShowDialog(this);
        dlg->resetHeaderLabels(type_exIn);
        dlg->setWindowTitle(type+"信息");
        dlg->setData(displayed);
        dlg->hideFindButton();
        dlg->exec();
    }
}

//修改联系人
void MainWindow::on_pushButton_2_clicked()
{
    bool ok;
    //通过修改联系人的输入框对应修改联系人姓名
    QString name = QInputDialog::getText(this, "修改联系人", "请输入要修改的联系人姓名：", QLineEdit::Normal, "", &ok);
    if (!ok ){
        return;
    }
    bool found = false;
    for (int i = 0; i < p_List.size(); ++i) {
        Person *p = p_List[i];
        if (p->getName() == name) {
            found = true;
            //弹出修改联系人窗口并修改内容
            AddPersonDialog dlg(this);
            dlg.setWindowTitle("修改联系人");
            dlg.setData(p);
            if (dlg.exec() == QDialog::Accepted) {
                p = dlg.getData();
                QMessageBox::information(this, "修改成功", "联系人信息已修改！");
                //同时修改数据库中数据
                QSqlQuery query;
                query.prepare(QString(R"(UPDATE user_%1 SET 类型=?,电话=?,邮箱=?,
                                    附加信息=? WHERE 姓名=?)").arg(currentUsername));
                query.addBindValue(p->getType());
                query.addBindValue(p->getPhone());
                query.addBindValue(p->getEmail());
                query.addBindValue(p->getExIn());
                query.addBindValue(p->getName());
                if(!query.exec()){
                    qDebug()<<"Update failed:"<<query.lastError().text();
                    QMessageBox::warning(this,"修改失败","数据库更新失败！");
                }
                else{
                    loadDatabaseForUser(currentUsername);
                }

            }
        }

    }
    if (!found) {
        QMessageBox::warning(this, "未找到", "未找到该联系人！");
    }
}
//添加联系人按钮
void MainWindow::on_pushButton_3_clicked()
{
    //1.创建一个添加联系人对话框对象
    AddPersonDialog dlg(this);
    qDebug() << "添加联系人窗口打开";
    if(dlg.exec()==QDialog::Accepted){
        Person *p=dlg.getData();
        for(Person * pp:p_List){
            if(p->getName()==pp->getName()){
                QMessageBox::warning(this,"重复","该联系人已存在！");
                return;
            }
        }
        QMessageBox::information(this,"成功","已添加联系人");
        //2.将新增联系人信息写入数据库
        QSqlQuery query;
        query.prepare(QString("INSERT INTO user_%1(类型,姓名,出生日期,电话,邮箱,附加信息)"
                              "VALUES (?,?,?,?,?,?)").arg(currentUsername));
        query.addBindValue(p->getType());
        query.addBindValue(p->getName());
        query.addBindValue(p->getBirthday().toString("yyyy-MM-dd"));
        query.addBindValue(p->getPhone());
        query.addBindValue(p->getEmail());
        query.addBindValue(p->getExIn());
        if(!query.exec()){
            qDebug()<<"Insert failed:"<<query.lastError().text();
            QMessageBox::warning(this,"添加失败","添加到数据库失败！");
        }
        else{
            qDebug()<<"Insert success!";
            loadDatabaseForUser(currentUsername);
        }

    }
}

//删除联系人
void MainWindow::on_pushButton_4_clicked()
{
    bool ok;
    //通过输入框检验是否有匹配的用户信息
    QString name=QInputDialog::getText(this,"删除联系人","请输入需要删除的联系人姓名",QLineEdit::Normal, "", &ok);
    if(!ok){
        return ;
    }

     bool found=false;
    for(int i=0;i<p_List.size();i++){
        Person *p=p_List[i];
        if(p->getName()==name){
            found=true;
            int ret =QMessageBox::warning(this,"确认删除","确认要删除该联系人吗?",QMessageBox::Yes|QMessageBox::No);
            if(ret==QMessageBox::Yes){
                //同步删除数据库
                QSqlQuery query;
                query.prepare(QString("DELETE FROM user_%1 WHERE 姓名 = ?").arg(currentUsername));
                query.addBindValue(name);
                if(!query.exec()){
                    qDebug()<<"Delete failed:"<<query.lastError().text();
                    QMessageBox::warning(this,"删除","数据库删除失败!");

                }
                else{
                    loadDatabaseForUser(currentUsername);
                    break;
                }
            }
            else{
                QMessageBox::information(this,"取消删除","该联系人未删除.");
                break;
            }
        }
    }
    if(!found)
    {
        QMessageBox::information(this, "未找到联系人", "未找到该联系人！");
    }
}
//查询联系人按钮
void MainWindow::on_pushButton_5_clicked()
{
    bool ok;
    //通过输入框检验是否有匹配的用户信息
    QString name=QInputDialog::getText(this,"查询联系人","请输入联系人姓名",QLineEdit::Normal,"",&ok);
    if(!ok){
        return;
    }
    bool found =false;
    for (Person *p : p_List) {
        if (p->getName() == name) {
            found = true;
            QString exIn;
            if(p->getType()=="同学")
            {
                exIn="学校名称：";
            }else if(p->getType()=="同事")
            {
                exIn="单位名称：";
            }else if(p->getType()=="朋友")
            {
                exIn="相识地点：";
            }else if(p->getType()=="亲戚")
            {
                exIn="称呼：";
            }
            QString info = QString(
                               "类型：%1\n"
                               "姓名：%2\n"
                               "出生日期：%3\n"
                               "电话：%4\n"
                               "Email：%5\n"
                               ).arg(p->getType())
                               .arg(p->getName())
                               .arg(p->getBirthday().toString("yyyy-MM-dd"))
                               .arg(p->getPhone())
                               .arg(p->getEmail())
                ;
            info+=exIn+p->getExIn();
            //显示联系人基本信息
            QMessageBox::information(this, "联系人信息", info);
            break;
        }
    }
    if (!found) {
        QMessageBox::warning(this, "未找到", "未找到该联系人！");
    }
}
//显示全体联系人
void MainWindow::on_pushButton_6_clicked()
{
    //创建显示窗口
    ShowDialog * dlg=new ShowDialog(this);
    //重用showdialog中的自定义函数读入数据
    dlg->setData(p_List);
    dlg->exec();//弹出窗口
}
//可在showdialog中调用p_List
QVector<Person*> MainWindow::getPersonList()
{
    return p_List;
}

//查找指定月份出生的人
void MainWindow::on_pushButton_8_clicked()
{
    int cnt=0;
    bool ok;
    int month =QInputDialog::getInt(this,"查找指定月份","请输入一个月份数",0,1,12,1,&ok);
    if(!ok){
        return;
    }
    QVector<Person*> p;
    for(int i=0;i<p_List.size();i++){
        QDate date=p_List[i]->getBirthday();
        if(date.month()==month){
            p.append(p_List[i]);
            cnt++;
        }
    }
    QString text=QString("共有%1人在%2月出生").arg(cnt).arg(month);
    if(cnt){
        ShowDialog *dlg =new ShowDialog(this);
        dlg->setData(p);
        dlg->show();
    }
    //窗口显示人数
    QMessageBox::information(this,"统计人数",text);
}
//排序
void MainWindow::on_pushButton_9_clicked()
{
    bool ok;
    //选择排序方式、顺序
    QStringList items1;
    items1<<"姓名"<<"出生日期";
    QStringList items2;
    items2<<"升序"<<"降序";
    QString item1=QInputDialog::getItem(this,"选择条件","请选择一个排序条件",items1,0,false,&ok);
    if(ok){
        qDebug()<<"用户选择的项："<<item1;
    }else{
        qDebug()<<"用户取消了选择";
        return;
    }
    QString item2=QInputDialog::getItem(this,"选择条件","请选择一个排序方式",items2,0,false,&ok);
    if(ok){
        qDebug()<<"用户选择的项："<<item2;
    }else{
        qDebug()<<"用户取消了选择";
        return;
    }
    //按照姓名排序
    if(item1=="姓名"){
        if(item2=="升序"){
            std::sort(p_List.begin(),p_List.end(),[=](Person *a,Person *b){
                return a->getName()<b->getName();
            });
        }
        else{
            std::sort(p_List.begin(),p_List.end(),[=](Person *a,Person *b){
                return a->getName()>b->getName();
            });
        }
    }
    //按照出生日期排序
    else if(item1=="出生日期"){
        if(item2=="升序"){
            std::sort(p_List.begin(),p_List.end(),[=](Person *a,Person *b){
                return a->getBirthday()<b->getBirthday();
            });
        }
        else{
            std::sort(p_List.begin(),p_List.end(),[=](Person *a,Person *b){
                return a->getBirthday()>b->getBirthday();
            });
        }
    }
    on_pushButton_6_clicked();
}
void MainWindow::on_pushButton_99_clicked()
{
    bool ok;
    QStringList items1;
    items1<<"姓名"<<"出生日期";
    QStringList items2;
    items2<<"升序"<<"降序";
    QString item1=QInputDialog::getItem(this,"选择条件","请选择一个排序条件",items1,0,false,&ok);
    if(ok)
    {
        qDebug()<<"用户选择的项："<<item1;
    }else{
        qDebug()<<"用户取消了选择";
        return;
    }
    QString item2=QInputDialog::getItem(this,"选择条件","请选择一个排序方式",items2,0,false,&ok);
    if(ok)
    {
        qDebug()<<"用户选择的项："<<item2;
    }else{
        qDebug()<<"用户取消了选择";
        return;
    }
    if(item1=="姓名")
    {
        if(item2=="升序")
        {
            std::sort(p_List.begin(),p_List.end(),[=](Person *a,Person *b){
                return a->getName()<b->getName();
            });
        }
        else{
            std::sort(p_List.begin(),p_List.end(),[=](Person *a,Person *b){
                return a->getName()>b->getName();
            });
        }
    }
    else if(item1=="出生日期")
    {
        if(item2=="升序")
        {
            std::sort(p_List.begin(),p_List.end(),[=](Person *a,Person *b){
                return a->getBirthday()<b->getBirthday();
            });
        }
        else{
            std::sort(p_List.begin(),p_List.end(),[=](Person *a,Person *b){
                return a->getBirthday()>b->getBirthday();
            });
        }
    }

}
//写入文件
void MainWindow::on_pushButton_10_clicked()
{
    //按类存储
    QVector<Person*> schoolfellows;
    QVector<Person*> colleagues;
    QVector<Person*> friends;
    QVector<Person*> relatives;
    for(int i=0;i<p_List.size();i++){
        if(p_List[i]->getType()=="同学")
        {
            schoolfellows.append(p_List[i]);
        }
        else if(p_List[i]->getType()=="同事"){
            colleagues.append(p_List[i]);
        }
        else if(p_List[i]->getType()=="朋友")
        {
            friends.append(p_List[i]);
        }
        else if(p_List[i]->getType()=="亲戚")
        {
            relatives.append(p_List[i]);
        }
    }
    //自定义存储函数
    saveToFile(schoolfellows,"C:\\Users\\thinkbook\\Desktop\\Starey\\CS\\Qt\\Code\\personal_mg\\txt\\AddressBook1.txt");
    saveToFile(colleagues,"C:\\Users\\thinkbook\\Desktop\\Starey\\CS\\Qt\\Code\\personal_mg\\txt\\AddressBook2.txt");
    saveToFile(friends,"C:\\Users\\thinkbook\\Desktop\\Starey\\CS\\Qt\\Code\\personal_mg\\txt\\AddressBook3.txt");
    saveToFile(relatives,"C:\\Users\\thinkbook\\Desktop\\Starey\\CS\\Qt\\Code\\personal_mg\\txt\\AddressBook4.txt");
    QMessageBox::information(this,"保存成功","联系人已成功保存到文件！");
}

void MainWindow::saveToFile(QVector<Person*> list,QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text)){
        qDebug()<<"无法打开文件"<<filename;
    }
    QTextStream out(&file);
    //写入表头
    out << qSetFieldWidth(10) << "类型" << qSetFieldWidth(0)
        << qSetFieldWidth(15) << "姓名" << qSetFieldWidth(0)
        << qSetFieldWidth(15) << "出生日期" << qSetFieldWidth(0)
        << qSetFieldWidth(15) << "电话" << qSetFieldWidth(0)
        << qSetFieldWidth(20) << "邮箱" << qSetFieldWidth(0)
        << qSetFieldWidth(40) << "附加信息" << qSetFieldWidth(0) << "\n";
     //将数据写入文件
    for(Person* p:list){
        out << qSetFieldWidth(10) << p->getType() << qSetFieldWidth(0)
            << qSetFieldWidth(15) << p->getName() << qSetFieldWidth(0)
            << qSetFieldWidth(15) << p->getBirthday().toString("yyyy-MM-dd") << qSetFieldWidth(0)
            << qSetFieldWidth(15) << p->getPhone() << qSetFieldWidth(0)
            << qSetFieldWidth(20) << p->getEmail() << qSetFieldWidth(0)
            << qSetFieldWidth(40) << p->getExIn() << qSetFieldWidth(0) << "\n";
    }
    file.close();
}
//替代
// bool MainWindow::isWithinFiveDays(QDate today, QDate date) {
//     int y1 = today.year(), m1 = today.month(), d1 = today.day();
//     int y2 = date.year(), m2 = date.month(), d2 = date.day();
//     if (y1 == y2 && m1 == m2) {
//         return (d2 - d1) >= 0 && (d2 - d1) <= 5;
//     }
//     int nextMonth=m1+1;
//     int Year=y1;
//     if (nextMonth>12){
//         nextMonth=1;
//         Year+=1;
//     }
//     if (y2 == Year && m2 == nextMonth) {
//         const int Month[] = {31,28,31,30,31,30,31,31,30,31,30,31 };
//         int currMonth = Month[m1 - 1];
//         if (m1==2&&((y1%4==0 && y1%100!= 0)||(y1% 400==0))) {
//             currMonth = 29;
//         }
//         int leftDays = currMonth - d1;
//         int total = leftDays + d2;
//         return total <= 5;
//     }
//     return false;
// }
// void MainWindow::on_pushButton_7_clicked()
// {
//     QDate currentDate = QDate::currentDate();
//     QVector<Person*> p;
//     ShowDialog *dlg = new ShowDialog(this);

//     for (Person* person : p_List) {
//         if (isWithinFiveDays(currentDate, person->getBirthday())) {
//             p.append(person);
//         }
//     }
//     dlg->setData(p);
//     dlg->show();
// }

//生成祝福文件
void MainWindow::on_pushButton_7_clicked()
{
    QDate currentdate= QDate::currentDate();
    QVector<Person*> p;
    ShowDialog *dlg =new ShowDialog(this);

    for(int i=0; i<p_List.size();i++)
    {
        bool gap=(p_List[i]->getBirthday()>=currentdate&&p_List[i]->getBirthday()<=currentdate.addDays(5));
        if(gap)
        {
            p.append(p_List[i]);

        }
    }
    if(p.size()){
        dlg->hideFindButton();
        dlg->setData(p);
        dlg->show();

        QStringList items;
        bool ok1;
        items<<"指定一个落款"<<"指定多个落款";
        QString item1=QInputDialog::getItem(this,"选择条件","请选择一个排序条件",items,0,false,&ok1);
        if(!ok1){
            return;
        }
        if(item1=="指定一个落款"){
            bool ok2;
            QString name= QInputDialog::getText(this,"祝福人姓名","请输入祝福人姓名",QLineEdit::Normal, "", &ok2);
            if(!ok2){
                return;
            }
            for(int i=0;i<p.size();i++){
                createFile(p,i,name);
            }
        }
        else{
            for(int i=0;i<p.size();i++){
                bool ok3;
                QString name= QInputDialog::getText(this,"祝福人姓名","请输入祝福人姓名",QLineEdit::Normal, "", &ok3);
                if(!ok3){
                    return;
                }
                createFile(p,i,name);
            }
        }
        QMessageBox::information(this,"生成成功","祝福文件已自动生成！");
    }else{
        QMessageBox::information(this,"生成取消","五天内无人过生日。");
    }

}

void MainWindow::createFile(QVector<Person*>p,int cnt,QString name)
{
    QString filename=QString("C:\\Users\\thinkbook\\Desktop\\Starey\\CS\\Qt\\Code\\personal_mg\\txt\\Congratulation%1.txt").arg(cnt);
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        qDebug()<<"无法打开文件"<<filename;
    }
    QTextStream ost(&file);
    ost<<p[cnt]->getName()<<"："<<"\n"
        <<"\t祝生日快乐，健康幸福！\n"
        <<"\t\t\t"<<name;
}


//查询文件按钮
void MainWindow::on_pushButton_11_clicked()
{
    readFileDialog dlg(this);
    qDebug() << "查询文件窗口打开";
    dlg.exec();
}
