//---------- Réalisation de la classe <Pile> (fichier Pile.cpp) ----------------

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------------ Include système
using namespace std;
#include <iostream>

//---------------------------------------------------------- Include personnel
#include "pile.hpp"

//----------------------------------------------------------------- Constantes

//--------------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Méthodes publiques

void Pile::push ( Noeud * element )
// Mode d'emploi :
// Ajoute un élément au sommet de la pile
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
} //----- Fin de push

bool Pile::vide ( ) const
// Mode d'emploi :
// Vérifie si la pile est vide
{
    return sommet == 0;
} //----- Fin de vide

size_t Pile::taille ( ) const
// Mode d'emploi :
// Retourne le nombre d'éléments dans la pile
{
    return sommet;
} //----- Fin de taille

Noeud * Pile::element ( size_t index ) const
// Mode d'emploi :
// Retourne l'élément à l'index donné
{
    if (index < sommet)
    {
        return pile[index];
    }
    else
    {
        cerr << "Erreur : Index hors limites." << endl;
        return nullptr;
    }
} //----- Fin de element

void Pile::Afficher ( ) const
// Mode d'emploi :
// Affiche tous les éléments de la pile
{
    cout << "Série de trajet: { " << endl;
    for (int i = sommet - 1 ; i >= 0; --i)
    {
        cout << " [ ";
        pile[i]->Afficher();
        cout << " ] ";
        if (i > 0)
        {
            cout << " -> ";
        }
    }
    cout << endl << "}" << endl;
} //----- Fin de Afficher

//----------------------------------------------------- Surcharge d'opérateurs

Pile & Pile::operator = ( const Pile & other )
// Mode d'emploi :
// Opérateur d'affectation par copie
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
} //----- Fin de operator =

//------------------------------------------------ Constructeurs - destructeur

Pile::Pile ( )
{
    capacite = 0;
    sommet = 0;
    pile = nullptr;
    
    #ifdef MAP
        cout << "Appel au constructeur de <Pile>" << endl;
    #endif
} //----- Fin de Pile


Pile::Pile ( Pile const & copie )
// Mode d'emploi :
// Constructeur de copie
{
    capacite = copie.capacite;
    sommet = copie.sommet;
    pile = new Noeud*[capacite];
    for (size_t i = 0; i < sommet; ++i)
    {
        pile[i] = copie.pile[i];
    }
} //----- Fin de Pile (constructeur de copie)

Pile::~Pile ( )
{
    delete[] pile;
    #ifdef MAP
        cout << "Appel au destructeur de <Pile>" << endl;
    #endif
} //----- Fin de ~Pile

//---------------------------------------------------------------------- PRIVE

//--------------------------------------------------------- Méthodes protégées