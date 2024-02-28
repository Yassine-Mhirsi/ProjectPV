#include "Personne.h"

Personne::Personne() : Id(0), Nom(""), Prenom(""), Mail("") {}


Personne::Personne(int id, string nom, string prenom, string mail) :Id(id), Nom(nom), Prenom(prenom), Mail(mail) {}


ostream& operator<<(ostream& os, const Personne& personne) {
    os << "Id: " << personne.Id << endl;
    os << "Nom: " << personne.Nom << endl;
    os << "Prenom: " << personne.Prenom << endl;
    os << "Mail: " << personne.Mail << endl;
    return os;
}
