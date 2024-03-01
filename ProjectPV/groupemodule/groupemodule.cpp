#pragma GCC diagnostic ignored "-Wunused-parameter"
//or this in .pro :QMAKE_CXXFLAGS += -Wno-unused-parameter
#include "groupemodule.h"
#include "ui_groupemodule.h"
#include <QtSql>
#include <QMessageBox>

groupemodule::groupemodule(QWidget *parent)
    : QDialog(parent), ui(new Ui::groupemodule) {
    ui->setupUi(this);
    connect(ui->add_pushButton, &QPushButton::clicked, this, &groupemodule::addGm);
    connect(ui->matiere_pushButton, &QPushButton::clicked, this, &groupemodule::showMat);
    connect(ui->matiere_tableView, &QTableView::clicked, this, &groupemodule::displayselectedmat);
    connect(ui->gm_tableView, &QTableView::clicked, this, &groupemodule::displaySelectedGm);
    connect(ui->delete_pushButton, &QPushButton::clicked, this, &groupemodule::deleteGm);
    connect(ui->gm_tableView, &QTableView::doubleClicked, this, &groupemodule::ToListeMat);

    PopulateMatiere();
    PopulateGM();
    PopulateLM();
    ui->add_pushButton->hide();
    ui->matiere_tableView->hide();
    ui->idMat_lineEdit->hide();
}

groupemodule::~groupemodule() {delete ui;}

groupemodule::groupemodule(string id, string nom, float coef, vector<matiere*>* matiere): IdGM(id), NomGM(nom), CoefGM(coef){ListeMat = *matiere;}


ostream& operator<<(ostream& os, const groupemodule& gm) {
    os << "IdGM: " << gm.IdGM << "\n";
    os << "NomGM: " << gm.NomGM << "\n";
    os << "CoefGM: " << gm.CoefGM << "\n";
    os << "ListeMat: \n";
    for (const auto& mat : gm.ListeMat) {
        os << *mat << "\n";
    }
    return os;
}

void groupemodule::PopulateMatiere(){
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from Matiere");

    ui->matiere_tableView->setModel(model);
}

void groupemodule::showMat(){
    ui->add_pushButton->show();
    ui->matiere_tableView->show();
}

void groupemodule::PopulateGM(){
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from GroupeModule");

    ui->gm_tableView->setModel(model);
}

void groupemodule::PopulateLM(){
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from Liste_Matiere");

    ui->LM_tableView->setModel(model);
}

void groupemodule::displayselectedmat(const QModelIndex &index){
    // Retrieve the data of the selected matiere
    int row = index.row();
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->matiere_tableView->model());
    QString idMat = model->data(model->index(row, 0)).toString(); // Assuming the first column contains IdMat

    qDebug() << "Selected Matiere ID:" << idMat;

    ui->idMat_lineEdit->setText(idMat);
}


void groupemodule::addGm(){
    QSqlQuery createGMQuery;
    if (!createGMQuery.exec("CREATE TABLE IF NOT EXISTS GroupeModule ("
                            "IdGm TEXT PRIMARY KEY,"
                            "NomGm TEXT NOT NULL,"
                            "CoefGm REAL)")) { // Added closing parenthesis for the CREATE TABLE statement
        qDebug() << "Error creating table:" << createGMQuery.lastError().text();
        return;
    } else {
        qDebug() << "Table created successfully";
    }

    QSqlQuery createLMQuery;
    if (!createLMQuery.exec("CREATE TABLE IF NOT EXISTS Liste_Matiere ("
                            "IdGm TEXT,"
                            "IdMat INTEGER,"
                            "PRIMARY KEY (IdGm, IdMat),"
                            "FOREIGN KEY (IdGm) REFERENCES GroupeModule(IdGm),"
                            "FOREIGN KEY (IdMat) REFERENCES Matiere(IdMat))")) { // Added closing parenthesis for the CREATE TABLE statement
        qDebug() << "Error creating table LISTEMAT:" << createLMQuery.lastError().text();
        return;
    } else {
        qDebug() << "Table created successfully";
    }


    QString idGm = ui->IdGM_lineEdit->text();
    QString nomGm = ui->name_lineEdit->text();
    double coefGm = ui->coef_doubleSpinBox->value();

    if (idGm.isEmpty()) {
        QMessageBox::critical(this, "Error", "Matiere id number cannot be empty");
        return;
    }

    if (nomGm.isEmpty()) {
        QMessageBox::critical(this, "Error", "Matiere name cannot be empty");
        return;
    }

    if (coefGm==0) {
        QMessageBox::critical(this, "Error", "Matiere coefGm number cannot 0");
        return;
    }


    // Insert data into the database
    QSqlQuery insertGMQuery;
    insertGMQuery.prepare("INSERT INTO GroupeModule VALUES (:IdGm,:nomMat, :coefGm)");
    insertGMQuery.bindValue(":IdGm", idGm);
    insertGMQuery.bindValue(":nomMat", nomGm);
    insertGMQuery.bindValue(":coefGm", coefGm);

    if (!insertGMQuery.exec()) {
        qDebug() << "Error inserting data:" << insertGMQuery.lastError().text();
    } else {
        qDebug() << "Data inserted successfully";
        // clearLineEdits();
        // Optionally, you can update your UI or perform any other action here
    }
    // PopulateMatiere();



    QString id = ui->idMat_lineEdit->text();

    if (id.isEmpty()) {
        QMessageBox::critical(this, "Error", "Select Matiere !!!");
        return;
    }

    // Insert data into the database
    QSqlQuery insertLMQuery;
    insertLMQuery.prepare("INSERT INTO Liste_Matiere (IdGm, IdMat) VALUES (:IdGm, :IdMat)");
    insertLMQuery.bindValue(":IdGm", idGm);
    insertLMQuery.bindValue(":IdMat", id);

    if (!insertLMQuery.exec()) {
        qDebug() << "Error inserting data:" << insertLMQuery.lastError().text();
        QMessageBox::critical(this, "Error", "UNIQUE constraint failed: Liste_Matiere.IdGm, Liste_Matiere.IdMat Unable to fetch row");
    } else {
        qDebug() << "Data inserted successfully";
        // clearLineEdits();
        // Optionally, you can update your UI or perform any other action here
    }
    PopulateGM();
    PopulateLM();
}

void groupemodule::displaySelectedGm(const QModelIndex &index) {
    int row = index.row();
    // ui->clear_pushButton->show();

    // Retrieve the data of the selected matiere
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->gm_tableView->model());
    QString idGm = model->data(model->index(row, 0)).toString(); // Assuming the first column contains IdMat
    QString nomGm = model->data(model->index(row, 1)).toString(); // Assuming the second column contains NomMat
    double coefGm = model->data(model->index(row, 2)).toDouble(); // Assuming the third column contains Coef
    // int enseignantId = model->data(model->index(row, 3)).toInt(); // Assuming the fourth column contains Ens

    // Populate line edits with the selected matiere's information
    ui->IdGM_lineEdit->setText(idGm);
    ui->name_lineEdit->setText(nomGm);
    ui->coef_doubleSpinBox->setValue(coefGm);

    // Show the modify button
    // ui->modify_pushButton->show();
    // ui->delete_pushButton->show();
    // ui->id_label->show();
    // ui->id_lineEdit->show();
}


void groupemodule::deleteGm() {
    // Retrieve the student ID from the line edit or any other suitable method
    QString idGm = ui->IdGM_lineEdit->text();

    // Confirm deletion with the user (optional)
    QMessageBox::StandardButton reply = QMessageBox::critical(this, "Delete GM",
                                                              "Are you sure you want to delete this GroupeModule?",
                                                              QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No)
        return;

    // Delete student information from the database
    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM GroupeModule WHERE IdGm = :idGm");
    deleteQuery.bindValue(":idGm", idGm);

    if (!deleteQuery.exec()) {
        qDebug() << "Error deleting data:" << deleteQuery.lastError().text();
    } else {
        qDebug() << "Data deleted successfully";
         // Refresh the table view to reflect changes
        // clearLineEdits(); // Optionally clear the line edits after deletion
    }


    QSqlQuery deleteLMQuery;
    deleteLMQuery.prepare("DELETE FROM Liste_Matiere WHERE IdGm = :idGm");
    deleteLMQuery.bindValue(":idGm", idGm);
    if (!deleteLMQuery.exec()) {
        qDebug() << "Error deleting row from Liste_Matiere:" << deleteLMQuery.lastError().text();
        return;
    }
    PopulateGM();
    PopulateLM();
    // ui->delete_pushButton->hide();
    // ui->modify_pushButton->hide();
    // ui->id_label->hide();
    // ui->id_lineEdit->hide();
}

void groupemodule::ToListeMat(const QModelIndex &index) {
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
    QPushButton *deleteButton = new QPushButton("Delete Selected Row", &dialog);

    layout->addWidget(tableView);
    layout->addWidget(deleteButton);
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

    // Connect the clicked signal of the tableView to the displayselectedmat slot
    connect(tableView, &QTableView::clicked, this, &groupemodule::displayselectedmat);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection); // or MultiSelectio
    disconnect(deleteButton, &QPushButton::clicked, nullptr, nullptr);


    connect(deleteButton, &QPushButton::clicked, this, [=]() {
        // Get the currently selected row index from the tableView
        int selectedRow = tableView->currentIndex().row();

        // Check if a row is selected
        if (selectedRow >= 0) {
            // Get the IdMat value from the selected row
            QString idMat = materialModel->data(materialModel->index(selectedRow, 0)).toString();
            qDebug() << "Selected Matiere ID:" << idMat;

            // Prepare SQL query to delete the selected row from Liste_Matiere
            QSqlQuery deleteQuery;
            deleteQuery.prepare("DELETE FROM Liste_Matiere WHERE IdGm = :idGm AND IdMat = :idMat");
            deleteQuery.bindValue(":idGm", idGm);
            deleteQuery.bindValue(":idMat", idMat);

            // Execute the delete query
            if (!deleteQuery.exec()) {
                // If an error occurs while executing the query, print an error message
                qDebug() << "Error deleting row from Liste_Matiere:" << deleteQuery.lastError().text();
                return;
            }

            // Remove the row from the table view
            materialModel->removeRow(selectedRow);


            // Prepare the SQL query
            QSqlQuery query;
            query.prepare("SELECT m.IdMat, m.NomMat, m.Coef "
                          "FROM Matiere AS m "
                          "INNER JOIN Liste_Matiere AS lm ON m.IdMat = lm.IdMat "
                          "WHERE lm.IdGm = :idGm");

            // Bind the value of idGm to the placeholder
            query.bindValue(":idGm", idGm);

            // Execute the query
            if (!query.exec()) {
                // If an error occurs while executing the query, print an error message
                qDebug() << "Error executing query:" << query.lastError().text();
                return;
            }

            // Set the query model for the table view
            QSqlQueryModel *mod = new QSqlQueryModel();
            mod->setQuery(std::move(query));
            tableView->setModel(mod);



        } else {
            qDebug() << "No rows selected"; // Debug output to indicate that no rows are selected
        }

    });




    dialog.exec();
}




