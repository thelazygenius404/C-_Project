#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class terrain
{
    string nom;
    int capacite;
    string emplacement;

public:
    terrain(string n = "", int c = 0, string emp = "") : nom(n), capacite(c), emplacement(emp) {}
    string getNom() const { return nom; }
    friend ostream &operator<<(ostream &, const terrain &);
    friend istream &operator>>(istream &, terrain &);
    int getCapacite()const{return capacite;}
    terrain& operator=(const terrain& other) {
        if (this != &other) {
         nom = other.nom;
         capacite = other.capacite;
         emplacement = other.emplacement;
        }
        return *this;
    }
};
istream &operator>>(istream &in, terrain &t)
{
    cout << "Nom de terrain: ";
    in >> t.nom;
    cout << "Capacite: ";
    in >> t.capacite;
    cout << "Emplacement: ";
    in >> t.emplacement;
    return in;
}
ostream &operator<<(ostream &os, const terrain &t)
{
    os << "Nom de terrain: " << t.nom << endl
       << "Capacite: " << t.capacite << endl
       << "Emplacement: " << t.emplacement << endl;
    return os;
}
void ajouterTerrain(vector<terrain> &ter)
{
        terrain t;
        cin >> t;
       if (find_if(ter.begin(),ter.end(), [&](const terrain& terr) { return terr.getNom() == t.getNom(); }) != ter.end()) {
            cout <<t.getNom()<< " existe déjà." << endl;
            return;
        }
        ter.push_back(t);
        cout<<t.getNom()<<" est ajoutee"<<endl;
}
void supprimerTerrain(vector<terrain> &ter, const string &nom)
{
    auto it = find_if(ter.begin(), ter.end(), [&](const terrain &t)
                      { return t.getNom() == nom; });
    if (it != ter.end())
    {
        ter.erase(it);
        cout << "Terrain " << nom << " supprimée." << endl;
    }
    else
        cout << "Terrain " << nom << " non trouvée." << endl;
}
void afficherTerrains(vector<terrain> &ter)
{
    for (auto i : ter)
        cout << i;
}
