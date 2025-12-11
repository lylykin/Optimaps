//---------- Interface de la classe <Pile> (fichier Pile.h) ----------------
#if ! defined ( PILE_H )
#define PILE_H

//------------------------------------------------------- Interfaces utilisées
#include "noeud.hpp"
#include <cstring>

//----------------------------------------------------------------- Constantes

//---------------------------------------------------------------------- Types

//----------------------------------------------------------------------------
// Rôle de la classe <Pile>
// Pile utilisée pour la recherche en profondeur.
//----------------------------------------------------------------------------

class Pile 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void push ( Noeud * element );
    // Mode d'emploi :
    // Ajoute un élément au sommet de la pile

    bool vide ( ) const;
    // Mode d'emploi :
    // Vérifie si la pile est vide

    size_t taille ( ) const;
    // Mode d'emploi :
    // Retourne le nombre d'éléments dans la pile

    Noeud * element ( size_t index ) const;
    // Mode d'emploi :
    // Retourne l'élément à l'index donné

    void Afficher ( ) const;
    // Mode d'emploi :
    // Affiche tous les éléments de la pile

    int Poids ( ) const { return poids; }
    // Mode d'emploi :
    // Retourne le poids total de la pile

//------------------------------------------------- Surcharge d'opérateurs
    Pile & operator = ( const Pile & other );
    // Mode d'emploi :
    // Opérateur d'affectation par copie

//-------------------------------------------- Constructeurs - destructeur
    Pile ( );

    Pile ( Pile const & copie );
    // Mode d'emploi :
    // Constructeur de copie

    virtual ~Pile ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Noeud ** pile;
    size_t capacite; 
    size_t sommet;
    size_t poids;
};

//------------------------------------ Autres définitions dépendantes de <Pile>

#endif // PILE_H

