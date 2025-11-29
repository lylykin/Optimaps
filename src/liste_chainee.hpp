#if !defined(LISTE_CHAINEE_H)
#    define LISTE_CHAINEE_H

#include "noeud.hpp"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe 
// donne un trajet simple entre 2 villes, et son moyen de transport.
//
//------------------------------------------------------------------------
class ListeChainee : public Noeud 
{
    //----------------------------------------------------------------- PUBLIC

public:


    //----------------------------------------------------- Méthodes publiques

    virtual void Afficher() const;
    // afficher la liste

    void AjouterTete(Noeud* noeud);
    // ajouter en tete un trajet. Est ce que séparation tete/fin et taille random? Par perf je dirais oui

    void AjouterFin(Noeud* noeud);
    //ajouter à la fin un trajet. meme remarque qu'au dessus

    virtual void AjouterNoeud(Noeud* noeud, int place = 0);
    //ajouter un trajet à une place. 
    // Si au début ou a la fin, appel automa            Noeud *new_traj = new Trajet(*noeud);tique de AjouterDebut ou AjouterFin

    void SupprimerFin();
    //ajouter à la fin un trajet. meme remarque qu'au dessus
    void SupprimerDebut();
    //ajouter à la fin un trajet. meme remarque qu'au dessus

    void SupprimerTrajet(Noeud *noeud, int place);
    //ajouter à la fin un trajet. meme remarque qu'au dessus

    Ville getDepart() const; 

    Ville getArrivee() const;


    //------------------------------------------------- Surcharge d'opérateurs
    ListeChainee();
    virtual ~ListeChainee();


    //-------------------------------------------- Constructeurs - destructeur

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
