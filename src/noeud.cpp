//---------- Réalisation de la classe Noeud(fichier Noeud.cpp) ------------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "noeud.hpp"
#include "trajet.hpp"
//----------------------------------------------------------------- PUBLIC

bool Noeud::equivalent(const char* vdepart, const char* varrivee) const
{
    return (strcmp(this->getDepart(), vdepart) == 0) && (strcmp(this->getArrivee(), varrivee) == 0);
}

bool Noeud::equivalent(const Noeud *autre) const
{
    return autre->equivalent(this->getDepart(), this->getArrivee());
}

