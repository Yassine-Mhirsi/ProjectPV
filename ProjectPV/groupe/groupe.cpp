#include "groupe.h"
#include "ui_groupe.h"
#include <QMessageBox>

groupe::groupe(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::groupe)
{
    ui->setupUi(this);
    ui->hidegm_pushButton->hide();
    ui->hideetu_pushButton->hide();
    ui->gm_label->hide();
    ui->gm_tableView->hide();
    ui->addgm_pushButton->hide();
    ui->etu_label->hide();
    ui->etu_tableView->hide();
    ui->addetu_pushButton->hide();
    PopulateGM();
    PopulateEtu();
    PopulateGRP();
    PopulateLG();
    connect(ui->addgm_pushButton, &QPushButton::clicked, this, &groupe::addGRP_GM);
    connect(ui->addetu_pushButton, &QPushButton::clicked, this, &groupe::addGRP_Etu);
    connect(ui->modify_pushButton, &QPushButton::clicked, this, &groupe::modifyGRP);
    connect(ui->delete_pushButton, &QPushButton::clicked, this, &groupe::deleteGRP);
    connect(ui->gm_tableView, &QTableView::clicked, this, &groupe::displayselectedgm);
    connect(ui->grp_tableView, &QTableView::clicked, this, &groupe::displaySelectedG);
    connect(ui->etu_tableView, &QTableView::clicked, this, &groupe::displayselectedEtu);
    connect(ui->grp_tableView, &QTableView::doubleClicked, this, &::groupe::ToListGRP);
    ui->LG_tableView->hide();
    ui->idgm_lineEdit->hide();
    ui->idetu_lineEdit->hide();
    connect(ui->showgm_pushButton, &QPushButton::clicked, this, &groupe::showGM);
    connect(ui->hidegm_pushButton, &QPushButton::clicked, this, &groupe::hideGM);
    connect(ui->showetu_pushButton, &QPushButton::clicked, this, &groupe::showEtu);
    connect(ui->hideetu_pushButton, &QPushButton::clicked, this, &groupe::hideEtu);



}

groupe::groupe(string id, string niveau, string diplome, string specialite, int num, vector<groupemodule*>* listemodules, vector<etudiant*>* listeetudiants)
    : IdGRP(id), Niveau(niveau), Diplome(diplome), Specialite(specialite), Num_G(num) {
    ListeModules = *listemodules;
    ListeEtudiants = *listeetudiants;};


groupe::~groupe() {delete ui;}

std::ostream& operator<<(std::ostream& os, const groupe& grp) {
    os << "IdGRP: " << grp.IdGRP << "\n";
    os << "Niveau: " << grp.Niveau << "\n";
    os << "Diplome: " << grp.Diplome << "\n";
    os << "Specialite: " << grp.Specialite << "\n";
    os << "Num_G: " << grp.Num_G << "\n";
    os << "ListeModules: \n";
    for (const auto& module : grp.ListeModules) {
        os << *module << "\n";
    }
    os << "ListeEtudiants: \n";
    for (const auto& etudiant : grp.ListeEtudiants) {
        os << *etudiant << "\n";
    }
    return os;
}

void groupe::showGM(){
    ui->showgm_pushButton->hide();
    ui->hidegm_pushButton->show();
    ui->gm_label->show();
    ui->gm_tableView->show();
    ui->addgm_pushButton->show();
}

void groupe::hideGM(){
    ui->showgm_pushButton->show();
    ui->hidegm_pushButton->hide();
    ui->gm_label->hide();
    ui->gm_tableView->hide();
    ui->addgm_pushButton->hide();
}

void groupe::showEtu(){
    ui->showetu_pushButton->hide();
    ui->hideetu_pushButton->show();
    ui->etu_label->show();
    ui->etu_tableView->show();
    ui->addetu_pushButton->show();
}

void groupe::hideEtu(){
    ui->showetu_pushButton->show();
    ui->hideetu_pushButton->hide();
    ui->etu_label->hide();
    ui->etu_tableView->hide();
    ui->addetu_pushButton->hide();
}

void groupe::customizeTableView() {
    ui->grp_tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->grp_tableView->horizontalHeader()->resizeSection(0, 60);

    ui->grp_tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->grp_tableView->horizontalHeader()->resizeSection(1, 90);

    ui->grp_tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->grp_tableView->horizontalHeader()->resizeSection(2, 80);

    ui->grp_tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->grp_tableView->horizontalHeader()->resizeSection(3, 180);
}


void groupe::PopulateGM(){
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from GroupeModule");

    ui->gm_tableView->setModel(model);
}

void groupe::PopulateEtu(){
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from Etudiant");

    ui->etu_tableView->setModel(model);}

void groupe::PopulateGRP(){
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from Groupe");

    ui->grp_tableView->setModel(model);
}

void groupe::PopulateLG(){
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from Liste_Groupe");

    ui->LG_tableView->setModel(model);
}

void groupe::displayselectedgm(const QModelIndex &index){
    // Retrieve the data of the selected matiere
    int row = index.row();
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->gm_tableView->model());
    QString idMat = model->data(model->index(row, 0)).toString(); // Assuming the first column contains IdMat

    qDebug() << "Selected GroupeModule ID:" << idMat;

    ui->idgm_lineEdit->setText(idMat);
}

void groupe::displayselectedEtu(const QModelIndex &index){
    // Retrieve the data of the selected matiere
    int row = index.row();
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->etu_tableView->model());
    QString idMat = model->data(model->index(row, 0)).toString(); // Assuming the first column contains IdMat

    qDebug() << "Selected Etudiant ID:" << idMat;

    ui->idetu_lineEdit->setText(idMat);
}

void groupe::displaySelectedG(const QModelIndex &index) {
    int row = index.row();
    // ui->clear_pushButton->show();

    // Retrieve the data of the selected matiere
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->grp_tableView->model());
    QString idG = model->data(model->index(row, 0)).toString(); // Assuming the first column contains IdMat
    QString niv = model->data(model->index(row, 1)).toString(); // Assuming the second column contains NomMat
    QString dip = model->data(model->index(row, 2)).toString(); // Assuming the second column contains NomMat
    QString spec = model->data(model->index(row, 3)).toString(); // Assuming the second column contains NomMat
    QString numg = model->data(model->index(row, 4)).toString(); // Assuming the second column contains NomMat

    // Populate line edits and combobox with the selected groupe's information
    ui->idGRP_lineEdit->setText(idG);
    ui->niv_comboBox->setCurrentText(niv);
    ui->dip_comboBox->setCurrentText(dip);
    ui->spec_comboBox->setCurrentText(spec);
    ui->numg_comboBox->setCurrentText(numg);

    // Show the modify button
    // ui->modify_pushButton->show();
    // ui->delete_pushButton->show();
    // ui->id_label->show();
    // ui->id_lineEdit->show();
}

void groupe::addGRP_GM(){
    QSqlQuery createGMQuery;
    if (!createGMQuery.exec("CREATE TABLE IF NOT EXISTS Groupe ("
                            "IdGRP TEXT PRIMARY KEY,"
                            "Niveau TEXT,"
                            "Diplôme TEXT,"
                            "Spécialité TEXT,"
                            "Num_G INTEGER)")) {
        qDebug() << "Error creating table:" << createGMQuery.lastError().text();
        return;
    } else {
        qDebug() << "Table created successfully";
    }
    QSqlQuery createLMQuery;
    if (!createLMQuery.exec("CREATE TABLE IF NOT EXISTS Liste_Groupe ("
                            "IdGRP TEXT,"
                            "IdGm TEXT,"
                            "numinsc number(5),"
                            "PRIMARY KEY (IdGRP, IdGm, numinsc),"
                            "FOREIGN KEY (IdGRP) REFERENCES Groupe(IdGRP),"
                            "FOREIGN KEY (IdGm) REFERENCES GroupeModule(IdGm),"
                            "FOREIGN KEY (numinsc) REFERENCES Etudiant(numinsc))")) { // Added closing parenthesis for the CREATE TABLE statement
        qDebug() << "Error creating table LISTEGRP:" << createLMQuery.lastError().text();
        return;
    } else {
        qDebug() << "Table created successfully";
    }


    QString idGRP = ui->idGRP_lineEdit->text();
    QString niv = ui->niv_comboBox->currentText();
    QString dip = ui->dip_comboBox->currentText();
    QString spec = ui->spec_comboBox->currentText();
    int numg = ui->numg_comboBox->currentText().toInt();


    // Insert data into the database
    QSqlQuery insertGMQuery;
    insertGMQuery.prepare("INSERT INTO Groupe VALUES (:IdGRP,:niv,:dip,:spec,:numg)");
    insertGMQuery.bindValue(":IdGRP", idGRP);
    insertGMQuery.bindValue(":niv", niv);
    insertGMQuery.bindValue(":dip", dip);
    insertGMQuery.bindValue(":spec", spec);
    insertGMQuery.bindValue(":numg", numg);

    if (!insertGMQuery.exec()) {
        qDebug() << "Error inserting data:" << insertGMQuery.lastError().text();
    } else {
        qDebug() << "Data inserted successfully";
        // clearLineEdits();
        // Optionally, you can update your UI or perform any other action here
    }
    PopulateGRP();



    QString idgm = ui->idgm_lineEdit->text();

    if (idgm.isEmpty()) {
        QMessageBox::critical(this, "Error", "Select GroupeModule !!!");
        return;
    }

    // Insert data into the database
    QSqlQuery insertLMQuery;
    insertLMQuery.prepare("INSERT INTO Liste_Groupe (IdGRP,IdGm, numinsc) VALUES (:IdGRP,:IdGm, :numinsc)");
    insertLMQuery.bindValue(":IdGRP", idGRP);
    insertLMQuery.bindValue(":IdGm", idgm);
    insertLMQuery.bindValue(":numinsc", NULL);

    if (!insertLMQuery.exec()) {
        qDebug() << "Error inserting data:" << insertLMQuery.lastError().text();
        QMessageBox::critical(this, "Error", "UNIQUE constraint failed: Liste_Groupe.IdGm, Liste_Matiere.IdMat Unable to fetch row");
    } else {
        qDebug() << "Data inserted successfully";
        // clearLineEdits();
        // Optionally, you can update your UI or perform any other action here
    }
    PopulateGRP();
    PopulateLG();
}

void groupe::addGRP_Etu(){
    QString idetu = ui->idetu_lineEdit->text();
    QString idGRP = ui->idGRP_lineEdit->text();
    // QString idGm = ui->idgm_lineEdit->text();


    if (idetu.isEmpty()) {
        QMessageBox::critical(this, "Error", "Select Etudiant !!!");
        return;
    }

    // Insert data into the database
    QSqlQuery insertLMQuery;
    insertLMQuery.prepare("INSERT INTO Liste_Groupe (IdGRP,IdGm, numinsc) VALUES (:IdGRP,:IdGm, :numinsc)");
    insertLMQuery.bindValue(":IdGRP", idGRP);
    insertLMQuery.bindValue(":IdGm", NULL);
    insertLMQuery.bindValue(":numinsc", idetu);

    if (!insertLMQuery.exec()) {
        qDebug() << "Error inserting data:" << insertLMQuery.lastError().text();
    } else {
        qDebug() << "Data inserted successfully";
        // clearLineEdits();
        // Optionally, you can update your UI or perform any other action here
    }
    PopulateGRP();
    PopulateLG();
}


void groupe::ToListGRP(const QModelIndex &index) {
    // Get the selected row index
    int row = index.row();

    // Get the model from the table view
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->gm_tableView->model());

    // Get the IdGm value from the selected row
    QString idGm = model->data(model->index(row, 0)).toString();
    QString idGRP = ui->idGRP_lineEdit->text();

    qDebug() << "Selected IdGm:" << idGm; // Debug output to check the selected IdGm value

    // Prepare SQL query to retrieve group data associated with the selected GroupeModule
    QSqlQuery query;
    query.prepare("SELECT gm.IdGm, gm.NomGm, gm.CoefGm "
                  "FROM GroupeModule AS gm "
                  "INNER JOIN Liste_Groupe AS lg ON gm.IdGm = lg.IdGm "
                  "WHERE lg.IdGRP = :idGRP");
    query.bindValue(":idGRP", idGRP);

    // Execute the SQL query
    if (!query.exec()) {
        // If an error occurs while executing the query, print an error message
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    // Set up dialog window for displaying group data
    QDialog dialog;
    dialog.setWindowTitle("Group Data");
    dialog.setWindowFlags(Qt::Window);
    dialog.setWindowModality(Qt::WindowModal); // Set window modality to WindowModal
    QVBoxLayout *layout = new QVBoxLayout(&dialog);
    QTableView *tableView = new QTableView(&dialog);
    QPushButton *deleteButton = new QPushButton("Delete Selected Row", &dialog);

    layout->addWidget(tableView);
    layout->addWidget(deleteButton);
    dialog.setLayout(layout);

    // Set model for the table view to display group data
    QSqlQueryModel *groupeModel = new QSqlQueryModel();
    groupeModel->setQuery(std::move(query));
    tableView->setModel(groupeModel);
    tableView->verticalHeader()->setVisible(false);

    // Set column headers for better readability (optional)
    groupeModel->setHeaderData(0, Qt::Horizontal, QObject::tr("IDGRP"));
    groupeModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Niveau"));
    groupeModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Diplôme"));
    groupeModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Spécialité"));
    groupeModel->setHeaderData(4, Qt::Horizontal, QObject::tr("Num_G"));

    // Adjust column widths to fit content (optional)
    tableView->resizeColumnsToContents();

    // Connect the delete button to a slot that handles row deletion from the table view
    connect(deleteButton, &QPushButton::clicked, this, [=]() {
        // Get the currently selected row index from the tableView
        int selectedRow = tableView->currentIndex().row();

        // Check if a row is selected
        if (selectedRow >= 0) {
            // Get the IDGRP value from the selected row
            QString idGRP = groupeModel->data(groupeModel->index(selectedRow, 0)).toString();
            qDebug() << "Selected IDGRP:" << idGRP;

            // Prepare SQL query to delete the selected row from Liste_Groupe
            QSqlQuery deleteQuery;
            deleteQuery.prepare("DELETE FROM Liste_Groupe WHERE IdGRP = :idGRP AND IdGm = :idGm");
            deleteQuery.bindValue(":idGRP", idGRP);
            deleteQuery.bindValue(":idGm", idGm);

            // Execute the delete query
            if (!deleteQuery.exec()) {
                // If an error occurs while executing the query, print an error message
                qDebug() << "Error deleting row from Liste_Groupe:" << deleteQuery.lastError().text();
                return;
            }

            // Remove the row from the table view
            groupeModel->removeRow(selectedRow);
        } else {
            qDebug() << "No rows selected"; // Debug output to indicate that no rows are selected
        }
    });
    dialog.setGeometry(100, 100, 400, 300); // Adjust the position and size as needed

    // Add another dialog for displaying student data
    QDialog studentDialog;
    studentDialog.setWindowTitle("Student Data");
    studentDialog.setWindowFlags(Qt::Window);
    studentDialog.setWindowModality(Qt::WindowModal); // Set window modality to WindowModal
    QVBoxLayout *studentLayout = new QVBoxLayout(&studentDialog);
    QTableView *studentTableView = new QTableView(&studentDialog);

    studentLayout->addWidget(studentTableView);
    studentDialog.setLayout(studentLayout);

    // Prepare SQL query to retrieve student data associated with the selected group
    QSqlQuery studentQuery;
    studentQuery.prepare("SELECT e.* "
                         "FROM Etudiant AS e "
                         "INNER JOIN Liste_Groupe AS lg ON e.numinsc = lg.numinsc "
                         "WHERE lg.IdGRP = :idGRP");
    studentQuery.bindValue(":idGRP", idGRP);

    // Execute the SQL query
    if (!studentQuery.exec()) {
        // If an error occurs while executing the query, print an error message
        qDebug() << "Error executing student query:" << studentQuery.lastError().text();
        return;
    }

    // Set model for the table view to display student data
    QSqlQueryModel *studentModel = new QSqlQueryModel();
    studentModel->setQuery(std::move(studentQuery));
    studentTableView->setModel(studentModel);
    studentTableView->verticalHeader()->setVisible(false);
    studentDialog.setGeometry(600, 100, 400, 300); // Adjust the position and size as needed

    // Set column headers for better readability (optional)
    // Adjust column widths to fit content (optional)


    studentTableView->resizeColumnsToContents();
    // Add delete button to the student dialog
    QPushButton *deleteStudentButton = new QPushButton("Delete Selected Student", &studentDialog);
    studentLayout->addWidget(deleteStudentButton);

    // Connect the delete button to a slot that handles student deletion
    // Connect the delete button to a slot that handles student deletion
    connect(deleteStudentButton, &QPushButton::clicked, this, [=]() {
        // Get the currently selected student row index from the studentTableView
        int selectedStudentRow = studentTableView->currentIndex().row();

        // Check if a student row is selected
        if (selectedStudentRow >= 0) {
            // Get the student's numinsc value from the selected row
            QString selectedNuminsc = studentModel->data(studentModel->index(selectedStudentRow, 0)).toString();
            qDebug() << "Selected Student Numinsc:" << selectedNuminsc;

            // Prepare SQL query to delete the selected student from Liste_Groupe
            QSqlQuery deleteStudentQuery;
            deleteStudentQuery.prepare("DELETE FROM Liste_Groupe WHERE IdGRP = :idGRP AND numinsc = :numinsc");
            deleteStudentQuery.bindValue(":idGRP", idGRP);
            deleteStudentQuery.bindValue(":numinsc", selectedNuminsc);

            // Execute the delete query
            if (!deleteStudentQuery.exec()) {
                // If an error occurs while executing the query, print an error message
                qDebug() << "Error deleting student from Liste_Groupe:" << deleteStudentQuery.lastError().text();
                return;
            } else {
                qDebug() << "Student deleted successfully"; // Debug output to indicate successful deletion
            }

            // Remove the student row from the student model
            studentModel->removeRow(selectedStudentRow);
            studentModel->submit(); // Submit changes to the model

                // Refresh the student table view
            studentTableView->viewport()->update();
        } else {
            qDebug() << "No student row selected"; // Debug output to indicate that no student row is selected
        }
    });





    dialog.show();
    studentDialog.exec();
}

void groupe::deleteGRP() {
    // Retrieve the ID of the group to delete
    QString idGrp = ui->idGRP_lineEdit->text();

    // Check if the ID is empty
    if (idGrp.isEmpty()) {
        qDebug() << "Group ID is empty.";
        // You may want to display an error message to the user here
        return;
    }

    // Prepare the SQL query to delete related rows in Liste_Groupe
    QSqlQuery deleteListeGroupeQuery;
    deleteListeGroupeQuery.prepare("DELETE FROM Liste_Groupe WHERE IdGRP = :idGrp");
    deleteListeGroupeQuery.bindValue(":idGrp", idGrp);

    // Execute the delete query for Liste_Groupe
    if (!deleteListeGroupeQuery.exec()) {
        qDebug() << "Error deleting related rows from Liste_Groupe:" << deleteListeGroupeQuery.lastError().text();
        // You may want to display an error message to the user here
        return; // Return if there's an error to prevent deleting the main group record
    }
    PopulateLG();
    // Prepare the SQL query to delete the group
    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM Groupe WHERE IdGRP = :idGrp");
    deleteQuery.bindValue(":idGrp", idGrp);

    // Execute the delete query for Groupe
    if (!deleteQuery.exec()) {
        qDebug() << "Error deleting group:" << deleteQuery.lastError().text();
        // You may want to display an error message to the user here
    } else {
        qDebug() << "Group deleted successfully";
        PopulateGRP(); // Refresh the table view to reflect changes
    }
}


void groupe::modifyGRP() {
    // Retrieve modified matiere information from line edits
    QString idGrp = ui->idGRP_lineEdit->text();
    QString niv = ui->niv_comboBox->currentText();
    QString dip = ui->dip_comboBox->currentText();
    QString spec = ui->spec_comboBox->currentText();
    int numg = ui->numg_comboBox->currentText().toInt();


    // Update matiere information in the database
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE Groupe SET Niveau = :niv, Diplôme = :dip, Spécialité = :spec ,Num_G =:numg WHERE IdGRP = :idGrp");
    updateQuery.bindValue(":idGrp", idGrp);
    updateQuery.bindValue(":niv", niv);
    updateQuery.bindValue(":dip", dip);
    updateQuery.bindValue(":spec", spec);
    updateQuery.bindValue(":numg", numg);

    if (!updateQuery.exec()) {
        qDebug() << "Error updating data:" << updateQuery.lastError().text();
    } else {
        qDebug() << "Data updated successfully";
        PopulateGRP(); // Refresh the table view to reflect changes
        // ui->modify_pushButton->hide();
    }
    PopulateGRP();
    // ui->delete_pushButton->hide();
    // ui->modify_pushButton->hide();
    // ui->clear_pushButton->hide();
    // ui->id_label->hide();
    // ui->id_lineEdit->hide();

}
