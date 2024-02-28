#ifndef ETUDIANT_H
#define ETUDIANT_H

#include "personne/personne.h"
#include <QDialog>

namespace Ui {
class etudiant;
}

class etudiant : public QDialog, Personne
{
    int Num_insc;
    Q_OBJECT

public:
    explicit etudiant(QWidget *parent = nullptr);
    etudiant(int, string, string, string, int);
    ~etudiant();
    friend std::ostream& operator<<(std::ostream& os, const etudiant& student);
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
    Ui::etudiant *ui;
    bool cancel = false;
};

#endif // ETUDIANT_H
