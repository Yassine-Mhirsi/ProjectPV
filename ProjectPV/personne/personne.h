#ifndef PERSONNE_H
#define PERSONNE_H
#include <iostream>

using namespace std;

class Personne
{
protected:
    int Id;
    string Nom;
    string Prenom;
    string Mail;

public:
    Personne();
    Personne(int, string, string, string);
    friend ostream& operator<<(ostream& os, const Personne& personne);

};

#endif // PERSONNE_H
