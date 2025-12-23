//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//------------------------------------------------------- Interfaces utilisées
#include "liste_chainee.hpp"
#include "trajet.hpp"
#include "pile.hpp"

//----------------------------------------------------------------- Constantes

//---------------------------------------------------------------------- Types

//----------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Gère un catalogue de trajets permettant l'ajout, l'affichage et la 
// recherche de trajets entre différentes villes.
//----------------------------------------------------------------------------

class Catalogue : public ListeChainee
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher ( ) const;
    // Mode d'emploi :
    // Affiche l'ensemble des trajets contenus dans le catalogue

    void AjouterTrajet ( Noeud * noeud );
    // Mode d'emploi :
    // Ajoute un trajet au catalogue

    Noeud * Recherche ( Ville villeDepart, Ville villeArrivee ) const;
    // Mode d'emploi :
    // Recherche un trajet direct entre deux villes
    //
    // Contrat :
    // Retourne nullptr si aucun trajet n'est trouvé

    Pile RechercheProfondeur ( Ville villeDepart, Ville villeArrivee ) const;
    // Mode d'emploi :
    // Recherche tous les trajets possibles entre deux villes
    // en utilisant un parcours en profondeur
    //
    // Contrat :
    // Retourne une pile vide si aucun trajet n'est trouvé

    void EnregistrerCatalogue(std::ofstream & fic) const ;

    void ChargerFichier(std::ifstream & fic);

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Catalogue ( );

    virtual ~Catalogue ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    Pile RechercheProfondeurImplementation ( Ville villeDepart, Ville villeArrivee, bool * parcouru = nullptr ) const;
    // Mode d'emploi :
    // Implémentation récursive de la recherche en profondeur
    //
    // Contrat :
    // parcouru doit être un tableau de taille >= nombre de trajets

//----------------------------------------------------- Attributs protégés
};

//------------------------------------ Autres définitions dépendantes de <Catalogue>

int CommaCount(std::string str);
std::string ExtractWord(std::string & str);

#endif // CATALOGUE_H
