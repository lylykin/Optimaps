#if !defined(PILE_H)
    #define PILE_H

#include "noeud.hpp"
#include <cstring>

// Pile utilisée pour la recherche en profondeur
class Pile 
{
public:   

    Pile(); 

    Pile(Pile const & copie);
    Pile & operator=(const Pile & other);

    virtual ~Pile();

    void push(Noeud* element);
    
    bool vide() const;
    size_t taille() const;

    Noeud* element(size_t index) const;

    void Afficher() const;
    int Poids() const { return poids; }
protected:
    Noeud ** pile;
    size_t capacite; 
    size_t sommet;
    size_t poids;
};

#endif // TRAJET_H

