#include "regis.h"
#include "ui_regis.h"
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>

regis::regis(QWidget *parent) :QWidget(parent),ui(new Ui::regis){
    ui->setupUi(this);

    //数据库的表
    model = new QSqlTableModel(this);
    model->setTable("student");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select(); //选取整个表的所有行
    ui->tableView->setModel(model);

    //linetext提示语
    QLineEdit *pLineEdit = ui->regisUsername;
    pLineEdit->setPlaceholderText(QStringLiteral("请输入用户名"));
    QPalette palette = pLineEdit->palette();
    palette.setColor(QPalette::Normal, QPalette::PlaceholderText, Qt::gray);
    pLineEdit->setPalette(palette);

    QLineEdit *pLineEdit2 = ui->regisPassword1;
    pLineEdit2->setPlaceholderText(QStringLiteral("请输入密码"));
    QPalette palette2 = pLineEdit2->palette();
    palette2.setColor(QPalette::Normal, QPalette::PlaceholderText, Qt::gray);
    pLineEdit2->setPalette(palette2);

    QLineEdit *pLineEdit3 = ui->regisPassword2;
    pLineEdit3->setPlaceholderText(QStringLiteral("请再次输入密码"));
    QPalette palette3 = pLineEdit3->palette();
    palette3.setColor(QPalette::Normal, QPalette::PlaceholderText, Qt::gray);
    pLineEdit3->setPalette(palette3);

    //设置确认按钮
    ui->confirm->setStyleSheet("border:none;border-radius:10px;");
    ui->confirm->setIcon(QIcon(QString("E://uiProject//confirmButtonBlack.png")));
    ui->confirm->setIconSize(QSize(300, 300));

    //设置取消按钮
    ui->cancel->setStyleSheet("border:none;border-radius:10px;");
    ui->cancel->setIcon(QIcon(QString("E://uiProject//cancelButtonBlack.png")));
    ui->cancel->setIconSize(QSize(300, 300));

    //设置head1按钮
    ui->head1->setStyleSheet("border:none;border-radius:10px;");
    ui->head1->setIcon(QIcon(QString("E://uiProject//head1.png")));
    ui->head1->setIconSize(QSize(100, 100));

    //设置head2按钮
    ui->head2->setStyleSheet("border:none;border-radius:10px;");
    ui->head2->setIcon(QIcon(QString("E://uiProject//head2.png")));
    ui->head2->setIconSize(QSize(100, 100));

    //设置head3按钮
    ui->head3->setStyleSheet("border:none;border-radius:10px;");
    ui->head3->setIcon(QIcon(QString("E://uiProject//head3.png")));
    ui->head3->setIconSize(QSize(100, 100));


    //设置head4按钮
    ui->head4->setStyleSheet("border:none;border-radius:10px;");
    ui->head4->setIcon(QIcon(QString("E://uiProject//head4.png")));
    ui->head4->setIconSize(QSize(100, 100));

    //设置head5按钮
    ui->head5->setStyleSheet("border:none;border-radius:10px;");
    ui->head5->setIcon(QIcon(QString("E://uiProject//head5.png")));
    ui->head5->setIconSize(QSize(100, 100));

    //设置head6按钮
    ui->head6->setStyleSheet("border:none;border-radius:10px;");
    ui->head6->setIcon(QIcon(QString("E://uiProject//head6.png")));
    ui->head6->setIconSize(QSize(100, 100));
}

regis::~regis(){
    delete ui;
}

/*
函数名：on_confirm_clicked()
参数：无
功能：注册界面，将用户信息导入数据库
返回值：无
*/
void regis::on_confirm_clicked(){
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
    if(username==""||password==""){
        QMessageBox::warning(this,QStringLiteral("注册失败"),QStringLiteral("输入内容不能为空"));
    }
    else if(password1!=password2){
        QMessageBox::warning(this,QStringLiteral("注册失败"),QStringLiteral("两次输入的密码不相同"));
    }
    else{
        model->insertRow(rowNum); //添加一行
        //此处修改插入值（用于保存成绩，注册用户信息）
        //model->setData(model->index(rowNum,2),score);//设定值，注意score设在第三列
        model->setData(model->index(rowNum,1),username);
        model->setData(model->index(rowNum,0),password);//密码在表中不显示，隐藏

        for(int i=2;i<15;i++){
            model->setData(model->index(rowNum,i),0);
        }

        model->setData(model->index(rowNum,15),head);

        //保存修改
        model->database().transaction(); //开始事务操作
        if (model->submitAll()) {
            model->database().commit(); //提交
        }else{
            model->database().rollback(); //回滚
            QMessageBox::warning(this, tr("tableModel"),tr("数据库错误: %1").arg(model->lastError().text()));
        }
        QMessageBox::information(this,QStringLiteral("注册情况"),QStringLiteral("注册成功"));
        this->~regis();
    }
}

/*
函数名：on_cancel_clicked()
参数：无
功能：退出当前界面
返回值：无
*/
void regis::on_cancel_clicked(){
    this->close();
}

void regis::on_head1_clicked(){
    head=1;
    //设置head1按钮
    ui->head1->setStyleSheet("border:none;border-radius:10px;");
    ui->head1->setIcon(QIcon(QString("E://uiProject//head1R.png")));
    ui->head1->setIconSize(QSize(100, 100));

    //设置head2按钮
    ui->head2->setStyleSheet("border:none;border-radius:10px;");
    ui->head2->setIcon(QIcon(QString("E://uiProject//head2.png")));
    ui->head2->setIconSize(QSize(100, 100));

    //设置head3按钮
    ui->head3->setStyleSheet("border:none;border-radius:10px;");
    ui->head3->setIcon(QIcon(QString("E://uiProject//head3.png")));
    ui->head3->setIconSize(QSize(100, 100));


    //设置head4按钮
    ui->head4->setStyleSheet("border:none;border-radius:10px;");
    ui->head4->setIcon(QIcon(QString("E://uiProject//head4.png")));
    ui->head4->setIconSize(QSize(100, 100));

    //设置head5按钮
    ui->head5->setStyleSheet("border:none;border-radius:10px;");
    ui->head5->setIcon(QIcon(QString("E://uiProject//head5.png")));
    ui->head5->setIconSize(QSize(100, 100));

    //设置head6按钮
    ui->head6->setStyleSheet("border:none;border-radius:10px;");
    ui->head6->setIcon(QIcon(QString("E://uiProject//head6.png")));
    ui->head6->setIconSize(QSize(100, 100));
}

void regis::on_head2_clicked(){
    head=2;
    //设置head1按钮
    ui->head1->setStyleSheet("border:none;border-radius:10px;");
    ui->head1->setIcon(QIcon(QString("E://uiProject//head1.png")));
    ui->head1->setIconSize(QSize(100, 100));

    //设置head2按钮
    ui->head2->setStyleSheet("border:none;border-radius:10px;");
    ui->head2->setIcon(QIcon(QString("E://uiProject//head2R.png")));
    ui->head2->setIconSize(QSize(100, 100));

    //设置head3按钮
    ui->head3->setStyleSheet("border:none;border-radius:10px;");
    ui->head3->setIcon(QIcon(QString("E://uiProject//head3.png")));
    ui->head3->setIconSize(QSize(100, 100));


    //设置head4按钮
    ui->head4->setStyleSheet("border:none;border-radius:10px;");
    ui->head4->setIcon(QIcon(QString("E://uiProject//head4.png")));
    ui->head4->setIconSize(QSize(100, 100));

    //设置head5按钮
    ui->head5->setStyleSheet("border:none;border-radius:10px;");
    ui->head5->setIcon(QIcon(QString("E://uiProject//head5.png")));
    ui->head5->setIconSize(QSize(100, 100));

    //设置head6按钮
    ui->head6->setStyleSheet("border:none;border-radius:10px;");
    ui->head6->setIcon(QIcon(QString("E://uiProject//head6.png")));
    ui->head6->setIconSize(QSize(100, 100));
}

void regis::on_head3_clicked(){
    head=3;

    //设置head1按钮
    ui->head1->setStyleSheet("border:none;border-radius:10px;");
    ui->head1->setIcon(QIcon(QString("E://uiProject//head1.png")));
    ui->head1->setIconSize(QSize(100, 100));

    //设置head2按钮
    ui->head2->setStyleSheet("border:none;border-radius:10px;");
    ui->head2->setIcon(QIcon(QString("E://uiProject//head2.png")));
    ui->head2->setIconSize(QSize(100, 100));

    //设置head3按钮
    ui->head3->setStyleSheet("border:none;border-radius:10px;");
    ui->head3->setIcon(QIcon(QString("E://uiProject//head3R.png")));
    ui->head3->setIconSize(QSize(100, 100));


    //设置head4按钮
    ui->head4->setStyleSheet("border:none;border-radius:10px;");
    ui->head4->setIcon(QIcon(QString("E://uiProject//head4.png")));
    ui->head4->setIconSize(QSize(100, 100));

    //设置head5按钮
    ui->head5->setStyleSheet("border:none;border-radius:10px;");
    ui->head5->setIcon(QIcon(QString("E://uiProject//head5.png")));
    ui->head5->setIconSize(QSize(100, 100));

    //设置head6按钮
    ui->head6->setStyleSheet("border:none;border-radius:10px;");
    ui->head6->setIcon(QIcon(QString("E://uiProject//head6.png")));
    ui->head6->setIconSize(QSize(100, 100));
}

void regis::on_head4_clicked(){
    head=4;

    //设置head1按钮
    ui->head1->setStyleSheet("border:none;border-radius:10px;");
    ui->head1->setIcon(QIcon(QString("E://uiProject//head1.png")));
    ui->head1->setIconSize(QSize(100, 100));

    //设置head2按钮
    ui->head2->setStyleSheet("border:none;border-radius:10px;");
    ui->head2->setIcon(QIcon(QString("E://uiProject//head2.png")));
    ui->head2->setIconSize(QSize(100, 100));

    //设置head3按钮
    ui->head3->setStyleSheet("border:none;border-radius:10px;");
    ui->head3->setIcon(QIcon(QString("E://uiProject//head3.png")));
    ui->head3->setIconSize(QSize(100, 100));


    //设置head4按钮
    ui->head4->setStyleSheet("border:none;border-radius:10px;");
    ui->head4->setIcon(QIcon(QString("E://uiProject//head4R.png")));
    ui->head4->setIconSize(QSize(100, 100));

    //设置head5按钮
    ui->head5->setStyleSheet("border:none;border-radius:10px;");
    ui->head5->setIcon(QIcon(QString("E://uiProject//head5.png")));
    ui->head5->setIconSize(QSize(100, 100));

    //设置head6按钮
    ui->head6->setStyleSheet("border:none;border-radius:10px;");
    ui->head6->setIcon(QIcon(QString("E://uiProject//head6.png")));
    ui->head6->setIconSize(QSize(100, 100));
}

void regis::on_head5_clicked(){
    head=5;

    //设置head1按钮
    ui->head1->setStyleSheet("border:none;border-radius:10px;");
    ui->head1->setIcon(QIcon(QString("E://uiProject//head1.png")));
    ui->head1->setIconSize(QSize(100, 100));

    //设置head2按钮
    ui->head2->setStyleSheet("border:none;border-radius:10px;");
    ui->head2->setIcon(QIcon(QString("E://uiProject//head2.png")));
    ui->head2->setIconSize(QSize(100, 100));

    //设置head3按钮
    ui->head3->setStyleSheet("border:none;border-radius:10px;");
    ui->head3->setIcon(QIcon(QString("E://uiProject//head3.png")));
    ui->head3->setIconSize(QSize(100, 100));


    //设置head4按钮
    ui->head4->setStyleSheet("border:none;border-radius:10px;");
    ui->head4->setIcon(QIcon(QString("E://uiProject//head4.png")));
    ui->head4->setIconSize(QSize(100, 100));

    //设置head5按钮
    ui->head5->setStyleSheet("border:none;border-radius:10px;");
    ui->head5->setIcon(QIcon(QString("E://uiProject//head5R.png")));
    ui->head5->setIconSize(QSize(100, 100));

    //设置head6按钮
    ui->head6->setStyleSheet("border:none;border-radius:10px;");
    ui->head6->setIcon(QIcon(QString("E://uiProject//head6.png")));
    ui->head6->setIconSize(QSize(100, 100));
}

void regis::on_head6_clicked(){
    head=6;

    //设置head1按钮
    ui->head1->setStyleSheet("border:none;border-radius:10px;");
    ui->head1->setIcon(QIcon(QString("E://uiProject//head1.png")));
    ui->head1->setIconSize(QSize(100, 100));

    //设置head2按钮
    ui->head2->setStyleSheet("border:none;border-radius:10px;");
    ui->head2->setIcon(QIcon(QString("E://uiProject//head2.png")));
    ui->head2->setIconSize(QSize(100, 100));

    //设置head3按钮
    ui->head3->setStyleSheet("border:none;border-radius:10px;");
    ui->head3->setIcon(QIcon(QString("E://uiProject//head3.png")));
    ui->head3->setIconSize(QSize(100, 100));


    //设置head4按钮
    ui->head4->setStyleSheet("border:none;border-radius:10px;");
    ui->head4->setIcon(QIcon(QString("E://uiProject//head4.png")));
    ui->head4->setIconSize(QSize(100, 100));

    //设置head5按钮
    ui->head5->setStyleSheet("border:none;border-radius:10px;");
    ui->head5->setIcon(QIcon(QString("E://uiProject//head5.png")));
    ui->head5->setIconSize(QSize(100, 100));

    //设置head6按钮
    ui->head6->setStyleSheet("border:none;border-radius:10px;");
    ui->head6->setIcon(QIcon(QString("E://uiProject//head6R.png")));
    ui->head6->setIconSize(QSize(100, 100));
}

void regis::on_confirm_pressed(){
    //设置确认按钮
    ui->confirm->setStyleSheet("border:none;border-radius:10px;");
    ui->confirm->setIcon(QIcon(QString("E://uiProject//confirmButtonWhite.png")));
    ui->confirm->setIconSize(QSize(300, 300));
}

void regis::on_confirm_released(){
    //设置确认按钮
    ui->confirm->setStyleSheet("border:none;border-radius:10px;");
    ui->confirm->setIcon(QIcon(QString("E://uiProject//confirmButtonBlack.png")));
    ui->confirm->setIconSize(QSize(300, 300));
}

void regis::on_cancel_pressed(){
    //设置取消按钮
    ui->cancel->setStyleSheet("border:none;border-radius:10px;");
    ui->cancel->setIcon(QIcon(QString("E://uiProject//cancelButtonWhite.png")));
    ui->cancel->setIconSize(QSize(300, 300));
}

void regis::on_cancel_released(){
    //设置取消按钮
    ui->cancel->setStyleSheet("border:none;border-radius:10px;");
    ui->cancel->setIcon(QIcon(QString("E://uiProject//cancelButtonBlack.png")));
    ui->cancel->setIconSize(QSize(300, 300));
}
