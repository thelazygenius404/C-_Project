#include <iostream>
#include <string>
#include <vector>
using namespace std;
class arbitre
{
public:
    enum Niveau {
        Debutant,
        Intermediaire,
        Professionnel,
        International
    };
private:
    string nom;
    Niveau n;
public:

    arbitre(string n = "",Niveau niv=Debutant) : nom(n),n(niv) {}
    string afficherNiveau() const {
        switch (n) {
            case Debutant: return "Débutant";
            case Intermediaire: return "Intermédiaire";
            case Professionnel: return "Professionnel";
            case International: return "International";
            default: return "Inconnu";
        }
    }
    void afficher()
    {
        cout << "L'arbitre: " << nom << endl;
        cout << "Niveau: "<<afficherNiveau()<<endl;
    }
    string getNom() const { return nom; }
    Niveau getNiveau() const { return n; }
arbitre& operator=(const arbitre& other) {

        if (this != &other) {
            nom = other.nom;
            n = other.n;
            return *this;
        }
        return *this;
    }
};
void ajouterArbitre(vector<arbitre> &arb, arbitre a)
{
    bool b = false;
    for (auto i : arb)
        if (i.getNom() == a.getNom())
            b = true;
    if (arb.size() < 6 && !b){
        arb.push_back(a);
        cout<<"L'arbitre "<<a.getNom()<<" ajoute"<<endl;}
    else if (b)
        cout << "L'arbitre est deja dans la liste" << endl;
    else
        cout << "La liste est complete" << endl;
}
