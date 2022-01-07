#include "regis.h"
#include "ui_regis.h"
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>

Regis::Regis(QWidget *parent) :QWidget(parent),ui(new Ui::Regis){
    ui->setupUi(this);

    //背景图自适应label大小
    QPalette PAllbackground = this->palette();
    QImage ImgAllbackground("E://uiProject//Login//regisBackground.png");
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
    QLineEdit *pLineEdit = ui->regisUsername;
    pLineEdit->setPlaceholderText(QString::fromLocal8Bit("请输入用户名"));
    QPalette *pal = new QPalette();
    pal->setColor(QPalette::Normal, QPalette::PlaceholderText, Qt::gray);
    pLineEdit->setPalette(*pal);

    ui->regisPassword1->setPlaceholderText(QString::fromLocal8Bit("请输入密码"));
    QPalette * palette2 = new QPalette();
    palette2->setColor(QPalette::Normal, QPalette::PlaceholderText, Qt::gray);
    ui->regisPassword1->setPalette(*palette2);

    ui->regisPassword2->setPlaceholderText(QString::fromLocal8Bit("请再次输入密码"));
    QPalette * palette3 = new QPalette();
    palette3->setColor(QPalette::Normal, QPalette::PlaceholderText, Qt::gray);
    ui->regisPassword2->setPalette(*palette3);
}

Regis::~Regis(){
    delete ui;
}

/*
函数名：on_confirm_clicked()
参数：无
功能：注册界面，将用户信息导入数据库
返回值：无
*/
void Regis::on_confirm_clicked(){
    //插入表，数据库
    int rowNum = model->rowCount(); //获得表的行数
    //获取lineEdit的文本
    QString username = ui->regisUsername->text();
    QString password=ui->regisPassword1->text();
    QString password1=ui->regisPassword1->text();
    QString password2=ui->regisPassword2->text();
    //此处插入用户信息：用户名，密码，成绩
    int score = 0;//初始化的成绩
    //报错
    if(username==""||password=="")
        QMessageBox::warning(this,QString::fromLocal8Bit("注册失败"),QString::fromLocal8Bit("输入内容不能为空"));

    else if(password1!=password2)
        QMessageBox::warning(this,QString::fromLocal8Bit("注册失败"),QString::fromLocal8Bit("两次输入的密码不相同"));
    else{
        model->insertRow(rowNum); //添加一行
        //此处修改插入值（用于保存成绩，注册用户信息）
        model->setData(model->index(rowNum,2),score);//设定值，注意score设在第三列
        model->setData(model->index(rowNum,1),username);
        model->setData(model->index(rowNum,0),password);//密码在表中不显示，隐藏

        //保存修改
        model->database().transaction(); //开始事务操作
        if (model->submitAll())
            model->database().commit(); //提交
        else {
            model->database().rollback(); //回滚
            QMessageBox::warning(this, tr("tableModel"),tr("数据库错误: %1").arg(model->lastError().text()));
        }
        QMessageBox::information(this,"注册情况","注册成功");
    }
}

/*
函数名：on_cancel_clicked()
参数：无
功能：退出当前界面
返回值：无
*/
void Regis::on_cancel_clicked(){
    this->close();
}
