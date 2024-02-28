#include "welcome.h"
#include "ui_welcome.h"
#include "./database/databasemanager.h"
#include "./mainwindow/mainwindow.h"
#include <QPixmap>

Welcome::Welcome(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Welcome)
{
    ui->setupUi(this);
    show();
    QPixmap pic("E:/documents/cpp/QtProjectPV/p/ProjectPV/assets/logopi.png");
    ui->Pi->setPixmap(pic);
    setWindowTitle("Grade managment");
    setWindowIcon(QIcon("E:/documents/cpp/QtProjectPV/p/ProjectPV/assets/iconpi.jpg"));

    connect(ui->welcome,&QPushButton::clicked,this,&Welcome::on_welcome_clicked);
}

Welcome::~Welcome()
{
    delete ui;
}

void Welcome::on_welcome_clicked()
{
    this->hide();
    MainWindow *add = new MainWindow();
    add->show();
}


void Welcome::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);

    // Connect to the database when the Welcome page is shown
    QSqlDatabase db = DatabaseManager::instance().database();
    if (!db.isOpen()) {
        qDebug() << "Database not open!";
        ui->status->setText("Database not open!");
    }else{
        qDebug() << "Connected...!";
        ui->status->setText("Connected...!");
    }
}
