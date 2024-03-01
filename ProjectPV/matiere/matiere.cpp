#pragma GCC diagnostic ignored "-Wunused-parameter"
#include "matiere.h"
#include "ui_matiere.h"
#include <QStandardItemModel>
#include <QStandardItem>
#include <QMessageBox>

matiere::matiere(QWidget *parent)
    : QDialog(parent), ui(new Ui::matiere) {
    ui->setupUi(this);
    setWindowTitle("Matiere Mangement");
    setWindowIcon(QIcon("E:/documents/cpp/QtProjectPV/p/ProjectPV/assets/iconpi.jpg"));
    PopulateTeacher();
    PopulateMatiere();
    connect(ui->add_pushButton, &QPushButton::clicked, this, &matiere::addMatiere);
    connect(ui->tableView, &QTableView::clicked, this, &matiere::displaySelectedMatiere);
    connect(ui->delete_pushButton, &QPushButton::clicked, this, &matiere::deleteMatiere);
    connect(ui->modify_pushButton, &QPushButton::clicked, this, &matiere::modifyMatiere);
    connect(ui->modify_pushButton, &QPushButton::clicked, this, &matiere::clearLineEdits);
    connect(ui->clear_pushButton, &QPushButton::clicked, this, &matiere::Clear);
    ui->add_teacher->setIcon(QIcon("E:/documents/cpp/QtProjectPV/p/ProjectPV/assets/add-round.svg"));
    ui->modify_pushButton->hide();
    ui->delete_pushButton->hide();
    ui->clear_pushButton->hide();
    ui->id_label->hide();
    ui->id_lineEdit->hide();
    connect(ui->searchbar, &QLineEdit::textChanged, this, &matiere::on_searchbar_textChanged);
    ui->searchbar->setClearButtonEnabled(true);
    ui->searchbar->setPlaceholderText("Search Matiere");

}

matiere::matiere(string id, string nomMat, float coef, enseignant* ens): IdMat(id), NomMat(nomMat), Coef(coef), Ens(ens) {}

matiere::~matiere() {delete ui;}

ostream& operator<<(ostream& os, const matiere& mat) {
    os << "IdMat: " << mat.IdMat << "\n";
    os << "NomMat: " << mat.NomMat << "\n";
    os << "Coef: " << mat.Coef << "\n";
    os << "Enseignant: " << *(mat.Ens) << "\n";
    return os;
}

void matiere::PopulateMatiere(){
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select m.IdMat , m.NomMat , m.Coef, e.CNSS , e.prenom , e.nom from Matiere m , Enseignant e where m.Ens=e.CNSS;");

    ui->tableView->setModel(model);
}

void matiere::PopulateTeacher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT CNSS, nom, prenom FROM Enseignant");

    ui->comboBox->clear(); // Clear existing items

    ui->comboBox->addItem("Select Teacher"); // Add "Select Teacher" as the first item

    int rowCount = model->rowCount();
    for (int i = 0; i < rowCount; ++i) {
        int teacherId = model->record(i).value("CNSS").toInt();
        QString teacherName = model->record(i).value("nom").toString();
        QString teacherLastName = model->record(i).value("prenom").toString();
        ui->comboBox->addItem(QString("%1 - %2 %3").arg(teacherId).arg(teacherName).arg(teacherLastName));
    }
}

void matiere::addMatiere() {

    QSqlQuery createTableQuery;
    if (!createTableQuery.exec("CREATE TABLE IF NOT EXISTS Matiere ("
                               "IdMat INTEGER PRIMARY KEY AUTOINCREMENT,"
                               "NomMat TEXT NOT NULL,"
                               "Coef REAL,"
                               "Ens INTEGER,"
                               "FOREIGN KEY(Ens) REFERENCES Enseignant(CNSS));")) {
        qDebug() << "Error creating table:" << createTableQuery.lastError().text();
        return;
    } else {
        qDebug() << "Table created successfully";
    }


    QString nomMat = ui->name_lineEdit->text();
    double coef = ui->doubleSpinBox->value();

    // Retrieve the selected item text from the combo box
    QString selectedText = ui->comboBox->currentText();

    // Extract the ID from the selected item text
    int enseignantId = selectedText.section(" - ", 0, 0).toInt();

    // Validate input
    if (nomMat.isEmpty() || enseignantId == 0) {
        QMessageBox::critical(this, "Error", "Matiere name and teacher selection cannot be empty");
        return;
    }

    // Insert data into the database
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO Matiere (NomMat, Coef, Ens) VALUES (:nomMat, :coef, :enseignantId)");
    insertQuery.bindValue(":nomMat", nomMat);
    insertQuery.bindValue(":coef", coef);
    insertQuery.bindValue(":enseignantId", enseignantId);

    if (!insertQuery.exec()) {
        qDebug() << "Error inserting data:" << insertQuery.lastError().text();
    } else {
        qDebug() << "Data inserted successfully";
        clearLineEdits();
        // Optionally, you can update your UI or perform any other action here
    }
    PopulateMatiere();
    ui->id_label->hide();
    ui->id_lineEdit->hide();
}

void matiere::displaySelectedMatiere(const QModelIndex &index) {
    int row = index.row();
    ui->clear_pushButton->show();

    // Retrieve the data of the selected matiere
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tableView->model());
    QString idMat = model->data(model->index(row, 0)).toString(); // Assuming the first column contains IdMat
    QString nomMat = model->data(model->index(row, 1)).toString(); // Assuming the second column contains NomMat
    double coef = model->data(model->index(row, 2)).toDouble(); // Assuming the third column contains Coef
    int enseignantId = model->data(model->index(row, 3)).toInt(); // Assuming the fourth column contains Ens

    // Populate line edits with the selected matiere's information
    ui->id_lineEdit->setText(idMat);
    ui->name_lineEdit->setText(nomMat);
    ui->doubleSpinBox->setValue(coef);

    // Set the selected teacher in the combobox
    for (int i = 0; i < ui->comboBox->count(); ++i) {
        QString comboBoxItemText = ui->comboBox->itemText(i);
        int comboBoxItemId = comboBoxItemText.section(" - ", 0, 0).toInt();
        if (comboBoxItemId == enseignantId) {
            ui->comboBox->setCurrentIndex(i);
            break;
        }
    }

    // Show the modify button
    ui->modify_pushButton->show();
    ui->delete_pushButton->show();
    ui->id_label->show();
    ui->id_lineEdit->show();
}

void matiere::deleteMatiere() {
    // Retrieve the student ID from the line edit or any other suitable method
    int idMat = ui->id_lineEdit->text().toInt();

    // Confirm deletion with the user (optional)
    QMessageBox::StandardButton reply = QMessageBox::critical(this, "Delete Matiere",
                                                              "Are you sure you want to delete this Matiere?",
                                                              QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No)
        return;

    // Delete student information from the database
    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM Matiere WHERE IdMat = :idMat");
    deleteQuery.bindValue(":idMat", idMat);

    if (!deleteQuery.exec()) {
        qDebug() << "Error deleting data:" << deleteQuery.lastError().text();
    } else {
        qDebug() << "Data deleted successfully";
        PopulateMatiere(); // Refresh the table view to reflect changes
        clearLineEdits(); // Optionally clear the line edits after deletion
    }
    ui->delete_pushButton->hide();
    ui->modify_pushButton->hide();
    ui->id_label->hide();
    ui->id_lineEdit->hide();
}

void matiere::modifyMatiere() {
    // Retrieve modified matiere information from line edits
    QString idMat = ui->id_lineEdit->text();
    QString nom = ui->name_lineEdit->text();
    double coef = ui->doubleSpinBox->value(); // Assuming coef is stored as a double in the database
    QString selectedText = ui->comboBox->currentText(); // Assuming enseignantId is stored as an integer in the database
    int CNSS = selectedText.section(" - ", 0, 0).toInt();

    if (CNSS == 0) {
        QMessageBox::critical(this, "Error", "Teacher selection cannot be empty");
        return;
    }

    // Update matiere information in the database
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE Matiere SET NomMat = :nom, Coef = :coef, Ens = :ens WHERE IdMat = :idMat");
    updateQuery.bindValue(":nom", nom);
    updateQuery.bindValue(":coef", coef);
    updateQuery.bindValue(":ens", CNSS);
    updateQuery.bindValue(":idMat", idMat);

    if (!updateQuery.exec()) {
        qDebug() << "Error updating data:" << updateQuery.lastError().text();
    } else {
        qDebug() << "Data updated successfully";
        PopulateMatiere(); // Refresh the table view to reflect changes
        ui->modify_pushButton->hide();
    }
    ui->delete_pushButton->hide();
    ui->modify_pushButton->hide();
    ui->clear_pushButton->hide();
    ui->id_label->hide();
    ui->id_lineEdit->hide();

}

void matiere::Clear() {
    clearLineEdits();
    ui->modify_pushButton->hide();
    ui->delete_pushButton->hide();
    ui->clear_pushButton->hide();
    ui->id_label->hide();
    ui->id_lineEdit->hide();
}


void matiere::clearLineEdits() {
    // Clear the line edits
    ui->id_lineEdit->clear();
    ui->name_lineEdit->clear();
    ui->doubleSpinBox->clear();
    ui->comboBox->clear();
    PopulateTeacher();
}


void matiere::searchMatiere(const QString &text)
{
    QSqlQuery query;
    QString queryString = "SELECT m.IdMat , m.NomMat , m.Coef, e.CNSS , e.prenom , e.nom from Matiere m , Enseignant e where (m.Ens=e.CNSS) and (m.IdMat LIKE :search OR m.NomMat LIKE :search OR m.Coef LIKE :search OR m.Ens LIKE :search OR e.nom LIKE :search OR e.prenom LIKE :search)";
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

void matiere::on_searchbar_textChanged(const QString &text)
{
    searchMatiere(text);
}

void matiere::on_add_teacher_clicked()
{
    enseignant *dep = new enseignant();
    dep->show();
}

