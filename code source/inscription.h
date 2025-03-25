#include "equipe.h"
#include <iostream>
#include <string>
using namespace std;
class inscription
{
    equipe e;
    bool valide;

public:
    inscription(equipe e, bool valide = false) : e(e), valide(valide) {}
    bool getValide() { return valide; }
    void setValide(bool b) { valide = b; }
    equipe getEquipe() { return e; }
    friend ostream &operator<<(ostream &, inscription &);
};
ostream &operator<<(ostream &os, inscription &i)
{
    if (i.valide)
        os << i.e.getNom() << "Cette equipe est inscrit." << endl;
    else
        os << i.e.getNom() << "Cette equipe n'est pas inscrit." << endl;
    return os;
}
void inscrireEquipe(vector<inscription>& insc, equipe eq)
{
    bool b = false;
    for (auto i : insc)
        if (i.getValide() && (i.getEquipe().getNom() == eq.getNom()))
        {
            cout << "Cette equipe est deja inscrit" << endl;
            b = true;
        }
    if (!b)
    {
        if (insc.size() < 11)
        {
            inscription i(eq, true);
            insc.push_back(i);
        }
        else
            cout << "L'inscription atteint la limite" << endl;
    }
}
void afficherInscriptions(vector<inscription> &insc)
{
    for (auto i : insc)
        cout << i;
}
void ajouterEquipe(vector<equipe>& ve,vector<inscription>& ins)
{
    equipe e;
        cin >> e;
        inscrireEquipe(ins,e);
        if (find_if(ve.begin(),ve.end(), [&](const equipe& eq) { return e.getNom() == eq.getNom(); }) != ve.end()) {
            cout <<e.getNom()<< " existe déjà." << endl;
            return;
        }
        ve.push_back(e);
        cout<<e.getNom()<<" est ajoutee"<<endl;

}