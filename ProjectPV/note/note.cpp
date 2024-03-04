#include "note.h"
#include "qboxlayout.h"
#include "ui_note.h"
#include <iostream>
#include <ostream>
#include <QSqlQueryModel>


note::note(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::note)
{
    ui->setupUi(this);
    connect(ui->grp_comboBox, qOverload<int>(&QComboBox::currentIndexChanged), this, &note::PopulateGM);
    connect(ui->gm_tableView, &QTableView::doubleClicked, this, &::note::ToListeGRP);
    PopulateGRP();

}

note::~note()
{
    delete ui;
}
note::note(matiere* mat, etudiant* etu, float note, string type) :Mat(mat), Etu(etu), Note(note), Type(type) {}


std::ostream& operator<<(std::ostream& os, const note& grade) {
    os << "Matiere: " << *(grade.Mat) << "\n";
    os << "Etudiant: " << *(grade.Etu) << "\n";
    os << "Note: "<< grade.Note << endl;
    os << "Type: " << grade.Type << endl;
    return os;
}


void note::PopulateGRP() {



    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT IdGRP FROM Groupe");

    ui->grp_comboBox->clear(); // Clear existing items

    ui->grp_comboBox->addItem("Select Groupe"); // Add "Select Teacher" as the first item

    int rowCount = model->rowCount();
    for (int i = 0; i < rowCount; ++i) {
        QString idgrp = model->record(i).value("IdGrp").toString();
        ui->grp_comboBox->addItem(QString("%1").arg(idgrp));
    }

}


void note::PopulateGM() {
    // Retrieve the selected IdGRP from the combobox
    QString selectedIdGRP = ui->grp_comboBox->currentText();

    // Query to fetch the group modules related to the selected group
    QSqlQueryModel *model = new QSqlQueryModel();
    QString queryString = "SELECT * FROM GroupeModule WHERE IdGm IN "
                          "(SELECT IdGm FROM Liste_Groupe WHERE IdGRP = :selectedIdGRP)";
    QSqlQuery query;
    query.prepare(queryString);
    query.bindValue(":selectedIdGRP", selectedIdGRP);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    model->setQuery(query);
    ui->gm_tableView->setModel(model);
}



void note::ToListeGRP(const QModelIndex &index) {
    // Get the selected row index
    int row = index.row();

    // Get the model from the table view
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->gm_tableView->model());

    // Get the IdGm value from the selected row
    QString idGm = model->data(model->index(row, 0)).toString();

    qDebug() << "Selected IdGm:" << idGm; // Debug output to check the selected IdGm value

    // Prepare SQL query to retrieve material data associated with the selected GroupeModule
    QSqlQuery query;
    query.prepare("SELECT m.IdMat, m.NomMat, m.Coef "
                  "FROM Matiere AS m "
                  "INNER JOIN Liste_Matiere AS lm ON m.IdMat = lm.IdMat "
                  "WHERE lm.IdGm = :idGm");
    query.bindValue(":idGm", idGm);

    // Execute the SQL query
    if (!query.exec()) {
        // If an error occurs while executing the query, print an error message
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    // Set up dialog window
    QDialog dialog;
    QVBoxLayout *layout = new QVBoxLayout(&dialog);
    QTableView *tableView = new QTableView(&dialog);

    layout->addWidget(tableView);
    dialog.setLayout(layout);

    // Set model for the table view to display material data
    QSqlQueryModel *materialModel = new QSqlQueryModel();
    materialModel->setQuery(std::move(query));
    tableView->setModel(materialModel);

    // Set column headers for better readability (optional)
    materialModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Matiere Name"));
    materialModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Coefficient"));

    // Adjust column widths to fit content (optional)
    tableView->resizeColumnsToContents();

    tableView->setSelectionMode(QAbstractItemView::SingleSelection); // or MultiSelection
    connect(tableView, &QAbstractItemView::clicked, [this, idGm, &tableView](const QModelIndex& clickedIndex) {
        // Retrieve the selected row index
        int clickedRow = clickedIndex.row();

        // Get the model from the table view
        QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(tableView->model());

        if (!model) {
            qDebug() << "Model is null";
            return;
        }

        // Get the IdMat value from the selected row
        QString selectedMat = model->data(model->index(clickedRow, 0)).toString();

        qDebug() << "Selected Matiere Id:" << selectedMat;
        QString selectedIdGRP = ui->grp_comboBox->currentText();
        qDebug() << "Selected grp Id:" << selectedIdGRP;


        // Prepare and execute query to fetch student data based on selected Matiere and idGm
        QSqlQuery queryy;
        queryy.prepare("SELECT DISTINCT e.nom , e.prenom , e.numinsc FROM Etudiant e "
                       "INNER JOIN Liste_Groupe g ON e.numinsc = g.numinsc "
                       "WHERE g.IdGrp = :selectedIdGrp");  // Adding condition for IdGRP
        queryy.bindValue(":selectedIdGrp", selectedIdGRP);  // Bind the selectedIdGRP value

        // Execute the SQL query
        if (!queryy.exec()) {
            // If an error occurs while executing the query, print an error message
            qDebug() << "Error executing query:" << queryy.lastError().text();
            return;
        }

        // Set up dialog window to display student data
        QDialog studentDialog;
        QVBoxLayout *studentLayout = new QVBoxLayout(&studentDialog);
        QTableView *studentTableView = new QTableView(&studentDialog);

        studentLayout->addWidget(studentTableView);
        studentDialog.setLayout(studentLayout);

        // Set model for the table view to display student data
        QSqlQueryModel *studentModel = new QSqlQueryModel();
        studentModel->setQuery(std::move(queryy));
        studentTableView->setModel(studentModel);

        // Set column headers for better readability (optional)
        studentModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Student Numinsc"));
        studentModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
        studentModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Surname"));

        // Adjust column widths to fit content (optional)
        studentTableView->resizeColumnsToContents();

        // Execute the student dialog
        studentDialog.exec();
    });





    // Execute the dialog
    dialog.exec();

}



void note::addNote(){

}


