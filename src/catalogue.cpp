//---------- Réalisation de la classe Catalogue (fichier catalogue.cpp) ------------

// GNU GPL v3 license  
//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string.h>
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
    for (int i = 0; i < taille; i++) // bon faire un getTaille?
    {
        ListeChainee::Afficher();
        cout << endl;
    }
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
    }

    return nullptr;
}
Noeud *Catalogue::RechercheProfondeur(Ville villeDepart, Ville villeArrivee) const
{

    return nullptr;
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue() : ListeChainee()
{
#ifdef MAP
    cout << "Appel au constructeur de <Ensemble>" << endl;
#endif
}

Catalogue::~Catalogue() 
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Ensemble>" << endl;
#endif
} //----- Fin de ~Ensemble

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
