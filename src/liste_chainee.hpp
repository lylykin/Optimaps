#if !defined(CATALOGUE_H)
#    define CATALOGUE_H

#include "noeud.hpp"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe 
// donne un trajet simple entre 2 villes, et son moyen de transport.
//
//------------------------------------------------------------------------
class ListeChainee
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    void Afficher();
    // afficher la liste

    Noeud RechercheNoeud(const Trajet & trajet);
    // retourner le noeud, ou trajet? correspondant? non ca faire plus dans catalogue?

    void AjouterTete(const Trajet & trajet);
    // ajouter en tete un trajet. Est ce que séparation tete/fin et taille random? Par perf je dirais oui

    void AjouterFin(const Trajet & trajet);
    //ajouter à la fin un trajet. meme remarque qu'au dessus

    void AjouterTrajet(const Trajet & trajet, int place);
    //ajouter un trajet à une place. 
    // Si au début ou a la fin, appel automatique de AjouterDebut ou AjouterFin

    void SupprimerFin(const Trajet & trajet);
    //ajouter à la fin un trajet. meme remarque qu'au dessus
    void SupprimerDebut(const Trajet & trajet);
    //ajouter à la fin un trajet. meme remarque qu'au dessus

    void SupprimerTrajet(const Trajet & trajet, int place);
    //ajouter à la fin un trajet. meme remarque qu'au dessus



    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    ListeChainee();

    virtual ~ListeChainee();
    // virtual car serait aussi encapsulée dans catalogue. 
    // Mode d'emploi :
    //
    // Contrat :
    //
    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    Noeud *tete;
    int taille;
    
};

//-------------------------------- Autres définitions dépendantes de <Ensemble>

#endif // TRAJET_H
