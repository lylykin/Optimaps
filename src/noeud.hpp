//---------- Interface de la classe <Noeud> (fichier Noeud.h) ----------------
#if ! defined ( NOEUD_H )
#define NOEUD_H

//------------------------------------------------------- Interfaces utilisées
#include "ville.hpp"
#include <cstring>
#include <fstream>
//----------------------------------------------------------------- Constantes

//---------------------------------------------------------------------- Types

//----------------------------------------------------------------------------
// Rôle de la classe <Noeud>
// Noeud utilisé dans une liste chaînée de trajets.
// La mémoire du noeud est gérée par la liste chaînée.
//----------------------------------------------------------------------------

class Noeud
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    Noeud * getSuivant ( ) const { return suivant; }
    // Mode d'emploi :
    // Retourne le noeud suivant

    void setSuivant ( Noeud * next ) { suivant = next; }
    // Mode d'emploi :
    // Définit le noeud suivant

    virtual Ville getDepart ( ) const { return nullptr; }
    // Mode d'emploi :
    // Retourne la ville de départ

    virtual void Afficher ( ) const { }
    // Mode d'emploi :
    // Affiche le noeud

    virtual Ville getArrivee ( ) const { return nullptr; }
    // Mode d'emploi :
    // Retourne la ville d'arrivée

    bool equivalent ( const char * vdepart, const char * varrivee ) const;
    // Mode d'emploi :
    // Vérifie si le noeud correspond aux villes données
    // Compare seulement les villes de départ et d'arrivée

    bool equivalent ( const Noeud * autre ) const;
    // Mode d'emploi :
    // Vérifie si le noeud est équivalent à un autre noeud

    virtual int poids ( ) const { return 1; }
    // Mode d'emploi :
    // Retourne le poids du noeud (nombre de segments)
    // Par défaut un noeud a un poids de 1

    virtual void Enregistrer(std::ofstream & fic) const = 0;
    //enregistrer un noeud à la fin du fichier fic

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    virtual ~Noeud ( ) { }

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Noeud * suivant;
};

//------------------------------------ Autres définitions dépendantes de <Noeud>

#endif // NOEUD_H
