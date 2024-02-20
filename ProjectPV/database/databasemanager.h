// databasemanager.h

#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtSql>

class DatabaseManager
{
public:
    static DatabaseManager& instance();
    QSqlDatabase& database();

private:
    DatabaseManager();
    ~DatabaseManager();

    QSqlDatabase m_database;
};

#endif // DATABASEMANAGER_H
