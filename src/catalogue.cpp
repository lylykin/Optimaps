//---------- Réalisation de la classe Catalogue (fichier catalogue.cpp) ------------

// GNU GPL v3 license  
//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <climits>
#include <cstddef>
#include <iostream>
#include <string.h>
#include "liste_chainee.hpp"
#include "pile.hpp"
#include "ville.hpp"
using namespace std;
//------------------------------------------------------ Include personnel
#include "catalogue.hpp"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC


/*

def bfs(o_graph, s_deb):
    
    q = [s_deb]         # noeuds à vister
    pred = {}           # predecesseur
    visitee = [s_deb]   # noeuds déjà visités

    while len(q) > 0:
        a_visiter = q.pop(0)
        if a_visiter in o_graph.keys(): 
            for v in o_graph[a_visiter]:
                # o_graph est de la forme : {a:[[1,b], [2,c]]}
                nom_noeud = v[1]
                if not nom_noeud in visitee:    # on vérifie que le noeud n'a pas déjà été visté
                    visitee.append(nom_noeud)   # on ajoute le noeud aux noeud déjà visités
                    pred[nom_noeud] = a_visiter 
                    q.append(nom_noeud)

    return pred 


def chemin(o_graph, s_deb, s_fin):
    """ 
    Trouve le plus court chemin entre deux noeuds
    
    Paramètres
    ----------
    o_graph : list
        liste des noeuds adjacents au noeud de départ
    s_deb : str
        noeud de départ
    s_fin : str
        noeud de fin

    Retourne
    -------
    chemin : list
        liste contenant le plus court chemin entre deux noeuds
    """
    
    l = bfs(o_graph, s_deb)

    if s_deb == s_fin: 
        return [s_deb] 
    elif not s_fin in l.keys(): 
        return []  
    else: 
        p = chemin(o_graph, s_deb, l[s_fin])
        return p + [s_fin]



*/
//----------------------------------------------------- Méthodes publiques
void Catalogue::Afficher() const
{
    std::cout << "Catalogue des trajets :" << std::endl;
    for(Noeud* current = tete; current != nullptr; current = current->getSuivant())
    {
        
        std::cout << " - ";
        current->Afficher();
        std::cout << std::endl;
    }

    std::cout << "Fin du catalogue." << std::endl;
}

void Catalogue::AjouterTrajet(Noeud *noeud) {ListeChainee::AjouterNoeud(noeud);}


Noeud *Catalogue::Recherche(Ville villeDepart, Ville villeArrivee) const
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
}
Pile Catalogue::RechercheProfondeur(Ville villeDepart, Ville villeArrivee) const
{
    bool* parcouru = new bool[taille];
    for(int i = 0; i < taille; ++i)
    {
        parcouru[i] = false;
    }

    Pile res = RechercheProfondeurImplementation(villeDepart, villeArrivee, parcouru);
    delete[] parcouru;
    return res;
}
Pile  Catalogue::RechercheProfondeurImplementation(Ville villeDepart, Ville villeArrivee, bool* parcouru) const
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
    Pile  meilleur_candidat {};
    for (int i = 0; i < taille; i++)
    {
        if (!parcouru[i] && strcmp(courant->getDepart(), villeDepart) == 0 &&
            strcmp(courant->getArrivee(), villeArrivee) == 0 )
        {
            Pile pile {};
            pile.push(courant);
            return pile;
        }

        if(!parcouru[i] && strcmp(courant->getDepart(), villeDepart) == 0)
        {
            parcouru[i] = true;
            Pile res = RechercheProfondeurImplementation(courant->getArrivee(), villeArrivee, parcouru);
            parcouru[i] = false; // on le remet à non visité pour d'autres chemins possibles
           
           
            if(res.taille() > 0)
            {
                res.push(courant);
                if(meilleur_candidat.taille() == 0 || res.Poids() < meilleur_candidat.Poids())
                {
                    meilleur_candidat = res;
                } 
            }
        }

        courant = courant->getSuivant();
    }


    // on est arrivé à la toute fin sans rien trouver
    return meilleur_candidat;
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue() : ListeChainee()
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
}

Catalogue::~Catalogue() 
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
