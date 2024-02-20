#include "./mainwindow/mainwindow.h"
#include "./welcome/welcome.h"
#include "./database/databasemanager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Welcome we;
    we.show();

    QObject::connect(&a, &QApplication::aboutToQuit, [&]() {
        // Close the database when the application is about to quit
        QSqlDatabase db = DatabaseManager::instance().database();
        if (db.isOpen()) {
            db.close();
            qDebug() << "Database connection closed";
        } else {
            qDebug() << "Database connection already closed";
        }
    });


    return a.exec();
}
