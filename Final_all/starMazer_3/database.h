#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QObject>

/*
函数名：createConnection()
参数：
功能：创建初始数据库
返回值：
*/
static bool createConnection()
{
    //创建数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database2.db");
    if(!db.open()) return false;
    QSqlQuery query;
    query.exec(QObject::tr("create table student (password int primary key, userName vchar,firstScore int,secondScore int,thirdScore int,forthScore int,firstAchi int,secondAchi int,thirdAchi int,forthAchi int,fifthAchi int,sixthAchi int,seventhAchi int,eighthAchi int,ninthAchi int,head int)"));
    //此处改动表的初始值
    query.exec(QObject::tr("insert into student values (12345,'小明',0,0,0,0,0,0,0,0,0,0,0,0,0,0)"));
    query.exec(QObject::tr("insert into student values (45645,'小红',0,0,0,0,0,0,0,0,0,0,0,0,0,0)"));
    query.exec(QObject::tr("insert into student values (75675,'小王',0,0,0,0,0,0,0,0,0,0,0,0,0,0)"));
    return true;
}



#endif // DATABASE_H
