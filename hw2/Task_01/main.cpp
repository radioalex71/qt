#include "mainwindow.h"
#include <QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QHostInfo>
#include <QtSql>
#include <QtNetwork>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

        qDebug() << "Sql:";
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setHostName("localhost");
        db.setDatabaseName("test.db");
        db.setUserName("root");
        db.setPassword("root");
        bool ok = db.open();
        qDebug() << "DB connect: " << ok;
        QString dbName = db.databaseName();
        qDebug() << "Имя базы данных: " << dbName;

        qDebug() << "Network:";
        QHostInfo info = QHostInfo::fromName("Project_second");
        QString HostName = info.hostName();
        qDebug() << "HostName: " << HostName;
        qDebug() << "LocalHost: " << QHostInfo::localHostName();

    return a.exec();
}
