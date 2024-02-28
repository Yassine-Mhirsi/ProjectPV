// databasemanager.cpp

#include "databasemanager.h"

DatabaseManager::DatabaseManager()
{
    // Initialize your database connection here
    m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName("example.sqlite");

    if (!m_database.open()) {
        qDebug() << "Error: connection with database failed";
    }
}

DatabaseManager::~DatabaseManager()
{
    if (m_database.isOpen()) {
        m_database.close();
    }
}

DatabaseManager& DatabaseManager::instance()
{
    static DatabaseManager instance;
    return instance;
}

QSqlDatabase& DatabaseManager::database()
{
    return m_database;
}


