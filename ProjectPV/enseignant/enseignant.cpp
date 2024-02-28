#include "enseignant.h"
#include "ui_enseignant.h"
#include <QMessageBox>
#include <QtSql>

enseignant::enseignant(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::enseignant)
{
    ui->setupUi(this);
    setWindowTitle("Teacher Mangement");
    setWindowIcon(QIcon("E:/documents/cpp/QtProjectPV/p/ProjectPV/assets/iconpi.jpg"));
    populateTableView();
    customizeTableView();
    connect(ui->add_pushButton, &QPushButton::clicked, this, &enseignant::addStudent);
    connect(ui->add_pushButton, &QPushButton::clicked, this, &enseignant::clearLineEdits);
    connect(ui->tableView, &QTableView::clicked, this, &enseignant::displaySelectedStudent);
    connect(ui->modify_pushButton, &QPushButton::clicked, this, &enseignant::saveStudent);
    connect(ui->tableView, &QTableView::clicked, this, &enseignant::toggleModifyButtonVisibility);
    connect(ui->modify_pushButton, &QPushButton::clicked, this, &enseignant::clearLineEdits);
    connect(ui->delete_pushButton, &QPushButton::clicked, this, &enseignant::deleteStudent);
    ui->modify_pushButton->setIcon(QIcon("E:/documents/cpp/QtProjectPV/p/ProjectPV/assets/edit.svg"));
    ui->delete_pushButton->setIcon(QIcon("E:/documents/cpp/QtProjectPV/p/ProjectPV/assets/delete.svg"));
    ui->add_pushButton->setIcon(QIcon("E:/documents/cpp/QtProjectPV/p/ProjectPV/assets/save.svg"));
    ui->clear_pushButton->setIcon(QIcon("E:/documents/cpp/QtProjectPV/p/ProjectPV/assets/clear.svg"));
    ui->modify_pushButton->hide();
    ui->delete_pushButton->hide();
    ui->clear_pushButton->hide();
    connect(ui->clear_pushButton, &QPushButton::clicked, this, &enseignant::Clear);
    connect(ui->searchbar, &QLineEdit::textChanged, this, &enseignant::on_searchbar_textChanged);
    ui->searchbar->setClearButtonEnabled(true);
    ui->searchbar->setPlaceholderText("Search teacher");
}

enseignant::~enseignant(){delete ui;}

enseignant::enseignant(int id, string nom, string prenom, string mail, int CNSS): Personne(id, nom, prenom, mail), CNSS(CNSS) {};


ostream& operator<<(ostream& os, const enseignant& teacher) {
    os << "Id: " << teacher.Id << endl;
    os << "Nom: " << teacher.Nom << endl;
    os << "Prenom: " << teacher.Prenom << endl;
    os << "Mail: " << teacher.Mail << endl;
    os << "CNSS: " << teacher.CNSS << endl;
    return os;
}


void enseignant::Clear() {
    clearLineEdits();
    ui->modify_pushButton->hide();
    ui->delete_pushButton->hide();
    ui->clear_pushButton->hide();
}

void enseignant::customizeTableView() {
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tableView->horizontalHeader()->resizeSection(0, 60);

    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->tableView->horizontalHeader()->resizeSection(1, 90);

    ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->tableView->horizontalHeader()->resizeSection(2, 80);

    ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->tableView->horizontalHeader()->resizeSection(3, 180);}

void enseignant::populateTableView() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Enseignant");

    ui->tableView->setModel(model);
}

void enseignant::addStudent() {

    // Create the table if it doesn't exist
    QSqlQuery createTableQuery;
    if (!createTableQuery.exec("CREATE TABLE IF NOT EXISTS Enseignant ("
                               "CNSS number(5) PRIMARY KEY,"
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
        QMessageBox::critical(this, "Error", "Teacher number cannot be empty");
        return;
    }
    bool ok;
    int numinsc = numinscString.toInt(&ok);
    if (!ok) {
        QMessageBox::critical(this, "Error", "Invalid teacher number");
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
    insertQuery.prepare("INSERT INTO Enseignant (CNSS, nom, prenom, mail) VALUES (:CNSS, :nom, :prenom, :mail)");
    insertQuery.bindValue(":CNSS", numinsc);
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

void enseignant::displaySelectedStudent(const QModelIndex &index) {
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

void enseignant::toggleModifyButtonVisibility() {
    // Hide the modify button when no row is selected
    if (ui->tableView->selectionModel()->selectedIndexes().isEmpty()) {
        ui->modify_pushButton->hide();

        ui->numinsc_lineEdit->clear();
        ui->name_lineEdit->clear();
        ui->lastname_lineEdit->clear();
        ui->mail_lineEdit->clear();
    }
}

void enseignant::clearLineEdits() {
    // Clear the line edits
    ui->numinsc_lineEdit->clear();
    ui->name_lineEdit->clear();
    ui->lastname_lineEdit->clear();
    ui->mail_lineEdit->clear();
}

void enseignant::saveStudent() {
    // Retrieve modified student information from line edits
    int numinsc = ui->numinsc_lineEdit->text().toInt();
    QString nom = ui->name_lineEdit->text();
    QString prenom = ui->lastname_lineEdit->text();
    QString mail = ui->mail_lineEdit->text();

    // Update student information in the database
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE Enseignant SET nom = :nom, prenom = :prenom, mail = :mail WHERE CNSS = :CNSS");
    updateQuery.bindValue(":nom", nom);
    updateQuery.bindValue(":prenom", prenom);
    updateQuery.bindValue(":mail", mail);
    updateQuery.bindValue(":CNSS", numinsc);

    if (!updateQuery.exec()) {
        qDebug() << "Error updating data:" << updateQuery.lastError().text();
    } else {
        qDebug() << "Data updated successfully";
        populateTableView(); // Refresh the table view to reflect changes
        ui->modify_pushButton->hide();
    }
    ui->delete_pushButton->hide();
    ui->modify_pushButton->hide();
}

void enseignant::toggleDeleteButtonVisibility() {
    // Hide the delete button when no row is selected
    if (ui->tableView->selectionModel()->selectedIndexes().isEmpty()) {
        ui->delete_pushButton->hide();

        ui->numinsc_lineEdit->clear();
        ui->name_lineEdit->clear();
        ui->lastname_lineEdit->clear();
        ui->mail_lineEdit->clear();
    }
}

void enseignant::deleteStudent() {
    // Retrieve the student ID from the line edit or any other suitable method
    int numinsc = ui->numinsc_lineEdit->text().toInt();

    // Confirm deletion with the user (optional)
    QMessageBox::StandardButton reply = QMessageBox::critical(this, "Delete Teacher",
                                                              "Are you sure you want to delete this teacher?",
                                                              QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No)
        return;

    // Delete student information from the database
    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM Enseignant WHERE CNSS = :CNSS");
    deleteQuery.bindValue(":CNSS", numinsc);

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

void enseignant::searchStudents(const QString &text)
{
    QSqlQuery query;
    QString queryString = "SELECT * FROM Enseignant WHERE CNSS LIKE :search OR nom LIKE :search OR prenom LIKE :search OR mail LIKE :search";
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

void enseignant::on_searchbar_textChanged(const QString &text)
{
    searchStudents(text);
}
