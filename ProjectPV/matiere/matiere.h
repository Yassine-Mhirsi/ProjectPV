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
    void PopulateMatiere();

private:
    Ui::matiere *ui;
};

#endif // MATIERE_H
