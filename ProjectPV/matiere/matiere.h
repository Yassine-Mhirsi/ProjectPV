#ifndef MATIERE_H
#define MATIERE_H

#include "./enseignant/enseignant.h"
#include <QDialog>
#include <QtSql>
#include <string> // Include for string

namespace Ui {
class matiere;
}

class matiere : public QDialog {
    Q_OBJECT

private:
    string IdMat;
    string NomMat;
    float Coef;
    enseignant* Ens;

public:
    explicit matiere(QWidget *parent = nullptr);
    matiere(string, string, float, enseignant*);
    ~matiere();
    friend ostream& operator<<(ostream& os, const matiere& mat);
    string getNomMat() const { return NomMat; }
    float getCoef() const { return Coef; }
    void PopulateTeacher();
    void addMatiere();
    void PopulateMatiere();
    void displaySelectedMatiere(const QModelIndex &index);
    void deleteMatiere();
    void modifyMatiere();
    void clearLineEdits();
    void Clear();
    void searchMatiere(const QString &text);
    void on_searchbar_textChanged(const QString &text);

private slots:
    void on_add_teacher_clicked();

private:
    Ui::matiere *ui;
};

#endif // MATIERE_H
