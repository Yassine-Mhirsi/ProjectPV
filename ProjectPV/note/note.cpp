#include "note.h"
#include "ui_note.h"
#include <iostream>
#include <ostream>

note::note(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::note)
{
    ui->setupUi(this);
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

