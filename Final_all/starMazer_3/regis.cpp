#include "regis.h"
#include "ui_regis.h"
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>

regis::regis(QWidget *parent) :QWidget(parent),ui(new Ui::regis){
    ui->setupUi(this);

    //���ݿ�ı�
    model = new QSqlTableModel(this);
    model->setTable("student");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select(); //ѡȡ�������������
    ui->tableView->setModel(model);

    //linetext��ʾ��
    QLineEdit *pLineEdit = ui->regisUsername;
    pLineEdit->setPlaceholderText(QStringLiteral("�������û���"));
    QPalette palette = pLineEdit->palette();
    palette.setColor(QPalette::Normal, QPalette::PlaceholderText, Qt::gray);
    pLineEdit->setPalette(palette);

    QLineEdit *pLineEdit2 = ui->regisPassword1;
    pLineEdit2->setPlaceholderText(QStringLiteral("����������"));
    QPalette palette2 = pLineEdit2->palette();
    palette2.setColor(QPalette::Normal, QPalette::PlaceholderText, Qt::gray);
    pLineEdit2->setPalette(palette2);

    QLineEdit *pLineEdit3 = ui->regisPassword2;
    pLineEdit3->setPlaceholderText(QStringLiteral("���ٴ���������"));
    QPalette palette3 = pLineEdit3->palette();
    palette3.setColor(QPalette::Normal, QPalette::PlaceholderText, Qt::gray);
    pLineEdit3->setPalette(palette3);

    //����ȷ�ϰ�ť
    ui->confirm->setStyleSheet("border:none;border-radius:10px;");
    ui->confirm->setIcon(QIcon(QString("E://uiProject//confirmButtonBlack.png")));
    ui->confirm->setIconSize(QSize(300, 300));

    //����ȡ����ť
    ui->cancel->setStyleSheet("border:none;border-radius:10px;");
    ui->cancel->setIcon(QIcon(QString("E://uiProject//cancelButtonBlack.png")));
    ui->cancel->setIconSize(QSize(300, 300));

    //����head1��ť
    ui->head1->setStyleSheet("border:none;border-radius:10px;");
    ui->head1->setIcon(QIcon(QString("E://uiProject//head1.png")));
    ui->head1->setIconSize(QSize(100, 100));

    //����head2��ť
    ui->head2->setStyleSheet("border:none;border-radius:10px;");
    ui->head2->setIcon(QIcon(QString("E://uiProject//head2.png")));
    ui->head2->setIconSize(QSize(100, 100));

    //����head3��ť
    ui->head3->setStyleSheet("border:none;border-radius:10px;");
    ui->head3->setIcon(QIcon(QString("E://uiProject//head3.png")));
    ui->head3->setIconSize(QSize(100, 100));


    //����head4��ť
    ui->head4->setStyleSheet("border:none;border-radius:10px;");
    ui->head4->setIcon(QIcon(QString("E://uiProject//head4.png")));
    ui->head4->setIconSize(QSize(100, 100));

    //����head5��ť
    ui->head5->setStyleSheet("border:none;border-radius:10px;");
    ui->head5->setIcon(QIcon(QString("E://uiProject//head5.png")));
    ui->head5->setIconSize(QSize(100, 100));

    //����head6��ť
    ui->head6->setStyleSheet("border:none;border-radius:10px;");
    ui->head6->setIcon(QIcon(QString("E://uiProject//head6.png")));
    ui->head6->setIconSize(QSize(100, 100));
}

regis::~regis(){
    delete ui;
}

/*
��������on_confirm_clicked()
��������
���ܣ�ע����棬���û���Ϣ�������ݿ�
����ֵ����
*/
void regis::on_confirm_clicked(){
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
    if(username==""||password==""){
        QMessageBox::warning(this,QStringLiteral("ע��ʧ��"),QStringLiteral("�������ݲ���Ϊ��"));
    }
    else if(password1!=password2){
        QMessageBox::warning(this,QStringLiteral("ע��ʧ��"),QStringLiteral("������������벻��ͬ"));
    }
    else{
        model->insertRow(rowNum); //���һ��
        //�˴��޸Ĳ���ֵ�����ڱ���ɼ���ע���û���Ϣ��
        //model->setData(model->index(rowNum,2),score);//�趨ֵ��ע��score���ڵ�����
        model->setData(model->index(rowNum,1),username);
        model->setData(model->index(rowNum,0),password);//�����ڱ��в���ʾ������

        for(int i=2;i<15;i++){
            model->setData(model->index(rowNum,i),0);
        }

        model->setData(model->index(rowNum,15),head);

        //�����޸�
        model->database().transaction(); //��ʼ�������
        if (model->submitAll()) {
            model->database().commit(); //�ύ
        }else{
            model->database().rollback(); //�ع�
            QMessageBox::warning(this, tr("tableModel"),tr("���ݿ����: %1").arg(model->lastError().text()));
        }
        QMessageBox::information(this,QStringLiteral("ע�����"),QStringLiteral("ע��ɹ�"));
        this->~regis();
    }
}

/*
��������on_cancel_clicked()
��������
���ܣ��˳���ǰ����
����ֵ����
*/
void regis::on_cancel_clicked(){
    this->close();
}

void regis::on_head1_clicked(){
    head=1;
    //����head1��ť
    ui->head1->setStyleSheet("border:none;border-radius:10px;");
    ui->head1->setIcon(QIcon(QString("E://uiProject//head1R.png")));
    ui->head1->setIconSize(QSize(100, 100));

    //����head2��ť
    ui->head2->setStyleSheet("border:none;border-radius:10px;");
    ui->head2->setIcon(QIcon(QString("E://uiProject//head2.png")));
    ui->head2->setIconSize(QSize(100, 100));

    //����head3��ť
    ui->head3->setStyleSheet("border:none;border-radius:10px;");
    ui->head3->setIcon(QIcon(QString("E://uiProject//head3.png")));
    ui->head3->setIconSize(QSize(100, 100));


    //����head4��ť
    ui->head4->setStyleSheet("border:none;border-radius:10px;");
    ui->head4->setIcon(QIcon(QString("E://uiProject//head4.png")));
    ui->head4->setIconSize(QSize(100, 100));

    //����head5��ť
    ui->head5->setStyleSheet("border:none;border-radius:10px;");
    ui->head5->setIcon(QIcon(QString("E://uiProject//head5.png")));
    ui->head5->setIconSize(QSize(100, 100));

    //����head6��ť
    ui->head6->setStyleSheet("border:none;border-radius:10px;");
    ui->head6->setIcon(QIcon(QString("E://uiProject//head6.png")));
    ui->head6->setIconSize(QSize(100, 100));
}

void regis::on_head2_clicked(){
    head=2;
    //����head1��ť
    ui->head1->setStyleSheet("border:none;border-radius:10px;");
    ui->head1->setIcon(QIcon(QString("E://uiProject//head1.png")));
    ui->head1->setIconSize(QSize(100, 100));

    //����head2��ť
    ui->head2->setStyleSheet("border:none;border-radius:10px;");
    ui->head2->setIcon(QIcon(QString("E://uiProject//head2R.png")));
    ui->head2->setIconSize(QSize(100, 100));

    //����head3��ť
    ui->head3->setStyleSheet("border:none;border-radius:10px;");
    ui->head3->setIcon(QIcon(QString("E://uiProject//head3.png")));
    ui->head3->setIconSize(QSize(100, 100));


    //����head4��ť
    ui->head4->setStyleSheet("border:none;border-radius:10px;");
    ui->head4->setIcon(QIcon(QString("E://uiProject//head4.png")));
    ui->head4->setIconSize(QSize(100, 100));

    //����head5��ť
    ui->head5->setStyleSheet("border:none;border-radius:10px;");
    ui->head5->setIcon(QIcon(QString("E://uiProject//head5.png")));
    ui->head5->setIconSize(QSize(100, 100));

    //����head6��ť
    ui->head6->setStyleSheet("border:none;border-radius:10px;");
    ui->head6->setIcon(QIcon(QString("E://uiProject//head6.png")));
    ui->head6->setIconSize(QSize(100, 100));
}

void regis::on_head3_clicked(){
    head=3;

    //����head1��ť
    ui->head1->setStyleSheet("border:none;border-radius:10px;");
    ui->head1->setIcon(QIcon(QString("E://uiProject//head1.png")));
    ui->head1->setIconSize(QSize(100, 100));

    //����head2��ť
    ui->head2->setStyleSheet("border:none;border-radius:10px;");
    ui->head2->setIcon(QIcon(QString("E://uiProject//head2.png")));
    ui->head2->setIconSize(QSize(100, 100));

    //����head3��ť
    ui->head3->setStyleSheet("border:none;border-radius:10px;");
    ui->head3->setIcon(QIcon(QString("E://uiProject//head3R.png")));
    ui->head3->setIconSize(QSize(100, 100));


    //����head4��ť
    ui->head4->setStyleSheet("border:none;border-radius:10px;");
    ui->head4->setIcon(QIcon(QString("E://uiProject//head4.png")));
    ui->head4->setIconSize(QSize(100, 100));

    //����head5��ť
    ui->head5->setStyleSheet("border:none;border-radius:10px;");
    ui->head5->setIcon(QIcon(QString("E://uiProject//head5.png")));
    ui->head5->setIconSize(QSize(100, 100));

    //����head6��ť
    ui->head6->setStyleSheet("border:none;border-radius:10px;");
    ui->head6->setIcon(QIcon(QString("E://uiProject//head6.png")));
    ui->head6->setIconSize(QSize(100, 100));
}

void regis::on_head4_clicked(){
    head=4;

    //����head1��ť
    ui->head1->setStyleSheet("border:none;border-radius:10px;");
    ui->head1->setIcon(QIcon(QString("E://uiProject//head1.png")));
    ui->head1->setIconSize(QSize(100, 100));

    //����head2��ť
    ui->head2->setStyleSheet("border:none;border-radius:10px;");
    ui->head2->setIcon(QIcon(QString("E://uiProject//head2.png")));
    ui->head2->setIconSize(QSize(100, 100));

    //����head3��ť
    ui->head3->setStyleSheet("border:none;border-radius:10px;");
    ui->head3->setIcon(QIcon(QString("E://uiProject//head3.png")));
    ui->head3->setIconSize(QSize(100, 100));


    //����head4��ť
    ui->head4->setStyleSheet("border:none;border-radius:10px;");
    ui->head4->setIcon(QIcon(QString("E://uiProject//head4R.png")));
    ui->head4->setIconSize(QSize(100, 100));

    //����head5��ť
    ui->head5->setStyleSheet("border:none;border-radius:10px;");
    ui->head5->setIcon(QIcon(QString("E://uiProject//head5.png")));
    ui->head5->setIconSize(QSize(100, 100));

    //����head6��ť
    ui->head6->setStyleSheet("border:none;border-radius:10px;");
    ui->head6->setIcon(QIcon(QString("E://uiProject//head6.png")));
    ui->head6->setIconSize(QSize(100, 100));
}

void regis::on_head5_clicked(){
    head=5;

    //����head1��ť
    ui->head1->setStyleSheet("border:none;border-radius:10px;");
    ui->head1->setIcon(QIcon(QString("E://uiProject//head1.png")));
    ui->head1->setIconSize(QSize(100, 100));

    //����head2��ť
    ui->head2->setStyleSheet("border:none;border-radius:10px;");
    ui->head2->setIcon(QIcon(QString("E://uiProject//head2.png")));
    ui->head2->setIconSize(QSize(100, 100));

    //����head3��ť
    ui->head3->setStyleSheet("border:none;border-radius:10px;");
    ui->head3->setIcon(QIcon(QString("E://uiProject//head3.png")));
    ui->head3->setIconSize(QSize(100, 100));


    //����head4��ť
    ui->head4->setStyleSheet("border:none;border-radius:10px;");
    ui->head4->setIcon(QIcon(QString("E://uiProject//head4.png")));
    ui->head4->setIconSize(QSize(100, 100));

    //����head5��ť
    ui->head5->setStyleSheet("border:none;border-radius:10px;");
    ui->head5->setIcon(QIcon(QString("E://uiProject//head5R.png")));
    ui->head5->setIconSize(QSize(100, 100));

    //����head6��ť
    ui->head6->setStyleSheet("border:none;border-radius:10px;");
    ui->head6->setIcon(QIcon(QString("E://uiProject//head6.png")));
    ui->head6->setIconSize(QSize(100, 100));
}

void regis::on_head6_clicked(){
    head=6;

    //����head1��ť
    ui->head1->setStyleSheet("border:none;border-radius:10px;");
    ui->head1->setIcon(QIcon(QString("E://uiProject//head1.png")));
    ui->head1->setIconSize(QSize(100, 100));

    //����head2��ť
    ui->head2->setStyleSheet("border:none;border-radius:10px;");
    ui->head2->setIcon(QIcon(QString("E://uiProject//head2.png")));
    ui->head2->setIconSize(QSize(100, 100));

    //����head3��ť
    ui->head3->setStyleSheet("border:none;border-radius:10px;");
    ui->head3->setIcon(QIcon(QString("E://uiProject//head3.png")));
    ui->head3->setIconSize(QSize(100, 100));


    //����head4��ť
    ui->head4->setStyleSheet("border:none;border-radius:10px;");
    ui->head4->setIcon(QIcon(QString("E://uiProject//head4.png")));
    ui->head4->setIconSize(QSize(100, 100));

    //����head5��ť
    ui->head5->setStyleSheet("border:none;border-radius:10px;");
    ui->head5->setIcon(QIcon(QString("E://uiProject//head5.png")));
    ui->head5->setIconSize(QSize(100, 100));

    //����head6��ť
    ui->head6->setStyleSheet("border:none;border-radius:10px;");
    ui->head6->setIcon(QIcon(QString("E://uiProject//head6R.png")));
    ui->head6->setIconSize(QSize(100, 100));
}

void regis::on_confirm_pressed(){
    //����ȷ�ϰ�ť
    ui->confirm->setStyleSheet("border:none;border-radius:10px;");
    ui->confirm->setIcon(QIcon(QString("E://uiProject//confirmButtonWhite.png")));
    ui->confirm->setIconSize(QSize(300, 300));
}

void regis::on_confirm_released(){
    //����ȷ�ϰ�ť
    ui->confirm->setStyleSheet("border:none;border-radius:10px;");
    ui->confirm->setIcon(QIcon(QString("E://uiProject//confirmButtonBlack.png")));
    ui->confirm->setIconSize(QSize(300, 300));
}

void regis::on_cancel_pressed(){
    //����ȡ����ť
    ui->cancel->setStyleSheet("border:none;border-radius:10px;");
    ui->cancel->setIcon(QIcon(QString("E://uiProject//cancelButtonWhite.png")));
    ui->cancel->setIconSize(QSize(300, 300));
}

void regis::on_cancel_released(){
    //����ȡ����ť
    ui->cancel->setStyleSheet("border:none;border-radius:10px;");
    ui->cancel->setIcon(QIcon(QString("E://uiProject//cancelButtonBlack.png")));
    ui->cancel->setIconSize(QSize(300, 300));
}
