#ifndef NOTE_H
#define NOTE_H
#include "matiere/matiere.h"
#include "etudiant/etudiant.h"
#include <ostream>
#include <iostream>

#include <QDialog>

namespace Ui {
class note;
}

class note : public QDialog
{
    Q_OBJECT

public:
    explicit note(QWidget *parent = nullptr);
    note(matiere*, etudiant*, float, string);
    ~note();
    friend std::ostream& operator<<(std::ostream& os, const note& grade);
    void addNote();
    void PopulateGRP();
    void ToListeGRP(const QModelIndex &index);
    void PopulateGM();

private:
    matiere* Mat;
    etudiant* Etu;
    float Note;
    string Type;
    Ui::note *ui;
};

#endif // NOTE_H
