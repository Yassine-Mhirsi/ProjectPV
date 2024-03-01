#ifndef GROUPE_H
#define GROUPE_H

#include "groupemodule/groupemodule.h"
#include "etudiant/etudiant.h"
#include <vector>
#include <string>
#include <QDialog>

namespace Ui {
class groupe;
}

class groupe : public QDialog
{
    Q_OBJECT

public:
    explicit groupe(QWidget *parent = nullptr);
    groupe(string, string, string, string, int, vector<groupemodule*>*, vector<etudiant*>*);
    ~groupe();
    friend ostream& operator<<(std::ostream& os, const groupe& grp);
    void PopulateGM();
    void PopulateEtu();
    void PopulateGRP();
    void PopulateLG();
    void addGRP_GM();
    void addGRP_Etu();
    void displayselectedgm(const QModelIndex &index);
    void displayselectedEtu(const QModelIndex &index);
    void displaySelectedG(const QModelIndex &index);
    void ToListGRP(const QModelIndex &index);
private:
    string IdGRP;
    string Niveau;
    string Diplome;
    string Specialite;
    int Num_G;
    vector<groupemodule*> ListeModules;
    vector<etudiant*> ListeEtudiants;
    Ui::groupe *ui;
};

#endif // GROUPE_H
