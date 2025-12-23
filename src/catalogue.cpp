//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ----------------

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------------ Include système
using namespace std;
#include <climits>
#include <cstddef>
#include <iostream>
#include <string.h>

//---------------------------------------------------------- Include personnel
#include "liste_chainee.hpp"

#include "catalogue.hpp"
#include "pile.hpp"
#include "ville.hpp"

//----------------------------------------------------------------- Constantes

//--------------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Méthodes publiques
void Catalogue::Afficher() const
{
    std::cout << "Catalogue des trajets :" << std::endl;
    for (Noeud *current = tete; current != nullptr; current = current->getSuivant())
    {

        std::cout << " - ";
        current->Afficher();
        std::cout << std::endl;
    }

    std::cout << "Fin du catalogue." << std::endl;
}

void Catalogue::AjouterTrajet(Noeud *noeud)
// Mode d'emploi :
// Ajoute un trajet au catalogue
{
    ListeChainee::AjouterNoeud(noeud);
} //----- Fin de AjouterTrajet

Noeud *Catalogue::Recherche(Ville villeDepart, Ville villeArrivee) const
// Mode d'emploi :
// Recherche un trajet direct entre deux villes
//
// Contrat :
// Retourne nullptr si aucun trajet n'est trouvé
{
    Noeud *courant = tete;
    for (int i = 0; i < taille; i++)
    {
        if (strcmp(courant->getDepart(), villeDepart) == 0 &&
            strcmp(courant->getArrivee(), villeArrivee) == 0)
        {
            return courant;
        }
        courant = courant->getSuivant();
    }

    return nullptr;
} //----- Fin de Recherche

Pile Catalogue::RechercheProfondeur(Ville villeDepart, Ville villeArrivee) const
// Mode d'emploi :
// Recherche tous les trajets possibles entre deux villes
// en utilisant un parcours en profondeur
//
// Contrat :
// Retourne une pile vide si aucun trajet n'est trouvé
{
    bool *parcouru = new bool[taille];
    for (int i = 0; i < taille; ++i)
    {
        parcouru[i] = false;
    }

    Pile res = RechercheProfondeurImplementation(villeDepart, villeArrivee, parcouru);
    delete[] parcouru;
    return res;
} //----- Fin de RechercheProfondeur

void Catalogue::EnregistrerCatalogue(std::ofstream &fic) const
{
    Noeud *res_noeud = tete;
    do
    {
        res_noeud->Enregistrer(fic);
        res_noeud = res_noeud->getSuivant();
        fic << std::endl;
    } while (res_noeud != nullptr);
}

void Catalogue::ChargerFichier(std::ifstream &fic)
//#TODO : debug
{

    string buffer;
    string v_dep;
    string v_arr;
    string trans;
    int index;
    int end_node = 0;

    while (getline(fic, buffer))
    {
        // cas où la ligne contient un trajet simple
        if (CommaCount(buffer) == 3)
        {
            v_dep = ExtractWord(buffer);
            v_arr = ExtractWord(buffer); // risque possible : si la supperssion sur buffer ne s'est pas faite
            trans = ExtractWord(buffer);

            Trajet *trajet = new Trajet(v_dep.c_str(), v_arr.c_str(), Str2Transport(trans.c_str()));
            AjouterFin(trajet);
        }
        else
        {
            ListeChainee *trajet_comp = new ListeChainee();
            // création de la liste de trajets
            do
            {
                if (end_node == 0)
                {
                    // cas ou on est sur une ville de départ : extraction de tout le noeud
                    v_dep = ExtractWord(buffer);
                    v_arr = ExtractWord(buffer);
                    trans = ExtractWord(buffer);
                    end_node ++;
                }
                else
                {
                    Trajet* traj = new Trajet (v_dep.c_str(), v_arr.c_str(), Str2Transport(trans.c_str()));
                    trajet_comp->AjouterFin(traj);
                    end_node = 0;  
                }
            } while (buffer != "");
        }
    }
}

//----------------------------------------------------- Surcharge d'opérateurs

//------------------------------------------------ Constructeurs - destructeur

Catalogue::Catalogue() : ListeChainee()
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue

Catalogue::~Catalogue()
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue

//---------------------------------------------------------------------- PRIVE

//--------------------------------------------------------- Méthodes protégées

Pile Catalogue::RechercheProfondeurImplementation(Ville villeDepart, Ville villeArrivee, bool *parcouru) const
// Mode d'emploi :
// Implémentation récursive de la recherche en profondeur
//
// Contrat :
// parcouru doit être un tableau de taille >= nombre de trajets
{

    // algorithme <<<<< maison >>>>
    // On évite d'utiliser DFS, BFS, ou Dijkstra car pas de STL autorisé
    // Sinon std::vector aurait été très très pratique et ce code innéficace n'aurait pas existé.

    // Pour chaque noeud:
    // - on vérifie si on a la ville de départ vers la ville d'arrivée,
    // - On visite si on a un noeud avec la même ville de départ, on le marque comme visité, puis on fait un appel récursif

    // c'est comme si on avait:
    // A -> B
    // A -> C
    // C -> D
    // D -> E

    // On parcours dans cet ordre pour A -> E:
    // A -> B (non)
    // A -> C (oui, on marque C comme visité)
    //     ON refait la recherche récursive de C -> E:
    //   C -> D (oui, on marque D comme visité)
    //       ON refait la recherche récursive de D -> E:
    //     D -> E (on a trouvé !)

    // pendant toute la recherche on rajoute le chemin à chaque fois à une file
    // On réutilise la même structure de liste chaînée pour le résultat

    Noeud *courant = tete;
    Pile meilleur_candidat{};
    for (int i = 0; i < taille; i++)
    {
        if (!parcouru[i] && strcmp(courant->getDepart(), villeDepart) == 0 &&
            strcmp(courant->getArrivee(), villeArrivee) == 0)
        {
            Pile pile{};
            pile.push(courant);
            return pile;
        }

        if (!parcouru[i] && strcmp(courant->getDepart(), villeDepart) == 0)
        {
            parcouru[i] = true;
            Pile res = RechercheProfondeurImplementation(courant->getArrivee(), villeArrivee, parcouru);
            parcouru[i] = false; // on le remet à non visité pour d'autres chemins possibles

            if (res.taille() > 0)
            {
                res.push(courant);
                if (meilleur_candidat.taille() == 0 || res.Poids() < meilleur_candidat.Poids())
                {
                    meilleur_candidat = res;
                }
            }
        }

        courant = courant->getSuivant();
    }

    // on est arrivé à la toute fin sans rien trouver
    return meilleur_candidat;
} //----- Fin de RechercheProfondeurImplementation

int CommaCount(string str)
{

    int count = 0;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == ',')
        {
            count++;
        }
    }
    return count;
}

string ExtractWord(string &str)
{
    string word = "";
    int i = 0;

    do
    {
        word += str[i];
    } while (str[i] != ',');

    str.erase(0, i);
    return word;
}
