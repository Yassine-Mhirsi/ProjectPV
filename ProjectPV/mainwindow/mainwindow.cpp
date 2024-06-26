#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "./etudiant/etudiant.h"
#include "./enseignant/enseignant.h"
#include <QPixmapCache>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include "./matiere/matiere.h"
#include "./groupemodule/groupemodule.h"
#include"./groupe/groupe.h"
#include "./note/note.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("System Mangement");
    setWindowIcon(QIcon("E:/documents/cpp/QtProjectPV/p/ProjectPV/assets/iconpi.jpg"));
    ui->etudiant_pushButton->setIcon(QIcon("E:/documents/cpp/QtProjectPV/p/ProjectPV/assets/student.svg"));
    ui->ens_pushButton->setIcon(QIcon("E:/documents/cpp/QtProjectPV/p/ProjectPV/assets/teacher.svg"));
    ui->matiere_pushButton->setIcon(QIcon("E:/documents/cpp/QtProjectPV/p/ProjectPV/assets/subject.svg"));
    ui->gm_pushButton->setIcon(QIcon("E:/documents/cpp/QtProjectPV/p/ProjectPV/assets/groupemodule.svg"));
    ui->grp_pushButton->setIcon(QIcon("E:/documents/cpp/QtProjectPV/p/ProjectPV/assets/groupe.svg"));
    ui->note_pushButton->setIcon(QIcon("E:/documents/cpp/QtProjectPV/p/ProjectPV/assets/note.svg"));
    connect(ui->etudiant_pushButton,&QPushButton::clicked,this,&MainWindow::on_etudiant_pushButton_clicked);
    connect(ui->ens_pushButton,&QPushButton::clicked,this,&MainWindow::on_pushButton_clicked);
    connect(ui->matiere_pushButton,&QPushButton::clicked,this,&MainWindow::on_pushButton_2_clicked);
    connect(ui->gm_pushButton,&QPushButton::clicked,this,&MainWindow::on_gm_pushButton_clicked);

}

MainWindow::~MainWindow(){delete ui;}


void MainWindow::on_etudiant_pushButton_clicked()
{
    etudiant *add = new etudiant();
    add->show();
}



void MainWindow::on_pushButton_clicked()
{
    enseignant *dep = new enseignant();
    dep->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    matiere *mat = new matiere();
    mat->show();
}


void MainWindow::on_gm_pushButton_clicked()
{
    groupemodule *gm = new groupemodule();
    gm->show();
}


void MainWindow::on_grp_pushButton_clicked()
{
    groupe *g = new groupe();
    g->show();
}


void MainWindow::on_note_pushButton_clicked()
{
    note *n = new note();
    n->show();
}

