#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class equipe
{
    string nom;
    int classement;
    int points;
    int matchsJoues;
    int butsPour;
    int butsContre;

public:
    equipe(string n = "", int cl = 0, int p = 0, int mj = 0, int bp = 0, int bc = 0) : nom(n), classement(cl),
            points(p), matchsJoues(mj), butsPour(bp), butsContre(bc) {}
    friend ostream &operator<<(ostream &, const equipe &);
    friend istream &operator>>(istream &, equipe &);
    string getNom() const { return nom; }
    void setClassement(int c) { classement = c; }
    void setPoints(int p) { points += p; }
    void setButcontre(int b) { butsContre += b; }
    void setButpour(int b) { butsPour += b; }
    int getButsPour() const { return butsPour; }
    int getButsContre() const { return butsContre; }
    int getPoints() const { return points; }
    int getClassement()const{return classement;}
    equipe& operator=(const equipe& other) {

        if (this != &other) {
            nom = other.nom;
            classement = other.classement;
            points = other.points;
            matchsJoues = other.matchsJoues;
            butsPour = other.butsPour;
            butsContre = other.butsContre;
        }

        return *this;

    }
    bool operator!=(const equipe& other) {
        if (nom == other.nom) {
            return false;
        }
        else {
            return true;         
        }
    }
};
istream& operator>>(istream& is, equipe& e)
{
    cout << "Nom de l'equipe : ";
    is >> e.nom;
    return is;
}
ostream& operator<<(ostream& os,const equipe& e)
{
    os << "Nom de l'equipe : " << e.nom << endl;
    return os;
}
void supprimerEquipe(vector<equipe>& ve, string nom)
{
    auto it = find_if(ve.begin(), ve.end(), [&](const equipe &e)
                      { return e.getNom() == nom; });
    if (it != ve.end())
    {
        ve.erase(it);
        cout << "Equipe " << nom << " supprimée." << endl;
    }
    else
        cout << "Equipe " << nom << " non trouvée." << endl;
}
void afficherEquipes(vector<equipe>& ve){
    for (auto i : ve)
        cout << i;
}