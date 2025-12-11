//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//------------------------------------------------------- Interfaces utilisées
#include "transport.hpp"
#include "ville.hpp"
#include "noeud.hpp"

//----------------------------------------------------------------- Constantes

//---------------------------------------------------------------------- Types

//----------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Représente un trajet simple entre deux villes avec un moyen de transport.
//----------------------------------------------------------------------------

class Trajet : public Noeud
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher ( ) const;
    // Mode d'emploi :
    // Affiche le trajet (ville de départ, ville d'arrivée et moyen de transport)

    Ville getDepart ( ) const { return depart; }
    // Mode d'emploi :
    // Retourne la ville de départ
    //
    // Contrat :
    // Le pointeur retourné devient invalide lors de la destruction du trajet

    Ville getArrivee ( ) const { return arrivee; }
    // Mode d'emploi :
    // Retourne la ville d'arrivée
    //
    // Contrat :
    // Le pointeur retourné devient invalide lors de la destruction du trajet

//------------------------------------------------- Surcharge d'opérateurs
    Trajet & operator = ( const Trajet & right );
    // Mode d'emploi :
    // Opérateur d'affectation par copie
    //
    // Contrat :
    // Crée une copie depuis right

//-------------------------------------------- Constructeurs - destructeur
    Trajet ( const char * vdepart, const char * varrivee, Transport transport );
    // Mode d'emploi :
    // Construit un trajet avec les paramètres fournis
    //
    // Contrat :
    // Crée une copie des chaînes de caractères départ et arrivée

    Trajet ( Trajet const & copie );
    // Mode d'emploi :
    // Constructeur de copie

    virtual ~Trajet ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Transport trans;
    Ville depart;
    Ville arrivee;
};

//------------------------------------ Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H
