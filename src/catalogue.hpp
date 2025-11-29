#if !defined(CATALOGUE_H)
#    define CATALOGUE_H
#include "liste_chainee.hpp"

#include "trajet.hpp"



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
class Catalogue : public ListeChainee
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    void Afficher() const;

    void AjouterTrajet(Noeud *noeud);

    Noeud* Recherche(Ville villeDepart, Ville villeArrivee) const;
    Noeud* RechercheProfondeur(Ville villeDepart, Ville villeArrivee) const;

   

    //------------------------------------------------- Surcharge d'opérateurs
    //-------------------------------------------- Constructeurs - destructeur
    Catalogue();
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
