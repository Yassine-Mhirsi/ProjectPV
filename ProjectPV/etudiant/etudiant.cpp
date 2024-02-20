#include "etudiant.h"
#include "ui_etudiant.h"
#include <QtSql>

etudiant::etudiant(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::etudiant)
{
    ui->setupUi(this);
    connect(ui->add_pushButton, &QPushButton::clicked, this, &etudiant::addStudent);

}

etudiant::~etudiant()
{
    delete ui;
}

void etudiant::populateListView() {
    // Fetch student data from the database
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Etudiant");

    // Set the model to the QListView
    ui->etudiant_listView->setModel(model);
}

void etudiant::addStudent() {


    // Create the table if it doesn't exist
    QSqlQuery createTableQuery;
    if (!createTableQuery.exec("CREATE TABLE IF NOT EXISTS Etudiant ("
                               "numinsc INTEGER PRIMARY KEY,"
                               "nom TEXT NOT NULL COLLATE NOCASE,"
                               "prenom TEXT NOT NULL COLLATE NOCASE,"
                               "mail TEXT NOT NULL COLLATE NOCASE);")) {
        qDebug() << "Error creating table:" << createTableQuery.lastError().text();
        return;
    } else {
        qDebug() << "Table created successfully";
    }

    // Retrieve student information from line edits
    QString numinsc = ui->numinsc_lineEdit->text();
    QString nom = ui->name_lineEdit->text();
    QString prenom = ui->lastname_lineEdit->text();
    QString mail = ui->mail_lineEdit->text();
    // Get other student information similarly

    // Insert student into the database
    // Insert data into the database
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO Etudiant (numinsc, nom, prenom, mail) VALUES (:numinsc, :nom, :prenom, :mail)");
    insertQuery.bindValue(":numinsc", numinsc);
    insertQuery.bindValue(":nom", nom);
    insertQuery.bindValue(":prenom", prenom);
    insertQuery.bindValue(":mail", mail);

    if (!insertQuery.exec()) {
        qDebug() << "Error inserting data:" << insertQuery.lastError().text();
    } else {
        qDebug() << "Data inserted successfully";
        populateListView();
    }

}

void etudiant::on_add_pushButton_clicked()
{

}

