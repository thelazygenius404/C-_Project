#include <vector>
#include <string>
#include "match.h"
using namespace std;
void afficherMenu()
{
    cout << "======== MENU PRINCIPAL ========" << endl;
    cout << "1. Gestion des équipes" << endl;
    cout << "2. Gestion des terrains" << endl;
    cout << "3. Gestion des arbitres" << endl;
    cout << "4. Planification des matchs et affichage de resultat" << endl;
    cout << "5. Affichage du classement" << endl;
    cout << "6. Affichage des matches de qualification" << endl;
    cout << "7. Rechercher un information" << endl;
    cout << "8. Quitter" << endl;
    cout << "================================" << endl;
    cout << "Entrez votre choix : ";
}
void gestionEquipes(vector<equipe>& eq,vector<inscription>& ins)
{
    int choix;
    do
    {
        cout << endl 
             << "=== Gestion des équipes ===" << endl;
        cout << "1. Ajouter une équipe" << endl;
        cout << "2. Supprimer une équipe" << endl;
        cout << "3. Afficher toutes les équipes" << endl;
        cout << "4. Retour au menu principal" << endl;
        cout << "Entrez votre choix : ";
        cin >> choix;

        switch (choix)
        {
        case 1:
        {
            equipe e;
            cin >> e;
            eq.push_back(e);
            break;
        }
        case 2:
        {
            string nom;
            cout << "Entrez le nom de l'équipe à supprimer : ";
            cin >> nom;
            supprimerEquipe(eq, nom);
            break;
        }
        case 3:
            afficherEquipes(eq);
            break;
        case 4:
            cout << "Retour au menu principal..." << endl;
            break;
        default:
            cout << "Choix invalide !" << endl;
        }
    } while (choix != 4);
}
void gestionTerrains(vector<terrain>& ter)
{
    int choix;
    do
    {
        cout << endl
             << "=== Gestion des terrains ===" << endl;
        cout << "1. Ajouter un terrain" << endl;
        cout << "2. Supprimer un terrain" << endl;
        cout << "3. Afficher tous les terrains" << endl;
        cout << "4. Retour au menu principal" << endl;
        cout << "Entrez votre choix : ";
        cin >> choix;

        switch (choix)
        {
        case 1:
        {
            ajouterTerrain(ter);
            break;
        }
        case 2:
        {
            string nom;
            cout << "Entrez le nom du terrain à supprimer : ";
            cin >> nom;
            supprimerTerrain(ter, nom);
            break;
        }
        case 3:
            afficherTerrains(ter);
            break;
        case 4:
            cout << "Retour au menu principal..." << endl;
            break;
        default:
            cout << "Choix invalide !" << endl;
        }
    } while (choix != 4);
}

void GestionArbitres(vector<match>& mat, vector<arbitre>&arb)
{
    int choix;
    do
    {
        cout << endl
             << "=== GESTION DES ARBITRES ===" << std::endl;
        cout << "1. Ajouter un arbitre" << std::endl;
        cout << "2. Afficher tous les arbitres" << std::endl;
        cout << "3. Retour au menu principale" << std::endl;
        cout << "Entrez votre choix : ";
        cin >> choix;
        switch (choix)
        {
        case 1:
        {
            string nom;
            int niveau;
            cout << "Entrer le nom de l'arbitre: ";
            cin >> nom;
            cout << "Entrez le niveau de l'arbitre (0: Débutant, 1: Intermédiaire, 2: Professionnel, 3: International) : ";
            cin >> niveau;
            arbitre a(nom,static_cast<arbitre::Niveau>(niveau));
            if (niveau >= 0 && niveau <= 3){
                ajouterArbitre(arb, a);
            }
            else
                cout << "Niveau invalide !" << endl;
            break;
        }
        case 2:
        {
            for (auto i : arb)
                i.afficher();
            break;
        }
        case 3:
            cout << "Retour au menu principal..." << endl;
            break;
        default:
            cout << "Choix invalide !" << endl;
        }
    } while (choix != 3);
}
int main()
{
    int choix;
    vector<terrain> ter={};
    vector<equipe> eq={};
    vector<match> mat={};
    vector<arbitre> arb={};
    vector<inscription> ins={};
    vector<equipe> eqT={};
    do{
    afficherMenu();
    cin >> choix;
    switch (choix)
    {
    case 1:
        gestionEquipes(eq,ins);
        break;
    case 2:
        gestionTerrains(ter);
        break;
    case 3:
        GestionArbitres(mat, arb);
        break;
    case 4:{
        attribuerEquipesAleatoirement(mat,eq,ter,arb);
        eqT=eq;
        break;}
    case 5:
        afficherClassement(eq);
        break;
    case 6:{
        for(auto i:mat){
          cout<<i;}
        break;
    }
    case 7:{
        int choix;
        do{
        cout << "1. Rechercher une équipe" << endl;
        cout << "2. Rechercher un terrain" << endl;
        cout << "3. Rechercher un arbitre" << endl;
        cout << "4. Retour au menu principal" << endl;
        cin >> choix;
        switch(choix){
            case 1:{
                string nom;
                cout << "Entrez le nom de l'équipe à rechercher : ";
                cin >> nom;
                for(auto i: eqT){
                    if(i.getNom()==nom)
                        cout<<i<<"Le classment :"<<i.getClassement()<<endl
                        <<"Points: "<<i.getPoints()<<endl
                        <<"Buts pour: "<<i.getButsPour()<<endl<<
                        "Buts contre: "<<i.getButsContre()<<endl;
                }
                break;
            }
            case 2:{
                string nom;
                cout << "Entrez le nom du terrain à rechercher : ";
                cin >> nom;
                for(auto i: ter){
                    if(i.getNom()==nom)
                        cout<<i;
                }
                break;
            }
            case 3:{
                string nom;
                cout << "Entrez le nom de l'arbitre à rechercher : ";
                cin >> nom;
                for(auto i: arb){
                    if(i.getNom()==nom)
                        i.afficher();
                }
                break;
            }
            case 4:
                cout << "Retour au menu principal..." << endl;
                break;
            default:
                cout << "Choix invalide !" << endl;
        }}while(choix!=4);
        break;}
    case 8:
        cout << "Merci d'utiliser l'application !" << endl;
        break;
    default:
        cout << "Choix invalide !" << endl;
    }}while(choix!=8);
    return 0;
}