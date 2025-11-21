#if !defined(TRAJET_H)
#    define TRAJET_H
#include "transport.hpp"
#include "ville.hpp"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe Trajet
// donne un trajet simple entre 2 villes, et son moyen de transport.
//
//------------------------------------------------------------------------
class Trajet
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    // pour les 3 méthodes d'en dessous, je ne suis pas sure de l'utilité?

    // Mode d'emploi :

    Ville getDepart() const { return depart; }
    Ville getArrivee() const { return arrivee;}
    // Contrat :
    // getDepart et getArrivee retournent un pointeur 
    // qui deviennent invalides lors de la destruction
    // de trajet ! 
     
    //------------------------------------------------- Surcharge d'opérateurs
    Trajet & operator=(const Trajet& right);
    // Contrat: 
    // Créé une copie depuis right 

    //-------------------------------------------- Constructeurs - destructeur
    Trajet(Ville vdepart, Ville varrivee, Transport transport);
    Trajet(Trajet const & copie);

    
    // Contrat: 
    // Créé une copie de départ et d'arrivee, 
    // Donc ne pas oublier de les free !


    virtual ~Trajet();
    // Mode d'emploi :
    //
    // Contrat :
    //
    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    Transport trans;
    Ville depart;  // ville de départ du trajet simple
    Ville arrivee; // ville d'arrivée
    // note pour améloration : manque le temps de trajet, et de pouvoir sélectonner un mode de transport
};

//-------------------------------- Autres définitions dépendantes de <Ensemble>

#endif // TRAJET_H
