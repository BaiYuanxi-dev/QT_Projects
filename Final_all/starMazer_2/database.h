#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QObject>

/*
��������createConnection()
������
���ܣ�������ʼ���ݿ�
����ֵ��
*/
static bool createConnection()
{
    //�������ݿ�
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database2.db");
    if(!db.open()) return false;
    QSqlQuery query;
    query.exec(QObject::tr("create table student (password int primary key, userName vchar,firstScore int,secondScore int,thirdScore int,forthScore int,firstAchi int,secondAchi int,thirdAchi int,forthAchi int,fifthAchi int,sixthAchi int,seventhAchi int,eighthAchi int,ninthAchi int,head int)"));
    //�˴��Ķ���ĳ�ʼֵ
    query.exec(QObject::tr("insert into student values (12345,'С��',0,0,0,0,0,0,0,0,0,0,0,0,0,0)"));
    query.exec(QObject::tr("insert into student values (45645,'С��',0,0,0,0,0,0,0,0,0,0,0,0,0,0)"));
    query.exec(QObject::tr("insert into student values (75675,'С��',0,0,0,0,0,0,0,0,0,0,0,0,0,0)"));
    return true;
}



#endif // DATABASE_H
