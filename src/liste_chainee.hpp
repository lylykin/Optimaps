//---------- Interface de la classe <ListeChainee> (fichier ListeChainee.h) ----------------
#if ! defined ( LISTE_CHAINEE_H )
#define LISTE_CHAINEE_H

//------------------------------------------------------- Interfaces utilisées
#include "noeud.hpp"

//----------------------------------------------------------------- Constantes
#define DEFAULT_PLACE 0

//---------------------------------------------------------------------- Types

//----------------------------------------------------------------------------
// Rôle de la classe <ListeChainee>
// Gère une liste chaînée de noeuds (trajets).
//----------------------------------------------------------------------------

class ListeChainee : public Noeud 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual int Poids ( ) const;
    // Mode d'emploi :
    // Retourne le poids total de la liste

    virtual void Afficher ( ) const;
    // Mode d'emploi :
    // Affiche tous les éléments de la liste

    void AjouterTete ( Noeud * noeud );
    // Mode d'emploi :
    // Ajoute un noeud en tête de liste

    void AjouterFin ( Noeud * noeud );
    // Mode d'emploi :
    // Ajoute un noeud à la fin de la liste

    virtual void AjouterNoeud ( Noeud * noeud, int place = DEFAULT_PLACE );
    // Mode d'emploi :
    // Ajoute un noeud à une position donnée
    // Si au début ou à la fin, appel automatique de AjouterTete ou AjouterFin

    void SupprimerFin ( );
    // Mode d'emploi :
    // Supprime le dernier noeud de la liste

    void SupprimerDebut ( );
    // Mode d'emploi :
    // Supprime le premier noeud de la liste

    void SupprimerTrajet ( int place );
    // Mode d'emploi :
    // Supprime le noeud à la position donnée
    // Contrat : 
    // place doit être un indice valide

    Ville getDepart ( ) const;
    // Mode d'emploi :
    // Retourne la ville de départ du premier noeud

    Ville getArrivee ( ) const;
    // Mode d'emploi :
    // Retourne la ville d'arrivée du dernier noeud

//------------------------------------------------- Surcharge d'opérateurs
    ListeChainee ( const ListeChainee & other ) = delete;
    ListeChainee & operator = ( const ListeChainee & other ) = delete;

//-------------------------------------------- Constructeurs - destructeur
    ListeChainee ( );

    virtual ~ListeChainee ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Noeud * tete;
    int taille;
};

//------------------------------------ Autres définitions dépendantes de <ListeChainee>

#endif // LISTE_CHAINEE_H
