#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "./etudiant/etudiant.h"
#include <QPixmapCache>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Student Mangement");
    connect(ui->etudiant_pushButton,&QPushButton::clicked,this,&MainWindow::on_etudiant_pushButton_clicked);

}

MainWindow::~MainWindow(){delete ui;}


void MainWindow::on_etudiant_pushButton_clicked()
{
    this->hide();
    etudiant *add = new etudiant();
    add->show();
}

