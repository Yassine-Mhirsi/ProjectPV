#include "groupe.h"
#include "ui_groupe.h"
#include <QMessageBox>

groupe::groupe(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::groupe)
{
    ui->setupUi(this);
    PopulateGM();
    PopulateEtu();
    PopulateGRP();
    PopulateLG();
    connect(ui->addgm_pushButton, &QPushButton::clicked, this, &groupe::addGRP_GM);
    connect(ui->addetu_pushButton, &QPushButton::clicked, this, &groupe::addGRP_Etu);
    connect(ui->gm_tableView, &QTableView::clicked, this, &groupe::displayselectedgm);
    connect(ui->grp_tableView, &QTableView::clicked, this, &groupe::displaySelectedG);
    connect(ui->etu_tableView, &QTableView::clicked, this, &groupe::displayselectedEtu);
    connect(ui->grp_tableView, &QTableView::doubleClicked, this, &::groupe::ToListGRP);


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

    // int enseignantId = model->data(model->index(row, 3)).toInt(); // Assuming the fourth column contains Ens

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

    qDebug() << "Selected IdGm:" << idGm; // Debug output to check the selected IdGm value

    // Prepare SQL query to retrieve groupe data associated with the selected GroupeModule
    QSqlQuery query;
    query.prepare("SELECT g.IdGRP, g.Niveau, g.Diplôme, g.Spécialité, g.Num_G "
                  "FROM Groupe AS g "
                  "INNER JOIN Liste_Groupe AS lg ON g.IdGRP = lg.IdGRP "
                  "WHERE lg.IdGm = :idGm");
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
    QPushButton *deleteButton = new QPushButton("Delete Selected Row", &dialog);

    layout->addWidget(tableView);
    layout->addWidget(deleteButton);
    dialog.setLayout(layout);

    // Set model for the table view to display groupe data
    QSqlQueryModel *groupeModel = new QSqlQueryModel();
    groupeModel->setQuery(std::move(query));
    tableView->setModel(groupeModel);

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

    dialog.exec();
}
