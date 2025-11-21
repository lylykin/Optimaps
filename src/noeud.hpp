#if !defined(NOEUD_H)
    #define NOEUD_H

#include "trajet.hpp"

// Noeud pour utilisé dans une liste chainée de trajets
// La mémoire du noeud est gérée par la liste chainée
class Noeud: public Trajet //réflextion public/protected
{
public:   
    Noeud(Trajet const& traj);

    Noeud* getSuivant() const { return suivant; }
    void setSuivant(Noeud* next) { suivant = next; }

    virtual ~Noeud();
protected:
    Noeud *suivant;
    
};

#endif // TRAJET_H
