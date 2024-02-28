#include "./mainwindow/mainwindow.h"
#include "./welcome/welcome.h"
#include "./database/databasemanager.h"
#include "etudiant/etudiant.h"
#include "enseignant/enseignant.h"
#include "matiere/matiere.h"
#include "groupemodule/groupemodule.h"
#include "groupe/groupe.h"
#include "note/note.h"
#include <vector>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Welcome we;
    we.show();

    QObject::connect(&a, &QApplication::aboutToQuit, [&]() {
        QSqlDatabase db = DatabaseManager::instance().database();
        if (db.isOpen()) {
            db.close();
            qDebug() << "Database connection closed";
        } else {
            qDebug() << "Database connection already closed";
        }
    });


    // enseignant* ens = new enseignant(1, "bachir", "boubou", "bachir@gmail.com", 11);

    // etudiant* etudiant1 = new etudiant(2, "yassine", "mhirsi", "yassine@gmail.com", 21318);
    // etudiant* etudiant2 = new etudiant(3, "ahmed", "benazzouz", "ahmed@gmail.com", 21399);

    // matiere* mat1 = new matiere("1", "Java", 3, ens);
    // matiere* mat2 = new matiere("2", "C++", 3, ens);

    // vector<matiere*> listeMat;
    // listeMat.push_back(mat1);
    // listeMat.push_back(mat2);

    // vector<etudiant*> listeEtudiants;
    // listeEtudiants.push_back(etudiant1);
    // listeEtudiants.push_back(etudiant2);

    // groupemodule* gm1 = new groupemodule("GM1", "Info", 6,&listeMat);
    // vector<groupemodule*> listegm;
    // listegm.push_back(gm1);
    // groupe grp("G1", "1ere", "ING", "INF", 2, &listegm, &listeEtudiants);

    // note n1(mat1,etudiant1,14,"TP");
    // cout << etudiant1;





    return a.exec();
}
