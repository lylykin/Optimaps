#if !defined(NOEUD_H)
    #define NOEUD_H

#include "ville.hpp"
// Noeud pour utilisé dans une liste chainée de trajets
// La mémoire du noeud est gérée par la liste chainée
class Noeud //réflextion public/protected
{
public:   

    Noeud* getSuivant() const { return suivant; }
    void setSuivant(Noeud* next) { suivant = next; }
    virtual Ville getDepart() const { return nullptr;}; 
    virtual void Afficher() const {}; 
    virtual Ville getArrivee() const { return nullptr;};

    virtual ~Noeud(){};
protected:
    Noeud *suivant;
    
};

#endif // TRAJET_H
