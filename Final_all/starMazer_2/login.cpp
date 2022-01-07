#include "login.h"
#include "ui_login.h"
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QStandardItem>

Login::Login(QWidget *parent): QWidget(parent), ui(new Ui::Login)
{
    ui->setupUi(this);

    //数据库的表
    model = new QSqlTableModel(this);
    model->setTable("student");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select(); //选取整个表的所有行
    ui->tableView->setModel(model);

    //linetext提示语
    QLineEdit *pLineEdit = ui->username;
    pLineEdit->setPlaceholderText(QStringLiteral("请输入用户名"));
    QPalette palette = pLineEdit->palette();
    palette.setColor(QPalette::Normal, QPalette::PlaceholderText, Qt::gray);
    pLineEdit->setPalette(palette);

    QLineEdit *pLineEdit2 = ui->password;
    pLineEdit2->setPlaceholderText(QStringLiteral("请输入密码"));
    QPalette palette2 = pLineEdit2->palette();
    palette2.setColor(QPalette::Normal, QPalette::PlaceholderText, Qt::gray);
    pLineEdit2->setPalette(palette2);

    //设置注册按钮
    ui->registerButton->setStyleSheet("border:none;border-radius:10px;");
    ui->registerButton->setIcon(QIcon(QString("E://uiProject//buttonRegis.png")));
    ui->registerButton->setIconSize(QSize(300, 300));

    //设置登录按钮
    ui->loginButton->setStyleSheet("border:none;border-radius:10px;");
    ui->loginButton->setIcon(QIcon(QString("E://uiProject//buttonLoginBlack.png")));
    ui->loginButton->setIconSize(QSize(300, 300));
}

Login::~Login()
{
    delete ui;
}


void Login::on_loginButton_clicked()
{
    model->setTable("student");   //重新关联表
    model->select();   //这样才能再次显示整个表的内容
    {
        //获取登录界面的用户名字和密码
        username = ui->username->text();
        QString password=ui->password->text();

        //表中筛选对应用户
        model->setFilter(QString("password = '%1' and userName = '%2'").arg(password).arg(username));
        model->select(); //显示结果
        //获得表的行数
        int rowNum = model->rowCount();
        //利用表的行数确定，是否找到用户对应的密码
        if(rowNum==1)
        {
            QMessageBox::information(this,QStringLiteral("登录情况"),QStringLiteral("登录成功"));
        }
        else
        {
            QMessageBox::critical(this,QStringLiteral("登录情况"),QStringLiteral("密码不正确！"));
        }
    }
    model->setTable("student");   //重新关联表
    model->select();   //这样才能再次显示整个表的内容
}

void Login::on_registerButton_clicked()
{
    //跳转到注册界面
    regi = new regis;
    regi->show();
}

/*
函数名：sort()
参数：
功能：排序成绩
返回值：
*/
void Login::sort(int column)
{
    int rowNum = model->rowCount();
    int num[100];
    model->setSort(column,Qt::DescendingOrder);
    model->select();
    for(int i=0;i<rowNum;i++){
        num[i]=model->data(model->index(i,1)).toInt();
    }
}

/*
函数名：delect()
参数：无
功能：删除选定行数
返回值：无
*/
void Login::delect()
{
    //选定要删除的行数（注意对应行-1）
    int curRow = 3;
    //获取选中的行
    model->removeRow(curRow);
    //删除该行
    int ok = QMessageBox::warning(this,tr("删除当前行!"),tr("你确定删除当前行吗？"),QMessageBox::Yes,QMessageBox::No);
    if(ok == QMessageBox::No)
    {
        model->revertAll(); //如果不删除，则撤销
    }
    else model->submitAll(); //否则提交，在数据库中删除该行
    //重新显示修改后的表
    model->setTable("student");   //重新关联表
    model->select();   //这样才能再次显示整个表的内容

}

//0，1，2（第一关成绩），3，4，5（第四关成绩），6（第一个成就），7，8，9，10，11，12，13，14，15（第五个成就）
int Login::getInformation(int column){
    int num=model->data(model->index(userColumn(),column)).toInt();
    return num;
}

//column对应第几关成绩or第几个成就
void Login::changeInformation(int column,int num){
    model->setData(model->index(userColumn(),column),num);
}

//获取对应用户名的某行
int Login::userColumn(){
    int rowNum = model->rowCount();
    QString user;
    int count=0;
    for(int i=0;i<rowNum;i++){
        user=model->data(model->index(i,1)).toString();
        if(user==username){
            break;
        }
        count++;
    }
    return count;
}

void Login::on_registerButton_pressed(){
    //设置注册按钮
    ui->registerButton->setStyleSheet("border:none;border-radius:10px;");
    ui->registerButton->setIcon(QIcon(QString("E://uiProject//buttonRegisPressed.png")));
    ui->registerButton->setIconSize(QSize(300, 300));
}

void Login::on_registerButton_released(){
    //设置注册按钮
    ui->registerButton->setStyleSheet("border:none;border-radius:10px;");
    ui->registerButton->setIcon(QIcon(QString("E://uiProject//buttonRegis.png")));
    ui->registerButton->setIconSize(QSize(300, 300));
}



void Login::on_loginButton_pressed(){
    //设置登录按钮
    ui->loginButton->setStyleSheet("border:none;border-radius:10px;");
    ui->loginButton->setIcon(QIcon(QString("E://uiProject//buttonLoginWhite.png")));
    ui->loginButton->setIconSize(QSize(300, 300));
}

void Login::on_loginButton_released(){
    //设置登录按钮
    ui->loginButton->setStyleSheet("border:none;border-radius:10px;");
    ui->loginButton->setIcon(QIcon(QString("E://uiProject//buttonLoginBlack.png")));
    ui->loginButton->setIconSize(QSize(300, 300));
}
