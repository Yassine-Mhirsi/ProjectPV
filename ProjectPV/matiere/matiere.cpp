#pragma GCC diagnostic ignored "-Wunused-parameter"
#include "matiere.h"
#include "ui_matiere.h"
#include <QStandardItemModel>
#include <QStandardItem>


matiere::matiere(QWidget *parent)
    : QDialog(parent), ui(new Ui::matiere) {
    ui->setupUi(this);
    PopulateMatiere();
}

matiere::matiere(string id, string nomMat, float coef, enseignant* ens): IdMat(id), NomMat(nomMat), Coef(coef), Ens(ens) {}

matiere::~matiere() {
    delete ui;
}

ostream& operator<<(ostream& os, const matiere& mat) {
    os << "IdMat: " << mat.IdMat << "\n";
    os << "NomMat: " << mat.NomMat << "\n";
    os << "Coef: " << mat.Coef << "\n";
    os << "Enseignant: " << *(mat.Ens) << "\n";
    return os;
}


void matiere::PopulateMatiere() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT nom FROM Enseignant");

    ui->comboBox->clear(); // Clear existing items

    ui->comboBox->addItem("Select Teacher"); // Add "Select Teacher" as the first item

    int rowCount = model->rowCount();
    for (int i = 0; i < rowCount; ++i) {
        QString teacherName = model->record(i).value("nom").toString();
        ui->comboBox->addItem(teacherName); // Add each teacher name to the combo box
    }
}

