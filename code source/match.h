#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "terrain.h"
#include "inscription.h"
#include <ctime>
#include <random>
#include "arbitre.h"
#include <iomanip>
using namespace std;
time_t t = time(nullptr);
tm *now = localtime(&t);
class date
{
    int jour, mois, annee,heure,minute;

public:
    date(int j = now->tm_mday, int m = now->tm_mon + 1, int a = now->tm_year + 1900,int h=now->tm_hour,int min=now->tm_min) : jour(j),
                        mois(m), annee(a),heure(h),minute(min) {}
    friend ostream &operator<<(ostream &, date);
    friend istream &operator>>(istream &, date &);
    date& operator=(const date& autre){
        if(this!=&autre){
        this->jour = autre.jour;
        this->mois = autre.mois;
        this->annee = autre.annee;
        this->heure = autre.heure;
        this->minute = autre.minute;
        }
        return *this;
    }
    bool estValide() const {
        if (mois < 1 || mois > 12) return false;
        if (jour < 1) return false;
        if(heure<0 || heure>23) return false;
        if(minute<0 || minute>59) return false;
        
        int joursParMois[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if (annee % 4 == 0 && (annee % 100 != 0 || annee % 400 == 0))
            joursParMois[1] = 29;
            
        return jour <= joursParMois[mois-1];
    }
};
ostream &operator<<(ostream &out, date d)
{
    out << d.jour << "/" << d.mois << "/" << d.annee<<endl<<d.heure<<":"<<d.minute;
    return out;
}
istream &operator>>(istream &in, date &d)
{
     cout << "Entree une date(format jj/mois/annee heure:minute):" << endl;
        in >> d.jour >> d.mois >> d.annee>>d.heure>>d.minute;
        
        while (!d.estValide()) {
            cout << "Date invalide. Réessayez (jj/mm/aaaa heure:minute):" << endl;
            in >> d.jour >> d.mois >> d.annee>>d.heure>>d.minute;
        }
        return in;
}
class match
{
    equipe eq1;
    equipe eq2;
    arbitre arb;
    terrain ter;
    date d;
    int scoreEq1;
    int scoreEq2;
public:
    match()=default;
    match(equipe e1, equipe e2, terrain t,date d,arbitre a) : 
    eq1(e1),eq2(e2),arb(a),ter(t),d(d), scoreEq1(0), scoreEq2(0) {}
    friend ostream &operator<<(ostream &,const match &);
    void setScoreEq1(int s) { scoreEq1 = s; }
    void setScoreEq2(int s) { scoreEq2 = s; }
    int getScoreEq1() const { return scoreEq1; }
    int getScoreEq2() const { return scoreEq2; }
    equipe getEquipe1() const { return eq1; }
    equipe getEquipe2() const { return eq2; }
    arbitre getArbitre() const { return arb; }
    void setArbitre(arbitre& ar) { arb = ar; }
    match& operator=(const match &m) {
        if (this != &m) {
            eq1 = m.eq1;
            eq2 = m.eq2;
            arb = m.arb;
            ter = m.ter;
            d = m.d;
            scoreEq1 = m.scoreEq1;
            scoreEq2 = m.scoreEq2;

        }
        return *this;
    }
const terrain& getTerrain() {
        return ter;
    }
void afficher(){
    cout <<endl<< "Match " << eq1.getNom() <<" vs "<< eq2.getNom() << endl
        << "Terrain: "<< ter.getNom() << endl
        << "Date: " << d << endl
        << "Arbitre: " << arb.getNom() << endl;}};
ostream &operator<<(ostream &out, const match& m)
{
    out <<endl<< "Match " << m.eq1.getNom() << ' ' << m.scoreEq1 << '-' << m.scoreEq2 << ' ' << m.eq2.getNom() << endl
        << "Terrain: "<< m.ter.getNom() << endl
        << "Date: " << m.d << endl
        << "Arbitre: " << m.arb.getNom() << endl;
    return out;
}
match creerMatch(equipe &e1, equipe &e2, terrain &t, date &d,arbitre& a)
{
    match m(e1, e2, t, d,a);
    // Initialisation du générateur aléatoire
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> scoreDist(0, 5); // Scores entre 0 et 5   
    // Génération des scores
    do{m.setScoreEq1(scoreDist(gen));
    m.setScoreEq2(scoreDist(gen));}while(m.getScoreEq1()==m.getScoreEq2());
    e1.setButpour(m.getScoreEq1());
    e1.setButcontre(m.getScoreEq2());
    e2.setButpour(m.getScoreEq2());
    e2.setButcontre(m.getScoreEq1());
    if (m.getScoreEq1() < m.getScoreEq2())
        e2.setPoints(3);
    else if (m.getScoreEq1() > m.getScoreEq2())
        e1.setPoints(3);
    return m;
}
vector<equipe> jouerPhase(vector<equipe> eq,vector<terrain> ter,vector<arbitre> ar)
{
    vector<equipe> vainqueurs;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> scoreDist(0, 5);
    int j=0;
    date d;
     for (size_t i = 0; i < eq.size(); i += 2) {  
        cin >> d;
        match mat=creerMatch(eq[i],eq[i+1],ter[j],d,ar[j]);
        j++;
        // Afficher le résultat du match
        cout<<mat;
        // Ajouter le vainqueur
        vainqueurs.push_back(mat.getScoreEq1() > mat.getScoreEq2() ? eq[i] : eq[i + 1]);
    }
    return vainqueurs;
}
void afficherClassement(vector<equipe> eq)
{
    cout << "#" << setw(10) << "Equipe" << setw(10) << "P" <<setw(10)<<"BP"<<setw(10)<<"BC"<< endl;
    for (auto i : eq)
        cout <<i.getClassement()<< setw(10) << i.getNom() << setw(10) << i.getPoints() <<setw(10)
        << i.getButsPour()<<setw(10)<<i.getButsContre()<< endl;
}
void attribuerEquipesAleatoirement(vector<match> &m, vector<equipe> &eq,vector<terrain>& ter,vector<arbitre>& ar){
    // Vérifier qu'il y a au moins deux équipes
    if (eq.size() < 2)
    {
        cout << "Pas assez d'équipes pour planifier des matchs." << endl;
        return;
    }
    if(eq.size()==10){
    // Mélanger les équipes aléatoirement
    random_device rd;
    mt19937 gen(rd());
    shuffle(eq.begin(), eq.end(), gen);
    // Former des paires et créer des matchs
    int i,j;
    date dateMatch;
    for (i=0,j=eq.size();i!=j;i++,j--)
    {   
        cin >> dateMatch;
        match mat=creerMatch(eq[j],eq[i],ter[i],dateMatch,ar[i]);
        m.push_back(mat);
    }
    for (i=0,j=eq.size();i!=j;i++,j--)
    {   
        cin >> dateMatch;
        match mat=creerMatch(eq[j],eq[i],ter[i],dateMatch,ar[i]);
        m.push_back(mat);
    }
    sort(eq.begin(), eq.end(), [](const equipe &a, const equipe &b)
         { return a.getPoints() > b.getPoints(); });
    int k = 1;
    for (auto &i : eq)
    {
        i.setClassement(k);
        k++;
    }
    eq.pop_back();
    eq.pop_back();
    return;
    }
    // Si une équipe reste sans adversaire, afficher un message
    if (eq.size() % 2 != 0){
        cout << "L'équipe " << eq.back().getNom() << " n'a pas d'adversaire pour ce tour." << endl;
        cout<<"Le nombre d'equipes doit etre pair"<<endl;
        return;}
    if(eq.size()==8){
        cout << "=== QUARTS DE FINALE ===" << endl;
        vector<equipe> demiFinalistes = jouerPhase(eq,ter,ar);
        cout << "=== DEMI-FINALES ===" << endl;
        vector<equipe> finalistes = jouerPhase(demiFinalistes,ter,ar);
        cout << "=== FINALE ===" << endl;
        vector<equipe> vainqueur = jouerPhase(finalistes,ter,ar);
        cout << "=== CHAMPION ===" <<endl;
        cout << "Le champion est : " << vainqueur[0].getNom() <<endl;
        return;
    }
    if(eq.size()==4){
        cout << "=== DEMI-FINALES ===" << endl;
        vector<equipe> finalistes = jouerPhase(eq,ter,ar);
        cout << "=== FINALE ===" << endl;
        vector<equipe> vainqueur = jouerPhase(finalistes,ter,ar);
        cout << "=== CHAMPION ===" <<endl;
        cout << "Le champion est : " << vainqueur[0].getNom() <<endl;
        return;
    }
    if(eq.size()==2){
        cout << "=== FINALE ===" << endl;
        vector<equipe> vainqueur = jouerPhase(eq,ter,ar);
        cout << "=== CHAMPION ===" <<endl;
        cout << "Le champion est : " << vainqueur[0].getNom() <<endl;
        return;
    }
    }




