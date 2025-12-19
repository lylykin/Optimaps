//---------- Réalisation de la classe <ListeChainee> (fichier ListeChainee.cpp) ----------------

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------------ Include système
using namespace std;
#include <iostream>

//---------------------------------------------------------- Include personnel
#include "liste_chainee.hpp"

//----------------------------------------------------------------- Constantes

//--------------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Méthodes publiques

void ListeChainee::AjouterTete(Noeud *noeud)
// Mode d'emploi :
// Ajoute un noeud en tête de liste
{
    std::cout << "Ajout d'un noeud en tête de liste" << std::endl;
    noeud->setSuivant(tete);
    tete = noeud;
    ++taille;
} //----- Fin de AjouterTete

int ListeChainee::Poids() const
// Mode d'emploi :
// Retourne le poids total de la liste
{
    int totalPoids = 0;
    Noeud *res_noeud = tete;
    for (int i = 0; i < taille; i++)
    {
        totalPoids += res_noeud->poids();
        res_noeud = res_noeud->getSuivant();
    }
    return totalPoids;
} //----- Fin de Poids

void ListeChainee::AjouterFin(Noeud *noeud)
// Mode d'emploi :
// Ajoute un noeud à la fin de la liste
{
    noeud->setSuivant(nullptr);

    // gestion du cas de la liste vide
    if (tete == nullptr)
    {
        tete = (noeud);
        ++taille;
    }
    else
    {
        Noeud *res_node = tete;

        // aller au dernier noeud de la liste
        for (int i = 0; i < taille - 1; ++i)
        {
            res_node = res_node->getSuivant();
        }

        res_node->setSuivant(noeud);
        ++taille;
    }
} //----- Fin de AjouterFin

void ListeChainee::AjouterNoeud(Noeud *noeud, int place)
// Mode d'emploi :
// Ajoute un noeud à une position donnée
// Si au début ou à la fin, appel automatique de AjouterTete ou AjouterFin
{
    std::cout << "Ajout de noeud à l'indice " << place << std::endl;
    if ((place >= taille) || (place < 0))
    {
        // gestion du cas de la lsite vide
        if (taille == 0)
        {
            AjouterTete(noeud);
        }
        // gestion de l'erreur d'indice
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

            Noeud *res_node = tete;

            for (int i = 0; i < place; i++)
            {
                res_node = res_node->getSuivant();
            }
            noeud->setSuivant(res_node->getSuivant());
            res_node->setSuivant(noeud);
            ++taille;
        }
    }
} //----- Fin de AjouterNoeud

void ListeChainee::SupprimerDebut()
// Mode d'emploi :
// Supprime le premier noeud de la liste
{

    if (tete == nullptr)
    {
        std::cerr << "erreur : liste vide, impossible de supprimer au début" << std::endl;
        return;
    }
    Noeud *old_tete = tete;
    tete = tete->getSuivant();

    delete old_tete;
    taille--;
} //----- Fin de SupprimerDebut

void ListeChainee::SupprimerFin()
// Mode d'emploi :
// Supprime le dernier noeud de la liste
{

    if (tete == nullptr)
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
} //----- Fin de SupprimerFin

void ListeChainee::SupprimerTrajet(int place)
// Mode d'emploi :
// Supprime le noeud à la position donnée
// Contrat :
// place doit être un indice valide
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
            Noeud *res_node = tete;

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
} //----- Fin de SupprimerTrajet

void ListeChainee::Afficher() const
// Mode d'emploi :
// Affiche tous les éléments de la liste
{

    Noeud *res_noeud = tete;
    for (int i = 0; i < taille; i++)
    {
        res_noeud->Afficher();
        res_noeud = res_noeud->getSuivant();
        if (res_noeud != nullptr)
        {
            cout << " -> ";
        }
    }
} //----- Fin de Afficher

Ville ListeChainee::getDepart() const
// Mode d'emploi :
// Retourne la ville de départ du premier noeud
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
} //----- Fin de getDepart

Ville ListeChainee::getArrivee() const
// Mode d'emploi :
// Retourne la ville d'arrivée du dernier noeud
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
} //----- Fin de getArrivee

void ListeChainee::Enregistrer(std::ofstream &fic) const
{
    Noeud *res_noeud = tete;
    for (int i = 0; i < taille; i++)
    {
        res_noeud->Enregistrer(fic);
        res_noeud = res_noeud->getSuivant();
    }
    
}

//----------------------------------------------------- Surcharge d'opérateurs

//------------------------------------------------ Constructeurs - destructeur

ListeChainee::ListeChainee()
{
    tete = nullptr;
    taille = 0;

#ifdef MAP
    cout << "Appel au constructeur de <ListeChainee>" << endl;
#endif
} //----- Fin de ListeChainee

ListeChainee::~ListeChainee()
{
    Noeud *res = tete;
    while (res != nullptr)
    {
        res = res->getSuivant();
        delete tete;
        tete = res;
    }
#ifdef MAP
    cout << "Appel au destructeur de <ListeChainee>" << endl;
#endif
} //----- Fin de ~ListeChainee

//---------------------------------------------------------------------- PRIVE

//--------------------------------------------------------- Méthodes protégées
