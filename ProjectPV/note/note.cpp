#include "note.h"
#include "qboxlayout.h"
#include "qlabel.h"
#include "qspinbox.h"
#include <QStandardItemModel>
#include <QStandardItem>
#include "ui_note.h"
#include <iostream>
#include <ostream>
#include <QSqlQueryModel>
#include <QMessageBox>


note::note(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::note)
{
    ui->setupUi(this);
    connect(ui->note_tableView, &QTableView::clicked, this, &note::displaySelectedNote);
    connect(ui->modify_pushButton, &QPushButton::clicked, this, &::note::ModifyNote);
    // connect(ui->pushButton, &QPushButton::clicked, this, &::note::MoyMat);
    connect(ui->grp_comboBox, qOverload<int>(&QComboBox::currentIndexChanged), this, &note::PopulateGM);
    connect(ui->gm_tableView, &QTableView::doubleClicked, this, &::note::ToListeGRP);
    PopulateGRP();
    PopulateNote();
    MoyMat();
    PopulateMoyMat();
    MoyGm();
    PopulateMoyGm();
    MoyGenerale();
    PopulateMoyGenerale();
    pv();
    connect(ui->grp_comboBox, qOverload<int>(&QComboBox::currentIndexChanged), this, &note::pv);
    // createStudentAverageView();
    // calculateStudentAverage();

}

note::~note(){delete ui;}


note::note(matiere* mat, etudiant* etu, float note, string type) :Mat(mat), Etu(etu), Note(note), Type(type) {}


std::ostream& operator<<(std::ostream& os, const note& grade) {
    os << "Matiere: " << *(grade.Mat) << "\n";
    os << "Etudiant: " << *(grade.Etu) << "\n";
    os << "Note: "<< grade.Note << endl;
    os << "Type: " << grade.Type << endl;
    return os;
}


void note::PopulateNote(){
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from Note;");

    ui->note_tableView->setModel(model);

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
    model->setQuery(std::move(query));
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
    connect(tableView, &QAbstractItemView::doubleClicked, [this, idGm, &tableView](const QModelIndex& clickedIndex) {
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
        queryy.prepare("SELECT DISTINCT e.numinsc,e.prenom, e.nom FROM Etudiant e "
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

        connect(studentTableView, &QAbstractItemView::doubleClicked, [ idGm, &studentTableView, &selectedMat](const QModelIndex& clickedIndex) {
            // Retrieve the selected row index
            int clickedRow = clickedIndex.row();

            // Get the model from the table view
            QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(studentTableView->model());

            if (!model) {
                qDebug() << "Model is null";
                return;
            }

            // Get the student's numinsc value from the selected row
            QString selectedNuminsc = model->data(model->index(clickedRow, 0)).toString();
            qDebug() << "Selected Student Numinsc:" << selectedNuminsc;

            // Create a new dialog for adding notes
            QDialog addNoteDialog;
            QVBoxLayout *addNoteLayout = new QVBoxLayout(&addNoteDialog);
            QLabel *titleLabel = new QLabel("Add Note for Student: " + selectedNuminsc, &addNoteDialog);

            // Add combobox for selecting the note type
            QComboBox *noteTypeComboBox = new QComboBox(&addNoteDialog);
            // Add items to the combobox (you may need to populate it with your note types)
            noteTypeComboBox->addItem("Select Type");
            noteTypeComboBox->addItem("DS");
            noteTypeComboBox->addItem("EXAM");
            noteTypeComboBox->addItem("TP");

            // Add more items as necessary
            addNoteLayout->addWidget(titleLabel);
            addNoteLayout->addWidget(noteTypeComboBox);

            // Add doublespinbox for entering the note value
            QDoubleSpinBox *noteValueSpinBox = new QDoubleSpinBox(&addNoteDialog);
            // Set properties for the doublespinbox (e.g., range, precision, etc.)
            noteValueSpinBox->setRange(0.0, 20.0); // Example range
            noteValueSpinBox->setSingleStep(0.25); // Example step
            addNoteLayout->addWidget(noteValueSpinBox);

            // Add submit button
            QPushButton *submitButton = new QPushButton("Submit", &addNoteDialog);
            addNoteLayout->addWidget(submitButton);

            // Connect submit button click signal to a slot to handle submission
            connect(submitButton, &QPushButton::clicked, [&selectedMat,selectedNuminsc, &addNoteDialog, noteTypeComboBox, noteValueSpinBox]() {
                // Retrieve selected note type
                QString selectedNoteType = noteTypeComboBox->currentText();
                // Retrieve entered note value
                double noteValue = noteValueSpinBox->value();


                // You can perform validation or further processing here

                // Print selected data for debugging
                qDebug() << "Selected Note Type:" << selectedNoteType;
                qDebug() << "Entered Note Value:" << noteValue;



                if (selectedNoteType == "Select Type") {
                    QMessageBox::critical(&addNoteDialog, "Error", "Please select a note type");
                    return;
                }

                if (noteValue == 0.0) {
                    QMessageBox::critical(&addNoteDialog, "Error", "Please a valid note value");
                    return;
                }


                QSqlQuery query;
                query.prepare("CREATE TABLE IF NOT EXISTS Note ("
                              "Mat TEXT,"
                              "Etu TEXT,"
                              "Note REAL,"
                              "Type TEXT,"
                              "PRIMARY KEY (Mat, Etu, Type),"
                              "FOREIGN KEY (Mat) REFERENCES Matiere(IdMat),"
                              "FOREIGN KEY (Etu) REFERENCES Etudiant(numinsc)"
                              ")");
                if (!query.exec()) {
                    qDebug() << "Error creating table Note:" << query.lastError().text();
                } else {
                    qDebug() << "Note table created successfully!";
                }


                // Insert data into the database
                QSqlQuery insertQuery;
                insertQuery.prepare("INSERT INTO Note (Mat, Etu, Note, Type) VALUES (:Mat, :Etu, :Note, :Type)");
                insertQuery.bindValue(":Mat", selectedMat); // Assuming selectedMat corresponds to Mat
                insertQuery.bindValue(":Etu", selectedNuminsc); // Binding student's numinsc
                insertQuery.bindValue(":Note", noteValue); // Binding entered note value
                insertQuery.bindValue(":Type", selectedNoteType); // Binding selected note type

                if (!insertQuery.exec()) {
                    qDebug() << "Error inserting data:" << insertQuery.lastError().text();
                } else {
                    qDebug() << "Data inserted successfully";
                    // Optionally, you can update your UI or perform any other action here
                    QMessageBox::information(&addNoteDialog, "Success", "Note added successfully");
                }
                // Close the dialog after submission
                addNoteDialog.close();
            });
            // Set the layout for the dialog and execute it
            addNoteDialog.setLayout(addNoteLayout);
            addNoteDialog.exec();
        });

        // Execute the student dialog
        studentDialog.exec();
    });
    // Execute the dialog
    dialog.exec();
    MoyMat();
    PopulateMoyMat();
    MoyGm();
    PopulateMoyGm();
    PopulateNote();
    MoyGenerale();
    PopulateMoyGenerale();
}

void note::displaySelectedNote(const QModelIndex &index) {
    int row = index.row();

    // Retrieve the data of the selected matiere
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->note_tableView->model());
    QString idMat = model->data(model->index(row, 0)).toString();
    QString idEtu = model->data(model->index(row, 1)).toString();
    double note = model->data(model->index(row, 2)).toDouble();
    QString type = model->data(model->index(row, 3)).toString();

    // Populate line edits with the selected matiere's information
    ui->idmat_lineEdit->setText(idMat);
    ui->idetu_lineEdit->setText(idEtu);
    ui->doubleSpinBox->setValue(note);
    ui->type_lineEdit->setText(type); // Set the text for type_lineEdit

}



void note::ModifyNote() {
    // Retrieve the data from line edits
    QString idMat = ui->idmat_lineEdit->text();
    QString idEtu = ui->idetu_lineEdit->text();
    double newNote = ui->doubleSpinBox->value();
    QString type = ui->type_lineEdit->text();

    // Prepare the SQL query to update the note
    QSqlQuery query;
    query.prepare("UPDATE Note SET Note = :newNote WHERE Mat = :idMat AND Etu = :idEtu AND Type = :type");
    query.bindValue(":newNote", newNote);
    query.bindValue(":idMat", idMat);
    query.bindValue(":idEtu", idEtu);
    query.bindValue(":type", type);


    // Execute the query
    if (!query.exec()) {
        qDebug() << "Error modifying note:" << query.lastError().text();
    } else {
        qDebug() << "Note modified successfully!";
        // Optionally, you can update the view or perform other actions here
    }
    PopulateNote();
    MoyMat();
    PopulateMoyMat();
    MoyGm();
    PopulateMoyGm();
    MoyGenerale();
    PopulateMoyGenerale();
}


void note::PopulateMoyMat(){
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from MoyMat;");

    ui->moymat_tableView->setModel(model);
}


void note::MoyMat() {
    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS MoyMat ("
                  "numinsc INTEGER,"
                  "IdMat INTEGER,"
                  "Moy REAL,"
                  "PRIMARY KEY (numinsc, IdMat),"
                  "FOREIGN KEY (numinsc) REFERENCES Etudiant(numinsc),"
                  "FOREIGN KEY (IdMat) REFERENCES Matiere(IdMat)"
                  ")");
    if (!query.exec()) {
        qDebug() << "Error creating table MoyMat:" << query.lastError().text();
        return; // Exit if table creation fails
    } else {
        qDebug() << "MoyMat table created successfully!";
    }

    // Prepare SQL query to calculate and update the average MoyMat for each student for each subject
    QSqlQuery updateQuery;
    updateQuery.prepare("INSERT OR REPLACE INTO MoyMat (numinsc, IdMat, Moy) "
                        "SELECT Etu, Mat, AVG(Note) "
                        "FROM Note "
                        "GROUP BY Etu, Mat");

    // Execute the update query
    if (!updateQuery.exec()) {
        // If an error occurs while executing the query, print an error message
        qDebug() << "Error updating average MoyMat for all students:" << updateQuery.lastError().text();
    } else {
        qDebug() << "Average MoyMat updated successfully for all students";
    }
    PopulateNote(); // Make sure this function is defined and called correctly
    PopulateMoyMat();
    MoyGm();
    PopulateMoyGm();
    MoyGenerale();
    PopulateMoyGenerale();
}

void note::PopulateMoyGm(){
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from MoyGm;");

    ui->moygm_tableView->setModel(model);
}


void note::MoyGm() {
    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS MoyGm ("
                  "numinsc INTEGER,"
                  "IdGm TEXT,"
                  "Moy REAL,"
                  "PRIMARY KEY (numinsc, IdGm),"
                  "FOREIGN KEY (numinsc) REFERENCES Etudiant(numinsc),"
                  "FOREIGN KEY (IdGm) REFERENCES GroupeModule(IdGm)"
                  ")");
    if (!query.exec()) {
        qDebug() << "Error creating table MoyGm:" << query.lastError().text();
        return; // Exit if table creation fails
    } else {
        qDebug() << "MoyGm table created successfully!";
    }

    // Prepare SQL query to calculate and update the average MoyGm for each student for each group of subjects
    QSqlQuery updateQuery;
    updateQuery.prepare("INSERT OR REPLACE INTO MoyGm (numinsc, IdGm, Moy) "
                        "SELECT LG.numinsc, LM.IdGm, SUM(MM.Moy * M.Coef) / SUM(M.Coef) "
                        "FROM Liste_Groupe AS LG "
                        "JOIN MoyMat AS MM ON LG.numinsc = MM.numinsc "
                        "JOIN Matiere AS M ON MM.IdMat = M.IdMat "
                        "JOIN Liste_Matiere AS LM ON MM.IdMat = LM.IdMat "
                        "GROUP BY LG.numinsc, LM.IdGm");

    // Execute the update query
    if (!updateQuery.exec()) {
        // If an error occurs while executing the query, print an error message
        qDebug() << "Error updating average MoyGm for all students:" << updateQuery.lastError().text();
    } else {
        qDebug() << "Average MoyGm updated successfully for all students";
    }
    PopulateMoyGm();
}


void note::PopulateMoyGenerale(){
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from MoyGenerale;");

    ui->moy_tableView->setModel(model);
}


void note::MoyGenerale() {
    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS MoyGenerale ("
                  "numinsc INTEGER,"
                  "Moy REAL,"
                  "Resultat TEXT,"
                  "Mention TEXT,"
                  "PRIMARY KEY (numinsc),"
                  "FOREIGN KEY (numinsc) REFERENCES Etudiant(numinsc)"
                  ")");
    if (!query.exec()) {
        qDebug() << "Error creating table MoyGenerale:" << query.lastError().text();
        return; // Exit if table creation fails
    } else {
        qDebug() << "MoyGenerale table created successfully!";
    }

    // Prepare SQL query to calculate and update the general average MoyGenerale for each student
    QSqlQuery updateQuery;
    updateQuery.prepare("INSERT OR REPLACE INTO MoyGenerale (numinsc, Moy, Resultat, Mention) "
                        "SELECT numinsc, SUM(Moy * CoefGm) / SUM(CoefGm), "
                        "CASE WHEN SUM(Moy * CoefGm) / SUM(CoefGm) > 10 THEN 'Admis' ELSE 'Ajourné' END, "
                        "CASE "
                        "WHEN SUM(Moy * CoefGm) / SUM(CoefGm) >= 18 THEN 'Excellent' "
                        "WHEN SUM(Moy * CoefGm) / SUM(CoefGm) >= 16 THEN 'Très Bien' "
                        "WHEN SUM(Moy * CoefGm) / SUM(CoefGm) >= 14 THEN 'Bien' "
                        "WHEN SUM(Moy * CoefGm) / SUM(CoefGm) >= 12 THEN 'Assez Bien' "
                        "WHEN SUM(Moy * CoefGm) / SUM(CoefGm) >= 10 THEN 'Passable' "
                        "ELSE '' END "
                        "FROM MoyGm "
                        "JOIN GroupeModule ON MoyGm.IdGm = GroupeModule.IdGm "
                        "GROUP BY numinsc");

    // Execute the update query
    if (!updateQuery.exec()) {
        // If an error occurs while executing the query, print an error message
        qDebug() << "Error updating general average MoyGenerale for all students:" << updateQuery.lastError().text();
    } else {
        qDebug() << "General average MoyGenerale updated successfully for all students";
    }
    PopulateMoyGenerale();
}

void note::pv(){

    QStandardItemModel *model = new QStandardItemModel(0, 0);
    QList<QStandardItem *> rowItems;
    QSqlQuery query;
    QString selectedGroupID = ui->grp_comboBox->currentText();
    for (int i = 0; i < 3; ++i) {
        QStandardItem *item = new QStandardItem("");
        item->setEditable(false);
        rowItems << item;
    }


    ui->pv_tableView->setSpan(0, 0, 1, 3);
    model->appendRow(rowItems);

    model->setHorizontalHeaderLabels({"Num Insc", "Nom", "Prenom"});

    query.prepare("SELECT e.numinsc, e.nom, e.prenom FROM Etudiant e, Liste_Groupe GMM WHERE GMM.numinsc = e.numinsc AND GMM.IdGRP = :idg");
    query.bindValue(":idg", selectedGroupID);

    if (!query.exec()) {
        qDebug() << "Error executing query";
        return;
    }

    int row = 0;
    while (query.next()) {
        QString numInsc = query.value(0).toString();
        QString nom = query.value(1).toString();
        QString prenom = query.value(2).toString();

        QList<QStandardItem *> studentItems;
        studentItems << new QStandardItem(numInsc);
        studentItems << new QStandardItem(nom);
        studentItems << new QStandardItem(prenom);

        model->insertRow(row + 1, studentItems);

        row++;
    }



    // for (int row = 1; row < model->rowCount(); ++row) {
    //     QString numInsc = model->item(row, 0)->text();
    //     qDebug() << "Numinsc:" << numInsc;
    //     for (int col = 3; model->columnCount();++col){

    //     }

    // }

    ui->pv_tableView->setModel(model);
}









