#include "groupe.h"
#include "ui_groupe.h"

groupe::groupe(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::groupe)
{
    ui->setupUi(this);
}

groupe::groupe(string id, string niveau, string diplome, string specialite, int num, vector<groupemodule*>* listemodules, vector<etudiant*>* listeetudiants)
    : IdGRP(id), Niveau(niveau), Diplome(diplome), Specialite(specialite), Num_G(num) {
    ListeModules = *listemodules;
    ListeEtudiants = *listeetudiants;
};


groupe::~groupe() {
    delete ui;
}

std::ostream& operator<<(std::ostream& os, const groupe& grp) {
    os << "IdGRP: " << grp.IdGRP << "\n";
    os << "Niveau: " << grp.Niveau << "\n";
    os << "Diplome: " << grp.Diplome << "\n";
    os << "Specialite: " << grp.Specialite << "\n";
    os << "Num_G: " << grp.Num_G << "\n";
    os << "ListeModules: \n";
    for (const auto& module : grp.ListeModules) {
        os << *module << "\n";
    }
    os << "ListeEtudiants: \n";
    for (const auto& etudiant : grp.ListeEtudiants) {
        os << *etudiant << "\n";
    }
    return os;
}
