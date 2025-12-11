
#include "pile.hpp"
#include <iostream>
// Pile utilisée pour la recherche en profondeur


Pile::Pile()
{

    capacite = 0;
    sommet = 0;
    pile = nullptr;
}

Pile::Pile(Pile const & copie)
{
    capacite = copie.capacite;
    sommet = copie.sommet;
    pile = new Noeud*[capacite];
    for (size_t i = 0; i < sommet; ++i)
    {
        pile[i] = copie.pile[i];
    }
}

Pile & Pile::operator=(const Pile & other)
{
    if (this != &other)
    {
        delete[] pile;
        capacite = other.capacite;
        sommet = other.sommet;
        pile = new Noeud*[capacite];
        for (size_t i = 0; i < sommet; ++i)
        {
            pile[i] = other.pile[i];
        }
    }
    return *this;
}

Pile::~Pile()
{
    delete[] pile;
}

void Pile::push(Noeud* element)
{ 
    if (capacite == 0)
    {
        // cas spécial : pile de capacité 0, on l'agrandit dynamiquement
        capacite = 1;
        Noeud** newPile = new Noeud*[capacite];
        delete[] pile;
        pile = newPile;
    }
    else  
    {
        capacite *= 2;
        Noeud** newPile = new Noeud*[capacite];
        for (size_t i = 0; i < sommet; ++i)
        {
            newPile[i] = pile[i];
        }

        delete[] pile;
        pile = newPile;
    }

    pile[sommet] = element;
    sommet++;
    poids += element->poids();
}

bool Pile::vide() const
{
    return sommet == 0;
}

size_t Pile::taille() const
{
    return sommet;
}

Noeud* Pile::element(size_t index) const
{
    if (index < sommet)
    {
        return pile[index];
    }
    else
    {
        std::cerr << "Erreur : Index hors limites." << std::endl;
        return nullptr;
    }
}

void Pile::Afficher() const
{
    std::cout << "Série de trajet: { " << std::endl;
    for (int i = sommet - 1 ; i >= 0; --i)
    {
        std::cout << " [ ";
        pile[i]->Afficher();
        std::cout << " ] ";
        if (i > 0)
        {
            std::cout << " -> ";
        }
    }
    std::cout <<std::endl<<  "}" << std::endl;
}