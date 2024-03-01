#include "etudiant.h"
#include "ui_etudiant.h"
#include <QMessageBox>
#include <QtSql>

etudiant::etudiant(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::etudiant)
{
    ui->setupUi(this);
    setWindowTitle("Student Mangement");
    setWindowIcon(QIcon("E:/documents/cpp/QtProjectPV/p/ProjectPV/assets/iconpi.jpg"));
    populateTableView();
    customizeTableView();
    connect(ui->add_pushButton, &QPushButton::clicked, this, &etudiant::addStudent);
    connect(ui->add_pushButton, &QPushButton::clicked, this, &etudiant::clearLineEdits);
    connect(ui->tableView, &QTableView::clicked, this, &etudiant::displaySelectedStudent);
    connect(ui->modify_pushButton, &QPushButton::clicked, this, &etudiant::saveStudent);
    connect(ui->tableView, &QTableView::clicked, this, &etudiant::toggleModifyButtonVisibility);
    connect(ui->modify_pushButton, &QPushButton::clicked, this, &etudiant::clearLineEdits);
    connect(ui->delete_pushButton, &QPushButton::clicked, this, &etudiant::deleteStudent);
    ui->modify_pushButton->setIcon(QIcon("E:/documents/cpp/QtProjectPV/p/ProjectPV/assets/edit.svg"));
    ui->delete_pushButton->setIcon(QIcon("E:/documents/cpp/QtProjectPV/p/ProjectPV/assets/delete.svg"));
    ui->add_pushButton->setIcon(QIcon("E:/documents/cpp/QtProjectPV/p/ProjectPV/assets/save.svg"));
    ui->clear_pushButton->setIcon(QIcon("E:/documents/cpp/QtProjectPV/p/ProjectPV/assets/clear.svg"));
    ui->modify_pushButton->hide();
    ui->delete_pushButton->hide();
    ui->clear_pushButton->hide();
    connect(ui->clear_pushButton, &QPushButton::clicked, this, &etudiant::Clear);
    connect(ui->searchbar, &QLineEdit::textChanged, this, &etudiant::on_searchbar_textChanged);
    ui->searchbar->setClearButtonEnabled(true);
    ui->searchbar->setPlaceholderText("Search student");

}

etudiant::etudiant(int id, string nom, string prenom, string mail, int numInsc): Personne(id, nom, prenom, mail), Num_insc(numInsc) {}

etudiant::~etudiant(){delete ui;}

ostream& operator<<(ostream& os, const etudiant& student) {
    os << "Id: " << student.Id << endl;
    os << "Nom: " << student.Nom << endl;
    os << "Prenom: " << student.Prenom << endl;
    os << "Mail: " << student.Mail << endl;
    os << "Num_insc: " << student.Num_insc << endl;
    return os;
}

void etudiant::Clear() {
        clearLineEdits();
        ui->modify_pushButton->hide();
        ui->delete_pushButton->hide();
        ui->clear_pushButton->hide();
}

void etudiant::customizeTableView() {
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tableView->horizontalHeader()->resizeSection(0, 60);

    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->tableView->horizontalHeader()->resizeSection(1, 90);

    ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->tableView->horizontalHeader()->resizeSection(2, 80);

    ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->tableView->horizontalHeader()->resizeSection(3, 180);}

void etudiant::populateTableView() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Etudiant");

    ui->tableView->setModel(model);
}

void etudiant::addStudent() {

    // Create the table if it doesn't exist
    QSqlQuery createTableQuery;
    if (!createTableQuery.exec("CREATE TABLE IF NOT EXISTS Etudiant ("
                               "numinsc number(5) PRIMARY KEY,"
                               "nom VARCHAR2(20) NOT NULL COLLATE NOCASE,"
                               "prenom VARCHAR2(20) NOT NULL COLLATE NOCASE,"
                               "mail VARCHAR2(30) NOT NULL COLLATE NOCASE);")) {
        qDebug() << "Error creating table:" << createTableQuery.lastError().text();
        return;
    } else {
        qDebug() << "Table created successfully";
    }

    QString numinscString = ui->numinsc_lineEdit->text();
    if (numinscString.isEmpty()) {
        QMessageBox::critical(this, "Error", "Student number cannot be empty");
        return;
    }
    bool ok;
    int numinsc = numinscString.toInt(&ok);
    if (!ok) {
        QMessageBox::critical(this, "Error", "Invalid student number");
        return;
    }

    QString nom = ui->name_lineEdit->text();
    QString prenom = ui->lastname_lineEdit->text();
    QString mail = ui->mail_lineEdit->text();

    // Validate input
    if (nom.isEmpty() || prenom.isEmpty() || mail.isEmpty()) {
        QMessageBox::critical(this, "Error", "Please fill in all fields");
        return;
    }

    // Insert student into the database
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
        populateTableView();
    }

}

void etudiant::displaySelectedStudent(const QModelIndex &index) {
    int row = index.row();
    ui->clear_pushButton->show();

    // Retrieve the data of the selected student
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tableView->model());
    QString numinsc = model->data(model->index(row, 0)).toString();
    QString nom = model->data(model->index(row, 1)).toString();
    QString prenom = model->data(model->index(row, 2)).toString();
    QString mail = model->data(model->index(row, 3)).toString();



    // Populate line edits with the selected student's information
    ui->numinsc_lineEdit->setText(numinsc);
    ui->name_lineEdit->setText(nom);
    ui->lastname_lineEdit->setText(prenom);
    ui->mail_lineEdit->setText(mail);

    // Show the modify button
    ui->modify_pushButton->show();
    ui->delete_pushButton->show();
}

void etudiant::toggleModifyButtonVisibility() {
    // Hide the modify button when no row is selected
    if (ui->tableView->selectionModel()->selectedIndexes().isEmpty()) {
        ui->modify_pushButton->hide();

        ui->numinsc_lineEdit->clear();
        ui->name_lineEdit->clear();
        ui->lastname_lineEdit->clear();
        ui->mail_lineEdit->clear();
    }
}

void etudiant::clearLineEdits() {
    // Clear the line edits
    ui->numinsc_lineEdit->clear();
    ui->name_lineEdit->clear();
    ui->lastname_lineEdit->clear();
    ui->mail_lineEdit->clear();
}

void etudiant::saveStudent() {
    // Retrieve modified student information from line edits
    int numinsc = ui->numinsc_lineEdit->text().toInt();
    QString nom = ui->name_lineEdit->text();
    QString prenom = ui->lastname_lineEdit->text();
    QString mail = ui->mail_lineEdit->text();

    // Update student information in the database
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE Etudiant SET nom = :nom, prenom = :prenom, mail = :mail WHERE numinsc = :numinsc");
    updateQuery.bindValue(":nom", nom);
    updateQuery.bindValue(":prenom", prenom);
    updateQuery.bindValue(":mail", mail);
    updateQuery.bindValue(":numinsc", numinsc);

    if (!updateQuery.exec()) {
        qDebug() << "Error updating data:" << updateQuery.lastError().text();
    } else {
        qDebug() << "Data updated successfully";
        populateTableView(); // Refresh the table view to reflect changes
        ui->modify_pushButton->hide();
    }
    ui->delete_pushButton->hide();
    ui->modify_pushButton->hide();
    ui->clear_pushButton->hide();

}

void etudiant::toggleDeleteButtonVisibility() {
    // Hide the delete button when no row is selected
    if (ui->tableView->selectionModel()->selectedIndexes().isEmpty()) {
        ui->delete_pushButton->hide();

        ui->numinsc_lineEdit->clear();
        ui->name_lineEdit->clear();
        ui->lastname_lineEdit->clear();
        ui->mail_lineEdit->clear();
    }
}

void etudiant::deleteStudent() {
    // Retrieve the student ID from the line edit or any other suitable method
    int numinsc = ui->numinsc_lineEdit->text().toInt();

    // Confirm deletion with the user (optional)
    QMessageBox::StandardButton reply = QMessageBox::critical(this, "Delete Student",
                                                              "Are you sure you want to delete this student?",
                                                              QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No)
        return;

    // Delete student information from the database
    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM Etudiant WHERE numinsc = :numinsc");
    deleteQuery.bindValue(":numinsc", numinsc);

    if (!deleteQuery.exec()) {
        qDebug() << "Error deleting data:" << deleteQuery.lastError().text();
    } else {
        qDebug() << "Data deleted successfully";
        populateTableView(); // Refresh the table view to reflect changes
        clearLineEdits(); // Optionally clear the line edits after deletion
    }
    ui->delete_pushButton->hide();
    ui->modify_pushButton->hide();
}

void etudiant::searchStudents(const QString &text)
{
    QSqlQuery query;
    QString queryString = "SELECT * FROM Etudiant WHERE numinsc LIKE :search OR nom LIKE :search OR prenom LIKE :search OR mail LIKE :search";
    query.prepare(queryString);
    query.bindValue(":search", "%" + text + "%");

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    QSqlQueryModel *model = new QSqlQueryModel(); // Create a new model
    model->setQuery(std::move(query)); // Move the query to setQuery

    // Set the model to the TableView
    ui->tableView->setModel(model);
}

void etudiant::on_searchbar_textChanged(const QString &text)
{
    searchStudents(text);
}

