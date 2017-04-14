#ifndef CONNECTDB_H
#define CONNECTDB_H
#include <QtSql>
#include <QDateTime>
#include <QMessageBox>

static bool initDatebase()
{
//    qDebug("create database");
//    QSqlDatabase mydb;
//    if(QSqlDatabase::contains("qt_sql_default_connection"))
//      mydb = QSqlDatabase::database("qt_sql_default_connection");
//    else
//      mydb = QSqlDatabase::addDatabase("QSQLITE","GBond");

//    mydb.setDatabaseName("liulong.db");//数据库名
//    bool ok=mydb.open();            //尝试连接数据库
//    if(!ok)
//    {
//        qDebug("Create Database Fail!");
//        return false;
//    }
//    QSqlQuery query;

//    if(!query.exec("CREATE TABLE table_information(ch1 int,ch2 int,ch3 int,ch4 int,ch5 int,ch6 int,ch7 int,ch8 int,datetime VARCHAR)"))
//    {
//        qDebug("Create Table Fail!");
//        return false;
//    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("my.db");
    if (!db.open()) {
        QMessageBox::critical(0, "Cannot open database",
            "Unable to establish a database connection.", QMessageBox::Cancel);
        return false;
    }
//    创建student表,第一次运行的时候，要执行建表命令。
//    QSqlQuery query;

//    query.exec(QString("CREATE TABLE table_information(ch1 int,ch2 int,ch3 int,ch4 int,ch5 int,ch6 int,ch7 int,ch8 int,datetime VARCHAR)"));
//    query.exec(QString("insert into table_information values(1,2, 3,4,5,6,7,8,9)"));

//    QDateTime dt;
//    QTime time;
//    QDate date;
//    dt.setTime(time.currentTime());
//    dt.setDate(date.currentDate());
//    QString currentDate = dt.toString("yyyy:MM:dd:hh:mm:ss"); //采用一定的格式保存时间日期
//    //将采集到的变量配置存到数据库中
//    query.exec(QString("insert into table_information(datetime)values('%1');").arg(currentDate));


    return true;
}

#endif // CONNECTDB_H
