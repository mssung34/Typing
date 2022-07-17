#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QtSql>
#include <QDebug>
#include <QSqlTableModel>
#include <iostream>
class Database
{
private:
    QSqlDatabase db;
public:
    Database() {
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("localhost");      // IP 또는 DNS Host name
        db.setDatabaseName("typing"); // DB명
        db.setUserName("root");     // 계정 명
        db.setPassword("1234");     // 계정 Password

        if(!db.open())
            exit(1);
    }
    QSqlDatabase GetDB()
    {
        return db;
    }
    ~Database() {
        db.close();
    }
};
