//---------- Réalisation de la classe <Ensemble> (fichier Ensemble.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "liste_chainee.hpp"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void ListeChainee::AjouterTete(const Trajet &trajet)
{

    Noeud *new_traj;
    *new_traj = (Noeud)trajet; // en profondeur
    new_traj->setSuivant(tete);
    tete = new_traj;
    ++taille;
}

void ListeChainee::AjouterFin(const Trajet &trajet)
{

    Noeud *new_traj;
    *new_traj = (Noeud)trajet;     // en profondeur
    new_traj->setSuivant(nullptr); // voir le constructeur : le ferait pas pas défaut?

    // gestion du cas de la liste vide
    if (tete == nullptr)
    {
        tete->setSuivant(new_traj);
    }
    else
    {
        Noeud *res_node = tete; // penser à appeler le destructeur de noeud?

        // aller au dernier noeud de la liste
        for (size_t i = 0; i < taille; ++i)
        {
            res_node = res_node->getSuivant();
        }

        res_node->setSuivant(new_traj);
        ++taille;
    }
}

void ListeChainee::AjouterTrajet(const Trajet &trajet, int place)
{
    try
    {
        if ((place >= taille) || (place < 0))
        {
            throw 134;
        }
        else
        {
            if (place == 0)
            {
                AjouterTete(trajet);
            }
            else if (place == taille - 1)
            {
                AjouterFin(trajet);
            }
            else
            {
                Noeud *new_traj;
                *new_traj = (Noeud)trajet; // en profondeur           {
                Noeud *res_node = tete;    // penser à appeler le destructeur de noeud?

                for (size_t i = 0; i < place; i++)
                {
                    res_node = res_node->getSuivant();
                }
                new_traj->setSuivant(res_node->getSuivant());
                res_node->setSuivant(new_traj);
                ++taille;
            }
        }
    }

    // je suis pas sure de l'utilisation ici, mais c'est ce que j'ai compris
    catch (int err)
    {
        cout << "erreur : place est out of range" << endl;
    }
}

void ListeChainee::SupprimerDebut(const Trajet &trajet)
{
    tete = tete->getSuivant();
    // question : suppression en mém du noeud originel de tete?
    taille--;
}

void ListeChainee::SupprimerFin(const Trajet &trajet)
{
    Noeud *res_node = tete;
    for (size_t i = 0; i < taille - 1; i++)
    {
        res_node = res_node->getSuivant();
    }
    (res_node->getSuivant())->~Noeud(); // meme rq que pour début?
    res_node->setSuivant(nullptr);
    taille--;
}

void ListeChainee::SupprimerTrajet(const Trajet &trajet, int place)
{
    try
    {
        if ((place >= taille) || (place < 0))
        {
            throw 134;
        }
        else
        {
            if (place == 0)
            {
                SupprimerDebut(trajet);
            }
            else if (place == taille - 1)
            {
                SupprimerFin(trajet);
            }
            else
            {
                Noeud *res_node = tete;    // penser à appeler le destructeur de noeud?

                for (size_t i = 0; i < place; i++)
                {
                    res_node = res_node->getSuivant();
                }
                Noeud *new_next = res_node->getSuivant()->getSuivant();
                res_node->getSuivant()->~Noeud();
                res_node->setSuivant(new_next);
                --taille;
            }
        }
    }

    // je suis pas sure de l'utilisation ici, mais c'est ce que j'ai compris
    catch (int err)
    {
        cout << "erreur : place est out of range" << endl;
    }   
}

void ListeChainee::Afficher(){
    cout<<"Liste [: "<< endl;
    Noeud *res_noeud = tete;
    for (size_t i = 0; i < taille; i++)
    {
        cout<<res_noeud<<"; "; 
        res_noeud = res_noeud->getSuivant();        
    }
    
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

ListeChainee::ListeChainee()
{
    tete = nullptr;
    taille = 0;
}

ListeChainee::~ListeChainee()
{

    Noeud *res = tete;
    while (res != nullptr)
    {
        res = res->getSuivant();
        delete tete;
        tete = res;
    }
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
