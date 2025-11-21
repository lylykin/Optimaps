#if !defined(CATALOGUE_H)
#    define CATALOGUE_H
#include "trajet.hpp"
#include "liste_chainee.hpp";


// #include "transport.hpp"
//#include "ville.hpp"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe Catalogue
// donne un trajet simple entre 2 villes, et son moyen de transport.
//
//------------------------------------------------------------------------
class Catalogue : public Trajet
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques



    //------------------------------------------------- Surcharge d'opérateurs
    //-------------------------------------------- Constructeurs - destructeur
    Catalogue();

    Trajet(Ville depart, Ville arrivee, Transport transport);
    //constructeur normal ou jsp


    virtual ~Catalogue();
    // Mode d'emploi :
    //
    // Contrat :
    //
    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    // liste chainée de trajets
};

//-------------------------------- Autres définitions dépendantes de <Ensemble>

#endif // TRAJET_H
