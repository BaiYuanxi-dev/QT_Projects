#include "regis.h"
#include "ui_regis.h"
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>

Regis::Regis(QWidget *parent) :QWidget(parent),ui(new Ui::Regis){
    ui->setupUi(this);

    //����ͼ����Ӧlabel��С
    QPalette PAllbackground = this->palette();
    QImage ImgAllbackground("E://uiProject//Login//regisBackground.png");
    QImage fitimgpic=ImgAllbackground.scaled(this->width(),this->height(), Qt::IgnoreAspectRatio);
    PAllbackground.setBrush(QPalette::Window, QBrush(fitimgpic));
    this->setPalette(PAllbackground);

    //���ݿ�ı�
    model = new QSqlTableModel(this);
    model->setTable("student");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select(); //ѡȡ�������������
    ui->tableView->setModel(model);

    //linetext��ʾ��
    QLineEdit *pLineEdit = ui->regisUsername;
    pLineEdit->setPlaceholderText(QString::fromLocal8Bit("�������û���"));
    QPalette *pal = new QPalette();
    pal->setColor(QPalette::Normal, QPalette::PlaceholderText, Qt::gray);
    pLineEdit->setPalette(*pal);

    ui->regisPassword1->setPlaceholderText(QString::fromLocal8Bit("����������"));
    QPalette * palette2 = new QPalette();
    palette2->setColor(QPalette::Normal, QPalette::PlaceholderText, Qt::gray);
    ui->regisPassword1->setPalette(*palette2);

    ui->regisPassword2->setPlaceholderText(QString::fromLocal8Bit("���ٴ���������"));
    QPalette * palette3 = new QPalette();
    palette3->setColor(QPalette::Normal, QPalette::PlaceholderText, Qt::gray);
    ui->regisPassword2->setPalette(*palette3);
}

Regis::~Regis(){
    delete ui;
}

/*
��������on_confirm_clicked()
��������
���ܣ�ע����棬���û���Ϣ�������ݿ�
����ֵ����
*/
void Regis::on_confirm_clicked(){
    //��������ݿ�
    int rowNum = model->rowCount(); //��ñ������
    //��ȡlineEdit���ı�
    QString username = ui->regisUsername->text();
    QString password=ui->regisPassword1->text();
    QString password1=ui->regisPassword1->text();
    QString password2=ui->regisPassword2->text();
    //�˴������û���Ϣ���û��������룬�ɼ�
    int score = 0;//��ʼ���ĳɼ�
    //����
    if(username==""||password=="")
        QMessageBox::warning(this,QString::fromLocal8Bit("ע��ʧ��"),QString::fromLocal8Bit("�������ݲ���Ϊ��"));

    else if(password1!=password2)
        QMessageBox::warning(this,QString::fromLocal8Bit("ע��ʧ��"),QString::fromLocal8Bit("������������벻��ͬ"));
    else{
        model->insertRow(rowNum); //���һ��
        //�˴��޸Ĳ���ֵ�����ڱ���ɼ���ע���û���Ϣ��
        model->setData(model->index(rowNum,2),score);//�趨ֵ��ע��score���ڵ�����
        model->setData(model->index(rowNum,1),username);
        model->setData(model->index(rowNum,0),password);//�����ڱ��в���ʾ������

        //�����޸�
        model->database().transaction(); //��ʼ�������
        if (model->submitAll())
            model->database().commit(); //�ύ
        else {
            model->database().rollback(); //�ع�
            QMessageBox::warning(this, tr("tableModel"),tr("���ݿ����: %1").arg(model->lastError().text()));
        }
        QMessageBox::information(this,"ע�����","ע��ɹ�");
    }
}

/*
��������on_cancel_clicked()
��������
���ܣ��˳���ǰ����
����ֵ����
*/
void Regis::on_cancel_clicked(){
    this->close();
}
