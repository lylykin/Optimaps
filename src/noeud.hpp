#if !defined(NOEUD_H)
    #define NOEUD_H

#include "ville.hpp"
#include <cstring>
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


    // equivalent puisque l'on ne compare seulement les ville de départ et d'arrivée
    // mais pas le moyen de transport ou les villes entre les deux
    bool equivalent(const char* vdepart, const char* varrivee) const;
    bool equivalent(const Noeud *autre) const;
    

    // nécessaire pour la recherche en profondeur afin d'obtenir le poids total du trajet
    // (nombre de segments)
    virtual int poids() const { return 1; } // par défaut un noeud a un poids de 1
    virtual ~Noeud(){};
protected:
    Noeud *suivant;
    
};

#endif // TRAJET_H
