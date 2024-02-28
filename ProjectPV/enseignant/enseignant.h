#ifndef ENSEIGNANT_H
#define ENSEIGNANT_H
#include "personne/personne.h"
#include <QDialog>

namespace Ui {
class enseignant;
}

class enseignant : public QDialog, Personne
{
    Q_OBJECT

public:
    explicit enseignant(QWidget *parent = nullptr);
    enseignant(int, string, string, string, int);
    ~enseignant();
    friend ostream& operator<<(ostream& os, const enseignant& teacher);
    void addStudent();
    void populateTableView();
    void displaySelectedStudent(const QModelIndex &index);
    void toggleModifyButtonVisibility();
    void saveStudent();
    void clearLineEdits();
    void customizeTableView();
    void deleteStudent();
    void toggleDeleteButtonVisibility();
    void Clear();
    void searchStudents(const QString &);
    void on_searchbar_textChanged(const QString &arg1);

private:
    int CNSS;
    Ui::enseignant *ui;
};

#endif // ENSEIGNANT_H
