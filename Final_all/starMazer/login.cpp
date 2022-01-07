#include "login.h"
#include "ui_login.h"
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QString>
#include <qstring.h>

Login::Login(QWidget *parent): QWidget(parent), ui(new Ui::Login){
    ui->setupUi(this);

    QPalette PAllbackground = this->palette();
    QImage ImgAllbackground("E://uiProject//Login//loginBackground.png");
    QImage fitimgpic=ImgAllbackground.scaled(this->width(),this->height(), Qt::IgnoreAspectRatio);
    PAllbackground.setBrush(QPalette::Window, QBrush(fitimgpic));
    this->setPalette(PAllbackground);

    //数据库的表
    model = new QSqlTableModel(this);
    model->setTable("student");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select(); //选取整个表的所有行
    ui->tableView->setModel(model);


    //linetext提示语
    ui->username->setPlaceholderText(QString::fromLocal8Bit("请输入用户名"));
    QPalette* pal = new QPalette();
    pal->setColor(QPalette::Normal, QPalette::PlaceholderText, Qt::gray);
    ui->username->setPalette(*pal);

    ui->password->setPlaceholderText(QString::fromLocal8Bit("请输入密码"));
    QPalette * palette2 = new QPalette();
    palette2->setColor(QPalette::Normal, QPalette::PlaceholderText, Qt::gray);
    ui->password->setPalette(*palette2);
}

Login::~Login(){
    delete ui;
}


void Login::on_loginButton_clicked(){
    model->setTable("student");   //重新关联表
    model->select();{   //这样才能再次显示整个表的内容

        //获取登录界面的用户名字和密码
        QString username = ui->username->text();
        QString password=ui->password->text();

        //表中筛选对应用户
        model->setFilter(QString("password = '%1' and userName = '%2'").arg(password).arg(username));
        model->select(); //显示结果
        //获得表的行数
        int rowNum = model->rowCount();
        //利用表的行数确定，是否找到用户对应的密码
        if(rowNum==1)
            QMessageBox::information(this,QString::fromLocal8Bit("登录情况"),QString::fromLocal8Bit("登录成功"));
        else
            QMessageBox::critical(this,QString::fromLocal8Bit("登录情况"),QString::fromLocal8Bit("密码不正确！"));
    }
}

void Login::on_registerButton_clicked(){
    //跳转到注册界面
        regi = new Regis;
        regi->show();
}

/*
函数名：sort()
参数：
功能：排序成绩
返回值：
*/
void Login::sort(){
    model->setSort(2,Qt::DescendingOrder);
    model->select();
}

/*
函数名：delect()
参数：无
功能：删除选定行数
返回值：无
*/
void Login::delect(){
    //选定要删除的行数（注意对应行-1）
    int curRow = 3;
    //获取选中的行
    model->removeRow(curRow);
    //删除该行
    int ok = QMessageBox::warning(this,tr("删除当前行!"),tr("你确定删除当前行吗？"),QMessageBox::Yes,QMessageBox::No);
    if(ok == QMessageBox::No)
        model->revertAll(); //如果不删除，则撤销
    else model->submitAll(); //否则提交，在数据库中删除该行
    //重新显示修改后的表
    model->setTable("student");   //重新关联表
    model->select();   //这样才能再次显示整个表的内容
}
