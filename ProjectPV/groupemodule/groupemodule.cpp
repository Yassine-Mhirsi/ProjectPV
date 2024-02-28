#pragma GCC diagnostic ignored "-Wunused-parameter"
//or this in .pro :QMAKE_CXXFLAGS += -Wno-unused-parameter
#include "groupemodule.h"
#include "ui_groupemodule.h"

groupemodule::groupemodule(QWidget *parent)
    : QDialog(parent), ui(new Ui::groupemodule) {
    ui->setupUi(this);
}

groupemodule::~groupemodule() {
    delete ui;
}

groupemodule::groupemodule(string id, string nom, float coef, vector<matiere*>* matiere)
    : IdGM(id), NomGM(nom), CoefGM(coef){
    ListeMat = *matiere;
}


ostream& operator<<(ostream& os, const groupemodule& gm) {
    os << "IdGM: " << gm.IdGM << "\n";
    os << "NomGM: " << gm.NomGM << "\n";
    os << "CoefGM: " << gm.CoefGM << "\n";
    os << "ListeMat: \n";
    for (const auto& mat : gm.ListeMat) {
        os << *mat << "\n";
    }
    return os;
}
