//---------- Réalisation de la classe <Ensemble> (fichier Ensemble.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "liste_chainee.hpp"

//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques



void ListeChainee::AjouterTete(Noeud *noeud)
{
    std::cout << "Ajout d'un noeud en tête de liste" << std::endl;
    noeud->setSuivant(tete);
    tete = noeud;
    ++taille;
}

int ListeChainee::Poids() const
{
    int totalPoids = 0;
    Noeud *res_noeud = tete;
    for (int i = 0; i < taille; i++)
    {
        totalPoids += res_noeud->poids();
        res_noeud = res_noeud->getSuivant();
    }
    return totalPoids;
}
void ListeChainee::AjouterFin(Noeud *noeud)
{
    noeud->setSuivant(nullptr); // voir le constructeur : le ferait pas pas défaut?

    // gestion du cas de la liste vide
    if (tete == nullptr)
    {
        tete = (noeud);
        ++taille;
    }
    else
    {
        Noeud *res_node = tete; // penser à appeler le destructeur de noeud?

        // aller au dernier noeud de la liste
        for (int i = 0; i < taille; ++i)
        {
            res_node = res_node->getSuivant();
        }

        res_node->setSuivant(noeud);
        ++taille;
    }
}

void ListeChainee::AjouterNoeud(Noeud *noeud, int place)
{
    std::cout << "Ajout de noeud à l'indice " << place << std::endl;
    if ((place >= taille) || (place < 0))
    {
        //gestion du cas de la lsite vide
        if (taille == 0)
        {
            AjouterTete(noeud);
        }
        //gestion de l'erreur d'indice
        else
        {
            std::cout << "erreur : place est out of range: " << place << std::endl;
            return;
        }
    }
    else
    {
        if (place == 0)
        {
            AjouterTete(noeud);
        }
        else if (place == taille - 1)
        {
            AjouterFin(noeud);
        }
        else
        {

            Noeud *res_node = tete; // penser à appeler le destructeur de noeud?

            for (int i = 0; i < place; i++)
            {
                res_node = res_node->getSuivant();
            }
            noeud->setSuivant(res_node->getSuivant());
            res_node->setSuivant(noeud);
            ++taille;
        }
    }
}

void ListeChainee::SupprimerDebut()
{

    if(tete == nullptr)
    {
        std::cerr << "erreur : liste vide, impossible de supprimer au début" << std::endl;
        return;
    }
    Noeud *old_tete = tete;
    tete = tete->getSuivant();


    delete old_tete;
    taille--;
}

void ListeChainee::SupprimerFin()
{

    if(tete == nullptr)
    {
        std::cerr << "erreur : liste vide, impossible de supprimer à la fin" << std::endl;
        return;
    }

    Noeud *res_node = tete;
    for (int i = 0; i < taille - 1; i++)
    {
        res_node = res_node->getSuivant();
    }

    delete res_node->getSuivant();
  //  (res_node->getSuivant())->~Noeud(); // meme rq que pour début?
    res_node->setSuivant(nullptr);
    taille--;
}

void ListeChainee::SupprimerTrajet(int place)
{
    // #FIXME : je pense que cette implémentation n'est pas logique.
    //  faire à partir du trajet et non de la place.
    if ((place >= taille) || (place < 0))
    {
        std::cerr << "erreur : place est out of range: " << place << std::endl;
        return;
    }
    else
    {
        if (place == 0)
        {
            SupprimerDebut();
        }
        else if (place == taille - 1)
        {
            SupprimerFin();
        }
        else
        {
            Noeud *res_node = tete; // penser à appeler le destructeur de noeud?

            for (int i = 0; i < place; i++)
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

void ListeChainee::Afficher() const
{
    std::cout << "Liste { " << std::endl;
    Noeud *res_noeud = tete;
    for (int i = 0; i < taille; i++)
    {
        res_noeud->Afficher();
        res_noeud = res_noeud->getSuivant();
    }

    std::cout << "}" << std::endl;
}
Ville ListeChainee::getDepart() const
{
    if (tete != nullptr)
    {
        return tete->getDepart();
    }
    else
    {
        // Gérer le cas où la liste est vide
        return nullptr;
    }
}
Ville ListeChainee::getArrivee() const
{
    if (tete != nullptr)
    {
        Noeud *res = tete;
        while (res->getSuivant() != nullptr)
        {
            res = res->getSuivant();
        }
        return res->getArrivee();
    }
    else
    {
        // Gérer le cas où la liste est vide
        return nullptr;
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
