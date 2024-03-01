#ifndef GROUPEMODULE_H
#define GROUPEMODULE_H

#include <QDialog>
#include <vector>
#include <string>
#include "matiere/matiere.h" // You need to include the header file for matiere here

namespace Ui {
class groupemodule;
}

class groupemodule : public QDialog {
    Q_OBJECT

public:
    explicit groupemodule(QWidget *parent = nullptr);
    groupemodule(string, string, float, vector<matiere*>*);
    ~groupemodule();
    friend ostream& operator<<(ostream& os, const groupemodule& gm);
    string getIdGM() const {return IdGM;}
    void PopulateMatiere();
    void addGm();
    void displayselectedmat(const QModelIndex &index);
    void PopulateGM();
    void showMat();
    void PopulateLM();
    void deleteGm();
    void displaySelectedGm(const QModelIndex &index);
    void ToListeMat(const QModelIndex &index);
private:
    string IdGM;
    string NomGM;
    float CoefGM;
    vector<matiere*> ListeMat;
    Ui::groupemodule *ui;
};

#endif // GROUPEMODULE_H


