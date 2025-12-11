//---------- Réalisation de la classe <Noeud> (fichier Noeud.cpp) ----------------

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------------ Include système
using namespace std;

//---------------------------------------------------------- Include personnel
#include "noeud.hpp"
#include "trajet.hpp"

//----------------------------------------------------------------- Constantes

//--------------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Méthodes publiques

bool Noeud::equivalent ( const char * vdepart, const char * varrivee ) const
// Mode d'emploi :
// Vérifie si le noeud correspond aux villes données
// Compare seulement les villes de départ et d'arrivée
{
    return (strcmp(this->getDepart(), vdepart) == 0) && (strcmp(this->getArrivee(), varrivee) == 0);
} //----- Fin de equivalent

bool Noeud::equivalent ( const Noeud * autre ) const
// Mode d'emploi :
// Vérifie si le noeud est équivalent à un autre noeud
{
    return autre->equivalent(this->getDepart(), this->getArrivee());
} //----- Fin de equivalent

//----------------------------------------------------- Surcharge d'opérateurs

//------------------------------------------------ Constructeurs - destructeur

//---------------------------------------------------------------------- PRIVE

//--------------------------------------------------------- Méthodes protégées

