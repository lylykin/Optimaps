//---------- Réalisation de la classe Noeud(fichier Noeud.cpp) ------------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "noeud.hpp"
#include "trajet.hpp"
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
Noeud::Noeud(Trajet const& traj)
  : ::Trajet(traj) {}

Noeud::~Noeud(){}
